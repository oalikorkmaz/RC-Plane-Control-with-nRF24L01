//yükseliş D3
//Kanatçıklar D4,D5
//Yön Dümeni D6

#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>
#include <Servo.h>

int motor = 0;
int yonDumeni = 0;
int kanatcikSol = 0;
int kanatcikSag = 0;
int yukselisDumeni = 0;

Servo motorServo;
Servo yonDumeniServo;
Servo kanatcikServoSol;
Servo kanatcikServoSag;
Servo yukselisDumeniServo;

struct Signal {
byte throttle;
byte pitch;
byte roll;
byte yaw;
};

Signal data;

const uint64_t pipeIn = 0xE9E8F0F0E1LL;
RF24 alici(9, 10);

void ResetData()
{
// Veri girişlerinin başlangıç değerleri
// (254/2=127) | Joystickler için orta konum
data.throttle = 127; // Motor Orta Konumda
data.pitch = 25;  //  Merkez
data.roll = 127;  //  Merkez
data.yaw = 127;   // Merkez
}

void setup()
{
  //Set the pins for each PWM signal | Her bir PWM sinyal için pinler belirleniyor.
  motorServo.attach(2, 1000, 2000);
  yonDumeniServo.attach(3);
  kanatcikServoSol.attach(4);
  kanatcikServoSag.attach(5);
  yukselisDumeniServo.attach(6);

  ResetData();
  alici.begin();
  alici.openReadingPipe(1,pipeIn);
  
  alici.startListening(); // Alıcı olarak sinyal iletişimi başlatılıyor
}

unsigned long lastRecvTime = 0;

void recvData()
{
while ( alici.available() ) {
alici.read(&data, sizeof(Signal));
lastRecvTime = millis();   // data alınıyor
}
}

void loop()
{
recvData();
unsigned long now = millis();
if ( now - lastRecvTime > 1000 ) {
ResetData(); // Sinyal kayıpsa data resetleniyor
}

motor = map(data.throttle, 0, 255, 1000, 2000);       // pin D2 (PWM signal)
yukselisDumeni = map(data.pitch, 0, 255, 1000, 2000); // pin D3 (PWM signal)
kanatcikSol = map(data.roll, 0, 255, 1000, 2000);     // pin D4 (PWM signal)
kanatcikSag = map(data.roll, 0, 255, 1000, 2000);     // pin D5 (PWM signal)
yonDumeni = map(data.yaw, 0, 255, 1000, 2000);        // pin D6 (PWM signal)



  // Serial.print("motor: ");
  // Serial.println(motor);
  // Serial.print("yonDumeni: ");
  // Serial.println(yonDumeni);
  // Serial.print("yukselisDumeni: ");
  // Serial.println(yukselisDumeni);
  // Serial.print("kanatcikSol: ");
  // Serial.println(kanatcikSol);
  // Serial.print("kanatcikSag: ");
  // Serial.println(kanatcikSag);
  


//PWM sinyaller çıkışlara gönderiliyor
motorServo.writeMicroseconds(motor);
yonDumeniServo.writeMicroseconds(yonDumeni);
yukselisDumeniServo.writeMicroseconds(yukselisDumeni);
kanatcikServoSag.writeMicroseconds(kanatcikSag);
kanatcikServoSol.writeMicroseconds(kanatcikSol);
}