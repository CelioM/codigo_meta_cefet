#include <Stepper.h> //INCLUINDO BIBLIOTECA DO STEPMOTOR

 

const int stepsPerRevolution = 65;  // VALOR DE PASSOS PARA UMA VOLTA

 

// INSTANCIANDO O MOTOR DE PASSO E CONFIGURANDO OS PINOS
Stepper myStepper(stepsPerRevolution, 8, 9, 10, 11);

 

// INSTANCIANDO SENSORES
int pinoPIR = 7;
const int pinoTOUCH = 6;
int acionamentoPIR;
int acionamentoTOUCH;

 

void setup() {
  //DEFININDO SENSORES COMO DADOS DE ENTRADA
  pinMode(pinoPIR, INPUT);
  pinMode(pinoTOUCH, INPUT);

 

 
  // DEFININDO ROTAÇÕES POR MINUTO (RPM)
  myStepper.setSpeed(2);
  // INCIANDO MONITOR SERIAL
  Serial.begin(9600);
}

 

void loop() {

 

  acionamentoPIR = digitalRead(pinoPIR);
  acionamentoTOUCH = digitalRead(pinoTOUCH);

 

  // VARIÁVEIS LOCAIS
  static byte numeroHoras = 0;

 

  // AÇÕES PARA CADA CONDIÇÃO
  if (acionamentoTOUCH == HIGH and && numeroHoras == 0) {
    Serial.println("Girando 1/4 Revolução Sentido Anti-Horário");
    myStepper.step(stepsPerRevolution / 4); //SENTIDO ANTI-HORARIO DO MOTOR DE PASSO
  } else if (acionamentoPIR == HIGH and acionamentoTOUCH == LOW && numeroHoras != 0) {
    Serial.println("Girando 1/4 Revolução Sentido Horário");
    myStepper.step(-stepsPerRevolution / 4); //SENTIDO HORARIO DO MOTOR DE PASSO
  }
}
