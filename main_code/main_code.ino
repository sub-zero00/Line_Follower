#define solpin1 8
#define solpin2 9
#define solpinpwm 10
#define sagpin1 13
#define sagpin2 12
#define sagpinpwm 11


int renk1; int renk2; int renk3; int renk4; int renk5;
int position;
int hata; int sonhata;
int sagmotorpwm; int solmotorpwm;
float kp = 0.03; float kd = 0.2;
int minhiz = 0; int ekhiz = 100; int duzeltme;


void setup(){
    pinMode(A5,INPUT);
    pinMode(A4,INPUT);
    pinMode(A3,INPUT);
    pinMode(A2,INPUT);
    pinMode(A1,INPUT);
    pinMode(8,OUTPUT);
    pinMode(9,OUTPUT);
    pinMode(10,OUTPUT);
    pinMode(11,OUTPUT);
    pinMode(12,OUTPUT);
    pinMode(13,OUTPUT);
}

void loop(){
    sensoroku();
    pid();
    motorkontrol();
}

void sensoroku(){
    int deger1 = analogRead(A5);
    int deger2 = analogRead(A4);
    int deger3 = analogRead(A3);
    int deger4 = analogRead(A2);
    int deger5 = analogRead(A1);
    if (deger1 <= 400){
        renk1 = 0;
    }
    else{
        renk1= 1;
    }
    if (deger2 <= 400){
        renk2 = 0;
    }
    else{
        renk2= 1;
    }
    if (deger3 <= 400){
        renk3 = 0;
    }
    else{
        renk3= 1;
    }
    if (deger4 <= 400){
        renk4 = 0;
    }
    else{
        renk4= 1;
    }
    if (deger5 <= 400){
        renk5 = 0;
    }
    else{
        renk5= 1;
    }
    position = (0 * renk1 + 1000 * renk2 + 2000 * renk3 + 3000 * renk4 +4000 * renk5) / (renk1 + renk2 + renk3 + renk4 + renk5);
    hata = position-2000;
}

void pid(){
    duzeltme = kp*hata+kd*(hata-sonhata);
    sonhata = hata;
    
    sagmotorpwm = (minhiz+ekhiz)+duzeltme;
    solmotorpwm = (minhiz+ekhiz)-duzeltme;

    sagmotorpwm = constrain(sagmotorpwm,-254,254);
    solmotorpwm = constrain(solmotorpwm,-254,254);
    /*motorkontrol(sagmotorpwm,solmotorpwm);*/

}

void motorkontrol(){
    if (solmotorpwm>=0){
        solmotorpwm = abs(solmotorpwm);
        digitalWrite(solpin1,LOW);
        digitalWrite(solpin2,HIGH);
        analogWrite(solpinpwm,solmotorpwm);
    }
    else{
        solmotorpwm = abs(solmotorpwm);
        digitalWrite(solpin1,HIGH);
        digitalWrite(solpin2,LOW);
        analogWrite(solpinpwm,solmotorpwm);
    }
    if (sagmotorpwm>=0){
        sagmotorpwm = abs(sagmotorpwm);
        digitalWrite(sagpin1,LOW);
        digitalWrite(sagpin2,HIGH);
        analogWrite(sagpinpwm,sagmotorpwm);
    }
    else{
        sagmotorpwm = abs(sagmotorpwm);
        digitalWrite(sagpin1,HIGH);
        digitalWrite(sagpin2,LOW);
        analogWrite(sagpinpwm,sagmotorpwm);
    }
}
