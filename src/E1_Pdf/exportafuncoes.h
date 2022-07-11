#ifndef EXPORTAFUNCOES_H
#define EXPORTAFUNCOES_H
#include "E1_Pdf_global.h"
#include <QGuiApplication>


#ifdef __WIN32
#define STDCALL __stdcall
#elif __linux__
#define STDCALL
#endif

extern  "C"{
    /*! \defgroup g9 Gerador PDF
     *  \brief Fornece funções para geração de Danfe NFCe e SAT.
     *  # E1 PDF Elgin
     *  O E1 Pdf Elgin é uma solução que fornece para Automação Comercial a possibilidade de gerar Danfes no formato PDF. Essa solução possibilita a geração PDF da danfe para os XML de retornos do SAT (Sistema autorizador transmissor) para as operações de Venda e Cancelamento e também para os XML de retorno de emissão de nota fiscal do contribuinte NFCE. Além de que o usuário pode variar entre layouts diferentes de acordo com a necessidade.
     *
     *  ## Por onde começar?
     *
     *  Baixe o pacote da solução E1 Pdf Elgin em github.com/elgindevelopercommunity. Através deste pacote, você poderá gerar a danfe em formato pdf se comunicando com a biblioteca (.dll).
     *
     *  ### Nomenclatura dos arquivos gerados
     *  Os arquivos processados com sucesso são gravados em `workdir`, \n
     *  ou em uma pasta definida pela função #ConfiguraDiretorioSaida,\n
     *  ou no caminho definido para variavel de ambiente `saida_e1_pdf`,\n
     *  seguindo os detalhes abaixo:
     *  ./DANFE/(SAT ou NFCe)/(VENDA ou CANCELAMENTO)/yyyy/MM/dd/yyyyMMddHHmmss.pdf
     *
     *
     * Convenções usadas nas chamadas das funções da biblioteca:\n
     * <b>Windows</b>\n
     *  > __stdcall
     * <b>Linux</b>\n
     *  > __cdecl\n
     */

   /*!
    * \ingroup g9
    * \brief Gera PDF Danfe SAT.
    *
    * Essa função recebe o XML de retorno da venda do SAT, valida o conteúdo, constrói o Danfe e realiza a geração do pdf de acordo com
    * a especificação da SEFAZ SP.
    * \param dados - Conteúdo do XML de retorno da venda do SAT.
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
    * A função bem sucedida deve retornar 0 e o arquivo PDF será salvo conforme definição do caminho de saída.\n
    * * Para mais informações sobre retorno consulte #IMP_Erro_ValidacaoXMLSAT ou #IMP_Erro_ValidacaoXML.
    *
    * Informações que não estejam presentes no XML serão desconsideradas.
    *
    */

    ///@cond
    E1_PDF_EXPORT STDCALL
    ///@endcond
    int GeraPDFSAT(char *dados_xml,int param);

    /*! \ingroup g9
     * \brief Gera PDF Danfe de cancelamento SAT.
     *
     * Essa função recebe o XML de retorno da operação de cancelamento e os dados de assinatura do QRCode de venda, valida as
     * informações, constrói o Danfe e realiza geração do cupom no formato PDF de acordo com a especificação da SEFAZ SP.
     * \param dados - Conteúdo do XML de cancelamento retornado pelo SAT.
     * \param assQRCode - Assinatura do QRCode retornado na operação de Venda. Essa informação é necessária porque o XML de retorno
     * da operação de cancelamento não contém essa informação.
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
     * A função bem sucedida deve retornar 0 e o arquivo PDF será salvo conforme definição do caminho de saída.\n
     *
     * Informações que não estejam presentes no XML serão desconsideradas.
     */

    ///@cond
    E1_PDF_EXPORT STDCALL
    ///@endcond
    int GeraPDFSATCancelamento(char *dados_xml,char* assQRCode,int param);

      /*! \ingroup g9
       * \brief Gera Pdf Danfe NFCe
       *
       * Essa função recebe o conteúdo do XML de venda do NFCe, valida o conteúdo, constrói o Danfe e realiza a geração do mesmo no formato Pdf.
       * \param dados - Conteúdo do XML retornado pela venda.
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
       * A função bem sucedida deve retornar 0 e o arquivo PDF será salvo conforme definição do caminho de saída.\n
       * * Para mais informações sobre retorno consulte #IMP_Erro_ValidacaoXMLNFCe ou #IMP_Erro_ValidacaoXML.
       *
       * Informações que não estejam presentes no XML serão desconsideradas.
       *
       *
       */

    ///@cond
    E1_PDF_EXPORT STDCALL
    ///@endcond
    int GeraPDFNFCe(char *dados,int indexcsc, char *csc, int param);

    ///@cond
    E1_PDF_EXPORT STDCALL
    ///@endcond
    /*! \ingroup g9
     * \brief ConfiguraDiretorioSaida - Função usada para configurar o diretório onde serão gerados os pdf.\n
     * A estrutura de diretório criado deve seguir conforme a seguir:\n
     * > ./DANFE/(SAT ou NFCe)/(VENDA ou CANCELAMENTO)/yyyy/MM/dd/yyyyMMddHHmmss.pdf
     * onde:
     * > yyyy = ANO\n
     * > MM = MÊS\n
     * > dd = DIA\n
     * > hh = HORA\n
     * > mm = MINUTO\n
     * > ss = SEGUNDO\n
     *
     * \param caminho
     * Parametro para informar caminho raiz onde serão gerados os decumentos.
     *
     * \note
     * O mesmo comportamento pode ser atingido configurando uma variável de ambiente chamada `saida_e1_pdf`\n
     * com o caminho onde deve ser gerado os arquivos.\n
     * A prioridade será da configuração será o valor da variavel de ambiente quando a mesma estiver definida.
     *
     * \return
     * O retorno é numérico.\n
     * A função bem sucedida deve retornar 0
     */
    int ConfiguraDiretorioSaida(const char *caminho);

    ///@cond
    E1_PDF_EXPORT STDCALL
    ///@endcond
    /*! \ingroup g9
     * \brief ObtemUltimoArquivo - Essa função deve ser utilizada para capturar o caminho do ultimo arquivo gerado pelas funções:\n
     * #GeraPDFSAT\n
     * #GeraPDFSATCancelamento\n
     * #GeraPDFNFCe\n
     *
     * \return
     * O retorno deve ser o caminho absoluto para o último arquivo gerado.
     */
    const char *ObtemUltimoArquivo();

     ///@cond
     E1_PDF_EXPORT STDCALL
     ///@endcond
     /*! \ingroup g9
     * \brief ImprimePDF.
     *
     * Função utilzada para realizar a impressão da Danfe PDF gerado pela biblioteca E1_Pdf na impressora padrão configurada no sistema operacional.
     * \param caminho - Parâmetro que recebe o caminho absoluto da Danfe PDF a ser impressa.
     *
     * \return
     * O retorno é numérico.\n
     * A função bem sucedida deve retornar 0
     * Para mais informações sobre retorno consulte #PDF_Error.
     * */
    int ImprimePDF(const char *caminho);
};
#endif // EXPORTAFUNCOES_H
