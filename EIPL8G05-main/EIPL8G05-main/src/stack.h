/**
 *@file biblioteca utilizada para a main que contém uma função
 */
 

/** \brief a constante SIZE possui tamanho 10240
 *
 */
#define SIZE    10240
/**\brief definem as macros que vão ser utilizadas
 *
 */
#ifndef __STACK_H__
#define __STACK_H__

#include <assert.h>

/** \brief declara um tipo de dados enumerados associados a potências de base 2 para serem utilizados nas máscaras
 *
 */
typedef enum
{
    /** \brief tipo de dados para enum se for long
     *
     */
    LONG = 1,
    /** \brief tipo de dados para enum se for double
     *
     */
    DOUBLE = 2,
    /** \brief tipo de dados para enum se for char
     *
     */
    CHAR = 4,
    /** \brief tipo de dados para enum se for string
     *
     */
    STRING = 8
} TYPE;
/** \brief criação da máscara INTEGER
 *
 */
#define INTEGER (LONG | CHAR)
/** \brief criação da máscara NUMBER
 *
 */
#define NUMBER (INTEGER | DOUBLE)

/** \brief atribui a máscara ao tipo de dados
 *
 */
typedef struct data
{
    /** \brief definição dos tipos de dados
     *
     */
    TYPE type;
    //Esta parte devia ser transformada em union mais tarde
    /** \brief tipo de dados para data se for long
     *
     */
    long LONG;
    /** \brief tipo de dados para data se for double
     *
     */
    double DOUBLE;
    /** \brief tipo de dados para data se for char
     *
     */
    char CHAR;
    /** \brief tipo de dados para data se for string
     *
     */
    char *STRING;
} DATA;

/** \brief a stack é um array do tipo *stack
 *
 */
typedef struct stack {
    /** \brief tipo de DATA usada na stack
     *
     */
    DATA *stack;
    /** \brief tamanho da stack
     *
     * nota: o size não é o número de elementos da stack mas sim o seu tamanho
     */
    int size;
    /** \brief número de elementos da stack
     *
     */
    int n_elems;
} STACK;

/** \brief protótipo
 *
 * @param elem
 * @param mask
 * @return
 */
int has_type(DATA elem, int mask); //protótipo

/** \brief protótipo
 *
 * @return
 */
STACK *new_stack();

/**\brief protótipo
 *
 * @param s a stack para onde vai o elemento
 * @param elem elemento que vai para a stack
 */
void push(STACK *s, DATA elem);    //recebe um apontador e um data
/** \brief protótipo
 *
 * @param s a stack de onde vai sair o elemento
 * @return um data
 */
DATA pop(STACK *s);
/** \brief protótipo
 *
 * @param s a stack
 * @return um data
 */
DATA top(STACK *s);
/** \brief protótipo
 *
 * @param s a stack
 * @return
 */
int is_empty(STACK *s);
/** \brief protótipo
 *
 * @param s: a stack que foi lida da qual provém o resultado
 */
void print_stack(STACK *s);

/** \brief cria um protótipo. Faz substituição de texto
 *
 */
#define STACK_OPERATION_PROTO(_type, _name)    \
    void push_##_name(STACK *s, _type val);    \
    _type pop_##_name(STACK *s);

/** \brief cria 2 protótipos
 *
 * @param s tipo de dados
 * @param val o nome que tem na estrutura
 */
STACK_OPERATION_PROTO(long, LONG)
/** \brief cria 2 protótipos
 *
 * @param s tipo de dados
 * @param val o nome que tem na estrutura
 */
STACK_OPERATION_PROTO(double, DOUBLE)
/** \brief cria 2 protótipos
 *
 * @param s tipo de dados
 * @param val o nome que tem na estrutura
 */
STACK_OPERATION_PROTO(char, CHAR)
/** \brief cria 2 protótipos
 *
 * @param s tipo de dados
 * @param val o nome que tem na estrutura
 */
STACK_OPERATION_PROTO(char *, STRING)

#endif
