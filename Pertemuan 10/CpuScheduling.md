Tentu! Berikut adalah **versi lengkap file `.md` (Markdown)** yang sudah saya perbaiki strukturnya agar lebih **rapi, profesional, dan mudah dibaca**.

---

### 📄 File: `CPU_Scheduling.md`

```markdown
# CPU Scheduling – Latihan Soal

## Soal 5.17: Analisis Algoritma Penjadwalan

Diberikan kumpulan proses sebagai berikut:

| Proses | Burst Time (ms) | Prioritas |
|--------|------------------|-----------|
| P₁     | 5                | 4         |
| P₂     | 3                | 1         |
| P₃     | 1                | 2         |
| P₄     | 7                | 2         |
| P₅     | 4                | 3         |

> **Catatan:**  
> - Semua proses tiba pada waktu `t = 0`.  
> - Urutan kedatangan: P₁ → P₂ → P₃ → P₄ → P₅.  
> - Prioritas **lebih tinggi** ditunjukkan oleh angka **lebih besar**.

---

### a. Gantt Chart untuk Berbagai Algoritma

#### 1. First-Come, First-Served (FCFS)

```
┌────────┬────────┬────────┬────────┬────────┐
│   P₁   │   P₂   │   P₃   │   P₄   │   P₅   │
└────────┴────────┴────────┴────────┴────────┘
0        5        8        9        16       20
```

#### 2. Shortest Job First (SJF) – Non-preemptive

```
┌────────┬────────┬────────┬────────┬────────┐
│   P₃   │   P₂   │   P₅   │   P₁   │   P₄   │
└────────┴────────┴────────┴────────┴────────┘
0        1        4        8        13       20
```

#### 3. Non-Preemptive Priority Scheduling  
(Prioritas makin tinggi = Angka makin besar)

```
┌────────┬────────┬────────┬────────┬────────┐
│   P₁   │   P₅   │   P₃   │   P₄   │   P₂   │
└────────┴────────┴────────┴────────┴────────┘
0        5        9        10       17       20
```

#### 4. Round Robin (Time Quantum = 2 ms)

```
┌────────┬────────┬────────┬────────┬────────┬────────┬────────┬────────┬────────┬────────┐
│   P₁   │   P₂   │   P₃   │   P₄   │   P₅   │   P₁   │   P₂   │   P₄   │   P₅   │   P₄   │
└────────┴────────┴────────┴────────┴────────┴────────┴────────┴────────┴────────┴────────┘
0        2        4        5        7        9        11       12       14       16       20
```

---

### b. Waktu Turnaround untuk Setiap Proses  
Waktu turnaround = waktu selesai – waktu kedatangan

#### 1. FCFS
- P₁: 5 – 0 = **5**
- P₂: 8 – 0 = **8**
- P₃: 9 – 0 = **9**
- P₄: 16 – 0 = **16**
- P₅: 20 – 0 = **20**

✅ Rata-rata Turnaround:  
(5 + 8 + 9 + 16 + 20) / 5 = **11.6 ms**

#### 2. SJF
- P₁: 13 – 0 = **13**
- P₂: 4 – 0 = **4**
- P₃: 1 – 0 = **1**
- P₄: 20 – 0 = **20**
- P₅: 8 – 0 = **8**

✅ Rata-rata Turnaround:  
(13 + 4 + 1 + 20 + 8) / 5 = **9.2 ms**

#### 3. Non-Preemptive Priority
- P₁: 5 – 0 = **5**
- P₂: 20 – 0 = **20**
- P₃: 10 – 0 = **10**
- P₄: 17 – 0 = **17**
- P₅: 9 – 0 = **9**

✅ Rata-rata Turnaround:  
(5 + 20 + 10 + 17 + 9) / 5 = **12.2 ms**

#### 4. Round Robin
- P₁: 11 – 0 = **11**
- P₂: 12 – 0 = **12**
- P₃: 5 – 0 = **5**
- P₄: 20 – 0 = **20**
- P₅: 16 – 0 = **16**

✅ Rata-rata Turnaround:  
(11 + 12 + 5 + 20 + 16) / 5 = **12.8 ms**

---

### c. Waktu Tunggu untuk Setiap Proses  
Waktu tunggu = waktu turnaround – burst time

#### 1. FCFS
- P₁: 5 – 5 = **0**
- P₂: 8 – 3 = **5**
- P₃: 9 – 1 = **8**
- P₄: 16 – 7 = **9**
- P₅: 20 – 4 = **16**

✅ Rata-rata Waktu Tunggu:  
(0 + 5 + 8 + 9 + 16) / 5 = **7.6 ms**

#### 2. SJF
- P₁: 13 – 5 = **8**
- P₂: 4 – 3 = **1**
- P₃: 1 – 1 = **0**
- P₄: 20 – 7 = **13**
- P₅: 8 – 4 = **4**

✅ Rata-rata Waktu Tunggu:  
(8 + 1 + 0 + 13 + 4) / 5 = **5.2 ms**

#### 3. Non-Preemptive Priority
- P₁: 5 – 5 = **0**
- P₂: 20 – 3 = **17**
- P₃: 10 – 1 = **9**
- P₄: 17 – 7 = **10**
- P₅: 9 – 4 = **5**

✅ Rata-rata Waktu Tunggu:  
(0 + 17 + 9 + 10 + 5) / 5 = **8.2 ms**

#### 4. Round Robin
- P₁: 11 – 5 = **6**
- P₂: 12 – 3 = **9**
- P₃: 5 – 1 = **4**
- P₄: 20 – 7 = **13**
- P₅: 16 – 4 = **12**

✅ Rata-rata Waktu Tunggu:  
(6 + 9 + 4 + 13 + 12) / 5 = **8.8 ms**

---

### d. Kesimpulan: Algoritma dengan Waktu Tunggu Terkecil

Dari semua algoritma di atas, **Shortest Job First (SJF)** menghasilkan **rata-rata waktu tunggu terkecil**, yaitu **5.2 ms**.

📊 Perbandingan:
- FCFS: 7.6 ms
- SJF: 5.2 ms ← **Terbaik**
- Non-Preemptive Priority: 8.2 ms
- Round Robin: 8.8 ms

---

## Soal 5.18: Preemptive Priority-Based Round-Robin Scheduling

### Informasi Proses

| Proses | Prioritas | Burst Time (ms) | Arrival Time |
|--------|-----------|------------------|--------------|
| P₁     | 8         | 15               | 0            |
| P₂     | 3         | 20               | 0            |
| P₃     | 4         | 20               | 20           |
| P₄     | 4         | 20               | 25           |
| P₅     | 5         | 5                | 45           |
| P₆     | 5         | 15               | 55           |

> **Aturan Penjadwalan:**
> - Prioritas lebih tinggi ditunjukkan oleh angka lebih besar.
> - Jika prioritas sama, gunakan round-robin.
> - Time quantum = 10 ms.
> - Saat dipreempt, proses dimasukkan ke akhir antrian.

---

### a. Gantt Chart Hasil Eksekusi

```
┌────────┬────────┬────────┬────────┬────────┬────────┬────────┬────────┬────────┬────────┬────────┐
│   P₁   │   P₁   │   P₃   │   P₃   │   P₃   │   P₅   │   P₆   │   P₆   │   P₄   │   P₄   │   P₂   │
└────────┴────────┴────────┴────────┴────────┴────────┴────────┴────────┴────────┴────────┴────────┘
0        10        20        30        40        50        60        70        80        90       100       110
```

---

### b. Waktu Turnaround untuk Setiap Proses

- P₁: 15 – 0 = **15**
- P₂: 110 – 0 = **110**
- P₃: 40 – 20 = **20**
- P₄: 90 – 25 = **65**
- P₅: 50 – 45 = **5**
- P₆: 70 – 55 = **15**

---

### c. Waktu Tunggu untuk Setiap Proses

- P₁: 15 – 15 = **0**
- P₂: 110 – 20 = **90**
- P₃: 20 – 20 = **0**
- P₄: 65 – 20 = **45**
- P₅: 5 – 5 = **0**
- P₆: 15 – 15 = **0**
```

---
