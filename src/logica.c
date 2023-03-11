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

/** \brief função que verifica se dois elementos são iguais
 *
 * @param teste : a stack
 */
void equal(STACK *teste) {
    DATA X = pop(teste);
    DATA Y = pop(teste);

    if((has_type(X, LONG) && has_type(Y, DOUBLE) && X.LONG==Y.DOUBLE) || (has_type(X, DOUBLE) && has_type(Y, LONG) && X.DOUBLE==Y.LONG)
    || (has_type(X, DOUBLE) && has_type(Y, DOUBLE) && X.DOUBLE==Y.DOUBLE)|| (has_type(X, LONG) && has_type(Y, LONG) && X.LONG==Y.LONG)
    || (has_type(X, CHAR) && has_type(Y, CHAR) && X.CHAR==Y.CHAR)){
        push_LONG(teste, 1);
    } else {
        push_LONG(teste, 0);
    }
}

/** \brief função que testa se o primeiro elemento é menor do que outro (se isto se verificar, devolve 1, se não, 0)
 *
 * @param teste : a stack
 */
void minor(STACK *teste) {
    DATA X = pop(teste);
    DATA Y = pop(teste);

    if((has_type(X, LONG) && has_type(Y, DOUBLE) && Y.DOUBLE<X.LONG) ||
        (has_type(X, DOUBLE) && has_type(Y, LONG) && Y.LONG<X.DOUBLE) ||
        (has_type(X, DOUBLE) && has_type(Y, DOUBLE) && Y.DOUBLE<X.DOUBLE)||
        (has_type(X, LONG) && has_type(Y, LONG) && Y.LONG<X.LONG) ||
        (has_type(X, CHAR) && has_type(Y, LONG) && Y.LONG<X.CHAR) ||
        (has_type(X, LONG) && has_type(Y, CHAR) && Y. CHAR<X.LONG) ||
        (has_type(X, CHAR) && has_type(Y, DOUBLE) && Y. DOUBLE<X.CHAR) ||
        (has_type(X, DOUBLE) && has_type(Y, CHAR) && Y. CHAR<X.DOUBLE) ||
        (has_type(X, CHAR) && has_type(Y, CHAR) && Y. CHAR<X.CHAR)){
        push_LONG(teste, 1);
    } else {
        push_LONG(teste, 0);
    }
}

/** \brief função que testa se o primeiro elemento é maior do que outro (se isto se verificar, devolve 1, se não, 0)
 *
 * @param teste : a stack
 */
void major(STACK *teste) {
    DATA X = pop(teste);
    DATA Y = pop(teste);

    if((has_type(X, LONG) && has_type(Y, DOUBLE) && Y.DOUBLE>X.LONG) || (has_type(X, DOUBLE) && has_type(Y, LONG) && Y.LONG>X.DOUBLE)
       || (has_type(X, DOUBLE) && has_type(Y, DOUBLE) && Y.DOUBLE>X.DOUBLE)|| (has_type(X, LONG) && has_type(Y, LONG) && Y.LONG>X.LONG)
       || (has_type(X, CHAR) && has_type(Y, LONG) && Y.LONG>X.CHAR) || (has_type(X, LONG) && has_type(Y, CHAR) && Y. CHAR>X.LONG)
       || (has_type(X, CHAR) && has_type(Y, DOUBLE) && Y. DOUBLE>X.CHAR) || (has_type(X, DOUBLE) && has_type(Y, CHAR) && Y. CHAR>X.DOUBLE)
       || (has_type(X, CHAR) && has_type(Y, CHAR) && Y. CHAR>X.CHAR)){
        push_LONG(teste, 1);
    } else {
        push_LONG(teste, 0);
    }
}

/** \brief função que testa se o elemento é igual a zero, se for, devolve 1, se não, 0 (nega o valor)
 *
 * @param teste : a stack
 */
void nottt(STACK *teste) {
    DATA X = pop(teste);

    if((has_type(X,LONG) && X.LONG ==0) || (has_type(X,DOUBLE) && X.DOUBLE ==0.0) || (has_type(X,CHAR) && X.CHAR =='\0')) {
        push_LONG(teste, 1);
    } else {
        push_LONG(teste, 0);
    }
}

/** \brief função que devolve o elemento que for o primeiro falso ou o último verdadeiro
 *
 * @param teste : a stack
 */
