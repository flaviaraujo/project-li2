/** \brief função que copia o topo da stack à variável
 *
 * @param s : a stack original
 * @param token : o identificador
 * @param variaveis : a stack onde são colocadas as variáveis e as letras atribuidas
 */
void guarda_val(STACK *s, char *token, STACK *variaveis);
/** \brief função que coloca no topo da stack o conteúdo da variável
 *
 * @param s : a stack original
 * @param token : o identificador
 * @param variaveis : a stack onde são colocadas as variáveis e as letras atribuidas
 * @param temporaria : a stack onde são colocadas as variáveis da stack variaveis para não perder as mesmas
 */
void coloca_var(STACK *s, char *token, STACK *variaveis, STACK *temporaria);
