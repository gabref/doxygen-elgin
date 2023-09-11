#ifndef EXPORTAFUNCOES_H
#define EXPORTAFUNCOES_H


#include "e1_impressora_global.h"

#ifdef __linux__
    #define STDCALL
    #define TCHAR char
    #define LPSTR const char*
#elif _WIN32
    #include "windows.h"
    #define TCHAR TCHAR
    #define LPSTR LPSTR
    #define STDCALL __stdcall
#endif

/*
Descrição:  Classe principal que exporta as funções da biblioteca e1_impressora
Autor:      Bruno Cruz
Data:       08/01/2018
*/


/*
 * MAPA DA DOCUMENTACAO
 * Arvore simples para esquematizar como a documentacao esta' organizada
 *
 * EDIT 05/08/2021: Movido para ../Documentacao/README.txt
 *                  Manter apenas no README para evitar inconsistencias
 */


extern "C"{
/*! \defgroup g0 Impressoras
 */

/** \defgroup M1 Térmica
  * \ingroup g0
  *
  * \brief Fornece funções para integração com impressoras ELGIN.
  *
  * Essa biblioteca fornece diversas funções de integração com as impresoras não Fiscais ELGIN.\n
  * Os modelos de impressoras compatíveis com essa biblioteca são:\n
  * > Impressora i7\n
  * > Impressora i7 Plus\n
  * > Impressora i8\n
  * > Impressora i9\n
  * > Impressora ix\n
  * > Impressora Fitpos\n
  * > Impressora BK-T681\n
  *
  * As impressoras de outras marcas compativeis são
  * > Bematech MP-4200\n
  * > Bematech MP-2800\n
  * > Daruma DR800\n
  * > Epson TM-T20\n
  * > Epson TM-T20X\n
  * > Control ID Print ID Touch\n
  * > Tanca TP-650\n
  * > Dimep D-PRINT DUAL\n
  *
  * Convenções usadas nas chamadas das funções da biblioteca:\n
  *<b>Windows</b>\n
  *  > __stdcall
  *<b>Linux</b>\n
  *  > __cdecl\n
*/

    // Funcoes da impressora
    /*! \ingroup M1
     * \brief Abre conexão com a impressora.
     *
     * \param tipo - Parâmetro do tipo numérico que define o tipo de comunicação que será estabelecido.\n
     * Conforme tabela a seguir:
     * Valor | Referência
     * ----- | -----------
     * 1     | USB
     * 2     | RS232
     * 3     | TCP/IP
     * 4     | Bluetooth
     * 5     | Impressoras acopladas <br> (Android)
     *\n
     *
     * \param modelo - Parâmetro tipo caractere que especifica o modelo para conexão.\n
     * Conforme lista:
     * > <b>Valores</b>\n
     * > i7\n
     * > i7 Plus\n
     * > i8\n
     * > i9\n
     * > ix\n
     * > Fitpos\n
     * > BK-T681\n
     * > MP-4200\n
     * > MP-2800\n
     * > DR800\n
     * > TM_T20\n
     * > TM-T20X\n
     * > Print ID Touch\n
     * > TP-650\n
     * > D-PRINT DUAL\n
     *
     * * NOTA: Daruma DR800 homologada com TABELA DE COMANDOS 3 com FIRMWARE 03.20.04
     * * OBS: Esse parâmetro é desconsiderado se o <b>tipo</b> da impressora for o <b>5</b>, podendo ser definido como "" (string vazia).
     *
     * \param conexao - Parâmetro tipo caractere que define detalhes de conexão.\n
     * Detalhes de conexão:
     * Referência | Valor exemplo
     * :--------- | ---------------
     * USB        | USB
     * RS232      | COM2
     * TCP/IP     | 192.168.0.20
     * Bluetooth  | AA:BB:CC:DD:EE:FF
     *\n
     *
     * * OBS: Esse parâmetro é desconsiderado se o <b>tipo</b> da impressora for o <b>5</b>, podendo ser definido como "" (string vazia).
     *
     * \param parametro - Parâmetro do tipo numérico auxiliar para a conexão com a impressora.\n
     * Utilizado para especificar <b>baudrate</b> ou <b>porta de comunicação TCP/IP.</b>\n
     *
     * * OBS: Quando a conexão estabelecida for USB ou Bluetooth esse parâmetro é desconsiderado e pode ser definido como valor 0.\n
     * * OBS: Esse parâmetro é desconsiderado se o <b>tipo</b> da impressora for o <b>5</b>, podendo ser definido como 0 (zero).
	 *
     *
     * \return
     * O retorno da função é do tipo numérico.\n
     * A função bem sucedida deve retornar 0.\n
     * * Para mais informações consulte #GER_Erro_Conexao, #GER_Erro_Conexao_Serial, #GER_Erro_Conexao_USB ou #GER_Erro_Conexao_TCP\n
     * * OBS: Caso a biblioteca encontre um hardware diferente do esperado a conexão será negada e o valor -5 será retornado.
     *
     *
     *
     */

    ///@cond
    E1_IMPRESSORASHARED_EXPORT STDCALL
    ///@endcond
    int AbreConexaoImpressora(int tipo, const char* modelo, const char* conexao, int parametro);

    /*! \ingroup M1
     * \brief Fecha conexão com a impressora.
     *
     * Finaliza a conexão que foi estabelecida em #AbreConexaoImpressora.
     *
     * \return
     * O retorno da função é do tipo numérico.\n
     * A função bem sucedida deve retornar 0.\n
     * * Para mais informações sobre retorno consulte #GER_Erro_Conexao.
     *
     */

    ///@cond
    E1_IMPRESSORASHARED_EXPORT STDCALL
    ///@endcond
    int FechaConexaoImpressora();

    /*! \ingroup M1
     * \brief EspacamentoEntreLinhas
     * Altera o espaçamento entre linhas na impressão (line mode).
     * \param tamanho
     * Define espaçamento. Valor entre 1 e 255.
     *
     * \return
     * Retorno numérico que indica se a operação foi concluída com sucesso.\n
     * A função bem sucedida deve retornar 0.\n
     * * Consulte <b>Códigos de erro</b> para mais informações.\n
     */
    ///@cond
    E1_IMPRESSORASHARED_EXPORT STDCALL
    ///@endcond
    int EspacamentoEntreLinhas(int tamanho);

    /*! \ingroup M1
     * \brief Envia informações de texto para o buffer da impressora.
     *
     * As informações são impressas quando o buffer atinge o limite, quando é executada a\n
     * função #AvancaPapel ou quando recebe um byte 10 (Line Feed – LF).\n
     * Caso nenhuma dessas opções seja executada um próximo comando pode apagar os dados do buffer.
     *
     * \param dados - Parâmetro tipo caractere com a informação que será enviada ao buffer de impressão.\n
     * \param posicao - Parâmetro tipo numérico que define a posição do texto a ser impresso.\n
     *
     * Os possíveis valores são:
     * Valor  | Posição
     * ------ | ---------
     * 0      | Esquerda
     * 1      | Centro
     * 2      | Direira
     * \n
     *
     * \param stilo - Parâmetro numérico que altera o estilo do texto impresso. \n
     * O texto pode ser alterado entre os seguintes estilos:
     * Valor | Descrição
     * ----- | ------------
     * 0     | Fonte A
     * 1     | Fonte B
     * 2     | Sublinhado
     * 4     | Modo reverso
     * 8     | Negrito
     *
     * * Para habilitar mais de um estilo deve-se realizar a somar dos valores.
     *\n
     *
     * \param tamanho - Define o tamanho do texto a ser impresso.\n
     * O texto pode ser aumentado em até 6 vezes na sua largura e altura.
     * Os valores definidos são:
     * Valor | Descrição
     * ----- | :----------
     * 0     | 1 x na altura e largura
     * 1     | 2 x na altura
     * 2     | 3 x na altura
     * 3     | 4 x na altura
     * 4     | 5 x na altura
     * 5     | 6 x na altura
     * 6     | 7 x na altura
     * 7     | 8 x na altura
     * 16    | 2 x na largura
     * 32    | 3 x na largura
     * 48    | 4 x na largura
     * 64    | 5 x na largura
     * 80    | 6 x na largura
     * 96    | 7 x na largura
     * 112   | 8 x na largura
     *
     * * Para aumentar largura e altura deve-se somar os valores.
     * * Apenas os modelos i7 e i9 suportam aumento de até 8 vezes. As demais atingem no máximo 6.
     * \n
     *
     * \return
     * O valor de retorno dessa função é um número indicando a quantidade de informação escrita no buffer.
     *  * Para mais informações sobre retorno consulte #IMP_Erro_Escrita_Impressora.
     *
     * > * Informações em buffer serão apagadas caso a função #InicializaImpressora seja executada.
     *
     */

    ///@cond
    E1_IMPRESSORASHARED_EXPORT STDCALL
    ///@endcond
    int ImpressaoTexto(const char* dados, int posicao, int stilo, int tamanho);

    /*! \ingroup M1
     * \brief Realiza o corte do papel.
     * * OBS: A impressora do SmartPOS não suporta este método, uma vez que não existe guilhotina
     * nesse modelo. Este método funciona corretamente nas demais impressoras térmicas, conectadas
     * ao SmartPOS.
     *
     * \param avanco - Parâmetro numérico que indica o quanto o papel deve avançar antes do corte.
     * \return
     * Retorno numérico que indica se a operação foi concluída com sucesso.\n
     * A função bem sucedida deve retornar 0.\n
     * * Consulte <b>Códigos de erro</b> para mais informações.\n
     *
     *
     */

    ///@cond
    E1_IMPRESSORASHARED_EXPORT STDCALL
    ///@endcond
    int Corte(int avanco);

    /*! \ingroup M1
     * \brief Realiza o corte total do papel.
     * * OBS: Algumas impressoras não suporta este método devido a limitação do hardware.\n
     *  As impressoras com tal limitação irão executar o corte parcial.
     *
     * \param avanco - Parâmetro numérico que indica o quanto o papel deve avançar antes do corte.
     * \return
     * Retorno numérico que indica se a operação foi concluída com sucesso.\n
     * A função bem sucedida deve retornar 0.\n
     * * Consulte <b>Códigos de erro</b> para mais informações.\n
     *
     *
     */

    ///@cond
    E1_IMPRESSORASHARED_EXPORT STDCALL
    ///@endcond
    int CorteTotal(int avanco);

    /*! \ingroup M1
     * \brief Impressão de QRCode
     *
     * Essa função imprime o código QRCode com possibilidade de variação de tamanho e nível de correção.
     * \param dados - Conjunto de informações que irão compor o QRCode.
     * \param tamanho - Tamanho do QRCode.\n
     * > Valores entre 1 e 6.
     * \param nivelCorrecao - Define o nível de correção a ser configurado para o QRCode.\n
     * Conforme tabela a seguir:
     * Valor  | Nível de correção
     * ------ | --------------------
     * 1      | 7%
     * 2      | 15%
     * 3      | 25%
     * 4      | 30%
     * \return
     * O retorno é numérico.\n
     * A função bem sucedida deve retornar 0.\n
     * * Para mais informações sobre retorno consulte #IMP_Erro_QRCode.
     *
     * > * O QRCode pode não ser impresso caso a área de impressão seja ultrapassada.\n
     * > Isso pode acontecer dependendo da quantidade de caracteres, tamanho do QRCode e nível de correção.
     *
     *
     */

    ///@cond
    E1_IMPRESSORASHARED_EXPORT STDCALL
    ///@endcond
    int ImpressaoQRCode(const char* dados, int tamanho, int nivelCorrecao);

    /*! \ingroup M1
     * \brief Impressão de código PDF417.
     *
     * Realiza a impressão de PDF417, com possibilidade de variação de tamanho e nível de correção.
     *
     * \param numCols - Parâmetro do tipo numérico que define o número de colunas.\n
     * \n
     * Valores válidos:
     * > Números entre 0 e 30 (0, 1, 2, ..., 30).\n
     * \n
     *
     * * OBS: O valor 0 significa processamento automático.\n
     * \n
     *
     * \param numRows - Parâmetro do tipo numérico que define o número de linhas.\n
     * \n
     * Valores válidos:
     * > Números entre 3 e 90 (3, 4, 5, ..., 90) ou 0.\n
     * \n
     *
     * * OBS: O valor 0 significa processamento automático.\n
     * \n
     *
     * \param width - Parâmetro do tipo numérico que define a largura do módulo, em pontos.\n
     * \n
     * Valores válidos:
     * > Números entre 2 e 8 (2, 3, 4, ..., 8).\n
     * \n
	 *
	 * * OBS: Se o <b>tipo</b> de conexão estiver definido como <b>5</b>, este parâmetro definirá a
	 * largura <i>preferencial</i> do módulo, em <b>pixels</b>, e os valores válidos serão todos os
	 * números inteiros positivos (0, 1, 2, ...).\n
     * \n
     *
     * \param height - Parâmetro do tipo numérico que define a altura da linha, multiplicando
     * o valor definido pela largura do módulo (configurada em <i>width</i>).\n
     * \n
     * Valores válidos:
     * > Números entre 2 e 8 (2, 3, 4, ..., 8).\n
     * \n
	 *
	 * * OBS: Se o <b>tipo</b> de conexão estiver definido como <b>5</b>, este parâmetro definirá a
	 * altura <i>preferencial</i> do módulo, em <b>pixels</b>, e os valores válidos serão todos os
	 * números inteiros positivos (0, 1, 2, ...).\n
     * \n
     *
     * \param errCorLvl - Parâmetro do tipo numérico que define o nível de correção de erro.\n
     * \n
     * Valores válidos:
     * Valor | Nível de Correção
     * ----- | -------
     * 0     | Nível 0
     * 1     | Nível 1
     * 2     | Nível 2
     * 3     | Nível 3
     * 4     | Nível 4
     * 5     | Nível 5
     * 6     | Nível 6
     * 7     | Nível 7
     * 8     | Nível 8
     * \n
     *
     * \param options - Parâmetro do tipo numérico que define a opção para PDF417.\n
     * \n
     * Valores válidos:
     * Valor | Tipo
     * ----- | -------
     * 0     | Standard
     * 1     | Truncated
     * \n
     *
     * \param dados - Parâmetro do tipo caractere que define o código a ser impresso.\n
     * \n
     * Valores válidos:
     * > Qualquer string de dados imprimíveis; máximo de 65532 caracteres.\n
     * \n
     *
     * \return
     * O retorno da função é do tipo numérico.\n
     * A função bem-sucedida deve retornar 0.\n
     *
     * * Para mais informações, consulte #IMP_Erro_PDF417
     *
     */

    ///@cond
    E1_IMPRESSORASHARED_EXPORT STDCALL
    ///@endcond
    int ImpressaoPDF417(int numCols, int numRows, int width, int height, int errCorLvl, int options, const char *dados);

    /*! \ingroup M1
     * \brief Impressão de código de barras.
     *
     * Realiza a impressão de código de barras.
     * \param tipo - Define o modelo do código de barras a ser impresso.
     * Segue tabela de tipos disponíveis:
     * | Valor | Modelo           | Quantidade de dados       | Caracteres                                   | Regras
     * | ----- | :--------------: | :-----------------------: | :------------------------------------------: | :----------------------------------: |
     * | 0     | UPC-A            | 11 ou 12                  | 0 até 9                                      | -                                    |
     * | 1     | UPC-E            | 6, 7, 8, 11 ou 12         | 0 até 9                                      | Quantidade = 6 se 1º != 0            |
     * | 2     | JAN13 / EAN 13   | 12 ou 13                  | 0 até 9                                      | -                                    |
     * | 3     | JAN8 / EAN 8     | 7 ou 8                    | 0 até 9                                      | -                                    |
     * | 4     | CODE 39          | 1 até 255                 | 0 até 9, A até Z\n SP, $, %, *, +, -, \, .   | -                                    |
     * | 5     | ITF              | 2 até 255 (números pares) | 0 até 9                                      | -                                    |
     * | 6     | CODE BAR         | 1 até 255                 | 0 até 9, A até D, a até d\n $, +, -, ., /, : | 1º e nº devem ser A até D ou a até d |
     * | 7     | CODE 93          | 1 até 255                 | 00H até 7FH                                  | -                                    |
     * | 8     | CODE 128         | 2 até 255                 | 00H até 7FH                                  | 1º = {, 2º = A, B ou C               |
     *
     * \param dados - Informação que compõe o código.
     * \param altura - Altura do código de barras.
     * Valor de 1 até 255.
     * \param largura - Define a largura do código de barras.
     * Valor de 1 até 6.
     * > Se valor definido ultrapassar área de impressão o código não será impresso.
     * \param HRI - Define a posição de impressão do conteúdo do código de barras.
     * > 1 - Acima do código.\n
     * > 2 - Abaixo do código.\n
     * > 3 - Ambos.\n
     * > 4 - Não impresso.\n
     * \return
     * O retorno é numérico.\n
     * A função bem sucedida deve retornar 0.\n
     * * Para mais informações sobre retorno consulte #IMP_Erro_CodigoBarras.
     *
     */

    ///@cond
    E1_IMPRESSORASHARED_EXPORT STDCALL
    ///@endcond
    int ImpressaoCodigoBarras(int tipo, const char* dados, int altura, int largura, int HRI);

    /*! \ingroup M1
     * \brief Imprime informações no buffer e avança o papel.
     * \param linhas - Indica o quanto o papel deve avançar.
     * \return
     * O retorno é numérico.\n
     * A função bem sucedida deve retornar 0.\n
     * * Para mais informações sobre retorno consulte <b>Códigos de erro.</b>
     *
     *
     */

    ///@cond
    E1_IMPRESSORASHARED_EXPORT STDCALL
    ///@endcond
    int AvancaPapel(int linhas);

    /*! \ingroup M1
     * \brief Obtém o status da impressora.
     *
     * Essa função disponibiliza o status de gaveta, tampa, sensor de papel e do ejetor.\n
     * * Essa função pode ter limitações de alguns modelos, conforme indicado na tabela a seguir:\n
     * |                        | Gaveta | Tampa | Sensor de pouco papel | Sensor de papel presente | Ejetor |
     * | :-----------------     | :----: | :---: | :-------------------: | :----------------------: | :----: |
     * | <b>i7</b>              |   x    |   x   |                       |             x            |        |
     * | <b>i8</b>              |   x    |   x   |                       |             x            |        |
     * | <b>i9</b>              |   x    |   x   |           x           |             x            |        |
     * | <b>ix</b>              |   x    |   x   |           x           |             x            |        |
     * | <b>Fitpos</b>          |        |   x   |           x           |             x            |        |
     * | <b>BK-T681</b>         |        |   x   |           x           |             x            |   x    |
     * | <b>MP-4200</b>         |   x    |   x   |           x           |             x            |        |
     * | <b>MP-2800</b>         |   x    |   x   |                       |             x            |        |
     * | <b>DR800</b>           |   x    |   x   |           x           |             x            |        |
     * | <b>TM-T20</b>          |   x    |   x   |                       |             x            |        |
     * | <b>Print ID Touch</b>  |   x    |   x   |                       |             x            |        |
     * | <b>SmartPOS</b>        |        |       |                       |             x            |        |
     * | <b>Mini PDV M8</b>     |   x    |       |                       |             x            |        |
     *
     *
     * \param param - Parâmetro tipo numérico para indicar qual status deve ser retornado.\n
     * Os possíveis valores são:
     * > 1 - Gaveta\n
     * > 2 - Tampa\n
     * > 3 - Papel\n
     * > 4 - Ejetor\n
     * > 5 - Geral\n
     *
     * \return
     * Retorno tipo numérico de acordo com a descrição a seguir:
     *  - <b>1- Status da gaveta.</b>
     *      + 1- Indica gaveta aberta.
     *      + 2- indica gaveta fechada.
     *  - <b>2- Status de tampa.</b>
     *      + 3- Indica tampa aberta.
     *      + 4- Indica tampa fechada.
     *  - <b>3- Status de papel.</b>
     *      + 5- Indica que o papel está presente e não está próximo do fim.
     *      + 6- Indica papel próximo do fim.
     *      + 7- Indica papel ausente.
     *  - <b>4- Retorna o status do ejetor.</b>
     *      + 8- Sem papel no ejetor.
     *      + 9- Com papel no ejetor.
     *  - <b>5- Retorna status geral.</b>\n
     * Essa função trabalha com bits de um byte para indicar os status.\n
     * Conforme descrição abaixo:
     * | BIT |   STATUS   |           DESCRIÇÃO             |
     * | :-: | :--------: | :-----------------------------: |
     * |  0  |   LIGADO   | Indica gaveta aberta            |
     * |  ^  | DESLIGADO  | Indica gaveta fechada           |
     * |  1  |   LIGADO   | Indica Tampa aberta             |
     * |  ^  | DESLIGADO  | Indica Tampa fechada            |
     * |  2  |   LIGADO   | Indica pouco papel              |
     * |  ^  | DESLIGADO  | Indica papel normal             |
     * |  3  |   LIGADO   | Indica papel ausente            |
     * |  ^  | DESLIGADO  | Indica papel presente           |
     * |  4  |   LIGADO   | Indica papel presente no ejetor |
     * |  ^  | DESLIGADO  | Indica papel ausente no ejetor  |
     * |  5  | DESLIGADO  | Fixo                            |
     * |  6  | DESLIGADO  | Fixo                            |
     * |  7  | DESLIGADO  | Fixo                            |
     *
     *
     * * Para mais informações sobre retorno consulte #IMP_Erro_Status ou #IMP_Erro_Leitura_Impressora.
     *
     */

    ///@cond
    E1_IMPRESSORASHARED_EXPORT STDCALL
    ///@endcond
    int StatusImpressora(int param);

    /*! \ingroup M1
     * \brief Abre gavetas Elgin.
	 *
     * Essa função usa parâmetros padrões para abertura de gavetas Elgin.
     * Para abrir gavetas de marcas diferentes use #AbreGaveta e envie os parâmetros necessários para abertura.
	 *
	 * \note
	 * O SmartPOS não suporta este método, uma vez que esse dispositivo não tem conector RJ-11.
     * Se a gaveta for conectada à outra impressora térmica e esta, por sua vez, estiver conectada ao
     * SmartPOS, o método funcionará corretamente.
     *
	 * \warning
	 * Para utilização desta função no MiniPDV M8 e M10 se faz necessário que o aplicativo solicite a permissão de armazenamento ao usuário\n
	 * ou que o usuário acesse as configurações do android, na sessão de permissões do aplicativo e habilite a opção de armazenamento.
	 *
	 *
     * \return
     * O retorno é numérico.\n
     * A função bem sucedida deve retornar 0.\n
     * * Para mais informações sobre retorno consulte #IMP_Erro_Abertura_Gaveta.
     *
     */

    ///@cond
    E1_IMPRESSORASHARED_EXPORT STDCALL
    ///@endcond
    int AbreGavetaElgin();

    /*! \ingroup M1
     * \brief Abre gaveta
     *
     * Essa função abre gavetas de acordo com os parâmetros fornecidos.
     * \param pino - Indicação do pino a ser acionado.\n
     * > Os valores possíveis são 0 ou 1.
     * \param ti - Tempo de inicialização do pulso.\n
     * > Valores possíveis são 1 até 255.
     * \param tf - Tempo de desativação do pulso.\n
     * > Valores possíveis são 1 até 255.
	 *
	 * \note
	 * O SmartPOS não suporta este método, uma vez que esse dispositivo não tem conector RJ-11.
     * Se a gaveta for conectada à outra impressora térmica e esta, por sua vez, estiver conectada ao
     * SmartPOS, o método funcionará corretamente.
     *
	 * \warning
	 * Para utilização desta função no MiniPDV M8 e M10 se faz necessário que o aplicativo solicite a permissão de armazenamento ao usuário\n
	 * ou que o usuário acesse as configurações do android, na sessão de permissões do aplicativo e habilite a opção de armazenamento.
	 *
     *
     * \return
     * O retorno é numérico.\n
     * A função bem sucedida deve retornar 0.\n
     * * Para mais informações sobre retorno consulte #IMP_Erro_Abertura_Gaveta.
     *
     */

    ///@cond
    E1_IMPRESSORASHARED_EXPORT STDCALL
    ///@endcond
    int AbreGaveta(int pino, int ti, int tf);

    /*! \ingroup M1
     * \brief Inicializa a impressora para novas tarefas.
     *
     * Essa função inicializa a impressora para novas tarefas, redefine as configurações para o padrão da impressora
     * e apaga as informações em buffer.
     * \return
     * O retorno é numérico.\n
     * A função bem sucedida deve retornar 0.\n
     * * Para mais informações sobre retorno consulte <b>Códigos de erro</b>.
     *
     */

    ///@cond
    E1_IMPRESSORASHARED_EXPORT STDCALL
    ///@endcond
    int InicializaImpressora();

    /*! \ingroup M1
     * \brief Define a posição do conteúdo a ser impresso.
     * * OBS: As impressoras do SmartPOS e do Mini PDV M8 suportam parcialmente este método; nas
	 * demais impressoras térmicas, conectadas nesses dispositivos, este método funciona completamente.
     *
     * \param posicao - Parâmetro tipo numérico para indicar a posição.\n
     * Os valores possíveis são:
     * Valor | Descrição
     * ----- | ------------
     * 0     | Esquerda
     * 1     | Centro
     * 2     | Direita
     *
     * \n
     * \return
     * O retorno é numérico\n
     * A função bem sucedida deve retornar 0.\n
     * * Para mais informações sobre retorno consulte #IMP_Erro_Escrita_Impressora.
     *
     *
     */

    ///@cond
    E1_IMPRESSORASHARED_EXPORT STDCALL
    ///@endcond
    int DefinePosicao(int posicao);

    /*! \ingroup M1
     * \brief Emite sinal sonoro.
     * * OBS: O SmartPOS e o Mini PDV M8 não suportam este método; contudo, este método funciona
     * corretamente nas demais impressoras térmicas, conectadas nesses dispositivos.
     *
     * Emite sinal sonoro na impressora. Algumas impressoras não estão habilitadas para emitir sinal sonoro.
     * \param qtd - Define quantidade de sinais emitidos.\n
     * > Esse valor deve ser entre 1 e 63.
     * \param tempoInicio - Define o tempo em que o sinal deve ficar ativo.
     * \param tempoFim - Define o tempo entre um sinal e outro.\n
     * > Valor de tempo deve ser de 1 à 25. Esse valor é multiplicado por 100 e passado em milisegundos para função.
     * \return
     * O retorno é numérico.\n
     * A função bem sucedida deve retornar 0.\n
     * * Para mais informações sobre retorno consulte #IMP_Erro_Emissao_Sinal_Sonoro.
     *
     */

    ///@cond
    E1_IMPRESSORASHARED_EXPORT STDCALL
    ///@endcond
    int SinalSonoro(int qtd, int tempoInicio, int tempoFim);

    /*! \ingroup M1
     * \brief Envia comandos ESCPOS direto para a porta de comunicação.
     * @note OBS: Este método apresenta algumas diferenças no ambiente Android - consulte
	 * sua documentação em Módulos > Android > Módulos > Impressora Térmica > DirectIO.
     *
     * Função de despejo de comandos na porta de comunicação. Essa função também recebe dados da porta de comunicação.
     * \param writeData - Sequência de comandos que devem ser enviados para a porta de comunicação.
     * \param writeNum - Quantidade de comandos enviados e que serão escritos.
     * \param readData - Alocação de memória que receberá os dados de retorno caso seja necessário.
     * \param readNum - Quantidade de dados que se espera ler. Após a execução da função,\n
     * essa variável deve indicar a quantidade de dados lidos da porta. Para\n
     * evitar a leitura da porta esse parâmetro deve estar em ZERO (0).
     * \return
     * O retorno é numérico.\n
     * A função bem sucedida deve retornar 0.\n
     * * Para mais informações sobre retorno consulte #IMP_Erro_Leitura_Impressora.
     */

    ///@cond
    E1_IMPRESSORASHARED_EXPORT STDCALL
    ///@endcond
    int DirectIO(unsigned char* writeData, unsigned int writeNum, unsigned char* readData, unsigned int* readNum);

    /*! \ingroup M1
     * \brief Imprime imagem carregada em memória.
     *
     * Essa função utiliza do par de chaves para imprimir a imagem carregada em memória.\n
     * O upload da imagem é feito através do aplicativo Elgin Utility.
     * \param key - Par de chaves identificador da imagem.\n
     *              Valores entre (char)32 e (char)126.\n
     *
     * * <b>Nota:</b> Se a função for usada no SmartPOS ou no Mini PDV M8, este parâmetro recebe o
     * <i>caminho</i>, relativo ao armazenamento interno do dispositivo, em que a
     * imagem a ser impressa se encontra.\n\n
     * 
     * Exemplo: o valor <b>Download/Figura.bmp</b>, passado neste parâmetro, imprime
     * o arquivo <b>Figura.bmp</b>, localizado no diretório <b>Download</b> (no
     * armazenamento interno).
     *
     * \param scala - Tamanho da impressão, podendo ser 1 ou 2 para normal e duplicado, respectivamente.
     *
     * \return
     * O retorno é numérico.\n
     * A função bem sucedida deve retornar 0.\n
     * * Para mais informações sobre o retorno consulte #IMP_Erro_Imagem.
     *
     */

    ///@cond
    E1_IMPRESSORASHARED_EXPORT STDCALL
    ///@endcond
    int ImprimeImagemMemoria(const char* key, int scala);


    // Funções da integração com SAT
    /*! \ingroup M1
     * \brief Imprime Danfe SAT.
     *
     * Essa função recebe o XML de retorno da venda do SAT, valida o conteúdo, constrói o Danfe e realiza a impressão de acordo com
     * a especificação da SEFAZ SP.
     * \param dados - Conteúdo do XML de retorno da venda do SAT\n
     * ou\n
     * Caminho para arquivo com dados do SAT prefixado com "path=", ex:\n
     * path=C:/Resposta SAT/CFe35210130197161000935590008544130085892910578.xml
     *
     * \param param - Parâmetro do tipo numérico para ativar bits que modificam o cupom a ser impresso.\n
     * \n
     * Os bits disponíveis e seus respectivos efeitos no cupom (quando ativados) são descritos a seguir:
     * Bit | Valor inteiro | Efeito no cupom
     * --- | ------------- | ---------------
     * 0   | 1             | Impressão do logo no cabeçalho
     * 1   | 2             | Extrato reduzido
     * 2   | 4             | Cupom em ambiente de teste
     * 6   | 64            | Registro de item com desconto ou acréscimo <br> e variações no grupo totais
     * 7   | 128           | Imprime usando novo layout
     * 8   | 256           | Ativa separadores no novo layout
     * \n
     *
     * O valor passado ao parâmetro deve ser a soma dos valores inteiros correspondentes aos bits desejados.\n
     * O valor 0 não ativa nenhum bit e imprime o cupom padrão.\n
     *
     * \return
     * O retorno é numérico.\n
     * A função bem sucedida deve retornar 0.\n
     * * Para mais informações sobre retorno consulte #IMP_Erro_ValidacaoXMLSAT ou #IMP_Erro_ValidacaoXML.
     *
     * Caso o XML apresente erros a função retornará a linha na qual encontrou o erro de acordo com XSD de validação.\n
     * Informações que não estejam presentes no XML serão desconsideradas.
     *
     *
     */

    ///@cond
    E1_IMPRESSORASHARED_EXPORT STDCALL
    ///@endcond
    int ImprimeXMLSAT(const char* dados, int param);

    /*! \ingroup M1
     * \brief Imprime Danfe de cancelamento SAT.
     *
     * Essa função recebe o XML de retorno da operação de cancelamento e os dados de assinatura do QRCode de venda, valida as
     * informações, constrói o Danfe e realiza impressão de acordo com a especificação da SEFAZ SP.
     * \param dados - Conteúdo do XML de cancelamento retornado pelo SAT\n
     * ou\n
     * Caminho para arquivo com dados do SAT prefixado com "path=", ex:\n
     * path=C:/Resposta SAT/CFe35210130197161000935590008544130085892910578.xml
     *
     * \param assQRCode - Assinatura do QRCode retornado na operação de Venda. Essa informação é necessária porque o XML de retorno
     * da operação de venda não a contém.
     *
     * \param param - Parâmetro do tipo numérico para ativar bits que modificam o cupom a ser impresso.\n
     * \n
     * Os bits disponíveis e seus respectivos efeitos no cupom (quando ativados) são descritos a seguir:
     * Bit | Valor inteiro | Efeito no cupom
     * --- | ------------- | ---------------
     * 0   | 1             | Impressão do logo no cabeçalho
     * 6   | 64            | Imprime usando novo layout
     * 7   | 128           | Ativa separadores no novo layout
     * \n
     *
     * O valor passado ao parâmetro deve ser a soma dos valores inteiros correspondentes aos bits desejados.\n
     * O valor 0 não ativa nenhum bit e imprime o cupom padrão.\n
     *
     * \return
     * O retorno é numérico.\n
     * A função bem sucedida deve retornar 0.\n
     * * Para mais informações sobre retorno consulte #IMP_Erro_ValidacaoXMLSAT ou #IMP_Erro_ValidacaoXML.
     *
     * Caso o XML apresente erros a função retornará a linha na qual encontrou o erro de acordo com XSD de validação.\n
     * Informações que não estejam presentes no XML serão desconsideradas.
     *
     *
     */

    ///@cond
    E1_IMPRESSORASHARED_EXPORT STDCALL
    ///@endcond
    int ImprimeXMLCancelamentoSAT(const char* dados, const char* assQRCode, int param);

    //Funções de integração com NFCe
    /*! \ingroup M1
     * \brief Imprime o Danfe NFCe
     *
     * Essa função recebe o conteúdo do XML de venda do NFCe, valida o conteúdo, constrói o Danfe e realiza a impressão.
     * \param dados - Conteúdo do XML retornado pela venda\n
     * ou\n
     * Caminho para arquivo com dados da NFCe prefixado com "path=", ex:\n
     * path=C:/Resposta NFCe/33180705481336000137651000000916401000005909-nfce.xml
     * \param indexcsc - Identificador do CSC (Código de Segurança do Contribuinte no Banco de Dados da SEFAZ).
     * > Deve ser informado sem os “0” (zeros) não significativos. A identificação do CSC corresponde à ordem do\n
     * > CSC no banco de dados da SEFAZ, não confundir com o próprio CSC.
     * \param csc - Código de Segurança do Contribuinte.
     * > Corresponde a um código de segurança alfanumérico (16 a 36 bytes) de conhecimento apenas da Secretaria \n
     * > da Fazenda da Unidade Federada do emitente e do próprio contribuinte. Anteriormente, o código de segurança\n
     * > CSC era chamado de “Token”.
     *
     * \param param - Parâmetro do tipo numérico para ativar bits que modificam o cupom a ser impresso.\n
     * \n
     * Os bits disponíveis e seus respectivos efeitos no cupom (quando ativados) são descritos a seguir:
     * Bit | Valor inteiro | Efeito no cupom
     * --- | ------------- | ---------------
     *  0  | 1             | Impressão de extrato resumido
     *  1  | 2             | Utilização do EAN 13 no código dos produtos
     *  2  | 4             | Impressão completa da descrição dos produtos
     *  3  | 8             | Impressão do logotipo da empresa carregado em memória
     *  4  | 16            | Impressão do cupom de homologação
     *  5  | 32            | Redução do espaço de impressão do cupom
     *  6  | 64            | Utilização de separadores de sessão para o cupom
     *  7  | 128           | Impressão do IE no cabeçalho do cupom
     *  8  | 256           | Impressão do número sequencial para cada item
     *  9  | 512           | Impressão em uma via para Danfe em contingência
     * 10  | 1024          | Impressão de acréscimos/descontos por item
     * \n
     *
     * O valor passado ao parâmetro deve ser a soma dos valores inteiros correspondentes aos bits desejados.\n
     * O valor 0 não ativa nenhum bit e imprime o cupom padrão.\n
     *
     * \return
     * O retorno é numérico.\n
     * A função bem sucedida deve retornar 0.\n
     * * Para mais informações sobre retorno consulte #IMP_Erro_ValidacaoXMLNFCe ou #IMP_Erro_ValidacaoXML.
     *
     */

    ///@cond
    E1_IMPRESSORASHARED_EXPORT STDCALL
    ///@endcond
    int ImprimeXMLNFCe(const char* dados, int indexcsc, const char* csc, int param);


    /*! \ingroup M1
     * \brief ImprimeXMLCancelamentoNFCe
     * Essa função recebe o conteúdo do XML de cancelamento do NFCe, valida o conteúdo, constrói o Danfe e realiza a impressão.
     * \param dados - Conteúdo do XML retornado no processo de cancelamento\n
     * ou\n
     * Caminho para arquivo com dados da NFCe prefixado com "path=", ex:\n
     * path=C:/Resposta NFCe/Canc_nfce.xml
     * \param param - Reservado para customizações. Passar valor ZERO.
     * \return A função bem sucedida deve retornar 0.\n
     * * Para mais informações sobre retorno consulte #IMP_Erro_ValidacaoXMLNFCe ou #IMP_Erro_ValidacaoXML.
     */
    ///@cond
    E1_IMPRESSORASHARED_EXPORT STDCALL
    ///@endcond
    int ImprimeXMLCancelamentoNFCe(const char *dados, int param);

    /*! \ingroup M1
     * \brief Habilita Modo Página.
     *
     * Deve ser utilizado para dar início aos trabalhos em modo página.
     *
     * \return
     * O retorno é numérico.\n
     * A função bem sucedida deve retornar 0.\n
     * * Para mais informações sobre retorno consulte <b>Códigos de erro</b>.
     *
     */

    ///@cond
    E1_IMPRESSORASHARED_EXPORT STDCALL
    ///@endcond
    int ModoPagina();


    /*! \ingroup M1
     * \brief Define Direção de Impressão
     * * OBS: A impressora do SmartPOS não suporta este método; contudo, este método
     * funciona corretamente nas demais impressoras térmicas, conectadas ao SmartPOS.
     *
     * Função do modo página utilizada para definir a direção em que serão realizadas as impressões.
     *
     * \param direcao - Valor entre 0 e 3.\n
     * > 0 - Da esquerda para direita partindo do ponto superior esquerdo.\n
     * > 1 - De baixo para cima partindo do ponto inferior esquerdo.\n
     * > 2 - Da direita para esquerda partindo do ponto inferior direito.\n
     * > 3 - De cima para baixo partindo do ponto superior direito.\n
     *
     * \return
     * O retorno é numérico.\n
     * A função bem sucedida deve retornar 0.\n
     * * Para mais informações sobre retorno consulte <b>Códigos de erro</b>.
     *
     *
     */

    ///@cond
    E1_IMPRESSORASHARED_EXPORT STDCALL
    ///@endcond
    int DirecaoImpressao(int direcao);

    /*! \ingroup M1
     * \brief Define Área Impressão
     * * OBS: A impressora do SmartPOS não suporta este método; contudo, este método
     * funciona corretamente nas demais impressoras térmicas, conectadas ao SmartPOS.
     *
     * Função do modo página usada para definir o tamanho da área de impressão.
     *
     * \param oHorizontal - Define o ponto inicial horizontal.
     * > Valor em pontos entre 0 e a sua definição do parâmetro dHorizontal.
     * \param oVertical - Define ponto inicial na direção vertical.
     * > Valor em pontos entre 0 e a sua definição do parâmetro dVertical.
     * \param dHorizontal  - Define a dimensão na direção horizontal.
     * > Valor em pontos entre 0 e 580.
     * \param dVertical Define a dimensão da direção vertical.
     * > Valor em pontos entre 0 e 6640.
     *
     * \return
     * O retorno é numérico.\n
     * A função bem sucedida deve retornar 0.\n
     * * Para mais informações sobre retorno consulte #IMP_Erro_ModoPagina.
     *
     *
     *
     */

    ///@cond
    E1_IMPRESSORASHARED_EXPORT STDCALL
    ///@endcond
    int DefineAreaImpressao(int oHorizontal, int oVertical, int dHorizontal, int dVertical);

    /*! \ingroup M1
     * \brief Define Posição de Impressão Horizontal.
     *
     * Função do modo página usada para definir a posição de impressão Horizontal.
     *
     * \param nLnH - Define o ponto inicial horizontal.
     * > Valor em pontos entre 0 e 580.
     *
     * \return
     * O retorno é numérico.\n
     * A função bem sucedida deve retornar 0.\n
     * * Para mais informações sobre retorno consulte #IMP_Erro_ModoPagina.
     *
     *
     */

    ///@cond
    E1_IMPRESSORASHARED_EXPORT STDCALL
    ///@endcond
    int PosicaoImpressaoHorizontal(int nLnH);

    /*! \ingroup M1
     * \brief Define a Posição da Impressão Vertical.
     * * OBS: A impressora do SmartPOS não suporta este método; contudo, este método
     * funciona corretamente nas demais impressoras térmicas, conectadas ao SmartPOS.
     *
     * Função do modo página usada para definir a posição de impressão Vertical.
     *
     * \param nLnH - Define o ponto inicial Vertical.
     * > Valor em pontos entre 0 e 6640.
     *
     * \return
     * O retorno é numérico.\n
     * A função bem sucedida deve retornar 0.\n
     * * Para mais informações sobre retorno consulte #IMP_Erro_ModoPagina.
     *
     *
     */

    ///@cond
    E1_IMPRESSORASHARED_EXPORT STDCALL
    ///@endcond
    int PosicaoImpressaoVertical(int nLnH);

    /*! \ingroup M1
     * \brief Imprime Modo Página.
     *
     * Função que imprime em Modo Página.
     *
     * \return
     * O retorno é numérico.\n
     * A função bem sucedida deve retornar 0.\n
     * * Para mais informações sobre retorno consulte #IMP_Erro_ModoPagina.
     *
     *
     */

    ///@cond
    E1_IMPRESSORASHARED_EXPORT STDCALL
    ///@endcond
    int ImprimeModoPagina();

    /*! \ingroup M1
     * \brief Limpa Buffer em Modo Página.
     * * OBS: A impressora do SmartPOS não suporta este método; contudo, este método
     * funciona corretamente nas demais impressoras térmicas, conectadas ao SmartPOS.
     *
     * Função do modo página usada para Limpar o Buffer.
     *
     * \return
     * O retorno é numérico.\n
     * A função bem sucedida deve retornar 0.\n
     * * Para mais informações sobre retorno consulte #IMP_Erro_ModoPagina.
     *
     *
     */

    ///@cond
    E1_IMPRESSORASHARED_EXPORT STDCALL
    ///@endcond
    int LimpaBufferModoPagina();

    /*! \ingroup M1
     * \brief Imprime Modo Página e Retorna ao Modo Padrão.
     * * OBS: A impressora do SmartPOS não suporta este método; contudo, este método
     * funciona corretamente nas demais impressoras térmicas, conectadas ao SmartPOS.
     *
     * Função do modo página usada para Imprimir.
     *
     * \return
     * O retorno é numérico.\n
     * A função bem sucedida deve retornar 0.\n
     * * Para mais informações sobre retorno consulte #IMP_Erro_ModoPagina.
     *
     *
     */

    ///@cond
    E1_IMPRESSORASHARED_EXPORT STDCALL
    ///@endcond
    int ImprimeMPeRetornaPadrao();

    /*! \ingroup M1
     * \brief Retorna ao Modo Padrão.
     * * OBS: A impressora do SmartPOS não suporta este método; contudo, este método
     * funciona corretamente nas demais impressoras térmicas, conectadas ao SmartPOS.
     *
     * Função do modo página usada para Retornar ao Modo Padrão.
     *
     * \return
     * O retorno é numérico.\n
     * A função bem sucedida deve retornar 0.\n
     * * Para mais informações sobre retorno consulte #IMP_Erro_ModoPagina.
     *
     *
     *
     */

    ///@cond
    E1_IMPRESSORASHARED_EXPORT STDCALL
    ///@endcond
    int ModoPadrao();

    ///@cond
    E1_IMPRESSORASHARED_EXPORT STDCALL
    ///@endcond
    char *IdImpressora(int id);

    /*! \ingroup M1
     * \brief Retorna a versão da DLL E1_Impressora.
     *
     * \return
     * O retorno da função é do tipo caractere.\n
     * \n
     *
     * A função bem-sucedida deve retornar ??.??.??, que representa a versão da DLL
     * em que esta função foi chamada; cada <b>?</b> é um dígito entre 0 e 9.
     * \n
     *
     *
     */

    ///@cond
    E1_IMPRESSORASHARED_EXPORT STDCALL
    ///@endcond
    char *GetVersaoDLL();

    /*!
     * \ingroup M1
     * \brief Realiza a impressão do Cupom TEF\n
     *
     * Essa função pode ser usada para imprimir o comprovante presente nos arquivos processados\n
     * nos TEF que utilizem modelo de troca de arquivos.\n
     * A função busca pelos registros 029-XXX.
     *
     * \param dados - Conteúdo a ser impresso\n
     * ou\n
     * Caminho para arquivo com dados da venda prefixado com "path=", ex:\n
     * path=C:/Client/intpos.001
     *
     *
     * \return
     * O retorno é numérico.\n
     * A função bem sucedida deve retornar 0.\n
     * Para mais informações a sessão código de erros
     */
	 
    ///@cond
    E1_IMPRESSORASHARED_EXPORT STDCALL
    ///@endcond
    int ImprimeCupomTEF(const char* dados);

    /*! \ingroup M1
     * \brief Imprime imagem enviada à impressora diretamente, sem carregá-la na memória.
     *
     * \param path - Parâmetro do tipo caractere que define a imagem que será impressa.\n
     * \n
     * Este parâmetro recebe como argumento o caminho, no sistema de arquivos, onde a imagem
     * está armazenada, incluindo seu nome.\n
     * \n
     *
     * \return
     * O retorno da função é do tipo numérico.\n
     * A função bem-sucedida deve retornar 0.\n
     * \n
     *
     */

    ///@cond
    E1_IMPRESSORASHARED_EXPORT STDCALL
    ///@endcond
    int ImprimeImagem(const char * path);



    /***********************************************************************************************************
        Implementações HPRT

        Descrição:  Classe que exporta as funções da biblioteca HPRT.
        Autor:      George Rocha
        Data:       08/01/2018

    ***********************************************************************************************************/

    /*! \defgroup M2 Funções DLL HPRT.
     * \ingroup g0
     *
     * \brief Fornece as funções para integração com as impressoras Elgin utilizando as Funções da DLL HPRT.
     *
     * Os modelos de impressoras compativeis com estas funções são:\n
     * > Impressora i7\n
     * > Impressora i9\n
     *
     * Convenções usadas nas chamadas das funções da biblioteca:\n
     *<b>Windows</b>\n
     *  > __stdcall
     *<b>Linux</b>\n
     *  > __cdecl\n
     */

    // Funções da impressora
    /*! \ingroup M2
     * \brief Printer Creator - Especifica a impressora que será usada.\n
     * (A impressora deve ser especificada antes de qualquer função ser usada.)\n
     *
     * \param handle - Parâmetro do tipo ponteiro que apontará o espaço na memória referente a impressora.\n
     *
     * \param model - Parametro do tipo caracter que especifica o modelo da impressora que será utilizada.\n
     *
     * \return
     * O retorno da função é do tipo numérico.\n
     * A função bem sucedida deve retornar 0.\n
     *
     */

    ///@cond
    E1_IMPRESSORASHARED_EXPORT STDCALL
    ///@endcond
    int PrinterCreator(void* handle, const TCHAR* model);

    /*! \ingroup M2
     * \brief Printer Creator S - Especifica a impressora que será usada.\n
     * (A impressora deve ser especificada antes de qualquer função ser usada.)\n
     *
     * \param model - Parametro do tipo caracter que especifica o modelo da impressora que será utilizada.\n
     *
     * \return
     * Sucesso: retorna o identificador do objeto da impressora.\n
     * Falha: retorna NULO.
     *
     */

    ///@cond
    E1_IMPRESSORASHARED_EXPORT STDCALL
    ///@endcond
    void* PrinterCreatorS(const TCHAR* model);

    /*! \ingroup M2
     * \brief Printer Destroy - Libera(Desfaz) a criação feita de uma impressora anteriormente.\n
     *
     * \param handle - Parametro do tipo ponteiro que apontará o espaço na memória referente a impressora.\n
     *
     * \return
     * O retorno da função é do tipo numérico.\n
     * A função bem sucedida deve retornar 0.\n
     *
     */

    ///@cond
    E1_IMPRESSORASHARED_EXPORT STDCALL
    ///@endcond
    int PrinterDestroy(void* handle);

    /*! \ingroup M2
     * \brief Port Open - Abre a porta de comunicação e se conecta à impressora.\n
     *
     * \param handle - Parametro do tipo ponteiro que apontará o espaço na memória referente a impressora.\n
     *
     * \param ioSettings - Parametro do tipo caracter responsável por definir a conexão desejada.\n
     * Conforme tabela a seguir:
     * Referencia | Valor
     * :----------|--------
     * USB        | USB
     * Serial     | COM2,BAUDRATE_115200
     * TCP/IP     | NET,192.168.1.200,9100
     *
     * \return
     * O retorno da função é do tipo numérico.\n
     * A função bem sucedida deve retornar 0.\n
     * * Para mais informações consulte #GER_Erro_Conexao, #GER_Erro_Conexao_Serial, #GER_Erro_Conexao_USB ou #GER_Erro_Conexao_TCP.\n
     * * OBS: Caso a biblioteca encontre um hardware diferente do esperado a conexão sera negada e o valor -5 será retornado.
     *
     */

    ///@cond
    E1_IMPRESSORASHARED_EXPORT STDCALL
    ///@endcond
    int PortOpen(void* handle, const TCHAR* ioSettings);

    /*! \ingroup M2
     * \brief Port Close - Fecha conexão com a impressora.\n
     *
     * \param handle - Parametro do tipo ponteiro que apontará o espaço na memória referente a impressora.\n
     *
     * \return
     * O retorno da função é do tipo numérico.\n
     * A função bem sucedida deve retornar 0.\n
     * * Para mais informações sobre retorno consulte #GER_Erro_Conexao.
     *
     */

    ///@cond
    E1_IMPRESSORASHARED_EXPORT STDCALL
    ///@endcond
    int PortClose(void* handle);

    /*! \ingroup M2
     * \brief Printer Initialize - Inicialia a impressora para novas tarefas.\n
     *
     * \param handle - Parametro do tipo ponteiro que apontará o espaço na memória referente a impressora.\n
     *
     * \return
     * O retorno é numérico.\n
     * A função bem sucedida deve retornar 0.\n
     * * Para mais informações sobre retorno consulte <b>Códigos de erro</b>.
     *
     */

    ///@cond
    E1_IMPRESSORASHARED_EXPORT STDCALL
    ///@endcond
    int PrinterInitialize(void* handle);

    /*! \ingroup M2
     * \brief Cancel Print Data In Page Mode - Limpa Buffer em Modo Página.\n
     *
     * \param handle - Parametro do tipo ponteiro que apontará o espaço na memória referente a impressora.\n
     *
     * \return
     * O retorno é numérico.\n
     * A função bem sucedida deve retornar 0.\n
     * * Para mais informações sobre retorno consulte #IMP_Erro_ModoPagina.
     *
     */

    ///@cond
    E1_IMPRESSORASHARED_EXPORT STDCALL
    ///@endcond
    int CancelPrintDataInPageMode(void* handle);

    /*! \ingroup M2
     * \brief Get Printer State - Solicita status da impressora em tempo real.\n
     *
     * \param handle - Parametro do tipo ponteiro que apontará o espaço na memória referente a impressora.\n
     *
     * \param printerStatus - Parametro do tipo ponteiro inteiro que armazenará o retorno da função.\n
     * Conforme tabela a seguir:
     * Valor | Referencia
     * :-----|---------------------------------
     * 0     | Sucesso
     * 1     | Tampa Aberta
     * 2     | Sem Papel
     * 4     | Quase sem Papel
     * 5     | Quase sem Papel / Tampa Aberta
     * 6     | Tampa Aberta / Sem Papel
     *
     * \return
     * O retorno é numérico.\n
     * A função bem sucedida deve retornar 0.\n
     * * Para mais informações sobre retorno consulte <b>Códigos de erro.</b>
     *
     */

    ///@cond
    E1_IMPRESSORASHARED_EXPORT STDCALL
    ///@endcond
    int GetPrinterState(void* handle, unsigned int* printerStatus);

    /*! \ingroup M2
     * \brief Cut Paper - Executa um corte parcial ou completo do papel.\n
     *
     * \param handle - Parmetro do tipo ponteiro que apontará o espaço na memória referente a impressora.\n
     *
     * \param cutMode - Parametro do tipo inteiro responsável por definir o tipo de corte.\n
     * Segue tabela de tipos disponiveis:\n
     * Referncia    | Valor
     * :-------------|----------
     * Corte Total   | 0
     * Corte Parcial | 1
     *
     * \param distance - Indica o quanto o papel deve avançar.\n
     *
     * \return
     * O retorno é numérico.\n
     * A função bem sucedida deve retornar 0.\n
     * * Para mais informações sobre retorno consulte <b>Códigos de erro.</b>
     *
     */

    ///@cond
    E1_IMPRESSORASHARED_EXPORT STDCALL
    ///@endcond
    int CutPaper(void* handle, int cutMode, int distance);

    /*! \ingroup M2
     * \brief Feed Line - Avança papel.\n
     *
     * \param handle - Parametro do tipo ponteiro que apontará o espaço na memória referente a impressora.\n
     *
     * \param lines - Parametro do tipo numérico que indica o quanto o papel deve avançar.\n
     *
     * \return
     * O retorno é numérico.\n
     * A função bem sucedida deve retornar 0.\n
     * * Para mais informações sobre retorno consulte <b>Códigos de erro.</b>
     *
     */

    ///@cond
    E1_IMPRESSORASHARED_EXPORT STDCALL
    ///@endcond
    int FeedLine(void* handle, int lines);

    /*! \ingroup M2
     * \brief Open Cash Drawer - Abre Gaveta de Dinheiro.\n
     *
     * \param handle - Parametro do tipo ponteiro que apontará o espaço na memória referente a impressora.\n
     *
     * \param pinMode - Parametro do tipo inteiro que seleciona o pino que será acionado.\n
     * Segue tabela de tipos disponiveis:\n
     *
     * Referencia        | Valor
     * :-----------------|----------
     * CASDRAWER_1 Pin 2 | 0
     * CASDRAWER_2 Pin 5 | 1
     *
     * \param onTime - Parametro do tipo inteiro que define o inicio do envio de pulso.\n
     *
     * \param offTime - Parametro do tipo inteiro que define o fim do envio de pulso.\n
     * (O offTime não deve ser menor que o parâmetro onTime.)\n
     *
     * \return
     * O retorno é numérico.\n
     * A função bem sucedida deve retornar 0.\n
     * * Para mais informações sobre retorno consulte <b>Códigos de erro.</b>
     *
     */

    ///@cond
    E1_IMPRESSORASHARED_EXPORT STDCALL
    ///@endcond
    int OpenCashDrawer(void* handle, int pinMode, int onTime, int offTime);

    ///@cond
    E1_IMPRESSORASHARED_EXPORT STDCALL
    ///@endcond
    int OpenDrawer(void* handle, int pinMode, int onTime, int offTime);

    /*! \ingroup M2
     * \brief Print Text - Função para impressão de texto com atributos.\n
     *
     * \param handle - Parametro do tipo ponteiro que apontará o espaço na memória referente a impressora.\n
     *
     * \param data - Parametro do tipo caracter com a informação que será enviada ao buffer para impressão.\n
     *
     * \param alignment - Parametro do tipo inteiro que defini a posição do texto a ser impresso.\n
     * Os possiveis valores são:
     * Valor  | Posição
     * ------ | ---------
     * 0      | Esquerda
     * 1      | Centro
     * 2      | Direita
     *
     * \param attribute - Parametro do tipo inteiro que defini as propriedades do texto a ser impresso.\n
     * Os possiveis valores são:
     * Valor  | Referencia
     * ------ | --------------------------------------
     * 0      | Fonte Padrão (font A)
     * 2      | Negrito
     * 4      | Underline
     * 8      | Fonte Reversa
     * 48     | Fonte com o dobro de Altura e Largura
     *
     * \param textSize - Parametro do tipo inteiro que define o tamanho e a largura da fonte a ser impressa.\n
     * Para definição de largura os possíveis valores são:
     * Valor  | Posição
     * ------ | ----------------------
     * 0      | Texto com Largura x 1
     * 16     | Texto com Largura x 2
     * 32     | Texto com Largura x 3
     * 48     | Texto com Largura x 4
     * 64     | Texto com Largura x 5
     * 80     | Texto com Largura x 6
     * 96     | Texto com Largura x 7
     * 112    | Texto com Largura x 8
     *
     * Para definição de altura os possíveis valores são:
     * Valor  | Posição
     * ------ | ----------------------
     * 0      | Texto com Altura x 1
     * 16     | Texto com Altura x 2
     * 32     | Texto com Altura x 3
     * 48     | Texto com Altura x 4
     * 64     | Texto com Altura x 5
     * 80     | Texto com Altura x 6
     * 96     | Texto com Altura x 7
     * 112    | Texto com Altura x 8
     *
     * \return
     * O retorno é numérico.\n
     * A função bem sucedida deve retornar 0.\n
     * * Para mais informações sobre retorno consulte <b>Códigos de erro.</b>
     *
     */

    ///@cond
    E1_IMPRESSORASHARED_EXPORT STDCALL
    ///@endcond
    int PrintText(void* handle, const TCHAR* data, int alignment, int attribute, int textSize);

    /*! \ingroup M2
     * \brief Print Text S - Função para impressão de texto.\n
     *
     * \param handle - Parametro do tipo ponteiro que apontará o espaço na memória referente a impressora.\n
     *
     * \param data - Parametro do tipo caracter com a informação que será enviada ao buffer para impressão.\n
     *
     * \return
     * O retorno é numérico.\n
     * A função bem sucedida deve retornar 0.\n
     * * Para mais informações sobre retorno consulte <b>Códigos de erro.</b>
     *
     */

    ///@cond
    E1_IMPRESSORASHARED_EXPORT STDCALL
    ///@endcond
    int PrintTextS(void* handle, const TCHAR* data);

    /*! \ingroup M2
     * \brief Print Bar Code - Impressao de codigo barras.
     * Realiza a impressão de código de barras.
     *
     * \param handle - Parametro do tipo ponteiro que apontará o espaço na memória referente a impressora.\n
     *
     * \param bcType - Parametro do tipo inteiro que define o modelo do código de barras a ser impresso.\n
     * Segue tabela de tipos disponíveis:
     * | Valor | Modelo           | Quantidade de dados       | Caracteres                                   | Regras
     * | ----- | :--------------: | :-----------------------: | :------------------------------------------: | :----------------------------------: |
     * | 0     | UPC-A            | 11 ou 12                  | 0 até 9                                      | -                                    |
     * | 1     | UPC-E            | 6, 7, 8, 11, 12           | 0 até 9                                      | Quantidade = 6 se 1º != 0            |
     * | 2     | JAN13 / EAN 13   | 12 ou 13                  | 0 até 9                                      | -                                    |
     * | 3     | JAN8 / EAN 8     | 7 ou 8                    | 0 até 9                                      | -                                    |
     * | 4     | CODE 39          | 1 até 255                 | 0 até 9, A ate Z\n SP, $, %, *, +, -, \, .   | -                                    |
     * | 5     | ITF              | 2 até 255 (numeros pares) | 0 ate 9                                      | -                                    |
     * | 6     | CODE BAR         | 1 até 255                 | 0 até 9, A até D, a até d\n $, +, -, ., /, : | 1º e nº devem ser A até D ou a até d |
     * | 7     | CODE 93          | 1 até 255                 | 00H até 7FH                                  | -                                    |
     * | 8     | CODE 128         | 2 até 255                 | 00H até 7FH                                  | 1º = {, 2º = A, B ou C               |
     *
     * \param bcData - Parametro do tipo caractere que deve receber as informações que compõe o código.\n
     *
     * \param width - Parametro do tipo inteiro que define a largura do código de barras.
     * Valor de 2 até 7.\n
     *
     * \param height - Parametro do tipo inteiro que define a altura do código de barras.
     * Valor de 1 até 255.\n
     * > Se valor definido ultrapassar area de impressão o código não será impresso.\n
     *
     * \param alignment - Parametro do tipo inteiro que define a posição do Código de Barras a ser impresso.\n
     * Os possiveis valores são:
     * Valor  | Posição
     * ------ | ---------
     * 0      | Esquerda
     * 1      | Centro
     * 2      | Direita
     *
     * \param hriPosition - Parametro do tipo inteiro que define a posição de impressão do conteúdo do código de barras.
     * Valor  | Posição
     * -------|--------------
     * 0      | Não Impresso\n
     * 1      | Acima do código\n
     * 2      | Abaixo do código\n
     * 3      | Ambos\n
     *
     * \return
     * O retorno é numérico.\n
     * A função bem sucedida deve retornar 0.\n
     * * Para mais informações sobre retorno consulte #IMP_Erro_CodigoBarras.
     */

    ///@cond
    E1_IMPRESSORASHARED_EXPORT STDCALL
    ///@endcond
    int PrintBarCode(void* handle, int bcType, const TCHAR* bcData, int width, int height, int alignment, int hriPosition);

    /*! \ingroup M2
     * \brief Print Symbol - Impressao de QRCode.
     * Realiza a impressão de QRCode.
     *
     * \param handle - Parametro do tipo ponteiro que apontará o espaço na memória referente a impressora.\n
     *
     * \param type - Parametro do tipo inteiro que define o modelo do QRCode a ser impresso.\n
     * Segue tabela de tipos disponíveis:
     * Valor | Modelo
     * 101   | Padrão PDF417
     * 102   | QRCode Simples PDF417
     * 103   | QRCode Tipo 1
     * 104   | QRCode Tipo 2
     *
     * \param data - Parametro do tipo caractere que deve receber as informações que compõe o código.\n
     *
     * \param errLevel - Define o nível de correção a ser configurado para o QRCode.\n
     * Conforme tabela a seguir:
     * Valor  | Nivel de correção
     * ------ | --------------------
     * 1      | 7%
     * 2      | 15%
     * 3      | 25%
     * 4      | 30%
     *
     * \param width - Parametro do tipo inteiro que define a largura do código de barras.
     * Valor de 2 até 7.\n
     *
     * \param height - Parametro do tipo inteiro que define a altura do código de barras.
     * Valor de 1 até 255.\n
     * > Se valor definido ultrapassar area de impressão o código não será impresso.\n
     *
     * \param alignment - Parametro do tipo inteiro que define a posição do Código de Barras a ser impresso.\n
     * Os possiveis valores são:
     * Valor  | Posição
     * ------ | ---------
     * 0      | Esquerda
     * 1      | Centro
     * 2      | Direita
     *
     * \return
     * O retorno é numérico.\n
     * A função bem sucedida deve retornar 0.\n
     * * Para mais informações sobre retorno consulte #IMP_Erro_CodigoBarras.
     */

    ///@cond
    E1_IMPRESSORASHARED_EXPORT STDCALL
    ///@endcond
    int PrintSymbol(void* handle, int type, const TCHAR* data, int errLevel, int width, int height, int alignment);

    /*! \ingroup M2
     * \brief Select Page Mode - Alterna do modo padrão para modo página.
     *
     * Deve ser utilizado para dar inicio aos trabalho em modo pagina.\n
     *
     * \param handle - Parametro do tipo ponteiro que apontará o espaço na memória referente a impressora.\n
     *
     * \return
     * O retorno é numérico.\n
     * A função bem sucedida deve retornar 0.\n
     * * Para mais informações sobre retorno consulte <b>Códigos de erro</b>.
     */

    ///@cond
    E1_IMPRESSORASHARED_EXPORT STDCALL
    ///@endcond
    int SelectPageMode(void* handle);

    /*! \ingroup M2
     * \brief Select Print Direction In Page Mode - Define Direção de Impressão no Modo Página.\n
     *
     * Função do modo página utilizada para definir a direção em que serão realizada as impressões.\n
     * (Esta função só é eficaz no modo página).
     *
     * \param handle - Parametro do tipo ponteiro que apontará o espaço na memória referente a impressora.\n
     *
     * \param direction - Valor entre 0 e 3\n.
     * > 0 - Da esquerda para direita partindo do ponto superior esquerdo\n.
     * > 1 - De baixo para cima partindo do ponto inferior esquerdo\n.
     * > 2 - Da direita para esquerda partindo do ponto inferior direito\n.
     * > 3 - De cima para baixo partindo do ponto superior direito\n.
     *
     * \return
     * O retorno é numérico.\n
     * A função bem sucedida deve retornar 0.\n
     * * Para mais informações sobre retorno consulte #IMP_Erro_ModoPagina.
     */

    ///@cond
    E1_IMPRESSORASHARED_EXPORT STDCALL
    ///@endcond
    int SelectPrintDirectionInPageMode(void* handle, int direction);

    /*! \ingroup M2
     * \brief Set Absolute Vertical Print Position In Page Mode - Define a Posição da Impressão Vertical.
     *
     * Função do modo pagina usada para definir a posição de impressão Vertical.
     *
     * \param handle - Parametro do tipo ponteiro que apontará o espaço na memória referente a impressora.\n
     *
     * \param position - Define o ponto inicial Vertical.
     * > Valor em Centimetros entre 0 e 40.
     *
     * \return
     * O retorno é numérico.\n
     * A função bem sucedida deve retornar 0.\n
     * * Para mais informações sobre retorno consulte #IMP_Erro_ModoPagina.
     */

    ///@cond
    E1_IMPRESSORASHARED_EXPORT STDCALL
    ///@endcond
    int SetAbsoluteVerticalPrintPositionInPageMode(void* handle, int position);

    /*! \ingroup M2
     * \brief Imprime Modo Pagina e Retorna ao Modo Padrão.
     *
     * Efetiva somente no modo página.\n
     *
     * \param handle - Parmetro do tipo ponteiro que apontará o espaço na memória referente a impressora.\n
     *
     * \return
     * O retorno é numérico.\n
     * A função bem sucedida deve retornar 0.\n
     * * Para mais informações sobre retorno consulte #IMP_Erro_ModoPagina.
     */

    ///@cond
    E1_IMPRESSORASHARED_EXPORT STDCALL
    ///@endcond
    int SetPrintAndReturnStandardMode(void* handle);

    /*! \ingroup M2
     * \brief Set Print Area In Page Mode - Define o tamanho e a origem lógica da área de impressão.
     *
     * Função do modo pagina usada para definir o tamanho da área de impressão.
     *
     * \param handle - Parametro do tipo ponteiro que apontará o espaço na memória referente a impressora.\n
     * \param horizontal - Define o ponto inicial horizontal
     * > Valor em Centimetros entre 0 e 8.\n
     * \param vertical - Define ponto inicial na direção vertical.
     * > valor em centimetros entre 0 e 40.\n
     * \param width  - Define a dimensão na direção horizontal
     * > valor em centimetros entre 0 e 8.\n
     * \param height Define a dimensão da direção vertical.
     * > valor em centimetros entre 0 e 40.\n
     *
     * \return
     * O retorno é numérico.\n
     * A função bem sucedida deve retornar 0.\n
     * * Para mais informações sobre retorno consulte #IMP_Erro_ModoPagina.
     */

    ///@cond
    E1_IMPRESSORASHARED_EXPORT STDCALL
    ///@endcond
    int SetPrintAreaInPageMode(void* handle, int horizontal, int vertical, int width, int height);

    /*! \ingroup M2
     * \brief Print Data In Page Mode - Imprime os dados no modo página e não retorna ao modo padrão.
     *
     * Função que imprime em Modo Página.
     *
     * \param handle - Parâmetro do tipo ponteiro que apontará o espaço na memória referente a impressora.\n
     *
     * \return
     * O retorno é numérico.\n
     * A função bem sucedida deve retornar 0.\n
     * * Para mais informações sobre retorno consulte #IMP_Erro_ModoPagina.
     */

    ///@cond
    E1_IMPRESSORASHARED_EXPORT STDCALL
    ///@endcond
    int PrintDataInPageMode(void* handle);

    /*! \ingroup M2
     * \brief Set Absolute Print Position - Define Posição de Impressão Horizontal.
     *
     * Função do modo pagina usada para definir a posição de impressão Horizontal.
     *
     * \param handle - Parâmetro do tipo ponteiro que apontará o espaço na memória referente a impressora.\n
     *
     * \param position - Define o ponto inicial horizontal
     * > Valor em Centimetros entre 0 e 8.
     *
     * \return
     * O retorno é numérico.\n
     * A função bem sucedida deve retornar 0.\n
     * * Para mais informações sobre retorno consulte #IMP_Erro_ModoPagina.
     */

    ///@cond
    E1_IMPRESSORASHARED_EXPORT STDCALL
    ///@endcond
    int SetAbSolutePrintPosition(void* handle, int position);

    /*! \ingroup M2
     * \brief Get Cash Drawer State - Obtém o estado atual da Gaveta de Dinheiro.
     *
     * Função responsável por pegar o status da Gaveta de Dinheiro em tempo real.
     *
     * \param handle - Parametro do tipo ponteiro que apontará o espaço na memória referente a impressora.\n
     *
     * \param drawerState - Guarda o valor referente ao status da Gaveta de Dinheiro.
     * Os possiveis valores são:
     * Valor  | Referência
     * ------ | ------------------------------
     * 0      | Gaveta Aberta
     * 1      | Gaveta fechada ou sem conexão
     *
     * \return
     * O retorno é numérico.\n
     * A função bem sucedida deve retornar 0.\n
     * * Para mais informações sobre retorno consulte #IMP_Erro_ModoPagina.
     */

    ///@cond
    E1_IMPRESSORASHARED_EXPORT STDCALL
    ///@endcond
    int GetCashDrawerState(void* handle, int* drawerState);

    ///@cond
    E1_IMPRESSORASHARED_EXPORT STDCALL
    ///@endcond
    int GetDrawerState(void* handle, int* drawerState);

    /*! \ingroup M2
     * \brief Set Align - Define a justificativa de impressão.
     *
     * \param handle - Parâmetro do tipo ponteiro que apontará o espaço na memória referente a impressora.\n
     *
     * \param align - Parâmetro tipo numérico para indica a posição.\n
     * Os valores possiveis são:
     * Valor | Descrição
     * ----- | ------------
     * 0     | Esquerda
     * 1     | Centro
     * 2     | Direita
     *
     * \n
     * \return
     * O retorno é numérico\n
     * A função bem sucedida deve retornar 0.\n
     * * Para mais informações sobre retorno consulte #IMP_Erro_Escrita_Impressora.
     */

    ///@cond
    E1_IMPRESSORASHARED_EXPORT STDCALL
    ///@endcond
    int SetAlign(void* handle, int align);

    /*! \ingroup M2
     * \brief Set Text Bold - Ativa o desativa o impressão de texto em negrito.
     *
     * \param handle - Parâmetro do tipo ponteiro que apontará o espaço na memória referente a impressora.\n
     *
     * \param bold - Parâmetro do tipo numérico para indicar ativação ou cancelamento do modo Negrito.\n
     * Os valores possiveis são:
     * Valor | Descrição
     * ----- | -------------------
     * 0     | Cancela modo Negrito
     * 1     | Ativa modo Negrito
     * \n
     *
     * \return
     * O retorno é numérico\n
     * A função bem sucedida deve retornar 0.\n
     * * Para mais informações sobre retorno consulte #IMP_Erro_Escrita_Impressora.
     */

    ///@cond
    E1_IMPRESSORASHARED_EXPORT STDCALL
    ///@endcond
    int SetTextBold(void* handle, int bold);

    /*! \ingroup M2
     * \brief Set Text Font - Define tipo de fonte na impressão de texto.
     *
     * \param handle - Parâmetro do tipo ponteiro que apontará o espaço na memória referente a impressora.\n
     *
     * \param font - Parâmetro do tipo numérico que indica qual fonte será usada na impressão.\n
     * Os valores possiveis são:
     * Valor | Descrição
     * ----- | -------------------
     * 0     | Fonte A
     * 1     | Fonte B
     * \n
     *
     * \return
     * O retorno é numérico\n
     * A função bem sucedida deve retornar 0.\n
     * * Para mais informações sobre retorno consulte #IMP_Erro_Escrita_Impressora.
     */

    ///@cond
    E1_IMPRESSORASHARED_EXPORT STDCALL
    ///@endcond
    int SetTextFont(void* handle, int font);

    E1_IMPRESSORASHARED_EXPORT int STDCALL SetLog(int enable, const TCHAR* path);

    /*! \ingroup M2
     * \brief Retorna do modo página para o modo padrão.
     *
     * Função do modo pagina usada para Retornar ao Modo Padrão.
     *
     * \param handle - Parâmetro do tipo ponteiro que apontará o espaço na memória referente a impressora.\n
     *
     * \return
     * O retorno é numérico.\n
     * A função bem sucedida deve retornar 0.\n
     * * Para mais informações sobre retorno consulte #IMP_Erro_ModoPagina.
     */

    ///@cond
    E1_IMPRESSORASHARED_EXPORT STDCALL
    ///@endcond
    int SelectStandardMode(void* handle);

    /*! \ingroup M2
     * \brief Prt Printer Creator - Especifica a impressora que será usada.\n
     * (A impressora deve ser especificada antes de qualquer função ser usada.)\n
     *
     * \param phandle - Parametro do tipo ponteiro que apontará o espaço na memória referente a impressora.\n
     * > Na criação da impressora, deve ser usado um ponteiro por referência.
     *
     * \param model - Parametro do tipo caracter que especifica o modelo da impressora que será utilizada.\n
     *
     * \return
     * O retorno da função é do tipo numérico.\n
     * A função bem sucedida deve retornar 0.\n
     *
     */

    ///@cond
    E1_IMPRESSORASHARED_EXPORT STDCALL
    ///@endcond
    int PrtPrinterCreator(void **phandle, const TCHAR *model);

    /*! \ingroup M2
     * \brief Prt Printer Destroy - Desconstroi a criação feita de uma impressora.\n
     *
     * \param handle - Parametro do tipo ponteiro que apontará o espaço na memória referente a impressora.\n
     *
     * \return
     * O retorno da função é do tipo numérico.\n
     * A função bem sucedida deve retornar 0.\n
     *
     */

    ///@cond
    E1_IMPRESSORASHARED_EXPORT STDCALL
    ///@endcond
    int PrtPrinterDestroy(void* handle);

    /*! \ingroup M2
     * \brief Prt Port Open - Abre conexão com a impressora.\n
     *
     * \param handle - Parametro do tipo ponteiro que apontará o espaço na memória referente a impressora.\n
     *
     * \param ioSettings - Parametro do tipo caracter responsável por definir a conexão desejada.\n
     * Conforme tabela a seguir:
     * Referencia | Valor
     * :----------|--------
     * USB        | USB
     * Serial     | COM2,BAUDRATE_115200
     * TCP/IP     | NET,192.168.1.200,9100
     *
     * \return
     * O retorno da função é do tipo numérico.\n
     * A função bem sucedida deve retornar 0.\n
     * * Para mais informações consulte #GER_Erro_Conexao, #GER_Erro_Conexao_Serial, #GER_Erro_Conexao_USB ou #GER_Erro_Conexao_TCP.\n
     * * OBS: Caso a biblioteca encontre um hardware diferente do esperado a conexão sera negada e o valor -5 será retornado.
     *
     */

    ///@cond
    E1_IMPRESSORASHARED_EXPORT STDCALL
    ///@endcond
    int PrtPortOpen(void* handle, const TCHAR *ioSettings);

    /*! \ingroup M2
     * \brief Prt Port Close - Fecha conexão com a impressora.\n
     *
     * \param handle - Parametro do tipo ponteiro que apontará o espaço na memória referente a impressora.\n
     *
     * \return
     * O retorno da função é do tipo numérico.\n
     * A função bem sucedida deve retornar 0.\n
     * * Para mais informações sobre retorno consulte #GER_Erro_Conexao.
     *
     */

    ///@cond
    E1_IMPRESSORASHARED_EXPORT STDCALL
    ///@endcond
    int PrtPortClose(void* handle);

    /*! \ingroup M2
     * \brief Prt Printer Initialize - Inicialia a impressora para novas tarefas.\n
     *
     * \param handle - Parametro do tipo ponteiro que apontará o espaço na memória referente a impressora.\n
     *
     * \return
     * O retorno é numérico.\n
     * A função bem sucedida deve retornar 0.\n
     * * Para mais informações sobre retorno consulte <b>Códigos de erro</b>.
     *
     */

    ///@cond
    E1_IMPRESSORASHARED_EXPORT STDCALL
    ///@endcond
    int PrtPrinterInitialize(void* handle);

    /*! \ingroup M2
     * \brief Prt Check Printer State - Solicita status da impressora em tempo real.\n
     *
     * \param handle - Parametro do tipo ponteiro que apontará o espaço na memória referente a impressora.\n
     *
     * \param printerStatus - Parametro do tipo ponteiro inteiro que armazenará o retorno da função.\n
     * Conforme tabela a seguir:
     * Valor | Referencia
     * :-----|---------------------------------
     * 0     | Sucesso
     * 1     | Sem Papel
     * 2     | Tampa Aberta
     * 4     | Quase sem Papel
     * 5     | Quase sem Papel / Tampa Aberta
     * 6     | Tampa Aberta / Sem Papel
     *
     * \return
     * O retorno é numérico.\n
     * A função bem sucedida deve retornar 0.\n
     * * Para mais informações sobre retorno consulte <b>Códigos de erro.</b>
     *
     */

    ///@cond
    E1_IMPRESSORASHARED_EXPORT STDCALL
    ///@endcond
    int PrtCheckPrinterState(void* handle, unsigned int* printerStatus);

    /*! \ingroup M2
     * \brief Prt Cut Paper - Corta o cupom.\n
     *
     * \param handle - Parametro do tipo ponteiro que apontará o espaço na memória referente a impressora.\n
     *
     * \param cutMode - Parametro do tipo inteiro responsável por definir o tipo de corte.\n
     * Segue tabela de tipos disponiveis:\n
     * Referencia    | Valor
     * :-------------|----------
     * Corte Total   | 0
     * Corte Parcial | 1
     *
     * \param distance - Indica o quanto o papel deve avançar.\n
     *
     * \return
     * O retorno é numérico.\n
     * A função bem sucedida deve retornar 0.\n
     * * Para mais informações sobre retorno consulte <b>Códigos de erro.</b>
     *
     */

    ///@cond
    E1_IMPRESSORASHARED_EXPORT STDCALL
    ///@endcond
    int PrtCutPaper(void* handle, int cutMode, int distance);

    /*! \ingroup M2
     * \brief Prt Feed Line - Avança papel.\n
     *
     * \param handle - Parametro do tipo ponteiro que apontará o espaço na memória referente a impressora.\n
     *
     * \param lines - Parametro do tipo numérico que indica o quanto o papel deve avançar.\n
     *
     * \return
     * O retorno é numérico.\n
     * A função bem sucedida deve retornar 0.\n
     * * Para mais informações sobre retorno consulte <b>Códigos de erro.</b>
     *
     */

    ///@cond
    E1_IMPRESSORASHARED_EXPORT STDCALL
    ///@endcond
    int PrtFeedLine(void* handle, int  lines);

    /*! \ingroup M2
     * \brief Prt Open Drawer - Abre Gaveta de Dinheiro.\n
     *
     * \param handle - Parametro do tipo ponteiro que apontará o espaço na memória referente a impressora.\n
     *
     * \param pin - Parametro do tipo inteiro que seleciona o pino que será acionado.\n
     * Segue tabela de tipos disponiveis:\n
     *
     * Referencia        | Valor
     * :-----------------|----------
     * CASDRAWER_1 Pin 2 | 0
     * CASDRAWER_2 Pin 5 | 1
     *
     * \param onTime - Parametro do tipo inteiro que define o inicio do envio de pulso.\n
     *
     * \param offTime - Parametro do tipo inteiro que define o fim do envio de pulso.\n
     * (O offTime não deve ser menor que o parâmetro onTime.)\n
     *
     * \return
     * O retorno é numérico.\n
     * A função bem sucedida deve retornar 0.\n
     * * Para mais informações sobre retorno consulte <b>Códigos de erro.</b>
     *
     */

    ///@cond
    E1_IMPRESSORASHARED_EXPORT STDCALL
    ///@endcond
    int PrtOpenDrawer(void* handle, int pin, int onTime, int offTime);

    /*! \ingroup M2
     * \brief Prt Get Drawer State - Solicita status da Gaveta de Dinheiro em tempo real.
     *
     * Função responsável por pegar o status da Gaveta de Dinheiro em tempo real.
     *
     * \param handle - Parametro do tipo ponteiro que apontará o espaço na memória referente a impressora.\n
     *
     * \param drawerState - Guarda o valor referente ao status da Gaveta de Dinheiro.
     * Os possiveis valores são:
     * Valor  | Referência
     * ------ | ------------------------------
     * 0      | Gaveta Aberta
     * 1      | Gaveta fechada ou sem conexão
     *
     * \return
     * O retorno é numérico.\n
     * A função bem sucedida deve retornar 0.\n
     * * Para mais informações sobre retorno consulte #IMP_Erro_ModoPagina.
     */

    ///@cond
    E1_IMPRESSORASHARED_EXPORT STDCALL
    ///@endcond
    int PrtGetDrawerState(void* handle, int* drawerState);

    /*! \ingroup M2
     * \brief Prt Print Text - Função para impressão de texto com atributos.\n
     *
     * \param handle - Parâmetro do tipo ponteiro que apontará o espaço na memória referente a impressora.\n
     * 
     * \param data - Parametro do tipo caracter com a informação que será enviada ao buffer para impressão.\n
     *
     * \param alignment - Parametro do tipo inteiro que defini a posição do texto a ser impresso.\n
     * Os possiveis valores são:
     * Valor  | Posição
     * ------ | ---------
     * 0      | Esquerda
     * 1      | Centro
     * 2      | Direita
     *
     * \param attribute - Parametro do tipo inteiro que defini as propriedades do texto a ser impresso.\n
     * Os possiveis valores são:
     * Valor  | Referencia
     * ------ | --------------------------------------
     * 0      | Fonte Padrão (font A)
     * 2      | Negrito
     * 4      | Underline
     * 8      | Fonte Reversa
     * 48     | Fonte com o dobro de Altura e Largura
     *
     * \param textSize - Parametro do tipo inteiro que define o tamanho e a largura da fonte a ser impressa.\n
     * Para definição de largura os possíveis valores são:
     * Valor  | Posição
     * ------ | ----------------------
     * 0      | Texto com Largura x 1
     * 16     | Texto com Largura x 2
     * 32     | Texto com Largura x 3
     * 48     | Texto com Largura x 4
     * 64     | Texto com Largura x 5
     * 80     | Texto com Largura x 6
     * 96     | Texto com Largura x 7
     * 112    | Texto com Largura x 8
     *
     * Para definição de altura os possíveis valores são:
     * Valor  | Posição
     * ------ | ----------------------
     * 0      | Texto com Altura x 1
     * 16     | Texto com Altura x 2
     * 32     | Texto com Altura x 3
     * 48     | Texto com Altura x 4
     * 64     | Texto com Altura x 5
     * 80     | Texto com Altura x 6
     * 96     | Texto com Altura x 7
     * 112    | Texto com Altura x 8
     *
     * \return
     * O retorno é numérico.\n
     * A função bem sucedida deve retornar 0.\n
     * * Para mais informações sobre retorno consulte <b>Códigos de erro.</b>
     *
     */

    ///@cond
    E1_IMPRESSORASHARED_EXPORT STDCALL
    ///@endcond
    int PrtPrintText(void *handle,const TCHAR* data, int alignment, int attribute, int textSize);

    /*! \ingroup M2
     * \brief Prt Print Bar Code - Impressao de codigo barras.
     * Realiza a impressão de código de barras.
     *
     * \param handle - Parametro do tipo ponteiro que apontará o espaço na memória referente a impressora.\n
     *
     * \param bcType - Parametro do tipo inteiro que define o modelo do código de barras a ser impresso.\n
     * Segue tabela de tipos disponíveis:
     * | Valor | Modelo           | Quantidade de dados       | Caracteres                                   | Regras
     * | ----- | :--------------: | :-----------------------: | :------------------------------------------: | :----------------------------------: |
     * | 0     | UPC-A            | 11 ou 12                  | 0 até 9                                      | -                                    |
     * | 1     | UPC-E            | 6, 7, 8, 11, 12           | 0 até 9                                      | Quantidade = 6 se 1º != 0            |
     * | 2     | JAN13 / EAN 13   | 12 ou 13                  | 0 até 9                                      | -                                    |
     * | 3     | JAN8 / EAN 8     | 7 ou 8                    | 0 até 9                                      | -                                    |
     * | 4     | CODE 39          | 1 até 255                 | 0 até 9, A ate Z\n SP, $, %, *, +, -, \, .   | -                                    |
     * | 5     | ITF              | 2 até 255 (numeros pares) | 0 ate 9                                      | -                                    |
     * | 6     | CODE BAR         | 1 até 255                 | 0 até 9, A até D, a até d\n $, +, -, ., /, : | 1º e nº devem ser A até D ou a até d |
     * | 7     | CODE 93          | 1 até 255                 | 00H até 7FH                                  | -                                    |
     * | 8     | CODE 128         | 2 até 255                 | 00H até 7FH                                  | 1º = {, 2º = A, B ou C               |
     *
     * \param bcData - Parametro do tipo caractere que deve receber as informações que compõe o código.\n
     *
     * \param width - Parametro do tipo inteiro que define a largura do código de barras.
     * Valor de 2 até 7.\n
     *
     * \param height - Parametro do tipo inteiro que define a altura do código de barras.
     * Valor de 1 até 255.\n
     * > Se valor definido ultrapassar area de impressão o código não será impresso.\n
     *
     * \param alignment - Parametro do tipo inteiro que define a posição do Código de Barras a ser impresso.\n
     * Os possiveis valores são:
     * Valor  | Posição
     * ------ | ---------
     * 0      | Esquerda
     * 1      | Centro
     * 2      | Direita
     *
     * \param hriPosition - Parametro do tipo inteiro que define a posição de impressão do conteúdo do código de barras.
     * > 0 - Não Impresso.\n
     * > 1 - Acima do código.\n
     * > 2 - Abaixo do código.\n
     * > 3 - Ambos.\n
     *
     * \return
     * O retorno é numérico.\n
     * A função bem sucedida deve retornar 0.\n
     * * Para mais informações sobre retorno consulte #IMP_Erro_CodigoBarras.
     */

    ///@cond
    E1_IMPRESSORASHARED_EXPORT STDCALL
    ///@endcond
    int PrtPrintBarCode(void* handle, int bcType, const TCHAR* bcData, int width, int height, int alignment, int hriPosition);

    /*! \ingroup M2
     * \brief Prt Print Symbol - Impressao de QRCode.
     * Realiza a impressão de QRCode.
     *
     * \param handle - Parametro do tipo ponteiro que apontará o espaço na memória referente a impressora.\n
     *
     * \param type - Parametro do tipo inteiro que define o modelo do QRCode a ser impresso.\n
     * Segue tabela de tipos disponíveis:
     * Valor | Modelo
     * 101   | Padrão PDF417
     * 102   | QRCode Simples PDF417
     * 103   | QRCode Tipo 1
     * 104   | QRCode Tipo 2
     *
     * \param data - Parametro do tipo caractere que deve receber as informações que compõe o código.\n
     *
     * \param errLevel - Define o nível de correção a ser configurado para o QRCode.\n
     * Conforme tabela a seguir:
     * Valor  | Nivel de correção
     * ------ | --------------------
     * 1      | 7%
     * 2      | 15%
     * 3      | 25%
     * 4      | 30%
     *
     * \param width - Parametro do tipo inteiro que define a largura do código de barras.
     * Valor de 2 até 7.\n
     *
     * \param height - Parametro do tipo inteiro que define a altura do código de barras.
     * Valor de 1 até 255.\n
     * > Se valor definido ultrapassar area de impressão o código não será impresso.\n
     *
     * \param alignment - Parametro do tipo inteiro que define a posição do Código de Barras a ser impresso.\n
     * Os possiveis valores são:
     * Valor  | Posição
     * ------ | ---------
     * 0      | Esquerda
     * 1      | Centro
     * 2      | Direita
     *
     * \return
     * O retorno é numérico.\n
     * A função bem sucedida deve retornar 0.\n
     * * Para mais informações sobre retorno consulte #IMP_Erro_CodigoBarras.
     */

    ///@cond
    E1_IMPRESSORASHARED_EXPORT STDCALL
    ///@endcond
    int PrtPrintSymbol(void* handle, int type, const TCHAR* data, int errLevel, int width, int height, int alignment);

    /*! \ingroup M2
     * \brief Prt Select Page Mode - Habilita Modo Pagina.
     *
     * Deve ser utilizado para dar inicio aos trabalho em modo pagina.\n
     *
     * \param handle - Parametro do tipo ponteiro que apontará o espaço na memória referente a impressora.\n
     *
     * \return
     * O retorno é numérico.\n
     * A função bem sucedida deve retornar 0.\n
     * * Para mais informações sobre retorno consulte <b>Códigos de erro</b>.
     */

    ///@cond
    E1_IMPRESSORASHARED_EXPORT STDCALL
    ///@endcond
    int PrtSelectPageMode(void* handle);

    /*! \ingroup M2
     * \brief Prt Select Standard Mode - Retorna ao Modo Padrão.
     *
     * Função do modo pagina usada para Retornar ao Modo Padrão.
     *
     * \param handle - Parametro do tipo ponteiro que apontará o espaço na memória referente a impressora.\n
     *
     * \return
     * O retorno é numérico.\n
     * A função bem sucedida deve retornar 0.\n
     * * Para mais informações sobre retorno consulte #IMP_Erro_ModoPagina.
     */

    ///@cond
    E1_IMPRESSORASHARED_EXPORT STDCALL
    ///@endcond
    int PrtSelectStandardMode(void* handle);

    /*! \ingroup M2
     * \brief Select Print Direction In Page Mode - Define Direção de Impressão no Modo Página.\n
     *
     * Função do modo página utilizada para definir a direção em que serão realizada as impressões.\n
     *
     * \param handle - Parametro do tipo ponteiro que apontará o espaço na memória referente a impressora.\n
     *
     * \param direction - Valor entre 0 e 3\n.
     * > 0 - Da esquerda para direita partindo do ponto superior esquerdo\n.
     * > 1 - De baixo para cima partindo do ponto inferior esquerdo\n.
     * > 2 - Da direita para esquerda partindo do ponto inferior direito\n.
     * > 3 - De cima para baixo partindo do ponto superior direito\n.
     *
     * \return
     * O retorno é numérico.\n
     * A função bem sucedida deve retornar 0.\n
     * * Para mais informações sobre retorno consulte #IMP_Erro_ModoPagina.
     */

    ///@cond
    E1_IMPRESSORASHARED_EXPORT STDCALL
    ///@endcond
    int PrtSelectPrintDirectionInPageMode(void* handle, int direction);

    /*! \ingroup M2
     * \brief Prt Set Text Position - Define a posição do conteudo a ser impresso.
     *
     * \param handle - Parametro do tipo ponteiro que apontará o espaço na memória referente a impressora.\n
     *
     * \param position - Parametro tipo numérico para indica a posição.\n
     * Os valores possiveis são:
     * Valor | Descrição
     * ----- | ------------
     * 0     | Esquerda
     * 1     | Centro
     * 2     | Direita
     *
     * \n
     * \return
     * O retorno é numérico\n
     * A função bem sucedida deve retornar 0.\n
     * * Para mais informações sobre retorno consulte #IMP_Erro_Escrita_Impressora.
     */

    ///@cond
    E1_IMPRESSORASHARED_EXPORT STDCALL
    ///@endcond
    int PrtSetTextPosition(void* handle, int position);

    /*! \ingroup M2
     * \brief Prt Set Absolute Vertical Print Position In Page Mode - Define a Posição da Impressão Vertical.
     *
     * Função do modo pagina usada para definir a posição de impressão Vertical.
     *
     * \param handle - Parametro do tipo ponteiro que apontará o espaço na memória referente a impressora.\n
     *
     * \param position - Define o ponto inicial Vertical.
     * > Valor em Centimetros entre 0 e 40.
     *
     * \return
     * O retorno é numérico.\n
     * A função bem sucedida deve retornar 0.\n
     * * Para mais informações sobre retorno consulte #IMP_Erro_ModoPagina.
     */

    ///@cond
    E1_IMPRESSORASHARED_EXPORT STDCALL
    ///@endcond
    int PrtSetAbsoluteVerticalPrintPositionInPageMode(void* handle, int position);

    /*! \ingroup M2
     * \brief Prt Set Print And Return Standard Mode - Imprime Modo Pagina e Retorna ao Modo Padrão.
     *
     * Função do modo pagina usada para Imprimir .\n
     *
     * \param handle - Parametro do tipo ponteiro que apontará o espaço na memória referente a impressora.\n
     *
     * \return
     * O retorno é numérico.\n
     * A função bem sucedida deve retornar 0.\n
     * * Para mais informações sobre retorno consulte #IMP_Erro_ModoPagina.
     */

    ///@cond
    E1_IMPRESSORASHARED_EXPORT STDCALL
    ///@endcond
    int PrtSetPrintAndReturnStandardMode(void* handle);

    /*! \ingroup M2
     * \brief Prt Cancel Print Data In PageMode - Limpa o buffer de impressão em Modo Página.
     *
     * Função do modo pagina usada para limpar o buffer de impressão.\n
     *
     * \param handle - Parametro do tipo ponteiro que apontará o espaço na memória referente a impressora.\n
     *
     * \return
     * O retorno é numérico.\n
     * A função bem sucedida deve retornar 0.\n
     * * Para mais informações sobre retorno consulte #IMP_Erro_ModoPagina.
     */

    ///@cond
    E1_IMPRESSORASHARED_EXPORT STDCALL
    ///@endcond
    int PrtCancelPrintDataInPageMode(void* handle);

    /*! \ingroup M2
     * \brief Prt Set Print Area In Page Mode - Define Area Impressão
     *
     * Função do modo pagina usada para definir o tamanho da área de impressão.
     *
     * \param handle - Parametro do tipo ponteiro que apontará o espaço na memória referente a impressora.\n
     * \param horizontal - Define o ponto inicial horizontal
     * > Valor em Centimetros entre 0 e 8.\n
     * \param vertical - Define ponto inicial na direção vertical.
     * > valor em centimetros entre 0 e 40.\n
     * \param width  - Define a dimensão na direção horizontal
     * > valor em centimetros entre 0 e 8.\n
     * \param height Define a dimensão da direção vertical.
     * > valor em centimetros entre 0 e 40.\n
     *
     * \return
     * O retorno é numérico.\n
     * A função bem sucedida deve retornar 0.\n
     * * Para mais informações sobre retorno consulte #IMP_Erro_ModoPagina.
     */

    ///@cond
    E1_IMPRESSORASHARED_EXPORT STDCALL
    ///@endcond
    int PrtSetPrintAreaInPageMode(void* handle, int horizontal, int vertical, int width, int height);

    /*! \ingroup M2
     * \brief Prt Print Data In Page Mode - Imprime Modo Página.
     *
     * Função que imprime em Modo Página.
     *
     * \param handle - Parametro do tipo ponteiro que apontará o espaço na memória referente a impressora.\n
     *
     * \return
     * O retorno é numérico.\n
     * A função bem sucedida deve retornar 0.\n
     * * Para mais informações sobre retorno consulte #IMP_Erro_ModoPagina.
     */

    ///@cond
    E1_IMPRESSORASHARED_EXPORT STDCALL
    ///@endcond
    int PrtPrintDataInPageMode(void* handle);

    /*! \ingroup M2
     * \brief Prt Set Text Bold - Define negrito no conteúdo a ser impresso.
     *
     * \param handle - Parametro do tipo ponteiro que apontará o espaço na memória referente a impressora.\n
     *
     * \param bold - Parametro do tipo numérico para indicar ativação ou cancelamento do modo Negrito.\n
     * Os valores possiveis são:
     * Valor | Descrição
     * ----- | -------------------
     * 0     | Cancela modo Negrito
     * 1     | Ativa modo Negrito
     * \n
     *
     * \return
     * O retorno é numérico\n
     * A função bem sucedida deve retornar 0.\n
     * * Para mais informações sobre retorno consulte #IMP_Erro_Escrita_Impressora.
     */

    ///@cond
    E1_IMPRESSORASHARED_EXPORT STDCALL
    ///@endcond
    int PrtSetTextBold(void* handle, int bold);

    /*! \ingroup M2
     * \brief Prt Set Text Font - Define tipo de Fonte a ser impressa.
     *
     * \param handle - Parametro do tipo ponteiro que apontará o espaço na memória referente a impressora.\n
     *
     * \param font - Parametro do tipo numérico que indica qual fonte será usada na impressão.\n
     * Os valores possiveis são:
     * Valor | Descrição
     * ----- | -------------------
     * 0     | Fonte A
     * 1     | Fonte B
     * \n
     *
     * \return
     * O retorno é numérico\n
     * A função bem sucedida deve retornar 0.\n
     * * Para mais informações sobre retorno consulte #IMP_Erro_Escrita_Impressora.
     */

    ///@cond
    E1_IMPRESSORASHARED_EXPORT STDCALL
    ///@endcond
    int PrtSetTextFont(void* handle, int font);

    ///@cond
    E1_IMPRESSORASHARED_EXPORT STDCALL
    ///@endcond
    int SetTextLineSpace(void* handle,int lineSpace);

    //PARA COMPATIBILIDADE COM SOCIN
    ///@cond
    E1_IMPRESSORASHARED_EXPORT STDCALL
    ///@endcond
    int DefineNVImage(void* handle, const char* imagePath, unsigned char kc1, unsigned char kc2);

    ///@cond
    E1_IMPRESSORASHARED_EXPORT STDCALL
    ///@endcond
    int PrintNVImage(void* handle, unsigned char kc1, unsigned char kc2);


    /*
    ///@cond
    E1_IMPRESSORASHARED_EXPORT STDCALL
    ///@endcond
    int DirectIO(void* handle, unsigned char* writeData, unsigned char* writeNum, unsigned char* readData, unsigned char* readNum, unsigned char* preadedNum);

    ///@cond
    E1_IMPRESSORASHARED_EXPORT STDCALL
    ///@endcond
    int PrtDirectIO(void* handle, unsigned char* writeData, unsigned int writeNum, unsigned char* readData, unsigned int readNum, unsigned int* preadedNum);

    ///@cond
    E1_IMPRESSORASHARED_EXPORT STDCALL
    ///@endcond
    int PrtSetTextLineSpace(void* handle, int lineSpace);

    ///@cond
    E1_IMPRESSORASHARED_EXPORT STDCALL
    ///@endcond
    int PrtSetCharacterSet(void* handle, int characterSet);

    ///@cond
    E1_IMPRESSORASHARED_EXPORT STDCALL
    ///@endcond
    int PrtPrintImage(void* handle, const TCHAR* filePath, int scaleMode);

    ///@cond
    E1_IMPRESSORASHARED_EXPORT STDCALL
    ///@endcond
    int PrtGetPrinterVersion(void* handle, int* version, int versionLen);

    ///@cond
    E1_IMPRESSORASHARED_EXPORT STDCALL
    ///@endcond
    int SetTextLineSpace(void* handle,int lineSpace);

    ///@cond
    E1_IMPRESSORASHARED_EXPORT STDCALL
    ///@endcond
    int SetCodePage(void* handle, int characterSet, int type);

    ///@cond
    E1_IMPRESSORASHARED_EXPORT STDCALL
    ///@endcond
    int SetInternationalCharacter(void* handle, int characterSet);

    ///@cond
    E1_IMPRESSORASHARED_EXPORT STDCALL
    ///@endcond
    int PrintTwoQRCode(void* handle, TCHAR* data1, int data1Len, int width1, int hAlign1, int vAlign1, TCHAR* data2, int data2Len, int width2, int hAlign2, int vAlign2);

    ///@cond
    E1_IMPRESSORASHARED_EXPORT STDCALL
    ///@endcond
    int PrintImage(void* handle, const TCHAR* filePath, int scaleMode);

    ///@cond
    E1_IMPRESSORASHARED_EXPORT STDCALL
    ///@endcond
    int PrintBitMapData(void* handle, int scaleMode, int width, int height, unsigned char* data);

    ///@cond
    E1_IMPRESSORASHARED_EXPORT STDCALL
    ///@endcond
    int DefineNVImageCompatible(void* handle, const TCHAR** filePathList, int imageQty);

    ///@cond
    E1_IMPRESSORASHARED_EXPORT STDCALL
    ///@endcond
    int PrintNVImageCompatible(void* handle, int imgNo, int scaleMode);

    ///@cond
    E1_IMPRESSORASHARED_EXPORT STDCALL
    ///@endcond
    int DefineDownloadedImageCompatible(void* handle, const TCHAR* filePath);

    ///@cond
    E1_IMPRESSORASHARED_EXPORT STDCALL
    ///@endcond
    int PrintDownloadedImageCompatible(void* handle, int scaleMode);

    ///@cond
    E1_IMPRESSORASHARED_EXPORT STDCALL
    ///@endcond
    int GetFirmwareVersion(void* handle, int* version, int versionLen);

    ///@cond
    E1_IMPRESSORASHARED_EXPORT STDCALL
    ///@endcond
    int PositionNextLabel(void* handle);

    ///@cond
    E1_IMPRESSORASHARED_EXPORT STDCALL
    ///@endcond
    int DefineDownloadedImage(void* handle, const char* imagePath, unsigned char kc1, unsigned char kc2);

    ///@cond
    E1_IMPRESSORASHARED_EXPORT STDCALL
    ///@endcond
    int PrintDownloadedImage(void* handle, unsigned char kc1, unsigned char kc2);

    ///@cond
    E1_IMPRESSORASHARED_EXPORT STDCALL
    ///@endcond
    int DefineBufferedImage(void* handle, const char* imagePath);

    ///@cond
    E1_IMPRESSORASHARED_EXPORT STDCALL
    ///@endcond
    int PrintBufferedImage(void* handle);

    ///@cond
    E1_IMPRESSORASHARED_EXPORT STDCALL
    ///@endcond
    int DeletAllNVImages(void* handle);

    ///@cond
    E1_IMPRESSORASHARED_EXPORT STDCALL
    ///@endcond
    int ClearBuffer(void* handle);

    ///@cond
    E1_IMPRESSORASHARED_EXPORT STDCALL
    ///@endcond
    int FormatError(int errorNo, int landid, unsigned char* buf, int pos, int bufSize);

    ///@cond
    E1_IMPRESSORASHARED_EXPORT STDCALL
    ///@endcond
    int SetBuzzer(void* handle, int enable);

    ///@cond
    E1_IMPRESSORASHARED_EXPORT STDCALL
    ///@endcond
    int SetLog(void* handle, const TCHAR* path);
    */
}

#endif // EXPORTAFUNCOES_H
