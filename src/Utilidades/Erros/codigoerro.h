#ifndef CODIGOERRO_H
#define CODIGOERRO_H

/*
Descrição:      Arquivo de cabeçalho com as definições de possiveis erros para a biblioteca de comunicação com as impressoras Elgin
Autor:          Bruno Cruz
Data:           10/01/2018
*/

/*! \defgroup g1 Códigos de erro.
 *
 * \brief Possíveis erros.
 *
 * Descreve todos os possíveis erros que podem ser encontrados no ambiente de desenvolvimento.
 * Todos os valores de retornos para as funções que não foram bem executadas.
 */

/** \ingroup g1
 * @brief SUCESSO - <b>(0)</b>Retorno para função bem sucedida.
 */
const int SUCESSO = 0;
const int TIMEOUT = -9998;

static const char* __SUCESSO = "SUCESSO";

/** \ingroup g1
 * @brief ERRO_DESCONHECIDO - <b>(-9999)</b>Retorno inesperado.
 */
const int ERRO_DESCONHECIDO = -9999;

static const char* __ERRO_AO_CARREGAR_DLL_SAT = "ERRO AO CARREGAR DLL SAT";
static const char* __ERRO_AO_CARREGAR_DLL_IMPRESSORA = "ERRO AO CARREGAR DLL IMPRESSORA";
static const char* __ERRO_AO_VALIDAR_DLL_SAL = "DLL SAT INVALIDA.";
static const char* __ERRO_CANCELAR_VENDA_SAT = "XML RECEBIDO NAO CONTEM CHAVE, CNPJSH E/OU SIGN_AC";


/** \ingroup g1.
 * @brief GER_Erro_Conexao enum -1 à -10
 *
 * A faixa de -1 à -10 descreve os possíveis erros de conexão.
 */
enum GER_Erro_Conexao{

    TIPO_INVALIDO       = -2,/**< <b>(-2)</b> Tipo informado não corresponde a USB, RS232 ou TCP/IP. */
    MODELO_INVALIDO     = -3,/**< <b>(-3)</b> Modelo de impressora informado é invalido ou não é suportado nessa versão. */
    PORTA_FECHADA       = -4,/**< <b>(-4)</b> Porta de comunicação está fechada. */
    CONEXAO_NEGADA      = -5,/**< <b>(-5)</b> Impressora não é uma impressora ELGIN. */
    CONEXAO_ATIVA       = -6/**< <b>(-6)</b> Conexão já está em aberto. */
};

/** \ingroup g1
 * @brief GER_Erro_Conexao_Serial enum -11 à -20
 *
 * A faixa de -11 à -20 define os possíveis erros de conexão RS232.
 */
enum GER_Erro_Conexao_Serial{
    BAUDRATE_INVALIDO                    = -11, /**< <b>(-11)</b> O baudrate informado é invalido para conexão. */
    DISPOSITIVO_NAO_EXISTE               = -12, /**< <b>(-12)</b> A dispositivo não existe para conexão. */
    PERMISSAO_NEGADA                     = -13, /**< <b>(-13)</b> Dispositivo já está aberto ou usuário não tem permissão. */
    ERRO_SERIAL_DESCONHECIDO             = -14, /**< <b>(-14)</b> Erro desconhecido na conexão serial. */
    DISPOSITIVO_JA_ESTA_ABERTO           = -15, /**< <b>(-15)</b> Tentativa de abrir um dispositivo já aberto. */
    RECURSO_INDISPONIVEL                 = -16, /**< <b>(-16)</b> Tentativa de acessar um recurso indisponível (removido do sistema, por exemplo). */
    OPERACAO_NAO_SUPORTADA               = -17, /**< <b>(-17)</b> Operação não suportada pelo sistema operacional em uso. */
    SERIAL_TIMEOUT                       = -18, /**< <b>(-18)</b> Erro de timeout. */
    DISPOSITIVO_REMOVIDO_INESPERADAMENTE = -19 /**< <b>(-19)</b> Ocorreu um erro de E/S quando um recurso se tornou indisponível, por exemplo, quando o dispositivo é removido inesperadamente do sistema. */
};

/** \ingroup g1
 * @brief GER_Erro_Conexao_USB enum -21 à -30
 *
 * A faixa de -21 à -30 define os possíveis erros de conexão USB
 */
enum GER_Erro_Conexao_USB{
    DISPOSITIVO_NAO_ENCONTRADO  = -21, /**< <b>(-21)</b> O dispositivo não foi encontrado. */
    ERRO_DE_ABERTURA_PORTA_USB  = -22, /**< <b>(-22)</b> Erro ao tentar abrir a porta de comunicação.*/
    ERRO_CLAIM_UL               = -23 /**< <b>(-23)</b> Erro ao tentar reivindicar a interface do identificador do dispositivo. */
};

/** \ingroup g1
 * @brief GER_Erro_Conexao_TCP enum -31 à -40
 *
 * A faixa de -31 à -40 especifica os possíveis erros para conexão TCP/IP.
 */
enum GER_Erro_Conexao_TCP{
    PORTA_TCP_INVALIDA  = -31 /**< <b>(-31)</b> Porta TCP/IP está fora dos limites.*/
};

/** \ingroup g1
 * @brief IMP_Erro_Escrita_Impressora enum -41 à -50
 *
 * Definições para os erros de escrita.\n
 * Faixa de -41 à -50.
 */
enum IMP_Erro_Escrita_Impressora{
    POSICAO_INVALIDA    = -41, /**< <b>(-41)</b> Posição de impressão está fora dos limites.*/
    STILO_INVALIDO      = -42, /**< <b>(-42)</b> Estilo de letra inválido.*/
    TAMANHO_INVALIDO    = -43, /**< <b>(-43)</b> Tamanho de letra inválido.*/
    ERRO_ESCRITA        = -44 /**< <b>(-44)</b> Erro na tentativa de escrita na porta de comunicação.*/
};

/** \ingroup g1
 * @brief IMP_Erro_QRCode enum -51 à -60
 *
 * Definições para os erros relacionados ao QRCode.\n
 * Faixa -51 à -60.
 */
enum IMP_Erro_QRCode{
    TAMANHO_QR_INVALIDO         = -51, /**< <b>(-51)</b> Tamanho do QRCode informado está fora dos limites.*/
    NIVEL_DE_CORRECAO_INVALIDO  = -52, /**< <b>(-52)</b> Nivel de correção incorreto.*/
    DADOS_QR_INVALIDOS          = -53 /**< <b>(-53)</b> Dados informados não são válidos.*/
};

/** \ingroup g1
 * @brief IMP_Erro_CodigoBarras enum -61 à -70
 *
 * Define os erros para a impressão dos códigos de barras.\n
 * Faixa -61 à -70.
 */
enum IMP_Erro_CodigoBarras{
    CB_ALTURA_INVALIDA              = -61, /**< <b>(-61)</b> Altura informada está fora dos limites.*/
    CB_LARGURA_INVALIDA             = -62, /**< <b>(-62)</b> Largura informada está fora dos limites.*/
    CB_HRI_INVALIDO                 = -63, /**< <b>(-63)</b> HRI informado está fora dos limites.*/
    CB_TIPO_INVALIDO                = -64, /**< <b>(-64)</b> O tipo de código de barras não existe.*/
    CB_DADOS_INVALIDOS              = -65, /**< <b>(-65)</b> Os dados informados não estão de acordo com o padrão aceito para o código de barras.*/
    CB_AREA_DE_IMPRESSAO_EXCEDIDA   = -66 /**< <b>(-66)</b> Código de barras atingiu a área de impressão.*/
};

/** \ingroup g1
 * @brief IMP_Erro_ValidacaoXML enum -71 à -80
 *
 * Especificação dos possíveis erros de valiação dos XMLs.
 * Faixa -71 à -80.
 */
enum IMP_Erro_ValidacaoXML{
    ERRO_XSD            = -71, /**< <b>(-71)</b> Um problema com o XSD foi encontrado.*/
    XSD_NAO_ENCONTRADO  = -72 /**< <b>(-72)</b> Arquivo de validação XML não foi encontrado.*/
};

/** \ingroup g1
 * @brief IMP_Erro_Leitura_Impressora enum -81 à -90
 *
 * Especificação dos possíveis erros de leitura.\n
 * Faixa -81 à -90.
 */
enum IMP_Erro_Leitura_Impressora{
    NENHUM_DADO_RETORNADO = -81, /**< <b>(-81)</b> Nenhum dado retornou na tentativa de leitura na impressora.*/
    FALHA_AO_ABRIR_ARQUIVO = -82 /**< <b>(-82)</b> Falha ao tentar abrir arquivo para leitura.*/
};

// BRIEF MODIFICADO: ANTES ESTAVA DE -81 AA -90 (REPETIDO): //
// * @brief IMP_Erro_ValidacaoXMLSAT enum -81 à -90

/** \ingroup g1
 * @brief IMP_Erro_ValidacaoXMLSAT enum -91 à -100
 *
 * Especificação dos possíveis erros de validação do XML do CF-e-SAT.\n
 * Faixa -91 à -100.
 */
enum IMP_Erro_ValidacaoXMLSAT{
    ASSINATURA_QRCODE_INVALIDA = -91, /**< <b>(-91)</b> Assinatura para o QRCode inválida.*/
    DADOS_XML_VAZIO = -92, /**< <b>(-92)</b> Função não recebeu os dados de impressão.*/
    DADOS_XML_INVALIDO = -93, /**< <b>(-93)</b> Função não pode reconheceu os dados enviados.*/
    ARQUIVO_XML_NAO_PODE_SER_ABERTO = -94, /**< <b>(-93)</b> Função não pode abrir o arquivo informado.*/
    ARQUIVO_XML_NAO_CONTEM_DADOS = -95 /**< <b>(-93)</b> O Arquivo informado está vazio*/
};

/** \ingroup g1
 * @brief IMP_Erro_ValidacaoXMLNFCe enum -101 à -110
 *
 * Possíveis erros na validação do XML NFCe.\n
 * Faixa -101 à -110
 */
enum IMP_Erro_ValidacaoXMLNFCe{
    VERSAO_XMLNFCE_NAO_SUPORTADA    = -101, /**< <b>(-101)</b> A versão do XML enviado para impressão não é suportada.\n Atualmente a versão suportada é a 4.00*/
    VERSAO_XMLNFCE_INDEFINIDA       = -102, /**< <b>(-102)</b> Não foi possível definir a versão do XML enviado.*/
    TIPO_EMISSAO_INDEFINIDA         = -103, /**< <b>(-103)</b> Tipo de emissão não encontrada no XML.\n Valor referente a TAG tpEmis do XML, utilizado para imprimir cupom em contingência.*/
    PARAMETRO_CONF_INVALIDO         = -104,
    ARQUIVO_XML_NFCE_NAO_PODE_SER_ABERTO = -105 /**< <b>(-93)</b> Função não pode abrir o arquivo informado.*/
};

/** \ingroup g1
 * @brief IMP_Erro_Emissao_Sinal_Sonoro enum -111 à -120
 *
 * Possíveis valores de retorno para comando de emissão de sinal sonoro.\n
 * Faixa -111 à -120.
 */
enum IMP_Erro_Emissao_Sinal_Sonoro{
    QUANTIDADE_FORA_INTERVALO   = -111, /**< <b>(-111)</b> Quantidade de sinais ultrapassa o limite de 63.*/
    TEMPO_FORA_LIMITE           = -112 /**< <b>(-112)</b> Tempo fora do interalo definido para função.*/
};

/** \ingroup g1
 * @brief IMP_Erro_Abertura_Gaveta enum -121 à -125.
 *
 * Definição dos possíveis erros para a abertura da gaveta.\n
 * Faixa -121 à -125.
 */
enum IMP_Erro_Abertura_Gaveta{
    PINO_INVALIDO       = -121, /**< <b>(-121)</b> Idicação de pino inválida.*/
    TEMPO_INVALIDO      = -122 /**< <b>(-122)</b> Tempo de acionamento inválido*/
};
// TEMPO_INVALIDO MODIFICADO: ANTES ESTAVA -222 (FORA DA FAIXA):
//    TEMPO_INVALIDO = -222 /**< <b>(-122)</b> Tempo de acionamento inválido*/

/** \ingroup g1
 * @brief IMP_Erro_Status enum -126 à -130
 *
 * Definição dos possíveis erros de Status.\n
 * Faixa -126 à -130.
 */
