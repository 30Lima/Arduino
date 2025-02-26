// Atribuir nomes aos pinos de I/O
#define BT1 8
#define BT2 9
#define ledR 4 
#define ledW 3
#define ledB 2

void setup() {
    // Habilita comuncação seriaç (BAUD rate = 9600 bits/s)
  Serial.begin(9600);
  pinMode(BT1, INPUT);
  pinMode(BT2, INPUT);
  pinMode(ledR, OUTPUT);
  pinMode(ledW, OUTPUT);
  pinMode(ledB, OUTPUT);
}

/*
Botão 1:
LOW ----> desligado -----> ledW piscando a cada 500ms
HIGH ----> ligado ----> ledR e ledB piscando alternados a cada 350ms.
*/

void loop() {
    statusBT1 = digitalRead(BT1);
    
  if(statusBT1 == HIGH){ // botão for pressionado
    contador++;
    Serial.print("Valor do contador = ");
    Serial.println(contador);
    piscaRB();
  }
  
  else{
    piscaW();
  }
  
}

void piscaRB(){
  digitalWrite(ledB, HIGH);
  digitalWrite(ledR, LOW);
  delay(350);
  digitalWrite(ledR, HIGH);
  digitalWrite(ledB, LOW);
  delay(350);
}

void piscaW(){
  digitalWrite(ledW, HIGH);
  delay(250);
  digitalWrite(ledW, LOW);
  delay(250);
}