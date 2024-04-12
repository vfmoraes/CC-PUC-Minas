/*
EP_04 - ULA 4 Bits + Arduino
Membros do grupo:
- Luís Augusto Lima de Oliveira (805413)
- Samuel Horta de Faria (801528)
- Victor Ferraz de Moraes (802371)

Criação: 09/04/2024
*/
#include <string.h>
#include <stdlib.h>

//Pinos de saída
int F3 = 13, F2 = 12, F1 = 11, F0 = 10;
//posições das variáveis
int pc = 0, w=1, x=2, y=3;
const int TAM = 100;
String memoria[TAM];
String instrucao;



void setup()
{
  //configuração dos pinos como saída
  pinMode(F3, OUTPUT);
  pinMode(F2, OUTPUT);
  pinMode(F1, OUTPUT);
  pinMode(F0, OUTPUT);
  
  //inicialização do serial com a configuração da taxa de transferencia
  Serial.begin(9600);
  
}





void loop()
{
  //teste para saber se há entrada no buffer
  if(Serial.available()>2){
    //reiniciar posição inicial das operações ULA para cada execução
    memoria[pc] = 4;
    memoria[x] = memoria[y] = memoria[w] = " ";
    atualizaLeds(0);
    int pos = 4;
    //leitura de cada char
    instrucao = "";
    delay(1); instrucao += (char) Serial.read();
    delay(1); instrucao += (char) Serial.read();
    delay(1); instrucao += (char) Serial.read();
    
    while(instrucao.compareTo("fim") != 0){
 		//teste se é um valor válido
      	bool ehValido = true;      	
      	for(int i=0; i<3; i++){
          	int val = hexToInt(instrucao.charAt(i));
          	//Se fora do intervalo de 0 a 15 então não é um valor válido
          	if( val < 0 ||  val >15){
          		ehValido = false;
              	i=3;
            }
        }
      	
      	//Se valido inserir no vetor
      	if(ehValido){
            //inserir no vetor
            if(pos != TAM){
                memoria[pos++] = instrucao;
                dumpMemoria(pos);
            } else {
                Serial.print("\nNao e possivel acumular mais operacoes\n");
            }
        //Se inválido não insere e imprime na tela avisando o erro
        } else {
        	Serial.print("\nAVISO: Valor Invalido, digite novamente\n");
        }
      
      	//Esperar que o buffer de entrada seja a quantidade correta de char
        while(Serial.available()<3);
        //leitura de cada char
        instrucao = "";
    	delay(1); instrucao += (char) Serial.read();
      	
      	//Tratamento para pular qualquer valor abaixo de '0', incluindo \n e espaço
        if(instrucao.charAt(0) <48){
          	instrucao = "";
          	while(Serial.available()<3);
        	delay(1); instrucao += (char) Serial.read();
        }
    	delay(1); instrucao += (char) Serial.read();
    	delay(1); instrucao += (char) Serial.read();
      	
    }
    
    int posTeste;
    while((posTeste = memoria[pc].toInt()) < pos){
        memoria[x] = memoria[posTeste].charAt(0);
      	memoria[y] = memoria[posTeste].charAt(1);
      	memoria[w] = ULA(memoria[x].charAt(0), memoria[y].charAt(0), memoria[posTeste].charAt(2));
        
      	dumpMemoria(pos);
      	atualizaLeds( hexToInt(memoria[w].charAt(0)) );
        delay(2000); //espera de 2 segundos para cada execução
      	memoria[pc] = posTeste+1;
    }
    Serial.print("\n------Fim-execucao-ULA-------\n\n");
	atualizaLeds(0);
  } 
}

void dumpMemoria(int qtdeElementos){
  	Serial.print(" | ");
  	for(int i = 0; i<qtdeElementos; i++){
      	Serial.print(memoria[i]);
      	Serial.print(" | ");
    }
	Serial.print("\n");
}

//Atualiza os leds que representam o binário a partir do valor do resto da divisão de 2
void atualizaLeds(int valor){

  // Atualiza os LEDs de acordo com o valor binário
  for (int i = 0; i < 4; i++) {
    int bit = valor % 2; // Extrai o bit correspondente do valor
    digitalWrite(i+F0, bit);
    valor/=2; //atualiza valor
  }
}

char ULA(int x, int y, int op){
	int resultado = 0;
  	//tranformar pra inteiro para melhor manipulação
  	x = hexToInt(x);
  	y = hexToInt(y);
    op = hexToInt(op);
  
  	//seleção das operações
    switch (op){
		case 0:
      		resultado = NOT(y);
      		break;
      	case 1:
      		resultado = NOT(AND(NOT(x), y));
      		break;
      	case 2:
			resultado = AND(NOT(x), y);
      		break;
      	//case 3:
      		//não necessário, já que o valor inicial de resultado já é 0
      	case 4:
      		resultado = NOT(AND(x, y));
      		break;
      	case 5:
			resultado = NOT(x);
      		break;
      	case 6:
      		resultado = XOR(x, y);
      		break;
      	case 7:
      		resultado = AND(x, NOT(y));
      		break;
      	case 8:
      		resultado = OR(NOT(x), NOT(y));
      		break;
      	case 9:
      		resultado = XOR(NOT(x), NOT(y));
      		break;
      	case 10:
      		resultado = y;
      		break;
      	case 11:
      		resultado = AND(x, y);
      		break;
      	case 12:
      		resultado = 15;
      		break;
      	case 13:
      		resultado = OR(x, NOT(y));
      		break;
      	case 14:
      		resultado = OR(x, y);
      		break;
      	case 15:
      	resultado = x; 
    }	
  
  	//return tranformando novamente para hexa
  	return intToHex(resultado);
}
              
int AND (int x, int y){
	return (x & y);
}

int OR(int x, int y){
 	return (x | y);
}

int not_fix(int x){
  	//Quando negado, fica menor que 0, na seguinte sequência: ~ 0 = -1, ~ 1 = -2, dai em diante. Dessa forma executa-se x+15 para pegar o valor correto do NOT
	return x+16;
}

int NOT(int x){
	return not_fix(~ x);
}

int XOR(int x, int y){
	return (x ^ y);
}

int hexToInt(int x){
  	// Se menor que A o valor será entre '0' e '9', valendo assim o ascii de x - ascii de '0' (48)
  	// Senão será um valor será entre 'A' e 'F', valendo assim o ascii de x - 55 para que dê 10 ou acima (ascii de A = 65)
	
  	return x < 'A' ? x - 48 : x - 55 ;
}



char intToHex(int x){

    // Se menor que 10 então é um inteiro, sendo assim adicionar 48 para retornar ao char correto
  	// se maior ou igual a 10 então é um valor entre A e F, sendo assim necessário adicionar 55 para retornar ao char correto
  	return x < 10 ? x + 48 : x + 55;

}

