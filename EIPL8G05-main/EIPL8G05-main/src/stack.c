
/**
 * @file contém a stack
 */
#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

/** \brief a função vai buscar um type e se esse type e a máscara forem diferentes
 * de 0, devolve o que queremos
 *
 * @param elem : elemento da STACK
 * @param mask : pode ser LONG, DOUBLE, CHAR ou STRING
 * @return age como um booleano
 */
int has_type(DATA elem, int mask){
    return (elem.type & mask) != 0;
}

/** \brief cria uma stack
 *
 * @return s :elementos para a stack
 */
STACK *new_stack(){
    STACK *s = (STACK *) calloc(1, sizeof(STACK));
    s->size = 100;
    s->stack = (DATA *) calloc(s->size, sizeof(DATA));
    return s;
}

/** \brief coloca os elemntos na stack
 *
 * @param s : a stack para onde vao os elemntos
 * @param elem : o elemento que vai para a stack e o seu type
 */
void push(STACK *s, DATA elem){
    if(s->size == s->n_elems){
        s->size += 100;
        s->stack = (DATA *) realloc(s->stack, s->size * sizeof(DATA));
    }
    s->stack[s->n_elems] = elem;
    s->n_elems++;
}

/**\brief retira o último elemento da stack
 *
 * @param s a stack de onde vao sair os elementos
 * @return
 */
DATA pop(STACK *s){
    s->n_elems--;
    return s->stack[s->n_elems];
}
/** \brief dá o topo da stack
 *
 * @param s a stack onde se encontra o elemento
 * @return
 */
DATA top(STACK *s){
    return s->stack[s->n_elems -1];
}
/** \brief verifica se a stack está vazia
 *
 * @param s a stack
 * @return
 */
int is_empty(STACK *s){
    return s->n_elems = 0;
}

/** \brief função que imprime o resultado
 *
 * @param s a stack que foi lida da qual provém o resultado
 */
void print_stack(STACK *s){
    for(int i = 0; i <s->n_elems; i++){
        DATA elem = s->stack[i];
        TYPE type = elem.type;
        switch(type){
            case LONG: printf("%ld", elem.LONG);
                break;
            case DOUBLE: printf("%g", elem.DOUBLE);
                break;
            case CHAR: printf("%c", elem.CHAR);
                break;
            case STRING: printf("%s", elem.STRING);
                break;
        }
    }
    printf("\n");
}

/** \brief contém as funcoes que serao usadas para fazer push e pop de diferentes types na stack
 *
 */
#define STACK_OPERATION(_type, _name)			\
	void push_##_name(STACK *s, _type val){ 	\
		DATA elem;								\
		elem.type = _name;						\
		elem._name = val;						\
		push(s, elem);							\
	}											\
	_type pop_##_name(STACK *s){				\
		DATA elem = pop(s); 					\
		assert(elem.type == _name);				\
		return elem._name;						\
	}

/** \brief cria 2 protótipos
 *
 * @param s tipo de dados
 * @param val o nome que tem na estrutura
 */
STACK_OPERATION(long, LONG)
/** \brief cria 2 protótipos
 *
 * @param s tipo de dados
 * @param val o nome que tem na estrutura
 */
STACK_OPERATION(double, DOUBLE)
/** \brief cria 2 protótipos
 *
 * @param s tipo de dados
 * @param val o nome que tem na estrutura
 */
STACK_OPERATION(char, CHAR)
/** \brief cria 2 protótipos
 *
 * @param s tipo de dados
 * @param val o nome que tem na estrutura
 */
STACK_OPERATION(char *, STRING)
// STACK_OPERATION(DATA, data)
