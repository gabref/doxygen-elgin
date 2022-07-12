#ifndef EXPORTAFUNCOES_H
#define EXPORTAFUNCOES_H

#include "e1_balanca.h"

#ifdef __WIN32
#define STDCALL __stdcall
#elif __linux__
#define STDCALL
#endif


/*
    Descricao:      Classe que exporta e documenta as funcoes da biblioteca E1_Balanca
    Autor:          Rodrigo Angelo
    Data:           10/09/2020
*/


E1_Balanca bal;


extern "C"{

    /** \defgroup g5 Balança
     *
     * \brief Fornece funções para integração com balanças ELGIN.
     *
     * Essa biblioteca fornece diversas funções de integração com as balanças ELGIN.\n
     * Os modelos de balanças compatíveis com essa biblioteca são:\n
     * > DP-3005\n
     * > SA-110\n
     * > DPSC\n
     * > DP30CK\n
     * \n
     *
     * Métodos para controle da balança:\n
     * > #LerPeso\n
     * > #LerPreco\n
     * > #LerTara\n
     * > #LerTotal\n
     * > #TararBalanca\n
     * > #ZerarBalanca\n
     * > #LigarDesligarDisplay\n
     * \n
     *
     * Para utilizar as funções de controle da balança, listadas acima, é necessário, antes,
     * executar os três métodos abaixo:\n
     * > #ConfigurarModeloBalanca // Escolhe o modelo de balança para usar na biblioteca\n
     * > #ConfigurarProtocoloComunicacao // Define o protocolo em que as funções de controle devem trabalhar\n
     * > #AbrirSerial // Estabelece uma conexão com a balança\n
     *
     * Após executar (com sucesso) as três funções listadas acima, os métodos para controle da balança
     * estarão aptos para utilização.\n
     * \n
     *
     * Notas para o método #ConfigurarModeloBalanca:\n
     * > #1. É o primeiro método que deve ser executado;\n
     * > #2. A conexão com a balança deve estar fechada toda vez que esse método for chamado;\n
     * > #3. Sempre que o modelo da balança for trocado, configure novamente o protocolo através do método
     * >     #ConfigurarProtocoloComunicacao.\n
     * \n
     *
     * Atualmente, a <b>versão Android</b> desta biblioteca possui as seguintes limitações:\n
     * > Ausência de suporte para comunicação com 7 bits de dados (length == 7)\n
     * > Ausência de suporte para protocolos contínuos\n
     * \n
     *
     * Convenções usadas nas chamadas das funções da biblioteca:\n
     *<b>Windows</b>\n
     *  > __stdcall
     *<b>Linux</b>\n
     *  > __cdecl\n
     */

    // METODOS PARA CONFIGURACAO DA BALANCA
    ////////////////////////////////////////////////////////////////////////////////////////////////////

    /*! \ingroup g5
     * \brief Obtém o modelo da balança configurado para uso na biblioteca.
     *
     * \return
     * O retorno da função é do tipo numérico.\n
     * A função bem-sucedida deve retornar o código correspondente à balança em uso, conforme tabela abaixo:
     * Código | Modelo
     * ------ | ------
     * 0      | DP-3005
     * 1      | SA-110
     * 2      | DPSC
     * 3      | DP30CK
     * \n
     *
     * * Para mais informações, consulte #Bal_Erro_Balanca, #Bal_Erro_Protocolo, #Bal_Erro_Abertura ou #Bal_Erro_Outros
     */

    ///@cond
    E1_BALANCASHARED_EXPORT STDCALL
    ///@endcond
    int ObterModeloBalanca();

    /*! \ingroup g5
     * \brief Configura o modelo da balança para uso na biblioteca.
     *
     * \param modeloBalanca - Parâmetro do tipo numérico que corresponde ao código da balança desejada, conforme tabela abaixo:
     * Código | Modelo
     * ------ | ------
     * 0      | DP-3005
     * 1      | SA-110
     * 2      | DPSC
     * 3      | DP30CK
     * \n
     *
     * \return
     * O retorno da função é do tipo numérico.\n
     * A função bem-sucedida deve retornar 0.\n
     *
     * * Para mais informações, consulte #Bal_Erro_Balanca, #Bal_Erro_Protocolo, #Bal_Erro_Abertura ou #Bal_Erro_Outros
     */

    ///@cond
    E1_BALANCASHARED_EXPORT STDCALL
    ///@endcond
    int ConfigurarModeloBalanca(int modeloBalanca);


    // METODOS PARA CONFIGURACAO DO PROTOCOLO
    ////////////////////////////////////////////////////////////////////////////////////////////////////

    /*! \ingroup g5
     * \brief Obtém o protocolo de comunicação configurado para uso na biblioteca.
     *
     * \return
     * O retorno da função é do tipo numérico.\n
     * A função bem-sucedida deve retornar o código correspondente ao protocolo em uso, conforme tabela abaixo:
     * Código | Protocolo
     * ------ | ---------
     * 0      | Protocolo 0
     * 1      | Protocolo 1
     * 2      | Protocolo 2
     * 3      | Protocolo 3
     * 4      | Protocolo 4
     * 5      | Protocolo 5
     * 7      | Protocolo 7
     * \n
     *
     * * Para mais informações, consulte #Bal_Erro_Balanca, #Bal_Erro_Protocolo, #Bal_Erro_Abertura ou #Bal_Erro_Outros
     */

    ///@cond
    E1_BALANCASHARED_EXPORT STDCALL
    ///@endcond
    int ObterProtocoloComunicacao();

    /*! \ingroup g5
     * \brief Configura o protocolo de comunicação para uso na biblioteca.
     *
     * \param protocoloComunicacao - Parâmetro do tipo numérico que corresponde ao código do protocolo desejado, conforme tabela abaixo:
     * Código | Protocolo
     * ------ | ---------
     * 0      | Protocolo 0
     * 1      | Protocolo 1
     * 2      | Protocolo 2
     * 3      | Protocolo 3
     * 4      | Protocolo 4
     * 5      | Protocolo 5
     * 7      | Protocolo 7
     * \n
     *
     * \return
     * O retorno da função é do tipo numérico.\n
     * A função bem-sucedida deve retornar 0.\n
     *
     * * Para mais informações, consulte #Bal_Erro_Balanca, #Bal_Erro_Protocolo, #Bal_Erro_Abertura ou #Bal_Erro_Outros
     */

    ///@cond
    E1_BALANCASHARED_EXPORT STDCALL
    ///@endcond
    int ConfigurarProtocoloComunicacao(int protocoloComunicacao);


    // METODOS PARA COMUNICACAO COM A BALANCA
    ////////////////////////////////////////////////////////////////////////////////////////////////////

    /*! \ingroup g5
     * \brief Abre uma conexão serial com a balança.
     * * OBS: Os valores válidos listados nos parâmetros desta função não se aplicam à todas as balanças;
     * para obter a lista dos valores suportados em uma balança específica, vide manual.
     *
     * \param device - Parâmetro do tipo caractere que define a porta serial desejada. Exemplo: COM2\n
     * * OBS: Na versão Android desta biblioteca não é preciso especificar a porta serial, uma vez que
     * esse parâmetro não está disponível.\n
     * \n
     *
     * \param baudrate - Parâmetro do tipo numérico que define o baudrate da conexão.\n
     * Valores válidos:
     * > 1200\n
     * > 2400\n
     * > 4800\n
     * > 9600\n
     * > 19200\n
     * > 38400\n
     * > 57600\n
     * > 115200\n
     * \n
     *
     * \param length - Parâmetro do tipo numérico que define o length da conexão.\n
     * Valores válidos:
     * > 5\n
     * > 6\n
     * > 7\n
     * > 8\n
     * \n
     *
     * \param parity - Parâmetro do tipo caractere que define a paridade da conexão.\n
     * Valores válidos:
     * Valor | Paridade
     * ----- | --------
     * n     | No Parity (Sem Paridade)
     * N     | No Parity (Sem Paridade)
     * e     | Even Parity (Paridade Par)
     * E     | Even Parity (Paridade Par)
     * o     | Odd Parity (Paridade Ímpar)
     * O     | Odd Parity (Paridade Ímpar)
     * \n
     *
     * \param stopbits - Parâmetro do tipo numérico que define o número de bits de parada.\n
     * Valores válidos:
     * > 1\n
     * > 2\n
     * \n
     *
     * \return
     * O retorno da função é do tipo numérico.\n
     * A função bem-sucedida deve retornar 0.\n
     *
     * * Para mais informações, consulte #Bal_Erro_Balanca, #Bal_Erro_Protocolo, #Bal_Erro_Abertura ou #Bal_Erro_Outros
     */

    ///@cond
    E1_BALANCASHARED_EXPORT STDCALL
    ///@endcond
    int AbrirSerial(const char* device, int baudrate, int length, char parity, int stopbits);

//    ///@cond
//    E1_BALANCASHARED_EXPORT STDCALL
//    ///@endcond
//    int AbrirTCP(const char* enderecoIP, int porta);

    /*! \ingroup g5
     * \brief Envia comandos direto para a porta de comunicação.
     *
     * Função de despejo de comandos na porta de comunicação. Essa função também recebe dados da porta de comunicação.
     *
     * \param wbuffer - Sequência de comandos que devem ser enviados para a porta de comunicação.\n
     *
     * \param wlen - Quantidade de comandos enviados e que serão escritos.\n
     *
     * \param rdbuffer - Alocação de memória que receberá os dados de retorno caso seja necessário.\n
     *
     * \param rdlen - Quantidade de dados que se espera ler.\n
     * Para evitar a leitura da porta esse parâmetro deve estar em ZERO (0).\n
     * O valor passado nesse parâmetro não pode ser maior do que a memória alocada em rdbuffer.\n
     *
     * \return
     * O retorno da função é do tipo numérico.\n
     * A função bem-sucedida deve retornar a quantidade de bytes lidos (se rdlen > 0) ou a quantidade de bytes
     * escritos (se rdlen == 0).\n
     *
     * * Para mais informações, consulte #Bal_Erro_Balanca, #Bal_Erro_Protocolo, #Bal_Erro_Abertura ou #Bal_Erro_Outros
     */

    ///@cond
    E1_BALANCASHARED_EXPORT STDCALL
    ///@endcond
    int DirectIO(const char* wbuffer, unsigned int wlen, char* rdbuffer, unsigned int rdlen);

    /*! \ingroup g5
     * \brief Fecha conexão com a balança.
     *
     * \return
     * O retorno da função é do tipo numérico.\n
     * A função bem-sucedida deve retornar 0.\n
     *
     * * Para mais informações, consulte #Bal_Erro_Balanca, #Bal_Erro_Protocolo, #Bal_Erro_Abertura ou #Bal_Erro_Outros
     */

    ///@cond
    E1_BALANCASHARED_EXPORT STDCALL
    ///@endcond
    int Fechar();

    /*! \ingroup g5
     * \brief Obtém o tipo de conexão em uso.
     *
     * \return
     * O retorno da função é do tipo numérico.\n
     * A função bem-sucedida deve retornar o código correspondente ao tipo de conexão em uso, conforme tabela abaixo:
     * Código | Conexão
     * ------ | -------
     * 0      | Sem Conexão
     * 1      | Conexão Serial
     * \n
     *
     * * Para mais informações, consulte #Bal_Erro_Balanca, #Bal_Erro_Protocolo, #Bal_Erro_Abertura ou #Bal_Erro_Outros
     */

    ///@cond
    E1_BALANCASHARED_EXPORT STDCALL
    ///@endcond
    int ObterTipoConexao();


    // METODOS PARA CONTROLE DA BALANCA
    ////////////////////////////////////////////////////////////////////////////////////////////////////

    /*! \ingroup g5
     * \brief Função para leitura de peso.
     * * OBS: Verifique se o protocolo em uso suporta esta funcionalidade.
     *
     * \param qtdLeituras - Parâmetro do tipo numérico que determina a quantidade de vezes em que o peso
     * sobre a balança deve ser consultado.\n
     * Valores válidos:
     * > Números maiores que zero (1, 2, 3, ...).
     * * OBS: Caso o protocolo seja contínuo, esse parâmetro é ignorado.
     *
     * \return
     * O retorno da função é do tipo caractere.\n
     * A função bem-sucedida deve retornar uma cadeia de caracteres que representa o peso lido da balança,
     * conforme protocolo configurado em #ConfigurarProtocoloComunicacao.\n
     *
     * * Para mais informações, consulte #Bal_Erro_Balanca, #Bal_Erro_Protocolo, #Bal_Erro_Abertura ou #Bal_Erro_Outros
     */

    ///@cond
    E1_BALANCASHARED_EXPORT STDCALL
    ///@endcond
    const char* LerPeso(int qtdLeituras);

    /*! \ingroup g5
     * \brief Função para leitura de preço.
     * * OBS: Verifique se o protocolo em uso suporta esta funcionalidade.
     *
     * \param qtdLeituras - Parâmetro do tipo numérico que determina a quantidade de vezes em que o preço
     * configurado na balança deve ser consultado.\n
     * Valores válidos:
     * > Números maiores que zero (1, 2, 3, ...).
     * * OBS: Caso o protocolo seja contínuo, esse parâmetro é ignorado.
     *
     * \return
     * O retorno da função é do tipo caractere.\n
     * A função bem-sucedida deve retornar uma cadeia de caracteres que representa o preço configurado na balança,
     * conforme protocolo configurado em #ConfigurarProtocoloComunicacao.\n
     *
     * * Para mais informações, consulte #Bal_Erro_Balanca, #Bal_Erro_Protocolo, #Bal_Erro_Abertura ou #Bal_Erro_Outros
     */

    ///@cond
    E1_BALANCASHARED_EXPORT STDCALL
    ///@endcond
    const char* LerPreco(int qtdLeituras);

    /*! \ingroup g5
     * \brief Função para leitura de tara.
     * * OBS: Verifique se o protocolo em uso suporta esta funcionalidade.
     *
     * \return
     * O retorno da função é do tipo caractere.\n
     * A função bem-sucedida deve retornar uma cadeia de caracteres que representa a tara feita na balança,
     * conforme protocolo configurado em #ConfigurarProtocoloComunicacao.\n
     *
     * * Para mais informações, consulte #Bal_Erro_Balanca, #Bal_Erro_Protocolo, #Bal_Erro_Abertura ou #Bal_Erro_Outros
     */

    ///@cond
    E1_BALANCASHARED_EXPORT STDCALL
    ///@endcond
    const char* LerTara(); // TESTAR!!!

    /*! \ingroup g5
     * \brief Função para leitura de preço total (peso * preço).
     * * OBS: Nos protocolos 0, 1, 2, 3 e 7, a <b>biblioteca</b> calculará o total com base no peso lido da balança e no
     * valor passado ao parâmetro <i>preco</i>; nos protocolos 4 e 5, o <i>preco</i> será enviado à balança e o <b>próprio
     * protocolo</b> fará o cálculo.
     *
     * \param preco - Parâmetro do tipo numérico que configura o preço/kg da balança, em R$ (reais), usado no cálculo
     * do preço total.\n
     * Valores válidos:
     * > Números entre 0.00 e 9999.99 (0.00, ..., 9999.99).
     * * OBS: A precisão é de duas casas decimais.
     *
     * \return
     * O retorno da função é do tipo caractere.\n
     * A função bem-sucedida deve retornar uma cadeia de caracteres que representa o preço total, em R$ (reais).\n
     *
     * * Para mais informações, consulte #Bal_Erro_Balanca, #Bal_Erro_Protocolo, #Bal_Erro_Abertura ou #Bal_Erro_Outros
     */

    ///@cond
    E1_BALANCASHARED_EXPORT STDCALL
    ///@endcond
    const char* LerTotal(double preco); // TESTAR PROTOCOLOS #4 E #5

    /*! \ingroup g5
     * \brief Função para tarar/destarar a balança.
     * * OBS: Verifique se o protocolo em uso suporta esta funcionalidade.
     *
     * \return
     * O retorno da função é do tipo numérico.\n
     * A função bem-sucedida deve retornar 0.\n
     *
     * * Para mais informações, consulte #Bal_Erro_Balanca, #Bal_Erro_Protocolo, #Bal_Erro_Abertura ou #Bal_Erro_Outros
     */

    ///@cond
    E1_BALANCASHARED_EXPORT STDCALL
    ///@endcond
    int TararBalanca(); // TESTAR!!!

    /*! \ingroup g5
     * \brief Função para zerar a balança.
     * * OBS: Verifique se o protocolo em uso suporta esta funcionalidade.
     *
     * \return
     * O retorno da função é do tipo numérico.\n
     * A função bem-sucedida deve retornar 0.\n
     *
     * * Para mais informações, consulte #Bal_Erro_Balanca, #Bal_Erro_Protocolo, #Bal_Erro_Abertura ou #Bal_Erro_Outros
     */

    ///@cond
    E1_BALANCASHARED_EXPORT STDCALL
    ///@endcond
    int ZerarBalanca(); // TESTAR!!!

    /*! \ingroup g5
     * \brief Função para ligar/desligar a balança (display).
     * * OBS: Verifique se o protocolo em uso suporta esta funcionalidade.
     *
     * \return
     * O retorno da função é do tipo numérico.\n
     * A função bem-sucedida deve retornar 0.\n
     *
     * * Para mais informações, consulte #Bal_Erro_Balanca, #Bal_Erro_Protocolo, #Bal_Erro_Abertura ou #Bal_Erro_Outros
     */

    ///@cond
    E1_BALANCASHARED_EXPORT STDCALL
    ///@endcond
    int LigarDesligarDisplay(); // TESTAR!!!


    /*! \ingroup g5
     * \brief Obtém o tempo máximo configurado para a duração da <b>leitura contínua</b>.
     * * OBS: O valor padrão é de 500 ms.
     *
     * \return
     * O retorno da função é do tipo numérico.\n
     * A função bem-sucedida deve retornar o tempo máximo, em milissegundos, que a operação de <b>leitura contínua</b>
     * deve durar.\n
     *
     * * Para mais informações, consulte #Bal_Erro_Balanca, #Bal_Erro_Protocolo, #Bal_Erro_Abertura ou #Bal_Erro_Outros
     */

    ///@cond
    E1_BALANCASHARED_EXPORT STDCALL
    ///@endcond
    int GetContinuousReadTime();

    /*! \ingroup g5
     * \brief Configura o tempo máximo para a duração da <b>leitura contínua</b>.
     *
     * \param continuousReadTime - Parâmetro do tipo numérico que define o tempo máximo, em milissegundos, que a
     * operação de <b>leitura contínua</b> deve durar.
     *
     */

    ///@cond
    E1_BALANCASHARED_EXPORT STDCALL
    ///@endcond
    void SetContinuousReadTime(int continuousReadTime);

}


#endif // EXPORTAFUNCOES_H
