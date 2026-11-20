/**
  Robô nav (desvia obstáculos)
  @authors  JOÃO, TAINARA E CLAYTON
  @version 1.0
  @link  https://github.com/JCR7-2696/Robo-nav
*/

// Sensor ultrassonico
#define echo 11  // recebe o pulso
#define trig 12  // envia o pulso
// led indicador 
#define led 13 // led indicador 
// Motores 
#define M1A 5 // motor esquerda
#define M1B 6 // motor esquerda 
#define M2A 9 // motor direita
#define M2B 10 // motor direita  

// Variaveis para ajuste de velocidade 

int velM1 = 255; // velocidade do motor M1 (0 a 255)
int velM2 = 255; // velocidade do motor M2 (0 a 255)

void setup() {
  pinMode(led, OUTPUT);   
  pinMode(trig, OUTPUT); // Sensor 
  pinMode(echo, INPUT); // Sensor
  pinMode(M1A, OUTPUT); // Motor esquerda 
  pinMode(M1B, OUTPUT); // Motor esquerda 
  pinMode(M2A, OUTPUT); // Motor direita
  pinMode(M2B, OUTPUT); // Motor direita
  Serial.begin(9600);  // Teste do sonar (provisório)
}

void loop() {
  //executa a função ping
  int distancia = ping();
  Serial.print(distancia);
  Serial.println(" cm");
  delay(60);  // 60ms entre leitura para eviar eco residual

  //lógica principal
  if (distancia < 30) {
    digitalWrite(led, HIGH);
    parar(); 
    delay(1000); // Ficar parado por 1 s.
    direita(); // girar sentido horario
    delay(300); // por 300ms
  } else {
    digitalWrite(led, LOW);
    frente();
  }
}

// Funcão para ler o sensor e retornar valor em CM.
int ping() {
  // iniciar o trig desligado
  digitalWrite(trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig, LOW);
  // LER O TEMPO DE DURAÇÃO (RETORNO) NO ECHO
  long duracao = pulseIn(echo, HIGH);
  //Converter para centímetros
  int distancia = duracao / 58.0;
  //retorno o valor da distancia em cm
  return distancia;

}  //


// Função para mover o robô para a frente
void frente () {
  analogWrite(M1A, velM1);
  analogWrite(M1B, 0);
  analogWrite(M2A, velM2);
  analogWrite(M2B, 0);
} 

  // Funcão para mover o robô de ré

void re(){
  analogWrite(M1B, velM1);
  analogWrite(M1A, 0);
  analogWrite(M2B, velM2);
  analogWrite(M2A, 0);
}
  // Função parar girar o robô no sentido horário
void direita() {
  analogWrite(M1B, velM1);
  analogWrite(M1A, 0);
  analogWrite(M2A, velM2);
  analogWrite(M2B, 0);

}
// Função parar girar o robô no sentido anti-horário
void esquerda() {
  analogWrite(M1A, velM1);
  analogWrite(M1B, 0);
  analogWrite(M2B, velM2);
  analogWrite(M2A, 0);



}
// Função parar o robô
void parar () {
  analogWrite(M1A, 0);
  analogWrite(M1B, 0);
  analogWrite(M2A, 0);
  analogWrite(M2B, 0);
} 


