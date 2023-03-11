/**
 * @file função que diz respeito ao parser
 */
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

/** \brief Esta é a função que vai fazer o parse de uma linha
 *
 * @param line A linha que foi lida, da qual se vai fazer o parse
 */
void parse(char *line) {
    char *delims = " \t\n";
    STACK *teste = new_stack();
    STACK *variaveis = new_stack();
    STACK *temporaria = new_stack();
    STACK *stack_array = new_stack();
    //char *token = strtok(line, delims);

    for(char *token = strtok(line, delims); token != NULL; token = strtok(NULL, delims)) {
        char *sobra1;
        char *sobra2;

        long val_l = strtol(token, &sobra1, 10);
        double val_d = strtod(token, &sobra2);
        if(strlen(sobra1) == 0)
            push_LONG(teste, val_l);

        else if(strlen(sobra2) == 0)
            push_DOUBLE(teste, val_d);

            /*else if(token[0] != '+')
                push_STRING(teste, token);
            */

        else if (strcmp(token, "A") == 0 || strcmp(token, "B") == 0 || strcmp(token, "C") == 0 || strcmp(token, "D") == 0 ||
                   strcmp(token, "E") == 0 || strcmp(token, "F") == 0 || strcmp(token, "G") == 0 || strcmp(token, "H") == 0 ||
                   strcmp(token, "I") == 0 || strcmp(token, "J") == 0 || strcmp(token, "K") == 0 || strcmp(token, "L") == 0 ||
                   strcmp(token, "M") == 0 || strcmp(token, "N") == 0 || strcmp(token, "O") == 0 || strcmp(token, "P") == 0 ||
                   strcmp(token, "Q") == 0 || strcmp(token, "R") == 0 || strcmp(token, "S") == 0 || strcmp(token, "T") == 0 ||
                   strcmp(token, "U") == 0 || strcmp(token, "V") == 0 || strcmp(token, "W") == 0 || strcmp(token, "X") == 0 ||
                   strcmp(token, "Y") == 0 || strcmp(token, "Z") == 0 ) {

            coloca_var(teste, token, variaveis, temporaria);

        }  else {
            switch (*token) {
                case '+':                                                      //SOMA
                    sum(teste, stack_array);
                    break;

                case '-':                                                     //DIFERENÇA
                    subtract(teste);
                    break;

                case '*':                                                   //MULTIPLICACAO
                    mult(teste);
                    break;

                case '/':                                                  //DIVISAO
                    division(teste);
                    break;

                case '(':                                                   //DECREMENTO
                    dec(teste);
                    break;

                case ')':                                                  //INCREMENTO
                    inc(teste);
                    break;

                case '%':                                           //RESTO DA DIVISAO
                    modulus(teste);
                    break;

                case '#':                                                     //POTENCIA
                    power(teste);
                    break;

                case '&':                                                       //AND
                    e(teste);
                    break;

                case '|':                                                           //OR
                    ou(teste);
                    break;

                case '^':                                                       //XOR
                    xorr(teste);
                    break;

                case '~':                                                           //NOT
                    nott(teste, stack_array);
                    break;

                case '\\':                                        //TROCA OS DOIS ULTIMOS ELEMENTOS
                    backs(teste);
                    break;

                case '@':                                       //TROCA OS TRES ULTIMOS ELEMENTOS
                    at(teste);
                    break;

                case ';':                                  //RETIRA O ULTIMO ELEMENTO DA STACK
                    scolon(teste);
                    break;

                case '_':                                           // REPLICA O ULTIMO ELEMENTO
                    undscore(teste);
                    break;

                case '$':                                 //COPIA N-ESIMO ELEMENTO PARA O TOPO DA STACK
                    dolar(teste);
                    break;

                case 'l':                                             //COMANDO QUE LE NOVA LINHA
                    readl(teste);
                    break;

                case 'i':
                    toint(teste);
                    break;

                case 'f':
                    tofloat(teste);
                    break;

                case 'c':
                    tochar(teste);
                    break;

                case '=':
                    equal(teste);
                    break;

                case '<':
                    minor(teste);
                    break;

                case '>':
                    major(teste);
                    break;

                case '!':
                    nottt(teste);
                    break;

                case '?':
                    ite(teste);
                    break;

                case '[':
                    cria_array(teste);
                    break;

                case ']':
                    fecha_array(teste, stack_array);
                    break;

                case '"':
                    cria_string(teste, token);
                    break;

                case 'e':
                    switch (*(token+1)) {

                        case '&':
                            shortcute(teste);
                            break;

                        case '|':
                            shortcutou(teste);
                            break;

                        case '<':
                            scminor(teste);
                            break;

                        case '>':
                            scmajor(teste);
                            break;
                    }
                    break;

                case ':':
                    guarda_val(teste, token, variaveis);
                    break;
            }
        }
    }
    print_stack(teste);
}
