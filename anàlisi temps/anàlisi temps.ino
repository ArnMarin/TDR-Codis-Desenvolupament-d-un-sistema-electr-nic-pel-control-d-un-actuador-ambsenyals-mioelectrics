const int n=1000;
int i,v;

void setup() {
 pinMode(13, OUTPUT);
 Serial.begin(115200);
  digitalWrite(13, HIGH);
  delay(1000);
  digitalWrite(13, LOW);
  
  for (i = 0; i < n; i++){
    v=analogRead(A0);
    Serial.println(v);
    delayMicroseconds(1200); 
  }
  
}

void loop() { 
}


 

