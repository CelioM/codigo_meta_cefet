#include <Stepper.h> 
#define null 0
 
const int stepsPerRevolution = 512;
const int pinoTouch = 7;
const int pinoPir = 6; 
  
//Inicializa a biblioteca utilizando as portas de 8 a 11 para 
//ligacao ao motor 
Stepper motor(stepsPerRevolution, 8,10,9,11); 
  
void setup() { 
  Serial.begin(9600);
 //Determina a velocdade inicial do motor 
  motor.setSpeed(60);
 
} 
  
void loop() {
 bool posicao = false; //false permite inicialmente a abertura do portão. Caso seja aberto, o sensor touch fica inativo pois 'posicao' assume valor true, que permite o uso do sensor pir, que ao fechar o portão ao ser acionado, vai ficar inativo pois 'posicao' vao voltar a retornar false. Sendo assim, os dois sensores só vao ser lidos uma vez por ciclo para definir uma rotação horaria e outra anti horaria de 90 graus no motor.
 const int touchRead = digitalRead(7); //leitura do pino do sensor touch
 const int pirRead = digitalRead(6); //leitura do pino do sensor PIR
 
 
 

 if ((touchRead) == LOW and (posicao)== true) {    
        if((pirRead) == LOW) {
              //continua aberto o portão até o sensor PIR ser acionado
              return null;
          } 
          
        if((pirRead)== HIGH && (posicao)==true) {       
            //Gira o motor no sentido anti-horario a 90 graus
          
            for (int i = 0; i<1; i++){
               motor.step(-512); 
               delay(1000);
               motor.setSpeed(0);
               motor.step(0);
               break;
            }
            //para o motor e inativa o sensor pir
            return posicao == false;
            delay(2000); //tempo para poder abrir após o portão ser fechado 
       } 
 }
 
 else if((touchRead) == HIGH && (posicao) == false){      
     //Gira o motor no sentido horario a 90 graus 
        
     for (int i = 0; i<1; i++){
       motor.step(512);
       delay(1000);
       motor.step(0);
       motor.setSpeed(0); 
       break;
     }
     
     //Pára o motor
     return posicao == true;
     delay(2000);  //aguarda 2 segundos para poder entrar no loop caso haja detecção pelo PIR
 }
 
}