enum IMP_Erro_Status{
    STATUS_NAO_SUPORTADO            = -126, /**< <b>(-126)</b> Status solicitado não suportado para o modelo de impressora selecionado.*/
    PARAMETRO_TIPO_STATUS_INVALIDO  = -127 /**< <b>(-127)</b> Especificação do status inválida.*/
};

/** \ingroup g1
 * @brief IMP_Erro_Imagem enum -131 à -135
 *
 * Definição dos possíveis erros para impressão de imagem.\n
 * Faixa -131 à -135.
 */
enum IMP_Erro_Imagem{
    KEY_INVALIDO        = -131, /**< <b>(-131)</b> Key da imagem está fora dos limites. Valor de (CHAR)32 à (CHAR)126.*/
    SCALA_INVALIDA      = -132 /**< <b>(-132)</b> Scala está fora dos limites. Valor de 1 ou 2.*/
};

/** \ingroup g1
 * @brief IMP_Erro_ModoPagina enum -136 à -140
 *
 * Definição dos possíveis erros para definição do modo pagina.\n
 * Faixa -136 à -140.
 */
enum IMP_Erro_ModoPagina{
    DIRECAO_INVALIDA                = -136, /**< <b>(-136)</b> Valor fora do range de 0 a 3.*/
    POS_IMP_HORIZONTAL_INVALIDA     = -137 /**< <b>(-137)</b> Posição horizontal ultrapassa o limite de 500 pontos.*/
};



enum IMP_Compatibilidade_HPRT{
    STATEPRINTER_SUCESSO            = 0,
    STATEPRINTER_SEMPAPEL           = 1,
    STATEPRINTER_TAMPAABERTA        = 2,
    STATEPRINTER_QSESEMPAPEL        = 4,
    STATEPRINTER_TAMPAEPAPEL        = 5,
    STATEPRINTER_QSESEMPAPELETAMPA  = 6,
    PRINTTEXT_ATRIBUTO_INVALIDO     = -145
};

/** \ingroup g1
 * @brief Erro_Sistema enum -150 à -160
 *
 * Definição dos possíveis erros para uso do serviço de comunicação.\n
 */
enum Erro_Sistema{
    NAO_FOI_POSSIVEL_INICIAR_O_SERVICO          = -150, /**< <b>(-150)</b> NÃO FOI POSSIVEL INICIAR O SERVIÇO.*/
    ERRO_AO_CARREGAR_BIBLIOTECA_DA_IMPRESSORA   = -151, /**< <b>(-151)</b> ERRO AO CARREGAR BIBLIOTECA DE COMUNICAÇÃO COM A IMPRESSORA.*/
    ERRO_AO_CARREGAR_BIBLIOTECA_DO_SAT          = -152, /**< <b>(-152)</b> ERRO AO CARREGAR BIBLIOTECA DE COMUNICAÇÃO COM SAT.*/
    ERRO_AO_CARREGAR_BIBLIOTECA_DO_E1SAT        = -153, /**< <b>(-153)</b> ERRO AO CARREGAR BIBLIOTECA AUXILIAR DO SAT*/
    OPERACAO_INVALIDA                           = -154, /**< <b>(-154)</b> OPERAÇÃO INVALIDA*/
    SERVICO_OCUPADO                             = -155, /**< <b>(-155)</b> SERVIÇO OCUPADO*/
    ERRO_AO_CARREGAR_BIBLIOTECA_DA_ETIQUETA     = -156, /**< <b>(-156)</b> ERRO AO CARREGAR BIBLIOTECA DE COMUNICAÇÃO COM A IMPRESSORA DE ETIQUETAS*/
    BIBLIOTECA_DO_SAT_INVALIDA                  = -157  /**< <b>(-157)</b> A BIBLIOTECA DO SAT NÃO É VALIDA*/
};

/** \ingroup g1
 * @brief Erro_EnvioComandos enum -160 à -170
 *
 * Definição dos possíveis erros no processamento dos comandos enviados ao serviço.\n
 */
enum Erro_EnvioComandos{
    COMANDO_INVALIDO                = -160,/**< <b>(-160)</b> COMANDO NÃO ENCONTRADO.*/
    ARQUIVO_NAO_EXISTE              = -161,/**< <b>(-161)</b> ARQUIVO NÃO ENCONTRADO.*/
    ESTE_JSON_NAO_E_UM_OBJETO       = -162,/**< <b>(-162)</b> JSON INVALIDO.*/
    TIPO_PARAMETRO_INVALIDO         = -163,/**< <b>(-163)</b> PARAMETRO PASSADO VIA JSON NÃO É UM PARAMETRO VALIDO.*/ 
    QUANTIDADE_INVALIDA             = -164,/**< <b>(-164)</b> QUANTIDADE DE PARAMETROS DA FUNCAO NAO É IGUAL AO PROTOTIPO.*/
    PARAMETRO_NAO_ENCONTRADO        = -165,/**< <b>(-165)</b> PARAMETRO INFORMADO NO JSON NÃO FOI ENCONTRADO NA LISTA DE PARAMETROS PARA A FUNCAO INDICADA.*/ 
    MODULO_FUNCAO_NAO_ENCONTRADO    = -166 /**< <b>(-166)</b> MODULO OU FUNCAO NAO ENCONTRADA NA LISTA.*/
};


/** \ingroup g1
 * @brief IMP_Erro_ConexaoAndroid enum -171 à -180 e -391 à -400
 *
 * Definição dos possíveis erros de conexão no ambiente Android.\n
 * Faixas -171 à -180 e -391 à -400.
 */

// *** CODIGOS ADICIONADOS PARA O CONTEXTO DE CONEXAO NO ANDROID ***
enum Erro_ConexaoAndroid{
    RECONEXOES_ESGOTADAS            = -171, /**< <b>(-171)</b> Instância da classe atingiu valor limite de reconexões do <b>tipo</b>.*/
    CONEXAO_ATIVA_OUTRO             = -172, /**< <b>(-172)</b> Outro <b>tipo</b> de dispositivo está usando a conexão.*/
    ERRO_ABERTURA_PORTA             = -173, /**< <b>(-173)</b> Erro na abertura da porta.*/
    ERRO_FECHAMENTO_PORTA           = -174, /**< <b>(-174)</b> Erro no fechamento da porta.*/
    ERRO_ESCRITA_PORTA              = -175, /**< <b>(-175)</b> Erro de escrita na porta.*/
    ERRO_NENHUM_BYTE_ENVIADO        = -176, /**< <b>(-176)</b> Nenhum byte foi enviado à impressora.*/
    ERRO_LEITURA_PORTA              = -177, /**< <b>(-177)</b> Erro de leitura na porta.*/
    THREAD_EXECUTION_EXCEPTION      = -178, /**< <b>(-178)</b> Erro na execução da thread (ExecutionException).*/
    THREAD_INTERRUPTED_EXCEPTION    = -179, /**< <b>(-179)</b> Erro na execução da thread (InterruptedException).*/
    ERRO_NOT_ACTIVITY               = -180, /**< <b>(-180)</b> Objeto context passado na função <i>setContext</i> não é instância de Activity.*/

    /* ***CODIGOS ENTRE -181 ~ -390 ESTAO RESERVADOS PARA E1_ETIQUETA*** */

    // *** CODIGOS ADICIONADOS PARA IMPLEMENTACAO BLUETOOTH ***
    MAC_ADDRESS_INVALIDO        = -391, /**< <b>(-391)</b> Mac Address inválido para conexão Bluetooth.*/
    DISPOSITIVO_NAO_SUPORTA_BT  = -392, /**< <b>(-392)</b> Dispositivo não suporta Bluetooth.*/
    BLUETOOTH_DESATIVADO        = -393, /**< <b>(-393)</b> Bluetooth do dispositivo está desativado.*/
    DISPOSITIVO_NAO_PAREADO     = -394, /**< <b>(-394)</b> Dispositivo não está pareado.*/
    ERRO_CONEXAO_BLUETOOTH      = -395 /**< <b>(-395)</b> Erro ao iniciar conexão Bluetooth.*/
};


/** \ingroup g1
 * @brief IMP_Erro_Outros enum -401 à -410
 *
 * Define os demais erros previstos nas funções.\n
 * Faixa -401 à -410.
 */

// *** ERRO SOBRE O USO DA FUNCAO DE CORTE NA SMARTPOS ***
enum Erro_Outros{
    ERRO_FUNCAO_NAO_SUPORTADA   = -401, /**< <b>(-401)</b> Dispositivo não suporta a função chamada.*/
    ERRO_ID_INVALIDO            = -402, /**< <b>(-402)</b> Parâmetro ID está fora dos limites.*/

    // OS ERROS ABAIXO SAO UTILIZADOS SOMENTE NO ANDROID;
    // FORAM ADICIONADOS AQUI PARA FICAREM VISIVEIS NA DOCUMENTACAO
    ERRO_SERVICO_NAO_INICIADO               = -403, /**< <b>(-403)</b> A função foi chamada sem o serviço estar iniciado.*/
    ERRO_ABERTURA_NAO_AUTORIZADA            = -404, /**< <b>(-404)</b> Tentativa não autorizada para iniciar o serviço.*/
    ERRO_FECHAMENTO_NAO_AUTORIZADO          = -405, /**< <b>(-405)</b> Tentativa não autorizada para encerrar o serviço.*/
    ERRO_FUNCAO_NAO_CHAMADA_PELO_SERVICO    = -406, /**< <b>(-406)</b> A função não foi chamada pelo módulo do serviço.*/
    ERRO_FUNCAO_NAO_DISPONIVEL_VIA_SERVICO  = -407, /**< <b>(-407)</b> A função não está disponível para uso com o serviço.*/
    ERRO_ACTIVITY_NAO_DEFINIDA				= -408 /**< <b>(-408)</b> A Activity não foi definida para abertura de conexão com impressora do dispositivo Android.*/
};

/** \ingroup g1
 * @brief IMP_Erro_PDF417 enum -411 à -420
 *
 * Definições para os erros relacionados ao PDF417.\n
 * Faixa -411 à -420.
 */
enum IMP_Erro_PDF417{
    NUMBER_COLUMNS_INVALIDO         = -411, /**< <b>(-411)</b> Parâmetro numCols está fora dos limites.*/
    NUMBER_ROWS_INVALIDO            = -412, /**< <b>(-412)</b> Parâmetro numRows está fora dos limites.*/
    WIDTH_INVALIDO                  = -413, /**< <b>(-413)</b> Parâmetro width está fora dos limites.*/
    HEIGHT_INVALIDO                 = -414, /**< <b>(-414)</b> Parâmetro height está fora dos limites.*/
    ERROR_CORRECTION_LEVEL_INVALIDO = -415, /**< <b>(-415)</b> Parâmetro errCorLvl está fora dos limites.*/
    OPTIONS_INVALIDO                = -416, /**< <b>(-416)</b> Parâmetro options inválido.*/
    DADOS_PDF_INVALIDOS             = -417, /**< <b>(-417)</b> Parâmetro dados inválido - não há dado ou os dados ultrapassam o limite de 65532 caracteres.*/
    ERRO_PDF_DESCONHECIDO           = -418 /**< <b>(-418)</b> Erro desconhecido na impressão do PDF417.*/
};


/*****************************************************************************/
/*****************************************************************************/


/*
    Descricao:      Arquivo de cabecalho com as definicoes de possiveis erros para a biblioteca E1_Etiqueta
    Autor:          Rodrigo Angelo
    Data:           27/06/2019
*/


/****************************************************************/
// FAIXA DOS CODIGOS DE ERRO: -181 ~ -390 (MANTER RESERVADO!!!) //
/****************************************************************/


/** \ingroup g1
 * \brief GER_Erro_SystemSetting enum -181 à -190
 *
 * Define os erros dos ajustes de configuração de sistema.\n
 * Faixa -181 à -190.
 */

enum GER_Erro_SystemSetting{
    ERRO_ALTURA_GAP             = -181, /**< <b>(-181)</b> Parâmetro altura está fora dos limites.*/
    ERRO_TIPO_TRANSFERENCIA     = -182, /**< <b>(-182)</b> Parâmetro transferencia inválido.*/
    ERRO_BAUDRATE_BAUDRATE      = -183, /**< <b>(-183)</b> Parâmetro baudrate inválido.*/
    ERRO_BAUDRATE_DATA_LENGTH   = -184, /**< <b>(-184)</b> Parâmetro dataLength inválido.*/
    ERRO_BAUDRATE_PARITY        = -185, /**< <b>(-185)</b> Parâmetro parity inválido.*/
    ERRO_BAUDRATE_STOP_BIT      = -186, /**< <b>(-186)</b> Parâmetro stopBit inválido.*/
    ERRO_SYMBOL                 = -187 /**< <b>(-187)</b> Parâmetro symbol inválido.*/
};

