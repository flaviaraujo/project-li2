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

/** \brief função que cria o array
 *
 * @param teste : a stack
 */
void cria_array(STACK *teste) {
    char *result = "???";
    push_STRING(teste,result);
    //print_stack(teste);

}
/** \brief função que preenche e fecha o array
 *
 * @param teste : a stack
 * @param stack_array : a stack onde vai ser colocado o array
 */
void fecha_array(STACK *teste , STACK *stack_array) {

    DATA X = pop(teste);

    char *result = "!!!";
    push_STRING(stack_array,result);

    while (strcmp(X.STRING,"???")!=0) {

        push(stack_array,X);
        X = pop(teste);
    }
    //print_stack(stack_array);
}

/** \brief função que retira as aspas da string e a devolve à stack
 *
 * @param teste : a stack
 * @param token : as aspas
 */
void cria_string(STACK *teste, char *token) {

    char *result = token;

    // retira as primeiras aspas
    if (token[0] == '"')
        memmove(token, token+1, strlen(token));

    //retira as segundas aspas
    token[strlen(token)-1] = 0;

    push_STRING(teste,result);

}
