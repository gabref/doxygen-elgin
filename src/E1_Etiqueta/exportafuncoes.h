#ifndef EXPORTAFUNCOES_H
#define EXPORTAFUNCOES_H

#include "e1_etiqueta.h"

#ifdef __WIN32
#define STDCALL __stdcall
#elif __linux__
#define STDCALL
#endif


/*
    Descricao:      Classe que exporta e documenta as funcoes da biblioteca E1_Etiqueta
    Autor:          Rodrigo Angelo
    Data:           05/08/2019
*/


E1_Etiqueta et;


/** \defgroup M0 Etiqueta
  * \ingroup g0
  *
  * \brief Fornece as funções da DLL E1_Etiqueta, em Linguagem A (PPLA).
  *
  * Ao longo do documento, o termo <i>propriedade(s)</i> pode aparecer como sinônimo
  * das configurações afetadas pelas funções dos grupos <i>Configuração de Sistema</i>,
  * <i>Nível de Sistema</i> e/ou <i>Formatação de Label</i>.\n
  * \n
  *
  * O termo <i>campo(s)</i>, bastante utilizado, se refere às <i>imagens</i> que uma etiqueta
  * pode ter, como textos, linhas, figuras/gráficos (imagens propriamente ditas) e códigos de
  * barras. Para facilitar a distinção entre <i>imagem</i> (propriamente dita) e seus sinônimos
  * e <i>imagens</i> (elementos da etiqueta), foi adotado o termo <i>campos</i> para se referir
  * à este último.\n
  * \n
  *
  * * OBS: A impressora L42 vem, por padrão de fábrica, com o firmware da linguagem
  * B (PPLB). Desse modo, antes de usar esta DLL, será necessário atualizar o firmware
  * da L42 para a linguagem A (PPLA).
  *
  * Convenções usadas nas chamadas das funções da biblioteca:\n
  *<b>Windows</b>\n
  *  > __stdcall
  *<b>Linux</b>\n
  *  > __cdecl\n
*/

/*! \defgroup ge0 Configuração de Sistema
 * \ingroup M0
 *
 * \brief Comandos de Configuração de Sistema (System Setting Commands) fornecem
 * funções para configurar as propriedades relacionadas à impressora.
 *
 * Estes parâmetros são gravados na EPROM, logo, serão preservados mesmo com
 * um desligamento ou uma reinicialização da impressora. Se um novo comando,
 * com parâmetros diferentes, for usado, estes novos parâmetros substituirão
 * os antigos.
 *
 * Convenções usadas nas chamadas das funções da biblioteca:\n
 *<b>Windows</b>\n
 *  > __stdcall
 *<b>Linux</b>\n
 *  > __cdecl\n
*/

/*! \defgroup ge1 Nível de Sistema
 * \ingroup M0
 *
 * \brief Comandos de Nível de Sistema (System Level Commands) fornecem funções
 * para configurar as propriedades relacionadas à impressão e ao ambiente das
 * etiquetas.
 *
 * Estes parâmetros não são gravados na EPROM, logo, serão perdidos sempre que
 * a impressora for desligada ou reiniciada.
 *
 * Convenções usadas nas chamadas das funções da biblioteca:\n
 *<b>Windows</b>\n
 *  > __stdcall
 *<b>Linux</b>\n
 *  > __cdecl\n
*/

/*! \defgroup ge2 Formatação de Label
 * \ingroup M0
 *
 * \brief Comandos de Formatação de Label (Label Formatting Commands) fornecem funções
 * para configurar as propriedades de formatação da etiqueta, tais como margens (offsets),
 * calor e velocidade de impressão.
 *
 * Convenções usadas nas chamadas das funções da biblioteca:\n
 *<b>Windows</b>\n
 *  > __stdcall
 *<b>Linux</b>\n
 *  > __cdecl\n
*/

/*! \defgroup ge3 Campos da Etiqueta
 * \ingroup M0
 *
 * \brief Fornece funções para criar os campos da etiqueta (Image Editing Commands).
 *
 * Convenções usadas nas chamadas das funções da biblioteca:\n
 *<b>Windows</b>\n
 *  > __stdcall
 *<b>Linux</b>\n
 *  > __cdecl\n
 *\n
 *
 * * OBS: Atente-se ao valor configurado na função <i>SetMedidas</i>.\n
*/

/*! \defgroup ge30 Texto
 * \ingroup ge3
 *
 * \brief Fornece funções para gerar textos na etiqueta.
 *
 * Convenções usadas nas chamadas das funções da biblioteca:\n
 *<b>Windows</b>\n
 *  > __stdcall
 *<b>Linux</b>\n
 *  > __cdecl\n
*/

/*! \defgroup ge31 Código de barras
 * \ingroup ge3
 *
 * \brief Fornece funções para gerar códigos de barras (uma e duas dimensões) na etiqueta.
 *
 * Convenções usadas nas chamadas das funções da biblioteca:\n
 *<b>Windows</b>\n
 *  > __stdcall
 *<b>Linux</b>\n
 *  > __cdecl\n
*/