/** \ingroup g1
 * \brief GER_Erro_SystemLevel enum -191 à -210
 *
 * Define os erros dos ajustes de nível de sistema.\n
 * Faixa -191 à -210.
 */

enum GER_Erro_SystemLevel{
    ERRO_MEDIDA                         = -191, /**< <b>(-191)</b> Parâmetro medida inválido.*/
    ERRO_BACKFEED                       = -192, /**< <b>(-192)</b> Parâmetro backfeed está fora dos limites.*/
    ERRO_PRINT_ST_POS                   = -193, /**< <b>(-193)</b> Parâmetro printStPos está fora dos limites.*/
    ERRO_SENSOR                         = -194, /**< <b>(-194)</b> Parâmetro sensor inválido.*/
    ERRO_MODO_CONTINUO                  = -195, /**< <b>(-195)</b> Parâmetro modoContinuo está fora dos limites.*/
    ERRO_LENGTH                         = -196, /**< <b>(-196)</b> Parâmetro length está fora dos limites.*/
//    ERRO_CUTTER_PEELER                = -197, /**< <b>(-197)</b> Parâmetro cutterPeeler inválido.*/
    ERRO_MEMORY_STATUS_TIPO_DADOS       = -198, /**< <b>(-198)</b> Parâmetro tipoDados inválido.*/
    ERRO_LIMPA_MODULO_MODULO            = -199, /**< <b>(-199)</b> Parâmetro modulo inválido.*/
    ERRO_ENVIA_IMAGEM_MODULO            = -200, /**< <b>(-200)</b> Parâmetro modulo inválido.*/
    ERRO_ENVIA_IMAGEM_FORMATO           = -201, /**< <b>(-201)</b> Parâmetro formato inválido.*/
    ERRO_ENVIA_IMAGEM_NOME_TAMANHO      = -202, /**< <b>(-202)</b> Parâmetro nome inválido - não há nome ou o nome ultrapassa o limite de 16 caracteres.*/
    ERRO_ENVIA_IMAGEM_NOME_CARACTERE    = -203, /**< <b>(-203)</b> Parâmetro nome inválido - nome tem algum caractere não alfanumérico.*/
    ERRO_ENVIA_IMAGEM_ARQUIVO           = -204, /**< <b>(-204)</b> Parâmetro arquivo inválido - arquivo inacessível.*/
    ERRO_EXCLUI_IMAGEM_MODULO           = -205, /**< <b>(-205)</b> Parâmetro modulo inválido.*/
    ERRO_EXCLUI_IMAGEM_NOME_TAMANHO     = -206, /**< <b>(-206)</b> Parâmetro nome inválido - não há nome ou o nome ultrapassa o limite de 16 caracteres.*/
    ERRO_EXCLUI_IMAGEM_NOME_CARACTERE   = -207 /**< <b>(-207)</b> Parâmetro nome inválido - nome tem algum caractere não alfanumérico.*/
};

/** \ingroup g1
 * \brief GER_Erro_LabelFormatting enum -211 à -220
 *
 * Define os erros dos ajustes de formatação de label.\n
 * Faixa -211 à -220.
 */

enum GER_Erro_LabelFormatting{
    ERRO_OFFSET_LINHA       = -211, /**< <b>(-211)</b> Parâmetro offsetLinha está fora dos limites.*/
    ERRO_OFFSET_COLUNA      = -212, /**< <b>(-212)</b> Parâmetro offsetColuna está fora dos limites.*/
    ERRO_VEL_IMPRESSAO      = -213, /**< <b>(-213)</b> Parâmetro velImpressao inválido.*/
    ERRO_TAM_PIXEL          = -214, /**< <b>(-214)</b> Parâmetro(s) largura e/ou altura inválido(s).*/
    ERRO_CALOR              = -215, /**< <b>(-215)</b> Parâmetro calor está fora dos limites.*/
    ERRO_QTDE               = -216, /**< <b>(-216)</b> Parâmetro qtde está fora dos limites.*/
    ERRO_CORTAR_ZERO        = -217, /**< <b>(-217)</b> Parâmetro cortarZero inválido.*/
//    ERRO_CUT_AMOUNT       = -218, /**< <b>(-218)</b> Parâmetro cutAmount está fora dos limites.*/
    ERRO_LOGIC_IMG_MODE     = -219, /**< <b>(-219)</b> Parâmetro logicImgMode inválido.*/
    ERRO_MIRROR             = -220 /**< <b>(-220)</b> Parâmetro mirror inválido.*/
};


/** \ingroup g1
 * @brief GER_Erro_Texto enum -221 à -230
 *
 * Define os erros para a geração de texto (fontes Alfanuméricas).\n
 * Faixa -221 à -230.
 */

enum GER_Erro_Texto{
    TEXTO_ROTACAO_INVALIDA                      = -221, /**< <b>(-221)</b> Parâmetro rotacao inválido.*/
    TEXTO_FONTE_INVALIDA                        = -222, /**< <b>(-222)</b> Parâmetro fonte inválido.*/
    TEXTO_MULTIPLICADOR_HORIZONTAL_INVALIDO     = -223, /**< <b>(-223)</b> Parâmetro multH está fora dos limites.*/
    TEXTO_MULTIPLICADOR_VERTICAL_INVALIDO       = -224, /**< <b>(-224)</b> Parâmetro multV está fora dos limites.*/
    TEXTO_COORDENADA_Y_INVALIDA                 = -225, /**< <b>(-225)</b> Parâmetro coordY está fora dos limites.*/
    TEXTO_COORDENADA_X_INVALIDA                 = -226, /**< <b>(-226)</b> Parâmetro coordX está fora dos limites.*/
    TEXTO_TEXTO_INVALIDO                        = -227 /**< <b>(-227)</b> Parâmetro texto inválido - não há texto ou o texto ultrapassa o limite de 255 caracteres.*/
};

/** \ingroup g1
 * @brief GER_Erro_TextoASD enum -231 à -240
 *
 * Define os erros para a geração de texto (fontes Smooth ASD).\n
 * Faixa -231 à -240.
 */

enum GER_Erro_TextoASD{
    TEXTOASD_ROTACAO_INVALIDA                   = -231, /**< <b>(-231)</b> Parâmetro rotacao inválido.*/
    TEXTOASD_MULTIPLICADOR_HORIZONTAL_INVALIDO  = -232, /**< <b>(-232)</b> Parâmetro multH está fora dos limites.*/
    TEXTOASD_MULTIPLICADOR_VERTICAL_INVALIDO    = -233, /**< <b>(-233)</b> Parâmetro multV está fora dos limites.*/
    TEXTOASD_TAMANHO_INVALIDO                   = -234, /**< <b>(-234)</b> Parâmetro tamanho inválido.*/
    TEXTOASD_COORDENADA_Y_INVALIDA              = -235, /**< <b>(-235)</b> Parâmetro coordY está fora dos limites.*/
    TEXTOASD_COORDENADA_X_INVALIDA              = -236, /**< <b>(-236)</b> Parâmetro coordX está fora dos limites.*/
    TEXTOASD_TEXTO_INVALIDO                     = -237 /**< <b>(-237)</b> Parâmetro texto inválido - não há texto ou o texto ultrapassa o limite de 255 caracteres.*/
};

/** \ingroup g1
 * @brief GER_Erro_TextoCourier enum -241 à -250
 *
 * Define os erros para a geração de texto (fontes Courier).\n
 * Faixa -241 à -250.
 */

enum GER_Erro_TextoCourier{
    TEXTOCOURIER_ROTACAO_INVALIDA                   = -241, /**< <b>(-241)</b> Parâmetro rotacao inválido.*/
    TEXTOCOURIER_MULTIPLICADOR_HORIZONTAL_INVALIDO  = -242, /**< <b>(-242)</b> Parâmetro multH está fora dos limites.*/
    TEXTOCOURIER_MULTIPLICADOR_VERTICAL_INVALIDO    = -243, /**< <b>(-243)</b> Parâmetro multV está fora dos limites.*/
    TEXTOCOURIER_SYMBOL_INVALIDO                    = -244, /**< <b>(-244)</b> Parâmetro symbol inválido.*/
    TEXTOCOURIER_COORDENADA_Y_INVALIDA              = -245, /**< <b>(-245)</b> Parâmetro coordY está fora dos limites.*/
    TEXTOCOURIER_COORDENADA_X_INVALIDA              = -246, /**< <b>(-246)</b> Parâmetro coordX está fora dos limites.*/
    TEXTOCOURIER_TEXTO_INVALIDO                     = -247 /**< <b>(-247)</b> Parâmetro texto inválido - não há texto ou o texto ultrapassa o limite de 255 caracteres.*/
};

/** \ingroup g1
 * @brief GER_Erro_Linha enum -251 à -260
 *
 * Define os erros para a geração de linha.\n
 * Faixa -251 à -260.
 */

enum GER_Erro_Linha{
    LINHA_COORDENADA_Y_INVALIDA     = -251, /**< <b>(-251)</b> Parâmetro coordY está fora dos limites.*/
    LINHA_COORDENADA_X_INVALIDA     = -252, /**< <b>(-252)</b> Parâmetro coordX está fora dos limites.*/
    LINHA_COMPRIMENTO_INVALIDO      = -253, /**< <b>(-253)</b> Parâmetro comprimento está fora dos limites.*/
    LINHA_ALTURA_INVALIDA           = -254 /**< <b>(-254)</b> Parâmetro altura está fora dos limites.*/
};

/** \ingroup g1
 * @brief GER_Erro_Box enum -261 à -270
 *
 * Define os erros para a geração de box.\n
 * Faixa -261 à -270.
 */

enum GER_Erro_Box{
    BOX_COORDENADA_Y_INVALIDA                   = -261, /**< <b>(-261)</b> Parâmetro coordY está fora dos limites.*/
    BOX_COORDENADA_X_INVALIDA                   = -262, /**< <b>(-262)</b> Parâmetro coordX está fora dos limites.*/
    BOX_COMPRIMENTO_INVALIDO                    = -263, /**< <b>(-263)</b> Parâmetro comprimento está fora dos limites.*/
    BOX_ALTURA_INVALIDA                         = -264, /**< <b>(-264)</b> Parâmetro altura está fora dos limites.*/
    BOX_GROSSURA_BORDAS_HORIZONTAIS_INVALIDA    = -265, /**< <b>(-265)</b> Parâmetro grosBordasH está fora dos limites.*/
    BOX_GROSSURA_BORDAS_VERTICAIS_INVALIDA      = -266 /**< <b>(-266)</b> Parâmetro grosBordasV está fora dos limites.*/
};

/** \ingroup g1
 * @brief GER_Erro_BarCode1D enum -271 à -280
 *
 * Define os erros para a geração de código de barras de uma dimensão.\n
 * Faixa -271 à -280.
 */

enum GER_Erro_BarCode1D{
    BARCODE1D_ROTACAO_INVALIDA                      = -271, /**< <b>(-271)</b> Parâmetro rotacao inválido.*/
    BARCODE1D_TIPO_INVALIDO                         = -272, /**< <b>(-272)</b> Parâmetro tipo inválido.*/
    BARCODE1D_LARGURA_BARRAS_LARGAS_INVALIDA        = -273, /**< <b>(-273)</b> Parâmetro largBarrasL está fora dos limites.*/
    BARCODE1D_LARGURA_BARRAS_ESTREITAS_INVALIDA     = -274, /**< <b>(-274)</b> Parâmetro largBarrasE está fora dos limites.*/
    BARCODE1D_ALTURA_INVALIDA                       = -275, /**< <b>(-275)</b> Parâmetro altura está fora dos limites.*/
    BARCODE1D_COORDENADA_Y_INVALIDA                 = -276, /**< <b>(-276)</b> Parâmetro coordY está fora dos limites.*/
    BARCODE1D_COORDENADA_X_INVALIDA                 = -277, /**< <b>(-277)</b> Parâmetro coordX está fora dos limites.*/
    BARCODE1D_CODIGO_INVALIDO                       = -278, /**< <b>(-278)</b> Parâmetro Código inválido - não há código ou o código ultrapassa o limite de 255 (ou 254, para o Code 128) caracteres.*/
    BARCODE1D_TAMANHO_INVALIDO                      = -279, /**< <b>(-279)</b> O código recebido não respeita o tamanho definido pelo seu tipo.*/
    BARCODE1D_CARACTERE_INVALIDO                    = -280 /**< <b>(-280)</b> O código recebido possui um ou mais caracteres não definidos pelo seu tipo.*/
};