void shortcute(STACK *teste) {
    DATA X = pop(teste);
    DATA Y = pop(teste);


    int a = has_type(X, LONG);
    int b = has_type(Y, DOUBLE);
    int c = has_type(Y, LONG);
    int d = has_type(X, DOUBLE);
    int e = has_type(X, CHAR);
    int f = has_type(Y, CHAR);
    int g;

    if (Y.DOUBLE == 0.0) {
        g=0;
    }

    switch (c) {
        case 1:
            switch (Y.LONG) {
                case 0:
                    push_LONG(teste, Y.LONG);
                    break;
                default:
                    switch (a) {
                        case 1:
                            push_LONG(teste, X.LONG);
                            break;
                    }
                    switch (d) {
                        case 1:
                            push_DOUBLE(teste, X.DOUBLE);
                            break;
                    }
                    switch (e) {
                        case 1:
                            push_CHAR(teste, X.CHAR);
                            break;
                    }
            }
            break;

    }
    switch (b) {
        case 1:
            switch (g) {
                case 0:
                    push_DOUBLE(teste, Y.DOUBLE);
                    break;
                default:
                    switch (a) {
                        case 1:
                            push_LONG(teste, X.LONG);
                            break;
                    }
                    switch (d) {
                        case 1:
                            push_DOUBLE(teste, X.DOUBLE);
                            break;
                    }
                    switch (e) {
                        case 1:
                            push_CHAR(teste, X.CHAR);
                            break;
                    }

            }
            break;
    }
    switch (f) {
        case 1:
            switch (Y.CHAR) {
                case '\0':
                    push_CHAR(teste, Y.CHAR);
                    break;
                default:
                    switch (a) {
                        case 1:
                            push_LONG(teste, X.LONG);
                            break;
                    }
                    switch (d) {
                        case 1:
                            push_DOUBLE(teste, X.DOUBLE);
                            break;
                    }
                    switch (e) {
                        case 1:
                            push_CHAR(teste, X.CHAR);
                            break;
                    }

            }
            break;
    }
}

/** \brief função que devolve o elemento que for o primeiro verdadeiro ou o último falso
 *
 * @param teste : a stack
 */
void shortcutou(STACK *teste) {
    DATA X = pop(teste);
    DATA Y = pop(teste);

    int a = has_type(X, LONG);
    int b = has_type(Y, DOUBLE);
    int c = has_type(Y, LONG);
    int d = has_type(X, DOUBLE);
    int e = has_type(X, CHAR);
    int f = has_type(Y, CHAR);
    int g = 1;

    if (Y.DOUBLE == 0.0) {
        g=0;
    }

    switch (c) {
        case 1:
            switch (Y.LONG) {
                case 0:
                    switch (a) {
                        case 1:
                            push_LONG(teste, X.LONG);
                            break;
                    }
                    switch (d) {
                        case 1:
                            push_DOUBLE(teste, X.DOUBLE);
                            break;
                    }
                    switch (e) {
                        case 1:
                            push_CHAR(teste, X.CHAR);
                            break;
                    }
                    break;
                default:
                    push_LONG(teste, Y.LONG);
            }
            break;

    }
    switch (b) {
        case 1:
            switch (g) {
                case 0:
                    switch (a) {
                        case 1:
                            push_LONG(teste, X.LONG);
                            break;
                    }
                    switch (d) {
                        case 1:
                            push_DOUBLE(teste, X.DOUBLE);
                            break;
                    }
                    switch (e) {
                        case 1:
                            push_CHAR(teste, X.CHAR);
                            break;
                    }
                    break;
                default:
                    push_DOUBLE(teste, Y.DOUBLE);
            }
            break;
    }
    switch (f) {
        case 1:
            switch (Y.CHAR) {
                case '\0':
                    switch (a) {
                        case 1:
                            push_LONG(teste, X.LONG);
                            break;
                    }
                    switch (d) {
                        case 1:
                            push_DOUBLE(teste, X.DOUBLE);
                            break;
                    }
                    switch (e) {
                        case 1:
                            push_CHAR(teste, X.CHAR);
                            break;
                    }
                    break;
                default:
                    push_CHAR(teste, Y.CHAR);
            }
            break;
    }
}

/** \brief função que devolve o elemento que for menor, entre os dois dados
 *
 * @param teste : a stack
 */
void scminor(STACK *teste) {
    DATA X = pop(teste);
    DATA Y = pop(teste);


    if (has_type(X,LONG)) {
        if (has_type(Y,LONG)) {
            if (Y.LONG<=X.LONG) {
                push_LONG(teste, Y.LONG);
            }
            else {
                push_LONG(teste, X.LONG);
            }
        }
        if (has_type(Y,DOUBLE)) {
            if (Y.DOUBLE<=X.LONG) {
                push_DOUBLE(teste, Y.DOUBLE);
            }
            else {
                push_LONG(teste, X.LONG);
            }
        }
        if (has_type(Y,CHAR)) {
            if (Y.CHAR<=X.LONG) {
                push_CHAR(teste, Y.CHAR);
            }
            else {
                push_LONG(teste, X.LONG);
            }
        }
    }else if (has_type(X,DOUBLE)) {
        if (has_type(Y,LONG)) {
            if (Y.LONG<=X.DOUBLE) {
                push_LONG(teste, Y.LONG);
            }
            else {
                push_DOUBLE(teste, X.DOUBLE);
            }
        }
        if (has_type(Y,DOUBLE)) {
            if (Y.DOUBLE<=X.DOUBLE) {
                push_DOUBLE(teste, Y.DOUBLE);
            }
            else {
                push_DOUBLE(teste, X.DOUBLE);
            }
        }
        if (has_type(Y,CHAR)) {
            if (Y.CHAR<=X.DOUBLE) {
                push_CHAR(teste, Y.CHAR);
            }
            else {
                push_DOUBLE(teste, X.DOUBLE);
            }
        }
    } else if (has_type(X,CHAR)) {
        if (has_type(Y,LONG)) {
            if (Y.LONG<=X.CHAR) {
                push_LONG(teste, Y.LONG);
            }
            else {
                push_CHAR(teste, X.CHAR);
            }
        }
        if (has_type(Y,DOUBLE)) {
            if (Y.DOUBLE<=X.CHAR) {
                push_DOUBLE(teste, Y.DOUBLE);
            }
            else {
                push_CHAR(teste, X.CHAR);
            }
        }
        if (has_type(Y,CHAR)) {
            if (Y.CHAR<=X.CHAR) {
                push_CHAR(teste, Y.CHAR);
            }
            else {
                push_CHAR(teste, X.CHAR);
            }
        }
    }

}
/** \brief função que devolve o elemento que for maior, entre os dois dados
 *
 * @param teste : a stack
 */
