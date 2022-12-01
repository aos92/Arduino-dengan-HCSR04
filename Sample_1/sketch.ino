// Pelacakan garis hitam untuk mobil pintar

int Left_motor_go = 6; // motor kiri maju (IN1)
int Left_motor_back = 11; // motor kiri belakang (IN2)
int Right_motor_go = 5;   // kanan motor maju (IN3)
int Right_motor_back = 3; // motor kanan kembali (IN4)

const int SensorRight = 1; // sensor inframerah pelacakan kanan
const int SensorLeft = 2; // sensor inframerah pelacakan kiri

int SL; // Status sensor inframerah pelacakan kiri
int SR; // Status sensor inframerah pelacakan kanan

void setup()
{
  // Inisialisasi penggerak motor IO sebagai mode output
  pinMode(Left_motor_go, OUTPUT);    // PIN 5 (PWM)
  pinMode(Left_motor_back, OUTPUT);  // PIN 9 (PWM)
  pinMode(Right_motor_go, OUTPUT);   // PIN 10 (PWM)
  pinMode(Right_motor_back, OUTPUT); // PIN 11 (PWM)

  pinMode(SensorRight, INPUT); // Menentukan sensor infra merah sebagai input
  pinMode(SensorLeft, INPUT);  // Menentukan sensor infra merah sebagai input
}

// Maju
void goStraight()
{
  //Motor kanan maju
  analogWrite(Right_motor_go, 60); // Rasio PWM 0~255 pengaturan kecepatan, perbedaan antara roda kiri dan kanan bertambah atau berkurang sedikit
  analogWrite(Right_motor_back, 0);
  
  // Motor kiri maju
  analogWrite(Left_motor_go, 60); // Rasio PWM 0~255 pengaturan kecepatan, perbedaan antara roda kiri dan kanan bertambah atau berkurang sedikit
  analogWrite(Left_motor_back, 0);
}

// Rem, Berhenti
void brake()
{
  digitalWrite(Right_motor_go, LOW);
  digitalWrite(Right_motor_back, LOW);
  digitalWrite(Left_motor_go, LOW);
  digitalWrite(Left_motor_back, LOW);
}

// Belok kiri (roda kiri tidak bergerak, roda kanan bergerak maju)
void turnLeft()
{
  // Motor kanan maju
  analogWrite(Right_motor_go, 60);
  analogWrite(Right_motor_back, 0); // Rasio PWM 0~255 pengaturan kecepatan
  
  // roda kiri tidak bergerak
  analogWrite(Left_motor_go, 0);
  analogWrite(Left_motor_back, 0); // Rasio PWM 0~255 pengaturan kecepatan
}

// Belok kanan (roda kanan tidak bergerak, roda kiri bergerak maju)
void turnRight()
{
  // Roda kanan tidak bergerak
  analogWrite(Right_motor_go, 0);
  analogWrite(Right_motor_back, 0); // Rasio PWM 0~255 pengaturan kecepatan
  
  // Motor kiri maju
  analogWrite(Left_motor_go, 60);
  analogWrite(Left_motor_back, 0); // Rasio PWM 0~255 pengaturan kecepatan
}

void loop()
{
  // Pembacaan digital RENDAH menunjukkan bahwa sensor berada di area putih, dan lampu indikator sensor menyala; pembacaan digital TINGGI menunjukkan bahwa sensor berada di area hitam, dan indikator sensor mati
  SL = digitalRead(SensorLeft);
  SR = digitalRead(SensorRight);

  if (SL == LOW && SR == LOW)
    // memanggil fungsi penerusan
    goStraight();
  else if (SL == HIGH & SR == LOW)
    // Sensor inframerah pelacakan kiri mendeteksi sinyal, mobil menyimpang dari lintasan ke kanan dan berbelok ke kiri
    turnLeft();
  else if (SR == HIGH & SL == LOW)
    // Sensor infra merah pelacakan kanan mendeteksi sinyal, mobil menyimpang dari lintasan ke kiri dan berbelok ke kanan
    turnRight();
  else
    // bila serba hitam, berhenti
    brake();
}