/** \ingroup g1
 * @brief The GER_Erro_QRCodeAuto enum -281 à -290
 *
 * Define os erros para a geração de QR Code (modo automático).\n
 * Faixa -281 à -290.
 */

enum GER_Erro_QRCodeAuto{
    QRCODEAUTO_ROTACAO_INVALIDA         = -281, /**< <b>(-281)</b> Parâmetro rotacao inválido.*/
    QRCODEAUTO_MULTIPLICADOR_INVALIDO   = -282, /**< <b>(-282)</b> Parâmetro mult está fora dos limites.*/
    QRCODEAUTO_COORDENADA_Y_INVALIDA    = -283, /**< <b>(-283)</b> Parâmetro coordY está fora dos limites.*/
    QRCODEAUTO_COORDENADA_X_INVALIDA    = -284, /**< <b>(-284)</b> Parâmetro coordX está fora dos limites.*/
    QRCODEAUTO_CODIGO_INVALIDO          = -285 /**< <b>(-285)</b> Parâmetro Código inválido - não há código ou o código ultrapassa o limite de 255 caracteres.*/
};

/** \ingroup g1
 * @brief The GER_Erro_QRCodeManual enum -291 à -310
 *
 * Define os erros para a geração de QR Code (modo manual).\n
 * Faixa -291 à -310.
 */

enum GER_Erro_QRCodeManual{
    QRCODEMANUAL_ROTACAO_INVALIDA           = -291, /**< <b>(-291)</b> Parâmetro rotacao inválido.*/
    QRCODEMANUAL_MULTIPLICADOR_INVALIDO     = -292, /**< <b>(-292)</b> Parâmetro mult está fora dos limites.*/
    QRCODEMANUAL_COORDENADA_Y_INVALIDA      = -293, /**< <b>(-293)</b> Parâmetro coordY está fora dos limites.*/
    QRCODEMANUAL_COORDENADA_X_INVALIDA      = -294, /**< <b>(-294)</b> Parâmetro coordX está fora dos limites.*/
    QRCODEMANUAL_NUM_MODELO_INVALIDO        = -295, /**< <b>(-295)</b> Parâmetro numModelo inválido.*/
    QRCODEMANUAL_NVL_COR_ERRO_INVALIDO      = -296, /**< <b>(-296)</b> Parâmetro nvlCorErro inválido.*/
    QRCODEMANUAL_NUM_MASCARA_INVALIDO       = -297, /**< <b>(-297)</b> Parâmetro numMascara inválido.*/
    QRCODEMANUAL_INPUT_INVALIDO             = -298, /**< <b>(-298)</b> Parâmetro input inválido.*/
    QRCODEMANUAL_INPUT_CONFIG_INVALIDO      = -299, /**< <b>(-299)</b> Parâmetro inputConfig inválido.*/
    QRCODEMANUAL_NUM_CHARS_8BIT_INVALIDO    = -300, /**< <b>(-300)</b> Parâmetro numChars8bit está fora dos limites.*/
    QRCODEMANUAL_CODIGO_INVALIDO            = -301 /**< <b>(-301)</b> Parâmetro Código inválido - não há código ou o código ultrapassa o limite de 255 caracteres.*/
};

/** \ingroup g1
 * @brief The GER_Erro_MaxiCode enum -311 à -320
 *
 * Define os erros para a geração de MaxiCode.\n
 * Faixa -311 à -320.
 */

enum GER_Erro_MaxiCode{
    MAXICODE_ROTACAO_INVALIDA           = -311, /**< <b>(-311)</b> Parâmetro rotacao inválido.*/
    MAXICODE_COORDENADA_Y_INVALIDA      = -312, /**< <b>(-312)</b> Parâmetro coordY está fora dos limites.*/
    MAXICODE_COORDENADA_X_INVALIDA      = -313, /**< <b>(-313)</b> Parâmetro coordX está fora dos limites.*/
    MAXICODE_PRIMARY_ZIP_INVALIDO       = -314, /**< <b>(-314)</b> Parâmetro priZip está fora dos limites.*/
    MAXICODE_SECONDARY_ZIP_INVALIDO     = -315, /**< <b>(-315)</b> Parâmetro secZip está fora dos limites.*/
    MAXICODE_COUNTRY_INVALIDO           = -316, /**< <b>(-316)</b> Parâmetro country está fora dos limites.*/
    MAXICODE_CLASS_OF_SERVICE_INVALIDA  = -317, /**< <b>(-317)</b> Parâmetro serClass está fora dos limites.*/
    MAXICODE_CODIGO_INVALIDO            = -318 /**< <b>(-318)</b> Parâmetro Código inválido - não há código ou o código ultrapassa o limite de 84 caracteres.*/
};

/** \ingroup g1
 * @brief The GER_Erro_DataMatrix enum -321 à -330
 *
 * Define os erros para a geração de DataMatrix.\n
 * Faixa -321 à -330.
 */

enum GER_Erro_DataMatrix{
    DATAMATRIX_ROTACAO_INVALIDA             = -321, /**< <b>(-321)</b> Parâmetro rotacao inválido.*/
    DATAMATRIX_MULTIPLICADOR_INVALIDO       = -322, /**< <b>(-322)</b> Parâmetro mult está fora dos limites.*/
    DATAMATRIX_COORDENADA_Y_INVALIDA        = -323, /**< <b>(-323)</b> Parâmetro coordY está fora dos limites.*/
    DATAMATRIX_COORDENADA_X_INVALIDA        = -324, /**< <b>(-324)</b> Parâmetro coordX está fora dos limites.*/
    DATAMATRIX_ROWS_INVALIDAS               = -325, /**< <b>(-325)</b> Parâmetro rows inválido.*/
    DATAMATRIX_COLUMNS_INVALIDAS            = -326, /**< <b>(-326)</b> Parâmetro columns inválido.*/
    DATAMATRIX_CODIGO_INVALIDO              = -327 /**< <b>(-327)</b> Parâmetro Código inválido - não há código ou o código ultrapassa o limite de 255 caracteres.*/
};

/** \ingroup g1
 * @brief The GER_Erro_DataBar enum -331 à -340
 *
 * Define os erros para a geração de DataBar.\n
 * Faixa -331 à -340.
 */

enum GER_Erro_DataBar{
    DATABAR_ROTACAO_INVALIDA                        = -331, /**< <b>(-331)</b> Parâmetro rotacao inválido.*/
    DATABAR_BAR_RATIO_INVALIDO                      = -332, /**< <b>(-332)</b> Parâmetro barRatio está fora dos limites.*/
    DATABAR_ALTURA_INVALIDA                         = -333, /**< <b>(-333)</b> Parâmetro altura está fora dos limites.*/
    DATABAR_COORDENADA_Y_INVALIDA                   = -334, /**< <b>(-334)</b> Parâmetro coordY está fora dos limites.*/
    DATABAR_COORDENADA_X_INVALIDA                   = -335, /**< <b>(-335)</b> Parâmetro coordX está fora dos limites.*/
    DATABAR_TIPO_INVALIDO                           = -336, /**< <b>(-336)</b> Parâmetro tipo inválido.*/
    DATABAR_PIXEL_MULTIPLIER_INVALIDO               = -337, /**< <b>(-337)</b> Parâmetro pxMult está fora dos limites.*/
    DATABAR_NUMERIC_LINEAR_DATA_TAMANHO_INVALIDO    = -338, /**< <b>(-338)</b> Parâmetro numLinData inválido - não há dado ou o dado ultrapassa o limite de 13 caracteres.*/
    DATABAR_NUMERIC_LINEAR_DATA_CARACTERE_INVALIDO  = -339, /**< <b>(-339)</b> Parâmetro numLinData inválido - dado contém algum caractere não numérico.*/
    DATABAR_CODIGO_INVALIDO                         = -340 /**< <b>(-340)</b> Parâmetro Código inválido - não há código ou o código ultrapassa o limite de 255 caracteres.*/
};

/** \ingroup g1
 * @brief The GER_Erro_DataBarExpanded enum -341 à -350
 *
 * Define os erros para a geração de DataBar (Expanded).\n
 * Faixa -341 à -350.
 */

enum GER_Erro_DataBarExpanded{
    DATABAREXPANDED_ROTACAO_INVALIDA                = -341, /**< <b>(-341)</b> Parâmetro rotacao inválido.*/
    DATABAREXPANDED_BAR_RATIO_INVALIDO              = -342, /**< <b>(-342)</b> Parâmetro barRatio está fora dos limites.*/
    DATABAREXPANDED_ALTURA_INVALIDA                 = -343, /**< <b>(-343)</b> Parâmetro altura está fora dos limites.*/
    DATABAREXPANDED_COORDENADA_Y_INVALIDA           = -344, /**< <b>(-344)</b> Parâmetro coordY está fora dos limites.*/
    DATABAREXPANDED_COORDENADA_X_INVALIDA           = -345, /**< <b>(-345)</b> Parâmetro coordX está fora dos limites.*/
    DATABAREXPANDED_PIXEL_MULTIPLIER_INVALIDO       = -346, /**< <b>(-346)</b> Parâmetro pxMult está fora dos limites.*/
    DATABAREXPANDED_SEGMENTS_PER_ROW_INVALIDO       = -347, /**< <b>(-347)</b> Parâmetro segsRow inválido.*/
    DATABAREXPANDED_ALPHANUMERIC_TAMANHO_INVALIDO   = -348, /**< <b>(-348)</b> Parâmetro alphanumeric inválido - não há dado.*/
    DATABAREXPANDED_ALPHANUMERIC_CARACTERE_INVALIDO = -349, /**< <b>(-349)</b> Parâmetro alphanumeric inválido - dado contém algum caractere não numérico.*/
    DATABAREXPANDED_CODIGO_INVALIDO                 = -350 /**< <b>(-350)</b> Parâmetro Código inválido - não há código ou o código ultrapassa o limite de 255 caracteres.*/
};

/** \ingroup g1
 * @brief The GER_Erro_PDF417 enum -351 à -370
 *
 * Define os erros para a geração de PDF-417.\n
 * Faixa -351 à -370.
 */

enum GER_Erro_PDF417{
    PDF417_ROTACAO_INVALIDA                     = -351, /**< <b>(-351)</b> Parâmetro rotacao inválido.*/
    PDF417_MULTIPLICADOR_HORIZONTAL_INVALIDO    = -352, /**< <b>(-352)</b> Parâmetro multH está fora dos limites.*/
    PDF417_MULTIPLICADOR_VERTICAL_INVALIDO      = -353, /**< <b>(-353)</b> Parâmetro multV está fora dos limites.*/
    PDF417_COORDENADA_Y_INVALIDA                = -354, /**< <b>(-354)</b> Parâmetro coordY está fora dos limites.*/
    PDF417_COORDENADA_X_INVALIDA                = -355, /**< <b>(-355)</b> Parâmetro coordX está fora dos limites.*/
    PDF417_TIPO_INVALIDO                        = -356, /**< <b>(-356)</b> Parâmetro tipo inválido.*/
    PDF417_SECURITY_LEVEL_INVALIDO              = -357, /**< <b>(-357)</b> Parâmetro secLevel inválido.*/
    PDF_417_ASPECT_RATIO_INVALIDO               = -358, /**< <b>(-358)</b> Parâmetro aspRatio está fora dos limites.*/
    PDF417_ROW_NUMBER_INVALIDO                  = -359, /**< <b>(-359)</b> Parâmetro rowNum está fora dos limites.*/
    PDF417_COLUMN_NUMBER_INVALIDO               = -360, /**< <b>(-360)</b> Parâmetro colNum está fora dos limites.*/
    PDF417_CODIGO_INVALIDO                      = -361 /**< <b>(-361)</b> Parâmetro Código inválido - não há código ou o código ultrapassa o limite de 255 caracteres.*/
};

