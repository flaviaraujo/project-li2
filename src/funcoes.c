#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "stack.h"
#include "parser.h"
#include "funcoes.h"
#include "array.h"

/** \brief função que faz a soma ou concatena arrays
 *
 * @param teste : a stack
 * @param stack_array : a stack onde vai ser colocado o array
 */
void sum(STACK *teste, STACK *stack_array) {

    STACK *aux1 = new_stack();
    STACK *aux2 = new_stack();
    STACK *aux3 = new_stack();
    STACK *aux4 = new_stack();

    if (stack_array->n_elems!=0) {

        DATA X = pop(stack_array);
        int i = 0;
        while (i<2) {
            if(strcmp(X.STRING,"!!!")==0) {
                i++;
                X = pop(stack_array);
            } else if(i==1) {
                push(aux1,X);
                X = pop(stack_array);
            } else {
                push(aux2,X);
                X = pop(stack_array);
            }
        }
        //print_stack(aux1);
        //print_stack(aux2);
        while (aux1->n_elems!=0) {
            DATA Y = pop(aux1);
            push(aux3,Y);
        }
        while (aux2->n_elems!=0) {
            DATA Y = pop(aux2);
            push(aux4,Y);
        }

        while (aux3->n_elems!=0) {
            DATA Y = pop(aux3);
            push(teste,Y);
        }
        while (aux4->n_elems!=0) {
            DATA Y = pop(aux4);
            push(teste,Y);
        }

    } else {
        DATA X = pop(teste);
        DATA Y = pop(teste);

        int a = has_type(X, LONG);
        int b = has_type(Y, DOUBLE);
        int c = has_type(Y, LONG);
        int d = has_type(X, DOUBLE);


        switch (a) {
            case 1 :
                switch (b) {
                    case 1:
                        push_DOUBLE(teste, X.LONG + Y.DOUBLE);
                        break;
                }
                switch (c) {
                    case 1:
                        push_LONG(teste, X.LONG + Y.LONG);
                        break;
                }
                break;
        }
        switch (d) {
            case 1 :
                switch (b) {
                    case 1:
                        push_DOUBLE(teste,  X.DOUBLE + Y.DOUBLE);
                        break;
                }
                switch (c) {
                    case 1:
                        push_DOUBLE(teste, X.DOUBLE + Y.LONG);
                        break;
                }
                break;
        }
    }
}
/** \brief função que faz a subtração
 *
 * @param teste : a stack
 */
void subtract(STACK *teste) {
    DATA X = pop(teste);
    DATA Y = pop(teste);

    int a = has_type(X, LONG);
    int b = has_type(Y, DOUBLE);
    int c = has_type(Y, LONG);
    int d = has_type(X, DOUBLE);

    switch (a) {
        case 1:
            switch (b) {
                case 1:
                    push_DOUBLE(teste, Y.DOUBLE - X.LONG);
                    break;

            }
            switch (c) {
                case 1:
                    push_LONG(teste, Y.LONG - X.LONG);
                    break;
            }
            break;
        
    }
    switch (d) {
        case 1:
            switch (b) {
                case 1:
                    push_DOUBLE(teste, Y.DOUBLE - X.DOUBLE);
                    break;

            }
            switch (c) {
                case 1:
                    push_DOUBLE(teste, Y.LONG - X.DOUBLE);
                    break;
            }
            break;
    }
}
/** \brief função que faz a multiplicação
 *
 * @param teste : a stack
 */
void mult(STACK *teste) {

    DATA X = pop(teste);
    DATA Y = pop(teste);


    int a = has_type(X, LONG);
    int b = has_type(Y, DOUBLE);
    int c = has_type(Y, LONG);
    int d = has_type(X, DOUBLE);

    switch (a) {
        case 1:
            switch (b) {
                case 1:
                    push_DOUBLE(teste, X.LONG * Y.DOUBLE);
                    break;

            }
            switch (c) {
                case 1:
                    push_LONG(teste, X.LONG * Y.LONG);
                    break;
            }
            break;

    }
    switch (d) {
        case 1:
            switch (b) {
                case 1:
                    push_DOUBLE(teste, X.DOUBLE * Y.DOUBLE);
                    break;

            }
            switch (c) {
                case 1:
                    push_DOUBLE(teste, X.DOUBLE * Y.LONG);
                    break;
            }
            break;
    }
}
/** \brief função que faz a divisão
 *
 * @param teste : a stack
 */
