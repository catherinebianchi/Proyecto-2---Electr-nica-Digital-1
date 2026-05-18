//Proyecto 2 - Electrónica Digital 1
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

//Buzzer
const int buzzer = A4;

//LedRGB
const int LEDrojo = 6;
const int LEDverde = 5;
const int LEDazul = 3;

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

}
