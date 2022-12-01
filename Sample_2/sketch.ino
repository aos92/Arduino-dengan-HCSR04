// Panggil perpustakaan dan file header lainnya
#include <Servo.h>
#include <SR04.h>
#include "setting.h"

// Koneksi pin arduino
int carLeftA = 6;
int carLeftB = 11;
int carRightA = 5;
int carRightB = 3;

// Inisialisasi perangkat ultrasonik dan kemudi
SR04 sr04 = SR04(ECHO_PIN, TRIG_PIN);
Servo servoUltraSonic;

void setup()
{
  // Konrksi servo
  servoUltraSonic.attach(9);
  // Penundaan, mudah dioperasikan
  delay(1000);
  /*
  Menurut dokumentasi resmi, gunakan pin fungsi analogWrite(), * Anda tidak dapat menggunakan pinMode() untuk menginisialisasi, sehingga dihilangkan. 
  */
}
void loop()
{
  // Deklarasikan dua variabel long integer untuk menyimpan hasil pengukuran jarak depan dan kanan.
  long forwardDistance = 0;
  long rightDistance = 0;
  // Panggil fungsi untuk mengukur jarak ke depan
  forwardDistance = controlServoAndGetDistance(FORWARD);
  if (forwardDistance >= 25)
  {
    // Jika jarak di depan lebih dari 25cm, teruslah bergerak maju.
    forward();
  }
  else
  {
    // Jika jarak di depan kurang dari 25cm, berhenti dan ukur jarak ke kanan.
    brake();
    rightDistance = controlServoAndGetDistance(RIGHT);
    if (rightDistance >= 25)
    {
      // Jika jarak ke kanan lebih dari 25cm, belok kanan.
      turn(RIGHT);
    }
    else
    {
      // Jika jarak ke kanan kurang dari 25cm, belok kiri.
      turn(LEFT);
    }
  }
}
