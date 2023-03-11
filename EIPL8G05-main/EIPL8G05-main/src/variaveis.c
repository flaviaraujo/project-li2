#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "stack.h"
#include "parser.h"
#include "funcoes.h"
#include "logica.h"
#include "variaveis.h"
#include "array.h"


/** \brief função que copia o topo da stack à variável
 *
 * @param teste : a stack original
 * @param token : o identificador
 * @param variaveis : a stack onde são colocadas as variáveis e as letras atribuidas
 */
void guarda_val(STACK *teste, char *token, STACK *variaveis) {

    char atrib[26]= {'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};
    char *varia[26]= {":A",":B",":C",":D",":E",":F",":G",":H",":I",":J",":K",":L",":M",":N",":O",":P",":Q",":R",":S",":T",":U",":V",":W",":X",":Y",":Z"};

    DATA Q = pop(teste);

    push(variaveis,Q);                                  // poe nas variaveis o numero que vai ser atribuido a letra
    int i=0;

    while (strcmp(token, varia[i]) != 0) {              // descobre o i para ver
        i++;
    }

    //printf("%d\n",i); teste para ver se o ciclo while está a funcionar
    char d = atrib[i];
    push_CHAR(variaveis,d);

    if (has_type(Q,LONG)) push_LONG(teste,Q.LONG);
    else if (has_type(Q,DOUBLE)) push_DOUBLE(teste,Q.DOUBLE);
    else if (has_type(Q,CHAR)) push_CHAR(teste,Q.CHAR);// resolver o problema do realloc
    //print_stack(variaveis); //teste para verificar se as variaveis estao a ser bem ataribuidas
    //print_stack(teste);
}

/** \brief função que coloca no topo da stack o conteúdo da variável
 *
 * @param teste : a stack original
 * @param token : o identificador
 * @param variaveis : a stack onde são colocadas as variáveis e as letras atribuidas
 * @param temporaria : a stack onde são colocadas as variáveis da stack variaveis para não perder as mesmas
 */
void coloca_var(STACK *teste, char *token, STACK *variaveis, STACK *temporaria) {

    char atrib[26]= {'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};

    int a=0;

    while (a>=0 && variaveis->n_elems!=0){
        DATA Q = pop(variaveis);
        //print_stack(variaveis);
        if(*token == Q.CHAR) {
            push(temporaria,Q);
            //print_stack(variaveis);
            break;
        }
        else {
            push(temporaria,Q);
            DATA S = pop(variaveis);
            push(temporaria,S);
        }
        a++;
    }
    //printf("%d\n",a);

    if (variaveis->n_elems==0) {
        int v_omiss[26] =  {10,  11, 12, 13, 14, 15, 0 , 0 , 0 , 0 , 0 , 0 , 0 , 10, 0 , 0 , 0 , 0 , 32, 0 , 0 , 0 , 0 , 0 , 1 , 2 };

        int i=0;
        while (*token != atrib[i]) {
            i++;
        }
        //printf("%d\n",i);

        if(i>=6 && i<=22) { //passar a char

            char A = v_omiss[i];

            push_CHAR(teste, A);
            //push_CHAR(variaveis, A);
        }
        else {
            int B = v_omiss[i];
            push_LONG(teste,B);
            //push_LONG(variaveis,B);
            //printf("%d\n",B);
        }

    } else {
        DATA W = pop(variaveis);
        //print_stack(variaveis);
        push(teste,W);
        //print_stack(teste);
        push(variaveis,W);


        int j=0;
        while (j<(2*a+1)) {
            DATA Q = pop(temporaria);
            push(variaveis,Q);
            j++;
        }
        //print_stack(temporaria);   para verificar se no final fica vazia
        //print_stack(variaveis);   para verificar se ficam guardadas todas as variáveis
    }
}
