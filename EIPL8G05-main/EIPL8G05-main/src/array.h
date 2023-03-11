/** \brief função que cria o array
 *
 * @param s : a stack
 */
void cria_array(STACK *s);
/** \brief função que preenche e fecha o array
 *
 * @param s : a stack
 * @param p : a stack onde vai ser colocado o array
 */
void fecha_array(STACK *s, STACK *p);
/** \brief função que retira as aspas da string e a devolve à stack
 *
 * @param s : a stack
 * @param token : as aspas
 */
void cria_string(STACK *s, char *token);
