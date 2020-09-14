#include "SoftwareSerial.h"
SoftwareSerial serial_connection(2, 4);//Create a serial connection with TX and RX on these pins

String vol_status="0";
void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);//Initialize communications to the serial monitor in the Arduino IDE
  serial_connection.begin(9600);//Initialize communications with the bluetooth module
  serial_connection.println("Ready!!!");//Send something to just start comms. This will never be seen.
  Serial.println("Started");//Tell the serial monitor that the sketch has started.
  pinMode(12,INPUT);
  pinMode(6,INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
int ldr1=analogRead(A7);
int ldr2=analogRead(A6);
int ldr3=analogRead(A5);
int ldr4=analogRead(A4);
double avg=(ldr1+ldr2+ldr3+ldr4)/4;
int auto_bright = map(avg, 500, 1023, 0, 100);
Serial.println(auto_bright);
delay(500);
 //serial_connection.println(auto_bright);
int vol_plus=digitalRead(6);
int vol_minus=digitalRead(12);
Serial.println(vol_plus);
Serial.println(vol_minus);
if(vol_plus==0)
vol_status="1";
else if(vol_minus==0)
vol_status="-1";
else
vol_status="0";
String data=String(auto_bright)+" "+vol_status+" ";
serial_connection.println(data);
}
