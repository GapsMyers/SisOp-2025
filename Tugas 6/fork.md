
# 🚀 Konsep Fork dan Implementasinya dalam Bahasa C

## 📘 Pengertian Fork

> **Fork** adalah _system call_ yang digunakan pada sistem operasi berbasis **UNIX/Linux** untuk menciptakan proses baru (_child process_) dengan cara menduplikasi proses yang sudah ada (_parent process_).

🔍 Saat `fork()` dipanggil:
- **Parent process** menerima nilai _PID_ dari child.
- **Child process** menerima nilai `0`.
- Kedua proses melanjutkan eksekusi dari titik setelah `fork()` dipanggil.

Fork menjadi fondasi dari **multiprogramming** dan **konkurensi**, serta sering dikombinasikan dengan fungsi `exec()` untuk menjalankan program yang berbeda di child process.

---

## 🛠️ Implementasi Fork dalam Bahasa C

Untuk menggunakan `fork()` di C, kita harus mengimpor header `<unistd.h>`. Berikut contoh implementasinya:

```c
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main() {
    pid_t pid;

    pid = fork();

    if (pid < 0) {
        fprintf(stderr, "Fork gagal
");
        return 1;
    }
    else if (pid == 0) {
        printf("👶 Ini adalah child process dengan PID: %d\n", getpid());
        printf("🧓 Parent PID: %d\n", getppid());

        for (int i = 1; i <= 5; i++) {
            printf("🔁 Child menghitung: %d\n", i);
            sleep(1);
        }

        printf("✅ Child process selesai\n");
    }
    else {
        printf("🧓 Ini adalah parent process dengan PID: %d\n", getpid());
        printf("👶 Child PID: %d\n", pid);

        int status;
        waitpid(pid, &status, 0);

        printf("📥 Parent process: Child selesai dengan status %d\n", status);
    }

    return 0;
}
```

🧠 **Penjelasan**:
- Child melakukan loop menghitung 1–5.
- Parent menunggu child selesai dengan `waitpid()`.

---

## 🖼️ Ilustrasi Proses Fork

![Fork Illustration](media/image1.png)

---

## 🎯 Kasus Penggunaan Fork

### 1. 💻 Shell Command Execution
Shell seperti **Bash** memanfaatkan `fork()` + `exec()` untuk menjalankan perintah pengguna.

### 2. 🌐 Web Server
Server seperti **Apache** menggunakan fork untuk menangani banyak koneksi secara paralel.

### 3. ⚙️ Parallel Processing
Tugas berat bisa dibagi ke beberapa proses untuk dijalankan di CPU multi-core.

### 4. 👻 Daemon Process
Fork juga digunakan untuk membuat proses _background_ yang independen dari terminal.

---

## ⚠️ Potensi Masalah dan Solusi

| Masalah             | Penjelasan                                                                 | Solusi                   |
|---------------------|----------------------------------------------------------------------------|--------------------------|
| 🔋 Resource Intensive | Fork menyalin seluruh ruang alamat proses.                                 | Gunakan **thread** atau `vfork()` |
| 🧟 Zombie Process     | Jika child selesai tapi parent tidak memanggil `wait()`, proses jadi zombie. | Gunakan `wait()`/`waitpid()`     |
| 🚫 Data Sharing       | Data antara proses tidak otomatis terhubung.                              | Gunakan **shared memory**, **pipes**, atau **sockets** |

---

## ✅ Kesimpulan

> Fork adalah pilar utama dalam pengembangan aplikasi **konkuren dan paralel** di sistem UNIX/Linux.

✅ Dengan `fork()`, proses bisa berjalan secara bersamaan dan independen.  
🛠️ Implementasi di C mudah dilakukan, namun perlu perhatian khusus terkait manajemen memori dan _process lifecycle_.

---

## 📚 Referensi

1. Stevens, W. R., & Rago, S. A. (2013). *Advanced Programming in the UNIX Environment* (3rd ed.).
2. Kerrisk, M. (2010). *The Linux Programming Interface*.
3. Love, R. (2013). *Linux System Programming* (2nd ed.).
