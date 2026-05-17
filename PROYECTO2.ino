//Proyecto 2 - Electrónica Digital 1
const int boton1 = 3;
const int boton2 = 4;
const int a = 10;
const int b = 11; 
const int c = 6; 
const int d = 7;
const int e = 8; 
const int f = 9;
const int g = 5;

int display = 0;
int salida = 0;
int contador = 0;

//Prototipo de funciones
void display0();
void display1();
void display2();

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

//Servo
//LedRGB

}

void loop() {
//Funciones
void display0(){
  digitalWrite(a,HIGH);
  digitalWrite(b,HIGH);
  digitalWrite(c,HIGH); 
  digitalWrite(d,HIGH); 
  digitalWrite(e,HIGH); 
  digitalWrite(f,HIGH);
}
void display1(){
  digitalWrite(b,HIGH); 
  digitalWrite(c,HIGH);
}
void display2(){
  digitalWrite(a,HIGH); 
  digitalWrite(b,HIGH); 
  digitalWrite(g,HIGH); 
  digitalWrite(d,HIGH); 
  digitalWrite(e,HIGH);
}

//anti rebote
int estado = digitalRead(boton1);
int estado2 = digitalRead(boton2);

if (estado==HIGH){
  salida = 1;
}
if((estado==LOW)&&(salida==1)){
  delay(15);
  contador++;
  if(contador>2){
    contador=0;
  }
}
switch(contador){
  case 0: display0(); break;
  case 1: display1(); break;
  case 2: display2(); break;
}


if((salida=0))

}
