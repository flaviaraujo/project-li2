/** \brief protótipo da função que faz a soma ou concatena arrays
 *
 * @param s : a stack
 * @param p : a stack onde vai ser colocado o array
 */
void sum(STACK *s, STACK *p);
/** \brief protótipo da função que faz a subtração
 *
 * @param s : a stack
 */
void subtract(STACK *s);
/** \brief protótipo da função que faz a multiplicação
 *
 * @param s : a stack
 */
void mult(STACK *s);
/** \brief protótipo da função que faz a divisão
 *
 * @param s : a stack
 */
void division(STACK *s);
/** \brief protótipo da função que faz a decrementação
 *
 * @param s : a stack
 */
void dec(STACK *s);
/** \brief protótipo da função que faz a incrementação
 *
 * @param s : a stack
 */
void inc(STACK *s);
/** \brief protótipo da função que faz o módulo da divisão inteira
 *
 * @param s : a stack
 */
void modulus(STACK *s);
/** \brief protótipo da função que faz a potenciação
 *
 * @param s : a stack
 */
void power(STACK *s);
/** \brief protótipo da função que faz o e lógico
 *
 * @param s : a stack
 */
void e(STACK *s);
/** \brief protótipo da função que faz o ou lógico
 *
 * @param s : a stack
 */
void ou(STACK *s);
/** \brief protótipo da função que faz o ou exclusivo
 *
 * @param s : a stack
 */
void xorr(STACK *s);
/** \brief protótipo da função que faz a negação ou coloca na stack teste todos os elementos do array
 *
 * @param s : a stack
 * @param p : a stack onde vai ser colocado o array
 */
void nott(STACK *s, STACK *p);
/** \brief protótipo da função que faz a troca dos dois últimos elementos da stack
 *
 * @param s : a stack
 */
void backs(STACK *s);
/** \brief protótipo da função que faz rodar os 3 elementos no topo da stack
 *
 * @param s : a stack
 */
void at(STACK *s);
/** \brief protótipo da função que faz pop do último elemento da stack
 *
 * @param s : a stack
 */
void scolon(STACK *s);
/** \brief protótipo da função que duplica o último elemento da stack
 *
 * @param s : a stack
 */
void undscore(STACK *s);
/** \brief protótipo da função que copia o n-ésimo elemento para o topo da stack
 *
 * @param s : a stack
 */
void dolar(STACK *s);
/** \brief protótipo da função que faz a leitura da linha seguinte
 *
 * @param s : a stack
 */
void readl(STACK *s);
/** \brief protótipo da função que converte o topo da stack num inteiro
 *
 * @param s : a stack
 */
void toint(STACK *s);
/** \brief protótipo da função que converte o topo da stack num decimal
 *
 * @param s : a stack
 */
void tofloat(STACK *s);
/** \brief protótipo da função que converte o topo da stack num caracter
 *
 * @param s : a stack
 */
void tochar(STACK *s);
