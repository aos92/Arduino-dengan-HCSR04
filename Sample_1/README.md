Ada dua pasang sensor fotolistrik inframerah kiri dan kanan yang dipasang di depan mobil. Ketika sepasang sensor bertemu dengan garis hitam, cahayanya benar-benar terserap dan tidak ada cahaya kembali. Pada saat ini, sepasang sensor lsinnya tidak menerima mengembalikan informasi dan menghasilkan tingkat tinggi. Sebaliknya, ketika sepasang sensor menemuii garis putih, outputnya rendah.

Output dari dua pasangan sensor  fotolistrik inframerah dapat digabungkan menjadi empat status (00, 01, 10, 11), dan instruksi yang berbeda diberikan ke mobil sesuai dengan status yang berbeda

00 = Maju
01 = Belok  kanan
10 = Belok kiri
11 = Rem

Pin untuk membaca sinyal dari pasangan fotolistrik inframerah dapat dihubungkan ke pin keluaran digital apa pun dari Arduino.

Karena motor perlu dikontrol oleh gelombang PWM, pin (D3, D5, D6, D9, D10, D11) yang mampu mengeluarkan gelombang PWM harus digunakan.



