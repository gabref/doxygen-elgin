/** @defgroup ma70 Funções
  * @ingroup ma7
  * @brief Descrição das funções de Modo Kiosk
  */

/**
 * @ingroup ma70
 * @{
 */

/**
 * @brief Função utilizada para desabilitar a barra de status do M10
 * 
 * @note Esta função por padrão desabilita a tela de bloqueio, 
 * sendo assim após a chamada da mesma não será possível 
 * visualizar a tela de bloqueio ao pressionar o botão POWER.
*/
void desabilitaBarraStatus();

/**
 * @brief Função utilizada para habilitar a barra de status do M10
 * @note Esta função por padrão habilita a tela de bloqueio caso 
 * seja bloqueada ao invocar o método para desabilitar barra de status, 
 * sendo assim após a chamada da mesma  será possível 
 * visualizar a tela de bloqueio ao pressionar o botão POWER.
*/
void habilitaBarraStatus();

/**
 * @brief Função utilizada para desativar a barra de navegação do M10
*/
void desabilitaBarraNavegacao();

/**
 * @brief Função utilizada para habilitar a barra de navegação do M10
*/
void habilitaBarraNavegacao();

/**
 * @brief Função utilizada para desativar o botão Power
 * 
 * @note Caso o equipamento entre em modo de descanso 
 * o botão volta a estar ativo para que você consiga desbloquear a tela novamente.
*/
void desabilitaBotaoPower();

/**
 * @brief Função utilizada para habilitar o botão Power
*/
void habilitaBotaoPower();

/**
 * @}
 */