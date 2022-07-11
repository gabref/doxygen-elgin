#ifndef EXPORTAFUNCOES_H
#define EXPORTAFUNCOES_H

#include "e1_bridge.h"

#ifdef __WIN32
#define STDCALL __stdcall
#elif __linux__
#define STDCALL
#endif


/*
    Descricao:      Classe que exporta e documenta as funcoes da biblioteca E1_Bridge
    Autor:          Rodrigo Angelo
    Data:           21/10/2021
*/


E1_Bridge br;
Log log; // Objeto global de log
Imprimir pr;
Personalizacao per;


extern "C"{
    /*!
    * \defgroup g12 E1_Bridge
    * \brief E1 Bridge
    * \brief Este módulo tem como objetivo fornecer comunicação entre ambiente desktop (Windows/Linux/Android) e SmartPos Elgin Pay, \n sendo possível realizar operações de venda utilizando uma biblioteca que faz comunicação com o terminal de pagamento via TCP/IP.\n
    *
    * ###Componentes
    * \b E1_Bridge \b (DLL/SO/AAR) \b - Extensão do aplicativo (DLL/SO/AAR) onde estão exportadas todas as funções para Iniciar uma venda ou operação administrativa no terminal de pagamento SmartPOS.\n
    * \b E1_DigitalHub (antigo E1_bridge) \b (APK) \b - Aplicativo android a ser instalado no SmartPOS para configurações de porta e ativação do serviço para comunicação com Windows.\n
    * Este componente está disponível na loja Elgin. Você pode habilitá-lo na loja Elgin, na seção Token.\n
    * \b e1_bridge_configs \b (JSON) \b - Arquivo de configuração da DLL gerado no workdir caso usuário nao especifique a variável de ambiente \b e1_bridge_configfile.\n
    *
    *
    * ###Por onde começar
    * -# O primeiro passo é habilitar o app para que ele possa ser carregado no seu terminal. Para isso, acesse seu perfil de software house no link abaixo: \n
    * https://elgin.app.br/
    *
    * -# Após acessar, no menu lateral você deve acessar a opção Token e então habilitar o aplicativo conforme imagem abaixo:
    * \image html imagem_token.jpeg
    * -#  No terminal, registrado com o token configurado anteriormente, você poderá realizar o download do aplicativo acessando o menu Elgin Store e clicando sobre o APP, \n vide imagem abaixo: \n
    * \image html loja_elgin.jpg
    * -#  Com o app instalado você poderá começar a realizar as transações.\n
    * • É importante que você verifique as configurações do app antes de começar os testes. \n
    * • Para isso abra o aplicativo e role a página para cima. Um botão deve aparecer no rodapé, pressione-o e digite a senha de acesso às configurações <b>(987654321)</b>
    *  \image html app.jpg
    *
    *
    * \n \n
    * Feito isso você pode começar a implementação. Use como base os links abaixo onde estão detalhadas as funções: \n
    * > \ref g51 \n
    * > \ref g52 \n
    * > \ref g53 \n
    * > \ref g54 \n
    *
    * Convenções usada nas chamadas das funções da biblioteca: \n
    * <b>Windows</b>\n
    * > __stdcall
    * <b>Linux</b>\n
    * > __cdecl\n
    * <b>Android</b>\n
    * > import com.elgin.e1.Pagamento.Brigde.Bridge;
    *
    * ###Arquivo de Configuração
    * \b e1_bridge_configfile - Nome da variável de ambiente para setar o path do arquivo de configuracao. \n
    * Caso o usuário não especifique a variável de ambiente, o arquivo \b e1_bridge_configs.json será criado no workdir.\n
    * Abaixo o exemplo de um arquivo de configuração gerado na pasta workdir.
    *  ``` ini
    * {
    *    "ipTerminal": "192.168.0.1",
    *    "portaStatus": 3001,
    *    "portaTransacao": 3000,
    *    "senha": "",
    *    "senhaHabilitada": false,
    *    "timeoutResposta": -1
    * }
    * ```
    *
    * ###Diagramas de sequência
    * Abaixo estão listados alguns diagramas de sequência para exemplificar os casos de uso mais comuns.\n
    *
    * • Operação de venda débito executada com sucesso:\n
    * \image html success.png
    *
    * • Operação multi-pdv para venda débito com exemplificação de terminal ocupado para o PDV2 ilustrado abaixo:\n
    * \image html busy.png
    *
    * • Operação de venda débito com exemplificação de fluxo de transação com Timeout: \n
    * \image html timeout.png
    *
    *
    * ###Suporte
    * Para realizar a homologação você poderá solicitar ao nosso suporte o envio de um equipamento perfil de desenvolvimento. \n
    * Caso tenha dificuldades você pode contatar nosso suporte através do link abaixo:
    * https://elginbematech.com.br/chamado/
    */

     /*! \defgroup g51 Funções Retorno Direto
     * \ingroup g12
     *
     *//**
     * \ingroup g51
     * Função utilizada para obter configuração do servidor
     * \return string no formato json
     * Exemplo:
     * ~~~.json
     * {"e1_bridge_code":0,"e1_bridge_msg":"192.168.0.1|3000|3001"}
     * ~~~
     */

    ///@cond
    E1_BRIDGESHARED_EXPORT STDCALL
    ///@endcond
    const char* GetServer();

    /*!
     * \ingroup g51
     * Configura servidor onde serão processadas as transações.
     * \param ipTerminal - IP do terminal SmartPOS onde o APP E1_Bridge esta em execução. Exemplo: 192.168.0.10
     * \param portaTransacao - Identificação da porta de comunicação. A porta padrão é 3000\n
     * O valor deve ser entre 0 e 65535, onde 0 será para definir com o valor padrão de 3000.
     * \param portaStatus - Identificação da porta onde serão obtido o status das transações. A porta padrão é 3001\n
     * O valor deve ser entre 0 e 65535, onde 0 será para definir com o valor padrão de 3001.
     * \return string no formato json
     * Exemplo:
     * ~~~.json
     * {"e1_bridge_code":0,"e1_bridge_msg":"Sucesso"}
     * ~~~
     */

    ///@cond
    E1_BRIDGESHARED_EXPORT STDCALL
    ///@endcond
    const char* SetServer(const char* ipTerminal, int portaTransacao, int portaStatus);

    /*!
     * \ingroup g51
     * \brief Configura as senhas que a dll vai enviar para o terminal para as transações
     * \param senha - senha configurada pelo usuário
     * \param habilitada - boolean para saber se a senha vai estar habilitada ou não.\n
     *  Ou seja se a senha será enviada para comunicar ou não.
     * \return string no formato json
     * Exemplo:
     * ~~~.json
     * {"e1_bridge_code":0,"e1_bridge_msg":"Sucesso"}
     * ~~~
     * */

    ///@cond
    E1_BRIDGESHARED_EXPORT STDCALL
    ///@endcond
    const char* SetSenha(const char* senha, bool habilitada);

    /*!
     * \ingroup g51
     * Obtem o timeout definido para as transações em segundos;\n
     * O valor padrão é de 180 segundos (3 minutos);
     * \return string no formato json
     * Exemplo:
     * ~~~.json
     * {"e1_bridge_code":0,"e1_bridge_msg":"180000"}
     * ~~~
     */
    ///@cond
    E1_BRIDGESHARED_EXPORT STDCALL
    ///@endcond
    const char* GetTimeout();

    /*!
     * \ingroup g51
     * Configura um timeout para as funções de transação.\n
     * O valor padrão é de 180 segundos (3 minutos);
     * \param timeout - Valor em segundos a ser definido.
     * \return string no formato json
     * Exemplo:
     * ~~~.json
     * {"e1_bridge_code":0,"e1_bridge_msg":"Sucesso"}
     * ~~~
     */

    ///@cond
    E1_BRIDGESHARED_EXPORT STDCALL
    ///@endcond
    const char* SetTimeout(int timeout);

    /*!
     * \ingroup g51
     * Obtém o status do terminal SmartPOS.\n
	 * Essa função disponibiliza o status de transação e de tela.
	 *
     * \return
	 * String no formato JSON. Exemplo:
     * ~~~.json
     * {"e1_bridge_code":2,"e1_bridge_msg":"Terminal livre|Tela bloqueada"}
     * ~~~
	 * \n
	 * Essa função trabalha com os bits de um inteiro positivo para indicar o status.\n
     * Conforme descrição abaixo:
     * | BIT |   STATUS   |           DESCRIÇÃO             |
     * | :-: | :--------: | :-----------------------------: |
     * |  0  |   LIGADO   | Indica terminal ocupado         |
     * |  ^  | DESLIGADO  | Indica terminal livre           |
     * |  1  |   LIGADO   | Indica tela bloqueada           |
     * |  ^  | DESLIGADO  | Indica tela desbloqueada        |
	 * * Consulte <b>Códigos de erro</b> para mais informações.
     */

    ///@cond
    E1_BRIDGESHARED_EXPORT STDCALL
    ///@endcond
    const char* ConsultarStatus();

    /*!
     * \ingroup g51
     * Retorna ultima transação processada pelo terminal.\n
     * Deve ser utilizada casos de timeout.
     * \param pdv - Identificação do PDV utilizada nas transações.
     * \return string no formato json.\n
     * Consulte a sessão retorno para ter um exemplo de um json de saída e todos os dados.
     */

    ///@cond
    E1_BRIDGESHARED_EXPORT STDCALL
    ///@endcond
    const char* ConsultarUltimaTransacao(const char* pdv);

    /*!
     * \ingroup g51
     * Imprimir Cupom Sat de acordo com a especificação da Sefaz para bobina de 55mm.
     * \note Essa Função pode ser usada para impressão de Danfe do MFe (Ceará)
     *
     * \param xml - Dados do XML retornado da operação de venda do SAT.
     * \return string no formato json
     * Exemplo:
     * ~~~.json
     * {"e1_bridge_code":0,"e1_bridge_msg":"Sucesso"}
     * ~~~
     */

    ///@cond
    E1_BRIDGESHARED_EXPORT STDCALL
    ///@endcond
    const char* ImprimirCupomSat(const char* xml);

    /*!
     * \ingroup g51
     * Imprimir Cupom de cancelamento SAT de acordo com a especificação da Sefaz para bobina de 55mm.
     * \note Essa Função pode ser usada para impressão de Danfe do MFe (Ceará)
     *
     * \param xml - Dados do XML retornado da operação de cancelamento do SAT.
     * \param assQRCode - Assinatura do QRcode retornado na venda cancelada.
     * \return string no formato json
     * Exemplo:
     * ~~~.json
     * {"e1_bridge_code":0,"e1_bridge_msg":"Sucesso"}
     * ~~~
     */

    ///@cond
    E1_BRIDGESHARED_EXPORT STDCALL
    ///@endcond
    const char* ImprimirCupomSatCancelamento(const char* xml, const char* assQRCode);

    /*!
     * \ingroup g51
     * Imprimir Cupom NFCe de acordo com a especificação da Sefaz para bobina de 55mm.
     *
     * \param xml - Dados do XML retornado da operação de venda nfce.\n
     * \param indexcsc - Identificador do CSC (Código de Segurança do Contribuinte no Banco de Dados da SEFAZ).
     * > Deve ser informado sem os “0” (zeros) não significativos. A identificação do CSC corresponde à ordem do\n
     * > CSC no banco de dados da SEFAZ, não confundir com o próprio CSC.
     * \param csc - Código de Segurança do Contribuinte.
     * > Corresponde a um código de segurança alfanumérico (16 a 36 bytes) de conhecimento apenas da Secretaria \n
     * > da Fazenda da Unidade Federada do emitente e do próprio contribuinte. Anteriormente, o código de segurança\n
     * > CSC era chamado de “Token”.
     *
     * \return string no formato json
     * Exemplo:
     * ~~~.json
     * {"e1_bridge_code":0,"e1_bridge_msg":"Sucesso"}
     * ~~~
     */
    ///@cond
    E1_BRIDGESHARED_EXPORT STDCALL
    ///@endcond
    const char* ImprimirCupomNfce(const char* xml, int indexcsc, const char* csc);

    /*!
     * \ingroup g51
     * \brief configura a senha do terminal remotamente.
     * \param senha - senha configurada pelo usuário
     * \param habilitada - booleano que configura se a senha vai ser ativada no servidor\n
     * ou não. Se for true vai ser verificado as senhas que recebem as transações\n
     * e se for false significa que vai ter uma senha que não vai estar em uso, portanto\n
     * qualquer transação que chegar no terminal vai ser aceito direto
     * \return string no formato json
     * Exemplo:
     * ~~~.json
     * {"e1_bridge_code":0,"e1_bridge_msg":"Sucesso"}
     * ~~~
     */

    ///@cond
    E1_BRIDGESHARED_EXPORT STDCALL
    ///@endcond
    const char* SetSenhaServer(const char* senha, bool habilitada);

    /*!
    * \ingroup g51
    * Inicia um operação de venda.\n
    * O tipo da operação será definido pelo operador como débito ou crédito.
    * \param idTransacao - Código númerico gerenciado pelo PDV para identificar uma transação.\n
    * Valor entre 0 e 999999.
    * \param pdv - Código identificador do PDV.\n
    * Valor alfanumérico.
    * \param valorTotal - Valor total da venda em centavos, ex: 100 para venda de R$1,00
    * \return String no formato Json com os dados da transação;
    * Consulte a sessão retorno para ter um exemplo de um json de saída e todos os dados.
    */

    ///@cond
    E1_BRIDGESHARED_EXPORT STDCALL
    ///@endcond
    const char* IniciaVenda(int idTransacao, const char* pdv, const char* valorTotal);

    /*!
     * \ingroup g51
     * Inicia uma venda no débito.\n
     * \param idTransacao - Código númerico gerenciado pelo PDV para identificar uma transação.\n
     * Valor entre 0 e 999999.
     * \param pdv - Código identificador do PDV.\n
     * Valor alfanumérico.
     * \param valorTotal - Valor total da venda em centavos, ex: 100 para venda de R$1,00
     * \return String no formato Json com os dados da transação;
     * Consulte a sessão retorno para ter um exemplo de um json de saída e todos os dados.
     */

    ///@cond
    E1_BRIDGESHARED_EXPORT STDCALL
    ///@endcond
    const char* IniciaVendaDebito(int idTransacao, const char* pdv, const char* valorTotal);

    /*!
     * \ingroup g51
     * Inicia Venda no Crédito.
     * \param idTransacao- Código númerico gerenciado pelo PDV para identificar uma transação.\n
     * Valor entre 0 e 999999.
     * \param pdv - Código identificador do PDV.\n
     * Valor alfanumérico.
     * \param valorTotal - Valor total da venda em centavos, ex: 100 para venda de R$1,00
     * \param tipoFinanciamento - Tipo do financiamento (A vista = 1, parcelado emissor = 2 ou parcelado estabelecimento = 3)
     * \param numParcelas - Quantidade de parcelas para as transações parcelada. Para transação a vista o valor sera desconsiderado.
     * \return String no formato Json com os dados da transação;
    * Consulte a sessão retorno para ter um exemplo de um json de saída e todos os dados.
     */

    ///@cond
    E1_BRIDGESHARED_EXPORT STDCALL
    ///@endcond
    const char* IniciaVendaCredito(int idTransacao, const char* pdv, const char* valorTotal, int tipoFinanciamento, int numParcelas);

    /*!
     * \ingroup g51
     * Inicia um cancelamento de venda.
     * \param idTransacao - Código númerico gerenciado pelo PDV para identificar uma transação.\n
     * Valor entre 0 e 999999.
     * \param pdv - Código identificador do PDV.\n
     * Valor alfanumérico.
     * \param valorTotal - Valor total da venda em centavos, ex: 100 para venda de R$1,00
     * \param dataHora - Data e hora da transação no formato dd/MM/yyyy HH:mm:ss ou dd/MM/yyyy.\n
     * Este valor é retornado no JSON das vendas na chave dataHoraTransacao.
     * \param nsu - nsu da transação que é retornado no JSON das vendas na chave nsuLocal.
     * \return String no formato Json com os dados da transação;
     * Consulte a sessão retorno para ter um exemplo de um json de saída e todos os dados.
     */

    ///@cond
    E1_BRIDGESHARED_EXPORT STDCALL
    ///@endcond
    const char* IniciaCancelamentoVenda(int idTransacao, const char* pdv, const char* valorTotal, const char* dataHora, const char* nsu);

    /*!
     * \ingroup g51
     * Inicia uma operação administrativa.
     * \param idTransacao - Código númerico gerenciado pelo PDV para identificar uma transação.\n
     * Valor entre 0 e 999999.
     * \param pdv - Código identificador do PDV.\n
     * Valor alfanumérico.
     * \param operacao - Informa a operação a ser realizada.
     * Operações disponiveis são:
     * > Operação administrativa = 0\n
     * > Operação de instalação = 1\n
     * > Operação de configuração = 2\n
     * > Operação de manutenção = 3\n
     * > Teste de comunicação = 4\n
     * > Operação de reimpressão de comprovante = 5\n
     * \return String no formato Json com os dados da transação;
     * Consulte a sessão retorno para ter um exemplo de um json de saída e todos os dados.
     */

    ///@cond
    E1_BRIDGESHARED_EXPORT STDCALL
    ///@endcond
    const char* IniciaOperacaoAdministrativa(int idTransacao, const char* pdv, int operacao);

     /*! \defgroup g52 Funções Retorno por Referência
     * \ingroup g12
     *

     *//**
     * \ingroup g52
     * Função utilizada para obter configuração do servidor
     * Exemplo:
     * ~~~.json
     * {"e1_bridge_code":0,"e1_bridge_msg":"192.168.0.1|3000|3001"}
     * ~~~
     */

    ///@cond
    E1_BRIDGESHARED_EXPORT STDCALL
    ///@endcond
    int GetServerRef(char** retorno);

    /*!
     * \ingroup g52
     * Configura servidor onde serão processadas as transações.
     * \param ipTerminal - IP do terminal SmartPOS onde o APP E1_Bridge esta em execução. Exemplo: 192.168.0.10
     * \param portaTransacao - Identificação da porta de comunicação. A porta padrão é 3000\n
     * O valor deve ser entre 0 e 65535, onde 0 será para definir com o valor padrão de 3000.
     * \param portaStatus - Identificação da porta onde serão obtido o status das transações. A porta padrão é 3001\n
     * O valor deve ser entre 0 e 65535, onde 0 será para definir com o valor padrão de 3001.
     * Exemplo:
     * ~~~.json
     * {"e1_bridge_code":0,"e1_bridge_msg":"Sucesso"}
     * ~~~
     */

    ///@cond
    E1_BRIDGESHARED_EXPORT STDCALL
    ///@endcond
    int SetServerRef(const char* ipTerminal, int portaTransacao, int portaStatus, char** retorno);

    /*!
     * \ingroup g52
     * \brief Configura as senhas que a dll vai enviar para o terminal para as transações
     * \param senha - senha configurada pelo usuário
     * \param habilitada - boolean para saber se a senha vai estar habilitada ou não.\n
     *  Ou seja se a senha será enviada para comunicar ou não.
     * \param retorno - parametro passado por referência que ira armazenar os dados\n
     * de retorno ao fim da transação.
     * \return código numérico referente ao processamento da função.\n
     * A função executada com sucesso deve retornar 0.\n
     * Para mais detalhes sobre o retorno consulte a sessão códigos de erro.
     */

    ///@cond
    E1_BRIDGESHARED_EXPORT STDCALL
    ///@endcond
    int SetSenhaRef(const char* senha, bool habilitada, char** retorno);

    /*!
     * \ingroup g52
     * Obtem o timeout definido para as transações em segundos;\n
     * O valor padrão é de 180 segundos (3 minutos);
     * Exemplo:
     * ~~~.json
     * {"e1_bridge_code":0,"e1_bridge_msg":"180000"}
     * ~~~
     */

    ///@cond
    E1_BRIDGESHARED_EXPORT STDCALL
    ///@endcond
    int GetTimeoutRef(char** retorno);

    /*!
     * \ingroup g52
     * Configura um timeout para as funções de transação.\n
     * O valor padrão é de 180 segundos (3 minutos);
     * \param timeout - Valor em segundos a ser definido.
     * Exemplo:
     * ~~~.json
     * {"e1_bridge_code":0,"e1_bridge_msg":"Sucesso"}
     * ~~~
     */

    ///@cond
    E1_BRIDGESHARED_EXPORT STDCALL
    ///@endcond
    int SetTimeoutRef(int timeout, char** retorno);

    /*!
     * \ingroup g52
     * Obtém o status do terminal SmartPOS.\n
	 * Essa função disponibiliza o status de transação e de tela.
	 *
	 * \param retorno - Alocação de memória que receberá o JSON de retorno
	 * da função, conforme descrito em #ConsultarStatus.
	 *
     * \return
	 * Um inteiro positivo para indicar o status, ou um inteiro
	 * negativo em caso de erro.\n
     * Essa função trabalha com os bits conforme descrição abaixo:
     * | BIT |   STATUS   |           DESCRIÇÃO             |
     * | :-: | :--------: | :-----------------------------: |
     * |  0  |   LIGADO   | Indica terminal ocupado         |
     * |  ^  | DESLIGADO  | Indica terminal livre           |
     * |  1  |   LIGADO   | Indica tela bloqueada           |
     * |  ^  | DESLIGADO  | Indica tela desbloqueada        |
	 * * Consulte <b>Códigos de erro</b> para mais informações.
     */

    ///@cond
    E1_BRIDGESHARED_EXPORT STDCALL
    ///@endcond
    int ConsultarStatusRef(char** retorno);

    /*!
     * \ingroup g52
     * Retorna ultima transação processada pelo terminal.\n
     * Deve ser utilizada casos de timeout.
     * \param pdv - Identificação do PDV utilizada nas transações.
     * Consulte a sessão retorno para ter um exemplo de um json de saída e todos os dados.
     */

    ///@cond
    E1_BRIDGESHARED_EXPORT STDCALL
    ///@endcond
    int ConsultarUltimaTransacaoRef(const char* pdv, char** retorno);

    /*!
     * \ingroup g52
     * Imprimir Cupom Sat de acordo com a especificação da Sefaz para bobina de 55mm.
     * \note Essa Função pode ser usada para impressão de Danfe do MFe (Ceará)
     *
     * \param xml - Dados do XML retornado da operação de venda do SAT.
     * \return string no formato json
     * Exemplo:
     * ~~~.json
     * {"e1_bridge_code":0,"e1_bridge_msg":"Sucesso"}
     * ~~~
     */

    ///@cond
    E1_BRIDGESHARED_EXPORT STDCALL
    ///@endcond
    int ImprimirCupomSatRef(const char* xml, char** retorno);

    /*!
     * \ingroup g52
     * Imprimir Cupom de cancelamento SAT de acordo com a especificação da Sefaz para bobina de 55mm.
     * \note Essa Função pode ser usada para impressão de Danfe do MFe (Ceará)
     *
     * \param xml - Dados do XML retornado da operação de cancelamento do SAT.
     * \param assQRCode - Assinatura do QRcode retornado na venda cancelada.
     * \return string no formato json
     * Exemplo:
     * ~~~.json
     * {"e1_bridge_code":0,"e1_bridge_msg":"Sucesso"}
     * ~~~
     */

    ///@cond
    E1_BRIDGESHARED_EXPORT STDCALL
    ///@endcond
    int ImprimirCupomSatCancelamentoRef(const char* xml, const char* assQRCode, char** retorno);

    /*!
     * \ingroup g52
     * Imprimir Cupom NFCe de acordo com a especificação da Sefaz para bobina de 55mm.
     *
     * \param xml - Dados do XML retornado da operação de venda nfce.\n
     * \param indexcsc - Identificador do CSC (Código de Segurança do Contribuinte no Banco de Dados da SEFAZ).
     * > Deve ser informado sem os “0” (zeros) não significativos. A identificação do CSC corresponde à ordem do\n
     * > CSC no banco de dados da SEFAZ, não confundir com o próprio CSC.
     * \param csc - Código de Segurança do Contribuinte.
     * > Corresponde a um código de segurança alfanumérico (16 a 36 bytes) de conhecimento apenas da Secretaria \n
     * > da Fazenda da Unidade Federada do emitente e do próprio contribuinte. Anteriormente, o código de segurança\n
     * > CSC era chamado de “Token”.
     *
     * \return string no formato json
     * Exemplo:
     * ~~~.json
     * {"e1_bridge_code":0,"e1_bridge_msg":"Sucesso"}
     * ~~~
     */

    ///@cond
    E1_BRIDGESHARED_EXPORT STDCALL
    ///@endcond
    int ImprimirCupomNfceRef(const char* xml, int indexcsc, const char* csc, char** retorno);

    /*!
     * \ingroup g52
     * \brief configura a senha do terminal remotamente.
     * \param senha - senha configurada pelo usuário
     * \param habilitada - boolean que configura se a senha vai ser ativada no servidor\n
     * ou não. Se for true vai ser verificado as senhas que recebem as transações\n
     * e se for false significa que vai ter uma senha que não vai estar em uso, portanto\n
     * qualquer transação que chegar no terminal vai ser aceito direto
     * \param retorno - parametro passado por referência que ira armazenar os dados\n
     * de retorno ao fim da transação.
     * \return código numérico referente ao processamento da função.\n
     * A função executada com sucesso deve retornar 0.\n
     * Para mais detalhes sobre o retorno consulte a sessão códigos de erro.
     */

    ///@cond
    E1_BRIDGESHARED_EXPORT STDCALL
    ///@endcond
    int SetSenhaServerRef(const char* senha, bool habilitada, char** retorno);

    /*!
    * \ingroup g52
    * Inicia um operação de venda.\n
    * O tipo da operação será definido pelo operador como débito ou crédito.
    * \param idTransacao - Código númerico gerenciado pelo PDV para identificar uma transação.\n
    * Valor entre 0 e 999999.
    * \param pdv - Código identificador do PDV.\n
    * Valor alfanumérico.
    * \param valorTotal - Valor total da venda em centavos, ex: 100 para venda de R$1,00
    * \return String no formato Json com os dados da transação;
    * Consulte a sessão retorno para ter um exemplo de um json de saída e todos os dados.
    */
    ///@cond
    E1_BRIDGESHARED_EXPORT STDCALL
    ///@endcond
    int IniciaVendaRef(int idTransacao, const char* pdv, const char* valorTotal, char** retorno);

    /*!
     * \ingroup g52
     * Inicia uma venda no débito.\n
     * \param idTransacao - Código númerico gerenciado pelo PDV para identificar uma transação.\n
     * Valor entre 0 e 999999.
     * \param pdv - Código identificador do PDV.\n
     * Valor alfanumérico.
     * \param valorTotal - Valor total da venda em centavos, ex: 100 para venda de R$1,00
     * \return String no formato Json com os dados da transação;
     * Consulte a sessão retorno para ter um exemplo de um json de saída e todos os dados.
     */

    ///@cond
    E1_BRIDGESHARED_EXPORT STDCALL
    ///@endcond
    int IniciaVendaDebitoRef(int idTransacao, const char* pdv, const char* valorTotal, char** retorno);

    /*!
     * \ingroup g52
     * Inicia Venda no Crédito.
     * \param idTransacao- Código númerico gerenciado pelo PDV para identificar uma transação.\n
     * Valor entre 0 e 999999.
     * \param pdv - Código identificador do PDV.\n
     * Valor alfanumérico.
     * \param valorTotal - Valor total da venda em centavos, ex: 100 para venda de R$1,00
     * \param tipoFinanciamento - Tipo do financiamento (A vista = 1, parcelado emissor = 2 ou parcelado estabelecimento = 3)
     * \param numParcelas - Quantidade de parcelas para as transações parcelada. Para transação a vista o valor sera desconsiderado.
     * \return String no formato Json com os dados da transação;
     * Consulte a sessão retorno para ter um exemplo de um json de saída e todos os dados.
     */

    ///@cond
    E1_BRIDGESHARED_EXPORT STDCALL
    ///@endcond
    int IniciaVendaCreditoRef(int idTransacao, const char* pdv, const char* valorTotal, int tipoFinanciamento, int numParcelas, char** retorno);

    /*!
     * \ingroup g52
     * Inicia um cancelamento de venda.
     * \param idTransacao - Código númerico gerenciado pelo PDV para identificar uma transação.\n
     * Valor entre 0 e 999999.
     * \param pdv - Código identificador do PDV.\n
     * Valor alfanumérico.
     * \param valorTotal - Valor total da venda em centavos, ex: 100 para venda de R$1,00
     * \param dataHora - Data e hora da transação no formato dd/MM/yyyy HH:mm:ss ou dd/MM/yyyy.\n
     * Este valor é retornado no JSON das vendas na chave dataHoraTransacao.
     * \param nsu - nsu da transação que é retornado no JSON das vendas na chave nsuLocal.
     * \return String no formato Json com os dados da transação;
     * Consulte a sessão retorno para ter um exemplo de um json de saída e todos os dados.
     */

    ///@cond
    E1_BRIDGESHARED_EXPORT STDCALL
    ///@endcond
    int IniciaCancelamentoVendaRef(int idTransacao, const char* pdv, const char* valorTotal, const char* dataHora, const char* nsu, char** retorno);

    /*!
     * \ingroup g52
     * Inicia uma operação administrativa.
     * \param idTransacao - Código númerico gerenciado pelo PDV para identificar uma transação.\n
     * Valor entre 0 e 999999.
     * \param pdv - Código identificador do PDV.\n
     * Valor alfanumérico.
     * \param operacao - Informa a operação a ser realizada.
     * Operações disponiveis são:
     * > Operação administrativa = 0\n
     * > Operação de instalação = 1\n
     * > Operação de configuração = 2\n
     * > Operação de manutenção = 3\n
     * > Teste de comunicação = 4\n
     * > Operação de reimpressão de comprovante = 5\n
     * \return String no formato Json com os dados da transação;
     * Consulte a sessão retorno para ter um exemplo de um json de saída e todos os dados.
     */

    ///@cond
    E1_BRIDGESHARED_EXPORT STDCALL
    ///@endcond
    int IniciaOperacaoAdministrativaRef(int idTransacao, const char* pdv, int operacao, char** retorno);

     /*! \defgroup g53 Funções Retorno por Arquivo
     * \ingroup g12
     *

     *//**
     * \ingroup g53
     * Obtem configuração do servidor.
     *
     * \note
     * Essa função é uma reescrita da função #GetServer alterando apenas o modo como os dados são retornados.\n
     *
     *
     * \param path - Caminho para o arquivo onde serão gravados os dados de resposta
     * \return Retorno tipo int. Operação realizada com sucesso deve retornar ZERO(0)\n
     * e os dados no formato json estaram disponiveis no arquivo informado por path.\n
     * * Consulte <b>Códigos de erro</b> para mais informações.\n
     */

    ///@cond
    E1_BRIDGESHARED_EXPORT STDCALL
    ///@endcond
    int GetServerArq(const char* path);

    /*!
     * \ingroup g53
     * Configura servidor onde serão processadas as transações.
     *
     * \note
     * Essa função é uma reescrita da função #SetServer alterando apenas o modo como os dados são retornados.\n
     *
     * \param ipTerminal - IP do terminal SmartPOS onde o APP E1_Bridge esta em execução. Exemplo: 192.168.0.10
     * \param portaTransacao - Identificação da porta de comunicação. A porta padrão é 3000\n
     * O valor deve ser entre 0 e 65535, onde 0 será para definir com o valor padrão de 3000.
     * \param portaStatus - Identificação da porta onde serão obtido o status das transações. A porta padrão é 3001\n
     * O valor deve ser entre 0 e 65535, onde 0 será para definir com o valor padrão de 3001.
     * \param path - Caminho para o arquivo onde serão gravados os dados de resposta
     * \return Retorno tipo int. Operação realizada com sucesso deve retornar ZERO(0).\n
     * e os dados no formato json estaram disponiveis no arquivo informado por path.\n
     * * Consulte <b>Códigos de erro</b> para mais informações.\n
     */
    ///@cond
    E1_BRIDGESHARED_EXPORT STDCALL
    ///@endcond
    int SetServerArq(const char* ipTerminal, int portaTransacao, int portaStatus, const char* path);

    /*!
     * \ingroup g53
     * \brief Configura as senhas que a dll vai enviar para o terminal para as transações
     * \param senha - senha configurada pelo usuário
     * \param habilitada - boolean para saber se a senha vai estar habilitada ou não.\n
     *  Ou seja se a senha será enviada para comunicar ou não.
     * \param path - Caminho para o arquivo onde serão gravados os dados de resposta
     * \return código numérico referente ao processamento da função.\n
     * A função executada com sucesso deve retornar 0.\n
     * Para mais detalhes sobre o retorno consulte a sessão códigos de erro.
     * */
    ///@cond
    E1_BRIDGESHARED_EXPORT STDCALL
    ///@endcond
    int SetSenhaArq(const char* senha, bool habilitada, const char* path);

    /*!
     * \ingroup g53
     * Obtem o timeout definido para as transações em segundos;\n
     * O valor padrão é de 180 segundos (3 minutos);
     *
     * \note
     * Essa função é uma reescrita da função #GetTimeout alterando apenas o modo como os dados são retornados.\n
     *
     * \param path - Caminho para o arquivo onde serão gravados os dados de resposta
     * \return Retorno tipo int. Operação realizada com sucesso deve retornar ZERO(0).\n
     * e os dados no formato json estaram disponiveis no arquivo informado por path.\n
     * * Consulte <b>Códigos de erro</b> para mais informações.\n
     */

    ///@cond
    E1_BRIDGESHARED_EXPORT STDCALL
    ///@endcond
    int GetTimeoutArq(const char* path);

    /*!
     * \ingroup g53
     * Configura um timeout para as funções de transação.\n
     * O valor padrão é de 180 segundos (3 minutos);
     *
     * \note
     * Essa função é uma reescrita da função #SetTimeout alterando apenas o modo como os dados são retornados.\n
     *
     * \param timeout - Valor em segundos a ser definido.
     * \param path - Caminho para o arquivo onde serão gravados os dados de resposta
     * \return Retorno tipo int. Operação realizada com sucesso deve retornar ZERO(0).\n
     * e os dados no formato json estaram disponiveis no arquivo informado por path.\n
     * * Consulte <b>Códigos de erro</b> para mais informações.\n
     */

    ///@cond
    E1_BRIDGESHARED_EXPORT STDCALL
    ///@endcond
    int SetTimeoutArq(int timeout, const char* path);

    /*!
     * \ingroup g53
     * Obtém o status do terminal SmartPOS.\n
	 * Essa função disponibiliza o status de transação e de tela.
	 *
	 * \param path - Caminho do arquivo que receberá o JSON de retorno
	 * da função, conforme descrito em #ConsultarStatus.
	 *
     * \return
	 * Um inteiro positivo para indicar o status, ou um inteiro
	 * negativo em caso de erro.\n
     * Essa função trabalha com os bits conforme descrição abaixo:
     * | BIT |   STATUS   |           DESCRIÇÃO             |
     * | :-: | :--------: | :-----------------------------: |
     * |  0  |   LIGADO   | Indica terminal ocupado         |
     * |  ^  | DESLIGADO  | Indica terminal livre           |
     * |  1  |   LIGADO   | Indica tela bloqueada           |
     * |  ^  | DESLIGADO  | Indica tela desbloqueada        |
	 * * Consulte <b>Códigos de erro</b> para mais informações.
     */

    ///@cond
    E1_BRIDGESHARED_EXPORT STDCALL
    ///@endcond
    int ConsultarStatusArq(const char* path);

    /*!
     * \ingroup g53
     * Retorna ultima transação processada pelo terminal.\n
     * Deve ser utilizada casos de timeout.
     *
     * \note
     * Essa função é uma reescrita da função #ConsultarUltimaTransacao alterando apenas o modo como os dados são retornados.\n
     *
     * \param pdv - Identificação do PDV utilizada nas transações.
     * \param path - Caminho para o arquivo onde serão gravados os dados de resposta
     * \return Retorno tipo int. Operação realizada com sucesso deve retornar ZERO(0).\n
     * e os dados no formato json estaram disponiveis no arquivo informado por path.\n
     * Consulte <b>Códigos de erro</b> para mais informações.\n
     */

    ///@cond
    E1_BRIDGESHARED_EXPORT STDCALL
    ///@endcond
    int ConsultarUltimaTransacaoArq(const char* pdv, const char* path);

    /*!
     * \ingroup g53
     * Imprimir Cupom Sat de acordo com a especificação da Sefaz para bobina de 55mm.
     * \note Essa Função pode ser usada para impressão de Danfe do MFe (Ceará)
     *
     * \param xml - Dados do XML retornado da operação de venda do SAT.
     * \param path - Caminho para o arquivo onde serão gravados os dados de resposta.
     * \return Retorno tipo int. Operação realizada com sucesso deve retornar ZERO(0).\n
     * e os dados no formato json estarão disponíveis no arquivo informado por path.\n
     * Consulte <b>Códigos de erro</b> para mais informações.\n
     */

    ///@cond
    E1_BRIDGESHARED_EXPORT STDCALL
    ///@endcond
    int ImprimirCupomSatArq(const char* xml, const char* path);

     /*!
     * \ingroup g53
     * Imprimir Cupom de cancelamento SAT de acordo com a especificação da Sefaz para bobina de 55mm.
     * \note Essa Função pode ser usada para impressão de Danfe do MFe (Ceará)
     *
     * \param xml - Dados do XML retornado da operação de cancelamento do SAT.
     * \param assQRCode - Assinatura do QRcode retornado na venda cancelada.
     * \param path - Caminho para o arquivo onde serão gravados os dados de resposta.
     * \return Retorno tipo int. Operação realizada com sucesso deve retornar ZERO(0).\n
     * e os dados no formato json estarão disponíveis no arquivo informado por path.\n
     * Consulte <b>Códigos de erro</b> para mais informações.\n
     */

    ///@cond
    E1_BRIDGESHARED_EXPORT STDCALL
    ///@endcond
    int ImprimirCupomSatCancelamentoArq(const char* xml, const char* assQRCode, const char* path);

    /*!
     * \ingroup g53
     * Imprimir Cupom NFCe de acordo com a especificação da Sefaz para bobina de 55mm.
     *
     * \param xml - Dados do XML retornado da operação de venda nfce.\n
     * \param indexcsc - Identificador do CSC (Código de Segurança do Contribuinte no Banco de Dados da SEFAZ).
     * > Deve ser informado sem os “0” (zeros) não significativos. A identificação do CSC corresponde à ordem do\n
     * > CSC no banco de dados da SEFAZ, não confundir com o próprio CSC.
     * \param csc - Código de Segurança do Contribuinte.
     * > Corresponde a um código de segurança alfanumérico (16 a 36 bytes) de conhecimento apenas da Secretaria da Fazenda\n
     * > da Fazenda da Unidade Federada do emitente e do próprio contribuinte. Anteriormente, o código de segurança\n
     * > CSC era chamado de “Token”.
     *
     * \return Retorno tipo int. Operação realizada com sucesso deve retornar ZERO(0).\n
     * e os dados no formato json estarão disponíveis no arquivo informado por path.\n
     * Consulte <b>Códigos de erro</b> para mais informações.\n
     */

    ///@cond
    E1_BRIDGESHARED_EXPORT STDCALL
    ///@endcond
    int ImprimirCupomNfceArq(const char* xml, int indexcsc, const char* csc, const char* path);
    /*!
     * \ingroup g53
     * \brief configura a senha do terminal remotamente.
     * \param senha - senha configurada pelo usuário
     * \param habilitada - boolean que configura se a senha vai ser ativada no servidor\n
     * ou não. Se for true vai ser verificado as senhas que recebem as transações\n
     * e se for false significa que vai ter uma senha que não vai estar em uso, portanto\n
     * qualquer transação que chegar no terminal vai ser aceito direto
     * \param path - Caminho para o arquivo onde serão gravados os dados de resposta
     * \return código numérico referente ao processamento da função.\n
     * A função executada com sucesso deve retornar 0.\n
     * Para mais detalhes sobre o retorno consulte a sessão códigos de erro.
     */
    ///@cond
    E1_BRIDGESHARED_EXPORT STDCALL
    ///@endcond

    int SetSenhaServerArq(const char* senha, bool habilitada, const char* path);

    /*!
    * \ingroup g53
    * Inicia um operação de venda.\n
    * O tipo da operação será definido pelo operador como débito ou crédito.
     *
     * \note
     * Essa função é uma reescrita da função #IniciaVenda alterando apenas o modo como os dados são retornados.\n
     *
    * \param idTransacao - Código númerico gerenciado pelo PDV para identificar uma transação.\n
    * Valor entre 0 e 999999.
    * \param pdv - Código identificador do PDV.\n
    * Valor alfanumérico.
    * \param valorTotal - Valor total da venda em centavos, ex: 100 para venda de R$1,00
    * \param path - Caminho para o arquivo onde serão gravados os dados de resposta
    * \return Retorno tipo int. Operação realizada com sucesso deve retornar ZERO(0).\n
    * e os dados no formato json estaram disponiveis no arquivo informado por path.\n
    * * Consulte <b>Códigos de erro</b> para mais informações.\n
    */

    ///@cond
    E1_BRIDGESHARED_EXPORT STDCALL
    ///@endcond
    int IniciaVendaArq(int idTransacao, const char* pdv, const char* valorTotal, const char* path);


    /*!
     * \ingroup g53
     * Inicia uma venda no débito.\n
     *
     * \note
     * Essa função é uma reescrita da função #IniciaVendaDebito alterando apenas o modo como os dados são retornados.\n
     *
     * \param idTransacao - Código númerico gerenciado pelo PDV para identificar uma transação.\n
     * Valor entre 0 e 999999.
     * \param pdv - Código identificador do PDV.\n
     * Valor alfanumérico.
     * \param valorTotal - Valor total da venda em centavos, ex: 100 para venda de R$1,00
     * \param path - Caminho para o arquivo onde serão gravados os dados de resposta
     * \return Retorno tipo int. Operação realizada com sucesso deve retornar ZERO(0).\n
     * e os dados no formato json estaram disponiveis no arquivo informado por path.\n
     * * Consulte <b>Códigos de erro</b> para mais informações.\n
     */

    ///@cond
    E1_BRIDGESHARED_EXPORT STDCALL
    ///@endcond
    int IniciaVendaDebitoArq(int idTransacao, const char* pdv, const char* valorTotal, const char* path);

    /*!
     * \ingroup g53
     * Inicia Venda no Crédito.\n
     *
     * \note
     * Essa função é uma reescrita da função #IniciaVendaCredito alterando apenas o modo como os dados são retornados.\n
     *
     * \param idTransacao- Código númerico gerenciado pelo PDV para identificar uma transação.\n
     * Valor entre 0 e 999999.
     * \param pdv - Código identificador do PDV.\n
     * Valor alfanumérico.
     * \param valorTotal - Valor total da venda em centavos, ex: 100 para venda de R$1,00
     * \param tipoFinanciamento - Tipo do financiamento (A vista = 1, parcelado emissor = 2 ou parcelado estabelecimento = 3)
     * \param numParcelas - Quantidade de parcelas para as transações parcelada. Para transação a vista o valor sera desconsiderado.
     * \param path - Caminho para o arquivo onde serão gravados os dados de resposta
     * \return Retorno tipo int. Operação realizada com sucesso deve retornar ZERO(0).\n
     * e os dados no formato json estaram disponiveis no arquivo informado por path.\n
     * * Consulte <b>Códigos de erro</b> para mais informações.\n
     */

    ///@cond
    E1_BRIDGESHARED_EXPORT STDCALL
    ///@endcond
    int IniciaVendaCreditoArq(int idTransacao, const char* pdv, const char* valorTotal, int tipoFinanciamento, int numParcelas, const char* path);

    /*!
     * \ingroup g53
     * Inicia um cancelamento de venda.\n
     *
     * \note
     * Essa função é uma reescrita da função #IniciaCancelamentoVenda alterando apenas o modo como os dados são retornados.\n
     *
     * \param idTransacao - Código númerico gerenciado pelo PDV para identificar uma transação.\n
     * Valor entre 0 e 999999.
     * \param pdv - Código identificador do PDV.\n
     * Valor alfanumérico.
     * \param valorTotal - Valor total da venda em centavos, ex: 100 para venda de R$1,00
     * \param dataHora - Data e hora da transação no formato dd/MM/yyyy HH:mm:ss ou dd/MM/yyyy.\n
     * Este valor é retornado no JSON das vendas na chave dataHoraTransacao.
     * \param nsu - nsu da transação que é retornado no JSON das vendas na chave nsuLocal.
     * \param path - Caminho para o arquivo onde serão gravados os dados de resposta
     * \return Retorno tipo int. Operação realizada com sucesso deve retornar ZERO(0).\n
     * e os dados no formato json estaram disponiveis no arquivo informado por path.\n
     * * Consulte <b>Códigos de erro</b> para mais informações.\n
     */

    ///@cond
    E1_BRIDGESHARED_EXPORT STDCALL
    ///@endcond
    int IniciaCancelamentoVendaArq(int idTransacao, const char* pdv, const char* valorTotal, const char* dataHora, const char* nsu, const char* path);

    /*!
     * \ingroup g53
     * Inicia uma operação administrativa.\n
     *
     * \note
     * Essa função é uma reescrita da função #IniciaOperacaoAdministrativa alterando apenas o modo como os dados são retornados.\n
     *
     * \param idTransacao - Código númerico gerenciado pelo PDV para identificar uma transação.\n
     * Valor entre 0 e 999999.
     * \param pdv - Código identificador do PDV.\n
     * Valor alfanumérico.
     * \param operacao - Informa a operação a ser realizada.
     * Operações disponiveis são:
     * > Operação administrativa = 0\n
     * > Operação de instalação = 1\n
     * > Operação de configuração = 2\n
     * > Operação de manutenção = 3\n
     * > Teste de comunicação = 4\n
     * > Operação de reimpressão de comprovante = 5\n
     * \param path - Caminho para o arquivo onde serão gravados os dados de resposta
     * \return Retorno tipo int. Operação realizada com sucesso deve retornar ZERO(0).\n
     * e os dados no formato json estaram disponiveis no arquivo informado por path.\n
     * * Consulte <b>Códigos de erro</b> para mais informações.\n
     */

    ///@cond
    E1_BRIDGESHARED_EXPORT STDCALL
    ///@endcond
    int IniciaOperacaoAdministrativaArq(int idTransacao, const char* pdv, int operacao, const char* path);


    //FUNÇÕES DE IMPRESSÃO DE TEXTO -----------------------------------------------------------------------------------------------------------------
    /*! \defgroup g54 Funções de Impressão
    * \ingroup g12
    * As funções descritas nessa sessão tem como objetivo disponibilizar um meio de uso da impressora do POS.\n
    * Abaixo é detalhado o fluxo de uso das funções para realizar uma impressão simples.\n
    *
    * \image html fluxograma_impressao_bridge.jpg
    *
    */
    
    /*!
    * \ingroup g54
    * Iniciar a configuração do layout a ser impresso.
    * \return Retorno tipo int.\n
    * Retornos:\n
    * 0 - Operação realizada com sucesso.\n
    * 1 - Erro.\n
    */
    ///@cond
    E1_BRIDGESHARED_EXPORT STDCALL
    ///@endcond
    int IniciarConfigLayout();


    /*!
    * \ingroup g54
    *
    * Adiciona um texto ao arquivo base de acordo com as características informadas nos parâmetros.
    *
    * \param info    - Informação e/ou texto a ser adicionado ao arquivo.\n
    * \param posição - Parâmetro tipo numérico que define a posição do texto a ser impresso.\n
    * > 0 - Esquerda\n
    * > 1 - Centro\n
    * > 2 - Direita\n
    * \param estilo - Parâmetro numérico que altera o estilo do texto impresso.\n
    * > 0  - Normal\n
    * > 1  - Condensado\n
    * > 2  - Expandido\n
    * > 4  - Dupla altura\n
    * > 8  - Sublinhado\n
    * > 16 - Modo reverso\n
    * > 32 - Negrito\n

    * Obs. Para habilitar mais de um estilo deve-se realizar a soma dos valores\n
    * \return Retorno tipo int.\n
    * Retornos:\n
    * 0 - Operação realizada com sucesso.\n
    * 1 - Erro.\n
    * 2 - Arquivo não encontrado.\n
    * 3 - Erro de parametro (incorreto).\n
    */
    ///@cond
    E1_BRIDGESHARED_EXPORT STDCALL
    ///@endcond
    int AdicionarTexto(const char* info, int posicao, int estilo);


    /*!
    * \ingroup g54
    *
    * Adiciona um texto ou o conteúdo de determinado arquivo ao arquivo base, de acordo com as características informadas nos parâmetros.
    *
    * \param info - Texto  : Informação e/ou texto a ser adicionado ao arquivo.\n
    * ou \n
    * Arquivo: "path=C:\\LocalDoArquivo/Arquivo.txt". O termo "path" sinaliza que será utilizado o conteúdo um arquivo (TXT) como parâmetro. \n
    * Consulte \ref g55 para mais detalhes
    * \return Retorno tipo int.\n
    * Retornos:\n
    * 0 - Operação realizada com sucesso.\n
    * 1 - Erro.\n
    * 2 - Arquivo não encontrado.\n
    * 3 - Erro de parametro (incorreto).\n
    */
    ///@cond
    E1_BRIDGESHARED_EXPORT STDCALL
    ///@endcond
    int AdicionarHTML(const char* info);


    /*!
    * \ingroup g54
    *
    * Adicionar "N" quebras de linha no arquivo base.
    *
    * \param quant - Quantidade de quebras de linha a serem adicionadas ao arquivo base (inteiro).\n
    * \return Retorno tipo int.\n
    * Retornos:\n
    * 0 - Operação realizada com sucesso.\n
    * 1 - Erro.\n
    * 2 - Arquivo não encontrado.\n
    * 3 - Erro de parametro (incorreto).\n
    */
    ///@cond
    E1_BRIDGESHARED_EXPORT STDCALL
    ///@endcond
    int AdicionarQuebraDeLinha(int quant);


    /*!
    *//**
    * \ingroup g54
    * Limpar arquivo base de layout.
    * \return Retorno tipo int.\n
    * Retornos:\n
    * 0 - Operação realizada com sucesso.\n
    * 1 - Erro.\n
    */
    ///@cond
    E1_BRIDGESHARED_EXPORT STDCALL
    ///@endcond
    int LimparLayout();


    /*!
    *\ingroup g54
    *
    *Realizar a impressão de código de barras.
    *
    *\param tipo - Define o modelo do código de barras a ser impresso.\n
    *Valor	|Modelo			|Quantidade de dados		|Caracteres					                |Regras
    *-------|---------------|---------------------------|-------------------------------------------|-----------------------------------
    *0		|UPC-A			|11 ou 12					|0 até 9						            |-
    *1		|UPC-E			|6, 7, 8, 11 ou 12			|0 até 9						            |Quantidade = 6 se 1º != 0
    *2		|JAN13 / EAN 13	|12 ou 13					|0 até 9						            |-
    *3		|JAN8 / EAN 8	|7 ou 8						|0 até 9						            |-
    *4		|CODE 39		|1 até 255					|0 até 9, A até Z\nSP, $, %, *, +, -, \, .	|-												
    *5		|ITF			|2 até 255 (números pares)	|0 até 9						            |-
    *6		|CODE BAR		|1 até 255					|0 até 9, A até D, a até d\n$, +, -, ., /, :|1º e nº devem ser A até D ou a até d
    *7		|CODE 93		|1 até 255					|00H até 7FH					            |-
    *8		|CODE 128		|2 até 255					|00H até 7FH					            |1º = {, 2º = A, B ou C
    *
    *\param dados   - Informação que compõe o código.\n
    *\param altura  - Altura do código de barras. Valor de 1 até 255.\n
    *\param largura - Define a largura do código de barras. Valor de 1 até 6. Se valor definido ultrapassar área de impressão o código não será impresso.\n
    *\param HRI     - Define a posição de impressão do conteúdo do código de barras.\n
    *1 - Acima do código\n
    *2 - Abaixo do código\n
    *3 - Ambos\n
    *4 - Não impresso\n
    *\return Retorno tipo int.\n
    *Retornos:\n
    *0 - Operação realizada com sucesso.\n
    *1 - Erro.\n
    *2 - Arquivo não encontrado.\n
    *3 - Erro de parametro (incorreto).\n
    */
    ///@cond
    E1_BRIDGESHARED_EXPORT STDCALL
    ///@endcond
    int AdicionarCodigoBarras(int tipo, const char* dados, int altura, int largura, int HRI);


    /*!
    *\ingroup g54
    *
    *Essa função imprime o código QRCode com possibilidade de variação de tamanho e nível de correção.
    *
    *\param dados             - Conjunto de informações que irão compor o QRCode.\n
    *\param tamanho           - Tamanho do QRCode. Valor de 1 até 6.\n
    *\param nivel de correção - Define o nível de correção a ser configurado para o QRCode.\n
    *1 - 7%\n
    *2 - 15%\n
    *3 - 25%\n
    *4 - 30%\n
    *\return Retorno tipo int.\n
    *Retornos:\n
    *0 - Operação realizada com sucesso.\n
    *1 - Erro.\n
    *2 - Arquivo não encontrado.\n
    *3 - Erro de parametro (incorreto).\n
    */
    ///@cond
    E1_BRIDGESHARED_EXPORT STDCALL
    ///@endcond
    int AdicionarQRCode(const char* dados, int tamanho, int nivelCorrecao);


    /*!
    *\ingroup g54
    *
    *Essa função imprime uma imagem de acordo com o path informado.
    *
    *\param path - Indica o "caminho" do arquivo de imagem a ser utilizado.\n
    *\return Retorno tipo int.\n
    *Retornos:\n
    *0 - Operação realizada com sucesso.\n
    *1 - Erro.\n
    *2 - Arquivo não encontrado.\n
    *3 - Erro de parametro (incorreto).\n
    */
    ///@cond
    E1_BRIDGESHARED_EXPORT STDCALL
    ///@endcond
    int AdicionarImagem(const char* path);


    /*!
    *\ingroup g54
    *
    *Essa função imprime o layout configurado.
    *
    *\return Retorno tipo const char*.\n
    *Exemplo de retorno para impressão realizada com sucesso
    * \code{.json}
    * {
    *   "e1_brigde_code": 0,
    *   "e1_brigde_msg": "Impressão E-HTML realizada com sucesso"
    * }
    * \endcode    
    */
    ///@cond
    E1_BRIDGESHARED_EXPORT STDCALL
    ///@endcond
    const char* ImprimirLayout();


    /*!
    *\ingroup g54
    *
    *Essa função reimprime o layout configurado anteriormente.
    *
    *\return Retorno tipo const char*.\n
    *Exemplo de retorno para impressão realizada com sucesso
    * \code{.json}
    * {
    *   "e1_brigde_code": 0,
    *   "e1_brigde_msg": "Impressão E-HTML realizada com sucesso"
    * }
    * \endcode    
    */
    ///@cond
    E1_BRIDGESHARED_EXPORT STDCALL
    ///@endcond
    const char* ReimprimirLayout();


    /*!
    * \ingroup g54
    *
    * Essa função verifica o status de papel na impressora do SmartPOS
    *
    * \return Retorno tipo const char* no formato JSON com o valor do status, vide exemplo abaixo:\n
    * Exemplo de retorno para papel ok
    * \code{.json}
    * {
    *   "e1_brigde_code": 5,
    *   "e1_brigde_msg": "Status obtido com sucesso"
    * }
    * \endcode    
    * Possiveis valores para a propriedade e1_brigde_code:.\n
    *  5- Indica que o papel está presente e não está próximo do fim.\n
    *  6- Indica papel próximo do fim.\n
    *  7- Indica papel ausente.\n
    */
    ///@cond
    E1_BRIDGESHARED_EXPORT STDCALL
    ///@endcond
    const char* StatusImpressora();

    //FUNÇÕES DE PERSONALIZAÇÃO ---------------------------------------------------------------------------------------------------------------------
    /*! \defgroup g56 Funções de Personalização
    * \ingroup g12
    * As funções descritas nessa sessão tem como objetivo disponibilizar um meio de personalização através do client.\n
    */

    /*!
    * \ingroup g56
    * Personalizar a cor do elemento botão.
    *
    *\param corBotao - Cor no formato hexadecimal. Ex: "#FFA500".\n
    *\return Retorno tipo const char* no formato JSON com o valor do status da operação.\n
    * Exemplo para operação realizada com sucesso
    *\code{.json}
    *{
    *  "e1_bridge_code": 0,
    *  "e1_bridge_msg": "Sucesso"
    *}
    *\endcode
    */
    ///@cond
    E1_BRIDGESHARED_EXPORT STDCALL
    ///@endcond
    const char* PersonalizarCorBotao(const char* corBotao);


    /*!
    *\ingroup g56
    * Personalizar a cor do elemento fonte.
    *
    *\param corFonte - Cor no formato hexadecimal. Ex: "#FFA500".\n
    *\return Retorno tipo const char* no formato JSON com o valor do status da operação.\n
    * Exemplo para operação realizada com sucesso
    *\code{.json}
    *{
    *  "e1_bridge_code": 0,
    *  "e1_bridge_msg": "Sucesso"
    *}
    *\endcode
    */
    ///@cond
    E1_BRIDGESHARED_EXPORT STDCALL
    ///@endcond
    const char* PersonalizarCorFonte(const char* corFonte);

    /*!
    * \ingroup g56
    * Personalizar a imagem de Logo.
    *
    *\param path - Indica o "caminho" do arquivo de imagem a ser utilizado.\n
    *\return Retorno tipo const char* no formato JSON com o valor do status da operação.\n
    * Exemplo para operação realizada com sucesso
    *\code{.json}
    *{
    *  "e1_bridge_code": 0,
    *  "e1_bridge_msg": "Sucesso"
    *}
    *\endcode
    */
    ///@cond
    E1_BRIDGESHARED_EXPORT STDCALL
    ///@endcond
    const char* PersonalizarLogo(const char* path);


    /*!
    * \ingroup g56
    * Personalizar a cor de background da tela.
    *
    *\param corBackground - Cor no formato hexadecimal. Ex: "#FFA500".\n
    *\return Retorno tipo const char* no formato JSON com o valor do status da operação.\n
    * Exemplo para operação realizada com sucesso
    *\code{.json}
    *{
    *  "e1_bridge_code": 0,
    *  "e1_bridge_msg": "Sucesso"
    *}
    *\endcode
    */
    ///@cond
    E1_BRIDGESHARED_EXPORT STDCALL
    ///@endcond
    const char* PersonalizarCorBackground(const char* corBackground);


    /*!
    * \ingroup g56
    * Personalizar estilo da fonte conforme tabela.
    *
    *\param fonte - Indica o número da fonte desejada, de acordo com a relação apresentada na tabela.\n
    *\return Retorno tipo const char* no formato JSON com o valor do status da operação.\n
    * Exemplo para operação realizada com sucesso
    *\code{.json}
    *{
    *  "e1_bridge_code": 0,
    *  "e1_bridge_msg": "Sucesso"
    *}
    *\endcode
    */
    ///@cond
    E1_BRIDGESHARED_EXPORT STDCALL
    ///@endcond
    const char* PersonalizarFonte(int fonte);


    //FUNÇÕES DE PERSONALIZAÇÃO - PAGAMENTO ---------------------------------------------------------------------------------------------------------
    /*!
    * \ingroup g56
    * Personalizar o icone do toolbar.
    *
    *\param path - Indica o "caminho" do arquivo de imagem a ser utilizado.\n
    *\return Retorno tipo const char* no formato JSON com o valor do status da operação.\n
    * Exemplo para operação realizada com sucesso
    *\code{.json}
    *{
    *  "e1_bridge_code": 0,
    *  "e1_bridge_msg": "Sucesso"
    *}
    *\endcode
    */
    ///@cond
    E1_BRIDGESHARED_EXPORT STDCALL
    ///@endcond
    const char* PersonalizarPagamentoIconeToolbar(const char* path);


    /*!
    * \ingroup g56
    * Personalizar estilo da fonte conforme tabela.
    *
    *\param fonte - Indica o número da fonte desejada, de acordo com a relação apresentada na tabela.\n
    *\return Retorno tipo const char* no formato JSON com o valor do status da operação.\n
    * Exemplo para operação realizada com sucesso
    *\code{.json}
    *{
    *  "e1_bridge_code": 0,
    *  "e1_bridge_msg": "Sucesso"
    *}
    *\endcode
    */
    ///@cond
    E1_BRIDGESHARED_EXPORT STDCALL
    ///@endcond
    const char* PersonalizarPagamentoFonte(int fonte);


    /*!
    * \ingroup g56
    * Personalizar a cor da fonte.
    *
    *\param corBackground - Cor no formato hexadecimal. Ex: "#FFA500".\n
    *\return Retorno tipo const char* no formato JSON com o valor do status da operação.\n
    * Exemplo para operação realizada com sucesso
    *\code{.json}
    *{
    *  "e1_bridge_code": 0,
    *  "e1_bridge_msg": "Sucesso"
    *}
    *\endcode
    */
    ///@cond
    E1_BRIDGESHARED_EXPORT STDCALL
    ///@endcond
    const char* PersonalizarPagamentoCorFonte(const char* corFonte);


    /*!
    * \ingroup g56
    * Personalizar a cor da fonte do teclado.
    *
    *\param corBackground - Cor no formato hexadecimal. Ex: "#FFA500".\n
    *\return Retorno tipo const char* no formato JSON com o valor do status da operação.\n
    * Exemplo para operação realizada com sucesso
    *\code{.json}
    *{
    *  "e1_bridge_code": 0,
    *  "e1_bridge_msg": "Sucesso"
    *}
    *\endcode
    */
    ///@cond
    E1_BRIDGESHARED_EXPORT STDCALL
    ///@endcond
    const char* PersonalizarPagamentoCorFonteTeclado(const char* corFonteTeclado);


    /*!
    * \ingroup g56
    * Personalizar a cor de fundo da toolbar.
    *
    *\param corBackground - Cor no formato hexadecimal. Ex: "#FFA500".\n
    *\return Retorno tipo const char* no formato JSON com o valor do status da operação.\n
    * Exemplo para operação realizada com sucesso
    *\code{.json}
    *{
    *  "e1_bridge_code": 0,
    *  "e1_bridge_msg": "Sucesso"
    *}
    *\endcode
    */
    ///@cond
    E1_BRIDGESHARED_EXPORT STDCALL
    ///@endcond
    const char* PersonalizarPagamentoCorFundoToolbar(const char* corFundoToolbar);


    /*!
    * \ingroup g56
    * Personalizar a cor do fundo de tela.
    *
    *\param corBackground - Cor no formato hexadecimal. Ex: "#FFA500".\n
    *\return Retorno tipo const char* no formato JSON com o valor do status da operação.\n
    * Exemplo para operação realizada com sucesso
    *\code{.json}
    *{
    *  "e1_bridge_code": 0,
    *  "e1_bridge_msg": "Sucesso"
    *}
    *\endcode
    */
    ///@cond
    E1_BRIDGESHARED_EXPORT STDCALL
    ///@endcond
    const char* PersonalizarPagamentoCorFundoTela(const char* corFundoTela);


    /*!
    * \ingroup g56
    * Personalizar a cor da tecla liberada no teclado.
    *
    *\param corBackground - Cor no formato hexadecimal. Ex: "#FFA500".\n
    *\return Retorno tipo const char* no formato JSON com o valor do status da operação.\n
    * Exemplo para operação realizada com sucesso
    *\code{.json}
    *{
    *  "e1_bridge_code": 0,
    *  "e1_bridge_msg": "Sucesso"
    *}
    *\endcode
    */
    ///@cond
    E1_BRIDGESHARED_EXPORT STDCALL
    ///@endcond
    const char* PersonalizarPagamentoCorTeclaLiberadaTeclado(const char* corTeclaLiberadaTeclado);


    /*!
    * \ingroup g56
    * Personalizar a cor de fundo do teclado.
    *
    *\param corBackground - Cor no formato hexadecimal. Ex: "#FFA500".\n
    *\return Retorno tipo const char* no formato JSON com o valor do status da operação.\n
    * Exemplo para operação realizada com sucesso
    *\code{.json}
    *{
    *  "e1_bridge_code": 0,
    *  "e1_bridge_msg": "Sucesso"
    *}
    *\endcode
    */
    ///@cond
    E1_BRIDGESHARED_EXPORT STDCALL
    ///@endcond
    const char* PersonalizarPagamentoCorFundoTeclado(const char* corFundoTeclado);


    /*!
    * \ingroup g56
    * Personalizar a cor do texto da caixa de edição.
    *
    *\param corBackground - Cor no formato hexadecimal. Ex: "#FFA500".\n
    *\return Retorno tipo const char* no formato JSON com o valor do status da operação.\n
    * Exemplo para operação realizada com sucesso
    *\code{.json}
    *{
    *  "e1_bridge_code": 0,
    *  "e1_bridge_msg": "Sucesso"
    *}
    *\endcode
    */
    ///@cond
    E1_BRIDGESHARED_EXPORT STDCALL
    ///@endcond
    const char* PersonalizarPagamentoCorTextoCaixaEdicao(const char* corTextoCaixaEdicao);


    /*!
    * \ingroup g56
    * Personalizar a cor do separador do menu.
    *
    *\param corBackground - Cor no formato hexadecimal. Ex: "#FFA500".\n
    *\return Retorno tipo const char* no formato JSON com o valor do status da operação.\n
    * Exemplo para operação realizada com sucesso
    *\code{.json}
    *{
    *  "e1_bridge_code": 0,
    *  "e1_bridge_msg": "Sucesso"
    *}
    *\endcode
    */
    ///@cond
    E1_BRIDGESHARED_EXPORT STDCALL
    ///@endcond
    const char* PersonalizarPagamentoCorSeparadorMenu(const char* corSeparadorMenu);


    //FUNÇÕES DE PERSONALIZAÇÃO - COMPROVANTE -------------------------------------------------------------------------------------------------------
    /*!
    * \ingroup g56
    * Personalizar a imagem do comprovante.
    *
    *\param path - Indica o "caminho" do arquivo de imagem a ser utilizado.\n
    *\return Retorno tipo const char* no formato JSON com o valor do status da operação.\n
    * Exemplo para operação realizada com sucesso
    *\code{.json}
    *{
    *  "e1_bridge_code": 0,
    *  "e1_bridge_msg": "Sucesso"
    *}
    *\endcode
    */
    ///@cond
    E1_BRIDGESHARED_EXPORT STDCALL
    ///@endcond
    const char* PersonalizarComprovante(const char* path);
}


