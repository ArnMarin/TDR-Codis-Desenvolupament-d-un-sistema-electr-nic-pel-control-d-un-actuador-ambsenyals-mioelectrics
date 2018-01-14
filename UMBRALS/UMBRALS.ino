
#include <Servo.h>
Servo myservo; 
const int led = 13;
const long interval = 1000;

int reg [10]= {0,0,0,0,0,0,0,0,0,0};
int promig;
int pos = 0;
int suma;
float vu;





void setup() {
  pinMode(led, OUTPUT);
  myservo.attach(9);
  Serial.begin(115200);
}

void loop() {
  int v;
  v = analogRead(A0);
  //v = 540;
  reg [pos]=v;
  pos = (pos + 1)%10;
  promig= ordrepromig(); 
  Serial.print("v=");
  Serial.print(v);
 Serial.print(" prom=");
  Serial.println(promig);
  if (promig > 85){
  myservo.write(175);
   }
  if (31>promig > 85){
    myservo.write(95);
   } 
  else if ( 30 > promig)
  {myservo.write(35); 
}
}


//rutina per fer l'ordre
//rutina per calcular promig

int ordrepromig(){
  int i;
  float prom;
  suma = 0;
  for (i = 0; i < 10; i++){
    suma = suma + reg[i];
  }
  prom = suma/10;
  prom = prom*180/1024;
  return (int)prom;
}

int toggleLed (){
  digitalWrite (led, HIGH);
  delayMicroseconds(10);
  digitalWrite(led, LOW);
}