/** \ingroup g1
 * @brief The GER_Erro_Imagem enum -371 à -380
 *
 * Define os erros para a geração de Imagem.\n
 * Faixa -371 à -380.
 */

enum GER_Erro_Imagem{
    IMAGEM_COORDENADA_Y_INVALIDA    = -371, /**< <b>(-371)</b> Parâmetro coordY está fora dos limites.*/
    IMAGEM_COORDENADA_X_INVALIDA    = -372, /**< <b>(-372)</b> Parâmetro coordX está fora dos limites.*/
    IMAGEM_NOME_TAMANHO_INVALIDO    = -373, /**< <b>(-373)</b> Parâmetro nome inválido - não há nome ou o nome ultrapassa o limite de 16 caracteres.*/
    IMAGEM_NOME_CARACTERE_INVALIDO  = -374 /**< <b>(-374)</b> Parâmetro nome inválido - nome tem algum caractere não alfanumérico.*/
};

/** \ingroup g1
 * @brief The GER_Erro_Outros enum -381 à -390
 *
 * Define os demais erros previstos nas funções.\n
 * Faixa -381 à -390.
 */

enum GER_Erro_Outros{
    ERRO_CAMPOS_OVERFLOW    = -381, /**< <b>(-381)</b> Etiqueta atingiu o valor máximo de campos.*/
    ERRO_LIMPAR             = -382 /**< <b>(-382)</b> Parâmetro keepProps inválido.*/
};


/*****************************************************************************/
/*****************************************************************************/


/*
    Descricao:      Arquivo de cabecalho com as definicoes de possiveis erros para a biblioteca E1_SAT
    Autor:          Bruno Cruz
    Data:           27/06/2019
*/


/****************************************************************/
// FAIXA DOS CODIGOS DE ERRO: -391 ~ -590 (MANTER RESERVADO!!!) //
/****************************************************************/


/**
 * @ingroup g1
 * @brief The SAT_Erro_Generico enum -391 à -400
 *
 * Define erros genericos da biblioteca e1_sat
 * Esses erros não estão vinculados especificamente a uma função.
 */
enum SAT_Erro_Generico{
    ARQUIVO_NAO_PODE_SER_ABERTO     = -391, /**< <b>(-391)</b> Arquivo esta sendo usado por outro processo ou não existe.*/
    CNPJ_INVALIDO                   = -392, /**< <b>(-392)</b> CNPJ tem mais de 14 dígitos.*/
    CPF_INVALIDO                    = -393, /**< <b>(-393)</b> CPF inválido ou tem mais de 11 dígitos.*/
    SIGNAC_INVALIDA                 = -394, /**< <b>(-394)</b> Assinatura comercial possui mais de 344 dígitos.*/
    NUMERO_CAIXA_INVALIDO           = -395, /**< <b>(-395)</b> Numero de caixa menor que 1 ou maior que 999.*/
    ARQUIVO_NAO_ENCONTRADO          = -396, /**< <b>(-396)</b> Arquivo xml não existe no caminho especificado.*/
    NOME_DESTINARIO_INVALIDO        = -397, /**< <b>(-397)</b> Nome do destinatario tem menos que 2 dígitos ou mais que 60.*/
    CHAVES_CFE_INVALIDAS            = -398, /**< <b>(-398)</b> Validação de chaves falharam e não foi possivel atualizar o arquvio. */
    RESPOSTA_SESSAO_FISCAL_INVALIDA = -399, /**< <b>(-399)</b> Não foi possivel consultar a Ultima sessão fiscal. */
    ERRO_CONSULTAR_SAT              = -400  /**< <b>(-400)</b> Não foi possivel realizar ConsultarSat, equipamento desconectado ou em processamento. */
};

/**
 * @ingroup g1
 * @brief The SAT_Erro_Cupom_Cancelamento enum -401 à -410
 */
enum SAT_Erro_Cupom_Cancelamento{
    CHAVE_CANCELAMENTO_INVALIDA = -401 /**< <b>(-401)</b> Chave de cancelamento com tamanho diferente de 47 ou não iniciado com prefixo CFe.*/

};

/**
 * @ingroup g1
 * @brief The SAT_Erro_Cupom_Venda enum -411 à -420
 */
enum SAT_Erro_Cupom_Venda{
    VERSAO_DADOS_ENT_INVALIDO   = -411, /**< <b>(-411)</b> Versão do leiaute para o xml é inválido.*/
    IE_INVALIDO                 = -412, /**< <b>(-412)</b> Inscrição estadual tem mais que 14 dígitos no leiaute 0.08 ou 12 no leiaute 0.07.*/
    IM_INVALIDO                 = -413, /**< <b>(-413)</b> Inscrição municipal tem mais de 15 dígitos.*/
    INDRATISSQN_INVALIDO        = -414, /**< <b>(-414)</b> Indicador de rateio do desconto diferente S ou N.*/
    CREGTRIBISSQN_INVALIDO      = -415 /**< <b>(-415)</b> Tamanho diferente de 1 para Regime Especial de Tributação do ISSQN.*/
};

/**
 * @ingroup g1
 * @brief The SAT_Erro_Dados_Entrega enum -421 à -430
 */
enum SAT_Erro_Dados_Entrega{
    LOGRADOURO_INVALIDO     = -421, /**< <b>(-421)</b> Logradouro fora dos limites de 2 à 60 caracteres.*/
    NUMERO_INVALIDO         = -422, /**< <b>(-422)</b> Numero fora dos limites de 1 à 60 caracteres.*/
    COMPLEMENTO_INVALIDO    = -423, /**< <b>(-423)</b> Complemento fora dos limites de 1 à 60 caracteres.*/
    BAIRRO_INVALIDO         = -424, /**< <b>(-424)</b> Bairro fora dos limites de 1 à 60 caracteres.*/
    MUNICIPIO_INVALIDO      = -425, /**< <b>(-425)</b> Municipio fora dos limites de 2 à 60 caracteres.*/
    UF_INVALIDO             = -426 /**< <b>(-426)</b> UF possui tamanho diferente de 2 caracteres.*/
};

/**
 * @ingroup g1
 * @brief The SAT_Erro_Dados_Produto enum -431 à -450
 */
enum SAT_Erro_Dados_Produto{
    CODIGO_PRODUTO_INVALIDO         = -431, /**< <b>(-431)</b> Código do produto fora dos limites de 1 à 60 caracteres.*/
    GTIN_INVALIDO                   = -432, /**< <b>(-432)</b> Valor não possui 8, 12, 13 ou 14 caracteres.*/
    DESCRICAO_PRODUTO_INVALIDA      = -433, /**< <b>(-433)</b> Descrição do produto vazia ou com mais de 120 caracteres.*/
    NCM_INVALIDO                    = -434, /**< <b>(-434)</b> NCM diferente de 2 ou 8 caracteres.*/
    CEST_INVALIDO                   = -435, /**< <b>(-435)</b> Código especificador da substituição tributária não possui 7 dígitos.*/
    CFOP_INVALIDO                   = -436, /**< <b>(-436)</b> Código fiscal de operações e prestações não possui 4 caracteres.*/
    UNIDADE_COMERCIAL_INVALIDA      = -437, /**< <b>(-437)</b> Unidade comercial vazia ou com mais de 6 dígitos .*/
    QUANTIDADE_COMERCIAL_INVALIDA   = -438, /**< <b>(-438)</b> Quantidade comercial deve ter de 5 à 15 digitos com 4 casas decimais separadas por ponto.*/
    VALOR_UNITARIO_INVALIDO         = -439, /**< <b>(-439)</b> Valor unitário de comercialização deve ter de 3 à 15 digitos com 3 casas decimais separadas por ponto.*/
    REGRA_CALCULO_INVALIDA          = -440, /**< <b>(-440)</b> Regra de cálculo diferente de T ou A.*/
    VALOR_DESCONTO_INVALIDO         = -441, /**< <b>(-441)</b> Valor de desconto sobre item deve ter de 3 à 15 digitos com 2 casas decimais separadas por ponto.*/
    VALOR_ACRESCIMO_INVALIDO        = -442, /**< <b>(-442)</b> Outras despesas acessórias sobre item deve ter de 3 à 15 digitos com 2 casas decimais separadas por ponto.*/
    NUMERO_ITEM_INVALIDO            = -443 /**< <b>(-443)</b> Valor para nItem inválido.*/
};

/**
 * @ingroup g1
 * @brief The SAT_Erro_Dados_OBS_Fisco enum 451 à 460
 */
enum SAT_Erro_Dados_OBS_Fisco{
    IDENTIFICADOR_CAMPO_INVALIDO    = -451, /**< <b>(-451)</b> Identificador do campo deve ter entre 1 e 20 dígitos.*/
    CONTEUDO_CAMPO_INVALIDO         = -452, /**< <b>(-452)</b> Conteudo do campo deve ter entre 1 e 60 dígitos.*/
    QUANTIDADE_ELEMENTO_EXCEDIDA    = -454 /**< <b>(-454)</b> O limite de observações para o fisco são de 10 elementos obsFiscoDet.*/
};

/**
 * @ingroup g1
 * @brief The SAT_Erro_Imposto enum -461 à 490
 */
enum SAT_Erro_Imposto{
    VITEM12741_INVALIDO                     = -461, /**< <b>(-461)</b> Valor aproximado dos tributos do Produto ou serviço(Lei 12741/12) deve ter de 3 à 15 digitos com 2 casas decimais separadas por ponto..*/
    ORIGEM_MERCADORIA_INVALIDA              = -462, /**< <b>(-462)</b> Tamanho diferente de 1 caractere.*/
    CST_INVALIDO                            = -463, /**< <b>(-463)</b> Tributação do ICMS deve ter tamanho igual a 2.*/
    ALIQUOTA_IMPOSTO_INVALIDA               = -464, /**< <b>(-464)</b> Aliquota do imposto deve ter de 3 a 5 dígitos com 2 casas decimais.*/
    CSOSN_INVALIDO                          = -465, /**< <b>(-465)</b> Código de Situação da Operação(Simples Nacional) deve ter 3 caracteres.*/
    BASE_CALCULO_INVALIDA                   = -466, /**< <b>(-466)</b> Base de calculo deve ter de 3 à 15 digitos com 2 casas decimais separadas por ponto.*/
    PERCENTUAL_ALIQUOTA_PIS_INVALIDA        = -467, /**< <b>(-467)</b> Aliquota do PIS deve ter 5 dígitos com 4 casas decimais separadas por ponto.*/
    QUANTIDADE_VENDIDA_PIS_INVALIDA         = -468, /**< <b>(-468)</b> Quantidade vendida deve ter de 5 à 16 digitos com 4 casas decimais separadas por ponto.*/
    VALOR_ALIQUOTA_PIS_INVALIDA             = -469, /**< <b>(-469)</b> Aliquota do PIS em reais deve ter de 5 à 15 digitos com 4 casas decimais separadas por ponto.*/
    GRUPO_INVALIDO                          = -470, /**< <b>(-470)</b> Valor deve ser 0 ou 1*/
    PERCENTUAL_ALIQUOTA_COFINS_INVALIDA     = -471, /**< <b>(-471)</b> Aliquota COFINS deve ter de 3 a 5 dígitos com 2 casas decimais.*/
    QUANTIDADE_VENDIDA_COFINS_INVALIDA      = -472, /**< <b>(-472)</b> Quantidade vendida deve ter de 5 à 16 digitos com 4 casas decimais separadas por ponto.*/
    VALOR_ALIQUOTA_COFINS_INVALIDA          = -473, /**< <b>(-473)</b> Aliquota do COFINS em reais deve ter de 5 à 15 digitos com 4 casas decimais separadas por ponto.*/
    VALOR_DEDUCOES_ISSQN_INVALIDA           = -474, /**< <b>(-474)</b> Valor das deduções ISSQN deve ter de 3 à 15 digitos com 2 casas decimais separadas por ponto.*/
    ALIQUOTA_ISSQN_INVALIDA                 = -475, /**< <b>(-475)</b> Aliquota ISSQN deve ter 5 dígitos com 2 casas decimais separadas por ponto.*/
    CODIGO_MUNICIPIO_FATO_GERADOR_INVALIDO  = -476, /**< <b>(-476)</b> Código do município de ocorrência do fato gerador do ISSQN deve ter 7 dígitos.*/
    ITEM_LISTA_SERVICO_INVALIDO             = -477, /**< <b>(-477)</b> Item da lista de serviço deve ter tamanho igual a 5.*/
    CODIGO_TRIBUTACAO_ISSQN_INVALIDO        = -478, /**< <b>(-478)</b> Código de tributação deve ter tamanho igual a 20.*/
    NATUREZA_OPERACAO_INVALIDA              = -479, /**< <b>(-479)</b> Natureza da operação deve ter tamanho igual a 2.*/
    INDICADOR_INCETIVO_FISCAL_ISSQN_INVALIDO= -480 /**< <b>(-480)</b> Valores aceitos são 1 ou 2, sim ou não respectivamente.*/
};

