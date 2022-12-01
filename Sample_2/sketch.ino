Dengan memanggil perangkat kemudi Arduino dan perpustakaan SR04, perangkat kemudi dikendalikan untuk menggerakkan kemudi ultrasonik, dan jarak dalam arah yang berbeda diukur, untuk merencanakan jalur labirin dan melakukan penghalang.

Catatan: Tidak seperti proyek file tunggal sebelumnya, proyek ini dikembangkan menggunakan banyak file, yang meningkatkan keterbacaan kode. Struktur file proyek adalah sebagai berikut:

..\sketch.ino
..\common.ino
..\pengaturan.h

Motor kiri A         = D6
Motor kiriB          = D11
Motor kanan A    = D5
Motor kananB     = D3
GEMA                   = D7
TRIGONOMETRI = D4
Sinyal servo         = D9

Menyederhanakan masalah adalah cara berpikir yang tepat dalam pemrograman.

Pertama-tama, harus ditetapkan bahwa mode mengemudi mobil di lintasan adalah mengemudi lurus dan berbelok ke kanan . Dengan demikian, pada lintasan dengan lebar tertentu, informasi posisi bodi mobil hanya dapat diperoleh dengan mengukur jarak di sisi kanan (atau sisi kiri) bodi mobil. Oleh karena itu, kita hanya perlu mendapatkan jarak di depan badan mobil dan jarak di sisi kanan (atau kiri) untuk merencanakan kondisi jalan mobil dan mewujudkan fungsi berjalan di labirin. Untuk dua jarak ini, kita dapat menetapkan ambang batas dan membuat daftar tabel. Setelah berpikir, kita dapat mengambil keputusan berikut untuk beberapa situasi sederhana:

Bagian depan kurang dari 25cm tidak tidak ya ya
Sisi kanan kurang dari 25cm tidak ya tidak ya
Pengambilan keputusan jalan terus jalan terus belok kanan belok kiri




