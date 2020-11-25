void setup(){
    pinMode(A5,INPUT);
    pinMode(A4,INPUT);
    pinMode(A3,INPUT);
    pinMode(A2,INPUT);
    pinMode(A1,INPUT);
    Serial.begin(9600);
}
void loop(){
    int deger1 = analogRead(A5);
    int deger2 = analogRead(A4);
    int deger3 = analogRead(A3);
    int deger4 = analogRead(A2);
    int deger5 = analogRead(A1);
    Serial.println(deger1);
    Serial.println(deger2);
    Serial.println(deger3);
    Serial.println(deger4);
    Serial.println(deger5);
    Serial.println("-------");
    delay(1000);
}