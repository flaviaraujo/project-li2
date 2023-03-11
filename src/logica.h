/** \brief função que verifica se dois elementos são iguais
 *
 * @param s : a stack
 */
void equal(STACK *s);
/** \brief função que testa se o primeiro elemento é menor do que outro (se isto se verificar, devolve 1, se não, 0)
 *
 * @param s : a stack
 */
void minor(STACK *s);
/** \brief função que testa se o primeiro elemento é maior do que outro (se isto se verificar, devolve 1, se não, 0)
 *
 * @param s : a stack
 */
void major(STACK *s);
/** \brief função que testa se o elemento é igual a zero, se for, devolve 1, se não, 0 (nega o valor)
 *
 * @param s : a stack
 */
void nottt(STACK *s);
/** \brief função que devolve o elemento que for o primeiro falso ou o último verdadeiro
 *
 * @param s : a stack
 */
void shortcute(STACK *s);
/** \brief função que devolve o elemento que for o primeiro verdadeiro ou o último falso
 *
 * @param s : a stack
 */
void shortcutou(STACK *s);
/** \brief função que devolve o elemento que for menor, entre os dois dados
 *
 * @param s : a stack
 */
void scminor(STACK *s);
/** \brief função que devolve o elemento que for maior, entre os dois dados
 *
 * @param s : a stack
 */
void scmajor(STACK *s);

/** \brief função que devolve o primeiro valor se a condição for verdadeira, se não, devolve a segunda
 *
 * @param s : a stack
 */
void ite(STACK *s); 
