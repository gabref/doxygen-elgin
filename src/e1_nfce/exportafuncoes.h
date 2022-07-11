#ifndef EXPORTAFUNCOES_H
#define EXPORTAFUNCOES_H

#include "e1_nfce.h"
#include "factoryjsonnfce.h"

#ifdef __linux__
    #define STDCALL
#elif _WIN32
    #define STDCALL __stdcall
#endif

//void __attribute__((constructor)) _initLibrary();
//void __attribute__((destructor)) _exitLibrary();

E1_NFCe e;
FactoryJsonNFCe fac;
extern "C" {

    /*! \defgroup g11 E1 NFC-e
     * \brief E1 NFC-e
     * \brief Esse módulo tem como objetivo simplificar o processo de integração dos pontos de venda (PDV) com o ambiente SEFAZ de emissão de nota fiscal do consumidor (NFCe). A aplicação de PDV deverá utilizar o módulo E1_NFCe para gerar os arquivos que serão transmitidos para sefaz e ao fim da geração devera enviar o arquivo gerado para função de emissão. Antes de entrar nos detalhes de integração se faz necessários alguns esclarecimentos sobre esse módulo. Abaixo estão detalhados os componentes desse módulo.
     *
     * ###Componentes
     * \b E1_NFCe \b (DLL/SO) \b - Extensão de aplicativo (DLL/SO) onde estão exportadas todas as funções para criação do documento, emissão, consulta e cancelamento de notas. É por meio dessa que o PDV fara toda a integração com o sistema de NFCe.

     * \b api_settings.ini \b - Arquivo de configuração da DLL, onde estão as configurações de timeout, identificação do PDV, URL da plataforma cloud e configurações de proxy.

     * \b NFCe \b Veraciti \b - Plataforma cloud responsavel por realizar a assinatura e transmissão para a SEFAZ. Nesse sistema o parceiro irá criar toda sua estrutura, desde a empresa, PDVs, configuração dos certificados. Também será nessa plataforma onde o cliente poderá consultar as notas emitidas, status das notas, valores processados, etc.
     *
     *
     * ###Por onde começar
     * ###Cloud
     *  -# A integração com o sistema de emissão de nota fiscal do consumidor pode ser iniciado criando uma conta na plataforma da Veracitti. Solicite a criação da conta pelo canal de suporte ao desenvolvedor (https://elginbematech.com.br/chamado/).\n
     *  -# Após a criação da conta, acesse https://nfce.veraciti.com.br/#/ e realize o login com os dados recebidos no email de cadastro.\n
     *  -# Ao realizar o primeiro acesso, faça o cadastro da empresa emitente no menu lateral Empresas > Empresas > Nova Empresa.\n
     *  ***Para emissão de NFCe será necessário carregar um certificado digital válido para assinatura dos documentos.***\n\n
     * \image html cadastro_empresa.png
     * \n
     *  -# Logo em seguida, crie um PDV clicando sobre Novo ponto de venda na opção PDVS da empresa criada anteriormente.\n\n
     * \image html cadastro_pdv.png
     * \n
     *  -# Após a criação do Ponto de Venda, será gerado os dados de autenticação com a plataforma, ClientID e Client Secret. Essa informações são visualizadas na seta ao lado de Editar.\n\n
     * \image html dados_cliente.png
     * \n
     *  -# Guarde estes dados para configuração do arquivo api_settings.ini.\n
     * ####
     * ###Local
     *  • O primeiro passo será configurar no arquivo api_settings.ini os dados do PDV que está sendo configurado. Por padrão a DLL irá criar o arquivo caso no encontre o mesmo na pasta de trabalho. Seu conteúdo padrão deve ser parecido com o descrito abaixo:
     *
     * ``` ini
     * # Endereços da plataforma NFCE Veraciti
     * [ENDPOINTS]
     * raiz=https://console.veraciti.com.br/api/v1/
     * token=auth2_token/token
     * emissao=nfce/
     * consulta=nfce/{nfe_key}
     * cancelamento=nfce/{nfe_key}/cancel
     *
     * # Configurações de proxy
     * [CONFIGURACOES_PROXY]
     * # Aceita 0 para desativar e 1 para ativar
     * ativado=0
     * endereco_ip=127.0.0.1
     * porta=8080
     * usuario=null
     * senha=null
     *
     * # Dados de autenticação com plataforma Veraciti
     * [DADOS_CLIENTE]
     * # Substituir por dados gerados na criação do PDV
     * client_id=null
     * client_secret=null
     * timeout_comunicacao=30
     * ```
     *
     * Convenções usada nas chamadas das funções da biblioteca: \n
     * <b>Windows</b>\n
     *   > __stdcall
     * <b>Linux</b>\n
     *   > __cdecl\n
     *
     *  • Localmente, o PDV deve carregar a DLL/SO e realizar as chamadas referente a criação do documento de\n
     *    acordo com a venda e então chamar a função de Emissão da nota.\n
     *  • Ao fim desse fluxo o PDV irá receber um json com os detalhes da emissão e o arquivo de XML processado pela\n
     *    sefaz em BASE64.\n
     *  • O PDV pode ainda usar a função de decodificação da nota para traduzir o BASE64 e gerar o arquivo em uma\n
     *    estrutura de pasta organizadas por data.\n\n
     *
     * O fluxo de integração com o a DLL segue os seguintes passos:
     *
     * \image html fluxo_basico_integracao.jpg
     */

     /*! \defgroup g50 Funcoes NFC-e E1
     * \ingroup g11
     *

     *//**
     * \ingroup g50
     * Função utilizada para teste de comunicação com API de autorização.
     * \return
     * O retorno em caso de sucesso será o conteúdo da resposta HTTP(200).
     */

    ///@cond
    E1_NFCESHARED_EXPORT STDCALL
    ///@endcond
    int TestaConexaoNFCe();

    /*! \ingroup g50
    *
    * Função utilizada na emissão de uma Nota Fiscal Eletrônica, após a geração da mesma.
    *
    * \param arquivo_nota - Caminho do arquivo contendo json com os dados da nota.
    *
    * \param ret - Receber a referência do dado após a emissão da nota.
    *
    * \return
    * O retorno em caso de sucesso será o conteúdo da resposta HTTP(200).
    *
    */

    ///@cond
    E1_NFCESHARED_EXPORT STDCALL
    ///@endcond
    const char *EmitirNota(const char *arquivo_nota, int *ret);

    /*! \ingroup g50
    *
    * Função utilizada para consultar um determinada Nota Fiscal Eletrônica pela chave.
    *
    * \param chave_nota - Parâmetro tipo String que recebe a chave da nota a ser consultada.
    *
    * \param ret - Parâmetro do tipo ponteiro para int que será passado por referência.
    *
    * \return
    * O retorno em caso de sucesso será o conteúdo da resposta HTTP(200).
    *
    */

    ///@cond
    E1_NFCESHARED_EXPORT STDCALL
    ///@endcond
    const char *ConsultarNota(const char *chave_nota, int* ret);

    /*! \ingroup g50
    *
    * Função utilizada no cancelamento da Nota Fiscal Eletrônica pela chave.
    *
    * \param chave_nota - Parâmetro tipo String que recebe a chave da nota a ser cancelada.
    *
    * \param protocolo - Parâmetro do tipo String que recebe o protocolo para cancelamento da nota.
    *
    * \param justificativa - Parâmetro do tipo String que recebe a justificativa para cancelamento da nota.
    *
    * \param ret - Parâmetro do tipo ponteiro para int que será passado por referência.
    *
    * \return
    * O retorno em caso de sucesso será o conteúdo da resposta HTTP(200).
    *
    */

    ///@cond
    E1_NFCESHARED_EXPORT STDCALL
    ///@endcond
    const char *CancelarNota(const char *chave_nota, const char *protocolo, const char *justificativa, int* ret);
    ///////////////////ALTERAR
    /*! \ingroup g50
    *
    * Função utilizada na decodificação da Nota Fiscal Eletrônica.
    *
    * \param path_root - Parâmetro tipo String contendo o caminho do arquivo contendo json com os dados da nota.
    *
    * \param resposta_emitir_nota - Parâmetro do tipo String que recebe o dado da emissão em BASE64.
    *
    * \param ret - Parâmetro do tipo ponteiro para int que será passado por referência.
    *
    * \return
    * O retorno em caso de sucesso sera o dado da emissão decodificado.
    *
    */

    ///@cond
    E1_NFCESHARED_EXPORT STDCALL
    ///@endcond
    const char *DecodificarNota(const char *path_root, const char *resposta_emitir_nota, int* ret);

    /*! \ingroup g50
    *
    * Função utilizada para consulta de Id de uma operação específica de emissão de cupom.
    *
    * \param id_local - Parâmetro tipo String contendo Id usado na emissão a ser consultada.
    *
    * \param ret - Parâmetro do tipo ponteiro para int que será passado por referência.
    *
    * \return
    * O retorno em caso de sucesso será o conteúdo da resposta HTTP(200).
    *
    */

    ///@cond
    E1_NFCESHARED_EXPORT STDCALL
    ///@endcond
    const char *ConsultarId(const char *id_local, int* ret);
    /*! \ingroup g50
    *
    * Função utilizada para consultar uma lista de eventos ocorridos na emissão da nota.
    *
    * \param chave_nota - Parâmetro tipo String que recebe a chave da nota a ser consultada os eventos.
    * \param ret - Parâmetro do tipo ponteiro para int que será passado por referência.
    *
    * \return
    * O retorno em caso de sucesso será o conteúdo da resposta HTTP(200).
    *
    */

    ///@cond
    E1_NFCESHARED_EXPORT STDCALL
    ///@endcond
    const char *ListarEventos(const char *chave_nota, int* ret);

    /*! \ingroup g50
    *
    * Função usada na gravação dos dados de venda partir do diretório informado em 'path_file' para abertura do cupom.\n
    *
    * \param path_file
    * Caminho absoluto onde o arquivo json será gerado.\n
    * EX:\n
    * > C:/NFCE/venda_001.json
    *
    * \param cUF
    * Código da UF do emitente do Documento Fiscal.\n
    * > <b>TAG:</b> B02\n
    * > <b>Parametro obrigatório</b>\n
    * > <b>Tipo:</b> Alfanumérico\n
    * > <b>Tamanho:</b> 2 \n
    *
    * \param cNF
    * Código numérico que compõe a chave de acesso.\n
    * > <b>TAG:</b> B03\n
    * > <b>Parametro opcional</b>\n
    * > <b>Tipo:</b> Numérico\n
    * > <b>Tamanho:</b> 8 \n
    *
    * \param natOp
    * Descrição da Natureza da Operação.\n
    * > <b>TAG:</b> B04\n
    * > <b>Parametro obrigatório</b>\n
    * > <b>Tipo:</b> Alfanumérico\n
    * > <b>Tamanho:</b> 1-60\n
    *
    * \param mod
    * Código do Modelo do Documento Fiscal \n
    * 55=NF-e emitida em substituição ao modelo 1 ou 1A;
    * 65=NFC-e, utilizada nas operações de venda no varejo (a critério da UF aceitar este modelo de documento).
    * > <b>TAG:</b> B07\n
    * > <b>Parametro opcional</b>\n
    * > <b>Tipo:</b> Numérico\n
    * > <b>Tamanho:</b> 2\n
    *
    * \param serie
    * Série do Documento Fiscal.\n
    * > <b>TAG:</b> B07\n
    * > <b>Parametro opcional</b>\n
    * > <b>Tipo:</b> Numérico\n
    * > <b>Tamanho:</b> 1-3\n
    *
    * \param nNF
    * Número do documento fiscal.\n
    * > <b>TAG:</b> B08\n
    * > <b>Parametro opcional</b>\n
    * > <b>Tipo:</b> Numérico\n
    * > <b>Tamanho:</b> 1-9\n
    *
    * \param dhEmi
    * Data e hora de emissão do Documento Fiscal: AAAA-MM-DDThh:mm:ssTZD\n
    * > <b>TAG:</b> B09\n
    * > <b>Parametro opcional</b>\n
    * > <b>Tipo:</b> Alfanumérico\n
    * > <b>Tamanho:</b> --\n
    *
    * \param dhSaiEnt
    * Data e hora de Saída ou da Entrada da Mercadoria/Produto\n
    * > <b>TAG:</b> B10\n
    * > <b>Parametro opcional</b>\n
    * > <b>Tipo:</b> Alfanumérico\n
    * > <b>Tamanho:</b> --\n
    *
    * \param tpNF
    * Tipo de Operação da NF-e: 0=Entrada; 1=Saída\n
    * > <b>TAG:</b> B11\n
    * > <b>Parametro opcional</b>\n
    * > <b>Tipo:</b> Numérico\n
    * > <b>Tamanho:</b> 1 \n
    *
    * \param idDest
    * Identificador de local de destino da operação : 1=Operação interna; 2=Operação interestadual; 3=Operação com exterior. \n
    * > <b>TAG:</b> B11a\n
    * > <b>Parametro opcional</b>\n
    * > <b>Tipo:</b> Numérico\n
    * > <b>Tamanho:</b> 1\n
    *
    * \param cMunFG
    * Código do Município de Ocorrência do Fato Gerador\n
    * > <b>TAG:</b> B12\n
    * > <b>Parametro opcional</b>\n
    * > <b>Tipo:</b> Numérico\n
    * > <b>Tamanho:</b> 7\n
    *
    * \param tpImp
    * Formato de Impressão do DANFE \n
    * > <b>TAG:</b> B21\n
    * > <b>Parametro obrigatório</b>\n
    * > <b>Tipo:</b> Numérico\n
    * > <b>Tamanho:</b> 1\n
    *
    * \param tpEmis
    * Tipo de Emissão da NF-e \n
    * > <b>TAG:</b> B22\n
    * > <b>Parametro opcional</b>\n
    * > <b>Tipo:</b> Numérico\n
    * > <b>Tamanho:</b> 1 \n
    *
    * \param cDV
    * Dígito Verificador da Chave de Acesso da NF-e \n
    * > <b>TAG:</b> B23\n
    * > <b>Parametro opcional</b>\n
    * > <b>Tipo:</b> Numérico\n
    * > <b>Tamanho:</b> 1 \n
    *
    * \param tpAmb
    * Identificação do Ambiente: 1=Produção/2= Homologação\n
    * > <b>TAG:</b> B24 \n
    * > <b>Parametro opcional</b>\n
    * > <b>Tipo:</b> Numérico \n
    * > <b>Tamanho:</b> 1 \n
    *
    * \param finNFe
    * Finalidade de emissão da NF-e \n
    * > <b>TAG:</b> B25\n
    * > <b>Parametro opcional</b>\n
    * > <b>Tipo:</b> Numérico\n
    * > <b>Tamanho:</b> 1\n
    *
    * \param indFinal
    * Indica operação com Consumidor final: 0=Normal; 1=Consumidor final;\n
    * > <b>TAG:</b> B25a\n
    * > <b>Parametro opcional</b>\n
    * > <b>Tipo:</b> Numérico\n
    * > <b>Tamanho:</b> 1\n
    *
    * \param indPres
    * Indicador de presença do comprador no estabelecimento comercial no momento da operação \n
    * > <b>TAG:</b> B25b\n
    * > <b>Parametro obrigatório</b>\n
    * > <b>Tipo:</b> Numérico\n
    * > <b>Tamanho:</b> 1 \n
    *
    * \param indIntermed
    * Indicador de intermediador/marketplace\n
    * > <b>TAG:</b> B25c \n
    * > <b>Parametro opcional</b>\n
    * > <b>Tipo:</b> Numérico\n
    * > <b>Tamanho:</b> 1 \n
    *
    * \param procEmi
    * Processo de emissão da NF-e\n
    * > <b>TAG:</b> B26\n
    * > <b>Parametro opcional</b>\n
    * > <b>Tipo:</b> Numérico\n
    * > <b>Tamanho:</b> 1 \n
    *
    * \param verProc
    * Versão do Processo de emissão da NF-e \n
    * > <b>TAG:</b> B27\n
    * > <b>Parametro opcional</b>\n
    * > <b>Tipo:</b> Alfanumérico\n
    * > <b>Tamanho:</b> 1-20\n
    *
    * \param dhCont
    * Data e Hora da entrada em contingência \n
    * > <b>TAG:</b> B28\n
    * > <b>Parametro opcional</b>\n
    * > <b>Tipo:</b> Alfanumérico\n
    * > <b>Tamanho:</b> --\n
    *
    * \param xJust
    * Justificativa da entrada em contingência\n
    * > <b>TAG:</b> B29\n
    * > <b>Parametro opcional</b>\n
    * > <b>Tipo:</b> Alfanumérico\n
    * > <b>Tamanho:</b> 15-256\n
    *
    * \param idLocal
    * Identificador único por ponto de venda para recuperação do status caso haja falha de conexão com a plataforma durante a autorização \n
    * > <b>Parametro opcional</b>\n
    * > <b>Tipo:</b> Alfanumérico\n
    * > <b>Tamanho:</b> 1-128\n
    *
    * \return
    * O retorno em caso de sucesso será(0). \n
    * Possiveis erros\n
    *
    * | DESCRIÇÃO                              | VALOR|
    * |----------------------------------------|------|
    * | NFCE_CNF_INVALIDO                      | -601 |
    * | NFCE_NATUREZA_OPERACAO_INVALIDA        | -602 |
    * | NFCE_MODELO_INVALIDA                   | -603 |
    * | NFCE_SERIE_INVALIDA                    | -604 |
    * | NFCE_NNF_INVALIDA                      | -605 |
    * | NFCE_TIPO_OPERACAO_INVALIDA            | -606 |
    * | NFCE_DESTINO_OPERACAO_INVALIDO         | -607 |
    * | NFCE_CODIGO_MUNICIPIO_ICMS_INVALIDO    | -608 |
    * | NFCE_TP_IMPRESSAO_INVALIDA             | -609 |
    * | NFCE_TP_EMISSAO_INVALIDA               | -610 |
    * | NFCE_DIGITO_VERIFICADOR_INVALIDO       | -611 |
    * | NFCE_FINALIDADE_EMISSAO_INVALIDA       | -612 |
    * | NFCE_IND_CONSUMIDOR_FINAL_INVALIDA     | -613 |
    * | NFCE_IND_PRESENCA_INVALIDA             | -614 |
    * | NFCE_PROC_EMISSAO_INVALIDA             | -615 |
    * | NFCE_VERSAO_APP_INVALIDA               | -616 |
    * | NFCE_PARAMETRO_INVALIDO                | -617 |
    * | NFCE_IDLOCAL_INVALIDO                  | -618 |
    *
    */

    ///@cond
    E1_NFCESHARED_EXPORT STDCALL
    ///@endcond
    int AbreCupomVenda(const char *path_file, const char *cUF, const char *cNF, const char *natOp, int mod, const char *serie, const char *nNF, const char *dhEmi,
                       const char *dhSaiEnt, int tpNF, int idDest, const char *cMunFG, int tpImp, int tpEmis, int cDV, int tpAmb, int finNFe, int indFinal,
                       int indPres, int indIntermed, int procEmi, const char *verProc, const char *dhCont, const char *xJust,const char* idLocal);

    /*! \ingroup g50
    *
    * Função uitlizada para informar emitente para composição das informações a serem enviadas para nuvem.\n
    *
    * \param path_file
    * Caminho absoluto onde o arquivo json será gerado.\n
    * EX:\n
    * > C:/NFCE/venda_001.json
    *
    * \param CNPJ
    * CNPJ do emitente.\n
    * > <b>TAG:</b> C02\n
    * > <b>Parametro obrigatório</b>\n
    * > <b>Tipo:</b> Numérico\n
    * > <b>Tamanho:</b> 14 \n
    *
    * \param CPF
    * CPF do remetente.\n
    * > <b>TAG:</b> C02a\n
    * > <b>Parametro opcional</b>\n
    * > <b>Tipo:</b> Alfanumérico\n
    * > <b>Tamanho:</b> 2-60 \n
    *
    * \param xNome
    * Razão Social ou Nome do emitente.\n
    * > <b>TAG:</b> C03\n
    * > <b>Parametro opcional</b>\n
    * > <b>Tipo:</b> Alfanumérico\n
    * > <b>Tamanho:</b> 60\n
    *
    * \param xFant
    * Nome fantasia.\n
    * > <b>TAG:</b> C04\n
    * > <b>Parâmetro opcional</b>\n
    * > <b>Tipo:</b> Alfanumérico\n
    * > <b>Tamanho:</b> 1-60\n
    *
    * \param xLgr
    * Logradouro.\n
    * > <b>TAG:</b> C06\n
    * > <b>Parametro opcional</b>\n
    * > <b>Tipo:</b> Alfanumérico\n
    * > <b>Tamanho:</b> 2-60\n
    *
    * \param nro
    * Número.\n
    * > <b>TAG:</b> C07\n
    * > <b>Parametro opcional</b>\n
    * > <b>Tipo:</b> Alfanumérico\n
    * > <b>Tamanho:</b> 1-60\n
    *
    * \param xCpl
    * Complemento \n
    * > <b>TAG:</b> C08\n
    * > <b>Parâmetro opcional</b>\n
    * > <b>Tipo:</b> Alfanumérico\n
    * > <b>Tamanho:</b> 1-60\n
    *
    * \param xBairro
    * Bairro \n
    * > <b>TAG:</b> C09\n
    * > <b>Parâmetro opcional</b>\n
    * > <b>Tipo:</b> Alfanumérico\n
    * > <b>Tamanho:</b> 2-60\n
    *
    * \param cMun
    * Código do município\n
    * > <b>TAG:</b> C10\n
    * > <b>Parâmetro opcional</b>\n
    * > <b>Tipo:</b> Numérico\n
    * > <b>Tamanho:</b> 7 \n
    *
    * \param xMun
    * Nome do município \n
    * > <b>TAG:</b> C11\n
    * > <b>Parâmetro opcional</b>\n
    * > <b>Tipo:</b> Alfanumérico\n
    * > <b>Tamanho:</b> 2-60\n
    *
    * \param UF
    * Sigla da UF \n
    * > <b>TAG:</b> C12\n
    * > <b>Parâmetro obrigatório</b>\n
    * > <b>Tipo:</b> Alfabeto \n
    * > <b>Tamanho:</b> 2\n
    *
    * \param CEP
    * Código do CEP \n
    * > <b>TAG:</b> C13\n
    * > <b>Parâmetro obrigatório</b>\n
    * > <b>Tipo:</b> Numérico\n
    * > <b>Tamanho:</b> 8\n
    *
    * \param cPais
    * Código do País (1058 = Brasil) \n
    * > <b>TAG:</b> C14\n
    * > <b>Parâmetro opcional</b>\n
    * > <b>Tipo:</b> Numérico\n
    * > <b>Tamanho:</b> 4\n
    *
    * \param xPais
    * Nome do País \n
    * > <b>TAG:</b> C15\n
    * > <b>Parâmetro opcional</b>\n
    * > <b>Tipo:</b> Alfanumérico\n
    * > <b>Tamanho:</b> 1-60\n
    *
    * \param fone
    * Telefone \n
    * > <b>TAG:</b> C16\n
    * > <b>Parâmetro opcional</b>\n
    * > <b>Tipo:</b> Alfanumérico\n
    * > <b>Tamanho:</b> 6-14\n
    *
    *
    * \param IE
    * Inscrição Estadual do Emitente \n
    * > <b>TAG:</b> C17\n
    * > <b>Parâmetro opcional</b>\n
    * > <b>Tipo:</b> Alfanumérico\n
    * > <b>Tamanho:</b> 2-14\n
    *
    * \param IEST
    * IE do Substituto Tributário\n
    * > <b>TAG:</b> C18\n
    * > <b>Parâmetro opcional</b>\n
    * > <b>Tipo:</b> Numérico\n
    * > <b>Tamanho:</b> 2-14\n
    *
    * \param IM
    * Inscrição Municipal do Prestador de Serviço \n
    * > <b>TAG:</b> C19\n
    * > <b>Parâmetro opcional</b>\n
    * > <b>Tipo:</b> Alfanumérico\n
    * > <b>Tamanho:</b> 1-15\n
    *
    * \param CNAE
    * CNAE fiscal\n
    * > <b>TAG:</b> C20\n
    * > <b>Parâmetro opcional</b>\n
    * > <b>Tipo:</b> Alfanumérico\n
    * > <b>Tamanho:</b> 7\n
    *
    * \param CRT
    * Código de Regime Tributário \n
    * > <b>TAG:</b> C21\n
    * > <b>Parâmetro opcional</b>\n
    * > <b>Tipo:</b> Alfanumérico\n
    * > <b>Tamanho:</b> 1\n
    *
    * \return
    * O retorno em caso de sucesso será ZERO(0).\n
    * Possiveis erros\n
    *
    * | DESCRIÇÃO                       | VALOR|
    * |---------------------------------|------|
    * | NFCE_CNPJ_INVALIDO              | -620 |
    * | NFCE_CPF_INVALIDO               | -621 |
    * | NFCE_ID_ESTRANGEIRO_INVALIDO    | -622 |
    * | NFCE_NOME_INVALIDO              | -623 |
    * | NFCE_ID_IE_DESTINATARIO         | -624 |
    * | NFCE_IE_INVALIDO                | -625 |
    * | NFCE_INCRICAO_SUFRAMA_INVALIDA  | -626 |
    * | NFCE_IM_INVALIDA                | -627 |
    * | NFCE_EMAIL_INVALIDO             | -628 |
    *
    */
    ///@cond
    E1_NFCESHARED_EXPORT STDCALL
    ///@endcond
    int InformaEmitente(const char *path_file, const char *CNPJ, const char *CPF, const char *xNome, const char *xFant,
                        const char *xLgr, const char *nro, const char *xCpl, const char *xBairro, int cMun, const char *xMun,
                        const char *UF, const char *CEP, int cPais, const char *xPais, const char *fone,
                        const char *IE, const char *IEST, const char *IM, const char *CNAE, int CRT);

//    ///@cond
//    E1_NFCESHARED_EXPORT STDCALL
//    ///@endcond
//    int InformaDestinatario(const char *file_path, const char *CNPJ, const char *CPF, const char *idEstrangeiro, const char *xNome,
//                                                          int indIEDest, const char *IE, const char *ISUF, const char *IM, const char *email);
//
//    ///@cond
//    E1_NFCESHARED_EXPORT STDCALL
//    ///@endcond
//    int InformaEnderecoDestinatario(const char *file_path, const char *xLgr, const char *nro, const char *xCpl, const char *xBairro, const char *cMun,
//                                                                  const char *xMun, int UF, const char *CEP, const char *cPais, const char *xPais, const char *fone);
//
//    ///@cond
//    E1_NFCESHARED_EXPORT STDCALL
//    ///@endcond
//    int InformaLocalRetirada(const char *file_path, const char *CNPJ, const char *CPF, const char *xLgr, const char *nro,
//                                                                            const char *xCpl, const char *xBairro, const char *cMun, const char *xMun, int UF);
//
//    ///@cond
//    E1_NFCESHARED_EXPORT STDCALL
//    ///@endcond
//    int InformaLocalEntrega(const char *file_path, const char *CNPJ, const char *CPF, const char *xLgr, const char *nro,
//                                                                           const char *xCpl, const char *xBairro, const char *cMun, const char *xMun, int UF);
//
//    ///@cond
//    E1_NFCESHARED_EXPORT STDCALL
//    ///@endcond
//    int InformaAutorizacaoAcessoXML(const char *file_path, const char *CNPJ, const char *CPF);

    /*! \ingroup g50
    *
    * Função uitlizada para informar transporte para construção do cupoim.\n
    *
    * \param file_path
    * Caminho absoluto onde o arquivo json será gerado.\n
    * EX:\n
    * > C:/NFCE/venda_001.json
    *
    * \param modFrete
    * Modalidade do frete.\n
    * > <b>TAG:</b> X02\n
    * > <b>Parâmetro obrigatório</b>\n
    * > <b>Tipo:</b> Numérico\n
    * > <b>Tamanho:</b> 1 \n
    *
    * \param CNPJ
    * CNPJ do Transportador.\n
    * > <b>TAG:</b> X04\n
    * > <b>Parâmetro opcional</b>\n
    * > <b>Tipo:</b>Numérico\n
    * > <b>Tamanho:</b> 14 \n
    *
    * \param CPF
    * CPF do Transportador.\n
    * > <b>TAG:</b> X05\n
    * > <b>Parâmetro opcional</b>\n
    * > <b>Tipo:</b> Numérico\n
    * > <b>Tamanho:</b> 11\n
    *
    * \param xNome
    * Razão Social ou nome.\n
    * > <b>TAG:</b> X06\n
    * > <b>Parametro opcional</b>\n
    * > <b>Tipo:</b> Alfanumérico\n
    * > <b>Tamanho:</b> 2-60\n
    *
    * \param IE
    * Inscrição Estadual do Transportador.\n
    * > <b>TAG:</b> X07\n
    * > <b>Parâmetro opcional</b>\n
    * > <b>Tipo:</b> Alfanumérico\n
    * > <b>Tamanho:</b> 2-14\n
    *
    * \param xEnder
    * Endereço Completo.\n
    * > <b>TAG:</b> X08\n
    * > <b>Parâmetro opcional</b>\n
    * > <b>Tipo:</b> Alfanumérico\n
    * > <b>Tamanho:</b> 1-60\n
    *
    * \param xMun
    * Nome do município. \n
    * > <b>TAG:</b> X09\n
    * > <b>Parâmetro opcional</b>\n
    * > <b>Tipo:</b> Alfanumérico\n
    * > <b>Tamanho:</b> 1-60\n
    *
    * \param UF
    * Sigla da UF. \n
    * > <b>TAG:</b> X10\n
    * > <b>Parâmetro opcional</b>\n
    * > <b>Tipo:</b> Alfanumérico\n
    * > <b>Tamanho:</b> 2\n
    *
    * \return
    * O retorno em caso de sucesso será(0). \n
    * Possiveis erros\n
    *
    * | DESCRIÇÃO                          | VALOR|
    * |------------------------------------|------|
    * | NFCE_MODALIDADE_FRETE_INVALIDA     | -650 |
    * | NFCE_CNPJ_TRANSPORTADOR_INVALIDO   | -651 |
    * | NFCE_CPF_TRANSPORTADOR_INVALIDO    | -652 |
    * | NFCE_xNOME_TRANSPORTADOR_INVALIDO  | -653 |
    * | NFCE_IE_TRANSPORTADOR_INVALIDO     | -654 |
    * | NFCE_XENDER_TRANSPORTADOR_INVALIDO | -655 |
    * | NFCE_xMUN_TRANSPORTADOR_INVALIDO   | -656 |
    * | NFCE_UF_TRANSPORTADOR_INVALIDO     | -657 |
    */

    ///@cond
    E1_NFCESHARED_EXPORT STDCALL
    ///@endcond
    int InformaTransporte(const char *file_path, int modFrete, const char *CNPJ, const char *CPF, const char *xNome,
                          const char *IE, const char *xEnder, const char *xMun, const char *UF);

    /*! \ingroup g50
    *
    * Função utilizada para informar Volumes quando existir trasnporte para compor informações pdo cupom.\n
    *
    * \param file_path
    * Caminho absoluto onde o arquivo json será gerado.\n
    * EX:\n
    * > C:/NFCE/venda_001.json
    *
    * \param qVol
    * Quantidade de volumes transportados.\n
    * > <b>TAG:</b> X27\n
    * > <b>Parâmetro opcional</b>\n
    * > <b>Tipo:</b> Numérico\n
    * > <b>Tamanho:</b> 1-15\n
    *
    * \param esp
    * Espécie dos volumes transportados.\n
    * > <b>TAG:</b> X28\n
    * > <b>Parâmetro opcional</b>\n
    * > <b>Tipo:</b> Alfanumérico\n
    * > <b>Tamanho:</b> 1-60\n
    *
    * \param marca
    * Descrição da Natureza da Operação.\n
    * > <b>TAG:</b> X29\n
    * > <b>Parâmetro opcional</b>\n
    * > <b>Tipo:</b> Alfanumérico\n
    * > <b>Tamanho:</b> 1-60\n
    *
    * \param nVol
    * Numeração dos volumes transportados.\n
    * > <b>TAG:</b> X30\n
    * > <b>Parâmetro opcional</b>\n
    * > <b>Tipo:</b> Alfanumérico\n
    * > <b>Tamanho:</b> 1-60\n
    *
    * \param pesoL
    * Peso Líquido (em kg).\n
    * > <b>TAG:</b> X31\n
    * > <b>Parâmetro opcional</b>\n
    * > <b>Tipo:</b> Numérico\n
    * > <b>Tamanho:</b> 12v3\n
    *
    * \param pesoB
    * Peso Bruto (em kg).\n
    * > <b>TAG:</b> X32\n
    * > <b>Parâmetro opcional</b>\n
    * > <b>Tipo:</b> Numérico\n
    * > <b>Tamanho:</b> 12v3\n
    *
    *\return
    * O retorno em caso de sucesso será o index do volume criado. Desse modo o valor deve ser > 1. \n
    * Possiveis erros\n
    *
    * | DESCRIÇÃO                                 | VALOR|
    * |-------------------------------------------|------|
    * | NFCE_VOLUMES_X27_QVOL_INVALIDO            | -770 |
    * | NFCE_VOLUMES_X28_ESP_INVALIDO             | -771 |
    * | NFCE_VOLUMES_X29_MARCA_INVALIDO           | -772 |
    * | NFCE_VOLUMES_X30_NVOL_INVALIDO            | -773 |
    * | NFCE_VOLUMES_X31_PESOL_INVALIDO           | -774 |
    * | NFCE_VOLUMES_X32_PESOB_INVALIDO           | -775 |
    * | NFCE_VOLUMES_NAO_E_POSSIVEL_INSERIR       | -776 |
    * | NFCE_VOLUMES_CHAVE_TRANSPORTE_NAO_EXISTE  | -777 |
    */

    ///@cond
    E1_NFCESHARED_EXPORT STDCALL
    ///@endcond
    int InformaVolumes(const char *file_path, const char *qVol, const char *especie, const char *marca,
                       const char *nVol, const char *pesoL, const char *pesoB);


    /*! \ingroup g50
    *
    * Função uitlizada para informar Lacres quando existir Volumes para compor informações para emissão de cupom.\n
    *
    * \param file_path
    * Caminho absoluto onde o arquivo json será gerado.\n
    * EX:\n
    * > C:/NFCE/venda_001.json
    *
    * \param nLacre
    * Número dos Lacres.\n
    * > <b>TAG:</b> X34\n
    * > <b>Parâmetro obrigatório</b>\n
    * > <b>Tipo:</b> Alfanumérico\n
    * > <b>Tamanho:</b> 1-60\n
    *
    * \param indexVolume -  Recebe o valor da posição do volume que será inserido o lacre.
    *
    * \return
    * O retorno em caso de sucesso será(0). \n
    * Possiveis erros\n
    *
    * | DESCRIÇÃO                                 | VALOR|
    * |-------------------------------------------|------|
    * | NFCE_LACRES_X34_NLACRE_INVALIDO           | -780 |
    * | NFCE_LACRES_CHAVE_VOLUMES_NAO_EXISTE      | -781 |
    * | NFCE_LACRES_INDEX_DO_VOLUME_NAO_ENCONTRADO| -782 |
    */

    ///@cond
    E1_NFCESHARED_EXPORT STDCALL
    ///@endcond
    int InformaLacres(const char *file_path, const char *nLacre, int indexVolume);

    /*! \ingroup g50
    *
    * Função utilizada para informar Pagamento na composição das informações para emissão do cupom.\n
    *
    * \param file_path
    * Caminho absoluto onde o arquivo json será gerado.\n
    * EX:\n
    * > C:/NFCE/venda_001.json
    *
    * \param indPag
    * Indicador da Forma de Pagamento.\n
    * > <b>TAG:</b> YA01b\n
    * > <b>Parâmetro obrigatório</b>\n
    * > <b>Tipo:</b> Numérico\n
    * > <b>Tamanho:</b> 1 \n
    *
    * \param tPag
    * Valor do Pagamento.\n
    * > <b>TAG:</b> YA02\n
    * > <b>Parâmetro obrigatório</b>\n
    * > <b>Tipo:</b> Numérico\n
    * > <b>Tamanho:</b> 2 \n
    *
    * \param vPag
    * Valor do Pagamento.\n
    * > <b>TAG:</b> YA03\n
    * > <b>Parametro obrigatório</b>\n
    * > <b>Tipo:</b> Numérico\n
    * > <b>Tamanho:</b> 13v2\n
    *
    * \param tpIntegra
    * Tipo de Integração para pagamento.\n
    * > <b>TAG:</b> YA04a\n
    * > <b>Parâmetro opcional</b>\n
    * > <b>Tipo:</b> Numérico\n
    * > <b>Tamanho:</b> 1\n
    *
    * \param CNPJ
    * CNPJ da instituição de pagamento.\n
    * > <b>TAG:</b> YA05\n
    * > <b>Parâmetro opcional</b>\n
    * > <b>Tipo:</b> Alfanumérico\n
    * > <b>Tamanho:</b>14\n
    *
    * \param tBand
    * Bandeira da operadora de cartão de crédito e/ou débito.\n
    * > <b>TAG:</b> YA06\n
    * > <b>Parâmetro opcional</b>\n
    * > <b>Tipo:</b> Numérico\n
    * > <b>Tamanho:</b> 2\n
    *
    * \param cAut
    * Número de autorização da operação cartão de crédito e/ou débito. \n
    * > <b>TAG:</b> YA07\n
    * > <b>Parâmetro opcional</b>\n
    * > <b>Tipo:</b> Alfanumérico\n
    * > <b>Tamanho:</b> 1-20\n
    *
    * \param vTroco
    * Valor do troco. \n
    * > <b>TAG:</b> YA09\n
    * > <b>Parâmetro opcional</b>\n
    * > <b>Tipo:</b> Numérico\n
    * > <b>Tamanho:</b> 13v2\n
    *
    * \return
    * O retorno em caso de sucesso será(0). \n
    * Possiveis erros\n
    *
    * | DESCRIÇÃO                               | VALOR|
    * |-----------------------------------------|------|
    * | NFCE_FORMA_PAGAMENTO_INVALIDA           | -660 |
    * | NFCE_VALOR_PAGAMENTO_INVALIDO           | -661 |
    * | NFCE_BANDEIRA_CARTAO_INVALIDA           | -662 |
    * | NFCE_CODIGO_AUTORIZACAO_INVALIDO        | -663 |
    * | NFCE_CNPJ_CREDENCIADORA_INVALIDO        | -664 |
    * | NFCE_INDICADOR_FORMA_PAGAMENTO_INVALIDO | -665 |
    * | NFCE_TIPO_INTEGRACAO_INVALIDA           | -666 |
    * | NFCE_VALOR_TROCO_INVALIDO               | -667 |
    */

    ///@cond
    E1_NFCESHARED_EXPORT STDCALL
    ///@endcond
    int InformaPagamento(const char *file_path, int indPag, int tPag, const char *vPag, int tpIntegra, const char *CNPJ, int tBand, const char *cAut, const char* vTroco);
//
//    ///@cond
//    E1_NFCESHARED_EXPORT STDCALL
//    ///@endcond
//    int InformaInformacoesAdicionais(const char *file_path, const char *infAdFisco, const char *infCpl, const char *xCampoObsCont, const char *xTextoObsCont, const char *xCampoObsFisco, const char *xTextoObsFisco, const char *nProc, int indProc);


    /*! \ingroup g50
    *
    * Função utilizada para informar Produto na composição das informações para emissão do cupom NFCe.\n
    *
    * \param file_path
    * Caminho absoluto onde o arquivo json será gerado.\n
    * EX:\n
    * > C:/NFCE/venda_001.json
    *
    * \param cProd
    * Código do produto ou serviço.\n
    * > <b>TAG:</b> I02\n
    * > <b>Parâmetro obrigatório</b>\n
    * > <b>Tipo:</b> Alfanumérico\n
    * > <b>Tamanho:</b> 1-60 \n
    *
    * \param cEAN
    * GTIN (Global Trade Item Number) do produto, antigo código EAN ou código de barras.\n
    * > <b>TAG:</b> I03\n
    * > <b>Parâmetro obrigatório</b>\n
    * > <b>Tipo:</b> Alfanumérico\n
    * > <b>Tamanho:</b> 0,8,12, 13, 14\n
    *
    * \param xProd
    * Descrição do produto ou serviço.\n
    * > <b>TAG:</b> I04\n
    * > <b>Parâmetro obrigatório</b>\n
    * > <b>Tipo:</b> Alfanumérico\n
    * > <b>Tamanho:</b> 1-120\n
    *
    * \param NCM
    * Código NCM com 8 dígitos.\n
    * > <b>TAG:</b> I05\n
    * > <b>Parâmetro obrigatório</b>\n
    * > <b>Tipo:</b> Numérico\n
    * > <b>Tamanho:</b> 2, 8\n
    *
    * \param NVE
    * Codificação NVE - Nomenclatura de Valor Aduaneiro e Estatística..\n
    * > <b>TAG:</b> I05a\n
    * > <b>Parâmetro opcional</b>\n
    * > <b>Tipo:</b> Alfanumérico\n
    * > <b>Tamanho:</b> 6\n
    *
    * \param CEST
    * Código CEST.\n
    * > <b>TAG:</b> I05c\n
    * > <b>Parâmetro obrigatório</b>\n
    * > <b>Tipo:</b> Numérico\n
    * > <b>Tamanho:</b> 7\n
    *
    * \param indEscala
    * Indicador de Escala Relevante\n
    * > <b>TAG:</b> I05d\n
    * > <b>Parâmetro obirgatório</b>\n
    * > <b>Tipo:</b> Alfanumérico\n
    * > <b>Tamanho:</b> 1\n
    *
    * \param CNPJFab
    * CNPJ do Fabricante da Mercadoria \n
    * > <b>TAG:</b> I05e\n
    * > <b>Parâmetro opcional</b>\n
    * > <b>Tipo:</b> Numérico\n
    * > <b>Tamanho:</b> 14\n
    *
    * \param cBenef
    * Código de Benefício Fiscal na UF aplicado ao item.\n
    * > <b>TAG:</b> I05f\n
    * > <b>Parâmetro opcional</b>\n
    * > <b>Tipo:</b> Alfanumérico\n
    * > <b>Tamanho:</b> 8,10\n
    *
    * \param EXTIPI
    * EX_TIPI \n
    * > <b>TAG:</b> I06\n
    * > <b>Parâmetro opcional</b>\n
    * > <b>Tipo:</b> Numérico\n
    * > <b>Tamanho:</b> 2-3\n
    *
    * \param CFOP
    * Código Fiscal de Operações e Prestações \n
    * > <b>TAG:</b> I08\n
    * > <b>Parâmetro obrigatório</b>\n
    * > <b>Tipo:</b> Numérico\n
    * > <b>Tamanho:</b> 4\n
    *
    * \param uCom
    * Unidade Comercial\n
    * > <b>TAG:</b> I09\n
    * > <b>Parâmetro obrigatório</b>\n
    * > <b>Tipo:</b> Alfanumérico\n
    * > <b>Tamanho:</b> 1-6\n
    *
    * \param qCom
    * Quantidade Comercial \n
    * > <b>TAG:</b> I10\n
    * > <b>Parâmetro obrigatório</b>\n
    * > <b>Tipo:</b> Numérico\n
    * > <b>Tamanho:</b> 11v0-4 \n
    *
    * \param vUnCom
    * Valor Unitário de Comercialização\n
    * > <b>TAG:</b> I10a\n
    * > <b>Parâmetro obrigatório</b>\n
    * > <b>Tipo:</b> Numérico\n
    * > <b>Tamanho:</b> 11v0-10\n
    *
    * \param vProd
    * Valor Total Bruto dos Produtos ou Serviços. \n
    * > <b>TAG:</b> I11\n
    * > <b>Parâmetro opcional</b>\n
    * > <b>Tipo:</b> Numérico\n
    * > <b>Tamanho:</b> 13v2\n
    *
    * \param cEANTrib
    * GTIN (Global Trade Item Number) da unidade tributável, antigo código EAN ou código de barras.\n
    * > <b>TAG:</b> I12\n
    * > <b>Parâmetro obrigatório</b>\n
    * > <b>Tipo:</b> Alfanumérico\n
    * > <b>Tamanho:</b> 0,8,12, 13, 14\n
    *
    * \param uTrib
    * Unidade Tributável. \n
    * > <b>TAG:</b> I13\n
    * > <b>ParÂmetro obrigatório</b>\n
    * > <b>Tipo:</b> Alfanumérico\n
    * > <b>Tamanho:</b> 1-6\n
    *
    * \param qTrib
    * Quantidade Tributável \n
    * > <b>TAG:</b> I14\n
    * > <b>Parâmetro obrigatório</b>\n
    * > <b>Tipo:</b> Numérico\n
    * > <b>Tamanho:</b> 11v0-4\n
    *
    * \param vUnTrib
    * Valor Unitário de tributação.\n
    * > <b>TAG:</b> I14a\n
    * > <b>Parâmetro obrigatório</b>\n
    * > <b>Tipo:</b> Numérico\n
    * > <b>Tamanho:</b> 11v0-10\n
    *
    * \param vFrete
    * Valor Total do Frete\n
    * > <b>TAG:</b> I15\n
    * > <b>Parâmetro opcional</b>\n
    * > <b>Tipo:</b> Numérico\n
    * > <b>Tamanho:</b>13v2\n
    *
    * \param vSeg
    * Valor Total do Seguro.\n
    * > <b>TAG:</b> I16\n
    * > <b>Parâmetro opcional</b>\n
    * > <b>Tipo:</b> Numérico\n
    * > <b>Tamanho:</b> 13v2\n
    *
    * \param vDesc
    * Valor do Desconto. \n
    * > <b>TAG:</b> I17\n
    * > <b>Parâmetro opcional</b>\n
    * > <b>Tipo:</b> Numérico\n
    * > <b>Tamanho:</b> 13v2\n
    *
    * \param vOutro
    * Outras despesas acessórias. \n
    * > <b>TAG:</b> I17a\n
    * > <b>Parâmetro opcional</b>\n
    * > <b>Tipo:</b> Numérico\n
    * > <b>Tamanho:</b> 13v2\n
    *
    * \param indTot
    * Indica se valor do Item (vProd) entra no valor total da NF-e (vProd) \n
    * > <b>TAG:</b> I17b\n
    * > <b>Parâmetro opcional</b>\n
    * > <b>Tipo:</b> Numérico\n
    * > <b>Tamanho:</b> 1\n
    *
    * \return
    * O retorno em caso de sucesso será o index do produto criado. Desse modo o valor deve ser > 1. \n
    * Esse Index pode ser usado para identificar o produto no informe de impostos.\n
    *
    * Possiveis erros\n
    *
    * | DESCRIÇÃO                                  | VALOR|
    * |--------------------------------------------|------|
    * | NFCE_CODIGO_PRODUTO_INVALIDO               | -670 |
    * | NFCE_CODIGO_EAN_INVALIDO                   | -671 |
    * | NFCE_DESCRICAO_PRODUTO_INVALIDA            | -672 |
    * | NFCE_NCM_PRODUTO_INVALIDO                  | -673 |
    * | NFCE_NVE_INVALIDO                          | -674 |
    * | NFCE_CEST_INVALIDO                         | -675 |
    * | NFCE_INDESCALA_INVALIDO                    | -676 |
    * | NFCE_CNPJ_FABRICANTE_INVALIDO              | -677 |
    * | NFCE_CBENEF_INVALIDO                       | -678 |
    * | NFCE_EXTIPI_PRODUTO_INVALIDO               | -679 |
    * | NFCE_CFOP_PRODUTO_INVALIDO                 | -680 |
    * | NFCE_UNIDADE_COMERCIAL_PRODUTO_INVALIDA    | -681 |
    * | NFCE_QUANTIDADE_COMERCIAL_PRODUTO_INVALIDA | -682 |
    * | NFCE_VALOR_UNI_COMERCIAL_PRODUTO_INVALIDO  | -683 |
    * | NFCE_VALOR_PRODUTO_INVALIDO                | -684 |
    * | NFCE_GTIN_PRODUTO_INVALIDO                 | -685 |
    * | NFCE_UNIDADE_TRIBUTAVEL_INVALIDA           | -686 |
    * | NFCE_QUANTIDADE_TRIBUTAVEL_INVALIDA        | -687 |
    * | NFCE_VALOR_UNI_TRIBUTACAO_INVALIDO         | -688 |
    * | NFCE_VALOR_FRETE_INVALIDO                  | -689 |
    * | NFCE_VALOR_SEGURO_INVALIDO                 | -690 |
    * | NFCE_VALOR_DESCONTO_INVALIDO               | -691 |
    * | NFCE_VALOR_OUTRO_INVALIDO                  | -692 |
    * | NFCE_INDICADOR_TOTAL_INVALIDO              | -693 |
    *
    */

    ///@cond
    E1_NFCESHARED_EXPORT STDCALL
    ///@endcond
    int InformaProduto(const char *file_path, const char *cProd, const char *cEAN, const char *xProd, const char *NCM, const char *NVE,
                       const char *CEST, const char *indEscala, const char *CNPJFab, const char *cBenef, const char* EXTIPI, const char *CFOP,
                       const char *uCom, const char *qCom, const char *vUnCom, const char *vProd, const char *cEANTrib, const char *uTrib,
                       const char *qTrib, const char *vUnTrib, const char *vFrete, const char *vSeg, const char *vDesc, const char *vOutro, int indTot);

//    ///@cond
//    E1_NFCESHARED_EXPORT STDCALL
//    ///@endcond
//    int InformaImposto(const char *file_path, int nItem, const char *vTotTrib);

    /*! \ingroup g50
    *
    * Função utilizada para informar PISALIQ na composição das informações para emissão da NFCe.\n
    *
    * \param file_path
    * Caminho absoluto onde o arquivo json será gerado.\n
    * EX:\n
    * > C:/NFCE/venda_001.json
    *
    * \param nItem
    *  Informação do index do produto a ser informado\n
    * > <b>Parâmetro obrigatório</b>\n
    * > <b>Tipo:</b> Numérico\n
    *
    * \param CST
    * Código de Situação Tributária do PIS.\n
    * > <b>TAG:</b> Q06\n
    * > <b>Parâmetro obrigatório</b>\n
    * > <b>Tipo:</b> Numérico\n
    * > <b>Tamanho:</b> 2\n
    *
    * \param vBC
    * Valor da Base de Cálculo do PIS.\n
    * > <b>TAG:</b> Q07\n
    * > <b>Parâmetro obrigatório</b>\n
    * > <b>Tipo:</b> Numérico\n
    * > <b>Tamanho:</b> 13v2\n
    *
    * \param pPIS
    * Alíquota do PIS (em percentual).\n
    * > <b>TAG:</b> Q08\n
    * > <b>Parâmetro obrigatório</b>\n
    * > <b>Tipo:</b> Numérico\n
    * > <b>Tamanho:</b> 3v2-4\n
    *
    * \param vPIS
    * Valor do PIS.\n
    * > <b>TAG:</b> Q09\n
    * > <b>Parâmetro obrigatório</b>\n
    * > <b>Tipo:</b> Numérico\n
    * > <b>Tamanho:</b> 13v2\n
    *
    * \return
    * O retorno em caso de sucesso será(0). \n
    * Possiveis erros consulte \ref NFCE_Erro_Impostos
    */

    ///@cond
    E1_NFCESHARED_EXPORT STDCALL
    ///@endcond
    int InformaPISAliq(const char *file_path, int nItem, const char *CST, const char *vBC, const char *pPIS, const char *vPIS);

    /*! \ingroup g50
    *
    * Função utilizada para informar PISQtde para composição das informações na emissão do cupom.\n
    *
    * \param file_path
    * Caminho absoluto onde o arquivo json será gerado.\n
    * EX:\n
    * > C:/NFCE/venda_001.json
    *
    * \param nItem
    *  Informação do index do produto a ser informado\n
    * > <b>Parâmetro obrigatório</b>\n
    * > <b>Tipo:</b> Numérico\n
    *
    * \param CST
    * Código de Situação Tributária do PIS.\n
    * > <b>TAG:</b> Q06\n
    * > <b>Parâmetro obrigatório</b>\n
    * > <b>Tipo:</b> Numérico\n
    * > <b>Tamanho:</b> 2\n
    *
    * \param qBCProd
    * Quantidade Vendida.\n
    * > <b>TAG:</b> Q10\n
    * > <b>Parâmetro obrigatório</b>\n
    * > <b>Tipo:</b> Numérico\n
    * > <b>Tamanho:</b> 12v0-4\n
    *
    * \param vAliqProd
    * Alíquota do PIS (em reais).\n
    * > <b>TAG:</b> Q11\n
    * > <b>Parâmetro obrigatório</b>\n
    * > <b>Tipo:</b> Numérico\n
    * > <b>Tamanho:</b> 11v0-4\n
    *
    * \param vPIS
    * Valor do PIS.\n
    * > <b>TAG:</b> Q09\n
    * > <b>Parâmetro obrigatório</b>\n
    * > <b>Tipo:</b> Numérico\n
    * > <b>Tamanho:</b> 13v2\n
    *
    * \return
    * O retorno em caso de sucesso será(0). \n
    * Possiveis erros consulte \ref NFCE_Erro_Impostos
    */

    ///@cond
    E1_NFCESHARED_EXPORT STDCALL
    ///@endcond
    int InformaPISQtde(const char *file_path, int nItem, const char *CST, const char *qBCProd, const char *vAliqProd, const char *vPIS);

    /*! \ingroup g50
    *
    * Função utilizada para informar PISNT na composição das informações para emissão.\n
    *
    * \param file_path
    * Caminho absoluto onde o arquivo json será gerado.\n
    * EX:\n
    * > C:/NFCE/venda_001.json
    *
    * \param nItem
    *  Informação do index do produto a ser informado\n
    * > <b>Parâmetro obrigatório</b>\n
    * > <b>Tipo:</b> Numérico\n
    *
    * \param CST
    * Código de Situação Tributária do PIS.\n
    * > <b>TAG:</b> Q06\n
    * > <b>Parâmetro obrigatório</b>\n
    * > <b>Tipo:</b> Numérico\n
    * > <b>Tamanho:</b> 2\n
    *
    * \return
    * O retorno em caso de sucesso será(0). \n
    * Possiveis erros consulte \ref NFCE_Erro_Impostos
    */

    ///@cond
    E1_NFCESHARED_EXPORT STDCALL
    ///@endcond
    int InformaPISNT(const char *file_path, int nItem, const char *CST);

    /*! \ingroup g50
    *
    * Função utilizada para informar PISOUTR na composição das informações para emissão.\n
    *
    * \param file_path
    * Caminho absoluto onde o arquivo json será gerado.\n
    * EX:\n
    * > C:/NFCE/venda_001.json
    *
    * \param nItem
    *  Informação do index do produto a ser informado\n
    * > <b>Parâmetro obrigatório</b>\n
    * > <b>Tipo:</b> Numérico\n
    *
    * \param grupo
    * Informar o grupo a ser criado\n
    * > <b>Parâmetro obrigatório</b>\n
    * > <b>Tipo:</b> Numérico\n
    *
    * \param CST
    * Código de Situação Tributária do PIS.\n
    * > <b>TAG:</b> Q06\n
    * > <b>Parâmetro obrigatório</b>\n
    * > <b>Tipo:</b> Numérico\n
    * > <b>Tamanho:</b> 2\n
    *
    * \param vBC_qBCProd
    * Quantidade Vendida.\n
    * > <b>TAG:</b> Q10\n
    * > <b>Parâmetro obrigatório</b>\n
    * > <b>Tipo:</b> Numérico\n
    * > <b>Tamanho:</b> 12v0-4\n
    *
    * \param pPIS_vAliqProd
    * Alíquota do PIS (em reais).\n
    * > <b>TAG:</b> Q11\n
    * > <b>Parâmetro obrigatório</b>\n
    * > <b>Tipo:</b> Numérico\n
    * > <b>Tamanho:</b> 11v0-4\n
    *
    * \param vPIS
    * Valor do PIS.\n
    * > <b>TAG:</b> R06\n
    * > <b>Parâmetro obrigatório</b>\n
    * > <b>Tipo:</b> Numérico\n
    * > <b>Tamanho:</b> 13v2\n
    *
    * \return
    * O retorno em caso de sucesso será(0). \n
    * Possiveis erros consulte \ref NFCE_Erro_Impostos
    */

    ///@cond
    E1_NFCESHARED_EXPORT STDCALL
    ///@endcond
    int InformaPISOutr(const char *file_path, int nItem, int grupo, const char *CST, const char *vBC_qBCProd, const char *pPIS_vAliqProd,
                                                     const char *vPIS);

    /*! \ingroup g50
    *
    * Função utilizada para informar CONFINSALIQ na composição das informações para emissão.\n
    *
    * \param file_path
    * Caminho absoluto onde o arquivo json será gerado.\n
    * EX:\n
    * > C:/NFCE/venda_001.json
    *
    * \param nItem
    *  Informação do index do produto a ser informado\n
    * > <b>Parâmetro obrigatório</b>\n
    * > <b>Tipo:</b> Numérico\n
    *
    * \param CST
    * Código de Situação Tributária do PIS.\n
    * > <b>TAG:</b> S06\n
    * > <b>Parâmetro obrigatório</b>\n
    * > <b>Tipo:</b> Numérico\n
    * > <b>Tamanho:</b> 2\n
    *
    * \param vBC
    * Valor da Base de Cálculo da COFINS.\n
    * > <b>TAG:</b> S07\n
    * > <b>Parâmetro obrigatório</b>\n
    * > <b>Tipo:</b> Numérico\n
    * > <b>Tamanho:</b> 13v2\n
    *
    * \param pCOFINS
    * Alíquota da COFINS (em percentual).\n
    * > <b>TAG:</b> S08\n
    * > <b>Parâmetro obrigatório</b>\n
    * > <b>Tipo:</b> Numérico\n
    * > <b>Tamanho:</b> 3v2-4\n
    *
    * \param vCOFINS
    * Valor da COFINS.\n
    * > <b>TAG:</b> S11\n
    * > <b>Parâmetro obrigatório</b>\n
    * > <b>Tipo:</b> Numérico\n
    * > <b>Tamanho:</b> 13v2\n
    *
    * \return
    * O retorno em caso de sucesso será(0). \n
    * Possiveis erros consulte \ref NFCE_Erro_Impostos
    */

    ///@cond
    E1_NFCESHARED_EXPORT STDCALL
    ///@endcond
    int InformaCofinsAliq(const char *file_path, int nItem, const char *CST, const char *vBC, const char *pCOFINS, const char *vCOFINS);

    /*! \ingroup g50
    *
    * Função utilizada para informar CONFINSQTDE na composição das informações para emissão.\n
    *
    * \param file_path
    * Caminho absoluto onde o arquivo json será gerado.\n
    * EX:\n
    * > C:/NFCE/venda_001.json
    *
    * \param nItem
    *  Informação do index do produto a ser informado\n
    * > <b>Parâmetro obrigatório</b>\n
    * > <b>Tipo:</b> Numérico\n
    *
    * \param CST
    * Código de Situação Tributária do PIS.\n
    * > <b>TAG:</b> S06\n
    * > <b>Parâmetro obrigatório</b>\n
    * > <b>Tipo:</b> Numérico\n
    * > <b>Tamanho:</b> 2\n
    *
    * \param qBCProd
    * Quantidade Vendida.\n
    * > <b>TAG:</b> S09\n
    * > <b>Parâmetro obrigatório</b>\n
    * > <b>Tipo:</b> Numérico\n
    * > <b>Tamanho:</b> 12v0-4\n
    *
    * \param vAliqProd
    * Alíquota da COFINS (em reais).\n
    * > <b>TAG:</b> S10\n
    * > <b>Parâmetro obrigatório</b>\n
    * > <b>Tipo:</b> Numérico\n
    * > <b>Tamanho:</b> 11v0-4\n
    *
    * \param vCOFINS
    * Valor da COFINS.\n
    * > <b>TAG:</b> S11\n
    * > <b>Parâmetro obrigatório</b>\n
    * > <b>Tipo:</b> Numérico\n
    * > <b>Tamanho:</b> 13v2\n
    *
    * \return
    * O retorno em caso de sucesso será(0). \n
    * Possiveis erros consulte \ref NFCE_Erro_Impostos
    */


    ///@cond
    E1_NFCESHARED_EXPORT STDCALL
    ///@endcond
    int InformaCofinsQtde(const char *file_path, int nItem, const char *CST, const char *qBCProd, const char *vAliqProd, const char *vCOFINS);

    /*! \ingroup g50
    *
    * Função utilizada para informar CONFINSNT na composição das informações para emissão.\n
    *
    * \param file_path
    * Caminho absoluto onde o arquivo json será gerado.\n
    * EX:\n
    * > C:/NFCE/venda_001.json
    *
    * \param nItem
    *  Informação do index do produto a ser informado\n
    * > <b>Parâmetro obrigatório</b>\n
    * > <b>Tipo:</b> Numérico\n
    *
    * \param CST
    * Código de Situação Tributária do PIS.\n
    * > <b>TAG:</b> S06\n
    * > <b>Parâmetro obrigatório</b>\n
    * > <b>Tipo:</b> Numérico\n
    * > <b>Tamanho:</b> 2\n
    *
    * \return
    * O retorno em caso de sucesso será(0). \n
    * Possiveis erros consulte \ref NFCE_Erro_Impostos
    */

    ///@cond
    E1_NFCESHARED_EXPORT STDCALL
    ///@endcond
    int InformaCofinsNT(const char *file_path, int nItem, const char *CST);

    /*! \ingroup g50
     * Analisar esta função refernte aos dados.
    *
    *  Função utilizada para informar CofinsOutr na composição das informações para emissão.\n
    *
    * \param file_path
    * Caminho absoluto onde o arquivo json será gerado.\n
    * EX:\n
    * > C:/NFCE/venda_001.json
    *
    * \param nItem
    *  Informação do index do produto a ser informado\n
    * > <b>Parâmetro obrigatório</b>\n
    * > <b>Tipo:</b> Numérico\n
    *
    * \param grupo
    * Informar o grupo a ser criado\n
    * > <b>Parâmetro obrigatório</b>\n
    * > <b>Tipo:</b> Numérico\n
    *
    * \param CST
    * Código de Situação Tributária do PIS.\n
    * > <b>TAG:</b> Q06\n
    * > <b>Parâmetro obrigatório</b>\n
    * > <b>Tipo:</b> Numérico\n
    * > <b>Tamanho:</b> 2\n
    *
    * \param vBC_qBCProd
    * Quantidade Vendida.\n
    * > <b>TAG:</b> Q10\n
    * > <b>Parâmetro obrigatório</b>\n
    * > <b>Tipo:</b> Numérico\n
    * > <b>Tamanho:</b> 12v0-4\n
    *
    * \param pCOFINS_vAliqProd,
    * Alíquota do PIS (em reais).\n
    * > <b>TAG:</b> Q11\n
    * > <b>Parâmetro obrigatório</b>\n
    * > <b>Tipo:</b> Numérico\n
    * > <b>Tamanho:</b> 11v0-4\n
    *
    * \param vCOFINS
    * Valor da COFINS.\n
    * > <b>TAG:</b> S11\n
    * > <b>Parâmetro obrigatório</b>\n
    * > <b>Tipo:</b> Numérico\n
    * > <b>Tamanho:</b> 13v2\n
    *
    * \return
    * O retorno em caso de sucesso será(0). \n
    * Possiveis erros consulte \ref NFCE_Erro_Impostos
    */

    ///@cond
    E1_NFCESHARED_EXPORT STDCALL
    ///@endcond
    int InformaCofinsOutr(const char *file_path, int nItem, int grupo, const char *CST, const char *vBC_qBCProd, const char *pCOFINS_vAliqProd, const char *vCOFINS);

//    ///@cond
//    E1_NFCESHARED_EXPORT STDCALL
//    ///@endcond
//    int InformaPISST(const char *file_path, int nItem, const char *vBC_qBCProd, const char *pPIS_vAliqProd, const char *vPIS, int grupo);

//    ///@cond
//    E1_NFCESHARED_EXPORT STDCALL
//    ///@endcond
//    int InformaCOFINSST(const char *file_path, int nItem, const char *vBC_qBCProd, const char *pCOFINS_vAliqProd, const char *vCOFINS, int grupo);
//
//    ///@cond
//    E1_NFCESHARED_EXPORT STDCALL
//    ///@endcond
//    int InformaISSQN(const char *file_path, int nItem, const char *vBC, const char *vAliq, const char *vISSQN, const char *cMunFG,
//                                                   const char *cListServ, const char *vDeducao, const char *vOutro, const char *vDescIncond, const char *vDescCond,
//                                                   const char *vISSRet, int indISS, const char *cServico, const char *cMun, const char *cPais, const char *nProcesso,
//                                                   int indIncentivo);
//
//    ///@cond
//    E1_NFCESHARED_EXPORT STDCALL
//    ///@endcond
//    int InformaIPI(const char *file_path, int nItem, const char *clEnq, const char *CNPJProd, const char *cSelo, const char *qSelo, const char *cEnq, const char *CST,
//                                                 const char *vBC, const char *pIPI, const char *qUnid, const char *vUnid, const char *vIPI, const char *IPINT_CST);

//    ///@cond
//    E1_NFCESHARED_EXPORT STDCALL
//    ///@endcond
//    int InformaImpostoImportacao(const char *file_path, int nItem, const char *vBC, const char *vDespAdu, const char *vII, const char *vIOF);

    /*! \ingroup g50
    *
    *  Função utilizada para informar ICMS00 na composição das informações para emissão\n
    *
    * \param file_path
    * Caminho absoluto onde o arquivo json será gerado.\n
    * EX:\n
    * > C:/NFCE/venda_001.json
    *
    * \param nItem
    *  Informação do index do produto a ser informado\n
    * > <b>Parâmetro obrigatório</b>\n
    * > <b>Tipo:</b> Numérico\n
    *
    * \param orig
    * Origem da mercadoria.\n
    * > <b>TAG:</b> N11\n
    * > <b>Parâmetro obrigatório</b>\n
    * > <b>Tipo:</b> Numérico\n
    * > <b>Tamanho:</b> 1\n
    *
    * \param CST
    * Tributação do ICMS = 00.\n
    * > <b>TAG:</b> N12\n
    * > <b>Parâmetro obrigatório</b>\n
    * > <b>Tipo:</b> Numérico\n
    * > <b>Tamanho:</b> 2\n
    *
    * \param modBC
    * Modalidade de determinação da BC do ICMS.\n
    * > <b>TAG:</b> N13\n
    * > <b>Parâmetro obrigatório</b>\n
    * > <b>Tipo:</b> Numérico\n
    * > <b>Tamanho:</b> 1 \n
    *
    * \param vBC
    * Valor da BC do ICMS\n
    * > <b>TAG:</b> N15\n
    * > <b>Parâmetro obrigatório</b>\n
    * > <b>Tipo:</b> Numérico\n
    * > <b>Tamanho:</b> 13v2\n
    *
    * \param pICMS
    * Alíquota do imposto. \n
    * > <b>TAG:</b> N16\n
    * > <b>Parâmetro obrigatório</b>\n
    * > <b>Tipo:</b> Numérico\n
    * > <b>Tamanho:</b> 3v2-4\n
    *
    * \param vICMS
    * Valor do ICMS. \n
    * > <b>TAG:</b> N17\n
    * > <b>Parâmetro opcional</b>\n
    * > <b>Tipo:</b> Numérico\n
    * > <b>Tamanho:</b> 13v2\n
    *
    * \param pFCP
    * Percentual do ICMS relativo ao Fundo de Combate à Pobreza (FCP). \n
    * > <b>TAG:</b> N17b\n
    * > <b>Parâmetro opcional</b>\n
    * > <b>Tipo:</b> Numérico\n
    * > <b>Tamanho:</b> 3v2-4\n
    *
    * \param vFCP
    * Valor do Fundo de Combate à Pobreza (FCP). \n
    * > <b>TAG:</b> N17c\n
    * > <b>Parâmetro opcional</b>\n
    * > <b>Tipo:</b> Numérico\n
    * > <b>Tamanho:</b> 13v2\n
    *
    * \return
    * O retorno em caso de sucesso será(0). \n
    * Possiveis erros consulte \ref NFCE_Erro_Impostos
    */

    ///@cond
    E1_NFCESHARED_EXPORT STDCALL
    ///@endcond
    int InformaICMS00(const char *file_path, int nItem, int orig, const char *CST, const char *modBC, const char *vBC, const char *pICMS, const char *vICMS, const char *pFCP, const char *vFCP);

    /*! \ingroup g50
    *
    *  Função utilizada para informar ICMS20 na composição das informações para emissão\n
    *
    * \param file_path
    * Caminho absoluto onde o arquivo json será gerado.\n
    * EX:\n
    * > C:/NFCE/venda_001.json
    *
    * \param nItem
    *  Informação do index do produto a ser informado\n
    * > <b>Parâmetro obrigatório</b>\n
    * > <b>Tipo:</b> Numérico\n
    *
    * \param orig
    * Origem da mercadoria.\n
    * > <b>TAG:</b> N11\n
    * > <b>Parâmetro obrigatório</b>\n
    * > <b>Tipo:</b> Numérico\n
    * > <b>Tamanho:</b> 1\n
    *
    * \param CST
    * Tributação do ICMS = 20.\n
    * > <b>TAG:</b> N12\n
    * > <b>Parâmetro obrigatório</b>\n
    * > <b>Tipo:</b> Numérico\n
    * > <b>Tamanho:</b> 2\n
    *
    * \param modBC
    * Modalidade de determinação da BC do ICMS.\n
    * > <b>TAG:</b> N13\n
    * > <b>Parâmetro obrigatório</b>\n
    * > <b>Tipo:</b> Numérico\n
    * > <b>Tamanho:</b> 1 \n
    *
    * \param pRedBC
    * Percentual da Redução de BC. \n
    * > <b>TAG:</b> N14\n
    * > <b>Parâmetro obrigatório</b>\n
    * > <b>Tipo:</b> Numérico\n
    * > <b>Tamanho:</b> 3v2-4\n
    *
    * \param vBC
    * Valor da BC do ICMS. \n
    * > <b>TAG:</b> N15\n
    * > <b>Parâmetro obrigatório</b>\n
    * > <b>Tipo:</b> Numérico\n
    * > <b>Tamanho:</b> 13v2\n
    *
    * \param pICMS
    * Alíquota do imposto \n
    * > <b>TAG:</b> N16\n
    * > <b>Parâmetro obrigatório</b>\n
    * > <b>Tipo:</b> Numérico\n
    * > <b>Tamanho:</b> 3v2-4\n
    *
    * \param vICMS
    * Valor do ICMS. \n
    * > <b>TAG:</b> N17\n
    * > <b>Parâmetro opcional</b>\n
    * > <b>Tipo:</b> Numérico\n
    * > <b>Tamanho:</b> 13v2\n
    *
    *  \param vBCFCP
    * Valor da Base de Cálculo do FCP. \n
    * > <b>TAG:</b> N17a\n
    * > <b>Parâmetro opcional</b>\n
    * > <b>Tipo:</b> Numérico\n
    * > <b>Tamanho:</b> 13v2\n
    *
    * \param pFCP
    * Percentual do ICMS relativo ao Fundo de Combate à Pobreza (FCP). \n
    * > <b>TAG:</b> N17b\n
    * > <b>Parâmetro opcional</b>\n
    * > <b>Tipo:</b> Numérico\n
    * > <b>Tamanho:</b> 3v2-4\n
    *
    * \param vFCP
    * Valor do Fundo de Combate à Pobreza (FCP). \n
    * > <b>TAG:</b> N17c\n
    * > <b>Parâmetro opcional</b>\n
    * > <b>Tipo:</b> Numérico\n
    * > <b>Tamanho:</b> 13v2\n
    *
    * \param vICMSDeson
    * Valor do ICMS desonerado. \n
    * > <b>TAG:</b> N28a\n
    * > <b>Parâmetro opcional</b>\n
    * > <b>Tipo:</b> Numérico\n
    * > <b>Tamanho:</b> 13v2\n
    *
    * \param motDesICMS
    * Motivo da desoneração do ICMS. \n
    * > <b>TAG:</b> N28\n
    * > <b>Parâmetro opcional</b>\n
    * > <b>Tipo:</b> Numérico\n
    * > <b>Tamanho:</b> 2\n
    *
    * \return
    * O retorno em caso de sucesso será(0). \n
    * Possiveis erros consulte \ref NFCE_Erro_Impostos
    */
    ///@cond
    E1_NFCESHARED_EXPORT STDCALL
    ///@endcond
    int InformaICMS20(const char *file_path, int nItem, int orig, const char *CST, const char *modBC, const char *pRedBC, const char *vBC,
                      const char *pICMS, const char *vICMS, const char *vBCFCP, const char *pFCP, const char *vFCP, const char *vICMSDeson, const char *motDesICMS);



    /*! \ingroup g50
    *
    *  Função utilizada para informar ICMS40 na composição das informações para emissão\n
    *
    * \param file_path
    * Caminho absoluto onde o arquivo json será gerado.\n
    * EX:\n
    * > C:/NFCE/venda_001.json
    *
    * \param nItem
    *  Informação do index do produto a ser informado\n
    * > <b>Parâmetro obrigatório</b>\n
    * > <b>Tipo:</b> Numérico\n
    *
    * \param orig
    * Origem da mercadoria.\n
    * > <b>TAG:</b> N11\n
    * > <b>Parâmetro obrigatório</b>\n
    * > <b>Tipo:</b> Numérico\n
    * > <b>Tamanho:</b> 1\n
    *
    * \param CST
    * Tributação do ICMS = 40, 41 ou 50.\n
    * > <b>TAG:</b> N12\n
    * > <b>Parâmetro obrigatório</b>\n
    * > <b>Tipo:</b> Numérico\n
    * > <b>Tamanho:</b> 2\n
    *
    * \param vICMSDeson
    * Valor do ICMS desonerado. \n
    * > <b>TAG:</b> N28a\n
    * > <b>Parâmetro opcional</b>\n
    * > <b>Tipo:</b> Numérico\n
    * > <b>Tamanho:</b> 13v2\n
    *
    * \param motDesICMS
    * Motivo da desoneração do ICMS. \n
    * > <b>TAG:</b> N28\n
    * > <b>Parâmetro opcional</b>\n
    * > <b>Tipo:</b> Numérico\n
    * > <b>Tamanho:</b> 2\n
    *
    * \return
    * O retorno em caso de sucesso será(0). \n
    * Possiveis erros consulte \ref NFCE_Erro_Impostos
    */
    ///@cond
    E1_NFCESHARED_EXPORT STDCALL
    ///@endcond
    int InformaICMS40(const char *file_path, int nItem, int orig, const char *CST, const char *vICMSDeson, const char *motDesICMS);



    /*! \ingroup g50
    *
    * Função utilizada para informar ICMS60 na composição das informações para emissão.\n
    *
    * \param file_path
    * Caminho absoluto onde o arquivo json será gerado.\n
    * EX:\n
    * > C:/NFCE/venda_001.json
    *
    * \param nItem
    *  Informação do index do produto a ser informado\n
    * > <b>Parâmetro obrigatório</b>\n
    * > <b>Tipo:</b> Numérico\n
    *
    * \param orig
    * Origem da mercadoria.\n
    * > <b>TAG:</b> N11\n
    * > <b>Parâmetro obrigatório</b>\n
    * > <b>Tipo:</b> Numérico\n
    * > <b>Tamanho:</b> 1\n
    *
    * \param CST
    * Tributação do ICMS = 60.\n
    * > <b>TAG:</b> N12\n
    * > <b>Parâmetro obrigatório</b>\n
    * > <b>Tipo:</b> Numérico\n
    * > <b>Tamanho:</b> 2\n
    *
    * \param vBCSTRet
    * Valor da BC do ICMS ST retido.\n
    * > <b>TAG:</b> N26\n
    * > <b>Parâmetro opcional</b>\n
    * > <b>Tipo:</b> Numérico\n
    * > <b>Tamanho:</b> 13v2 \n
    *
    * \param pST
    * Alíquota suportada pelo Consumidor Final. \n
    * > <b>TAG:</b> N26a\n
    * > <b>Parâmetro opcional</b>\n
    * > <b>Tipo:</b> Numérico\n
    * > <b>Tamanho:</b> 3v2-4\n
    *
    * \param vICMSSubstituto
    * Valor do ICMS próprio do Substituto. \n
    * > <b>TAG:</b> N26b\n
    * > <b>Parâmetro opcional</b>\n
    * > <b>Tipo:</b> Numérico\n
    * > <b>Tamanho:</b> 13v2\n
    *
    * \param vICMSSTRet
    * Valor do ICMS ST retido. \n
    * > <b>TAG:</b> N27\n
    * > <b>Parâmetro opcional</b>\n
    * > <b>Tipo:</b> Numérico\n
    * > <b>Tamanho:</b> 13v2\n
    *
    * \param vBCFCPSTRet
    * Valor da Base de Cálculo do FCP retido anteriormente. \n
    * > <b>TAG:</b> N27a\n
    * > <b>Parâmetro opcional</b>\n
    * > <b>Tipo:</b> Numérico\n
    * > <b>Tamanho:</b> 13v2\n
    *
    *  \param pFCPSTRet
    * Percentual do FCP retido anteriormente por Substituição Tributária. \n
    * > <b>TAG:</b> N27b\n
    * > <b>Parâmetro opcional</b>\n
    * > <b>Tipo:</b> Numérico\n
    * > <b>Tamanho:</b> 3v2-4\n
    *
    * \param vFCPSTRet
    * Valor do FCP retido por Substituição Tributária. \n
    * > <b>TAG:</b> N27d\n
    * > <b>Parâmetro opcional</b>\n
    * > <b>Tipo:</b> Numérico\n
    * > <b>Tamanho:</b> 13v2\n
    *
    * \param pRedBCEfet
    * Percentual de redução da base de cálculo efetiva. \n
    * > <b>TAG:</b> N34\n
    * > <b>Parâmetro opcional</b>\n
    * > <b>Tipo:</b> Numérico\n
    * > <b>Tamanho:</b> 3v2-4\n
    *
    * \param vBCEfet
    * Valor da base de cálculo efetiva. \n
    * > <b>TAG:</b> N35\n
    * > <b>Parâmetro opcional</b>\n
    * > <b>Tipo:</b> Numérico\n
    * > <b>Tamanho:</b> 13v2\n
    *
    * \param pICMSEfet
    * Alíquota do ICMS efetiva. \n
    * > <b>TAG:</b> N36\n
    * > <b>Parâmetro opcional</b>\n
    * > <b>Tipo:</b> Numérico\n
    * > <b>Tamanho:</b> 3v2-4\n
    *
    * \param vICMSEfet
    * Alíquota do ICMS efetiva. \n
    * > <b>TAG:</b> N37\n
    * > <b>Parâmetro opcional</b>\n
    * > <b>Tipo:</b> Numérico\n
    * > <b>Tamanho:</b> 13v2\n
    *
    * \return
    * O retorno em caso de sucesso será(0). \n
    * Possiveis erros consulte \ref NFCE_Erro_Impostos
    */
    ///@cond
    E1_NFCESHARED_EXPORT STDCALL
    ///@endcond
    int InformaICMS60(const char *file_path, int nItem, int orig, const char *CST, const char *vBCSTRet, const char *pST, const char *vICMSSubstituto,
                      const char *vICMSSTRet, const char *vBCFCPSTRet, const char *pFCPSTRet, const char *vFCPSTRet, const char *pRedBCEfet,
                      const char *vBCEfet, const char *pICMSEfet, const char *vICMSEfet);

//    ///@cond
//    E1_NFCESHARED_EXPORT STDCALL
//    ///@endcond
//    int InformaICMS90(const char *file_path, int nItem, int orig, const char *CST, const char *modBC, const char *pRedBC, const char *vBC, const char *pICMS, const char *vICMS,
//                                                    const char *modBCST, const char *pMVAST, const char *pRedBCST, const char *vBCST, const char *pICMSST, const char *vICMSST, const char *vICMSDeson, const char *motDesICMS);


    /*! \ingroup g50
    * \brief InformaICMSSN102 Função para informe de tributação ICMS pelo Simples Nacional, CSOSN=102, 103, 300 ou 400 (v2.0)
    * \param file_path
    * Caminho absoluto onde o arquivo json será gerado.\n
    * EX:\n
    * > C:/NFCE/venda_001.json
    *
    * \param nItem
    *  Informação do index do produto a ser informado\n
    * > <b>Parâmetro obrigatório</b>\n
    * > <b>Tipo:</b> Numérico\n
    *
    * \param orig
    * Origem da mercadoria.\n
    * > <b>TAG:</b> N11\n
    * > <b>Parâmetro obrigatório</b>\n
    * > <b>Tipo:</b> Numérico\n
    * > <b>Tamanho:</b> 1\n
    *
    * \param CSOSN
    * Código de Situação da Operação – Simples Nacional.\n
    * > <b>TAG:</b> N12a\n
    * > <b>Parâmetro obrigatório</b>\n
    * > <b>Tipo:</b> Numérico\n
    * > <b>Tamanho:</b> 3 \n
    *
    * \return
    * O retorno em caso de sucesso será(0). \n
    * Possiveis erros consulte \ref NFCE_Erro_Impostos
    */
    ///@cond
    E1_NFCESHARED_EXPORT STDCALL
    ///@endcond
    int InformaICMSSN102(const char *file_path, int nItem, int orig, const char *CSOSN);

//    ///@cond
//    E1_NFCESHARED_EXPORT STDCALL
//    ///@endcond
//    int InformaICMSSN202(const char *file_path, int nItem, int orig, const char *CSOSN, const char *modBCST, const char *pMVAST, const char *pRedBCST,
//                                                       const char *vBCST, const char *pICMSST, const char *vICMSST);

    /*! \ingroup g50
    * \brief InformaICMSSN500 - Função para Tributação ICMS pelo Simples Nacional, CSOSN=500 (v2.0)
    * \param file_path
    * Caminho absoluto onde o arquivo json será gerado.\n
    * EX:\n
    * > C:/NFCE/venda_001.json
    *
    * \param nItem
    *  Informação do index do produto a ser informado\n
    * > <b>Parâmetro obrigatório</b>\n
    * > <b>Tipo:</b> Numérico\n
    *
    * \param orig
    * Origem da mercadoria.\n
    * > <b>TAG:</b> N11\n
    * > <b>Parâmetro obrigatório</b>\n
    * > <b>Tipo:</b> Numérico\n
    * > <b>Tamanho:</b> 1\n
    *
    * \param CSOSN
    * Código de Situação da Operação – Simples Nacional.\n
    * > <b>TAG:</b> N12a\n
    * > <b>Parâmetro obrigatório</b>\n
    * > <b>Tipo:</b> Numérico\n
    * > <b>Tamanho:</b> 3 \n
    *
    * \param vBCSTRet
    * Valor da BC do ICMS ST retido.\n
    * > <b>TAG:</b> N26\n
    * > <b>Parâmetro opcional</b>\n
    * > <b>Tipo:</b> Numérico\n
    * > <b>Tamanho:</b> 13v2 \n
    *
    * \param pST
    * Alíquota suportada pelo Consumidor Final. \n
    * > <b>TAG:</b> N26a\n
    * > <b>Parâmetro opcional</b>\n
    * > <b>Tipo:</b> Numérico\n
    * > <b>Tamanho:</b> 3v2-4\n
    *
    * \param vICMSSubstituto
    * Valor do ICMS próprio do Substituto. \n
    * > <b>TAG:</b> N26b\n
    * > <b>Parâmetro opcional</b>\n
    * > <b>Tipo:</b> Numérico\n
    * > <b>Tamanho:</b> 13v2\n
    *
    * \param vICMSSTRet
    * Valor do ICMS ST retido. \n
    * > <b>TAG:</b> N27\n
    * > <b>Parâmetro opcional</b>\n
    * > <b>Tipo:</b> Numérico\n
    * > <b>Tamanho:</b> 13v2\n
    *
    * \param vBCFCPSTRet
    * Valor da Base de Cálculo do FCP retido anteriormente. \n
    * > <b>TAG:</b> N27a\n
    * > <b>Parâmetro opcional</b>\n
    * > <b>Tipo:</b> Numérico\n
    * > <b>Tamanho:</b> 13v2\n
    *
    *  \param pFCPSTRet
    * Percentual do FCP retido anteriormente por Substituição Tributária. \n
    * > <b>TAG:</b> N27b\n
    * > <b>Parâmetro opcional</b>\n
    * > <b>Tipo:</b> Numérico\n
    * > <b>Tamanho:</b> 3v2-4\n
    *
    * \param vFCPSTRet
    * Valor do FCP retido por Substituição Tributária. \n
    * > <b>TAG:</b> N27d\n
    * > <b>Parâmetro opcional</b>\n
    * > <b>Tipo:</b> Numérico\n
    * > <b>Tamanho:</b> 13v2\n
    *
    * \param pRedBCEfet
    * Percentual de redução da base de cálculo efetiva. \n
    * > <b>TAG:</b> N34\n
    * > <b>Parâmetro opcional</b>\n
    * > <b>Tipo:</b> Numérico\n
    * > <b>Tamanho:</b> 3v2-4\n
    *
    * \param vBCEfet
    * Valor da base de cálculo efetiva. \n
    * > <b>TAG:</b> N35\n
    * > <b>Parâmetro opcional</b>\n
    * > <b>Tipo:</b> Numérico\n
    * > <b>Tamanho:</b> 13v2\n
    *
    * \param pICMSEfet
    * Alíquota do ICMS efetiva. \n
    * > <b>TAG:</b> N36\n
    * > <b>Parâmetro opcional</b>\n
    * > <b>Tipo:</b> Numérico\n
    * > <b>Tamanho:</b> 3v2-4\n
    *
    * \param vICMSEfet
    * Alíquota do ICMS efetiva. \n
    * > <b>TAG:</b> N37\n
    * > <b>Parâmetro opcional</b>\n
    * > <b>Tipo:</b> Numérico\n
    * > <b>Tamanho:</b> 13v2\n
    *
    * \return
    * O retorno em caso de sucesso será(0). \n
    * Possiveis erros consulte \ref NFCE_Erro_Impostos
    */
    ///@cond
    E1_NFCESHARED_EXPORT STDCALL
    ///@endcond
    int InformaICMSSN500(const char *file_path,
                         int nItem,
                         int orig,
                         const char *CSOSN,
                         const char *vBCSTRet,
                         const char *pST,
                         const char *vICMSSubstituto,
                         const char *vICMSSTRet,
                         const char *vBCFCPSTRet,
                         const char *pFCPSTRet,
                         const char *vFCPSTRet,
                         const char *pRedBCEfet,
                         const char *vBCEfet,
                         const char *pICMSEfet,
                         const char *vICMSEfet);

//    ///@cond
//    E1_NFCESHARED_EXPORT STDCALL
//    ///@endcond
//    int InformaICMSSN900(const char *file_path, int nItem, int orig, const char *modBC, const char *vBC, const char *pRedBC, const char *pICMS, const char *vICMS, const char *modBCST, const char *pMVAST,
//                                                       const char *pRedBCST, const char *vBCST, const char *pICMSST, const char *vICMSST, const char *CSOSN, const char *pCredSN, const char *vCredICMSSN);

}

#endif // EXPORTAFUNCOES_H