void division(STACK *teste) {

    DATA Y = pop(teste);
    DATA X = pop(teste);

    int a = has_type(X, LONG);
    int b = has_type(Y, DOUBLE);
    int c = has_type(Y, LONG);
    int d = has_type(X, DOUBLE);

    switch (a) {
        case 1:
            switch (b) {
                case 1:
                    push_DOUBLE(teste, X.LONG / Y.DOUBLE);
                    break;

            }
            switch (c) {
                case 1:
                    push_LONG(teste, X.LONG / Y.LONG);
                    break;
            }
            break;

    }
    switch (d) {
        case 1:
            switch (b) {
                case 1:
                    push_DOUBLE(teste, X.DOUBLE / Y.DOUBLE);
                    break;

            }
            switch (c) {
                case 1:
                    push_DOUBLE(teste, X.DOUBLE / Y.LONG);
                    break;
            }
            break;
    }
}
/** \brief função que faz a decrementação
 *
 * @param teste : a stack
 */
void dec(STACK *teste) {
    DATA X = pop(teste);

    if(has_type(X, DOUBLE)){
        double result = X.DOUBLE - 1;
        push_DOUBLE(teste, result);
    }
    else if (has_type(X, LONG)){
        long result = X.LONG - 1;
        push_LONG(teste, result);
    }
    else if (has_type(X, CHAR)){
        char result = X.CHAR - 1;
        push_CHAR(teste, result);
    }
}
/** \brief função que faz a incrementação
 *
 * @param teste : a stack
 */
void inc(STACK *teste) {
    DATA X = pop(teste);

    if(has_type(X, DOUBLE)){
        double result = X.DOUBLE + 1;
        push_DOUBLE(teste, result);
    }
    else if (has_type(X, LONG)){
        long result = X.LONG + 1;
        push_LONG(teste, result);
    }
    else if (has_type(X, CHAR)){
        char result = X.CHAR + 1;
        push_CHAR(teste, result);
    }
}
/** \brief função que faz o resto da divisão inteira
 *
 * @param teste : a stack
 */
void modulus(STACK *teste) {

    DATA Y = pop(teste);
    DATA X = pop(teste);

    if(has_type(X, LONG) && has_type(Y, DOUBLE)){
        long result = X.LONG % Y.LONG;
        push_LONG(teste, result);
    }
    else if (has_type(X, DOUBLE) && has_type(Y, LONG)){
        long result = X.LONG % Y.LONG;
        push_LONG(teste, result);
    }
    else if(has_type(X, DOUBLE) && has_type(Y, DOUBLE)){
        long result = X.LONG % Y.LONG;
        push_LONG(teste, result);
    } else if(has_type(X, LONG) && has_type(Y, LONG)){
        long result = X.LONG % Y.LONG;
        push_LONG(teste, result);
    }
}
/** \brief função que faz a potenciação
 *
 * @param teste : a stack
 */
void power(STACK *teste) {
    DATA Y = pop(teste);
    DATA X = pop(teste);


    if(has_type(X, LONG) && has_type(Y, DOUBLE)){
        double result = pow(X.LONG , Y.DOUBLE);
        push_DOUBLE(teste, result);
    }
    else if (has_type(X, DOUBLE) && has_type(Y, LONG)){
        double result = pow(X.DOUBLE, Y.LONG);
        push_DOUBLE(teste, result);
    }
    else if(has_type(X, DOUBLE) && has_type(Y, DOUBLE)){
        double result = pow(X.DOUBLE, Y.DOUBLE);
        push_DOUBLE(teste, result);
    }
    else if(has_type(X, LONG) && has_type(Y, LONG)){
        long result = pow(X.LONG, Y.LONG);
        push_LONG(teste, result);
    }
}
/** \brief função que faz o e lógico
 *
 * @param teste : a stack
 */
