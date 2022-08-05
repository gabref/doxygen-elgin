/*! @defgroup g130 Funções
  * @ingroup g13
  * @brief Descrição das funções de PIX4
  */

/**
 * @ingroup g130 
 * @{
 */

/**
 * @brief Método utilizado para estabelecer conexão usb com PIX4.
 * 
 * @param porta `char*` Parâmetro do tipo cadeia de caracteres que recebe a porta COM em que o PIX4 está conectado, por exemplo: `"COM4"`.
 * @return `int` O retorno da função é do tipo inteiro. <br>
 * A função bem sucedida deve retornar 0.<br>
 * | Código Erro | Descrição| 
 * | :--- | :--- |
 * | -12 | Dispositivo não existe |
 * | -13 | Permissão Negada |
 * | -14 | Erro Desconhecido |
 * | -19 | Dispositivo Removido Inesperadamente | 
 */
int AbreConexaoDisplay(const char* porta);

/**
 * @brief Método utilizado para obter a versão atual do firmware. 
 * @return `int` O retorno da função é do tipo numérico.<br>
 * A função bem sucedida deve retornar a versao atual do firmware (ex: 13).<br>
 * A função mal sucedida deve retornar -1.
 */
int ObtemVersaoFirmware(); 

/**
 * @brief Método utilizado para obter o estado atual da conexão do equipamento.
 * 
 * @return `boolean` O retorno da função é do tipo boolean.<br>
 * A função bem sucedida deve retornar TRUE.<br>
 * A função mal sucedida deve retornar FALSE.<br>
 */
boolean ObtemConexao();

/**
 * @brief Método usado para desconectar o PIX4.
 * 
 * @return `int` O retorno da função é do tipo numérico.<br>
 * A função bem sucedida deve retornar 0.<br>
 * A função mal sucedida deve retornar -1.<br>
 */
int DesconectarDisplay();

/**
 * @brief Método utilizado na inicialização e limpeza da tela para novas apresentações.
 * 
 * @return `int` O retorno da função é do tipo numérico.<br>
 * A função bem sucedida deve retornar 0.<br>
 * A função mal sucedida deve retornar -1. <br>
 */
int InicializaDisplay();

/**
 * @brief Método usado na reinicialização do Display PIX4, após reinicialização necessário realizar uma nova abertura de conexão.
 * 
 * @return `int` O retorno da função é do tipo numérico.<br>
 * A função bem sucedida deve retornar 0.<br>
 * A função mal sucedida deve retornar -1. <br>
 */
int ReinicializaDisplay();

/**
 * @brief Método utilizado para gravar imagem no dispositivo.
 * 
 * @note A resolução máxima do hardware é 320x480, então qualquer imagem acima desta resolução não será visualizado como deveria.
 * 
 * @param fileName Define o nome identificador da imagem a ser salva.
 * Ex:<br>
 * | fileName | filePath |
 * | :--- | :--- |
 * | Imagem Inicial | logo.jpg |
 * | Imagem 1 | p1.jpg |
 * | Imagem 2 | p3.jpg |
 * <br>
 * @param filePath `char*` Define o caminho onde se encontra a imagem a ser salva.
 * @param largura `char*` Define a largura imagem. (ex. 320)
 * @param altura `char*` Define a altura imagem. (ex. 480)
 * @return `int` O retorno da função é do tipo numérico.<br>
 * A função bem sucedida deve retornar 0.<br>
 * A função mal sucedida deve retornar -1. <br>
 */
int CarregaImagemDisplay(const char* fileName, const char* filePath, final int largura, final int altura);

/**
 * @brief Método utilizado para apresentar uma imagem  gravada anteriormente usando método CarregaImagemDisplay().
 * 
 * @param fileName `char*` Define o nome dado ao arquivo quando carregado.
 * @param posH `char*` Define a coordenada posição horizontal. 0 >= posH <= 480.
 * @param posV `char*` Define a coordenada posição vertical. 0 >= posV <= 300.
 * @param tipo `char*` Define o tipo de apresentação.<br>
 * | Valor | Descrição |
 * | :--- | :--- |
 * | 0 | Apenas mostrar |
 * | 1 | Mostrar após limpar a tela |
 * <br>
 * @return `int` O retorno da função é do tipo numérico.<br>
 * A função bem sucedida deve retornar 0.<br>
 * A função mal sucedida deve retornar -1. <br>
 */