/**
 * @ingroup g1
 * @brief The SAT_Erro_Informacao_Adicional_Produto enum -491 à -500
 */
enum SAT_Erro_Informacao_Adicional_Produto{
    INFORMACOES_ADICIONAIS_PRODUTO_INVALIDA = -491 /**< <b>(-491)</b> Valor informado tem mais que 500 caracteres.*/
};

/**
 * @ingroup g1
 * @brief The SAT_Erro_Total enum -501 à -510
 */
enum SAT_Erro_Total{
    VALOR_DESCONTO_SUBTOTAL_INVALIDO         = -501, /**< <b>(-501)</b> Valor de desconto sobre subtotal deve ter de 3 à 15 digitos com 2 casas decimais separadas por ponto.*/
    VALOR_ACRESCIMO_SUBTOTAL_INVALIDO        = -502, /**< <b>(-502)</b> Valor de acrescimo sobre subtotal deve ter de 3 à 15 digitos com 2 casas decimais separadas por ponto.*/
    VALOR_VCFELEI12741_INVALIDO              = -503 /**< <b>(-503)</b> Valor aproximado dos tributos do CFe-SAT deve ter de 3 à 15 digitos com 2 casas decimais separadas por ponto.*/
};

/**
 * @ingroup g1
 * @brief The SAT_Erro_Pagamento enum -511 à -520
 */
enum SAT_Erro_Pagamento{
    CODIGO_MEIO_PAGAMENTO_INVALIDO      = -511, /**< <b>(-511)</b> Código do meio de pagamento deve ter 2 dígitos.*/
    VALOR_MEIO_PAGAMENTO_INVALIDO       = -512, /**< <b>(-512)</b> Valor do Meio de Pagamento empregado para quitação do CF-edeve ter de 3 à 15 digitos com 2 casas decimais separadas por ponto.*/
    CREDENCIADORA_CARTAO_INVALIDO       = -513, /**< <b>(-513)</b> Credenciadora do cartão deve ter 3 dígitos*/
    QUANTIDADE_MEIO_PAGAMENTO_EXCEDIDA  = -514 /**< <b>(-514)</b> Número maximo de tags MP excedito. XML possui 10 tags MP.*/
};

/**
 * @ingroup g1
 * @brief The SAT_Erro_Informacao_Adicional enum -521 à -530
 */
enum SAT_Erro_Informacao_Adicional{
    TAMANHO_INFORMACOES_COMPLEMENTARES_INVALIDO = -521 /**< <b>(-521)</b> Tamanho maximo excedido. Deve possuir até 5000 caracteres*/
};


/*****************************************************************************/
/*****************************************************************************/


/*
    Descricao:      Arquivo de cabecalho com as definicoes de possiveis erros para a biblioteca E1_NFCe
    Autor:          Bruno Cruz
    Data:           28/07/2019
*/


/****************************************************************/
// FAIXA DOS CODIGOS DE ERRO: -591 ~ -790 (MANTER RESERVADO!!!) //
/****************************************************************/


enum NFCe_Erro_Generico{
    ARQUIVO_JSON_NAO_ENCONTRADO         =-591,
    ARQUIVO_JSON_NAO_PODE_SER_ABERTO    =-592,
    ARQUIVO_JSON_INVALIDO               =-593,
    NFCE_UF_INVALIDA                    =-594,
    NFCE_PRODUTO_NAO_ENCONTRADO         =-595,
};

enum NFCe_Erro_Abertura_Cupom{
    NFCE_CNF_INVALIDO                       =-601,
    NFCE_NATUREZA_OPERACAO_INVALIDA         =-602,
    NFCE_MODELO_INVALIDA                    =-603,
    NFCE_SERIE_INVALIDA                     =-604,
    NFCE_NNF_INVALIDA                       =-605,
    NFCE_TIPO_OPERACAO_INVALIDA             =-606,
    NFCE_DESTINO_OPERACAO_INVALIDO          =-607,
    NFCE_CODIGO_MUNICIPIO_ICMS_INVALIDO     =-608,
    NFCE_TP_IMPRESSAO_INVALIDA              =-609,
    NFCE_TP_EMISSAO_INVALIDA                =-610,
    NFCE_DIGITO_VERIFICADOR_INVALIDO        =-611,
    NFCE_FINALIDADE_EMISSAO_INVALIDA        =-612,
    NFCE_IND_CONSUMIDOR_FINAL_INVALIDA      =-613,
    NFCE_IND_PRESENCA_INVALIDA              =-614,
    NFCE_PROC_EMISSAO_INVALIDA              =-615,
    NFCE_VERSAO_APP_INVALIDA                =-616,
    NFCE_PARAMETRO_INVALIDO                 =-617,
    NFCE_IDLOCAL_INVALIDO                   =-618
};

enum NCFe_Erro_Identificador{
    NFCE_CNPJ_INVALIDO              =-620,
    NFCE_CPF_INVALIDO               =-621,
    NFCE_ID_ESTRANGEIRO_INVALIDO    =-622,
    NFCE_NOME_INVALIDO              =-623,
    NFCE_ID_IE_DESTINATARIO         =-624,
    NFCE_IE_INVALIDO                =-625,
    NFCE_INCRICAO_SUFRAMA_INVALIDA  =-626,
    NFCE_IM_INVALIDA                =-627,
    NFCE_EMAIL_INVALIDO             =-628
};

enum NFCe_Erro_Endereco{
    NFCE_LOGRADOURO_INVALIDO         =-630,
    NFCE_NUMERO_INVALIDO             =-631,
    NFCE_COMPLEMENTO_INVALIDO        =-632,
    NFCE_BAIRRO_INVALIDO             =-633,
    NFCE_CODIGO_MUNICIPIO_INVALIDO   =-634,
    NFCE_MUNICIPIO_INVALIDO          =-635,
    NFCE_CEP_INVALIDO                =-636,
    NFCE_CODIGO_PAIS_INVALIDO        =-637,
    NFCE_NOME_PAIS_INVALIDO          =-638,
    NFCE_FONE_INVALIDO               =-639,
};

enum NFCe_Erro_Frete{
    NFCE_MODALIDADE_FRETE_INVALIDA      =-650,
    NFCE_CNPJ_TRANSPORTADOR_INVALIDO    =-651,
    NFCE_CPF_TRANSPORTADOR_INVALIDO     =-652,
    NFCE_xNOME_TRANSPORTADOR_INVALIDO   =-653,
    NFCE_IE_TRANSPORTADOR_INVALIDO      =-654,
    NFCE_XENDER_TRANSPORTADOR_INVALIDO  =-655,
    NFCE_xMUN_TRANSPORTADOR_INVALIDO    =-656,
    NFCE_UF_TRANSPORTADOR_INVALIDO      =-657
};

enum NFCe_Erro_Pagamento{
    NFCE_FORMA_PAGAMENTO_INVALIDA           =-660,
    NFCE_VALOR_PAGAMENTO_INVALIDO           =-661,
    NFCE_BANDEIRA_CARTAO_INVALIDA           =-662,
    NFCE_CODIGO_AUTORIZACAO_INVALIDO        =-663,
    NFCE_CNPJ_CREDENCIADORA_INVALIDO        =-664,
    NFCE_INDICADOR_FORMA_PAGAMENTO_INVALIDO =-665,
    NFCE_TIPO_INTEGRACAO_INVALIDA           =-666,
    NFCE_VALOR_TROCO_INVALIDO               =-667
};

enum NFCE_Erro_Produto{
    NFCE_CODIGO_PRODUTO_INVALIDO                =-670,
    NFCE_CODIGO_EAN_INVALIDO                    =-671,
    NFCE_DESCRICAO_PRODUTO_INVALIDA             =-672,
    NFCE_NCM_PRODUTO_INVALIDO                   =-673,
    NFCE_NVE_INVALIDO                           =-674,
    NFCE_CEST_INVALIDO                          =-675,
    NFCE_INDESCALA_INVALIDO                     =-676,
    NFCE_CNPJ_FABRICANTE_INVALIDO               =-677,
    NFCE_CBENEF_INVALIDO                        =-678,
    NFCE_EXTIPI_PRODUTO_INVALIDO                =-679,
    NFCE_CFOP_PRODUTO_INVALIDO                  =-680,
    NFCE_UNIDADE_COMERCIAL_PRODUTO_INVALIDA     =-681,
    NFCE_QUANTIDADE_COMERCIAL_PRODUTO_INVALIDA  =-682,
    NFCE_VALOR_UNI_COMERCIAL_PRODUTO_INVALIDO   =-683,
    NFCE_VALOR_PRODUTO_INVALIDO                 =-684,
    NFCE_GTIN_PRODUTO_INVALIDO                  =-685,
    NFCE_UNIDADE_TRIBUTAVEL_INVALIDA            =-686,
    NFCE_QUANTIDADE_TRIBUTAVEL_INVALIDA         =-687,
    NFCE_VALOR_UNI_TRIBUTACAO_INVALIDO          =-688,
    NFCE_VALOR_FRETE_INVALIDO                   =-689,
    NFCE_VALOR_SEGURO_INVALIDO                  =-690,
    NFCE_VALOR_DESCONTO_INVALIDO                =-691,
    NFCE_VALOR_OUTRO_INVALIDO                   =-692,
    NFCE_INDICADOR_TOTAL_INVALIDO               =-693,
};

/*! \ingroup g1
 * \brief The NFCE_Erro_Impostos enum
 */
enum NFCE_Erro_Impostos{
    NFCE_TOTAL_TRIBUTOS_INVALIDO                        =-700, /**< <b>-700</b> */
    NFCE_CST_INVALIDO                                   =-701, /**< <b>-701</b> */
    NFCE_VBC_INVALIDO                                   =-702, /**< <b>-702</b> */
    NFCE_ALIQUOTA_IMPOSTO_INVALIDA                      =-703, /**< <b>-703</b> */
    NFCE_VALOR_IMPOSTO_INVALIDO                         =-704, /**< <b>-704</b> */
    NFCE_QBCPROD_INVALIDA                               =-705, /**< <b>-705</b> */
    NFCE_VALOR_ALIQUOTA_PISCOFINS_INVALIDA              =-706, /**< <b>-706</b> */

    NFCE_CODIGO_MUNICIPIO_FATO_GERADOR_ISSQN_INVALIDO   =-707, /**< <b>-707</b> */
    NFCE_ITEM_SERVICO_INVALIDO                          =-708, /**< <b>-708</b> */
    NFCE_VALOR_DEDUCAO_ISSQN_INVALIDO                   =-709, /**< <b>-709</b> */
    NFCE_VOUTRO_ISSQN_INVALIDO                          =-710, /**< <b>-710</b> */
    NFCE_VALOR_DESCONTO_INCONDICIONADO_INVALIDO         =-711, /**< <b>-711</b> */
    NFCE_VALOR_DESCONTO_CONDICIONADO_INVALIDO           =-712, /**< <b>-712</b> */
    NFCE_VALOR_REDENCAO_ISS_INVALIDO                    =-713, /**< <b>-713</b> */
    NFCE_INDICADOR_EXIGIBILIDADE_ISS_INVALIDO           =-714, /**< <b>-714</b> */
    NFCE_CODIGO_SERVICO_ISSQN_INVALIDO                  =-715, /**< <b>-715</b> */
    NFCE_CODIGO_MUNICIPIO_ISSQN_INVALIDO                =-716, /**< <b>-716</b> */
    NFCE_CODIGO_PAIS_ISSQN_INVALIDO                     =-717, /**< <b>-717</b> */
    NFCE_NUMERO_PROCESSO_INVALIDO                       =-718, /**< <b>-718</b> */
    NFCE_INDICADOR_INCENTIVO_FISCAL                     =-719, /**< <b>-719</b> */

