# Programming Exercise

---

## a. Penerapan Thread pada `SumTask.java`

- **Deskripsi:**  
  Di file `SumTask.java`, program memanfaatkan **multithreading** untuk membagi pekerjaan penjumlahan array ke beberapa thread.  
  - Kelas `SumTask` mengimplementasikan **Runnable** dan menghitung sebagian data array.  
  - Dengan menggunakan **Thread**, program memproses bagian-bagian array secara paralel, lalu hasilnya dijumlahkan kembali oleh thread utama.  

- **Manfaat:**  
  Pendekatan ini menunjukkan bagaimana **multithreading** meningkatkan performa komputasi data besar dengan membagi tugas menjadi beberapa bagian yang dieksekusi secara bersamaan.

---

## b. Penerapan Thread di Linux (`thrd-posix.c`) dan Windows (`thrd-win32.c`)

### 1. **`thrd-posix.c` (Linux)**

- **Pendekatan:**  
  Menggunakan pustaka **POSIX thread (pthread)**.  
  - Fungsi `pthread_create()` digunakan untuk membuat thread baru.  
  - Fungsi `pthread_join()` digunakan untuk menunggu thread selesai.  

- **Keunggulan:**  
  Ini adalah metode standar untuk **multithreading** di sistem **UNIX-like**, cocok untuk aplikasi server dan pemrosesan paralel.

---

### 2. **`thrd-win32.c` (Windows)**

- **Pendekatan:**  
  Menggunakan **Windows API** dengan fungsi `CreateThread()` untuk membuat thread baru.  
  - Thread dijalankan dengan **fungsi callback**.  
  - Sinkronisasi dilakukan dengan `WaitForSingleObject()`.

- **Perbedaan:**  
  Meski fungsionalitasnya mirip dengan **POSIX**, struktur dan parameter Windows API lebih spesifik dan berbasis **handle** sistem operasi Windows.

---

## 🔑 Kesimpulan

- **Perspektif Multiplatform:**  
  Kedua file (`thrd-posix.c` dan `thrd-win32.c`) menunjukkan bagaimana thread diimplementasikan dalam lingkungan yang berbeda.  
  - **Linux:** Menggunakan pustaka **POSIX thread**.  
  - **Windows:** Menggunakan **Windows API**.

- **Portabilitas Program:**  
  Penting untuk memahami bagaimana **threading** bekerja di masing-masing sistem operasi untuk membuat program yang **portabel**.
