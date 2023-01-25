/** @defgroup tf Funções
  * @ingroup t2
  */

/**
 * @ingroup tf 
 * @{
 */

/**
 * @brief GetProdutoTef
 * 
 * @return Retorna o código do produto TEF em uso
 */
int GetProdutoTef();

/**
 * @brief GetClientTCP
 * 
 * @return Retorna a configuração atual do Client, no formato ip_client|porta_client
 */
const char *GetClientTCP();

/**
 * @brief Configura o IP e a porta onde o ElginTEF está operando;
 * 
 * @param ip string do IP a ser usado pelo ElginTEF
 * @param porta int da porta a ser usada pelo ElginTEF
 * @return Retorna o resultado da operação (erro ou sucesso). Em caso de sucesso, esses parâmetros serão persistidos no arquivo de configuração.
 */
const char *SetClientTCP(const char* ip, int porta);
 
/**
 * @brief Configura os dados do PDV 
 * 
 * Necessários para operação com ElginTEF e persiste-os no arquivo de configuração
 * 
 * @param textoPinpad O texto que será exibido no visor do Pinpad conectado à AC, normalmente o nome da AC
 * @param versaoAC String indicando a versão da AC; esse texto também é exibido no visor do Pinpad
 * @param nomeEstabelecimento O nome do estabelecimento no qual a AC está em execução
 * @param loja O nome/código (String) da loja (pertencente ao estabelecimento) na qual a AC está em execução
 * @param identificadorPontoCaptura O nome/código (String) do terminal (pertencente à loja) no qual a AC está em execução
 * @return Retorna sucesso, se o arquivo for criado/atualizado com sucesso, ou erro, caso contrário.
 */
const char *ConfigurarDadosPDV(const char* textoPinpad, const char* versaoAC, const char* nomeEstabelecimento, const char* loja, const char* identificadorPontoCaptura);

/**
 * @brief Inicia Operação
 * 
 * Estabelece uma conexão com o ElginTEF, permitindo que a API realize transações com o Client. 
 * Este método deve ser chamado sempre que a API for carregada ou após a execução do método #FinalizarOperacaoTEF.
 * Este método lê o arquivo de configuração para obter os dados do Client e do PDV, conforme documentado nas funções #SetClientTCP e #ConfigurarDadosPDV. <br>
 * Caso a leitura do arquivo falhe e essas funções ainda não foram chamadas no carregamento atual da biblioteca (execução da aplicação), elas deverão ser chamadas antes de prosseguir com a inicialização.
 * Opcionalmente, pode-se passar um JSON com os dados do PDV que serão usados nas operações subsequentes, sobrescrevendo os valores definidos no método #ConfigurarDadosPDV (o arquivo de configuração não é alterado nesse caso).
 * @param dadosCaptura Recebe payload com informações da Automação Comercial. **Parâmetro opcional**. 
 * * Se não for passado, a API irá consumir os dados presentes no arquivo de configuração **e1_tef_configs.json** com as informações dadas às funções #SetClientTCP e #ConfigurarDadosPDV.
 * * Se for passado, a API usará os dados passados no payload com as seguintes chaves: `textoPinpad`, `versaoAC`, `nomeEstabelecimento`, `loja`, `identificadorPontoCaptura`.
 * 
 * @return Uma string JSON com a seguinte estrutura:
 *      @code{.json}
 *          {
 *              "codigo": 0,
 *              "mensagem": "Sucesso",
 *              "tef": {
 *                  ...
 *              }
 *          }
 *      @endcode
 * 
 * * **codigo**: chave do tipo `int` que indica o resultado da função chamada pela API, **sempre** presente no JSON de resposta.
 * * **mensagem**: chave do tipo `string` que indica a mensagem / resposta referente ao **codigo** retornado, de acordo com a função chamada pela API, **sempre** presente no JSON de resposta.
 * * **tef**: chave do tipo `objeto JSON` que contém as chaves de resposta do TEF Elgin. <br> Essa chave é **retornada somente** em casos de sucesso com as funções de operação TEF: `IniciarOperacaoTEF()`, `RecuperarOperacaoTEF()`, `RealizarPagamentoTEF()`, `RealizarAdmTEF()`, `ConfirmarOperacaoTEF()`, `FinalizarOperacaoTEF()`.
 */