extern "C"{
    // METODOS SETTER; MANIPULAM AS PROPRIEDADES
    /*****************************************************************************/

    /***************************/
    /* SYSTEM SETTING COMMANDS */
    /***************************/

    /*! \ingroup ge0
     * \brief Define a altura do gap.
     *
     * \param tipo - Parâmetro do tipo numérico que define o tipo de comunicação que será estabelecido.\n
     * \n
     * Conforme tabela a seguir:
     * Valor | Referência
     * ----- | ----------
     * 1     | USB
     * 2     | RS232
     * 3     | TCP/IP
     * \n
     *
     * \param modelo - Parâmetro do tipo caractere que especifica o modelo para conexão.\n
     * \n
     * Conforme lista:
     * > <b>Valores</b>\n
     * > L42\n
     * > L42PRO\n
     * > TT042-50\n
     * \n
     *
     * \param conexao - Parâmetro do tipo caractere que define detalhes de conexão.\n
     * \n
     * Detalhes de conexão:
     * Referência | Valor exemplo
     * :--------- | -------------
     * USB        | USB
     * RS232      | COM2
     * TCP/IP     | 192.168.0.20
     * \n
     *
     * \param param - Parâmetro do tipo numérico auxiliar para a conexão com a impressora.\n
     * \n
     * Utilizado para especificar <b>baudrate</b> ou <b>porta de comunicação TCP/IP</b>.\n
     *
     * * OBS: Quando a conexão estabelecida for a USB esse parâmetro é desconsiderado, podendo ser definido com o valor 0.\n
     * \n
     *
     * \param altura - Parâmetro do tipo numérico que define a altura do gap, em <b>milímetros</b>.\n
     * \n
     * Valores válidos:
     * > Números entre 0 e 99 (0, 1, 2, ..., 99).\n
     * \n
     * Exemplos:
     * Valor | Altura do gap
     * ----- | -------------
     * 5     | Meio milímetro
     * 30    | 3 milímetros
     * \n
     *
     * \return
     * O retorno da função é do tipo numérico.\n
     * A função bem-sucedida deve retornar 0.\n
     *
     * * Para mais informações, consulte #GER_Erro_SystemSetting, #GER_Erro_Conexao, #GER_Erro_Conexao_Serial, #GER_Erro_Conexao_USB ou #GER_Erro_Conexao_TCP\n
     * * OBS: Caso a biblioteca encontre um hardware diferente do esperado a conexão será negada e o valor -5 será retornado.
     */

    ///@cond
    E1_ETIQUETASHARED_EXPORT STDCALL
    ///@endcond
    int SetAlturaGap(int tipo, const char *modelo, const char *conexao, int param, int altura);

    /*! \ingroup ge0
     * \brief Define o tipo de transferência.
     *
     * \param tipo - Parâmetro do tipo numérico que define o tipo de comunicação que será estabelecido.\n
     * \n
     * Conforme tabela a seguir:
     * Valor | Referência
     * ----- | ----------
     * 1     | USB
     * 2     | RS232
     * 3     | TCP/IP
     * \n
     *
     * \param modelo - Parâmetro do tipo caractere que especifica o modelo para conexão.\n
     * \n
     * Conforme lista:
     * > <b>Valores</b>\n
     * > L42\n
     * > L42PRO\n
     * > TT042-50\n
     * \n
     *
     * \param conexao - Parâmetro do tipo caractere que define detalhes de conexão.\n
     * \n
     * Detalhes de conexão:
     * Referência | Valor exemplo
     * :--------- | -------------
     * USB        | USB
     * RS232      | COM2
     * TCP/IP     | 192.168.0.20
     * \n
     *
     * \param param - Parâmetro do tipo numérico auxiliar para a conexão com a impressora.\n
     * \n
     * Utilizado para especificar <b>baudrate</b> ou <b>porta de comunicação TCP/IP</b>.\n
     *
     * * OBS: Quando a conexão estabelecida for a USB esse parâmetro é desconsiderado, podendo ser definido com o valor 0.\n
     * \n
     *
     * \param transferencia - Parâmetro do tipo numérico que define o tipo de transferência.\n
     * \n
     * Valores válidos:
     * Valor | Tipo de transferência
     * ----- | ---------------------
     * 0     | Térmica direta
     * 1     | Transferência térmica
     * \n
     *
     * \return
     * O retorno da função é do tipo numérico.\n
     * A função bem-sucedida deve retornar 0.\n
     *
     * * Para mais informações, consulte #GER_Erro_SystemSetting, #GER_Erro_Conexao, #GER_Erro_Conexao_Serial, #GER_Erro_Conexao_USB ou #GER_Erro_Conexao_TCP\n
     * * OBS: Caso a biblioteca encontre um hardware diferente do esperado a conexão será negada e o valor -5 será retornado.
     */

    ///@cond
    E1_ETIQUETASHARED_EXPORT STDCALL
    ///@endcond
    int SetTipoTransferencia(int tipo, const char *modelo, const char *conexao, int param, int transferencia);

    /*! \ingroup ge0
     * \brief Define o baudrate, o comprimento dos dados, a paridade e o número de stop bits.
     * * OBS: As impressoras suportam parcialmente esta função.
     *
     * \param tipo - Parâmetro do tipo numérico que define o tipo de comunicação que será estabelecido.\n
     * \n
     * Conforme tabela a seguir:
     * Valor | Referência
     * ----- | ----------
     * 1     | USB
     * 2     | RS232
     * 3     | TCP/IP
     * \n
     *
     * \param modelo - Parâmetro do tipo caractere que especifica o modelo para conexão.\n
     * \n
     * Conforme lista:
     * > <b>Valores</b>\n
     * > L42\n
     * > L42PRO\n
     * > TT042-50\n
     * \n
     *
     * \param conexao - Parâmetro do tipo caractere que define detalhes de conexão.\n
     * \n
     * Detalhes de conexão:
     * Referência | Valor exemplo
     * :--------- | -------------
     * USB        | USB
     * RS232      | COM2
     * TCP/IP     | 192.168.0.20
     * \n
     *
     * \param param - Parâmetro do tipo numérico auxiliar para a conexão com a impressora.\n
     * \n
     * Utilizado para especificar <b>baudrate</b> ou <b>porta de comunicação TCP/IP</b>.\n
     *
     * * OBS: Quando a conexão estabelecida for a USB esse parâmetro é desconsiderado, podendo ser definido com o valor 0.\n
     * \n
     *
     * \param baudrate - Parâmetro do tipo numérico que define o baudrate.\n
     * \n
     * Valores válidos:
     * Valor | Baudrate
     * ----- | --------
     * 0     | 9600
     * 1     | 600
     * 2     | 2400
     * 3     | 19200
     * 4     | 4800
     * 5     | 38400
     * 6     | 1200
     * 7     | 9600
     * 8     | 57600
     * 9     | 115200
     * \n
     *
     * * OBS: Certifique-se de que a impressora suporta o baudrate selecionado.\n
     * \n
     *
     * \param dataLength - Parâmetro do tipo numérico que define o comprimento dos dados.\n
     * \n
     * Valores válidos:
     * Valor | Comprimento dos dados
     * ----- | ---------------------
     * 7     | 7-bit data
     * 8     | 8-bit data
     * \n
     *
     * \param parity - Parâmetro do tipo numérico que define a paridade.\n
     * \n
     * Valores válidos:
     * Valor | Paridade
     * ----- | --------
     * 0     | None
     * 1     | Even
     * 2     | Odd
     * \n
     *
     * \param stopBit - Parâmetro do tipo numérico que define o número de stop bits.\n
     * \n
     * Valores válidos:
     * Valor | Número de stop bits
     * ----- | -------------------
     * 1     | 1 stop bit
     * 2     | 2 stop bits
     * \n
     *
     * \return
     * O retorno da função é do tipo numérico.\n
     * A função bem-sucedida deve retornar 0.\n
     *
     * * Para mais informações, consulte #GER_Erro_SystemSetting, #GER_Erro_Conexao, #GER_Erro_Conexao_Serial, #GER_Erro_Conexao_USB ou #GER_Erro_Conexao_TCP\n
     * * OBS: Caso a biblioteca encontre um hardware diferente do esperado a conexão será negada e o valor -5 será retornado.
     */

    ///@cond
    E1_ETIQUETASHARED_EXPORT STDCALL
    ///@endcond
    int SetBaudrate(int tipo, const char *modelo, const char *conexao, int param, int baudrate, int dataLength, int parity, int stopBit);

    /*! \ingroup ge0
     * \brief Define o symbol set das fontes Smooth ASD.
     * * OBS: As impressoras não suportam esta função.
     *
     * \param tipo - Parâmetro do tipo numérico que define o tipo de comunicação que será estabelecido.\n
     * \n
     * Conforme tabela a seguir:
     * Valor | Referência
     * ----- | ----------
     * 1     | USB
     * 2     | RS232
     * 3     | TCP/IP
     * \n
     *
     * \param modelo - Parâmetro do tipo caractere que especifica o modelo para conexão.\n
     * \n
     * Conforme lista:
     * > <b>Valores</b>\n
     * > L42\n
     * > L42PRO\n
     * > TT042-50\n
     * \n
     *
     * \param conexao - Parâmetro do tipo caractere que define detalhes de conexão.\n
     * \n
     * Detalhes de conexão:
     * Referência | Valor exemplo
     * :--------- | -------------
     * USB        | USB
     * RS232      | COM2
     * TCP/IP     | 192.168.0.20
     * \n
     *
     * \param param - Parâmetro do tipo numérico auxiliar para a conexão com a impressora.\n
     * \n
     * Utilizado para especificar <b>baudrate</b> ou <b>porta de comunicação TCP/IP</b>.\n
     *
     * * OBS: Quando a conexão estabelecida for a USB esse parâmetro é desconsiderado, podendo ser definido com o valor 0.\n
     * \n
     *
     * \param symbol - Parâmetro do tipo numérico que define o symbol set das fontes Smooth ASD.\n
     * \n
     * Valores válidos:
     * Valor | Symbol set
     * ----- | ----------
     * 0     | USASCII
     * 1     | Reino Unido
     * 2     | Espanhol
     * 3     | Sueco
     * 4     | Francês
     * 5     | Alemão
     * 6     | Italiano
     * 7     | Dinamarquês/Norueguês
     * \n
     *
     * \return
     * O retorno da função é do tipo numérico.\n
     * A função bem-sucedida deve retornar 0.\n
     *
     * * Para mais informações, consulte #GER_Erro_SystemSetting, #GER_Erro_Conexao, #GER_Erro_Conexao_Serial, #GER_Erro_Conexao_USB ou #GER_Erro_Conexao_TCP\n
     * * OBS: Caso a biblioteca encontre um hardware diferente do esperado a conexão será negada e o valor -5 será retornado.
     */

    ///@cond
    E1_ETIQUETASHARED_EXPORT STDCALL
    ///@endcond
    int SetSymbolASD(int tipo, const char *modelo, const char *conexao, int param, int symbol);


    /*************************/
    /* SYSTEM LEVEL COMMANDS */
    /*************************/

    /*! \ingroup ge1
     * \brief Define o sistema de unidades adotado para a configuração dos campos da etiqueta e de
     * algumas propriedades.
     *
     * \param medida - Parâmetro do tipo numérico que define se o sistema de unidades utilizado será
     * o métrico (cm/100) ou o imperial (pol/100); cm = centímetro, pol = polegada.\n
     * \n
     * Se o sistema escolhido for o métrico, os valores passados aos parâmetros relacionados
     * ao posicionamento e às dimensões dos campos da etiqueta (coordenadas, altura e comprimento,
     * por exemplo) estarão em centésimos de centímetro.\n
     * \n
     * Se o sistema escolhido for o imperial, os valores passados àqueles parâmetros estarão em
     * centésimos de polegada. O sistema de unidades determinado aqui também afetará outras propriedades
     * da impressão, como o <i>back-feed</i>, o <i>offset de coluna</i> e o <i>offset de linha</i>.\n
     * \n
     * Valores válidos:
     * Valor | Sistema de Unidades
     * ----- | -------------------
     * 0     | Métrico
     * 1     | Imperial
     * \n
     *
     * * Se esta função não for usada, assume-se o valor 0.\n
     * \n
     *
     * \return
     * O retorno da função é do tipo numérico.\n
     * A função bem-sucedida deve retornar 0.\n
     *
     * * Para mais informações, consulte #GER_Erro_SystemLevel
     */

    ///@cond
    E1_ETIQUETASHARED_EXPORT STDCALL
    ///@endcond
    int SetMedidas(int medida);

    /*! \ingroup ge1
     * \brief Define a distância em que a etiqueta será deslocada da impressora após a impressão;
     * isso faz com que a etiqueta fique a uma distância conveniente para o usuário "rasgá-lo" do
     * restante do papel.
     * * OBS: A impressora L42PRO não suporta esta função.
     *
     * \param backfeed - Parâmetro do tipo numérico que define o back-feed de impressão.\n
     * \n
     * Valores válidos:
     * > Números entre 220 e 999 (220, 221, 222, ..., 999).\n
     * \n
     * Exemplos:
     * Valor | Back-feed (métrico) | Back-feed (imperial)
     * ----- | ------------------- | --------------------
     * 220   | (Valor padrão)      | (Valor padrão)
     * 250   | +3 milímetros       | +3 décimos de polegada
     * 320   | +1 centímetro       | +1 polegada
     * \n
     *
     * * Se esta função não for usada, assume-se o valor 250.\n
     * * OBS: Atente-se ao valor configurado na função <i>SetMedidas</i>.\n
     * \n
     *
     * \return
     * O retorno da função é do tipo numérico.\n
     * A função bem-sucedida deve retornar 0.\n
     *
     * * Para mais informações, consulte #GER_Erro_SystemLevel
     */

    ///@cond
    E1_ETIQUETASHARED_EXPORT STDCALL
    ///@endcond
    int SetBackfeed(int backfeed);

    /*! \ingroup ge1
     * \brief Define a posição inicial de impressão.
     * * OBS: A impressora L42PRO não suporta esta função.
     *
     * \param printStPos - Parâmetro do tipo numérico que define a posição inicial de impressão. O
     * valor padrão 220 configura a posição incial exatamente abaixo da linha TPH (cabeça de impressão).\n
     * \n
     * Valores válidos:
     * > Números entre 0 e 9999 (0, 1, 2, ..., 9999).\n
     * \n
     *
     * * Se esta função não for usada, assume-se o valor 220.\n
     * * OBS: Use esta função somente se realmente necessário.\n
     * \n
     *
     * \return
     * O retorno da função é do tipo numérico.\n
     * A função bem-sucedida deve retornar 0.\n
     *
     * * Para mais informações, consulte #GER_Erro_SystemLevel
     */

    ///@cond
    E1_ETIQUETASHARED_EXPORT STDCALL
    ///@endcond
    int SetPrintStPos(int printStPos);

    /*! \ingroup ge1
     * \brief Define se o sensor a ser usado na impressão será o transmissivo ou o reflexivo.
     *
     * \param sensor - Parâmetro do tipo numérico que define o sensor a ser utilizado na impressão.\n
     * \n
     * Valores válidos:
     * Valor | Sensor
     * ----- | ------
     * 0     | Transmissivo
     * 1     | Reflexivo
     * \n
     *
     * * Se esta função não for usada, assume-se o valor 0.\n
     * \n
     *
     * \return
     * O retorno da função é do tipo numérico.\n
     * A função bem-sucedida deve retornar 0.\n
     *
     * * Para mais informações, consulte #GER_Erro_SystemLevel
     */

    ///@cond
    E1_ETIQUETASHARED_EXPORT STDCALL
    ///@endcond
    int SetSensor(int sensor);

    /*! \ingroup ge1
     * \brief Ativa (ou desativa) o modo de impressão contínuo e configura a distância de papel a ser impresso.
     *
     * \param modoContinuo - Parâmetro do tipo numérico que ativa e define a distância de impressão do modo contínuo,
     * isto é, a quantidade de papel que será impresso entre o início e o final da impressão, em centésimos de centímetro
     * (ou de polegada).\n
     * \n
     * Se o modo contínuo for usado, as configurações feitas nas funções <i>SetSensor</i> e <i>SetPrintStPos</i> serão
     * ignoradas.\n
     * \n
     * Valores válidos:
     * > Números entre 0 e 9999 (0, 1, 2, ..., 9999).\n
     * \n
     * Exemplos:
     * Valor | Distância (métrico) | Distância (imperial)
     * ----- | ------------------- | --------------------
     * 5     | Meio milímetro      | 5 centésimos de polegada
     * 10    | 1 milímetro         | 1 décimo de polegada
     * 200   | 2 centímetros       | 2 polegadas
     * 4500  | 45 centímetros      | 45 polegadas
     * \n
     *
     * * Se esta função não for usada, assume-se o valor 0.\n
     * * OBS: Atente-se ao valor configurado na função <i>SetMedidas</i>.\n
     * * OBS: Para desativar/não usar o modo contínuo, use o valor 0.\n
     * \n
     *
     * \return
     * O retorno da função é do tipo numérico.\n
     * A função bem-sucedida deve retornar 0.\n
     *
     * * Para mais informações, consulte #GER_Erro_SystemLevel
     */

    ///@cond
    E1_ETIQUETASHARED_EXPORT STDCALL
    ///@endcond
    int SetModoContinuo(int modoContinuo);

    /*! \ingroup ge1
     * \brief Define o comprimento (altura) máximo da etiqueta.
     *
     * \param length - Parâmetro do tipo numérico que define o comprimento (altura) máximo da etiqueta.\n
     * \n
     * Valores válidos:
     * > Números entre 0 e 9999 (0, 1, 2, ..., 9999).\n
     * \n
     * Exemplos:
     * Valor | Length (métrico) | Length (imperial)
     * ----- | ---------------- | -----------------
     * 300   | 3 centímetros    | 3 polegadas
     * 1200  | 12 centímetros   | 12 polegadas
     * \n
     *
     * * Se esta função não for usada, assume-se o valor 0.\n
     * * OBS: Atente-se ao valor configurado na função <i>SetMedidas</i>.\n
     * * OBS: Os valores suportados variam de 1\" a 12\".\n
     * * OBS: O valor 0 ignora esta função.\n
     * \n
     *
     * \return
     * O retorno da função é do tipo numérico.\n
     * A função bem-sucedida deve retornar 0.\n
     *
     * * Para mais informações, consulte #GER_Erro_SystemLevel
     */

    ///@cond
    E1_ETIQUETASHARED_EXPORT STDCALL
    ///@endcond
    int SetLength(int length);

// HA' INCERTEZA QUANTO AO USO DE CUTTER/PEELER NAS IMPRESSORAS (SUPORTE)
//    ///@cond
//    E1_ETIQUETASHARED_EXPORT STDCALL
//    ///@endcond
//    int SetCutterPeeler(int cutterPeeler);


    /*****************************/
    /* LABEL FORMATTING COMMANDS */
    /*****************************/

    /*! \ingroup ge2
     * \brief Define a margem inferior da impressão (a distância, a partir da margem inferior da etiqueta,
     * em que o eixo y de impressão será posicionado).
     *
     * \param offsetLinha - Parâmetro do tipo numérico que define a posição do eixo y no plano da
     * etiqueta, de baixo para cima.\n
     * \n
     * Valores válidos:
     * > Números entre 0 e 9999 (0, 1, 2, ..., 9999).\n
     * \n
     * Exemplos:
     * Valor | Offset de Linha (métrico) | Offset de Linha (imperial)
     * ----- | ------------------------- | --------------------------
     * 5     | Meio milímetro            | 5 centésimos de polegada
     * 10    | 1 milímetro               | 1 décimo de polegada
     * 200   | 2 centímetros             | 2 polegadas
     * 4500  | 45 centímetros            | 45 polegadas
     * \n
     *
     * * Se esta função não for usada, assume-se o valor 0.\n
     * * OBS: Atente-se ao valor configurado na função <i>SetMedidas</i>.\n
     * \n
     *
     * \return
     * O retorno da função é do tipo numérico.\n
     * A função bem-sucedida deve retornar 0.\n
     *
     * * Para mais informações, consulte #GER_Erro_LabelFormatting
     */

    ///@cond
    E1_ETIQUETASHARED_EXPORT STDCALL
    ///@endcond
    int SetOffsetLinha(int offsetLinha);

    /*! \ingroup ge2
     * \brief Define a margem esquerda da impressão (a distância, a partir da margem esquerda da etiqueta,
     * em que o eixo x de impressão será posicionado).
     *
     * \param offsetColuna - Parâmetro do tipo numérico que define a posição do eixo x no plano da
     * etiqueta, da esquerda para a direita.\n
     * \n
     * Valores válidos:
     * > Números entre 0 e 9999 (0, 1, 2, ..., 9999).\n
     * \n
     * Exemplos:
     * Valor | Offset de Coluna (métrico) | Offset de Coluna (imperial)
     * ----- | -------------------------- | ---------------------------
     * 5     | Meio milímetro             | 5 centésimos de polegada
     * 10    | 1 milímetro                | 1 décimo de polegada
     * 200   | 2 centímetros              | 2 polegadas
     * 4500  | 45 centímetros             | 45 polegadas
     * \n
     *
     * * Se esta função não for usada, assume-se o valor 0.\n
     * * OBS: Atente-se ao valor configurado na função <i>SetMedidas</i>.\n
     * \n
     *
     * \return
     * O retorno da função é do tipo numérico.\n
     * A função bem-sucedida deve retornar 0.\n
     *
     * * Para mais informações, consulte #GER_Erro_LabelFormatting
     */

    ///@cond
    E1_ETIQUETASHARED_EXPORT STDCALL
    ///@endcond
    int SetOffsetColuna(int offsetColuna);

    /*! \ingroup ge2
     * \brief Define a velocidade de impressão.
     *
     * \param velImpressao - Parâmetro do tipo numérico que define a velocidade de impressão.\n
     * \n
     * Valores válidos:
     * Valor | Velocidade
     * ----- | ----------
     * 0     | 1,0"/seg
     * 1     | 1,5"/seg
     * 2     | 2,0"/seg
     * 3     | 2,5"/seg
     * 4     | 3,0"/seg
     * 5     | 3,5"/seg
     * 6     | 4,0"/seg
     * 7     | 4,5"/seg
     * 8     | 5,0"/seg
     * 9     | 5,5"/seg
     * 10    | 6,0"/seg
     * 11    | 7,0"/seg
     * \n
     *
     * * Se esta função não for usada, assume-se o valor 2.\n
     * * OBS: Certifique-se de que a impressora suporta a velocidade selecionada.\n
     * \n
     *
     * \return
     * O retorno da função é do tipo numérico.\n
     * A função bem-sucedida deve retornar 0.\n
     *
     * * Para mais informações, consulte #GER_Erro_LabelFormatting
     */

    ///@cond
    E1_ETIQUETASHARED_EXPORT STDCALL
    ///@endcond
    int SetVelImpressao(int velImpressao);

    /*! \ingroup ge2
     * \brief Define a largura e a altura do pixel que será usado na etiqueta.
     *
     * \param largura - Parâmetro do tipo numérico que define a largura do pixel.\n
     * \n
     * Valores válidos:
     * > 1 ou 2 (1, 2).\n
     * \n
     *
     * * Se esta função não for usada, assume-se o valor 1.\n
     * \n
     *
     * \param altura - Parâmetro do tipo numérico que define a altura do pixel.\n
     * \n
     * Valores válidos:
     * > Números entre 1 e 3 (1, 2, 3).\n
     * \n
     *
     * * Se esta função não for usada, assume-se o valor 1.\n
     * \n
     *
     * \return
     * O retorno da função é do tipo numérico.\n
     * A função bem-sucedida deve retornar 0.\n
     *
     * * Para mais informações, consulte #GER_Erro_LabelFormatting
     */

    ///@cond
    E1_ETIQUETASHARED_EXPORT STDCALL
    ///@endcond
    int SetTamPixel(int largura, int altura);

    /*! \ingroup ge2
     * \brief Define o calor de impressão, isto é, o quão forte será a cor da impressão.
     *
     * \param calor - Parâmetro do tipo numérico que define o calor de impressão.\n
     * \n
     * Valores válidos:
     * > Números entre 0 e 20 (0, 1, 2, ..., 20).\n
     * \n
     *
     * * Se esta função não for usada, assume-se o valor 9.\n
     * \n
     *
     * \return
     * O retorno da função é do tipo numérico.\n
     * A função bem-sucedida deve retornar 0.\n
     *
     * * Para mais informações, consulte #GER_Erro_LabelFormatting
     */

    ///@cond
    E1_ETIQUETASHARED_EXPORT STDCALL
    ///@endcond
    int SetCalor(int calor);

    /*! \ingroup ge2
     * \brief Define quantas vezes a etiqueta será impressa.
     *
     * \param qtde - Parâmetro do tipo numérico que define a quantidade de vezes que a etiqueta será impressa.\n
     * \n
     * Valores válidos:
     * > Números entre 0 e 9999 (0, 1, 2, ..., 9999).\n
     * \n
     *
     * * Se esta função não for usada, assume-se o valor 1.\n
     * \n
     *
     * \return
     * O retorno da função é do tipo numérico.\n
     * A função bem-sucedida deve retornar 0.\n
     *
     * * Para mais informações, consulte #GER_Erro_LabelFormatting
     */

    ///@cond
    E1_ETIQUETASHARED_EXPORT STDCALL
    ///@endcond
    int SetQtde(int qtde);

    /*! \ingroup ge2
     * \brief Define se o número zero (0) deve ser "cortado" ou não, para distingui-lo da letra O.
     *
     * \param cortarZero - Parâmetro do tipo numérico que define se o zero será cortado na impressão.\n
     * \n
     * Valores válidos:
     * Valor | Cortar zero?
     * ----- | ------------
     * 0     | Não
     * 1     | Sim
     * \n
     *
     * * Se esta função não for usada, assume-se o valor 1.\n
     * * OBS: Esta propriedade só afeta as fontes alfanuméricas de 0 a 6 (veja a função <i>GerarTexto</i>).\n
     * \n
     *
     * \return
     * O retorno da função é do tipo numérico.\n
     * A função bem-sucedida deve retornar 0.\n
     *
     * * Para mais informações, consulte #GER_Erro_LabelFormatting
     */

    ///@cond
    E1_ETIQUETASHARED_EXPORT STDCALL
    ///@endcond
    int SetCortarZero(int cortarZero);

// HA' INCERTEZA QUANTO AO USO DE CUTTER NAS IMPRESSORAS (SUPORTE)
//    ///@cond
//    E1_ETIQUETASHARED_EXPORT STDCALL
//    ///@endcond
//    int SetCutAmount(int cutAmount);

    /*! \ingroup ge2
     * \brief Define o modo lógico de impressão dos campos
     *
     * \param logicImgMode - Parâmetro do tipo numérico que define se a impressora irá operar
     * no modo lógico XOR (eXclusive OR) ou no modo lógico OR.\n
     * \n
     * Este parâmetro influencia no resultado da impressão de campos com partes sobrepostas: no
     * modo XOR, essas partes não seriam impressas e, no modo OR, seriam.\n
     * \n
     * Suponha o caso em que um texto estaria dentro de uma linha sólida (e totalmente sobreposto
     * pela linha, portanto): no modo XOR, o texto não seria impresso, permitindo sua visibilidade
     * e, no modo OR, o texto seria impresso junto com a linha, tornando-o indistinguível.\n
     * \n
     * Valores válidos:
     * Valor | Modo lógico
     * ----- | -----------
     * 1     | XOR
     * 2     | OR
     * \n
     *
     * * Se esta função não for usada, assume-se o valor 1.\n
     * \n
     *
     * \return
     * O retorno da função é do tipo numérico.\n
     * A função bem-sucedida deve retornar 0.\n
     *
     * * Para mais informações, consulte #GER_Erro_LabelFormatting
     */

    ///@cond
    E1_ETIQUETASHARED_EXPORT STDCALL
    ///@endcond
    int SetLogicImgMode(int logicImgMode);

    /*! \ingroup ge2
     * \brief Define se os textos serão espelhados ou não durante a impressão.
     *
     * \param mirror - Parâmetro do tipo numérico que define se o texto será espelhado na impressão.\n
     * \n
     * Valores válidos:
     * Valor | Espelhar?
     * ----- | ------------
     * 0     | Não
     * 1     | Sim
     * \n
     *
     * * Se esta função não for usada, assume-se o valor 0.\n
     * \n
     *
     * \return
     * O retorno da função é do tipo numérico.\n
     * A função bem-sucedida deve retornar 0.\n
     *
     * * Para mais informações, consulte #GER_Erro_LabelFormatting
     */

    ///@cond
    E1_ETIQUETASHARED_EXPORT STDCALL
    ///@endcond
    int SetMirror(int mirror);


    // METODOS PARA GERACAO DOS CAMPOS DA ETIQUETA; MANIPULAM O VETOR campos[]
    /*****************************************************************************/

    /**************************/
    /* IMAGE EDITING COMMANDS */
    /**************************/

    /*! \ingroup ge30
     * \brief Gera um texto na etiqueta usando as fontes alfanuméricas.
     *
     * \param rotacao - Parâmetro do tipo numérico que define a rotação do texto em relação ao plano da etiqueta.\n
     * \n
     * Valores válidos:
     * Valor | Rotação
     * ----- | -------
     * 1     | Retrato
     * 2     | Paisagem reversa
     * 3     | Retrato reverso
     * 4     | Paisagem
     * \n
     *
     * \param fonte - Parâmetro do tipo numérico que define a fonte do texto.\n
     * \n
     * Valores válidos:
     * Valor | Fonte
     * ----- | ------
     * 0     | ASCII Character Set
     * 1     | ASCII+Extension Character Set
     * 2     | ASCII+Extension Character Set
     * 3     | Alphanumeric Uppercase
     * 4     | Alphanumeric Uppercase
     * 5     | Alphanumeric Uppercase
     * 6     | Alphanumeric Uppercase
     * 7     | OCR-A
     * 8     | OCR-B
     * \n
     *
     * \param multH - Parâmetro do tipo numérico que define a multiplicação horizontal (largura) da fonte.\n
     * \n
     * Valores válidos:
     * > Números entre 0 e 24 (0, 1, 2, ..., 24).\n
     * \n
     *
     * \param multV - Parâmetro do tipo numérico que define a multiplicação vertical (altura) da fonte.\n
     * \n
     * Valores válidos:
     * > Números entre 0 e 24 (0, 1, 2, ..., 24).\n
     * \n
     *
     * \param coordY - Parâmetro do tipo numérico que define a coordenada Y de impressão, isto é, a quantos
     * centésimos de centímetro (ou de polegada) do eixo y (no plano da etiqueta) o texto será impresso.\n
     * \n
     * Valores válidos:
     * > Números entre 0 e 9999 (0, 1, 2, ..., 9999).\n
     * \n
     * Exemplos:
     * Valor | Coord. Y (métrico) | Coord. Y (imperial)
     * ----- | ------------------ | -------------------
     * 5     | Meio milímetro     | 5 centésimos de polegada
     * 10    | 1 milímetro        | 1 décimo de polegada
     * 200   | 2 centímetros      | 2 polegadas
     * 4500  | 45 centímetros     | 45 polegadas
     * \n
     *
     * \param coordX - Parâmetro do tipo numérico que define a coordenada X de impressão, isto é, a quantos
     * centésimos de centímetro (ou de polegada) do eixo x (no plano da etiqueta) o texto será impresso.\n
     * \n
     * Valores válidos:
     * > Números entre 0 e 9999 (0, 1, 2, ..., 9999).\n
     * \n
     * Exemplos:
     * Valor | Coord. X (métrico) | Coord. X (imperial)
     * ----- | ------------------ | -------------------
     * 5     | Meio milímetro     | 5 centésimos de polegada
     * 10    | 1 milímetro        | 1 décimo de polegada
     * 200   | 2 centímetros      | 2 polegadas
     * 4500  | 45 centímetros     | 45 polegadas
     * \n
     *
     * \param texto - Parâmetro do tipo caractere que define o texto a ser impresso.\n
     * \n
     * Valores válidos:
     * > Qualquer string de dados imprimíveis; máximo de 255 caracteres.\n
     * \n
     *
     * \return
     * O retorno da função é do tipo numérico.\n
     * A função bem-sucedida deve retornar 0.\n
     *
     * * Para mais informações, consulte #GER_Erro_Texto
    */

    ///@cond
    E1_ETIQUETASHARED_EXPORT STDCALL
    ///@endcond
    int GerarTexto(int rotacao, int fonte, int multH, int multV, int coordY, int coordX, const char *texto);

    /*! \ingroup ge30
     * \brief Gera um texto na etiqueta usando as fontes Smooth ASD.
     *
     * \param rotacao - Parâmetro do tipo numérico que define a rotação do texto em relação ao plano da etiqueta.\n
     * \n
     * Valores válidos:
     * Valor | Rotação
     * ----- | -------
     * 1     | Retrato
     * 2     | Paisagem reversa
     * 3     | Retrato reverso
     * 4     | Paisagem
     * \n
     *
     * \param tamanho - Parâmetro do tipo numérico que define o tamanho da fonte.\n
     * \n
     * Valores válidos:
     * Valor | Tamanho
     * ----- | -------
     * 0     | 4 pontos
     * 1     | 6 pontos
     * 2     | 8 pontos
     * 3     | 10 pontos
     * 4     | 12 pontos
     * 5     | 14 pontos
     * 6     | 18 pontos
     * \n
     *
     * \param multH - Parâmetro do tipo numérico que define a multiplicação horizontal (largura) da fonte.\n
     * \n
     * Valores válidos:
     * > Números entre 0 e 24 (0, 1, 2, ..., 24).\n
     * \n
     *
     * \param multV - Parâmetro do tipo numérico que define a multiplicação vertical (altura) da fonte.\n
     * \n
     * Valores válidos:
     * > Números entre 0 e 24 (0, 1, 2, ..., 24).\n
     * \n
     *
     * \param coordY - Parâmetro do tipo numérico que define a coordenada Y de impressão, isto é, a quantos
     * centésimos de centímetro (ou de polegada) do eixo y (no plano da etiqueta) o texto será impresso.\n
     * \n
     * Valores válidos:
     * > Números entre 0 e 9999 (0, 1, 2, ..., 9999).\n
     * \n
     * Exemplos:
     * Valor | Coord. Y (métrico) | Coord. Y (imperial)
     * ----- | ------------------ | -------------------
     * 5     | Meio milímetro     | 5 centésimos de polegada
     * 10    | 1 milímetro        | 1 décimo de polegada
     * 200   | 2 centímetros      | 2 polegadas
     * 4500  | 45 centímetros     | 45 polegadas
     * \n
     *
     * \param coordX - Parâmetro do tipo numérico que define a coordenada X de impressão, isto é, a quantos
     * centésimos de centímetro (ou de polegada) do eixo x (no plano da etiqueta) o texto será impresso.\n
     * \n
     * Valores válidos:
     * > Números entre 0 e 9999 (0, 1, 2, ..., 9999).\n
     * \n
     * Exemplos:
     * Valor | Coord. X (métrico) | Coord. X (imperial)
     * ----- | ------------------ | -------------------
     * 5     | Meio milímetro     | 5 centésimos de polegada
     * 10    | 1 milímetro        | 1 décimo de polegada
     * 200   | 2 centímetros      | 2 polegadas
     * 4500  | 45 centímetros     | 45 polegadas
     * \n
     *
     * \param texto - Parâmetro do tipo caractere que define o texto a ser impresso.\n
     * \n
     * Valores válidos:
     * > Qualquer string de dados imprimíveis; máximo de 255 caracteres.\n
     * \n
     *
     * \return
     * O retorno da função é do tipo numérico.\n
     * A função bem-sucedida deve retornar 0.\n
     *
     * * Para mais informações, consulte #GER_Erro_TextoASD
     */

    ///@cond
    E1_ETIQUETASHARED_EXPORT STDCALL
    ///@endcond
    int GerarTextoASD(int rotacao, int tamanho, int multH, int multV, int coordY, int coordX, const char *texto);

    /*! \ingroup ge30
     * \brief Gera um texto na etiqueta usando as fontes Courier.
     *
     * \param rotacao - Parâmetro do tipo numérico que define a rotação do texto em relação ao plano da etiqueta.\n
     * \n
     * Valores válidos:
     * Valor | Rotação
     * ----- | -------
     * 1     | Retrato
     * 2     | Paisagem reversa
     * 3     | Retrato reverso
     * 4     | Paisagem
     * \n
     *
     * \param symbol - Parâmetro do tipo numérico que define o symbol set.\n
     * \n
     * Valores válidos:
     * Valor | Symbol
     * ----- | ------
     * 0     | Roman-8
     * 1     | ECMA-94
     * 2     | PC set
     * 3     | PC set A
     * 4     | PC set B
     * 5     | Legal
     * 6     | Greek
     * 7     | Russian
     * \n
     *
     * \param multH - Parâmetro do tipo numérico que define a multiplicação horizontal (largura) da fonte.\n
     * \n
     * Valores válidos:
     * > Números entre 0 e 24 (0, 1, 2, ..., 24).\n
     * \n
     *
     * \param multV - Parâmetro do tipo numérico que define a multiplicação vertical (altura) da fonte.\n
     * \n
     * Valores válidos:
     * > Números entre 0 e 24 (0, 1, 2, ..., 24).\n
     * \n
     *
     * \param coordY - Parâmetro do tipo numérico que define a coordenada Y de impressão, isto é, a quantos
     * centésimos de centímetro (ou de polegada) do eixo y (no plano da etiqueta) o texto será impresso.\n
     * \n
     * Valores válidos:
     * > Números entre 0 e 9999 (0, 1, 2, ..., 9999).\n
     * \n
     * Exemplos:
     * Valor | Coord. Y (métrico) | Coord. Y (imperial)
     * ----- | ------------------ | -------------------
     * 5     | Meio milímetro     | 5 centésimos de polegada
     * 10    | 1 milímetro        | 1 décimo de polegada
     * 200   | 2 centímetros      | 2 polegadas
     * 4500  | 45 centímetros     | 45 polegadas
     * \n
     *
     * \param coordX - Parâmetro do tipo numérico que define a coordenada X de impressão, isto é, a quantos
     * centésimos de centímetro (ou de polegada) do eixo x (no plano da etiqueta) o texto será impresso.\n
     * \n
     * Valores válidos:
     * > Números entre 0 e 9999 (0, 1, 2, ..., 9999).\n
     * \n
     * Exemplos:
     * Valor | Coord. X (métrico) | Coord. X (imperial)
     * ----- | ------------------ | -------------------
     * 5     | Meio milímetro     | 5 centésimos de polegada
     * 10    | 1 milímetro        | 1 décimo de polegada
     * 200   | 2 centímetros      | 2 polegadas
     * 4500  | 45 centímetros     | 45 polegadas
     * \n
     *
     * \param texto - Parâmetro do tipo caractere que define o texto a ser impresso.\n
     * \n
     * Valores válidos:
     * > Qualquer string de dados imprimíveis; máximo de 255 caracteres.\n
     * \n
     *
     * \return
     * O retorno da função é do tipo numérico.\n
     * A função bem-sucedida deve retornar 0.\n
     *
     * * Para mais informações, consulte #GER_Erro_TextoCourier
     */

    ///@cond
    E1_ETIQUETASHARED_EXPORT STDCALL
    ///@endcond
    int GerarTextoCourier(int rotacao, int symbol, int multH, int multV, int coordY, int coordX, const char *texto);

    /*! \ingroup ge3
     * \brief Gera uma linha na etiqueta.
     *
     * \param coordY - Parâmetro do tipo numérico que define a coordenada Y de impressão, isto é, a quantos
     * centésimos de centímetro (ou de polegada) do eixo y (no plano da etiqueta) a linha será impressa.\n
     * \n
     * Valores válidos:
     * > Números entre 0 e 9999 (0, 1, 2, ..., 9999).\n
     * \n
     * Exemplos:
     * Valor | Coord. Y (métrico) | Coord. Y (imperial)
     * ----- | ------------------ | -------------------
     * 5     | Meio milímetro     | 5 centésimos de polegada
     * 10    | 1 milímetro        | 1 décimo de polegada
     * 200   | 2 centímetros      | 2 polegadas
     * 4500  | 45 centímetros     | 45 polegadas
     * \n
     *
     * \param coordX - Parâmetro do tipo numérico que define a coordenada X de impressão, isto é, a quantos
     * centésimos de centímetro (ou de polegada) do eixo x (no plano da etiqueta) a linha será impressa.\n
     * \n
     * Valores válidos:
     * > Números entre 0 e 9999 (0, 1, 2, ..., 9999).\n
     * \n
     * Exemplos:
     * Valor | Coord. X (métrico) | Coord. X (imperial)
     * ----- | ------------------ | -------------------
     * 5     | Meio milímetro     | 5 centésimos de polegada
     * 10    | 1 milímetro        | 1 décimo de polegada
     * 200   | 2 centímetros      | 2 polegadas
     * 4500  | 45 centímetros     | 45 polegadas
     * \n
     *
     * \param comprimento - Parâmetro do tipo numérico que define o comprimento da linha,
     * em centésimos de centímetro (ou de polegada).\n
     * \n
     * Valores válidos:
     * > Números entre 0 e 9999 (0, 1, 2, ..., 9999).\n
     * \n
     * Exemplos:
     * Valor | Comprimento (métrico) | Comprimento (imperial)
     * ----- | --------------------- | ----------------------
     * 5     | Meio milímetro        | 5 centésimos de polegada
     * 10    | 1 milímetro           | 1 décimo de polegada
     * 200   | 2 centímetros         | 2 polegadas
     * 4500  | 45 centímetros        | 45 polegadas
     * \n
     *
     * \param altura - Parâmetro do tipo numérico que define a altura da linha,
     * em centésimos de centímetro (ou de polegada).\n
     * \n
     * Valores válidos:
     * > Números entre 0 e 9999 (0, 1, 2, ..., 9999).\n
     * \n
     * Exemplos:
     * Valor | Altura (métrico) | Altura (imperial)
     * ----- | ---------------- | -----------------
     * 5     | Meio milímetro   | 5 centésimos de polegada
     * 10    | 1 milímetro      | 1 décimo de polegada
     * 200   | 2 centímetros    | 2 polegadas
     * 4500  | 45 centímetros   | 45 polegadas
     * \n
     *
     * \return
     * O retorno da função é do tipo numérico.\n
     * A função bem-sucedida deve retornar 0.\n
     *
     * * Para mais informações, consulte #GER_Erro_Linha
    */

    ///@cond
    E1_ETIQUETASHARED_EXPORT STDCALL
    ///@endcond
    int GerarLinha(int coordY, int coordX, int comprimento, int altura);

    /*! \ingroup ge3
     * \brief Gera um box na etiqueta.
     *
     * \param coordY - Parâmetro do tipo numérico que define a coordenada Y de impressão, isto é, a quantos
     * centésimos de centímetro (ou de polegada) do eixo y (no plano da etiqueta) o box será impresso.\n
     * \n
     * Valores válidos:
     * > Números entre 0 e 9999 (0, 1, 2, ..., 9999).\n
     * \n
     * Exemplos:
     * Valor | Coord. Y (métrico) | Coord. Y (imperial)
     * ----- | ------------------ | -------------------
     * 5     | Meio milímetro     | 5 centésimos de polegada
     * 10    | 1 milímetro        | 1 décimo de polegada
     * 200   | 2 centímetros      | 2 polegadas
     * 4500  | 45 centímetros     | 45 polegadas
     * \n
     *
     * \param coordX - Parâmetro do tipo numérico que define a coordenada X de impressão, isto é, a quantos
     * centésimos de centímetro (ou de polegada) do eixo x (no plano da etiqueta) o box será impresso.\n
     * \n
     * Valores válidos:
     * > Números entre 0 e 9999 (0, 1, 2, ..., 9999).\n
     * \n
     * Exemplos:
     * Valor | Coord. X (métrico) | Coord. X (imperial)
     * ----- | ------------------ | -------------------
     * 5     | Meio milímetro     | 5 centésimos de polegada
     * 10    | 1 milímetro        | 1 décimo de polegada
     * 200   | 2 centímetros      | 2 polegadas
     * 4500  | 45 centímetros     | 45 polegadas
     * \n
     *
     * \param comprimento - Parâmetro do tipo numérico que define o comprimento do box,
     * em centésimos de centímetro (ou de polegada).\n
     * \n
     * Valores válidos:
     * > Números entre 0 e 9999 (0, 1, 2, ..., 9999).\n
     * \n
     * Exemplos:
     * Valor | Comprimento (métrico) | Comprimento (imperial)
     * ----- | --------------------- | ----------------------
     * 5     | Meio milímetro        | 5 centésimos de polegada
     * 10    | 1 milímetro           | 1 décimo de polegada
     * 200   | 2 centímetros         | 2 polegadas
     * 4500  | 45 centímetros        | 45 polegadas
     * \n
     *
     * \param altura - Parâmetro do tipo numérico que define a altura do box,
     * em centésimos de centímetro (ou de polegada).\n
     * \n
     * Valores válidos:
     * > Números entre 0 e 9999 (0, 1, 2, ..., 9999).\n
     * \n
     * Exemplos:
     * Valor | Altura (métrico) | Altura (imperial)
     * ----- | ---------------- | -----------------
     * 5     | Meio milímetro   | 5 centésimos de polegada
     * 10    | 1 milímetro      | 1 décimo de polegada
     * 200   | 2 centímetros    | 2 polegadas
     * 4500  | 45 centímetros   | 45 polegadas
     * \n
     *
     * \param grosBordasH - Parâmetro do tipo numérico que define a grossura das bordas horizontais
     * (superior e inferior) do box, em centésimos de centímetro (ou de polegada).\n
     * \n
     * Valores válidos:
     * > Números entre 0 e 9999 (0, 1, 2, ..., 9999).\n
     * \n
     * Exemplos:
     * Valor | Gros. Bordas Hor. (métrico) | Gros. Bordas Hor. (imperial)
     * ----- | --------------------------- | ----------------------------
     * 5     | Meio milímetro              | 5 centésimos de polegada
     * 10    | 1 milímetro                 | 1 décimo de polegada
     * 200   | 2 centímetros               | 2 polegadas
     * 4500  | 45 centímetros              | 45 polegadas
     * \n
     *
     * \param grosBordasV: Parâmetro do tipo numérico que define a grossura das bordas verticais
     * (laterais) do box, em centésimos de centímetro (ou de polegada).\n
     * \n
     * Valores válidos:
     * > Números entre 0 e 9999 (0, 1, 2, ..., 9999).\n
     * \n
     * Exemplos:
     * Valor | Gros. Bordas Ver. (métrico) | Gros. Bordas Ver. (imperial)
     * ----- | --------------------------- | ----------------------------
     * 5     | Meio milímetro              | 5 centésimos de polegada
     * 10    | 1 milímetro                 | 1 décimo de polegada
     * 200   | 2 centímetros               | 2 polegadas
     * 4500  | 45 centímetros              | 45 polegadas
     * \n
     *
     * \return
     * O retorno da função é do tipo numérico.\n
     * A função bem-sucedida deve retornar 0.\n
     *
     * * Para mais informações, consulte #GER_Erro_Box
    */

    ///@cond
    E1_ETIQUETASHARED_EXPORT STDCALL
    ///@endcond
    int GerarBox(int coordY, int coordX, int comprimento, int altura, int grosBordasH, int grosBordasV);

    /*! \ingroup ge31
     * \brief Gera um código de barras de uma dimensão na etiqueta.
     * * OBS: A impressora L42PRO não suporta os códigos de barras Code 128 A e Coda Bar.
     *
     * \param rotacao - Parâmetro do tipo numérico que define a rotação do código de barras em relação ao plano da etiqueta.\n
     * \n
     * Valores válidos:
     * Valor | Rotação
     * ----- | -------
     * 1     | Retrato
     * 2     | Paisagem reversa
     * 3     | Retrato reverso
     * 4     | Paisagem
     * \n
     *
     * \param tipo - Parâmetro do tipo numérico que define o tipo do código de barras.\n
     * \n
     * Valores válidos:
     * Valor | Tipo                                                                        | Comprimento<br> (caracteres) | Check<br>sum | Caracteres<br>válidos                 | Razão das<br>barras
     * ----- | --------------------------------------------------------------------------- | ---------------------------- | ------------ | ------------------------------------- | -------------------
     * 0     | Code 3 of 9                                                                 | Variável                     | Não          | 0 ~ 9, A ~ Z,<br>$ % * + - . / espaço | 2 : 1 ~3 : 1
     * 1     | UPC-A                                                                       | 11 + 1                       | Sim          | 0 ~ 9                                 | 2 : 3 : 4
     * 2     | UPC-E                                                                       | 6 + 1                        | Sim          | 0 ~ 9                                 | 2 : 3 : 4
     * 3     | Interleaved 2 of 5                                                          | Variável                     | Não          | 0 ~ 9                                 | 2 : 1 ~3 : 1
     * 4     | Code 128 A                                                                  | Variável                     | Sim          | Códigos 0 ~ 127 (ASCII)               | 2 : 3 : 4
     * 5     | Code 128 B                                                                  | Variável                     | Sim          | Códigos 0 ~ 127 (ASCII)               | 2 : 3 : 4
     * 6     | Code 128 C                                                                  | Variável (valores pares)     | Sim          | 0 ~ 9                                 | 2 : 3 : 4
     * 7     | EAN-13                                                                      | 12 + 1                       | Sim          | 0 ~ 9                                 | 2 : 3 : 4
     * 8     | EAN-8                                                                       | 7 + 1                        | Sim          | 0 ~ 9                                 | 2 : 3 : 4
     * 9     | HBIC                                                                        | Variável                     | Sim          | 0 ~ 9, A ~ Z,<br>$ % * + - . / espaço | 2 : 1 ~3 : 1
     * 10    | Coda bar                                                                    | No mínimo 3                  | Não          | 0 ~ 9, A ~ D,<br>$ + - . : /          | 2 : 1 ~3 : 1
     * 11    | Interleaved 2 of 5 with a<br>modulo 10 checksum                             | Variável                     | Sim          | 0 ~ 9                                 | 2 : 1 ~3 : 1
     * 12    | Plessey                                                                     | 1 ~ 14                       | Sim          | 0 ~ 9                                 | 2 : 1 ~3 : 1
     * 13    | Interleaved 2 of 5 with a<br>modulo 10 checksum<br>and shipping bearer bars | Variável                     | Sim          | 0 ~ 9                                 | 2 : 1 ~3 : 1
     * 14    | UPC2                                                                        | 2                            | Não          | 0 ~ 9                                 | 2 : 3 : 4
     * 15    | UPC5                                                                        | 5                            | Não          | 0 ~ 9                                 | 2 : 3 : 4
     * 16    | Code 93                                                                     | Variável                     | Sim          | 0 ~ 9, A ~ Z,<br>$ % + - . / espaço   | 2 : 3 : 4
     * 17    | Postnet                                                                     | Variável                     | Sim          | 0 ~ 9                                 | ---
     * 18    | UCC/EAN Code 128                                                            | 19 + 1                       | Sim          | 0 ~ 9                                 | 2 : 3 : 4
     * 19    | UCC/EAN Code 128<br>K-MART                                                  | 18                           | Sim          | 0 ~ 9                                 | 2 : 3 : 4
     * 20    | UCC/EAN Code 128<br>Random weight                                           | 34                           | Sim          | 0 ~ 9                                 | 2 : 3 : 4
     * 21    | Telepen                                                                     | Variável                     | Sim          | Códigos 0 ~ 127 (ASCII)               | 2 : 3 : 4
     * 22    | FIM<br> (Facing Identification Mark)                                        | 1                            | Não          | A, B, C, D                            | ---
     * \n
     *
     * * OBS: O caractere do checksum (+1) é calculado e adicionado junto ao código automaticamente.\n
     * * OBS: Os códigos de barras dos tipos 13, 17, 18, 19 e 20 são suportados parcialmente pela L42PRO.\n
     * * OBS: Os códigos de barras dos tipos 4 e 19 são suportados parcialmente pela L42.\n
     * \n
     *
     * \param largBarrasL - Parâmetro do tipo numérico que define a largura das barras largas.\n
     * \n
     * Valores válidos:
     * > Números entre 0 e 24 (0, 1, 2, ..., 24).\n
     * \n
     *
     * * OBS: Veja o campo "Razão das barras", na tabela do parâmetro <i>tipo</i>.\n
     * \n
     *
     * \param largBarrasE - Parâmetro do tipo numérico que define a largura das barras espessas.\n
     * \n
     * Valores válidos:
     * > Números entre 0 e 24 (0, 1, 2, ..., 24).\n
     * \n
     *
     * * OBS: Veja o campo "Razão das barras", na tabela do parâmetro <i>tipo</i>.\n
     * \n
     *
     * \param altura - Parâmetro do tipo numérico que define a altura das barras,
     * em centésimos de centímetro (ou de polegada).\n
     * \n
     * Valores válidos:
     * > Números entre 0 e 999 (0, 1, 2, ..., 999).\n
     * \n
     * Exemplos:
     * Valor | Altura (métrico) | Altura (imperial)
     * ----- | ---------------- | -----------------
     * 5     | Meio milímetro   | 5 centésimos de polegada
     * 10    | 1 milímetro      | 1 décimo de polegada
     * 200   | 2 centímetros    | 2 polegadas
     * \n
     *
     * * OBS: O valor 0 equivale à altura padrão.\n
     * \n
     *
     * \param coordY - Parâmetro do tipo numérico que define a coordenada Y de impressão, isto é, a quantos
     * centésimos de centímetro (ou de polegada) do eixo y (no plano da etiqueta) o código de barras será impresso.\n
     * \n
     * Valores válidos:
     * > Números entre 0 e 9999 (0, 1, 2, ..., 9999).\n
     * \n
     * Exemplos:
     * Valor | Coord. Y (métrico) | Coord. Y (imperial)
     * ----- | ------------------ | -------------------
     * 5     | Meio milímetro     | 5 centésimos de polegada
     * 10    | 1 milímetro        | 1 décimo de polegada
     * 200   | 2 centímetros      | 2 polegadas
     * 4500  | 45 centímetros     | 45 polegadas
     * \n
     *
     * \param coordX - Parâmetro do tipo numérico que define a coordenada X de impressão, isto é, a quantos
     * centésimos de centímetro (ou de polegada) do eixo x (no plano da etiqueta) o código de barras será impresso.\n
     * \n
     * Valores válidos:
     * > Números entre 0 e 9999 (0, 1, 2, ..., 9999).\n
     * \n
     * Exemplos:
     * Valor | Coord. X (métrico) | Coord. X (imperial)
     * ----- | ------------------ | -------------------
     * 5     | Meio milímetro     | 5 centésimos de polegada
     * 10    | 1 milímetro        | 1 décimo de polegada
     * 200   | 2 centímetros      | 2 polegadas
     * 4500  | 45 centímetros     | 45 polegadas
     * \n
     *
     * \param codigo - Parâmetro do tipo caractere que define o código a ser impresso.\n
     * \n
     * Valores válidos:
     * > Qualquer string de dados imprimíveis; máximo de 254 caracteres (Code 128) ou 255 caracteres (demais tipos).\n
     * \n
     *
     * * OBS: O código deve respeitar a quantidade e os tipos de caracteres permitidos pelo <i>tipo</i>.\n
     * \n
     *
     * \param exibirStr - Parâmetro do tipo numérico que define se o código deverá ser impresso junto com as barras (abaixo delas) ou não.\n
     * \n
     * Valores válidos:
     * Valor | Exibe código?
     * ----- | -------------
     * 0     | Não
     * 1     | Sim
     * \n
     *
     * * OBS: Os códigos de barras dos tipos 17 (Postnet) e 22 (FIM) não suportam a exibição do código.\n
     * \n
     *
     * \return
     * O retorno da função é do tipo numérico.\n
     * A função bem-sucedida deve retornar 0.\n
     *
     * * Para mais informações, consulte #GER_Erro_BarCode1D
     */

    ///@cond
    E1_ETIQUETASHARED_EXPORT STDCALL
    ///@endcond
    int GerarBarCode1D(int rotacao, int tipo, int largBarrasL, int largBarrasE, int altura, int coordY, int coordX, const char *codigo, int exibirStr);

    /*! \ingroup ge31
     * \brief Gera um QR Code na etiqueta; modo automático.
     * * OBS: A impressora L42 suporta parcialmente esta função.
     *
     * \param rotacao - Parâmetro do tipo numérico que define a rotação do QR Code em relação ao plano da etiqueta.\n
     * \n
     * Valores válidos:
     * Valor | Rotação
     * ----- | -------
     * 1     | Retrato
     * 2     | Paisagem reversa
     * 3     | Retrato reverso
     * 4     | Paisagem
     * \n
     *
     * \param mult - Parâmetro do tipo numérico que define a dimensão do QR Code impresso.\n
     * \n
     * Valores válidos:
     * > Números entre 1 e 35 (1, 2, 3, ..., 35).\n
     * \n
     *
     * \param coordY - Parâmetro do tipo numérico que define a coordenada Y de impressão, isto é, a quantos
     * centésimos de centímetro (ou de polegada) do eixo y (no plano da etiqueta) o QR Code será impresso.\n
     * \n
     * Valores válidos:
     * > Números entre 0 e 9999 (0, 1, 2, ..., 9999).\n
     * \n
     * Exemplos:
     * Valor | Coord. Y (métrico) | Coord. Y (imperial)
     * ----- | ------------------ | -------------------
     * 5     | Meio milímetro     | 5 centésimos de polegada
     * 10    | 1 milímetro        | 1 décimo de polegada
     * 200   | 2 centímetros      | 2 polegadas
     * 4500  | 45 centímetros     | 45 polegadas
     * \n
     *
     * \param coordX - Parâmetro do tipo numérico que define a coordenada X de impressão, isto é, a quantos
     * centésimos de centímetro (ou de polegada) do eixo x (no plano da etiqueta) o QR Code será impresso.\n
     * \n
     * Valores válidos:
     * > Números entre 0 e 9999 (0, 1, 2, ..., 9999).\n
     * \n
     * Exemplos:
     * Valor | Coord. X (métrico) | Coord. X (imperial)
     * ----- | ------------------ | -------------------
     * 5     | Meio milímetro     | 5 centésimos de polegada
     * 10    | 1 milímetro        | 1 décimo de polegada
     * 200   | 2 centímetros      | 2 polegadas
     * 4500  | 45 centímetros     | 45 polegadas
     * \n
     *
     * \param codigo - Parâmetro do tipo caractere que define o código a ser impresso.\n
     * \n
     * Valores válidos:
     * > Dados numéricos, dados alfanuméricos, dados byte de 8-bit e Kanji.\n
     * \n
     *
     * \return
     * O retorno da função é do tipo numérico.\n
     * A função bem-sucedida deve retornar 0.\n
     *
     * * Para mais informações, consulte #GER_Erro_QRCodeAuto
     */

    ///@cond
    E1_ETIQUETASHARED_EXPORT STDCALL
    ///@endcond
    int GerarQRCodeAuto(int rotacao, int mult, int coordY, int coordX, const char *codigo);

    /*! \ingroup ge31
     * \brief Gera um QR Code na etiqueta; modo manual.
     * * OBS: A impressora L42 suporta parcialmente esta função.
     *
     * \param rotacao - Parâmetro do tipo numérico que define a rotação do QR Code em relação ao plano da etiqueta.\n
     * \n
     * Valores válidos:
     * Valor | Rotação
     * ----- | -------
     * 1     | Retrato
     * 2     | Paisagem reversa
     * 3     | Retrato reverso
     * 4     | Paisagem
     * \n
     *
     * \param mult - Parâmetro do tipo numérico que define a dimensão do QR Code impresso.\n
     * \n
     * Valores válidos:
     * > Números entre 1 e 35 (1, 2, 3, ..., 35).\n
     * \n
     *
     * \param coordY - Parâmetro do tipo numérico que define a coordenada Y de impressão, isto é, a quantos
     * centésimos de centímetro (ou de polegada) do eixo y (no plano da etiqueta) o QR Code será impresso.\n
     * \n
     * Valores válidos:
     * > Números entre 0 e 9999 (0, 1, 2, ..., 9999).\n
     * \n
     * Exemplos:
     * Valor | Coord. Y (métrico) | Coord. Y (imperial)
     * ----- | ------------------ | -------------------
     * 5     | Meio milímetro     | 5 centésimos de polegada
     * 10    | 1 milímetro        | 1 décimo de polegada
     * 200   | 2 centímetros      | 2 polegadas
     * 4500  | 45 centímetros     | 45 polegadas
     * \n
     *
     * \param coordX - Parâmetro do tipo numérico que define a coordenada X de impressão, isto é, a quantos
     * centésimos de centímetro (ou de polegada) do eixo x (no plano da etiqueta) o QR Code será impresso.\n
     * \n
     * Valores válidos:
     * > Números entre 0 e 9999 (0, 1, 2, ..., 9999).\n
     * \n
     * Exemplos:
     * Valor | Coord. X (métrico) | Coord. X (imperial)
     * ----- | ------------------ | -------------------
     * 5     | Meio milímetro     | 5 centésimos de polegada
     * 10    | 1 milímetro        | 1 décimo de polegada
     * 200   | 2 centímetros      | 2 polegadas
     * 4500  | 45 centímetros     | 45 polegadas
     * \n
     *
     * \param numModelo - Parâmetro do tipo numérico que define o número do modelo do QR Code.\n
     * \n
     * Valores válidos:
     * > 1 ou 2 (1, 2).\n
     * > Valor padrão: 2.\n
     * \n
     *
     * \param nvlCorErro - Parâmetro do tipo numérico que define o nível de correção de erro.\n
     * \n
     * Valores válidos:
     * Valor | Nível
     * ----- | -----
     * 0     | Nível de confiabilidade Ultra (30%)
     * 1     | Nível de confiabilidade Alto (25%)
     * 2     | Nível de confiabilidade Padrão (15%)
     * 3     | Nível de densidade Alto (7%)
     * \n
     *
     * \param numMascara - Parâmetro do tipo numérico que define o número de máscara.\n
     * \n
     * Valores válidos:
     * Valor | Máscara
     * ----- | -------
     * 0     | Máscara 0
     * 1     | Máscara 1
     * 2     | Máscara 2
     * 3     | Máscara 3
     * 4     | Máscara 4
     * 5     | Máscara 5
     * 6     | Máscara 6
     * 7     | Máscara 7
     * 8     | Sem máscara
     * 9     | Seleção automática
     * \n
     *
     * \param input - Parâmetro do tipo numérico que define o modo de entrada de dados.\n
     * \n
     * Valores válidos:
     * Valor | Input
     * ----- | -----
     * 0     | Configuração automática, ASCII
     * 1     | Automático, hex-ASCII
     * 2     | Configuração manual, ASCII
     * 3     | Manual, hex-ASCII
     * \n
     *
     * \param inputConfig - Parâmetro do tipo numérico que define o tipo de dado que compõe o QR Code.\n
     * \n
     * Valor | Input
     * ----- | -----
     * 0     | Dado numérico
     * 1     | Dado alfanumérico
     * 2     | Dado byte de 8-bit
     * 3     | Kanji
     * \n
     *
     * \param numChars8bit - Parâmetro do tipo numérico que define o número de caracteres que o <i>código</i>
     * do QR Code terá (no máximo), caso o parâmetro <i>inputConfig</i> tenha recebido o valor 2. Se o parâmetro
     * <i>inputConfig</i> receber um valor válido diferente de 2, o valor passado para <i>numChars8bit</i>
     * será ignorado.\n
     * \n
     * Valores válidos:
     * > Números entre 0 e 9999 (0, 1, 2, ..., 9999).\n
     * \n
     *
     * * OBS: Cada ideograma do chinês simplificado/tradicional tem dois caracteres.\n
     * \n
     *
     * \param codigo - Parâmetro do tipo caractere que define o código a ser impresso.\n
     * \n
     * Valores válidos:
     * > Dados numéricos, dados alfanuméricos, dados byte de 8-bit e Kanji.\n
     * \n
     *
     * \return
     * O retorno da função é do tipo numérico.\n
     * A função bem-sucedida deve retornar 0.\n
     *
     * * Para mais informações, consulte #GER_Erro_QRCodeManual
     */

    ///@cond
    E1_ETIQUETASHARED_EXPORT STDCALL
    ///@endcond
    int GerarQRCodeManual(int rotacao, int mult, int coordY, int coordX, int numModelo, int nvlCorErro, int numMascara, int input, int inputConfig, int numChars8bit, const char *codigo);

    /*! \ingroup ge31
     * \brief Gera um código MaxiCode na etiqueta.
     * * OBS: A impressora L42PRO não suporta esta função.
     *
     * \param rotacao - Parâmetro do tipo numérico que define a rotação do MaxiCode em relação ao plano da etiqueta.\n
     * \n
     * Valores válidos:
     * Valor | Rotação
     * ----- | -------
     * 1     | Retrato
     * 2     | Paisagem reversa
     * 3     | Retrato reverso
     * 4     | Paisagem
     * \n
     *
     * \param coordY - Parâmetro do tipo numérico que define a coordenada Y de impressão, isto é, a quantos
     * centésimos de centímetro (ou de polegada) do eixo y (no plano da etiqueta) o MaxiCode será impresso.\n
     * \n
     * Valores válidos:
     * > Números entre 0 e 9999 (0, 1, 2, ..., 9999).\n
     * \n
     * Exemplos:
     * Valor | Coord. Y (métrico) | Coord. Y (imperial)
     * ----- | ------------------ | -------------------
     * 5     | Meio milímetro     | 5 centésimos de polegada
     * 10    | 1 milímetro        | 1 décimo de polegada
     * 200   | 2 centímetros      | 2 polegadas
     * 4500  | 45 centímetros     | 45 polegadas
     * \n
     *
     * \param coordX - Parâmetro do tipo numérico que define a coordenada X de impressão, isto é, a quantos
     * centésimos de centímetro (ou de polegada) do eixo x (no plano da etiqueta) o MaxiCode será impresso.\n
     * \n
     * Valores válidos:
     * > Números entre 0 e 9999 (0, 1, 2, ..., 9999).\n
     * \n
     * Exemplos:
     * Valor | Coord. X (métrico) | Coord. X (imperial)
     * ----- | ------------------ | -------------------
     * 5     | Meio milímetro     | 5 centésimos de polegada
     * 10    | 1 milímetro        | 1 décimo de polegada
     * 200   | 2 centímetros      | 2 polegadas
     * 4500  | 45 centímetros     | 45 polegadas
     * \n
     *
     * \param priZip - Parâmetro do tipo numérico que define o código postal principal.\n
     * \n
     * Valores válidos:
     * > Números entre 0 e 99999 (0, 1, 2, ..., 99999).\n
     * \n
     *
     * \param secZip - Parâmetro do tipo numérico que define o código postal secundário.\n
     * \n
     * Valores válidos:
     * > Números entre 0 e 9999 (0, 1, 2, ..., 9999).\n
     * \n
     *
     * \param country - Parâmetro do tipo numérico que define o código do país.\n
     * \n
     * Valores válidos:
     * > Números entre 0 e 999 (0, 1, 2, ..., 999).\n
     * \n
     *
     * \param serClass - Parâmetro do tipo numérico que define o código da classe de serviço.\n
     * \n
     * Valores válidos:
     * > Números entre 0 e 999 (0, 1, 2, ..., 999).\n
     * \n
     *
     * \param codigo - Parâmetro do tipo caractere que define o código a ser impresso.\n
     * \n
     * Valores válidos:
     * > Qualquer string de dados imprimíveis; máximo de 84 caracteres.\n
     * \n
     *
     * \return
     * O retorno da função é do tipo numérico.\n
     * A função bem-sucedida deve retornar 0.\n
     *
     * * Para mais informações, consulte #GER_Erro_MaxiCode
     */

    ///@cond
    E1_ETIQUETASHARED_EXPORT STDCALL
    ///@endcond
    int GerarMaxiCode(int rotacao, int coordY, int coordX, int priZip, int secZip, int country, int serClass, const char *codigo);

    /*! \ingroup ge31
     * \brief Gera um código DataMatrix na etiqueta.
     * * OBS: A impressora L42PRO não suporta esta função.
     *
     * \param rotacao - Parâmetro do tipo numérico que define a rotação do DataMatrix em relação ao plano da etiqueta.\n
     * \n
     * Valores válidos:
     * Valor | Rotação
     * ----- | -------
     * 1     | Retrato
     * 2     | Paisagem reversa
     * 3     | Retrato reverso
     * 4     | Paisagem
     * \n
     *
     * \param mult - Parâmetro do tipo numérico que define a dimensão do DataMatrix impresso.\n
     * \n
     * Valores válidos:
     * > Números entre 0 e 24 (0, 1, 2, ..., 24).\n
     * \n
     *
     * \param coordY - Parâmetro do tipo numérico que define a coordenada Y de impressão, isto é, a quantos
     * centésimos de centímetro (ou de polegada) do eixo y (no plano da etiqueta) o DataMatrix será impresso.\n
     * \n
     * Valores válidos:
     * > Números entre 0 e 9999 (0, 1, 2, ..., 9999).\n
     * \n
     * Exemplos:
     * Valor | Coord. Y (métrico) | Coord. Y (imperial)
     * ----- | ------------------ | -------------------
     * 5     | Meio milímetro     | 5 centésimos de polegada
     * 10    | 1 milímetro        | 1 décimo de polegada
     * 200   | 2 centímetros      | 2 polegadas
     * 4500  | 45 centímetros     | 45 polegadas
     * \n
     *
     * \param coordX - Parâmetro do tipo numérico que define a coordenada X de impressão, isto é, a quantos
     * centésimos de centímetro (ou de polegada) do eixo x (no plano da etiqueta) o DataMatrix será impresso.\n
     * \n
     * Valores válidos:
     * > Números entre 0 e 9999 (0, 1, 2, ..., 9999).\n
     * \n
     * Exemplos:
     * Valor | Coord. X (métrico) | Coord. X (imperial)
     * ----- | ------------------ | -------------------
     * 5     | Meio milímetro     | 5 centésimos de polegada
     * 10    | 1 milímetro        | 1 décimo de polegada
     * 200   | 2 centímetros      | 2 polegadas
     * 4500  | 45 centímetros     | 45 polegadas
     * \n
     *
     * \param rows - Parâmetro do tipo numérico que define o número de linhas requeridas.\n
     * \n
     * Valores válidos:
     * > Números pares entre 0 e 999 (0, 1, 2, ..., 999).\n
     * \n
     *
     * * OBS: O valor 0 faz com que o número de linhas seja determinado automaticamente.\n
     * \n
     *
     * \param columns - Parâmetro do tipo numérico que define o número de colunas requeridas.\n
     * \n
     * Valores válidos:
     * > Números pares entre 0 e 999 (0, 1, 2, ..., 999).\n
     * \n
     *
     * * OBS: O valor 0 faz com que o número de colunas seja determinado automaticamente.\n
     * \n
     *
     * \param codigo - Parâmetro do tipo caractere que define o código a ser impresso.\n
     * \n
     * Valores válidos:
     * > Qualquer string de dados imprimíveis; máximo de 255 caracteres.\n
     * \n
     *
     * \return
     * O retorno da função é do tipo numérico.\n
     * A função bem-sucedida deve retornar 0.\n
     *
     * * Para mais informações, consulte #GER_Erro_DataMatrix
     */

    ///@cond
    E1_ETIQUETASHARED_EXPORT STDCALL
    ///@endcond
    int GerarDataMatrix(int rotacao, int mult, int coordY, int coordX, int rows, int columns, const char *codigo);

    /*! \ingroup ge31
     * \brief Gera um código DataBar na etiqueta.
     * * OBS: A impressora L42PRO suporta parcialmente esta função.
     *
     * \param rotacao - Parâmetro do tipo numérico que define a rotação do DataBar em relação ao plano da etiqueta.\n
     * \n
     * Valores válidos:
     * Valor | Rotação
     * ----- | -------
     * 1     | Retrato
     * 2     | Paisagem reversa
     * 3     | Retrato reverso
     * 4     | Paisagem
     * \n
     *
     * \param barRatio - Parâmetro do tipo numérico que define a razão entre as barras.\n
     * \n
     * Valores válidos:
     * > Números entre 1 e 9 (1, 2, 3, ..., 9).\n
     * \n
     *
     * \param altura - Parâmetro do tipo numérico que define a altura das barras,
     * em centésimos de centímetro (ou de polegada).\n
     * \n
     * Valores válidos:
     * > Números entre 0 e 999 (0, 1, 2, ..., 999).\n
     * \n
     * Exemplos:
     * Valor | Altura (métrico) | Altura (imperial)
     * ----- | ---------------- | -----------------
     * 5     | Meio milímetro   | 5 centésimos de polegada
     * 10    | 1 milímetro      | 1 décimo de polegada
     * 200   | 2 centímetros    | 2 polegadas
     * \n
     *
     * \param coordY - Parâmetro do tipo numérico que define a coordenada Y de impressão, isto é, a quantos
     * centésimos de centímetro (ou de polegada) do eixo y (no plano da etiqueta) o DataBar será impresso.\n
     * \n
     * Valores válidos:
     * > Números entre 0 e 9999 (0, 1, 2, ..., 9999).\n
     * \n
     * Exemplos:
     * Valor | Coord. Y (métrico) | Coord. Y (imperial)
     * ----- | ------------------ | -------------------
     * 5     | Meio milímetro     | 5 centésimos de polegada
     * 10    | 1 milímetro        | 1 décimo de polegada
     * 200   | 2 centímetros      | 2 polegadas
     * 4500  | 45 centímetros     | 45 polegadas
     * \n
     *
     * \param coordX - Parâmetro do tipo numérico que define a coordenada X de impressão, isto é, a quantos
     * centésimos de centímetro (ou de polegada) do eixo x (no plano da etiqueta) o DataBar será impresso.\n
     * \n
     * Valores válidos:
     * > Números entre 0 e 9999 (0, 1, 2, ..., 9999).\n
     * \n
     * Exemplos:
     * Valor | Coord. X (métrico) | Coord. X (imperial)
     * ----- | ------------------ | -------------------
     * 5     | Meio milímetro     | 5 centésimos de polegada
     * 10    | 1 milímetro        | 1 décimo de polegada
     * 200   | 2 centímetros      | 2 polegadas
     * 4500  | 45 centímetros     | 45 polegadas
     * \n
     *
     * \param tipo - Parâmetro do tipo numérico que define o tipo do DataBar (RSS).\n
     * \n
     * Valores válidos:
     * Valor | Tipo
     * ----- | -------
     * 0     | GS1 DataBar Omnidirectional <br> (RSS-14)
     * 1     | GS1 DataBar Limited <br> (RSS Limited)
     * 2     | GS1 DataBar Stacked <br> (RSS Stacked)
     * 3     | GS1 DataBar Truncated <br> (RSS Truncated)
     * 4     | GS1 DataBar Stacked Omnidirectional <br> (RSS Stacked Omnidirectional)
     * \n
     *
     * \param pxMult - Parâmetro do tipo numérico que define o multiplicador do pixel.\n
     * \n
     * Valores válidos:
     * > Números entre 1 e 9 (1, 2, 3, ..., 9).\n
     * \n
     *
     * \param numLinData - Parâmetro do tipo numérico que define o dado linear numérico.\n
     * \n
     * Valores válidos:
     * > Até 13 números entre 0 e 9 (0, 2, 3, ..., 9).\n
     * \n
     *
     * \param codigo - Parâmetro do tipo caractere que define o código a ser impresso.\n
     * \n
     * Valores válidos:
     * > Qualquer string de dados imprimíveis; máximo de 255 caracteres.\n
     * \n
     *
     * \return
     * O retorno da função é do tipo numérico.\n
     * A função bem-sucedida deve retornar 0.\n
     *
     * * Para mais informações, consulte #GER_Erro_DataBar
     */

    ///@cond
    E1_ETIQUETASHARED_EXPORT STDCALL
    ///@endcond
    int GerarDataBar(int rotacao, int barRatio, int altura, int coordY, int coordX, int tipo, int pxMult, const char *numLinData, const char *codigo);

    /*! \ingroup ge31
     * \brief Gera um código DataBar, tipo Expanded, na etiqueta.
     * * OBS: A impressora L42PRO suporta parcialmente esta função.
     *
     * \param rotacao - Parâmetro do tipo numérico que define a rotação do DataBar em relação ao plano da etiqueta.\n
     * \n
     * Valores válidos:
     * Valor | Rotação
     * ----- | -------
     * 1     | Retrato
     * 2     | Paisagem reversa
     * 3     | Retrato reverso
     * 4     | Paisagem
     * \n
     *
     * \param barRatio - Parâmetro do tipo numérico que define a razão entre as barras.\n
     * \n
     * Valores válidos:
     * > Números entre 1 e 9 (1, 2, 3, ..., 9).\n
     * \n
     *
     * \param altura - Parâmetro do tipo numérico que define a altura das barras,
     * em centésimos de centímetro (ou de polegada).\n
     * \n
     * Valores válidos:
     * > Números entre 0 e 999 (0, 1, 2, ..., 999).\n
     * \n
     * Exemplos:
     * Valor | Altura (métrico) | Altura (imperial)
     * ----- | ---------------- | -----------------
     * 5     | Meio milímetro   | 5 centésimos de polegada
     * 10    | 1 milímetro      | 1 décimo de polegada
     * 200   | 2 centímetros    | 2 polegadas
     * \n
     *
     * \param coordY - Parâmetro do tipo numérico que define a coordenada Y de impressão, isto é, a quantos
     * centésimos de centímetro (ou de polegada) do eixo y (no plano da etiqueta) o DataBar será impresso.\n
     * \n
     * Valores válidos:
     * > Números entre 0 e 9999 (0, 1, 2, ..., 9999).\n
     * \n
     * Exemplos:
     * Valor | Coord. Y (métrico) | Coord. Y (imperial)
     * ----- | ------------------ | -------------------
     * 5     | Meio milímetro     | 5 centésimos de polegada
     * 10    | 1 milímetro        | 1 décimo de polegada
     * 200   | 2 centímetros      | 2 polegadas
     * 4500  | 45 centímetros     | 45 polegadas
     * \n
     *
     * \param coordX - Parâmetro do tipo numérico que define a coordenada X de impressão, isto é, a quantos
     * centésimos de centímetro (ou de polegada) do eixo x (no plano da etiqueta) o DataBar será impresso.\n
     * \n
     * Valores válidos:
     * > Números entre 0 e 9999 (0, 1, 2, ..., 9999).\n
     * \n
     * Exemplos:
     * Valor | Coord. X (métrico) | Coord. X (imperial)
     * ----- | ------------------ | -------------------
     * 5     | Meio milímetro     | 5 centésimos de polegada
     * 10    | 1 milímetro        | 1 décimo de polegada
     * 200   | 2 centímetros      | 2 polegadas
     * 4500  | 45 centímetros     | 45 polegadas
     * \n
     *
     * \param pxMult - Parâmetro do tipo numérico que define o multiplicador do pixel.\n
     * \n
     * Valores válidos:
     * > Números entre 1 e 9 (1, 2, 3, ..., 9).\n
     * \n
     *
     * \param segsRow - Parâmetro do tipo numérico que define o número de segmentos por linha.\n
     * \n
     * Valores válidos:
     * > Números pares entre 2 e 22 (2, 3, 4, ..., 22).\n
     * \n
     *
     * \param alphanumeric - Parâmetro do tipo numérico que define o alfanumérico.\n
     * \n
     * Valores válidos:
     * > Números entre 0 e 9 (0, 2, 3, ..., 9).\n
     * \n
     *
     * \param codigo - Parâmetro do tipo caractere que define o código a ser impresso.\n
     * \n
     * Valores válidos:
     * > Qualquer string de dados imprimíveis; máximo de 255 caracteres.\n
     * \n
     *
     * \return
     * O retorno da função é do tipo numérico.\n
     * A função bem-sucedida deve retornar 0.\n
     *
     * * Para mais informações, consulte #GER_Erro_DataBarExpanded
     */

    ///@cond
    E1_ETIQUETASHARED_EXPORT STDCALL
    ///@endcond
    int GerarDataBarExpanded(int rotacao, int barRatio, int altura, int coordY, int coordX, int pxMult, int segsRow, const char *alphanumeric, const char *codigo);

    /*! \ingroup ge31
     * \brief Gera um código PDF-417 na etiqueta.
     *
     * \param rotacao - Parâmetro do tipo numérico que define a rotação do PDF-417 em relação ao plano da etiqueta.\n
     * \n
     * Valores válidos:
     * Valor | Rotação
     * ----- | -------
     * 1     | Retrato
     * 2     | Paisagem reversa
     * 3     | Retrato reverso
     * 4     | Paisagem
     * \n
     *
     * \param multH - Parâmetro do tipo numérico que define a multiplicação horizontal (largura) do PDF-417.\n
     * \n
     * Valores válidos:
     * > Números entre 0 e 24 (0, 1, 2, ..., 24).\n
     * \n
     *
     * \param multV - Parâmetro do tipo numérico que define a multiplicação vertical (altura) do PDF-417.\n
     * \n
     * Valores válidos:
     * > Números entre 0 e 24 (0, 1, 2, ..., 24).\n
     * \n
     *
     * \param coordY - Parâmetro do tipo numérico que define a coordenada Y de impressão, isto é, a quantos
     * centésimos de centímetro (ou de polegada) do eixo y (no plano da etiqueta) o PDF-417 será impresso.\n
     * \n
     * Valores válidos:
     * > Números entre 0 e 9999 (0, 1, 2, ..., 9999).\n
     * \n
     * Exemplos:
     * Valor | Coord. Y (métrico) | Coord. Y (imperial)
     * ----- | ------------------ | -------------------
     * 5     | Meio milímetro     | 5 centésimos de polegada
     * 10    | 1 milímetro        | 1 décimo de polegada
     * 200   | 2 centímetros      | 2 polegadas
     * 4500  | 45 centímetros     | 45 polegadas
     * \n
     *
     * \param coordX - Parâmetro do tipo numérico que define a coordenada X de impressão, isto é, a quantos
     * centésimos de centímetro (ou de polegada) do eixo x (no plano da etiqueta) o PDF-417 será impresso.\n
     * \n
     * Valores válidos:
     * > Números entre 0 e 9999 (0, 1, 2, ..., 9999).\n
     * \n
     * Exemplos:
     * Valor | Coord. X (métrico) | Coord. X (imperial)
     * ----- | ------------------ | -------------------
     * 5     | Meio milímetro     | 5 centésimos de polegada
     * 10    | 1 milímetro        | 1 décimo de polegada
     * 200   | 2 centímetros      | 2 polegadas
     * 4500  | 45 centímetros     | 45 polegadas
     * \n
     *
     * \param tipo - Parâmetro do tipo numérico que define o tipo do PDF-417.\n
     * \n
     * Valores válidos:
     * Valor | Tipo
     * ----- | -------
     * 0     | Normal
     * 1     | Truncated
     * \n
     *
     * \param secLevel - Parâmetro do tipo numérico que define o nível de segurança.\n
     * \n
     * Valores válidos:
     * > Números entre 0 e 8 (0, 1, 2, ..., 8).\n
     * \n
     *
     * \param aspRatio - Parâmetro do tipo numérico que define a proporção da tela.\n
     * \n
     * Valores válidos:
     * > Números entre 0 e 99 (0, 1, 2, ..., 99).\n
     * \n
     *
     * * OBS: O valor 0 significa 1:2.\n
     * \n
     *
     * \param rowNum - Parâmetro do tipo numérico que define o número de linha.\n
     * \n
     * Valores válidos:
     * > Números entre 3 e 90 (3, 4, 5, ..., 90).\n
     * \n
     *
     * * OBS: O valor 0 faz o melhor ajuste.\n
     * \n
     *
     * \param colNum - Parâmetro do tipo numérico que define o número de coluna.\n
     * \n
     * Valores válidos:
     * > Números entre 1 e 30 (1, 2, 3, ..., 30).\n
     * \n
     *
     * * OBS: O valor 0 faz o melhor ajuste.\n
     * \n
     *
     * \param codigo - Parâmetro do tipo caractere que define o código a ser impresso.\n
     * \n
     * Valores válidos:
     * > Qualquer string de dados imprimíveis; máximo de 255 caracteres.\n
     * \n
     *
     * \return
     * O retorno da função é do tipo numérico.\n
     * A função bem-sucedida deve retornar 0.\n
     *
     * * Para mais informações, consulte #GER_Erro_PDF417
     */

    ///@cond
    E1_ETIQUETASHARED_EXPORT STDCALL
    ///@endcond
    int GerarPDF417(int rotacao, int multH, int multV, int coordY, int coordX, int tipo, int secLevel, int aspRatio, int rowNum, int colNum, const char *codigo);

    /*! \ingroup ge3
     * \brief Gera uma imagem na etiqueta.
     * * OBS: A impressora L42PRO não suporta esta função (somente as duas imagens pré-carregadas na memória
     * Flash, <i>ELGINPB</i> e <i>COYOTE</i>, podem ser impressas).
     *
     * \param coordY - Parâmetro do tipo numérico que define a coordenada Y de impressão, isto é, a quantos
     * centésimos de centímetro (ou de polegada) do eixo y (no plano da etiqueta) a imagem será impressa.\n
     * \n
     * Valores válidos:
     * > Números entre 0 e 9999 (0, 1, 2, ..., 9999).\n
     * \n
     * Exemplos:
     * Valor | Coord. Y (métrico) | Coord. Y (imperial)
     * ----- | ------------------ | -------------------
     * 5     | Meio milímetro     | 5 centésimos de polegada
     * 10    | 1 milímetro        | 1 décimo de polegada
     * 200   | 2 centímetros      | 2 polegadas
     * 4500  | 45 centímetros     | 45 polegadas
     * \n
     *
     * \param coordX - Parâmetro do tipo numérico que define a coordenada X de impressão, isto é, a quantos
     * centésimos de centímetro (ou de polegada) do eixo x (no plano da etiqueta) a imagem será impressa.\n
     * \n
     * Valores válidos:
     * > Números entre 0 e 9999 (0, 1, 2, ..., 9999).\n
     * \n
     * Exemplos:
     * Valor | Coord. X (métrico) | Coord. X (imperial)
     * ----- | ------------------ | -------------------
     * 5     | Meio milímetro     | 5 centésimos de polegada
     * 10    | 1 milímetro        | 1 décimo de polegada
     * 200   | 2 centímetros      | 2 polegadas
     * 4500  | 45 centímetros     | 45 polegadas
     * \n
     *
     * \param nome - Parâmetro do tipo caractere que define o nome da imagem a ser impressa.\n
     * \n
     * Valores válidos:
     * > Qualquer string de dados alfanuméricos; máximo de 16 caracteres.\n
     * \n
     *
     * * OBS: Antes de imprimir uma imagem, é necessário que ela esteja carregada na memória
     * da impressora. Para carregar imagens, use a função <i>EnviaImagem</i>.\n
     * \n
     *
     * \return
     * O retorno da função é do tipo numérico.\n
     * A função bem-sucedida deve retornar 0.\n
     *
     * * Para mais informações, consulte #GER_Erro_Imagem
     */

    ///@cond
    E1_ETIQUETASHARED_EXPORT STDCALL
    ///@endcond
    int GerarImagem(int coordY, int coordX, const char *nome);


    // CONTROLES DA IMPRESSORA
    /*****************************************************************************/

    /*! \ingroup M0
     * \brief Comando para limpar a etiqueta, isto é, remover todos os campos criados.
     *
     * \param keepProps - Parâmetro do tipo numérico que define se as propriedades configuradas nos
     * módulos <i>Nível de Sistema</i> e <i>Formatação de Label</i> devem ser mantidas ou não.\n
     * \n
     * Valores válidos:
     * Valor | Manter propriedades?
     * ----- | --------------------
     * 0     | Não
     * 1     | Sim
     * \n
     *
     * \return
     * O retorno da função é do tipo numérico.\n
     * A função bem-sucedida deve retornar 0.\n
     *
     * * Para mais informações, consulte #GER_Erro_Outros
     */

    ///@cond
    E1_ETIQUETASHARED_EXPORT STDCALL
    ///@endcond
    int Limpa(int keepProps);

    /*! \ingroup M0
     * \brief Abre conexão com a impressora, imprime a etiqueta, depois de configurá-la com as funções
     * dos módulos <i>Nível de Sistema</i>, <i>Formatação de Label</i> e <i>Campos da Etiqueta</i>,
     * e fecha a conexão.
     *
     * \param tipo - Parâmetro do tipo numérico que define o tipo de comunicação que será estabelecido.\n
     * \n
     * Conforme tabela a seguir:
     * Valor | Referência
     * ----- | ----------
     * 1     | USB
     * 2     | RS232
     * 3     | TCP/IP
     * \n
     *
     * \param modelo - Parâmetro do tipo caractere que especifica o modelo para conexão.\n
     * \n
     * Conforme lista:
     * > <b>Valores</b>\n
     * > L42\n
     * > L42PRO\n
     * > TT042-50\n
     * \n
     *
     * \param conexao - Parâmetro do tipo caractere que define detalhes de conexão.\n
     * \n
     * Detalhes de conexão:
     * Referência | Valor exemplo
     * :--------- | -------------
     * USB        | USB
     * RS232      | COM2
     * TCP/IP     | 192.168.0.20
     * \n
     *
     * \param param - Parâmetro do tipo numérico auxiliar para a conexão com a impressora.\n
     * \n
     * Utilizado para especificar <b>baudrate</b> ou <b>porta de comunicação TCP/IP</b>.\n
     *
     * * OBS: Quando a conexão estabelecida for a USB esse parâmetro é desconsiderado, podendo ser definido com o valor 0.\n
     * \n
     *
     * \return
     * O retorno da função é do tipo numérico.\n
     * A função bem-sucedida deve retornar 0.\n
     *
     * * Para mais informações, consulte #GER_Erro_Conexao, #GER_Erro_Conexao_Serial, #GER_Erro_Conexao_USB ou #GER_Erro_Conexao_TCP\n
     * * OBS: Caso a biblioteca encontre um hardware diferente do esperado a conexão será negada e o valor -5 será retornado.
     */

    ///@cond
    E1_ETIQUETASHARED_EXPORT STDCALL
    ///@endcond
    int Imprime(int tipo, const char *modelo, const char *conexao, int param);

    /*! \ingroup M0
     * \brief Aplica um reset na impressora.
     *
     * \param tipo - Parâmetro do tipo numérico que define o tipo de comunicação que será estabelecido.\n
     * \n
     * Conforme tabela a seguir:
     * Valor | Referência
     * ----- | ----------
     * 1     | USB
     * 2     | RS232
     * 3     | TCP/IP
     * \n
     *
     * \param modelo - Parâmetro do tipo caractere que especifica o modelo para conexão.\n
     * \n
     * Conforme lista:
     * > <b>Valores</b>\n
     * > L42\n
     * > L42PRO\n
     * > TT042-50\n
     * \n
     *
     * \param conexao - Parâmetro do tipo caractere que define detalhes de conexão.\n
     * \n
     * Detalhes de conexão:
     * Referência | Valor exemplo
     * :--------- | -------------
     * USB        | USB
     * RS232      | COM2
     * TCP/IP     | 192.168.0.20
     * \n
     *
     * \param param - Parâmetro do tipo numérico auxiliar para a conexão com a impressora.\n
     * \n
     * Utilizado para especificar <b>baudrate</b> ou <b>porta de comunicação TCP/IP</b>.\n
     *
     * * OBS: Quando a conexão estabelecida for a USB esse parâmetro é desconsiderado, podendo ser definido com o valor 0.\n
     * \n
     *
     * \return
     * O retorno da função é do tipo numérico.\n
     * A função bem-sucedida deve retornar 0.\n
     *
     * * Para mais informações, consulte #GER_Erro_Conexao, #GER_Erro_Conexao_Serial, #GER_Erro_Conexao_USB ou #GER_Erro_Conexao_TCP\n
     * * OBS: Caso a biblioteca encontre um hardware diferente do esperado a conexão será negada e o valor -5 será retornado.
     */

    ///@cond
    E1_ETIQUETASHARED_EXPORT STDCALL
    ///@endcond
    int Reset(int tipo, const char *modelo, const char *conexao, int param); // Interaction

    /*! \ingroup M0
     * \brief Retorna uma sequência de 8 bytes que descreve o status geral da impressora.
     *
     * \param tipo - Parâmetro do tipo numérico que define o tipo de comunicação que será estabelecido.\n
     * \n
     * Conforme tabela a seguir:
     * Valor | Referência
     * ----- | ----------
     * 1     | USB
     * 2     | RS232
     * 3     | TCP/IP
     * \n
     *
     * \param modelo - Parâmetro do tipo caractere que especifica o modelo para conexão.\n
     * \n
     * Conforme lista:
     * > <b>Valores</b>\n
     * > L42\n
     * > L42PRO\n
     * > TT042-50\n
     * \n
     *
     * \param conexao - Parâmetro do tipo caractere que define detalhes de conexão.\n
     * \n
     * Detalhes de conexão:
     * Referência | Valor exemplo
     * :--------- | -------------
     * USB        | USB
     * RS232      | COM2
     * TCP/IP     | 192.168.0.20
     * \n
     *
     * \param param - Parâmetro do tipo numérico auxiliar para a conexão com a impressora.\n
     * \n
     * Utilizado para especificar <b>baudrate</b> ou <b>porta de comunicação TCP/IP</b>.\n
     *
     * * OBS: Quando a conexão estabelecida for a USB esse parâmetro é desconsiderado, podendo ser definido com o valor 0.\n
     * \n
     *
     * \return
     * O retorno da função é do tipo caractere.\n
     * A função bem-sucedida deve retornar XXXXXXXX, em que cada <i>X</i>, que será <i>Y</i> ou <i>N</i>, representa
     * o estado da impressora em determinado critério, conforme relação abaixo:\n
     * \n
     * Byte # | Significado
     * ------ | -----------
     * 1      | Y = Firmware parser ocupado <br> N = Firmware parser inativo
     * 2      | Y = Sem papel <br> N = Papel instalado
     * 3      | Y = Sem ribbon <br> N = Ribbon instalado
     * 4      | Y = Imprimindo arquivo em lote <br> N = Outros
     * 5      | Y = Está imprimindo <br> N = Não está imprimindo
     * 6      | Y = Impressora está pausada <br> N = Impressora não está pausada
     * 7      | Y = Label está presente <br> N = Label não está presente
     * 8      | Sempre será N
     * \n
     *
     * * Para mais informações, consulte #GER_Erro_Conexao, #GER_Erro_Conexao_Serial, #GER_Erro_Conexao_USB ou #GER_Erro_Conexao_TCP\n
     * * OBS: Caso a biblioteca encontre um hardware diferente do esperado a conexão será negada e o valor -5 será retornado.
     */

    ///@cond
    E1_ETIQUETASHARED_EXPORT STDCALL
    ///@endcond
    char *Status(int tipo, const char *modelo, const char *conexao, int param); // Interaction

    /*! \ingroup M0
     * \brief Retorna o status imediato da impressora.
     * * OBS: A impressora L42 não suporta esta função.
     * * OBS: Diferentemente de todas as demais funções desta DLL, esta não pertence à PPLA mas sim, à EPL;
     * dessa forma, é possível que alguns status não sejam retornados.
     *
     * \param tipo - Parâmetro do tipo numérico que define o tipo de comunicação que será estabelecido.\n
     * \n
     * Conforme tabela a seguir:
     * Valor | Referência
     * ----- | ----------
     * 1     | USB
     * 2     | RS232
     * 3     | TCP/IP
     * \n
     *
     * \param modelo - Parâmetro do tipo caractere que especifica o modelo para conexão.\n
     * \n
     * Conforme lista:
     * > <b>Valores</b>\n
     * > L42\n
     * > L42PRO\n
     * > TT042-50\n
     * \n
     *
     * \param conexao - Parâmetro do tipo caractere que define detalhes de conexão.\n
     * \n
     * Detalhes de conexão:
     * Referência | Valor exemplo
     * :--------- | -------------
     * USB        | USB
     * RS232      | COM2
     * TCP/IP     | 192.168.0.20
     * \n
     *
     * \param param - Parâmetro do tipo numérico auxiliar para a conexão com a impressora.\n
     * \n
     * Utilizado para especificar <b>baudrate</b> ou <b>porta de comunicação TCP/IP</b>.\n
     *
     * * OBS: Quando a conexão estabelecida for a USB esse parâmetro é desconsiderado, podendo ser definido com o valor 0.\n
     * \n
     *
     * \return
     * O retorno da função é do tipo caractere.\n
     * A função bem-sucedida deve retornar XX<CR>\<LF>, em que XX representa o status imediato da impressora, conforme relação abaixo,
     * e CR e LF são os caracteres <i>Carriage Return</i> e <i>Label Feed</i>, respectivamente.\n
     * \n
     * Retorno | Significado
     * ------- | -----------
     * 00      | Sem erro
     * 01      | Erro de sintaxe
     * 02      | Objeto excedeu borda da etiqueta
     * 03      | Erro no número de caracteres do barcode
     * 04      | Memória insuficiente para armazenar dado
     * 05      | Erro na configuração de memória
     * 06      | Erro na interface RS-232
     * 07      | Papel ou ribbon vazio
     * 08      | Nome duplicado: formulário, gráfico ou soft font
     * 09      | Nome não encontrado: formulário, gráfico ou soft font
     * 10      | Não está no modo de entrada de dados
     * 11      | Cabeça de impressão aberta
     * 12      | Impressora está pausada
     * 50      | Impressora ocupada - imprimindo
     * 80*     | Indefinido
     * 81*     | Erro no cutter
     * 82*     | Falha de sensor
     * 83*     | Ocorrência de interrupção ilegal
     * 84*     | Alimentação excessiva
     * \n
     * (*) Requer intervenção: Pressione Feed ou Reset
     *
     * * Para mais informações, consulte #GER_Erro_Conexao, #GER_Erro_Conexao_Serial, #GER_Erro_Conexao_USB ou #GER_Erro_Conexao_TCP\n
     * * OBS: Caso a biblioteca encontre um hardware diferente do esperado a conexão será negada e o valor -5 será retornado.
     */

    ///@cond
    E1_ETIQUETASHARED_EXPORT STDCALL
    ///@endcond
    char *StatusEPL(int tipo, const char *modelo, const char *conexao, int param); // Interaction

    /*! \ingroup M0
     * \brief Produz um efeito similar ao de pressionar o botão Feed da impressora.
     *
     * Se a impressora não estiver em modo contínuo, avança o papel até encontrar um gap (avança uma
     * etiqueta em branco). Se a impressora estiver em modo contínuo, avança o papel até uma certa distância.
     *
     * \param tipo - Parâmetro do tipo numérico que define o tipo de comunicação que será estabelecido.\n
     * \n
     * Conforme tabela a seguir:
     * Valor | Referência
     * ----- | ----------
     * 1     | USB
     * 2     | RS232
     * 3     | TCP/IP
     * \n
     *
     * \param modelo - Parâmetro do tipo caractere que especifica o modelo para conexão.\n
     * \n
     * Conforme lista:
     * > <b>Valores</b>\n
     * > L42\n
     * > L42PRO\n
     * > TT042-50\n
     * \n
     *
     * \param conexao - Parâmetro do tipo caractere que define detalhes de conexão.\n
     * \n
     * Detalhes de conexão:
     * Referência | Valor exemplo
     * :--------- | -------------
     * USB        | USB
     * RS232      | COM2
     * TCP/IP     | 192.168.0.20
     * \n
     *
     * \param param - Parâmetro do tipo numérico auxiliar para a conexão com a impressora.\n
     * \n
     * Utilizado para especificar <b>baudrate</b> ou <b>porta de comunicação TCP/IP</b>.\n
     *
     * * OBS: Quando a conexão estabelecida for a USB esse parâmetro é desconsiderado, podendo ser definido com o valor 0.\n
     * \n
     *
     * \return
     * O retorno da função é do tipo numérico.\n
     * A função bem-sucedida deve retornar 0.\n
     *
     * * Para mais informações, consulte #GER_Erro_Conexao, #GER_Erro_Conexao_Serial, #GER_Erro_Conexao_USB ou #GER_Erro_Conexao_TCP\n
     * * OBS: Caso a biblioteca encontre um hardware diferente do esperado a conexão será negada e o valor -5 será retornado.
     */

    ///@cond
    E1_ETIQUETASHARED_EXPORT STDCALL
    ///@endcond
    int Feed(int tipo, const char *modelo, const char *conexao, int param); // System Level

    /*! \ingroup M0
     * \brief Faz uma impressão de teste.
     *
     * \param tipo - Parâmetro do tipo numérico que define o tipo de comunicação que será estabelecido.\n
     * \n
     * Conforme tabela a seguir:
     * Valor | Referência
     * ----- | ----------
     * 1     | USB
     * 2     | RS232
     * 3     | TCP/IP
     * \n
     *
     * \param modelo - Parâmetro do tipo caractere que especifica o modelo para conexão.\n
     * \n
     * Conforme lista:
     * > <b>Valores</b>\n
     * > L42\n
     * > L42PRO\n
     * > TT042-50\n
     * \n
     *
     * \param conexao - Parâmetro do tipo caractere que define detalhes de conexão.\n
     * \n
     * Detalhes de conexão:
     * Referência | Valor exemplo
     * :--------- | -------------
     * USB        | USB
     * RS232      | COM2
     * TCP/IP     | 192.168.0.20
     * \n
     *
     * \param param - Parâmetro do tipo numérico auxiliar para a conexão com a impressora.\n
     * \n
     * Utilizado para especificar <b>baudrate</b> ou <b>porta de comunicação TCP/IP</b>.\n
     *
     * * OBS: Quando a conexão estabelecida for a USB esse parâmetro é desconsiderado, podendo ser definido com o valor 0.\n
     * \n
     *
     * \return
     * O retorno da função é do tipo numérico.\n
     * A função bem-sucedida deve retornar 0.\n
     *
     * * Para mais informações, consulte #GER_Erro_Conexao, #GER_Erro_Conexao_Serial, #GER_Erro_Conexao_USB ou #GER_Erro_Conexao_TCP\n
     * * OBS: Caso a biblioteca encontre um hardware diferente do esperado a conexão será negada e o valor -5 será retornado.
     */

    ///@cond
    E1_ETIQUETASHARED_EXPORT STDCALL
    ///@endcond
    int Teste(int tipo, const char *modelo, const char *conexao, int param); // System Level

    /*! \ingroup M0
     * \brief Exibe o status da memória da impressora: as imagens, as fontes ou os labels carregados e o
     * espaço disponível em cada módulo (RAM e Flash).
     * * OBS: A impressora L42PRO suporta parcialmente esta função.
     *
     * \param tipo - Parâmetro do tipo numérico que define o tipo de comunicação que será estabelecido.\n
     * \n
     * Conforme tabela a seguir:
     * Valor | Referência
     * ----- | ----------
     * 1     | USB
     * 2     | RS232
     * 3     | TCP/IP
     * \n
     *
     * \param modelo - Parâmetro do tipo caractere que especifica o modelo para conexão.\n
     * \n
     * Conforme lista:
     * > <b>Valores</b>\n
     * > L42\n
     * > L42PRO\n
     * > TT042-50\n
     * \n
     *
     * \param conexao - Parâmetro do tipo caractere que define detalhes de conexão.\n
     * \n
     * Detalhes de conexão:
     * Referência | Valor exemplo
     * :--------- | -------------
     * USB        | USB
     * RS232      | COM2
     * TCP/IP     | 192.168.0.20
     * \n
     *
     * \param param - Parâmetro do tipo numérico auxiliar para a conexão com a impressora.\n
     * \n
     * Utilizado para especificar <b>baudrate</b> ou <b>porta de comunicação TCP/IP</b>.\n
     *
     * * OBS: Quando a conexão estabelecida for a USB esse parâmetro é desconsiderado, podendo ser definido com o valor 0.\n
     * \n
     *
     * \param tipoDados - Parâmetro do tipo numérico que define qual tipo de dados armazenado na memória a impressora irá
     * buscar e retornar.\n
     * \n
     * Valores válidos:
     * Valor | Dados
     * ----- | -----
     * 0     | Fontes
     * 1     | Imagens
     * 2     | Labels
     * \n
     *
     * \return
     * O retorno da função é do tipo caractere.\n
     * A função bem-sucedida deve uma cadeia de caracteres que mostra os dados carregados nos dois módulos da memória
     * (conforme o tipo especificado, em <i>tipoDados</i>) seguido do espaço disponível em cada módulo.\n
     *
     * * Para mais informações, consulte #GER_Erro_Conexao, #GER_Erro_Conexao_Serial, #GER_Erro_Conexao_USB ou #GER_Erro_Conexao_TCP\n
     * * OBS: Caso a biblioteca encontre um hardware diferente do esperado a conexão será negada e o valor -5 será retornado.
     */

    ///@cond
    E1_ETIQUETASHARED_EXPORT STDCALL
    ///@endcond
    char *MemoryStatus(int tipo, const char *modelo, const char *conexao, int param, int tipoDados); // System Level

    /*! \ingroup M0
     * \brief Apaga o conteúdo carregado nos dois módulos da impressora (RAM e Flash).
     * * OBS: A impressora L42PRO não suporta esta função.
     *
     * \param tipo - Parâmetro do tipo numérico que define o tipo de comunicação que será estabelecido.\n
     * \n
     * Conforme tabela a seguir:
     * Valor | Referência
     * ----- | ----------
     * 1     | USB
     * 2     | RS232
     * 3     | TCP/IP
     * \n
     *
     * \param modelo - Parâmetro do tipo caractere que especifica o modelo para conexão.\n
     * \n
     * Conforme lista:
     * > <b>Valores</b>\n
     * > L42\n
     * > L42PRO\n
     * > TT042-50\n
     * \n
     *
     * \param conexao - Parâmetro do tipo caractere que define detalhes de conexão.\n
     * \n
     * Detalhes de conexão:
     * Referência | Valor exemplo
     * :--------- | -------------
     * USB        | USB
     * RS232      | COM2
     * TCP/IP     | 192.168.0.20
     * \n
     *
     * \param param - Parâmetro do tipo numérico auxiliar para a conexão com a impressora.\n
     * \n
     * Utilizado para especificar <b>baudrate</b> ou <b>porta de comunicação TCP/IP</b>.\n
     *
     * * OBS: Quando a conexão estabelecida for a USB esse parâmetro é desconsiderado, podendo ser definido com o valor 0.\n
     * \n
     *
     * \return
     * O retorno da função é do tipo numérico.\n
     * A função bem-sucedida deve retornar 0.\n
     *
     * * Para mais informações, consulte #GER_Erro_Conexao, #GER_Erro_Conexao_Serial, #GER_Erro_Conexao_USB ou #GER_Erro_Conexao_TCP\n
     * * OBS: Caso a biblioteca encontre um hardware diferente do esperado a conexão será negada e o valor -5 será retornado.
     */

    ///@cond
    E1_ETIQUETASHARED_EXPORT STDCALL
    ///@endcond
    int LimpaMemoria(int tipo, const char *modelo, const char *conexao, int param); // System Level

    /*! \ingroup M0
     * \brief Apaga o conteúdo carregado em um módulo específico da impressora (RAM ou Flash).
     * * OBS: A impressora L42PRO suporta parcialmente esta função (os dados não são apagados imediatamente,
     * mas somente depois de uma reinicialização).
     *
     * \param tipo - Parâmetro do tipo numérico que define o tipo de comunicação que será estabelecido.\n
     * \n
     * Conforme tabela a seguir:
     * Valor | Referência
     * ----- | ----------
     * 1     | USB
     * 2     | RS232
     * 3     | TCP/IP
     * \n
     *
     * \param modelo - Parâmetro do tipo caractere que especifica o modelo para conexão.\n
     * \n
     * Conforme lista:
     * > <b>Valores</b>\n
     * > L42\n
     * > L42PRO\n
     * > TT042-50\n
     * \n
     *
     * \param conexao - Parâmetro do tipo caractere que define detalhes de conexão.\n
     * \n
     * Detalhes de conexão:
     * Referência | Valor exemplo
     * :--------- | -------------
     * USB        | USB
     * RS232      | COM2
     * TCP/IP     | 192.168.0.20
     * \n
     *
     * \param param - Parâmetro do tipo numérico auxiliar para a conexão com a impressora.\n
     * \n
     * Utilizado para especificar <b>baudrate</b> ou <b>porta de comunicação TCP/IP</b>.\n
     *
     * * OBS: Quando a conexão estabelecida for a USB esse parâmetro é desconsiderado, podendo ser definido com o valor 0.\n
     * \n
     *
     * \param modulo - Parâmetro do tipo numérico que define o módulo que será apagado.\n
     * \n
     * Valores válidos:
     * Valor | Módulo
     * ----- | ------
     * 0     | RAM
     * 1     | Flash
     * \n
     *
     * \return
     * O retorno da função é do tipo numérico.\n
     * A função bem-sucedida deve retornar 0.\n
     *
     * * Para mais informações, consulte #GER_Erro_Conexao, #GER_Erro_Conexao_Serial, #GER_Erro_Conexao_USB ou #GER_Erro_Conexao_TCP\n
     * * OBS: Caso a biblioteca encontre um hardware diferente do esperado a conexão será negada e o valor -5 será retornado.
     */

    ///@cond
    E1_ETIQUETASHARED_EXPORT STDCALL
    ///@endcond
    int LimpaModulo(int tipo, const char *modelo, const char *conexao, int param, int modulo); // System Level

    /*! \ingroup M0
     * \brief Envia uma imagem para a memória da impressora (RAM ou Flash).
     * * OBS: A impressora L42PRO suporta parcialmente esta função (as imagens não são carregadas imediatamente,
     * mas somente depois de uma reinicialização).
     *
     * \param tipo - Parâmetro do tipo numérico que define o tipo de comunicação que será estabelecido.\n
     * \n
     * Conforme tabela a seguir:
     * Valor | Referência
     * ----- | ----------
     * 1     | USB
     * 2     | RS232
     * 3     | TCP/IP
     * \n
     *
     * \param modelo - Parâmetro do tipo caractere que especifica o modelo para conexão.\n
     * \n
     * Conforme lista:
     * > <b>Valores</b>\n
     * > L42\n
     * > L42PRO\n
     * > TT042-50\n
     * \n
     *
     * \param conexao - Parâmetro do tipo caractere que define detalhes de conexão.\n
     * \n
     * Detalhes de conexão:
     * Referência | Valor exemplo
     * :--------- | -------------
     * USB        | USB
     * RS232      | COM2
     * TCP/IP     | 192.168.0.20
     * \n
     *
     * \param param - Parâmetro do tipo numérico auxiliar para a conexão com a impressora.\n
     * \n
     * Utilizado para especificar <b>baudrate</b> ou <b>porta de comunicação TCP/IP</b>.\n
     *
     * * OBS: Quando a conexão estabelecida for a USB esse parâmetro é desconsiderado, podendo ser definido com o valor 0.\n
     * \n
     *
     * \param modulo - Parâmetro do tipo numérico que define o módulo onde a imagem será carregada.\n
     * \n
     * Valores válidos:
     * Valor | Módulo
     * ----- | ------
     * 0     | RAM
     * 1     | Flash
     * \n
     *
     * \param formato - Parâmetro do tipo numérico que define o formato da imagem que será enviada.\n
     * \n
     * Valores válidos:
     * Valor | Formato
     * ----- | -------
     * 0     | BMP Flipped
     * 1     | BMP
     * 2     | IMG Flipped
     * 3     | IMG
     * 4     | PCX Flipped
     * 5     | PCX
     * 6     | HEX
     * \n
     *
     * \param nome - Parâmetro do tipo caractere que define um nome para a imagem.\n
     * Esse é o nome que identificará, na memória, a imagem enviada.\n
     * \n
     * Valores válidos:
     * > Qualquer string de dados alfanuméricos; máximo de 16 caracteres.\n
     * \n
     *
     * \param arquivo - Parâmetro do tipo caractere que define a imagem que será carregada.\n
     * \n
     * Este parâmetro recebe como argumento o caminho, no sistema de arquivos, onde a imagem
     * a ser enviada está armazenada, seguida do nome da imagem.\n
     * \n
     * O argumento deve representar um arquivo de imagem válido, isto é, uma imagem acessível pela
     * função e que esteja em algum dos formatos disponíveis no parâmetro <i>formato</i>.\n
     * \n
     * > Se a função for usada no Android, este parâmetro recebe o <i>caminho relativo ao
     * > armazenamento interno do dispositivo</i>.\n
     * > \n
     * > Exemplo: o valor <b>Download/Figura.bmp</b>, passado neste parâmetro, envia o arquivo
     * > <b>Figura.bmp</b>, localizado no diretório <b>Download</b> (no armazenamento interno).\n
     * \n
     * Veja, abaixo, um exemplo de uso válido desta função, seguido de um breve comentário
     * sobre os argumentos passados:
     * \n
     * > <b>EnviaImagem(1, "L42", "USB", 0, 1, 0, "LOGOTIPO", "C:\\Imagens\\LogoTipoEmpresa.bmp");</b>\n
     * \n
     * No exemplo acima a função enviará, ao módulo <b>Flash</b> da impressora, a imagem <b>LogoTipoEmpresa.bmp</b>,
     * localizada no diretório <b>C:\\Imagens</b>, com o nome <b>LOGOTIPO</b>. O argumento <b>0</b>, imediatamente
     * antes de <b>LOGOTIPO</b>, informa à impressora que o arquivo enviado é uma imagem <b>BMP Flipped</b>.\n
     * \n
     * Os primeiros quatro argumentos permitem que a função envie o comando à impressora <b>L42</b> via <b>USB</b>.\n
     * \n
     *
     * \return
     * O retorno da função é do tipo numérico.\n
     * A função bem-sucedida deve retornar 0.\n
     * Se a impressora for a L42, um <i>beep</i> indicará o envio bem-sucedido da imagem.\n
     *
     * * Para mais informações, consulte #GER_Erro_Conexao, #GER_Erro_Conexao_Serial, #GER_Erro_Conexao_USB ou #GER_Erro_Conexao_TCP\n
     * * OBS: Caso a biblioteca encontre um hardware diferente do esperado a conexão será negada e o valor -5 será retornado.
     */

    ///@cond
    E1_ETIQUETASHARED_EXPORT STDCALL
    ///@endcond
    int EnviaImagem(int tipo, const char *modelo, const char *conexao, int param, int modulo, int formato, const char *nome, const char *arquivo); // System Level

    /*! \ingroup M0
     * \brief Exclui uma imagem enviada à memória da impressora.
     *
     * \param tipo - Parâmetro do tipo numérico que define o tipo de comunicação que será estabelecido.\n
     * \n
     * Conforme tabela a seguir:
     * Valor | Referência
     * ----- | ----------
     * 1     | USB
     * 2     | RS232
     * 3     | TCP/IP
     * \n
     *
     * \param modelo - Parâmetro do tipo caractere que especifica o modelo para conexão.\n
     * \n
     * Conforme lista:
     * > <b>Valores</b>\n
     * > L42\n
     * > L42PRO\n
     * > TT042-50\n
     * \n
     *
     * \param conexao - Parâmetro do tipo caractere que define detalhes de conexão.\n
     * \n
     * Detalhes de conexão:
     * Referência | Valor exemplo
     * :--------- | -------------
     * USB        | USB
     * RS232      | COM2
     * TCP/IP     | 192.168.0.20
     * \n
     *
     * \param param - Parâmetro do tipo numérico auxiliar para a conexão com a impressora.\n
     * \n
     * Utilizado para especificar <b>baudrate</b> ou <b>porta de comunicação TCP/IP</b>.\n
     *
     * * OBS: Quando a conexão estabelecida for a USB esse parâmetro é desconsiderado, podendo ser definido com o valor 0.\n
     * \n
     *
     * \param modulo - Parâmetro do tipo numérico que define o módulo onde a imagem a ser excluída está.\n
     * \n
     * Valores válidos:
     * Valor | Módulo
     * ----- | ------
     * 0     | RAM
     * 1     | Flash
     * \n
     *
     * \param nome - Parâmetro do tipo caractere que define o nome da imagem que será excluída.\n
     * \n
     * Valores válidos:
     * > Qualquer string de dados alfanuméricos; máximo de 16 caracteres.\n
     * \n
     *
     * \return
     * O retorno da função é do tipo numérico.\n
     * A função bem-sucedida deve retornar 0.\n
     *
     * * Para mais informações, consulte #GER_Erro_Conexao, #GER_Erro_Conexao_Serial, #GER_Erro_Conexao_USB ou #GER_Erro_Conexao_TCP\n
     * * OBS: Caso a biblioteca encontre um hardware diferente do esperado a conexão será negada e o valor -5 será retornado.
     */

    ///@cond
    E1_ETIQUETASHARED_EXPORT STDCALL
    ///@endcond
    int ExcluiImagem(int tipo, const char *modelo, const char *conexao, int param, int modulo, const char *nome); // System Level


    // METODOS DIVERSOS...
    /*****************************************************************************/

    /*! \ingroup M0
     * \brief Retorna a versão da DLL E1_Etiqueta.
     *
     * \return
     * O retorno da função é do tipo caractere.\n
     * \n
     *
     * A função bem-sucedida deve retornar ??.??.??, que representa a versão da DLL
     * em que esta função foi chamada; cada <b>?</b> é um dígito entre 0 e 9.
     */

    ///@cond
    E1_ETIQUETASHARED_EXPORT STDCALL
    ///@endcond
    char *GetVersaoDLL();

    /*! \ingroup M0
     * \brief Envia comandos, em protocolo suportado pela impressora, direto para a porta de comunicação.
	 * * OBS: Este método não está disponível para uso com o @ref g8.
     * * OBS: Este método apresenta algumas diferenças no ambiente Android - consulte sua documentação em
	 * Módulos > Android > Módulos > Impressora de Etiquetas > DirectIO.
     *
     * Função de despejo de comandos na porta de comunicação. Essa função também recebe dados da porta.
     *
     * \param tipo - Parâmetro do tipo numérico que define o tipo de comunicação que será estabelecido.\n
     * \n
     * Conforme tabela a seguir:
     * Valor | Referência
     * ----- | ----------
     * 1     | USB
     * 2     | RS232
     * 3     | TCP/IP
     * \n
     *
     * \param modelo - Parâmetro do tipo caractere que especifica o modelo para conexão.\n
     * \n
     * Conforme lista:
     * > <b>Valores</b>\n
     * > L42\n
     * > L42PRO\n
     * > TT042-50\n
     * \n
     *
     * \param conexao - Parâmetro do tipo caractere que define detalhes de conexão.\n
     * \n
     * Detalhes de conexão:
     * Referência | Valor exemplo
     * :--------- | -------------
     * USB        | USB
     * RS232      | COM2
     * TCP/IP     | 192.168.0.20
     * \n
     *
     * \param param - Parâmetro do tipo numérico auxiliar para a conexão com a impressora.\n
     * \n
     * Utilizado para especificar <b>baudrate</b> ou <b>porta de comunicação TCP/IP</b>.\n
     *
     * * OBS: Quando a conexão estabelecida for a USB esse parâmetro é desconsiderado, podendo ser definido com o valor 0.\n
     * \n
     *
     * \param writeData - Sequência de bytes que devem ser enviados para a porta de comunicação.\n
     * \n
     *
     * \param writeNum - Quantidade de bytes enviados e que serão escritos.\n
     * \n
     *
     * \param readData - Alocação de memória que receberá os dados de retorno caso seja necessário.\n
     * \n
     *
     * \param readNum - Quantidade de dados que se espera ler. Para
     * evitar a leitura da porta esse parâmetro deve estar em ZERO (0).\n
     * \n
     *
     * Veja, abaixo, um exemplo de uso válido desta função, em C++, seguido de um comentário detalhado
     * sobre os argumentos passados:
     *
     * @code
     * unsigned char * esc = new unsigned char[4]{2, 70, 13, 13}; // Avanca papel
     * unsigned char * ler; // Armazena os dados retornados pela impressora
     * memset(ler, 0, 1); // "Apaga" lixo de memória presente na variável ler
     *
     * int *ret = DirectIO(1, "L42PRO", "USB", 0, esc, 4, ler, 0);
     *
     * // Imprime o retorno de DirectIO e a resposta da impressora:
     * printf("\n Ret: %d ; Escreveu: %d ; Leu: %d ; Dados lidos: %s \n", ret[0], ret[1], ret[2], ler);
     * @endcode
     *
     * \n
     * > No exemplo acima, os primeiros quatro argumentos permitem que a função envie o comando à impressora
     * > <b>L42PRO</b> via <b>USB</b>.\n
     *
     * > Em seguida, são passados a variável <b>esc</b> e o argumento <b>4</b> à função; a variável <b>esc</b>
     * > contém o comando que o <i>DirectIO</i> enviará à impressora - um avanço de papel, em PPLA - e o valor
     * > <b>4</b>, a quantidade de bytes que devem ser escritos - no exemplo, todos os quatro bytes do comando
     * > armazenado na variável <b>esc</b>.\n
     *
     * > Note ainda o byte <i>13</i>, duplicado, no comando: os comandos PPLA devem terminar, por padrão, com
     * > um byte 13 (caractere CR); a impressora L42PRO, no entanto, necessita de um CR adicional para que o
     * > comando seja reconhecido, dai o motivo do byte 13 estar duplicado.\n
     *
     * > Por fim, são passados à função a variável <b>ler</b> e o argumento <b>0</b>; a variável <b>ler</b>
     * > armazenará os dados retornados pela impressora, em resposta ao comando enviado, e o valor <b>0</b>,
     * > a quantidade de bytes que deverão ser lidos - no exemplo, o comando de avanço de papel não retorna
     * > nenhum dado, portanto, o argumento <b>0</b> passado faz com que o DirectIO não realize a leitura da
     * > porta.\n
     * \n
     *
     * \return
     * O retorno da função é um vetor de int, com três posições, cujo conteúdo é descrito a seguir:
     * > Posição 0: Código de retorno da função (=0: Sucesso, <0: Falha de comunicação/leitura).\n
     * > Posição 1: Quantidade de bytes escritos na porta (<0: Falha de escrita).\n
     * > Posição 2: Quantidade de bytes lidos na porta.\n
     * \n
     *
     * * Para mais informações, consulte #GER_Erro_Conexao, #GER_Erro_Conexao_Serial, #GER_Erro_Conexao_USB ou #GER_Erro_Conexao_TCP\n
     * * OBS: Caso a biblioteca encontre um hardware diferente do esperado a conexão será negada e o valor -5 será retornado na posição 0 do vetor.
     */

    ///@cond
    E1_ETIQUETASHARED_EXPORT STDCALL
    ///@endcond
    int *DirectIO(int tipo, const char *modelo, const char *conexao, int param, unsigned char* writeData, unsigned int writeNum, unsigned char* readData, unsigned int readNum);

    /*! \ingroup M0
     * \brief Envia um arquivo com comandos, em protocolo suportado, para impressora, que irá executá-los.
     * * OBS: Existe também a função <i>DespejarArquivoLF</i>, idêntica a esta, exceto pelo único diferencial
     * daquela incluir um byte 10 (caractere LF) ao final de cada linha lida do arquivo, antes de enviá-la à
     * impressora (o arquivo original permanece inalterado). O método <i>DespejarArquivoLF</i> é útil nos
     * casos em que esta função falhar no despejo.
     *
     * \param tipo - Parâmetro do tipo numérico que define o tipo de comunicação que será estabelecido.\n
     * \n
     * Conforme tabela a seguir:
     * Valor | Referência
     * ----- | ----------
     * 1     | USB
     * 2     | RS232
     * 3     | TCP/IP
     * \n
     *
     * \param modelo - Parâmetro do tipo caractere que especifica o modelo para conexão.\n
     * \n
     * Conforme lista:
     * > <b>Valores</b>\n
     * > L42\n
     * > L42PRO\n
     * > TT042-50\n
     * \n
     *
     * \param conexao - Parâmetro do tipo caractere que define detalhes de conexão.\n
     * \n
     * Detalhes de conexão:
     * Referência | Valor exemplo
     * :--------- | -------------
     * USB        | USB
     * RS232      | COM2
     * TCP/IP     | 192.168.0.20
     * \n
     *
     * \param param - Parâmetro do tipo numérico auxiliar para a conexão com a impressora.\n
     * \n
     * Utilizado para especificar <b>baudrate</b> ou <b>porta de comunicação TCP/IP</b>.\n
     *
     * * OBS: Quando a conexão estabelecida for a USB esse parâmetro é desconsiderado, podendo ser definido com o valor 0.\n
     * \n
     *
     * \param caminho - Parâmetro do tipo caractere que define o arquivo que será enviado.\n
     * \n
     * Este parâmetro recebe como argumento o caminho, no sistema de arquivos, onde o arquivo
     * está armazenado, incluindo seu nome.\n
	 * \n
     * > Se a função for usada no Android, este parâmetro recebe o <i>caminho relativo ao
     * > armazenamento interno do dispositivo</i>.\n
     * > \n
     * > Exemplo: o valor <b>Download/Etiqueta.txt</b>, passado neste parâmetro, despeja o arquivo
     * > <b>Etiqueta.txt</b>, localizado no diretório <b>Download</b> (no armazenamento interno).\n
     * \n
     *
     * \return
     * O retorno da função é do tipo numérico.\n
     * A função bem-sucedida deve retornar 0.\n
     *
     * * Para mais informações, consulte #GER_Erro_Conexao, #GER_Erro_Conexao_Serial, #GER_Erro_Conexao_USB ou #GER_Erro_Conexao_TCP\n
     * * OBS: Caso a biblioteca encontre um hardware diferente do esperado a conexão será negada e o valor -5 será retornado.
     */

    ///@cond
    E1_ETIQUETASHARED_EXPORT STDCALL
    ///@endcond
    int DespejarArquivo(int tipo, const char *modelo, const char *conexao, int param, const char *caminho);

    ///@cond
    E1_ETIQUETASHARED_EXPORT STDCALL
    ///@endcond
    int DespejarArquivoLF(int tipo, const char *modelo, const char *conexao, int param, const char *caminho);
}


#endif // EXPORTAFUNCOES_H