void e(STACK *teste) {

    DATA X = pop(teste);
    DATA Y = pop(teste);


    if(has_type(X, LONG) && has_type(Y, DOUBLE)){
        long result = X.LONG & Y.LONG;
        push_LONG(teste, result);
    }
    else if (has_type(X, DOUBLE) && has_type(Y, LONG)){
        long result = X.LONG & Y.LONG;
        push_LONG(teste, result);
    }
    else if(has_type(X, DOUBLE) && has_type(Y, DOUBLE)){
        long result = X.LONG & Y.LONG;
        push_LONG(teste, result);
    } else if(has_type(X, LONG) && has_type(Y, LONG)){
        long result = X.LONG & Y.LONG;
        push_LONG(teste, result);
    }
}
/** \brief função que faz o ou lógico
 *
 * @param teste : a stack
 */
void ou(STACK *teste) {
    DATA X = pop(teste);
    DATA Y = pop(teste);


    if(has_type(X, LONG) && has_type(Y, DOUBLE)){
        long result = X.LONG | Y.LONG;
        push_LONG(teste, result);
    }
    else if (has_type(X, DOUBLE) && has_type(Y, LONG)){
        long result = X.LONG | Y.LONG;
        push_LONG(teste, result);
    }
    else if(has_type(X, DOUBLE) && has_type(Y, DOUBLE)){
        long result = X.LONG | Y.LONG;
        push_LONG(teste, result);
    }
    else if(has_type(X, LONG) && has_type(Y, LONG)){
        long result = X.LONG | Y.LONG;
        push_LONG(teste, result);
    }
}
/** \brief função que faz o ou exclusivo
 *
 * @param teste : a stack
 */
void xorr(STACK *teste) {
    DATA X = pop(teste);
    DATA Y = pop(teste);


    if(has_type(X, LONG) && has_type(Y, DOUBLE)){
        long result = X.LONG ^ Y.LONG;
        push_LONG(teste, result);
    }
    else if (has_type(X, DOUBLE) && has_type(Y, LONG)){
        long result = X.LONG ^ Y.LONG;
        push_LONG(teste, result);
    }
    else if(has_type(X, DOUBLE) && has_type(Y, DOUBLE)){
        long result = X.LONG ^ Y.LONG;
        push_LONG(teste, result);
    }
    else if(has_type(X, LONG) && has_type(Y, LONG)){
        long result = X.LONG ^ Y.LONG;
        push_LONG(teste, result);
    }
}
/** \brief função que faz a negação ou coloca na stack teste todos os elementos do array
 *
 * @param teste : a stack
 * @param stack_array : a stack onde vai ser colocado o array
 */
void nott(STACK *teste, STACK *stack_array) {

    if (stack_array->n_elems!=0) {
        DATA X = pop(stack_array);
        while (strcmp(X.STRING,"!!!")!=0) {
            push(teste, X);
            X = pop(stack_array);
        }

    } else {
        DATA X = pop(teste);

        if(has_type(X, DOUBLE)){
            long result = ~ X.LONG;
            push_LONG(teste, result);
        }
        else if (has_type(X, LONG)){
            long result = ~ X.LONG;
            push_LONG(teste, result);
        }
    }
}

/** \brief função que faz a troca dos dois últimos elementos da stack
 *
 * @param teste : a stack
 */
void backs(STACK *teste) {
    DATA X = pop(teste);
    DATA Y = pop(teste);

    push(teste, X);
    push(teste, Y);
}
/** \brief função que faz rodar os 3 elementos no topo da stack
 *
 * @param teste : a stack
 */
void at(STACK *teste) {
    DATA Z = pop(teste);
    DATA Y = pop(teste);
    DATA X = pop(teste);

    push(teste, Y);
    push(teste, Z);
    push(teste, X);
}
/** \brief função que faz pop do último elemento da stack
 *
 * @param teste : a stack
 */
