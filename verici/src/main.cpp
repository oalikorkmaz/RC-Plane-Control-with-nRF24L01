#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>

const uint64_t pipeOut = 0xE9E8F0F0E1LL;   //IMPORTANT: The same as in the receiver 0xE9E8F0F0E1LL | Bu adres alıcı ile aynı olmalı
RF24 verici(9, 10); // select CE,CSN pin | CE ve CSN pinlerin seçimi

int solToggle = 2;
int solToggleDeger = 0;

struct Signal {
byte throttle;
byte pitch;
byte roll;
byte yaw;
};

Signal data;

void ResetData()
{
data.throttle = 127; //  (254/2=127)| Motor Kapalı sinyal kesildiğindeki pozisyon)
data.pitch = 127; // Merkez (sinyal kesildiğindeki pozisyon)
data.roll = 127; // Merkez (sinyal kesildiğindeki pozisyon)
data.yaw = 127; // Merkez (sinyal kesildiğindeki pozisyon)
}

void setup()
{
//Start everything up
Serial.begin(9600);
verici.begin();
verici.openWritingPipe(pipeOut);
verici.stopListening(); //Verici olarak sinyal iletişimi başlatılıyor
ResetData();
pinMode(solToggle, INPUT);
}

// Joystick center and its borders | Joystick merkez ve sınırları

int mapJoystickValues(int val, int lower, int middle, int upper, bool reverse)
{
val = constrain(val, lower, upper);
if ( val < middle )
val = map(val, lower, middle, 0, 128);
else
val = map(val, middle, upper, 128, 255);
return ( reverse ? 255 - val : val );
}

void loop()
{
// Kumanda Kol Kalibrasyonları
// "true" veya "false" servo yönünü belirler
solToggleDeger = digitalRead(solToggle);

if(solToggleDeger == 1){
data.throttle = mapJoystickValues( analogRead(A0), 12, 524, 1020, false );
}else{
data.throttle = mapJoystickValues( 0, 0, 499, 1023, false );
}

data.pitch = mapJoystickValues( analogRead(A1), 12, 524, 1020, true );
data.yaw = mapJoystickValues( analogRead(A2), 15, 524, 1020, true );
data.roll = mapJoystickValues( analogRead(A3), 12, 524, 1020, true );

// Serial.print("yaw: ");
// Serial.println(analogRead(A2));
// delay(1000);


verici.write(&data, sizeof(Signal));
}