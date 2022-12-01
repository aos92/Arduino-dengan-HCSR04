// File ini berisi beberapa fungsi kontrol umum 

// @nama fungsi: void speedControl(int side, int dir);
// @param: param opsional sisi: LEFT / RIGHT

// dir parameter opsional: FORWARD / BACK / STOP

// @Catatan: Parameter "MISTAKE" digunakan untuk menyempurnakan kecepatan kedua motor,

// Dalam contoh, roda kanan lebih lambat, jadi 5 ditambahkan saat menetapkan nilai ke roda kanan,

// Nilai ini harus disesuaikan dengan benar sesuai dengan situasi sebenarnya. 


#define MISTAKE 5
void speedControl(int side, int dir)
{
  int A, B;
  int s;
  if (LEFT == side)
  {
    A = carLeftA;
    B = carLeftB;
    s = SPEED;
  }
  else if (RIGHT == side)
  {
    A = carRightA;
    B = carRightB;
    s = SPEED + MISTAKE;
  }
  if (FORWARD == dir)
  {
    analogWrite(A, s);
    analogWrite(B, 0);
  }
  else if (BACK == dir)
  {
    analogWrite(A, 0);
    analogWrite(B, s);
  }
  else if (STOP == dir)
  {
    analogWrite(A, 0);
    analogWrite(B, 0);
  }
}
// @nama fungsi: void turn(int dir); 
// @param: dir param opsional: KIRI / KANAN 
// @Catatan: Parameter "TURN_TIME" digunakan untuk mengatur waktu tunda satu putaran, 
// Telah digunakan untuk secara tepat mengontrol sudut khusus 90 derajat, 
// 450 md digunakan dalam contoh, yang perlu disetel sesuai dengan situasi sebenarnya. 

#define TURN_TIME 450
void turn(int dir)
{
  if (LEFT == dir)
  {
    speedControl(RIGHT, FORWARD);
    speedControl(LEFT, BACK);
    delay(TURN_TIME);
    brake();
  }
  else if (RIGHT == dir)
  {
    speedControl(LEFT, FORWARD);
    speedControl(RIGHT, BACK);
    delay(TURN_TIME);
    brake();
  }
  else
  {
    // do nothing
  }
}

/) @nama fungsi: rem(); 
// @param: Tidak ada 
// @Keterangan: Enkapsulasi fungsi parkir untuk memudahkan panggilan.

void brake()
{
  speedControl(LEFT, STOP);
  speedControl(RIGHT, STOP);
}

// @nama fungsi: maju(); 
// @param: Tidak ada 
// @Keterangan: Enkapsulasi fungsi teruskan untuk pemanggilan mudah.

void forward()
{
  speedControl(RIGHT, FORWARD);
  speedControl(LEFT, FORWARD);
}

// @nama fungsi: mundur(); 
// @param: Tidak ada 
// @Keterangan: Enkapsulasi fungsi kembali untuk memudahkan pemanggilan, tidak digunakan dalam proyek ini.

void backward()
{
  speedControl(RIGHT, BACK);
  speedControl(LEFT, BACK);
}
/* 
// @nama fungsi: long controlServoAndGetDistance(int dir); 
// @parameters: dir parameter opsional: FORWARD / LEFT / RIGHT
// @return value: nilai rata-rata rentang bilangan bulat panjang 
// @Catatan: Setelah parameter "dir" diberikan, perangkat kemudi akan diputar ke sudut yang ditentukan, 
// Pada contoh, nilai servo alignment adalah 97, 
// 180 ke left, 19 ke right, 
// Harus disesuaikan sesuai dengan situasi aktual. 
// Pada contoh, arah LEFT tidak digunakan. */
long controlServoAndGetDistance(int dir)
{
  long disAvg = 999;
  if (FORWARD == dir)
  {
    servoUltraSonic.write(97);
  }
  else if (LEFT == dir)
  {
    servoUltraSonic.write(180);
  }
  else if (RIGHT == dir)
  {
    servoUltraSonic.write(19);
  }
  else
  {
    // do nothing
  }
  // Fungsi delay ini untuk menunggu steering gear selesai. penundaan (500); 
  // Panggil metode pengambilan sampel rata-rata perpustakaan SR04. Metode ini mengambil sampel 5 kali dengan interval 25 md, menghilangkan nilai maksimum dan minimum, dan mengambil nilai rata-rata.
  disAvg = sr04.DistanceAvg(25, 5);
  return disAvg;
}
