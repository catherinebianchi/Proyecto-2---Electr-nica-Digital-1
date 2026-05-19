//Proyecto 2 - Electrónica Digital 1
#include <Servo.h>

//Botones
const int boton1 = 4;
const int boton2 = 2;

//Display
const int a = 7;
const int b = 8; 
const int c = 10; 
const int d = 11;
const int e = 13; 
const int f = 9;
const int g = A3;

int display = 0;
int salida = 0;
int modo = 0;
int salida2 = 0;
int temp;

//Buzzer
const int buzzer = A4;
int alarma = 0;
int apagada = 0;

//LedRGB
const int LEDrojo = 6;
const int LEDverde = 5;
const int LEDazul = 3;

//Servo
Servo miServo;
int angulo = 0;
int potPin = A0;
int potValue;
int lpm;

//Prototipo de funciones
void color(int rojo, int verde, int azul);

void setup() {
//Botones
pinMode(boton1, INPUT);
pinMode(boton2, INPUT);

//Display
pinMode(a, OUTPUT);
pinMode(b, OUTPUT);
pinMode(c, OUTPUT);
pinMode(d, OUTPUT);
pinMode(e, OUTPUT);
pinMode(f, OUTPUT);
pinMode(g, OUTPUT);

//LedRGB
pinMode(LEDrojo,OUTPUT);
pinMode(LEDverde,OUTPUT);
pinMode(LEDazul,OUTPUT);

//Servo
miServo.attach(12);
pinMode(potPin, INPUT);
miServo.write(angulo);

//Buzzer
pinMode(buzzer,OUTPUT);

}

void loop() {
//DISPLAY
//anti rebote
int estado = digitalRead(boton1);
int estado2 = digitalRead(boton2);

if (estado==HIGH){
  salida = 1;
}
if((estado==LOW)&&(salida==1)){
  delay(15);
  modo=modo+1;
  if(modo>2){
    modo=0;
  }
  salida=0;
}
//Apagar Display
digitalWrite(a,LOW);
digitalWrite(b,LOW);
digitalWrite(c,LOW);
digitalWrite(d,LOW);
digitalWrite(e,LOW);
digitalWrite(f,LOW);
digitalWrite(g,LOW);

switch(modo){
  case 0: digitalWrite(a,HIGH); digitalWrite(b,HIGH); digitalWrite(c,HIGH); digitalWrite(d,HIGH); digitalWrite(e,HIGH); digitalWrite(f,HIGH); break;
  case 1: digitalWrite(b,HIGH); digitalWrite(c,HIGH); break;
  case 2: digitalWrite(a,HIGH); digitalWrite(b,HIGH); digitalWrite(g,HIGH); digitalWrite(d,HIGH); digitalWrite(e,HIGH); break;
}

//MODO 0
if(modo==0){
  miServo.write(0);
  color(0,0,0);
}

//MODO 1
if(modo == 1){
  miServo.write(angulo);
  potValue = analogRead(potPin);
  lpm = map(potValue, 0, 1023, 0, 200); //Latidos por minuto
  angulo = map(lpm, 0, 200, 0, 180);
  miServo.write(angulo);
  delay(10);

  if(lpm<60){
    color(255,255,0);
  } else if((60<lpm)&&(lpm<100)){
    color(0,255,0);
  } else if((100<lpm)&&(lpm<150)){
    color(255,0,0);
  } else if(lpm>=150){
    color(255,0,0);
    delay(250);
    color(0,0,0);
    delay(250);
  }
}//Fin modo 1

//MODO 2
if(modo == 2){

int estado2 = digitalRead(boton2);
if(estado2==HIGH){
  salida2=1;
}

if((estado2==LOW)&&(salida2==1)){
  alarma = 0;
  apagada = 1;
  delay(15);
  salida2=0;
  }


  potValue = analogRead(potPin);
  temp = map(potValue, 0, 1023, 93, 104); //Temperatura según potenciómetro
  delay(200);

if(temp<95){
  color(255,0,255); //Morado
  miServo.write(0);
  if((alarma == 0)&&(apagada==0)){
    alarma = 1;
  }
  }

 else if((temp>95)&&(temp<98)){
  color(0,255,255); //Cyan o celeste
  miServo.write(45);
  alarma = 0;
  apagada=0;

} else if ((temp>98)&&(temp<100)){
  color(255,255,0); //Amarillo
  miServo.write(90);
  alarma = 0;
  apagada=0;

} else if ((temp>100)&&(temp<102)){
  color(255,160,0); //Anaranjado
  miServo.write(135);
  alarma = 0;
  apagada=0;

} else if(temp>102){
  color(255,255,255); //Blanco
  miServo.write(180);
  if ((alarma == 0)&&(apagada==0)){
    alarma = 1;
  }
  }

if(alarma == 1){
  digitalWrite(buzzer, HIGH);
} else{
  digitalWrite(buzzer, LOW);
}

}//Fin modo 2

}

//Funciones
void color(int rojo, int verde, int azul){
  analogWrite(LEDrojo, rojo);
  analogWrite(LEDverde, verde);
  analogWrite(LEDazul, azul);
}