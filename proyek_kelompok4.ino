// Deklarasi pin sensor ultrasonik
const int trigPin = 4;
const int echoPin = 3;

// Deklarasi pin sensor suara
const int soundPin = 2;
volatile bool flag = 0;

void setup() {
  // Mengaktifkan Serial Monitor
  Serial.begin(9600);
  
  // Mengatur pin trigPin sebagai output dan echoPin sebagai input
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  
  // Mengatur pin soundPin sebagai input
  pinMode(soundPin, INPUT);
  Serial.println("1");
  attachInterrupt(digitalPinToInterrupt(2), DOR, RISING);
  Serial.println("2");
}

void loop() {
  // Membaca jarak dari sensor ultrasonik
  long duration, distance;
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  //Serial.println("3");
  duration = pulseIn(echoPin, HIGH);
  distance = (duration / 2) / 29.1; // Menghitung jarak dalam centimeter
  
  // Membaca input dari sensor suara
  
 //Serial.println(distance);
  if (distance < 20 && flag) {
    flag=0;
    Serial.println("Kucing terdeteksi!");
    // Tambahkan aksi yang ingin dilakukan ketika kucing terdeteksi di sini
  }
  delay(10);
  
}

void ASU(){
  flag=1;
}