int ApresentaImagem(const char* fileName, int posH, int posV, int tipo);

/**
 * @brief Método utilizado para apresentar o qrCode na coordenada especificada.
 * 
 * @param qrCode `char*` Define o valor do QRCode a ser apresentado.
 * @param tamanho `int` Parâmetro do tipo inteiro que define o  tamanho do qrCode. 15 >= tamanho <= 255.
 * @param posH `int` Parâmetro do tipo inteiro que define a coordenada posição horizontal. 0 >= posH <= 480.
 * @param posV `int` Parâmetro do tipo inteiro que define a coordenada posição vertical. 0 >= posV <= 300.
 * @return `int` O retorno da função é do tipo numérico.<br>
 * A função bem sucedida deve retornar 0.<br>
 * A função mal sucedida deve retornar -1. <br>
 */
int ApresentaQRCode(const char* qrCode, int tamanho, int posH, int posV);

/**
 * @brief Método utilizado para apresentar um texto colorido na coordenada especificada.
 * 
 * @param texto `char*` Parâmetro do tipo caractere que define o texto a ser apresentado.
 * @param idTexto `int` Parâmetro do tipo numérico que define o id do texto a ser apresentado. `1 >= idTexto =< 19`.
 * @param tamanho `int` Parâmetro do tipo numérico que define o tamanho da fonte. `10 >= tamanho =< 50`.
 * @param posH `int` Parâmetro do tipo numérico que define a coordenada posição horizontal. `0 >= posH <= 480`.
 * @param posV `int` Parâmetro do tipo numérico que define a coordenada posição vertical. `0 >= posV <= 300`.
 * @param hexadecimal `char*` Parâmetro do tipo cadeia de caracteres que define a cor da fonte em hexadecimal.
 * @return `int` O retorno da função é do tipo numérico.<br>
 * A função bem sucedida deve retornar 0.<br>
 * A função mal sucedida deve retornar -1. <br>
 */
int ApresentaTextoColorido(const char* texto, int idTexto,int tamanho,int posH,int posV,String hexadecimal);

/**
 * @brief Método utilizado para apresentar uma lista dinâmica de compras.
 * 
 * @param descricao `char*` Parâmetro do tipo caractere que define a descrição do produto.
 * @param valor `double` Parâmetro do tipo numérico que define o valor do Produto.
 */
void ApresentaListaCompras(const char* descricao, double valor);

/**
 * @brief Método utilizado para inicializar a tela de finalização de venda.
 * 
 * @param subTotal `double` Parâmetro do tipo numérico que define o valor do sub total da venda.
 * @param desconto `double` Parâmetro do tipo numérico que define o valor desconto da venda.
 * @param totalPagar `double` Parâmetro do tipo numérico que define o valor total a pagar da venda.
 */
void InicializaLayoutPagamento(double subTotal, double desconto, double totalPagar);

/**
 * @brief Método utilizado para adicionar uma forma de pagamento ao layout de finalização da venda.
 * 
 * @param tipoPagamento `int` Parâmetro do tipo inteiro que define qual tipo de pagamento sera adicionado. (1 >= tipoPagamento <= 4)<br>
 * | Valor | Descrição |
 * | :--- | :--- |
 * | 1 | Dinheiro |
 * | 2 | Crédito |
 * | 3 | Débito |
 * | 4 | PIX |
 * <br>
 * @param valor `double` Parâmetro do tipo double que define o valor da forma de pagamento.
 * @return `int` O retorno da função é do tipo numérico.<br>
 * A função bem sucedida deve retornar 0.<br>
 * A função mal sucedida deve retornar -1. <br>
 */
int AdicionaFormaPagamento(int tipoPagamento, double valor);

/**
 * @} 
 */