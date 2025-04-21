# ⚙️ Manajemen Proses

> Proses adalah program yang sedang dieksekusi – entitas aktif yang membutuhkan sumber daya sistem.

## 🔸 Karakteristik Proses

- Proses membutuhkan sumber daya:
  - CPU, memori, I/O, file
  - Data inisialisasi
- Terminasi proses melepaskan sumber daya.
- **Single-threaded:** satu program counter → eksekusi instruksi satu per satu.
- **Multi-threaded:** satu program counter per thread.
- Banyak proses dapat berjalan bersamaan melalui **multiplexing CPU**.

## 🔹 Aktivitas Manajemen Proses

- Membuat & menghapus proses.
- Menangguhkan & melanjutkan proses.
- Sinkronisasi antar proses.
- Komunikasi antar proses.
- Penanganan deadlock.

---

# 🧠 Manajemen Memori

> Menyimpan dan mengelola instruksi dan data yang digunakan oleh proses.

## 🔸 Tujuan

- Memastikan instruksi & data tersedia di memori saat dibutuhkan.
- Mengoptimalkan penggunaan CPU dan respons sistem.

## 🔹 Aktivitas

- Melacak penggunaan memori dan siapa yang menggunakannya.
- Menentukan data/proses yang dimuat/keluar dari memori.
- Alokasi dan dealokasi memori secara efisien.

---

# 🗂️ Manajemen Sistem Berkas

> Memberikan abstraksi logis dari penyimpanan data fisik dalam bentuk file & direktori.

## 🔸 Konsep Dasar

- Media penyimpanan dikendalikan perangkat (disk, tape).
- Karakteristik: kecepatan akses, kapasitas, metode akses.

## 🔹 Aktivitas OS

- Membuat & menghapus file/direktori.
- Primitive untuk manipulasi file.
- Memetakan file ke penyimpanan sekunder.
- Backup file ke media non-volatile.
- Kontrol akses file.

---

# 💾 Manajemen Penyimpanan Massal

> Menangani penyimpanan jangka panjang dan volume besar data.

## 🔸 Pentingnya

- Disk menyimpan data besar & permanen.
- Kinerja sistem sangat tergantung pada manajemen disk.

## 🔹 Aktivitas OS

- Mounting & unmounting.
- Manajemen ruang kosong.
- Alokasi & penjadwalan disk.
- Partisi & perlindungan data.
- Pengelolaan penyimpanan tersier (CD, tape).

---

# ⚡ Caching

> Menyediakan akses cepat ke data melalui penyimpanan sementara.

## 🔸 Prinsip Dasar

- Data disalin dari media lambat ke media cepat (cache).
- Cache dicek lebih dulu saat mengakses data.

## 🔹 Keuntungan & Tantangan

- Akses lebih cepat jika data ada di cache (cache hit).
- Jika tidak (cache miss), data disalin dulu ke cache.
- Cache lebih kecil dari media aslinya.
- Desain cache:
  - Ukuran cache
  - Kebijakan penggantian (replacement policy)

---
