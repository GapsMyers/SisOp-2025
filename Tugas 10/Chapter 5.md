# **Studi Kasus dan Analisis Penjadwalan Round Robin (RR)**  
*Oleh: Gavin Dwi Aurora Putra*  
*NRP: 3124521018*  

---

## **1. Pendahuluan**  
Round Robin (RR) adalah algoritma penjadwalan berbasis waktu nyata (*real-time*) yang menggunakan **time quantum** sebagai batas waktu eksekusi setiap proses. Algoritma ini memastikan setiap proses mendapat alokasi CPU secara adil, dengan kemampuan preemptive untuk menghindari starvation.  

### **Kelebihan**  
- **Adil**: Setiap proses mendapat alokasi waktu yang sama.  
- **Responsif**: Cocok untuk sistem interaktif.  
- **Mencegah Starvation**: Proses tidak tertunda selamanya.  

### **Kekurangan**  
- **Overhead Context Switching**: Semakin kecil time quantum, semakin tinggi overhead.  
- **Turnaround Time**: Tidak optimal untuk proses CPU-bound.  

---

## **2. Studi Kasus**  
### **Data Proses**  
| Proses | Burst Time (ms) | Arrival Time (ms) |  
|--------|------------------|-------------------|  
| P1     | 5                | 0                 |  
| P2     | 3                | 3                 |  
| P3     | 1                | 5                 |  
| P4     | 7                | 7                 |  
| P5     | 4                | 9                 |  

### **Konfigurasi**  
- **Time Quantum**: 2 ms
- **Proses tiba di waktu berbeda**

## **3. Gantt Chart**  
```plaintext
| P1  | P1  | P2  | P3  | P4  | P5  | P1  | P2  | P4  | P5  | P4  |
0     2     4     5     7     9    11    13    15    17    19    22
```

## **4. Perhitungan Metrik Terperinci**  

### **a. Turnaround Time (TAT)**  
**P1 (Burst Time = 5ms)**:
- Arrival: 0ms
- Eksekusi: 0-2, 4-5, 11-13
- Waktu Selesai: 13ms
- TAT = 13 - 0 = 13ms

**P2 (Burst Time = 3ms)**:
- Arrival: 3ms
- Eksekusi: 4-5, 13-15
- Waktu Selesai: 15ms
- TAT = 15 - 3 = 12ms

**P3 (Burst Time = 1ms)**:
- Arrival: 5ms
- Eksekusi: 5-6
- Waktu Selesai: 6ms
- TAT = 6 - 5 = 1ms

**P4 (Burst Time = 7ms)**:
- Arrival: 7ms
- Eksekusi: 7-9, 15-17, 19-22
- Waktu Selesai: 22ms
- TAT = 22 - 7 = 15ms

**P5 (Burst Time = 4ms)**:
- Arrival: 9ms
- Eksekusi: 9-11, 17-19
- Waktu Selesai: 19ms
- TAT = 19 - 9 = 10ms

### **b. Waiting Time (WT)**  
**P1**: WT = 13 - 5 - 0 = 8ms
- Menunggu saat: 2-4 (2ms), 5-11 (6ms)

**P2**: WT = 15 - 3 - 3 = 9ms
- Menunggu saat: 5-13 (8ms), setelah 15 selesai

**P3**: WT = 6 - 1 - 5 = 0ms
- Tidak ada waktu tunggu

**P4**: WT = 22 - 7 - 7 = 8ms
- Menunggu saat: 9-15 (6ms), 17-19 (2ms)

**P5**: WT = 19 - 4 - 9 = 6ms
- Menunggu saat: 11-17 (6ms)

### **c. Rata-rata Waiting Time**  
$$
\begin{align*}
\text{Rata-rata WT} &= \frac{8 + 9 + 0 + 8 + 6}{5} \\
&= \frac{31}{5} \\
&= 6.2 \text{ ms}
\end{align*}
$$

### **d. CPU Utilization**  
Total Burst Time = 5 + 3 + 1 + 7 + 4 = 20ms
Total Time = 22ms
$$
\begin{align*}
\text{CPU Utilization} &= \frac{\text{Total Burst Time}}{\text{Total Time}} \times 100\% \\
&= \frac{20}{22} \times 100\% \\
&\approx 90.91\%
\end{align*}
$$

### **e. Throughput**  
$$
\begin{align*}
\text{Throughput} &= \frac{\text{Jumlah Proses}}{\text{Total Time}} \\
&= \frac{5 \text{ proses}}{22 \text{ ms}} \\
&\approx 0.227 \text{ proses/ms}
\end{align*}
$$

---

## **5. Analisis Hasil**  
- **Waiting Time**: Rata-rata 6.2 ms, lebih baik daripada FCFS (15.4 ms) tetapi kalah dari SJF (9.2 ms).  
- **Turnaround Time**: Proses P4 memiliki TAT tertinggi (15 ms) karena burst time terbesar.  
- **CPU Utilization**: Baik (90.91%), tetapi ada penurunan dibandingkan skenario sebelumnya.  
- **Throughput**: 0.227 proses/ms, cukup untuk sistem interaktif tetapi tidak efisien untuk proses CPU-bound.  

---

## **6. Perbandingan dengan Algoritma Lain**  
| Algoritma       | Rata-rata WT | TAT Rata-rata | Catatan |  
|------------------|--------------|---------------|---------|  
| **Round Robin**  | 6.2 ms       | 11.2 ms       | Adil, tetapi overhead tinggi. |  
| **FCFS**         | 15.4 ms      | 19.8 ms       | Tidak preemptive, tidak responsif. |  
| **SJF (Non-Preemptive)** | 9.2 ms | 13.6 ms       | Efisien, tetapi tidak real-time. |  

---

## **7. Pengaruh Time Quantum**  
### **Time Quantum = 1 ms**  
- **Context Switching**: 20+ kali → Overhead sangat tinggi.  
- **CPU Utilization**: Turun karena frekuensi switching.  

### **Time Quantum = 10 ms**  
- **Context Switching**: Hanya 5 kali → CPU Utilization >99%.  
- **Kekurangan**: Mirip FCFS karena time quantum besar.  

---

## **8. Real-Time Scheduling**  
### **Rate-Monotonic Scheduling (RMS)**  
- Prioritas statis berdasarkan periode: **periode pendek → prioritas tinggi**.  
- Contoh: Dua proses dengan periode 50 ms (P₁) dan 100 ms (P₂), CPU utilization:  
  $$
  \frac{25}{50} + \frac{35}{80} = 0.94 \, (\text{94%})
  $$  

### **Earliest-Deadline-First (EDF)**  
- Prioritas dinamis berdasarkan deadline: **deadline lebih awal → prioritas lebih tinggi**.  

---

## **9. Kesimpulan**  
1. **Round Robin** cocok untuk sistem yang mengutamakan fairness dan real-time.  
2. **Time Quantum** kritis:  
   - Terlalu kecil → Overhead context switching tinggi.  
   - Terlalu besar → Performa mirip FCFS.  
3. **SJF** lebih optimal untuk waiting time minimal, tetapi tidak real-time.  
4. **Rate-Monotonic** dan **EDF** diperlukan untuk sistem real-time dengan deadline ketat.  

---
