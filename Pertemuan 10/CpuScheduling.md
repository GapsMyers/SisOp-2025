# **Penjadwalan CPU: Analisis Berbagai Algoritma Penjadwalan**

## **5.17 Studi Kasus: Perbandingan Algoritma Penjadwalan CPU**

### **Data Proses Awal**
Berikut adalah daftar proses dengan durasi burst time (waktu eksekusi) dan prioritas masing-masing:

| Proses | Burst Time (ms) | Prioritas |
|--------|------------------|-----------|
| P₁     | 5                | 4         |
| P₂     | 3                | 1         |
| P₃     | 1                | 2         |
| P₄     | 7                | 2         |
| P₅     | 4                | 3         |

> **Catatan:**  
Semua proses tiba pada waktu **0**, dalam urutan: **P₁, P₂, P₃, P₄, P₅**.  
Prioritas yang lebih tinggi ditunjukkan oleh angka yang lebih besar.

---

## **a. Diagram Gantt untuk Setiap Algoritma Penjadwalan**

### **1. First-Come, First-Served (FCFS)**

```
┌────────┬────────┬────────┬────────┬────────┐
│   P₁   │   P₂   │   P₃   │   P₄   │   P₅   │
└────────┴────────┴────────┴────────┴────────┘
0        5        8        9        16       20
```

### **2. Shortest Job First (SJF) - Non-Preemptive**

```
┌────────┬────────┬────────┬────────┬────────┐
│   P₃   │   P₂   │   P₅   │   P₁   │   P₄   │
└────────┴────────┴────────┴────────┴────────┘
0        1        4        8        13       20
```

### **3. Non-Preemptive Priority (Angka prioritas semakin besar = prioritas semakin tinggi)**

```
┌────────┬────────┬────────┬────────┬────────┐
│   P₁   │   P₅   │   P₃   │   P₄   │   P₂   │
└────────┴────────┴────────┴────────┴────────┘
0        5        9        10       17       20
```

### **4. Round Robin (Time Quantum = 2 ms)**

```
┌────────┬────────┬────────┬────────┬────────┬────────┬────────┬────────┬────────┬────────┐
│   P₁   │   P₂   │   P₃   │   P₄   │   P₅   │   P₁   │   P₂   │   P₄   │   P₅   │   P₄   │
└────────┴────────┴────────┴────────┴────────┴────────┴────────┴────────┴────────┴────────┘
0        2        4        5        7        9        11       12       14       16       20
```

---

## **b. Waktu Turnaround untuk Setiap Proses**

Waktu **turnaround** didefinisikan sebagai:
```
Waktu Turnaround = Waktu Selesai - Waktu Kedatangan
```

### **1. FCFS**
| Proses | Waktu Turnaround |
|--------|------------------|
| P₁     | 5                |
| P₂     | 8                |
| P₃     | 9                |
| P₄     | 16               |
| P₅     | 20               |

**Rata-rata Turnaround:** `(5 + 8 + 9 + 16 + 20) / 5 = 11.6 ms`

### **2. SJF**
| Proses | Waktu Turnaround |
|--------|------------------|
| P₁     | 13               |
| P₂     | 4                |
| P₃     | 1                |
| P₄     | 20               |
| P₅     | 8                |

**Rata-rata Turnaround:** `(13 + 4 + 1 + 20 + 8) / 5 = 9.2 ms`

### **3. Non-Preemptive Priority**
| Proses | Waktu Turnaround |
|--------|------------------|
| P₁     | 5                |
| P₂     | 20               |
| P₃     | 10               |
| P₄     | 17               |
| P₅     | 9                |

**Rata-rata Turnaround:** `(5 + 20 + 10 + 17 + 9) / 5 = 12.2 ms`

### **4. Round Robin**
| Proses | Waktu Turnaround |
|--------|------------------|
| P₁     | 11               |
| P₂     | 12               |
| P₃     | 5                |
| P₄     | 20               |
| P₅     | 16               |

**Rata-rata Turnaround:** `(11 + 12 + 5 + 20 + 16) / 5 = 12.8 ms`

---

## **c. Waktu Tunggu untuk Setiap Proses**

Waktu **tunggu** didefinisikan sebagai:
```
Waktu Tunggu = Waktu Turnaround - Burst Time
```

