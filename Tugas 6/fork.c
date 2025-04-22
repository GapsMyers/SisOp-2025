#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/shm.h>
#include <sys/ipc.h>

#define N 4 

int main() {
    
    int A[N][N] = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12},
        {13, 14, 15, 16}
    };
    
    int B[N][N] = {
        {16, 15, 14, 13},
        {12, 11, 10, 9},
        {8, 7, 6, 5},
        {4, 3, 2, 1}
    };
    
    int shmid;
    int (*result)[N]; // Pointer untuk matriks hasil
    key_t key = IPC_PRIVATE;
    
    shmid = shmget(key, N * N * sizeof(int), IPC_CREAT | 0666);
    if (shmid < 0) {
        perror("shmget");
        exit(1);
    }
    
    result = shmat(shmid, NULL, 0);
    if (result == (int (*)[N]) -1) {
        perror("shmat");
        exit(1);
    }
    
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            result[i][j] = 0;
        }
    }
    
    pid_t pid;
    for (int i = 0; i < N; i++) {
        pid = fork();
        
        if (pid < 0) {
            // Error handling
            perror("fork");
            exit(1);
        } else if (pid == 0) {
            // Proses anak - bertanggung jawab untuk 1 baris
            for (int j = 0; j < N; j++) {
                for (int k = 0; k < N; k++) {
                    result[i][j] += A[i][k] * B[k][j];
                }
            }
            exit(0);
        }
    }
    
    
    for (int i = 0; i < N; i++) {
        wait(NULL);
    }
    
  
    printf("Matriks A:\n");
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("%4d ", A[i][j]);
        }
        printf("\n");
    }
    

    printf("\nMatriks B:\n");
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("%4d ", B[i][j]);
        }
        printf("\n");
    }
 
    printf("\nHasil Perkalian A x B:\n");
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("%4d ", result[i][j]);
        }
        printf("\n");
    }
    
    if (shmdt(result) == -1) {
        perror("shmdt");
        exit(1);
    }
    
    if (shmctl(shmid, IPC_RMID, NULL) == -1) {
        perror("shmctl");
        exit(1);
    }
    
    return 0;
}