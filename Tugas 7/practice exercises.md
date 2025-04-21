# 📘 Practice Exercises - Chapter 4: Threads & Concurrency

## 🔹 4.1 - Multithreading vs Single-threaded Examples

Berikut tiga contoh program yang menunjukkan performa lebih baik jika menggunakan multithreading:

1. **Web Server**
   - Menangani banyak permintaan klien secara bersamaan.
   - Setiap thread bisa melayani satu klien tanpa memblokir yang lain.

2. **Aplikasi Pengolahan Gambar/Video**
   - Misalnya dalam filter atau pengeditan, bagian-bagian gambar diproses paralel.

3. **Compiler**
   - Fase-fase seperti parsing, semantic analysis, dan optimasi bisa dilakukan di thread berbeda.

---

## 🔹 4.2 - Amdahl’s Law & Speedup Calculation

**Rumus Amdahl’s Law:**

\[
\text{Speedup} = \frac{1}{(1 - P) + \frac{P}{N}}
\]

Dengan:
- \(P = 0.6\) (60% dari aplikasi bisa diparalelkan)
- \(N = \) jumlah core

### a) 2 Core

\[
\text{Speedup} = \frac{1}{(1 - 0.6) + \frac{0.6}{2}} = \frac{1}{0.4 + 0.3} = \frac{1}{0.7} ≈ \textbf{1.43}
\]

### b) 4 Core

\[
\text{Speedup} = \frac{1}{(1 - 0.6) + \frac{0.6}{4}} = \frac{1}{0.4 + 0.15} = \frac{1}{0.55} ≈ \textbf{1.82}
\]

---

## 🔹 4.3 - Web Server Parallelism Type

Web server multithreaded dari Section 4.1 menunjukkan **Task Parallelism**:
- Setiap thread menangani tugas berbeda (permintaan HTTP dari klien yang berbeda).

---

## 🔹 4.4 - User-level vs Kernel-level Threads

| Aspek                    | User-Level Threads                          | Kernel-Level Threads                          |
|--------------------------|---------------------------------------------|-----------------------------------------------|
| Manajemen                | Diatur oleh pustaka di user space           | Diatur langsung oleh kernel                   |
| Switching                | Lebih cepat, tidak perlu trap ke kernel     | Lebih lambat karena melalui kernel            |
| Blocking                 | Satu thread block → semua ikut terblokir    | Bisa memilih thread lain saat satu blocking   |
| Kapan digunakan?         | Cocok untuk aplikasi ringan & cepat switch | Cocok untuk aplikasi multithreading kompleks  |

---

## 🔹 4.5 - Context Switching Antar Kernel Threads

Langkah-langkah context switching oleh kernel:
1. Simpan status thread aktif (register, counter, dsb).
2. Perbarui tabel penjadwalan kernel.
3. Muat status thread tujuan.
4. Pindahkan kontrol eksekusi ke thread baru.

---

## 🔹 4.6 - Resource Thread vs Process

- **Thread**:
  - Stack sendiri
  - Thread Control Block (TCB)
  - Berbagi memori, file descriptor, dan context proses

- **Process**:
  - Memiliki seluruh ruang alamat sendiri (heap, stack, code, dll)
  - Isolasi penuh → lebih berat dibanding thread

---

## 🔹 4.7 - Real-Time Thread & LWP

Jika sistem menggunakan **many-to-many model** dengan **LWP (Lightweight Process)**:

✅ **Real-time thread perlu di-bind ke LWP**  
→ Karena hanya dengan binding, kernel bisa langsung menjadwalkan dan memastikan deadline real-time terpenuhi.

Tanpa binding, thread real-time bisa saja tertunda oleh scheduler user-level.

---
