
# 🧬 Sejarah Sistem Operasi – Format Menarik

## A.1 🚀 Migrasi Fitur
Fitur dari sistem operasi komputer besar seperti **MULTICS** kini digunakan pada perangkat kecil seperti mikrokomputer dan smartphone. UNIX yang terinspirasi dari MULTICS menjadi dasar sistem operasi modern seperti Windows, macOS, dan Linux.

## A.2 🖥️ Sistem Awal

### A.2.1 🔧 Sistem Komputer Terdedikasi
- Penggunaan awal perangkat seperti pembaca kartu & pita magnetik.
- Diperlukan assembler, loader, linker, device driver.
- FORTRAN & COBOL memudahkan pemrograman tapi proses tetap rumit.
- Waktu setup lama menyebabkan CPU idle → efisiensi rendah.

### A.2.2 🤖 Sistem Komputer Bersama
- Masalah: Programmer langsung operasikan komputer → tidak efisien.
- Solusi: Operator + batch job → dikendalikan monitor resident & control card (`$JOB`, `$FTN`, `$END`).
- Manfaat: Otomatisasi eksekusi, efisiensi naik.

### A.2.3 🔄 Overlapped I/O
- Gunakan disk sebagai buffer (spooling) → CPU & I/O paralel.
- Menuju ke multiprogramming → dasar OS modern.

## A.3 🧠 Atlas
- Dikembangkan di Manchester (1950-an).
- Fitur: batch + spooling, demand paging, memori virtual.
- Page Replacement: prediksi pola looping + bit referensi.

## A.4 💻 XDS-940
- Time-sharing OS dari UC Berkeley.
- Paging untuk relokasi, berbagi kode antar proses, system call, manajemen memori modern.

## A.5 🏗️ THE
- OS berlapis dari Eindhoven, Belanda.
- Menggunakan semafor, proses statis, antrian input batch.
- Penjadwalan prioritas & paging berbasis perangkat lunak.

## A.6 🧩 RC 4000
- Kernel modular, proses komunikatif via pesan, round-robin.
- Perangkat I/O juga diperlakukan sebagai proses.

## A.7 ⌨️ CTSS
- Time-sharing awal (MIT, 1961).
- 32 pengguna, IBM 7090, penjadwalan multilevel feedback queue.

## A.8 🔐 MULTICS
- Layanan komputasi seperti utilitas umum.
- Konsep: paged segmentation, virtual address ↔ file system, keamanan proses.
- Menginspirasi UNIX.

## A.9 🏢 IBM OS/360
- Menyatukan platform IBM, dukungan virtual memory.
- Tantangan: arsitektur kompleks, kegagalan TSS/360, pergeseran ke PC.

## A.10 📟 TOPS-20
- Time-sharing populer di PDP-10.
- Fitur virtual memory & interactive CLI.
- Digantikan oleh sistem 32-bit seperti VAX/VMS.

## A.11 💾 CP/M & MS-DOS
- CP/M untuk Intel 8080 → digantikan MS-DOS untuk 8086.
- MS-DOS mendominasi PC meskipun minim proteksi memori.

## A.12 🖱️ Macintosh & Windows
- Apple pelopor GUI, kalah bersaing dengan Windows.
- PC menyamai mainframe → era baru server.

## A.13 🧪 Mach
- Microkernel dari CMU (pengganti BSD).
- Dukungan multiprosesor, komunikasi pesan, memori virtual.
- Digunakan di macOS & iOS (XNU kernel).

## A.14 🔐 Sistem Berbasis Kapabilitas

### A.14.1 Hydra
- Hak akses via kapabilitas, kontrol akses ketat, modular.
- Dukung prosedur dengan hak akses terbatas.

### A.14.2 Cambridge CAP
- Microcode + software capability.
- Sistem eksperimen, butuh pemahaman mendalam.

## A.15 🧬 Sistem Lainnya
- MCP (Burroughs), SCOPE (CDC 6600), dan lainnya pernah dominan.
- Digantikan oleh OS baru seiring kemajuan hardware & teknologi.