    NFCE_IPI_CLASSE_ENQUADRAMENTO_INVALIDA              =-720, /**< <b>-720</b> */
    NFCE_IPI_CNPJ_PRODUTO_INVALIDO                      =-721, /**< <b>-721</b> */
    NFCE_IPI_CODIGO_SELO_INVALIDO                       =-722, /**< <b>-722</b> */
    NFCE_IPI_QUANTIDADE_SELO_INVALIDO                   =-723, /**< <b>-723</b> */
    NFCE_IPI_CODIGO_ENQUADRAMENTO_INVALIDO              =-724, /**< <b>-724</b> */
    NFCE_IPI_QUANTIDADE_TOTAL_TRIBUTACAO_INVALIDA       =-725, /**< <b>-725</b> */
    NFCE_IPI_VALOR_UNIDADE_TRIBUTAVEL_INVALIDA          =-726, /**< <b>-726</b> */

    NFCE_II_VALOR_DESPESAS_ADUANEIRAS_INVALIDO          =-727, /**< <b>-727</b> */
    NFCE_II_VALOR_IOF_INVALIDO                          =-728, /**< <b>-728</b> */

    NFCE_ICMS_N11_ORIG_INVALIDA                         =-729, /**< <b>-729</b> */
    NFCE_ICMS_N13_MODBC_INVALIDA                        =-730, /**< <b>-730</b> */
    NFCE_ICMS_N14_PREDBC_INVALIDO                       =-731, /**< <b>-731</b> */
    NFCE_ICMS_N16_PICMS_INVALIDO                        =-732, /**< <b>-732</b> */
    NFCE_ICMS_N16A_VICMSOP_INVALIDO                     =-733, /**< <b>-733</b> */
    NFCE_ICMS_N16B_PDIF_INVALIDO                        =-734, /**< <b>-734</b> */
    NFCE_ICMS_N17_VICMS_INVALIDO                        =-735, /**< <b>-735</b> */
    NFCE_ICMS_N17a_VBCFCP_INVALIDO                      =-736, /**< <b>-736</b> */
    NFCE_ICMS_N17b_PFCP_INVALIDO                        =-737, /**< <b>-737</b> */
    NFCE_ICMS_N17c_VFCP_INVALIDO                        =-738, /**< <b>-738</b> */
    NFCE_ICMS_N18_MODBCST_INVALIDO                      =-739, /**< <b>-739</b> */
    NFCE_ICMS_N19_PMVAST_INVALIDO                       =-740, /**< <b>-740</b> */
    NFCE_ICMS_N20_PREDBCST_INVALIDO                     =-741, /**< <b>-741</b> */
    NFCE_ICMS_N21_VBCST_INVALIDO                        =-742, /**< <b>-742</b> */
    NFCE_ICMS_N22_PICMSST_INVALIDO                      =-743, /**< <b>-743</b> */
    NFCE_ICMS_N23_VICMSST_INVALIDO                      =-744, /**< <b>-744</b> */
    NFCE_ICMS_N27A_VICMSDESON_INVALIDO                  =-745, /**< <b>-745</b> */
    NFCE_ICMS_N28_MOTDESICMS_INVALIDO                   =-746, /**< <b>-746</b> */
    NFCE_ICMS_N26_VBCSTRET_INVALIDO                     =-747, /**< <b>-747</b> */
    NFCE_ICMS_N26a_PST_INVALIDO                         =-748, /**< <b>-748</b> */
    NFCE_ICMS_N26b_VICMSSUBUSTITUTO_INVALIDO            =-749, /**< <b>-749</b> */
    NFCE_ICMS_N25_PBCOP_INVALIDO                        =-750, /**< <b>-750</b> */
    NFCE_ICMS_N24_UFST_INVALIDO                         =-751, /**< <b>-751</b> */
    NFCE_ICMS_N27_VICMSSTRET_INVALIDO                   =-752, /**< <b>-752</b> */
    NFCE_ICMS_N27a_NFCE_ICMS_N27_INVALIDO               =-753, /**< <b>-753</b> */
    NFCE_ICMS_N27b_PFCPSTRET_INVALIDO                   =-754, /**< <b>-754</b> */
    NFCE_ICMS_N27d_VFCPSTRET_INVALIDO                   =-755, /**< <b>-755</b> */

    NFCE_ICMS_N31_VBCSTDEST_INVALIDO                    =-755, /**< <b>-755</b> */
    NFCE_ICMS_N32_VICMSSTDEST_INVALIDO                  =-756, /**< <b>-756</b> */
    NFCE_ICMS_N12A_CSOSN_INVALIDO                       =-757, /**< <b>-757</b> */
    NFCE_ICMS_N29_PCREDSN_INVALIDO                      =-758, /**< <b>-758</b> */
    NFCE_ICMS_N30_VCREDICMSSN_INVALIDO                  =-759, /**< <b>-759</b> */
    NFCE_ICMS_N34_PREDBCEFET_INVALIDO                   =-760, /**< <b>-760</b> */
    NFCE_ICMS_N35_VBCEFET_INVALIDO                      =-761, /**< <b>-761</b> */
    NFCE_ICMS_N36_PICMSEFET_INVALIDO                    =-761, /**< <b>-761</b> */
    NFCE_ICMS_N37_VICMSEFET_INVALIDO                    =-762  /**< <b>-762</b> */
};

enum NFCE_Erro_Volumes{

    NFCE_VOLUMES_X27_QVOL_INVALIDO                   =-770,
    NFCE_VOLUMES_X28_ESP_INVALIDO                    =-771,
    NFCE_VOLUMES_X29_MARCA_INVALIDO                  =-772,
    NFCE_VOLUMES_X30_NVOL_INVALIDO                   =-773,
    NFCE_VOLUMES_X31_PESOL_INVALIDO                  =-774,
    NFCE_VOLUMES_X32_PESOB_INVALIDO                  =-775,
    NFCE_VOLUMES_NAO_E_POSSIVEL_INSERIR              =-776,
    NFCE_VOLUMES_CHAVE_TRANSPORTE_NAO_EXISTE         =-777
};

enum NFCE_Erro_Lacres{

    NFCE_LACRES_X34_NLACRE_INVALIDO                  =-780,
    NFCE_LACRES_CHAVE_VOLUMES_NAO_EXISTE             =-781,
    NFCE_LACRES_INDEX_DO_VOLUME_NAO_ENCONTRADO       =-782
};


/*****************************************************************************/
/*****************************************************************************/


/*
    Descricao:      Arquivo de cabecalho com as definicoes de possiveis erros para a biblioteca E1_Balanca
    Autor:          Rodrigo Angelo
    Data:           14/09/2020
*/


/****************************************************************/
// FAIXA DOS CODIGOS DE ERRO: -791 ~ -890 (MANTER RESERVADO!!!) //
/****************************************************************/


/** \ingroup g1
 * @brief The Bal_Erro_Balanca enum -791 à -800
 *
 * Define os erros relativos à escolha/troca do modelo de balança.\n
 * Faixa -791 à -800.
 */

enum Bal_Erro_Balanca {
    BAL_CONEXAO_ATIVA           = -791, /**< <b>(-791)</b> Tentativa de trocar a balança sem encerrar sua conexão.*/
    BAL_BALANCA_EM_USO          = -792, /**< <b>(-792)</b> Tentativa de trocar o modelo de balança pelo próprio modelo em uso no momento.*/
    BAL_BALANCA_INVALIDA        = -793, /**< <b>(-793)</b> Modelo de balança informado na função <i>ConfigurarModeloBalanca()</i> é inválido.*/
    BAL_NENHUMA_BALANCA_EM_USO  = -794 /**< <b>(-794)</b> Nenhuma balança foi configurada para uso na biblioteca.*/
};

/** \ingroup g1
 * @brief The Bal_Erro_Protocolo enum -801 à -810
 *
 * Define os erros relativos à escolha/troca do protocolo de comunicação.\n
 * Faixa -801 à -810.
 */

enum Bal_Erro_Protocolo {
    BAL_PROTOCOLO_INVALIDO                              = -801, /**< <b>(-801)</b> Protocolo informado na função <i>ConfigurarProtocoloComunicacao()</i> é inválido.*/
    BAL_PROTOCOLO_EM_USO                                = -802, /**< <b>(-802)</b> Tentativa de trocar o protocolo pelo próprio protocolo em uso no momento.*/
    BAL_PROTOCOLO_NAO_SUPORTADO                         = -803, /**< <b>(-803)</b> Protocolo informado na função <i>ConfigurarProtocoloComunicacao()</i> não é suportado pela balança em uso.*/
    BAL_PROTOCOLO_NAO_SUPORTADO_PELAS_CONFIGS_SERIAIS   = -804, /**< <b>(-804)</b> Protocolo informado na função <i>ConfigurarProtocoloComunicacao()</i> não é suportado pela combinação de parâmetros configurados na conexão serial.*/
    BAL_NENHUM_PROTOCOLO_EM_USO                         = -805 /**< <b>(-805)</b> Nenhum protocolo foi configurado para uso com a balança.*/
};

/** \ingroup g1
 * @brief The Bal_Erro_Abertura enum -811 à -820
 *
 * Define os erros relativos à abertura de conexão serial.\n
 * Faixa -811 à -820.
 */

enum Bal_Erro_Abertura {
    BAL_BAUDRATE_NAO_SUPORTADO                          = -811, /**< <b>(-811)</b> Baudrate informado na função <i>AbrirSerial()</i> não é suportado pela balança em uso.*/
    BAL_LENGTH_NAO_SUPORTADO                            = -812, /**< <b>(-812)</b> Length informado na função <i>AbrirSerial()</i> não é suportado pela balança em uso.*/
    BAL_PARITY_NAO_SUPORTADO                            = -813, /**< <b>(-813)</b> Parity informado na função <i>AbrirSerial()</i> não é suportado pela balança em uso.*/
    BAL_STOPBITS_NAO_SUPORTADO                          = -814, /**< <b>(-814)</b> Stopbits informado na função <i>AbrirSerial()</i> não é suportado pela balança em uso.*/

    BAL_BAUDRATE_INVALIDO                               = -815, /**< <b>(-815)</b> Baudrate inválido para conexão serial.*/
    BAL_LENGTH_INVALIDO                                 = -816, /**< <b>(-816)</b> Length inválido para conexão serial.*/
    BAL_PARITY_INVALIDO                                 = -817, /**< <b>(-817)</b> Parity inválido para conexão serial.*/
    BAL_STOPBITS_INVALIDO                               = -818, /**< <b>(-818)</b> Stopbits inválido para conexão serial.*/

    BAL_COMBINACAO_DE_PARAMETROS_INVALIDA               = -819, /**< <b>(-819)</b> Os parâmetros informados na função <i>AbrirSerial()</i>, individualmente, são suportados pela balança em uso; porém, esses parâmetros não estão em uma combinação correta, suportada pela balança.*/
    BAL_CONFIGS_SERIAIS_NAO_SUPORTADAS_PELO_PROTOCOLO   = -820 /**< <b>(-820)</b> Combinação de parâmetros informados na função <i>AbrirSerial()</i> não é suportada pelo protocolo em uso.*/
};

/** \ingroup g1
 * @brief The Bal_Erro_Outros enum -821 à -830
 *
 * Define os demais erros previstos na biblioteca E1_Balanca.\n
 * Faixa -821 à -830.
 */

enum Bal_Erro_Outros {
    BAL_QTD_LEITURAS_INVALIDA                   = -821, /**< <b>(-821)</b> Valor não-positivo passado ao parâmetro <i>qtdLeituras</i> da função <i>LerPeso()</i> ou <i>LerPreco()</i>.*/
    BAL_COMANDO_NAO_SUPORTADO_PELA_BALANCA      = -822, /**< <b>(-822)</b> Função chamada não é suportada pela balança em uso.*/
    BAL_COMANDO_NAO_SUPORTADO_PELO_PROTOCOLO    = -823, /**< <b>(-823)</b> Função chamada não é suportada pelo protocolo em uso.*/
    BAL_PRECO_INVALIDO                          = -824, /**< <b>(-824)</b> Parâmetro <i>preco</i> da função <i>LerTotal()</i> está fora dos limites.*/
    BAL_FALHA_NA_LEITURA_DO_PESO                = -825, /**< <b>(-825)</b> Função <i>LerTotal()</i> falhou na leitura do peso sobre a balança.*/
    BAL_FALHA_AO_ENVIAR_PRECO                   = -826, /**< <b>(-826)</b> Função <i>LerTotal()</i> falhou ao enviar o preço à balança (protocolos #4 e #5).*/
    CHAMADA_NAO_PERMITIDA                       = -827 /**< <b>(-827)</b> Função interna.*/
};


