/**
 * @file Ficheiro que contém a função principal do programa
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include "parser.h"
#include "stack.h"



/** \brief esta é a função principal do programa
 *
 * @return o valor 0
 */
int main () {
    char line[10240];

    assert(fgets(line, 10240, stdin) != NULL);
    assert(line[strlen(line)-1] == '\n');

    parse(line);
    return 0;
}