### **1. FCFS**
| Proses | Waktu Tunggu |
|--------|--------------|
| P₁     | 0            |
| P₂     | 5            |
| P₃     | 8            |
| P₄     | 9            |
| P₅     | 16           |

**Rata-rata Waktu Tunggu:** `7.6 ms`

### **2. SJF**
| Proses | Waktu Tunggu |
|--------|--------------|
| P₁     | 8            |
| P₂     | 1            |
| P₃     | 0            |
| P₄     | 13           |
| P₅     | 4            |

**Rata-rata Waktu Tunggu:** `5.2 ms`

### **3. Non-Preemptive Priority**
| Proses | Waktu Tunggu |
|--------|--------------|
| P₁     | 0            |
| P₂     | 17           |
| P₃     | 9            |
| P₄     | 10           |
| P₅     | 5            |

**Rata-rata Waktu Tunggu:** `8.2 ms`

### **4. Round Robin**
| Proses | Waktu Tunggu |
|--------|--------------|
| P₁     | 6            |
| P₂     | 9            |
| P₃     | 4            |
| P₄     | 13           |
| P₅     | 12           |

**Rata-rata Waktu Tunggu:** `8.8 ms`

---

## **d. Algoritma dengan Rata-Rata Waktu Tunggu Terkecil**

Berdasarkan hasil di atas, algoritma dengan rata-rata waktu tunggu terendah adalah:

### ✅ **Shortest Job First (SJF) dengan rata-rata waktu tunggu 5.2 ms**

Perbandingan antar algoritma:
- **FCFS:** 7.6 ms  
- **SJF:** 5.2 ms  
- **Non-Preemptive Priority:** 8.2 ms  
- **Round Robin:** 8.8 ms  

---

## **5.18 Studi Kasus: Penjadwalan Preemptive Berbasis Prioritas dan Round Robin**

### **Data Proses Tambahan**
| Proses | Prioritas | Burst Time (ms) | Arrival Time |
|--------|-----------|------------------|---------------|
| P₁     | 8         | 15               | 0             |
| P₂     | 3         | 20               | 0             |
| P₃     | 4         | 20               | 20            |
| P₄     | 4         | 20               | 25            |
| P₅     | 5         | 5                | 45            |
| P₆     | 5         | 15               | 55            |

> **Keterangan:**  
> - Semakin tinggi nilai prioritas, semakin tinggi juga prioritas prosesnya.  
> - Jika dua proses memiliki prioritas sama, maka digunakan strategi **Round Robin** dengan **time quantum = 10 ms**.  
> - Jika proses dipreempt (terinterupsi), maka akan ditempatkan di akhir antrian.

---

## **a. Urutan Eksekusi dengan Diagram Gantt**

```
┌────────┬────────┬────────┬────────┬────────┬────────┬────────┬────────┬────────┬────────┬────────┐
│   P₁   │   P₁   │   P₃   │   P₃   │   P₃   │   P₅   │   P₆   │   P₆   │   P₄   │   P₄   │   P₂   │
└────────┴────────┴────────┴────────┴────────┴────────┴────────┴────────┴────────┴────────┴────────┘
0        10       20       30       40       50       60       70       80       90      100      110
```

### **Penjelasan Singkat Urutan Eksekusi:**
1. **P₁** dieksekusi pertama karena memiliki prioritas tertinggi.
2. Setelah selesai, **P₂** mulai berjalan hingga ada kedatangan **P₃** (prioritas lebih tinggi).
3. Proses dilanjutkan sesuai prioritas dan aturan round robin jika prioritas sama.
4. Setiap kali proses dipreempt, ia ditempatkan kembali ke belakang antrian.

---

## **b. Waktu Turnaround untuk Setiap Proses**

| Proses | Waktu Turnaround |
|--------|------------------|
| P₁     | 15               |
| P₂     | 110              |
| P₃     | 20               |
| P₄     | 65               |
| P₅     | 5                |
| P₆     | 15               |

---

## **c. Waktu Tunggu untuk Setiap Proses**

| Proses | Waktu Tunggu |
|--------|--------------|
| P₁     | 0            |
| P₂     | 90           |
| P₃     | 0            |
| P₄     | 45           |
| P₅     | 0            |
| P₆     | 0            |

---
