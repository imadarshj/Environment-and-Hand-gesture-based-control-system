void setup() 
{ 
  pinMode(A0,INPUT);
  pinMode(11, OUTPUT);
  Serial.begin(9600);
}

void loop()
{
  
   int intensity=analogRead(A0);
//  int inte/nsity=554;
   Serial.println(intensity);
   delay(1000);
}