/*****************************************************************************/
/*****************************************************************************/


/*
    Descricao:      Arquivo de cabecalho com as definicoes de possiveis erros para a biblioteca E1_PDF
    Autor:          Bruno Cruz
    Data:           25/05/2021
*/


/*****************************************************************/
// FAIXA DOS CODIGOS DE ERRO: -890 ~ -1200 (MANTER RESERVADO!!!) //
/*****************************************************************/


/** \ingroup g1
 * @brief The PDF_Error enum -890 à -900
 *
 * Define os possiveis erros para a biblioteca E1_PDF\n
 * Faixa -890 até -900.
 */
enum PDF_Error{
    ZINT_NAO_CARREGADA           = -890, /**< <b>(-890)</b> Dependência externa Zint.dll não foi carregada.*/
    ARQUIVO_NAO_FOI_ABERTO       = -891, /**< <b>(-891)</b> Função chamada não é suportada pela balança em uso.*/
    DIRETORIO_INVALIDO           = -892, /**< <b>(-892)</b> Diretorio inválido ou não existe.*/
    IMPRESSORA_NAO_E_VALIDA      = -893, /**< <b>(-893)</b> Impressora Padrão não esta válida ou disponivel para uso.*/
    FALHA_AO_CARREGAR_DOCUMENTO  = -894, /**< <b>(-894)</b> Falha ao carregar documento pdf a ser impresso.*/
    DOCUMENTO_NAO_EXISTE         = -895, /**< <b>(-895)</b> Documento nPdf não existe.*/
    DOCUMENTO_NAO_POSSUI_PAGINAS = -896, /**< <b>(-896)</b> Dcocumento Pdf não possui paginas ou esté em branco.*/
    IMAGEM_NAO_FOI_GERADA        = -897  /**< <b>(-897)</b> Falha na geração de imagem ára impressão dee pdf.*/
};


/*****************************************************************************/
/*****************************************************************************/


/*
    Descricao:      Arquivo de cabecalho com as definicoes de possiveis erros para a biblioteca E1_Bridge
    Autor:          Rodrigo Angelo
    Data:           25/10/2021
*/


/******************************************************************/
// FAIXA DOS CODIGOS DE ERRO: -1201 ~ -1300 (MANTER RESERVADO!!!) //
/******************************************************************/


/** \ingroup g1
 * @brief The Br_Erro_Config enum -1201 à -1210
 *
 * Define os erros relativos à configuração do E1_Bridge.\n
 * Faixa -1201 à -1210.
 */

enum Br_Erro_Config {
    BR_IP_TERMINAL_INVALIDO         = -1201, /**< <b>(-1201)</b> IP informado para o terminal não é um IPv4 válido.*/
    BR_PORTA_TRANSACAO_INVALIDA     = -1202, /**< <b>(-1202)</b> Porta de transação informada é inválida.*/
    BR_PORTA_STATUS_INVALIDA        = -1203, /**< <b>(-1203)</b> Porta de status informada é inválida.*/
    BR_PORTAS_IGUAIS                = -1204, /**< <b>(-1204)</b> Portas de transação e de status não são distintas.*/
    BR_TIMEOUT_INVALIDO             = -1205, /**< <b>(-1205)</b> Timeout informado não está entre 1 e 10 minutos.*/
    BR_IP_TERMINAL_NAO_INFORMADO    = -1206, /**< <b>(-1206)</b> IP do terminal não foi informado.*/
    BR_SENHA_NULL                   = -1207, /**< <b>(-1207)</b> Parâmetro senha não pode ser null.*/
    BR_SENHA_NAO_INFORMADA          = -1208, /**< <b>(-1208)</b> Senha do terminal não foi informada.*/
    BR_MESMA_CONFIG_SENHA           = -1209  /**< <b>(-1209)</b> Configuração de senha solicitada já está em uso.*/
};

/** \ingroup g1
 * @brief The Br_Erro_Param enum -1211 à -1230
 *
 * Define os erros relativos aos parâmetros usados nas funções do E1_Bridge.\n
 * Faixa -1211 à -1230.
 */

enum Br_Erro_Param {
    BR_VALOR_TOTAL_NULL             = -1211, /**< <b>(-1211)</b> Parâmetro valorTotal não pode ser null.*/
    BR_VALOR_TOTAL_NAN              = -1212, /**< <b>(-1212)</b> Parâmetro valorTotal não é um número.*/
    BR_VALOR_TOTAL_INVALIDO         = -1213, /**< <b>(-1213)</b> Parâmetro valorTotal está fora dos limites.*/
    BR_TIPO_CARTAO_INVALIDO         = -1214, /**< <b>(-1214)</b> Parâmetro tipoCartao inválido.*/
    BR_TIPO_FINANCIAMENTO_INVALIDO  = -1215, /**< <b>(-1215)</b> Parâmetro tipoFinanciamento inválido.*/
    BR_NUM_PARCELAS_INVALIDO        = -1216, /**< <b>(-1216)</b> Parâmetro numParcelas está fora dos limites.*/
    BR_NSU_NULL                     = -1217, /**< <b>(-1217)</b> Parâmetro nsu não pode ser null.*/
    BR_NSU_INVALIDO                 = -1218, /**< <b>(-1218)</b> Parâmetro nsu inválido.*/
    BR_DATA_HORA_NULL               = -1219, /**< <b>(-1219)</b> Parâmetro dataHora não pode ser null.*/
    BR_DATA_HORA_INVALIDA           = -1220, /**< <b>(-1220)</b> Parâmetro dataHora não representa uma data válida.*/
    BR_OPERACAO_INVALIDA            = -1221, /**< <b>(-1221)</b> Parâmetro operacao inválido.*/
    BR_ERRO_ABERTURA_ARQUIVO        = -1222, /**< <b>(-1222)</b> Erro ao criar/abrir o arquivo informado pelo parâmetro path.*/
    BR_ERRO_ESCREVER_ARQUIVO        = -1223, /**< <b>(-1223)</b> Erro ao gravar o retorno no arquivo informado pelo parâmetro path.*/
    BR_OUTPUT_NULL                  = -1224, /**< <b>(-1224)</b> Parâmetro retorno não pode ser null.*/
    BR_ID_TRANSACAO_INVALIDO        = -1225, /**< <b>(-1225)</b> Parâmetro idTransacao está fora dos limites.*/
    BR_PDV_NULL                     = -1226, /**< <b>(-1226)</b> Parâmetro pdv não pode ser null.*/
    BR_PDV_INVALIDO                 = -1227, /**< <b>(-1227)</b> Parâmetro pdv inválido.*/
    BR_TIPO_CUPOM_INVALIDO          = -1228, /**< <b>(-1228)</b> Parâmetro tipoCupom inválido.*/
    BR_XML_NULL                     = -1229, /**< <b>(-1229)</b> Parâmetro xml não pode ser null.*/
    BR_XML_INVALIDO                 = -1230  /**< <b>(-1230)</b> Parâmetro xml inválido.*/
};

/** \ingroup g1
 * @brief The Br_Erro_Status enum -1231 à -1240
 *
 * Define os erros relativos à função de status do E1_Bridge.\n
 * Faixa -1231 à -1240.
 */

enum Br_Erro_Status {
    BR_STATUS_EM_ANDAMENTO  = -1231, /**< <b>(-1231)</b> Já existe uma consulta de status em andamento.<br>A aplicação pode escolher outro terminal ou aguardar por alguns segundos e tentar novamente.*/
    BR_ERRO_CONECTAR_STATUS = -1232, /**< <b>(-1232)</b> Erro ao se conectar com o serviço de status.<br>O usuário deve ser instruído a validar se a aplicação está em execução no terminal e se a rede está ok no computador e no SmartPOS.*/
    BR_ERRO_LEITURA_STATUS  = -1233, /**< <b>(-1233)</b> Erro ao ler o retorno do status.*/
    BR_STATUS_NAO_RETORNADO = -1234  /**< <b>(-1234)</b> Serviço de status não retornou nenhum dado.*/
};

/** \ingroup g1
 * @brief The Br_Erro_Transacao enum -1241 à -1250
 *
 * Define os erros relativos às funções de transação do E1_Bridge.\n
 * Faixa -1241 à -1250.
 */

enum Br_Erro_Transacao {
    BR_TRANSACAO_EM_ANDAMENTO   = -1241, /**< <b>(-1241)</b> Já existe uma transação em andamento.<br>A aplicação pode escolher outro terminal ou aguardar por alguns segundos e tentar novamente.*/
    BR_ERRO_CONECTAR_TRANSACAO  = -1242, /**< <b>(-1242)</b> Erro ao se conectar com o serviço de transação.<br>O usuário deve ser instruído a validar se a aplicação está em execução no terminal e se a rede está ok no computador e no SmartPOS.*/
    BR_ERRO_ENVIO_TRANSACAO     = -1243, /**< <b>(-1243)</b> Erro ao enviar dados da transação ao terminal.*/
    BR_ERRO_CONFIRMAR_TRANSACAO = -1244, /**< <b>(-1244)</b> Terminal não confirmou o recebimento da transação.*/
    BR_ERRO_LEITURA_TRANSACAO   = -1245, /**< <b>(-1245)</b> Erro ao ler o retorno da transação.*/
    BR_TRANSACAO_NAO_RETORNADA  = -1246, /**< <b>(-1246)</b> Serviço de transação não retornou nenhum dado.*/
    BR_TELA_BLOQUEADA           = -1247  /**< <b>(-1247)</b> Terminal está com a tela bloqueada, não é possível iniciar a transação.*/
};

/** \ingroup g1
 * @brief The Br_Erro_Param_Extras enum -1251 à -1300
 *
 * Define mais erros relativos aos parâmetros usados nas funções do E1_Bridge.\n
 * Faixa -1251 à -1300.
 */

enum Br_Erro_Param_Extras {
    BR_ASS_QRCODE_NULL      = -1251, /**< <b>(-1251)</b> Parâmetro assQRCode não pode ser null.*/
    BR_ASS_QRCODE_INVALIDO  = -1252, /**< <b>(-1252)</b> Parâmetro assQRCode inválido.*/
    BR_CSC_NULL             = -1253, /**< <b>(-1253)</b> Parâmetro csc não pode ser null.*/
    BR_CSC_INVALIDO         = -1254, /**< <b>(-1254)</b> Parâmetro csc inválido.*/

    BR_PARAMETRO_NULL       = -1255, /**< <b>(-1255)</b> Parâmetro parametro não pode ser null.*/
    BR_PARAMETRO_INVALIDO   = -1256  /**< <b>(-1256)</b> Parâmetro parametro inválido.*/
};


/*****************************************************************************/
/*****************************************************************************/


/*
    Descricao:      Erros genericos, que podem ocorrer em qualquer modulo da E1
    Autor:          Rodrigo Angelo
    Data:           25/06/2021
*/


/******************************************************************/
// FAIXA DOS CODIGOS DE ERRO: -9000 ~ -9998 (MANTER RESERVADO!!!) //
/******************************************************************/


/** \ingroup g1
 * @brief The UTIL_Erro_Interno enum -9000 à -9099
 *
 * Define os erros internos previstos na biblioteca E1.\n
 * Faixa -9000 à -9099.
 */

// Erros da classe Utilidades
enum UTIL_Erro_Interno {
    // Erros do metodo getFormattedFileName
    UTIL_DATA_INVALIDA          = -9000, /**< <b>(-9000)</b> Erro ao calcular a data do sistema.*/
    UTIL_ERRO_CAMINHO_ABSOLUTO  = -9001, /**< <b>(-9001)</b> Erro ao calcular o caminho absoluto do diretório raiz.*/
    UTIL_EXTENSAO_INVALIDA      = -9002, /**< <b>(-9002)</b> Extensão inválida para o arquivo.*/
    UTIL_TIPO_INVALIDO          = -9003, /**< <b>(-9003)</b> Tipo de arquivo inválido.*/
    UTIL_ERRO_GERAR_ESTRUTURA   = -9004, /**< <b>(-9004)</b> Erro ao gerar a estrutura de diretórios.*/
    UTIL_ERRO_ACESSAR_ESTRUTURA = -9005  /**< <b>(-9005)</b> Erro ao acessar a estrutura gerada.*/
};


#endif // CODIGOERRO_H
