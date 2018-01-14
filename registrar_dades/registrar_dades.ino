const int n=1000;
int i,v;

void setup() {
 pinMode(13, OUTPUT);
 Serial.begin(115200);
   for (i = 0; i < n; i++){
    v=analogRead(A0);
    Serial.println(v);
   
  }
  
}

void loop() { 
}