#endif // EXPORTAFUNCOES_H


/** \defgroup g55 TAGs de impressão
* \ingroup g12
* ##ABAIXO ESTÃO DETALHADAS AS TAGS SUPORTADAS NA FUNÇÃO IMPRIME HTML
*
* ###TAGs - Texto
* Texto:
* \code{.xml} <texto> </texto> \endcode
*  
* Alinhamento centro: 
* \code{.xml} <ce> </ce> \endcode
*  
* Alinhamento à direita: 
* \code{.xml} <ad> </ad> \endcode
*  
* Alinhamento à esquerda: 
* \code{.xml} <ae> </ae> \endcode
*  
* Texto condensado: 
* \code{.xml} <c> </c> \endcode
*  
* Texto expandido: 
* \code{.xml} <e> </e> \endcode
*  
* Texto dupla altura: 
* \code{.xml} <da> </da> \endcode
*  
* Texto sublinhado: 
* \code{.xml} <s> </s> \endcode
*  
* Texto modo reverso: 
* \code{.xml} <r> </r> \endcode
*  
* Texto negrito: 
* \code{.xml} <b> </b> \endcode
*  
* Exemplos
* \code{.xml} 
* <ehtml>
*
*   <texto><b><da><e><ae>ESQUERDA</ae></e></da></b></texto>
* 
*   <texto><b><da><e><ce>CENTRO</ce></e></da></b></texto>
* 
*   <texto><b><da><e><ad>DIREITA</ad></e></da></b></texto>
* 
*   <texto><ce>NORMAL</ce></texto>
* 
*   <texto><c><ce>CONDENSADO</ce></c></texto>
* 
*   <texto><e><ce>EXPANDIDO</ce></e></texto>
* 
*   <texto><da><ce>DUPLA ALTURA</ce></da></texto>
* 
*   <texto><s><ce>SUBLINHADO</ce></s></texto>
* 
*   <texto><r><ce>MODO REVERSO</ce></r></texto>
* 
*   <texto><b><ce>NEGRITO</ce></b></texto>
*
* </ehtml>
* \endcode
* <hr>
* ###TAG - Código de barras
* Código de barras:
*  
* Tipos de código de barras
*  
* UPCA: \n
* \code{.xml} <upc-a> </upc-a> \endcode
* UPCE: \n
* \code{.xml} <upc-e> </upc-e> \endcode
* EAN13: \n
* \code{.xml} <ean13> </ean13> \endcode
* EAN8: \n
* \code{.xml} <ean8> </ean8> \endcode
* CODE39: \n
* \code{.xml} <code39> </code39> \endcode
* CODE93: \n
* \code{.xml} <code93> </code93> \endcode
* CODE 128: \n
* \code{.xml} <code128> </code128> \endcode
* ITF: \n
* \code{.xml} <itf> </itf> \endcode
*  
* Texto do código de barras:
* \code{.xml} <txt> </txt> \endcode
*  
* Altura do código de barras:
* \code{.xml} <hx> </hx> \endcode
*  
* Largura do código de barras:
* \code{.xml} <wx> </wx> \endcode
*  
* HRI do código de barras:
* \code{.xml} <hri> </hri> \endcode
*  
* Exemplo
* \code{.xml} 
* </ehtml>
*    <ean13>
*        <txt>012345678901</txt>
*        <hx>30</hx>
*        <wx>5</wx>
*        <hri>2</hri>
*    </ean13>
* </ehtml>
* \endcode
* <hr>
* 
* ###TAG - QR Code
* QR Code:
* \code{.xml} <qrcode> </qrcode> \endcode
*  
* Texto QR Code:
* \code{.xml} <txt> </txt> \endcode
*  
* Tamanho QR Code:
* \code{.xml} <lmodulo> </lmodulo> \endcode
*  
* Nivel de correção QR Code:
* \code{.xml} <correcao> </correcao> \endcode
*  
* Exemplo
* \code{.xml}
* <ehtml>
*     <qrcode>
*         <txt>TEXTO QR CODE</txt>
*         <lmodulo>3</lmodulo>
*         <correcao>2</correcao>
*     </qrcode>
* <\ehtml>
* \endcode
* <hr>
*  
* ###TAG - Imagem
* Imagem:
* \code{.xml} <bitmap> </bitmap> \endcode
*  
* Exemplo
* \code{.xml} <bitmap>$IMAGEM$</bitmap> \endcode
*  
* \note O respectivo arquivo de imagem deve ser lido e transformado para a Base64. Esse conteúdo deve ser carregado/informado no campo $IMAGEM$. 
* 
* 
*/
