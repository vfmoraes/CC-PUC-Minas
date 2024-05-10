#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define IN_C 10000000 //instruction_counting
#define BYTE char  
#define FREQUENCY 2808.1  //Frequência do computador - modificar se necessário



float test(int option, int type){
    clock_t inicio, fim;
    register int c;
    float Tempo, media=0;
    for (int k=1;k<=10;k=k+1) {  
        if(type == 1){ // byte tests (8 bits)
            BYTE value1 = 1;
            BYTE value2 = 3;
            switch (option) {
                //------constants------//
                case 1: //soma 
                    inicio = clock();
                    for (c=1;c<=IN_C;c=c+1) 
                        value1 = value1 + 3;
                    fim = clock();
                    break;
                
                case 2: //or
                    inicio = clock();
                    for (c=1;c<=IN_C;c=c+1) 
                        value1 = value1 | 3;
                    fim = clock();
                    break;
                
                case 3: //Mult
                    inicio = clock();
                    for (c=1;c<=IN_C;c=c+1) 
                        value1 = value1 * 3;
                    fim = clock();
                    break;
                //------Variables------//
                case 4: //soma 
                    inicio = clock();
                    for (c=1;c<=IN_C;c=c+1) 
                        value1 = value1 + value2;
                    fim = clock();
                    break;
                
                case 5: //or
                    inicio = clock();
                    for (c=1;c<=IN_C;c=c+1) 
                        value1 = value1 | value2;
                    fim = clock();
                    break;

                case 6: //Mult
                    inicio = clock();
                    for (c=1;c<=IN_C;c=c+1) 
                        value1 = value1 * value2;
                    fim = clock();
                    break;
                
                
                
                default:
                    printf("\nIncorrect test option\n");
                    exit(1);
            } 
        } else if (type == 2){ //int tests
            int value1 = 1;
            int value2 = 2;
            switch (option) {
                //------constants------//
                case 1: //soma 
                    inicio = clock();
                    for (c=1;c<=IN_C;c=c+1) 
                        value1 = value1 + 3;
                    fim = clock();
                    break;
                
                case 2: //or
                    inicio = clock();
                    for (c=1;c<=IN_C;c=c+1) 
                        value1 = value1 | 3;
                    fim = clock();
                    break;
                
                case 3: //Mult
                    inicio = clock();
                    for (c=1;c<=IN_C;c=c+1) 
                        value1 = value1 * 3;
                    fim = clock();
                    break;
                //------Variables------//
                case 4: //soma 
                    inicio = clock();
                    for (c=1;c<=IN_C;c=c+1) 
                        value1 = value1 + value2;
                    fim = clock();
                    break;
                
                case 5: //or
                    inicio = clock();
                    for (c=1;c<=IN_C;c=c+1) 
                        value1 = value1 | value2;
                    fim = clock();
                    break;

                case 6: //Mult
                    inicio = clock();
                    for (c=1;c<=IN_C;c=c+1) 
                        value1 = value1 * value2;
                    fim = clock();
                    break;
                
                
                
                default:
                    printf("\nIncorrect test option\n");
                    exit(1);
            } 
        } else if (type == 3){ //float tests
            float value1 = 1;
            float value2 = 3;
            switch (option) {
                //------constants------//
                case 1: //soma 
                    inicio = clock();
                    for (c=1;c<=IN_C;c=c+1) 
                        value1 = value1 + 3;
                    fim = clock();
                    break;
                
                
                case 3: //Mult
                    inicio = clock();
                    for (c=1;c<=IN_C;c=c+1) 
                        value1 = value1 * 3;
                    fim = clock();
                    break;
                //------Variables------//
                case 4: //soma 
                    inicio = clock();
                    for (c=1;c<=IN_C;c=c+1) 
                        value1 = value1 + value2;
                    fim = clock();
                    break;
                

                case 6: //Mult
                    inicio = clock();
                    for (c=1;c<=IN_C;c=c+1) 
                        value1 = value1 * value2;
                    fim = clock();
                    break;
                
                
                
                default:
                    printf("\nIncorrect test option\n");
                    exit(1);
            } 
        } else if (type == 0) { //Default case
            inicio = clock();
            for (c=1;c<=IN_C;c=c+1);
            fim = clock();
        } else { //incorrect type 
            printf("\nIncorrect type option\n");
            exit(1);
        }
        
        
        Tempo = (fim - inicio);
        media += Tempo;
        printf("\r");
    }
    return media/10;
}

void printTime(int Base, float* byteVal, float* intVal, float* floatVal){
    printf("\nTestes tempo medio (ms)");
    printf("\n\t---------------------------------------------------------------------------------------------------------------------------------"
           "\n\t|\tTipo\t|\ttempo\t|\t\tteste(i = i op 3)\t\t|\t\tteste(i = i op j)\t\t|"
           "\n\t|\t    \t|\tbase\t|------------------------------------------------------------------------------------------------"
           "\n\t|\t    \t|\t\t|\tSoma\t|\tOr\t|\tMult\t|\tSoma\t|\tOr\t|\tMult\t|"
           "\n\t---------------------------------------------------------------------------------------------------------------------------------");
    printf("\n\t|\tByte\t|\t%d\t|", Base);
    for(int i=0; i<6; i++) printf("\t%g\t|", byteVal[i]);
    printf("\n\t|\tInt\t|\t%d\t|", Base);
    for(int i=0; i<6; i++) printf("\t%g\t|", intVal[i]);
    printf("\n\t|\tFloat\t|\t%d\t|\t%g\t|\txxx\t|\t%g\t|\t%g\t|\txxx\t|\t%g\t|", Base, floatVal[0], floatVal[1], floatVal[2], floatVal[3]);
    printf("\n\t---------------------------------------------------------------------------------------------------------------------------------");
}

