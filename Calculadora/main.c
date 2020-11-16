#include <stdio.h>
#include<stdlib.h>
#include<math.h>


float modolo(float n1) {
    float n2;
    if(n1>=0){
        n2=n1;
    }else if(n1<=0){
        n2=-n1;
    }
    return n1;
}


float expoente(float n1, float exp) {
    int ctd=0;
    float novo=n1;
    if(n1>0) {
        for(ctd=0; ctd<exp-1; ctd++) {
            novo=novo*n1;
        }
    } else if(n1==0) return 1;
    else {
        n1=n1-(n1*2);
        printf("%f\n\n",n1);
        for(ctd=0; ctd>exp+1; ctd--) {
            novo=novo*n1;
        }
        novo=1/novo;
    }
    return novo;
}

float raiz(float n1, float indice){
    float eqdm, eqdM;
    return 0;
}

int main() {

    //Declaração de variaveis
    float n1=0,n2 ,resultado, op=0,exp;
    char c, h ='s';
    char Cfunc[100];
    FILE *history;
    history = fopen("log.txt", "a");
    printf("***Calculadora***\n\nOperacoes disponiveis:\nSoma: +\nSubtracao: -\nMultiplicacao: *\nDivisao: /\nExpoente: \'\n\nComandos no fim do programa\nHelp: h\nFechar programa: n\n\n");

    //do while loop para repetir o programa ate ser permida a tecla f
    do {
        if(op==0) {
            printf("Escreva 1 numero\n");
            fprintf(history, "%f ", n1);
        }else n1=resultado;

       // printf("Escreva a operacao que quer executar\n");
        scanf(" %c", &c);
        fprintf(history,"%c ",c);
        if(c!='='&& c!= '\''){

          //  printf("Escreva outro numero\n");
            scanf("%f", &n2);
            fprintf(history, "%f ", n2);
        }

        //intrepretaçao da variavel c executando opção adequada
        switch(c) {

            //soma
            case '+':
                resultado = n1 + n2;
                printf("Resultado: %f\n", resultado);
                break;

                //Subtração
            case '-':
                resultado = n1 - n2;
                printf("Resultado: %f\n", resultado);
                break;

                //Multiplicação
            case '*':
                resultado = n1 * n2;
                printf("Resultado: %f\n", resultado);
                break;

                //Divisao
            case '/':
                resultado = n1 / n2;
                printf("Resultado: %f\n", resultado);
                break;

                //Expoente
            case '\'':
                printf("Escreva o expoente a que quer elevar\n");
                scanf("%f", &exp);
                resultado=expoente(n1,exp);
                printf("Resultado: %f\n", resultado);
                break;

                //Dar resultado
            case '=':
                printf("%f\n",resultado);
                fprintf(history,"%f\n",resultado);
                op=-1;

                //Dar ao utilizador possibilidade de fechar o programa ou pedir ajuda
                printf("deseija continuar ?\n");
                scanf(" %c", &h);
                break;
                //Opção default
            default:
                printf("Operacao invalida\n");
        }
        if(h =='h')
            printf("\nOperacoes disponiveis:\nSoma: +\nSubtracao: -\nMultiplicacao: *\nDivisao: /\nExpoente: \'\n\nComandos no fim do programa\nHelp: h\nFechar programa: n\n\n");
        op++;
    } while(h!='n');
    fclose(history);
    return 0;
}