const char *IniciarOperacaoTEF(const char* dadosCaptura);


 
 
/**
 * @brief Função que recupera a operação cancelada.
 * 
 * Caso alguma operação falhe antes de ser concluída/confirmada (porque o "PDV caiu", por exemplo), este método pode ser chamado para iniciar uma nova comunicação com ElginTEF e recuperar os dados da operação interrompida, de forma que ela possa ser confirmada ou cancelada através do método #ConfirmarOperacaoTEF.
 * Opcionalmente, pode-se passar um JSON com os dados do PDV, sobrescrevendo os valores definidos no método #ConfigurarDadosPDV (o arquivo de configuração não é alterado nesse caso).
 * Esse método foi criado com o intuito de simplificar a recuperação de operações interrompidas e não substitui o serviço administrativo destinado a esse fim (Administração Pendências).
 * 
 * @param dadosCaptura Recebe payload com informações da Automação Comercial. **Parâmetro opcional**. 
 * * Se não for passado, a API irá consumir os dados presentes no arquivo de configuração **e1_tef_configs.json** com as informações dadas às funções #SetClientTCP e #ConfigurarDadosPDV.
 * * Se for passado, a API usará os dados passados no payload com as seguintes chaves: `textoPinpad`, `versaoAC`, `nomeEstabelecimento`, `loja`, `identificadorPontoCaptura`.
 * 
 * @return Uma string JSON com a seguinte estrutura:
 *      @code{.json}
 *          {
 *              "codigo": 0,
 *              "mensagem": "Sucesso",
 *              "tef": {
 *                  ...
 *              }
 *          }
 *      @endcode
 * 
 * * **codigo**: chave do tipo `int` que indica o resultado da função chamada pela API, **sempre** presente no JSON de resposta.
 * * **mensagem**: chave do tipo `string` que indica a mensagem / resposta referente ao **codigo** retornado, de acordo com a função chamada pela API, **sempre** presente no JSON de resposta.
 * * **tef**: chave do tipo `objeto JSON` que contém as chaves de resposta do TEF Elgin. <br> Essa chave é **retornada somente** em casos de sucesso com as funções de operação TEF: `IniciarOperacaoTEF()`, `RecuperarOperacaoTEF()`, `RealizarPagamentoTEF()`, `RealizarAdmTEF()`, `ConfirmarOperacaoTEF()`, `FinalizarOperacaoTEF()`.
 */
const char *RecuperarOperacaoTEF(const char* dadosCaptura);

/**
 * @brief Inicia uma operação de pagamento.
 *
 * @param codigoOperacao Indica o tipo de cartão a ser utilizado no pagamento, conforme lista a seguir
 * esse parâmetro é ignorado caso a operação esteja em estado de coleta.
 * 0 - Ignora cartão (o tipo de cartão será perguntado durante o processo de coleta)
 * 1 - Cartão de crédito
 * 2 - Cartão de débito
 * 3 - Voucher (débito)
 * 4 - Frota (débito)
 * 5 - Private label (crédito)
 *
 * @param dadosCaptura JSON com as informações iniciais do pagamento ou os dados de resposta da coleta. Para detalhes sobre os valores possíveis conferir a seção Payloads em @ref t2
 * @param novaTransacao Informa à função em qual estado encontra-se o processo de pagamento:
 * * true - indica o início de uma nova operação de pagamento
 * * false - indica uma operação já iniciada, em estado de coleta em @ref t2
 * @return Uma string JSON com a seguinte estrutura:
 *      @code{.json}
 *          {
 *              "codigo": 0,
 *              "mensagem": "Sucesso",
 *              "tef": {
 *                  ...
 *              }
 *          }
 *      @endcode
 * 
 * * **codigo**: chave do tipo `int` que indica o resultado da função chamada pela API, **sempre** presente no JSON de resposta.
 * * **mensagem**: chave do tipo `string` que indica a mensagem / resposta referente ao **codigo** retornado, de acordo com a função chamada pela API, **sempre** presente no JSON de resposta.
 * * **tef**: chave do tipo `objeto JSON` que contém as chaves de resposta do TEF Elgin. <br> Essa chave é **retornada somente** em casos de sucesso com as funções de operação TEF: `IniciarOperacaoTEF()`, `RecuperarOperacaoTEF()`, `RealizarPagamentoTEF()`, `RealizarAdmTEF()`, `ConfirmarOperacaoTEF()`, `FinalizarOperacaoTEF()`.
 */