void scmajor(STACK *teste) {
    DATA X = pop(teste);
    DATA Y = pop(teste);

    if (has_type(X,LONG)) {
        if (has_type(Y,LONG)) {
            if (Y.LONG>=X.LONG) {
                push_LONG(teste, Y.LONG);
            }
            else {
                push_LONG(teste, X.LONG);
            }
        }
        if (has_type(Y,DOUBLE)) {
            if (Y.DOUBLE>=X.LONG) {
                push_DOUBLE(teste, Y.DOUBLE);
            }
            else {
                push_LONG(teste, X.LONG);
            }
        }
        if (has_type(Y,CHAR)) {
            if (Y.CHAR>=X.LONG) {
                push_CHAR(teste, Y.CHAR);
            }
            else {
                push_LONG(teste, X.LONG);
            }
        }
    }else if (has_type(X,DOUBLE)) {
        if (has_type(Y,LONG)) {
            if (Y.LONG>=X.DOUBLE) {
                push_LONG(teste, Y.LONG);
            }
            else {
                push_DOUBLE(teste, X.DOUBLE);
            }
        }
        if (has_type(Y,DOUBLE)) {
            if (Y.DOUBLE>=X.DOUBLE) {
                push_DOUBLE(teste, Y.DOUBLE);
            }
            else {
                push_DOUBLE(teste, X.DOUBLE);
            }
        }
        if (has_type(Y,CHAR)) {
            if (Y.CHAR>=X.DOUBLE) {
                push_CHAR(teste, Y.CHAR);
            }
            else {
                push_DOUBLE(teste, X.DOUBLE);
            }
        }
    } else if (has_type(X,CHAR)) {
        if (has_type(Y,LONG)) {
            if (Y.LONG>=X.CHAR) {
                push_LONG(teste, Y.LONG);
            }
            else {
                push_CHAR(teste, X.CHAR);
            }
        }
        if (has_type(Y,DOUBLE)) {
            if (Y.DOUBLE>=X.CHAR) {
                push_DOUBLE(teste, Y.DOUBLE);
            }
            else {
                push_CHAR(teste, X.CHAR);
            }
        }
        if (has_type(Y,CHAR)) {
            if (Y.CHAR>=X.CHAR) {
                push_CHAR(teste, Y.CHAR);
            }
            else {
                push_CHAR(teste, X.CHAR);
            }
        }
    }
}

/** \brief função que devolve o primeiro valor se a condição for verdadeira, se não, devolve a segunda
 *
 * @param teste : a stack
 */
void ite(STACK *teste) {
    DATA X = pop(teste);
    DATA Y = pop(teste);
    DATA Z = pop(teste);

    int a = has_type(X, LONG);
    int b = has_type(Y, DOUBLE);
    int c = has_type(Y, LONG);
    int d = has_type(X, DOUBLE);
    int e = has_type(X, CHAR);
    int f = has_type(Y, CHAR);

    if ((has_type(Z,LONG) && Z.LONG ==0) || (has_type(Z,DOUBLE) && Z.DOUBLE == 0.0) || (has_type(Z,CHAR) && Z.CHAR =='\0')) {

        switch (a) {
            case 1:
                push_LONG(teste, X.LONG);
                break;

        }
        switch (d) {
            case 1:
                push_DOUBLE(teste, X.DOUBLE);
                break;
        }
        switch (e) {
            case 1:
                push_CHAR(teste, X.CHAR);
                break;
        }
    } else {
        switch (c) {
            case 1:
                push_LONG(teste, Y.LONG);
                break;

        }
        switch (b) {
            case 1:
                push_DOUBLE(teste, Y.DOUBLE);
                break;
        }
        switch (f) {
            case 1:
                push_CHAR(teste, Y.CHAR);
                break;
        }
    }
}
