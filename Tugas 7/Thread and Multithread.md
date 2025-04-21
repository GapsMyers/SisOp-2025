# Single Thread vs Multithread

## Single Thread

### Pengertian
Single Thread adalah model eksekusi di mana sebuah proses hanya memiliki **satu jalur eksekusi**. Tugas-tugas dalam program dijalankan secara berurutan (satu per satu).

### Karakteristik
- Eksekusi tugas bersifat **sekuensial** (tidak ada paralelisasi).
- Jika satu tugas memakan waktu lama, tugas berikutnya harus menunggu.
- Sederhana dalam implementasi dan debugging.

### Kelebihan
| ✅ | ❌ |
|----|----|
| Mudah dipahami dan di-debug | Tidak efisien untuk operasi berskala besar |
| Tidak perlu sinkronisasi data | Responsivitas rendah untuk aplikasi kompleks |

### Contoh Penggunaan
- Program sederhana (kalkulasi matematis dasar).
- Aplikasi dengan operasi ringan yang tidak memerlukan paralelisasi.

---

## Multithread

### Pengertian
Multithread memungkinkan program menjalankan **beberapa thread (jalur eksekusi)** secara bersamaan, baik secara paralel (pada CPU multi-core) maupun konkuren.

### Karakteristik
- Meningkatkan kinerja dan responsivitas aplikasi.
- Memungkinkan pembagian sumber daya antar thread.
- Membutuhkan manajemen kompleks seperti sinkronisasi.

### Kelebihan
| ✅ | ❌ |
|----|----|
| Efisiensi tinggi pada CPU multi-core | Risiko `race condition` dan deadlock |
| Cocok untuk operasi I/O atau tugas berat | Kompleksitas implementasi lebih tinggi |
| Responsivitas aplikasi lebih baik | Konsumsi memori lebih besar |

### Contoh Penggunaan
- Server web (menangani banyak permintaan sekaligus).
- Aplikasi GUI (menjaga antarmuka tetap responsif).
- Game dan pemrosesan multimedia.

---

## Perbandingan Singkat
| Aspek              | Single Thread          | Multithread            |
|---------------------|------------------------|------------------------|
| **Eksekusi**        | Sekuensial             | Paralel/Konkuren       |
| **Kompleksitas**    | Rendah                 | Tinggi                 |
| **Efisiensi**       | Optimal untuk tugas kecil | Unggul untuk tugas berat |
| **Risiko**          | Tidak ada race condition | Perlu manajemen thread |
| **Penggunaan CPU**  | Kurang optimal         | Optimal (multi-core)   |

---

> **Catatan**: Pemilihan model tergantung pada kebutuhan aplikasi. Single Thread cocok untuk tugas sederhana, sementara Multithread diperlukan untuk optimasi performa pada operasi kompleks.
