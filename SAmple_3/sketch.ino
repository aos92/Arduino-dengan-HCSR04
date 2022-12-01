// Pertama panggil perpustakaan kelas ultrasonik dengan mendeklarasikan
#include <SR04.h>

// Berikut beberapa definisi makro yang membantu keterbacaan program.
// Anda dapat mengabaikannya, membaca program dengan hati-hati dan Anda akan memahami tujuannya.
#define LEFT 0
#define RIGHT 1
#define FORWARD 2
#define BACK 3

// Tentukan beberapa pin sensor ultrasonik
#define TRIG_PIN 4
#define ECHO_PIN 7

// Tentukan kecepatan motor penggerak, 255 adalah yang tertinggi dan 0 adalah yang terendah. Memodifikasi nilai ini akan mengubah kecepatan.
#define SPEED 70

// Tentukan beberapa pin motor penggerak troli Perlu dicatat bahwa hanya pin 3, 5, 9, 10, 11, dll. yang dapat menghasilkan PWM.
int carLeftA = 6;
int carLeftB = 11;
int carRightA = 5;
int carRightB = 3;

// Tentukan variabel yang menyimpan jarak yang diukur oleh gelombang ultrasonik.
long distance;

// Panggil fungsi inisialisasi ultrasonik, pernyataan spesifik, tidak perlu menghafal, cukup periksa program sampel saat menggunakannya.
SR04 sr04 = SR04(ECHO_PIN, TRIG_PIN);
void setup()
{
 // Konfigurasikan beberapa pin yang digerakkan oleh motor mobil.
 // Perlu dicatat bahwa meskipun beberapa pin gelombang ultrasonik digunakan.
 // Tapi karena sudah diinisialisasi di perpustakaan ultrasonik, tidak perlu mengulang konfigurasi.
  pinMode(carLeftA, OUTPUT);
  pinMode(carLeftB, OUTPUT);
  pinMode(carRightA, OUTPUT);
  pinMode(carRightB, OUTPUT);
}

// Ulangi program, terus jalankan
void loop()
{
  // Pertama gunakan jarak ultrasonik yang diukur.
  distance = sr04.Distance();
  // Lalu nilai jaraknya.
  if (distance <= 20)
  {
    // Jika jaraknya kurang dari 20CM.
    // Panggil fungsi speedControl di bawah untuk mengonfigurasi arah lari kedua motor.
    speedControl(RIGHT, BACK);
    speedControl(LEFT, BACK);
  }
  else if (20 < distance && distance < 50)
  {
   // Jika jaraknya 20-50CM, maju.
    speedControl(RIGHT, FORWARD);
    speedControl(LEFT, FORWARD);
  }
  else if (distance >= 50)
  {
    // Jika jaraknya lebih dari 50, berhenti.
    analogWrite(carLeftA, 0);
    analogWrite(carLeftB, 0);
    analogWrite(carRightA, 0);
    analogWrite(carRightB, 0);
  }
  // Kemudian jalankan loop berikutnya.
}

void speedControl(int side, int dir)
{
  // Ini adalah fungsi kontrol motor yang mudah dipahami oleh program.
  // Ini memiliki dua parameter, yang pertama adalah pemilihan motor, dan yang kedua adalah arah operasi.
  // Tentu saja, Anda juga dapat memindahkan beberapa pernyataan dalam program ini ke loop untuk mencapai efek yang sama.
  if (LEFT == side)
  {
      // Pertama tentukan motor mana yang akan dikendalikan.
    if (FORWARD == dir)
    {
      // Tentukan arah mana untuk menjalankan motor. 
      // Output analog digunakan di sini, dan esensinya adalah untuk menampilkan PWM.
      analogWrite(carLeftA, SPEED);
      analogWrite(carLeftB, 0);
    }
    else if (BACK == dir)
    {
      analogWrite(carLeftA, 0);
      analogWrite(carLeftB, SPEED);
    }
  }
  else if (RIGHT == side)
  {
    if (FORWARD == dir)
    {
      analogWrite(carRightA, 0);
      analogWrite(carRightB, SPEED);
    }
    else if (BACK == dir)
    {
      analogWrite(carRightA, SPEED);
      analogWrite(carRightB, 0);
    }
  }
}