const char *RealizarPagamentoTEF(int codigoOperacao, const char* dadosCaptura, bool novaTransacao);

/**
 * @brief Inicia uma operação administrativa.
 * 
 * @param codigoOperacao Indica o tipo de operação administrativa a ser realizada, conforme lista a seguir
 * Esse parâmetro é ignorado caso a operação esteja em estado de coleta.
 * 0 - Perguntar operação no processo de coleta
 * 1 - Cancelamento
 * 2 - Pendências
 * 3 - Reimpressão
 * @param dadosCaptura JSON com as informações iniciais da operação administrativa ou os dados de resposta da coleta. Para detalhes sobre os valores possíveis conferir a seção **Payloads** em @ref t2
 * @param novaTransacao Informa à função em qual estado encontra-se o processo administrativo:
 * * true - indica o início de uma nova operação administrativa
 * * false - indica uma operação já iniciada, em estado de coleta
 * @return Uma string JSON com a seguinte estrutura:
 *      @code{.json}
 *          {
 *              "codigo": 0,
 *              "mensagem": "Sucesso",
 *              "tef": {
 *                  ...
 *              }
 *          }
 *      @endcode
 * 
 * * **codigo**: chave do tipo `int` que indica o resultado da função chamada pela API, **sempre** presente no JSON de resposta.
 * * **mensagem**: chave do tipo `string` que indica a mensagem / resposta referente ao **codigo** retornado, de acordo com a função chamada pela API, **sempre** presente no JSON de resposta.
 * * **tef**: chave do tipo `objeto JSON` que contém as chaves de resposta do TEF Elgin. <br> Essa chave é **retornada somente** em casos de sucesso com as funções de operação TEF: `IniciarOperacaoTEF()`, `RecuperarOperacaoTEF()`, `RealizarPagamentoTEF()`, `RealizarAdmTEF()`, `ConfirmarOperacaoTEF()`, `FinalizarOperacaoTEF()`.
 */
const char *RealizarAdmTEF(int codigoOperacao, const char* dadosCaptura, bool novaTransacao);

/**
 * @brief Realiza uma operação de PIX. Essa função segue o mesmo fluxo da função 
 * RealizarPagamentoTEF e depende do serviço habilitado na operadora de TEF.
​​ * ​​​​​É importante que após a finalização da transação a automação realize a 
 * confirmação da transação usando a função de confirmação.
 * @note É obrigatório que se tenha um pinpad para a apresentação do QRCode.
 * @param dadosCaptura Usado para enviar o valor da transação em centavos. Ex: 1000 = R$10,00
 * @param novaTransacao Usado para indicar o inicio de uma transação.
 * @return O Retorno será um JSON no padrão da API onde serão retornadas as informações de 
 * acordo com o processamento da transação.
 * Durante o processamento os dados utilizados para gerar a imagem do QRCode em tela 
 * devem ser retornados na chave "mensagemResultado" do obj "tef". Tal mensagem tem a 
 * seguinte estrutura: QRCODE;[dados];[infoComplementaresEmBase64]
 * sendo que o index 1 dessa estrutura pode ser usado para gerar a imagem de apresentação.
 * ### Exemplo de retorno
 *      @code{.json}
 *          {
 *              "codigo": 0,
 *              "mensagem": "Sucesso",
 *              "tef": {
 *                  "automacao_coleta_retorno": "0",
 *                  "automacao_coleta_sequencial": "2",
 *                  "mensagemResultado": "QRCODE;89504E470D0A1A0A0000000D4...hIEVMR0lOIn1dfQ"
 *              }
 *          }
 *      @endcode
 * Após o pagador realizar a leitura e pagamento da transação o retorno da transação deve ser similar ao retorno da transação convencional.
*/
const char *RealizarPixTEF(const char* dadosCaptura, bool novaTransacao);