void scolon(STACK *teste) {
    STACK *lixo = new_stack();
    DATA X = pop(teste);

    if(has_type(X, LONG)){
        push_LONG(lixo, X.LONG);
    }
    else if (has_type(X, DOUBLE)){
        push_DOUBLE(lixo, X.DOUBLE);
    }
    else if (has_type(X, CHAR)){
        push_CHAR(lixo, X.CHAR);
    }

}
/** \brief função que duplica o último elemento da stack
 *
 * @param teste : a stack
 */
void undscore(STACK *teste) {
    DATA X = pop(teste);

    push(teste,X);
    push(teste,X);
}
/** \brief função que copia o n-ésimo elemento para o topo da stack
 *
 * @param teste : a stack
 */
void dolar(STACK *teste) {
    DATA R;
    STACK *auxiliar = new_stack();

    DATA Y;
    Y = pop(teste);

    for (int i = 0; i <= Y.LONG; i++) {  // copia para um array os valores que estao a ser retirados da stack

        DATA X = pop(teste);

        int a = has_type(X,LONG);
        int b = has_type(X,DOUBLE);

        switch (a) {
            case 1:
                push_LONG(auxiliar, X.LONG);
                R.LONG = X.LONG;
                break;
        }
        switch (b) {
            case 1:
                push_DOUBLE(auxiliar, X.DOUBLE);
                R.DOUBLE = X.DOUBLE;
                break;

        }
    }
    for (long j = Y.LONG; j >= 0; j--) { // coloca na stack os valores que foram colocados no array

        DATA Z = pop(auxiliar);

        int a = has_type(Z,LONG);
        int b = has_type(Z,DOUBLE);

        switch (a) {
            case 1:
                push_LONG(teste, Z.LONG);
                break;
        }
        switch (b) {
            case 1:
                push_DOUBLE(teste, Z.DOUBLE);
                break;

        }
    }

    int a = has_type(R,LONG);
    int b = has_type(R,DOUBLE);

    switch (a) {
        case 1:
            push_LONG(teste, R.LONG);
            break;
    }
    switch (b) {
        case 1:
            push_DOUBLE(teste, R.DOUBLE);
            break;

    }
}
/** \brief função que faz a leitura da linha seguinte
 *
 * @param teste : a stack
 */
void readl(STACK *teste) {
    char aline[10240];
    assert(fgets(aline, 10240, stdin) != NULL);
    assert(aline[strlen(aline)-1] == '\n');
    aline[strlen(aline)-1] = '\0';
    push_STRING(teste, aline);
}
/** \brief função que converte o topo da stack num inteiro
 *
 * @param teste : a stack
 */
void toint(STACK *teste) {
    DATA X = pop(teste);

    if(has_type(X, DOUBLE)){
        push_LONG(teste, X.DOUBLE);
    }else if (has_type(X, CHAR)){
        push_LONG(teste, X.CHAR);
    }else if (has_type(X, STRING)){
        push_LONG(teste, atoi(X.STRING));
    }else
        push(teste,X);
}
/** \brief função que converte o topo da stack num decimal
 *
 * @param teste : a stack
 */
void tofloat(STACK *teste) {
    DATA X = pop(teste);

    if (has_type(X, LONG)){
        push_DOUBLE(teste, X.LONG);
    }else if (has_type(X, CHAR)){
        push_DOUBLE(teste, X.CHAR);
    }else if (has_type(X, STRING)){
        push_DOUBLE(teste, atof(X.STRING));
    }else
        push_DOUBLE(teste,X.DOUBLE);
}
/** \brief função que converte o topo da stack num caracter
 *
 * @param teste : a stack
 */
void tochar(STACK *teste) {
    DATA X = pop(teste);

    if (has_type(X, LONG)){
        push_CHAR(teste, X.LONG);
    }else if (has_type(X, STRING)){
        push_CHAR(teste, strtol(X.STRING, &sobra1,10));
    }else
        push(teste,X);
}