void printMips(int Base, float* byteVal, float* intVal, float* floatVal){
    printf("\n\nTestes MIPS (milhoes de instrucoes por segundo)");
    printf("\n\t-----------------------------------------------------------------------------------------------------------------"
           "\n\t|\tTipo\t|\t\tteste(i = i op 3)\t\t|\t\tteste(i = i op j)\t\t|"
           "\n\t|\t    \t|------------------------------------------------------------------------------------------------"
           "\n\t|\t    \t|\tSoma\t|\tOr\t|\tMult\t|\tSoma\t|\tOr\t|\tMult\t|"
           "\n\t-----------------------------------------------------------------------------------------------------------------");
    printf("\n\t|\tByte\t|");
    for(int i=0; i<6; i++) printf("\t%g\t|", 10/((byteVal[i]-Base)*0.001));
    printf("\n\t|\tInt\t|");
    for(int i=0; i<6; i++) printf("\t%g\t|", 10/((intVal[i]-Base)*0.001));
    printf("\n\t|\tFloat\t|\t%g\t|\txxx\t|\t%g\t|\t%g\t|\txxx\t|\t%g\t|", 10/((floatVal[0]-Base)*0.001), 10/((floatVal[1]-Base)*0.001), 10/((floatVal[2]-Base)*0.001), 10/((floatVal[3]-Base)*0.001));
    printf("\n\t-----------------------------------------------------------------------------------------------------------------");
}

void printCpi(int Base, float* byteVal, float* intVal, float* floatVal){
    printf("\n\nTestes CPI");
    printf("\n\t-----------------------------------------------------------------------------------------------------------------"
           "\n\t|\tTipo\t|\t\tteste(i = i op 3)\t\t|\t\tteste(i = i op j)\t\t|"
           "\n\t|\t    \t|------------------------------------------------------------------------------------------------"
           "\n\t|\t    \t|\tSoma\t|\tOr\t|\tMult\t|\tSoma\t|\tOr\t|\tMult\t|"
           "\n\t-----------------------------------------------------------------------------------------------------------------");
    printf("\n\t|\tByte\t|");
    for(int i=0; i<6; i++) printf("\t%.4g\t|", ((byteVal[i]-Base)/(IN_C / FREQUENCY))*1000);
    printf("\n\t|\tInt\t|");
    for(int i=0; i<6; i++) printf("\t%.4g\t|", ((intVal[i]-Base)/(IN_C / FREQUENCY))*1000);
    printf("\n\t|\tFloat\t|\t%.4g\t|\txxx\t|\t%.4g\t|\t%.4g\t|\txxx\t|\t%.4g\t|", ((floatVal[0]-Base)/(IN_C / FREQUENCY))*1000,((floatVal[1]-Base)/(IN_C / FREQUENCY))*1000, ((floatVal[2]-Base)/(IN_C / FREQUENCY))*1000, ((floatVal[3]-Base)/(IN_C / FREQUENCY))*1000);
    printf("\n\t-----------------------------------------------------------------------------------------------------------------");
}

int main() {
    
    
    float Base, byteVal[6], intVal[6], floatVal[4];
    /*
    Test params usage

    (option, type)
          0, x --> base test

          1, x --> byte test
          2, x --> int test
          3, x --> float test

          x, 1 --> const sum
          x, 2 --> const or (inexistent to float)
          x, 3 --> const mult
          x, 4 --> vary sum
          x, 5 --> vary or (inexistent to float)
          x, 6 --> vary mult

    */    

 //   float *i, *j,x=3,y=1;
 //   i=&x;
 //   j=&y;
    
    
    //-------begin-tests---------//
    Base = test(0, 0);
    printf("Teste byte em andamento (0/6)");
    for(int i=0; i<6; i++){
        byteVal[i] = test(i+1, 1);
        printf("\rTeste byte em andamento (%d/6)", i);
    }
    printf("\rTeste int em andamento (0/6)       ");
    for(int i=0; i<6; i++){
        intVal[i] = test(i+1, 2);
        printf("\rTeste int em andamento (%d/6)", i);
    }
    printf("\rTeste float em andamento (0/4)");
    floatVal[0] = test(1, 3);
    printf("\rTeste float em andamento (1/4)");
    floatVal[1] = test(3, 3);
    printf("\rTeste float em andamento (2/4)");
    floatVal[2] = test(4, 3);
    printf("\rTeste float em andamento (3/4)");
    floatVal[3] = test(6, 3);
    printf("\rTeste float em andamento (4/4)");
    printf("\r                                 \r");
    //-------end-tests---------//


    //-------print-results------//
    printTime(Base, byteVal, intVal, floatVal);
    printMips(Base, byteVal, intVal, floatVal);
    printCpi(Base, byteVal, intVal, floatVal);
    

}