/**
 * @brief Função utilizada para confirmar ou cancelar uma operação recém-realizada.
 * 
 * Deve ser chamada após o término da coleta, quando  a chave `resultadoTransacao` == 0.
 *
 * Essa função exige que alguma operação esteja em andamento.
 * Caso ocorra algum erro durante a operação (queda de conexão, queda de energia ou qualquer outro problema que interrompa a comunicação entre API <--> ElginTEF), existem duas formas para cancelá-la ou confirmá-la: 
 *   
 * a. Chamar os métodos RecuperarOperacaoTEF() + ConfirmarOperacaoTEF()
 *      - Devem ser chamadas imediatamente após a solução do problema 
 * b. Chamar os métodos IniciarOperacaoTEF() + RealizarAdmTEF() // codigoOperacao = 2 (pendências) 
 *      - Forma recomendada, pode ser chamada a qualquer momento 
 * 
 * @param id Indica o sequencial utilizado na operação a ser confirmada/cancelada.
 * Esse é o sequencial opcionalmente informado no payload no início da operação, que também é retornado ao usuário ao término da coleta.
 * @param acao Indica a ação a ser realizada com a operação em questão:
 * 0 - Cancelar
 * 1 - Confirmar
 *  
 * @return Uma string JSON com a seguinte estrutura:
 *      @code{.json}
 *          {
 *              "codigo": 0,
 *              "mensagem": "Sucesso",
 *              "tef": {
 *                  ...
 *              }
 *          }
 *      @endcode
 * 
 * * **codigo**: chave do tipo `int` que indica o resultado da função chamada pela API, **sempre** presente no JSON de resposta.
 * * **mensagem**: chave do tipo `string` que indica a mensagem / resposta referente ao **codigo** retornado, de acordo com a função chamada pela API, **sempre** presente no JSON de resposta.
 * * **tef**: chave do tipo `objeto JSON` que contém as chaves de resposta do TEF Elgin. <br> Essa chave é **retornada somente** em casos de sucesso com as funções de operação TEF: `IniciarOperacaoTEF()`, `RecuperarOperacaoTEF()`, `RealizarPagamentoTEF()`, `RealizarAdmTEF()`, `ConfirmarOperacaoTEF()`, `FinalizarOperacaoTEF()`.
 */
const char *ConfirmarOperacaoTEF(int id, int acao);

/**
 * @brief Finaliza a conexão com o ElginTEF.
 * 
 * Após essa chamada a API não realizará novas transações com o Client até que uma nova chamada de IniciarOperacaoTEF() seja feita.
 * 
 * @param id Indica o sequencial a ser utilizado na finalização, devendo ser o valor do sequencial usado na última operação somado com 1.
 * Pode-se passar o valor 1, uma vez que a API resolve com o ElginTEF o sequencial correto a ser utilizado.
 * @return Uma string JSON com a seguinte estrutura:
 *      @code{.json}
 *          {
 *              "codigo": 0,
 *              "mensagem": "Sucesso",
 *              "tef": {
 *                  ...
 *              }
 *          }
 *      @endcode
 * 
 * * **codigo**: chave do tipo `int` que indica o resultado da função chamada pela API, **sempre** presente no JSON de resposta.
 * * **mensagem**: chave do tipo `string` que indica a mensagem / resposta referente ao **codigo** retornado, de acordo com a função chamada pela API, **sempre** presente no JSON de resposta.
 * * **tef**: chave do tipo `objeto JSON` que contém as chaves de resposta do TEF Elgin. <br> Essa chave é **retornada somente** em casos de sucesso com as funções de operação TEF: `IniciarOperacaoTEF()`, `RecuperarOperacaoTEF()`, `RealizarPagamentoTEF()`, `RealizarAdmTEF()`, `ConfirmarOperacaoTEF()`, `FinalizarOperacaoTEF()`.
 */
