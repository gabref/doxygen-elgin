/**
 * @ingroup t2 
 * @{
 */

/**
 * @brief Get the Produto Tef object
 * 
 * @return int Retorna o código do produto TEF em uso
 */
int GetProdutoTef();

/**
 * @brief Informa à API qual produto TEF será utilizado 
 * 
 * No momento temos apenas um produto implementado, logo, este será o produto padrão e essa função pode ser ignorada.
 * 
 * @param produtoTef 
 */
void SetProdutoTef(int produtoTef);

/**
 * @brief Get the Client T C P object
 * 
 * @return const char* Retorna a configuração atual do Client, no formato ip_client|porta_client
 */
const char *GetClientTCP();

/**
 * @brief Configura o IP e a porta onde o V$PagueClient está operando;
 * 
 * @param ip 
 * @param porta 
 * @return const char* retorna o resultado da operação (erro ou sucesso). Em caso de sucesso, esses parâmetros serão persistidos no arquivo de configuração.
 */
const char *SetClientTCP(const char* ip, int porta);
 
/**
 * @brief Configura os dados do PDV 
 * 
 * Necessários para operação com V$PagueClient. e persiste-os no arquivo de configuração
 * 
 * @param textoPinpad 
 * @param versaoAC 
 * @param nomeEstabelecimento 
 * @param loja 
 * @param identificadorPontoCaptura 
 * @return const char* retorna sucesso, se o arquivo for criado/atualizado com sucesso, ou erro, caso contrário.
 */
const char *ConfigurarDadosPDV(const char* textoPinpad, const char* versaoAC, const char* nomeEstabelecimento, const char* loja, const char* identificadorPontoCaptura);

/**
 * @brief Inicia Operação
 * 
 * Estabelece uma conexão com V$PagueClient, permitindo que a API realize transações com o Client. 
 * Este método deve ser chamado sempre que a API for carregada ou após a execução do método FinalizarOperacaoTEF.
 * Este método lê o arquivo de configuração para obter os dados do Client e do PDV. conforme documentado nas funções SetClientTCP e ConfigurarDadosPDV. Caso a leitura do arquivo falhe E essas funções ainda não foram chamadas no carregamento atual da biblioteca (execução da aplicação), elas deverão ser chamadas antes de prosseguir com a inicialização.
 * Opcionalmente, pode-se passar um JSON com os dados do PDV que serão usados nas operações subsequentes, sobrescrevendo os valores definidos no método ConfigurarDadosPDV (o arquivo de configuração não é alterado nesse caso).
 * @param dadosCaptura 
 * @return const char* 
 */
const char *IniciarOperacaoTEF(const char* dadosCaptura);


 
 
/**
 * @brief Função que recupera a operação cancelada.
 * 
 * Caso alguma operação falhe antes de ser concluída/confirmada (porque o "PDV caiu", por exemplo), este método pode ser chamado para iniciar uma nova comunicação com V$PagueClient E recuperar os dados da operação interrompida, de forma que ela possa ser confirmada ou cancelada através do método ConfirmarOperacaoTEF.
 * Opcionalmente, pode-se passar um JSON com os dados do PDV, sobrescrevendo os valores definidos no método ConfigurarDadosPDV (o arquivo de configuração não é alterado nesse caso).
 * Esse método foi criado com o intuito de simplificar a recuperação de operações interrompidas e não substitui o serviço administrativo destinado a esse fim (Administração Pendências).
 * 
 * @param dadosCaptura 
 * @return const char* 
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
 * @param dadosCaptura JSON com as informações iniciais do pagamento ou os dados de resposta da coleta. Para detalhes sobre os valores possíveis vide seção IV. Protocolo / payloads.
 * @param novaTransacao Informa à função em qual estado encontra-se o processo de pagamento:
 * * true - indica o início de uma nova operação de pagamento
 * * false - indica uma operação já iniciada, em estado de coleta
 * @return const char*
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
 * @param dadosCaptura JSON com as informações iniciais da operação administrativa ou os dados de resposta da coleta. Para detalhes sobre os valores possíveis vide seção IV. Protocolo / payloads.
 * @param novaTransacao Informa à função em qual estado encontra-se o processo administrativo:
 * * true - indica o início de uma nova operação administrativa
 * * false - indica uma operação já iniciada, em estado de coleta
 * @return const char* 
 */
const char *RealizarAdmTEF(int codigoOperacao, const char* dadosCaptura, bool novaTransacao);

/**
 * @brief Função utilizada para confirmar ou cancelar uma operação recém-realizada.
 * 
 * Deve ser chamada após o término da coleta, quando resultadoTransacao == 0.
 *
 * Essa função exige que alguma operação esteja em andamento.
 * Caso ocorra algum erro durante a operação (queda de conexão, queda de energia ou qualquer outro problema que interrompa a comunicação entre API <--> V$PagueClient), existem duas formas para cancelá-la ou confirmá-la: 
 *   
 * a. Chamar os métodos RecuperarOperacaoTEF + ConfirmarOperacaoTEF 
 *      - Devem ser chamadas imediatamente após a solução do problema 
 * b. Chamar os métodos IniciarOperacaoTEF + RealizarAdmTEF // codigoOperacao = 2 (pendências) 
 *      - Forma recomendada, pode ser chamada a qualquer momento 
 * 
 * @param id Indica o sequencial utilizado na operação a ser confirmada/cancelada.
 * Esse é o sequencial opcionalmente informado no payload no início da operação, que também é retornado ao usuário ao término da coleta.
 * @param acao Indica a ação a ser realizada com a operação em questão:
 * 0 - Cancelar
 * 1 - Confirmar
 *  
 * @return const char*
 */
const char *ConfirmarOperacaoTEF(int id, int acao);

/**
 * @brief Finaliza a conexão com V$PagueClient.
 * 
 * Após essa chamada a API não realizará novas transações com o Client até que uma nova chamada de IniciarOperacaoTEF seja feita.
 * 
 * @param id id - Indica o sequencial a ser utilizado na finalização, devendo ser o valor do sequencial usado na última operação somado com 1.
 * Pode-se passar o valor 1, uma vez que a API resolve com o V$PagueClient o sequencial correto a ser utilizado.
 * @return const char* 
 */
const char *FinalizarOperacaoTEF(int id);

/**
 * @} 
 */