const char *FinalizarOperacaoTEF(int id);

/**
 * @brief Realiza a coleta de um dado no PINPAD. Os dados inseridos são apresentados no display 
 * do pinpad mascarados com (*).
 * @param tipoColeta Identifica qual coleta deve ser realizada. Os valores possíveis são: 
 * 1(RG), 2(CPF), 3(CNPJ) e 4(Telefone)
 * @param confirmar Indica que ao fim da operação deve ser realizada a confirmação do dado pelo pinpad.
 * @return O retorno será um JSON no padrão da API onde a informação coletada esta preenchida na 
 * chave "resultadoCapturaPinPad" do obj "tef". A automação deve validar o valor de "retorno", 
 * quando igual a 1 a operação pode ser considerada como sucesso. Quando igual a 9 indica que 
 * o usuário não cancelou a operação.
 * ### Exemplo Sucesso
 *      @code{.json}
 *          {
 *              "codigo": 0,
 *              "mensagem": "Sucesso",
 *              "tef": {
 *                  "mensagemResultado": "CNPJC+691980880001",
 *                  "resultadoCapturaPinPad": "691980880001",
 *                  "retorno": "1",
 *                  "sequencial": "101",
 *                  "servico": "perguntar"
 *              }
 *          }
 *      @endcode
 * 
 * ### Exemplo Cancelamento
 *      @code{.json}
 *          {
 *              "codigo": 0,
 *              "mensagem": "Sucesso",
 *              "tef": {
 *                  "mensagemResultado": "Operacao cancelada pelo cliente",
 *                  "retorno": "9",
 *                  "sequencial": "8",
 *                  "servico": "coletar"
 *              }
 *          }
 *      @endcode
*/
const char *RealizarColetaPinPad(int tipoColeta, bool confirmar);

/**
 * @brief Realiza a confirmação de um dado coletado usando o pinpad
 * @param tipoCaptura Indica qual o tipo da confirmação a ser realizada. 
 * Os valores possíveis são: 1(RG), 2(CPF), 3(CNPJ), 4(Telefone), 5(seleção) ou 6(Operadora)
 * @param dadosCaptura Dados a serem apresentados no display do pinpad.
 * @return O retorno será um JSON no padrão da API onde a informação coletada esta preenchida 
 * na chave "resultadoCapturaPinPad" do obj "tef". A automação deve validar o valor de "retorno", 
 * quando igual a 1 a operação pode ser considerada como sucesso. Quando igual a 9 indica que 
 * o usuário não confirmou a operação.
 * ### Exemplo Sucesso
 *      @code{.json}
 *          {
 *              "codigo": 0,
 *              "mensagem": "Sucesso",
 *              "tef": {
 *                  "mensagemResultado": "CNPJC+691980880001",
 *                  "resultadoCapturaPinPad": "691980880001",
 *                  "retorno": "1",
 *                  "sequencial": "101",
 *                  "servico": "perguntar"
 *              }
 *          }
 *      @endcode
 * 
 * ### Exemplo Cancelamento
 *      @code{.json}
 *          {
 *              "codigo": 0,
 *              "mensagem": "Sucesso",
 *              "tef": {
 *                  "mensagemResultado": "RGC+000000000",
 *                  "retorno": "9",
 *                  "sequencial": "9",
 *                  "servico": "perguntar"
 *              }
 *          }
 *      @endcode
*/
const char *ConfirmarCapturaPinPad(int tipoCaptura, const char *dadosCaptura);

/**
 * @} 
 */