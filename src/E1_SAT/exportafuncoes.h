#ifndef EXPORTAFUNCOES_H
#define EXPORTAFUNCOES_H
#include "e1_sat_global.h"

#ifdef __WIN32
#define STDCALL __stdcall
#elif __linux__
#define STDCALL
#endif

    /*
     Descrição: Classe principal que exporta as funções da biblioteca de comunicação do  SAT.
     Autor:     Edilson Julio
     Data:      12/04/2019
     */

__attribute__((constructor))void initLib();
__attribute__((destructor)) void exitLib();

extern "C"{

    /*! \defgroup g2 SAT
     * \brief Fornece funções específicas de comunicação com SAT Elgin.
     *
     * Os modelos compatíveis com essa biblioteca são: \n
     * > Linker SAT Elgin II. \n
     * > SmartSAT\n
     * > Bematech RB 1000\n
     * > Bematech RB 2000\n
     * > Bematech SATGO\n
     *
     * Convenções usadas nas chamadas das funções da biblioteca:\n
     *<b>Windows</b>\n
     *  > __stdcall
     *<b>Linux</b>\n
     *  > __cdecl\n
     *
     *  ### Arquivo de configuracao
     *  O arquivo de configuração é carregado do diretório atual onde a aplicação está\n
     *  sendo executada. Um exemplo do arquivo sat-config.ini pode ser visto abaixo:
     *
     * ``` ini
     * [Logging]
     * # Aceita info, debug ou trace
     * level = trace
     *
     * # Onde escrever o log
     * file = /tmp/sat.log
     *
     * [Connection]
     * # Usar conexao continua com o dispositivo (default: true)
     * continuous = true
     *
     * # Hub onde o dispositivo esta conectado
     * #hub = 1
     *
     * # Porta onde o dispositivo esta conectado
     * #port = 2
     *
     * # Serial do dispositivo
     * serial = 900018930
     * ```
     */

///@cond

///FUNÇÕES ADICIONAIS FORAM COMENTADAS PARA NÃO GERAR CONFUSÃO NA DOCUMENTAÇÃO E POR NÃO TER DEMANDA DE USO
////////////////////////////////////////////////////////////////////////////////////////////////////////////

/// @endcond
////////////////////////////////////////////////////////////////////////////////////////////////////////////

//    FUNÇÕES BASICAS DA DLL DO SAT - Versao 7.0.0

   /*! \ingroup g2
     *
     * Função utilizada no processo de ativação do sat.
     *
     * \param numSessao - Parâmetro do tipo numérico que informa o número de sessão.
     *
     * \param subComando - Parâmetro do tipo numérico que define o tipo de certificação.
     *
     * \param codAtivacao - Parâmetro do tipo caracter que informa a senha definida pelo contribuinte.
     *
     * \param cnpj - Parâmetro do tipo caracter que informa o cnpj do contribuinte.
     *
     * \param cUF - Parâmetro do tipo numérico que informa o codigo da federação estadual .
     *
     * \return
     * O retorno será uma string informando se o sat foi ativado ou se esta pendente de vinculação.
     *
     *
     * \n\n
     * > <b><i> Exemplo json para uso com Serviço.</b></i>
     * ~~~~~~~.json
     *  {
     *      "Modulo": "SAT",
     *      "Comando": "AtivarSAT",
     *      "Parametros": [{
     *          "numSessao": 00008,
     *          "subComando": 2,
     *		    "codAtivacao": "123456789",
     *		    "cnpj": "14200166000166",
     *		    "cUF": "15"
     *       }]
     *  }
     * ~~~~~~~
     *
     * \n
     * > <b><i> Exemplo de comando com separadores para uso do Serviço no modo troca de arquivos.</b></i>
     * ~~~~~~~.json
     * SAT:|AtivarSAT:|00008:|2:|123456789:|14200166000166:|15
     * ~~~~~~~
     *
    */

     ///@cond
     E1_SATSHARED_EXPORT STDCALL
     ///@endcond
     char* AtivarSAT(int numSessao,int subComando, const char *codAtivacao,const char* cnpj,int cUF);

    /*! \ingroup g2
     *
     * Função utilizada para enviar os dados de uma venda para que o SAT possa gerar um CFe de venda.
     *
     * \param numSessao - Parâmetro do tipo numérico que informa o número de sessão.
     *
     * \param codAtivacao - Parâmetro do tipo caracter que informa a senha definida pelo contribuinte.
     *
     * \param dadosVenda - Parâmetro do tipo caracter que define a entrada dos dados de venda.
     *
     * \return
     * O retorno em caso de sucesso será um string informando resultado da operação.
     *
     *
     * \n\n
     * > <b><i> Exemplo json para uso com Serviço.</b></i>
     * ~~~~~~~.json
     *  {
     *      "Modulo": "SAT",
     *      "Comando": "EnviarDadosVenda",
     *      "Parametros": [{
     *          "numSessao": 00009,
     *		    "codAtivacao": "123456789",
     * 			"dadosVenda": "<?xml version=\"1.0\"?> <CFe> <infCFe versaoDadosEnt=\"0.07\"> <ide><CNPJ>16716114000172</CNPJ><signAC>SGR-SAT SISTEMA DE GESTAO E RETAGUARDA DO SAT</signAC><numeroCaixa>001</numeroCaixa> </ide><emit><CNPJ>14200166000166</CNPJ><IE>111111111111</IE><indRatISSQN>N</indRatISSQN></emit><dest></dest><det nItem=\"1\"> <prod> <cProd>00000000000001</cProd> <xProd>PRODUTO NFCE 1</xProd> <NCM>94034000</NCM> <CFOP>5102</CFOP> <uCom>UN</uCom> <qCom>1.0000</qCom> <vUnCom>3.51</vUnCom> <indRegra>T</indRegra> </prod> <imposto> <ICMS><ICMS00><Orig>0</Orig><CST>00</CST><pICMS>7.00</pICMS></ICMS00> </ICMS><PIS><PISAliq><CST>01</CST><vBC>6.51</vBC><pPIS>0.0165</pPIS></PISAliq> </PIS> <COFINS><COFINSAliq><CST>01</CST><vBC>6.51</vBC><pCOFINS>0.0760</pCOFINS></COFINSAliq> </COFINS> </imposto> </det> <total><DescAcrEntr><vDescSubtot>0.51</vDescSubtot></DescAcrEntr><vCFeLei12741>0.56</vCFeLei12741></total><pgto> <MP> <cMP>01</cMP> <vMP>6.51</vMP> </MP></pgto><infAdic> <infCpl>Trib aprox R$ 0,36 federal, R$ 1,24 estadual e R$ 0,00 municipal&lt;br&gt;CAIXA: 001 OPERADOR: ROOT</infCpl></infAdic></infCFe></CFe>"
     *       }]
     *  }
     * ~~~~~~~
     *
     * \n
     * > <b><i> Exemplo de comando com separadores para uso do Serviço no modo troca de arquivos.</b></i>
     * ~~~~~~~.json
     * SAT:|EnviarDadosVenda:|00009:|123456789:|<?xml version=\"1.0\"?> <CFe> <infCFe versaoDadosEnt=\"0.07\"> <ide><CNPJ>16716114000172</CNPJ><signAC>SGR-SAT SISTEMA DE GESTAO E RETAGUARDA DO SAT</signAC><numeroCaixa>001</numeroCaixa> </ide><emit><CNPJ>14200166000166</CNPJ><IE>111111111111</IE><indRatISSQN>N</indRatISSQN></emit><dest></dest><det nItem=\"1\"> <prod> <cProd>00000000000001</cProd> <xProd>PRODUTO NFCE 1</xProd> <NCM>94034000</NCM> <CFOP>5102</CFOP> <uCom>UN</uCom> <qCom>1.0000</qCom> <vUnCom>3.51</vUnCom> <indRegra>T</indRegra> </prod> <imposto> <ICMS><ICMS00><Orig>0</Orig><CST>00</CST><pICMS>7.00</pICMS></ICMS00> </ICMS><PIS><PISAliq><CST>01</CST><vBC>6.51</vBC><pPIS>0.0165</pPIS></PISAliq> </PIS> <COFINS><COFINSAliq><CST>01</CST><vBC>6.51</vBC><pCOFINS>0.0760</pCOFINS></COFINSAliq> </COFINS> </imposto> </det> <total><DescAcrEntr><vDescSubtot>0.51</vDescSubtot></DescAcrEntr><vCFeLei12741>0.56</vCFeLei12741></total><pgto> <MP> <cMP>01</cMP> <vMP>6.51</vMP> </MP></pgto><infAdic> <infCpl>Trib aprox R$ 0,36 federal, R$ 1,24 estadual e R$ 0,00 municipal&lt;br&gt;CAIXA: 001 OPERADOR: ROOT</infCpl></infAdic></infCFe></CFe>
     * ~~~~~~~
     *
     */

     ///@cond
     E1_SATSHARED_EXPORT STDCALL
     ///@endcond
     char* EnviarDadosVenda(int numSessao, const char* codAtivacao, const char* dadosVenda);

     /*! \ingroup g2
      *
      * Função utilizada para efetuar o cancelamento do cupom referente à última venda realizada.
      *
      * \param numSessao - Parâmetro do tipo numérico que informa o número de sessão.
      *
      * \param codAtivacao - Parâmetro do tipo caractere que informa o código de ativação definido pelo usuário.
      *
      * \param numeroCFe - Parâmetro do tipo caractere que permite ao usuário informar o número do CFe da venda a ser cancelada.
      *
      * \param dadosCancelamento - Parâmetro do tipo caractere que define o XML de cancelamento referente ao número de CFe informado.
      *
      * \return
      * O retorno, em caso de sucesso, será uma string informando o resultado da operação.
      * \n
      *
      * > <b><i> Exemplo JSON para uso com Serviço. </b></i>
      * ~~~~~~~.json
      *  {
      *      "Modulo": "SAT",
      *      "Comando": [
      *          {"Funcao": "CancelarUltimaVenda",
      *          "Parametros": [
      *              {"numSessao": 00001,
      *              "codAtivacao": "123456789",
      *              "numeroCFe": "CFe13181114200166000166599000162500104927318337",
      *              "dadosCancelamento": "<CFeCanc><infCFe chCanc=\"CFe13181114200166000166599000162500104927318337\"><ide><CNPJ>16716114000172</CNPJ><signAC>MD2Nof/O0tQMPKiYeeAydSjYt7YV9kU0nWKZGXHVdYIzR2W9Z6tgXni/Y5bnjmUAk8MkqlBJIiOOIskKCjJ086k7vAP0EU5cBRYj/nzHUiRdu9AVD7WRfVs00BDyb5fsnnKg7gAXXH6SBgCxG9yjAkxJ0l2E2idsWBAJ5peQEBZqtHytRUC+FLaSfd3+66QNxIBlDwQIRzUGPaU6fvErVDSfMUf8WpkwnPz36fCQnyLypqe/5mbox9pt3RCbbXcYqnR/4poYGr9M9Kymj4/PyX9xGeiXwbgzOOHNIU5M/aAs0rulXz948bZla0eXABgEcp6mDkTzweLPZTbmOhX+eA==</signAC><numeroCaixa>001</numeroCaixa></ide><emit/><dest></dest><total/></infCFe></CFeCanc>"
      *              }
      *          ]}
      *      ]
      *  }
      * ~~~~~~~
      * \n
      *
      * > <b><i> Exemplo de comando com separadores para uso com Serviço. </b></i>
      * ~~~~~~~.json
      * SAT:|CancelarUltimaVenda:|00001:|123456789:|CFe13181114200166000166599000162500104927318337:|<CFeCanc><infCFe chCanc=\"CFe13181114200166000166599000162500104927318337\"><ide><CNPJ>16716114000172</CNPJ><signAC>MD2Nof/O0tQMPKiYeeAydSjYt7YV9kU0nWKZGXHVdYIzR2W9Z6tgXni/Y5bnjmUAk8MkqlBJIiOOIskKCjJ086k7vAP0EU5cBRYj/nzHUiRdu9AVD7WRfVs00BDyb5fsnnKg7gAXXH6SBgCxG9yjAkxJ0l2E2idsWBAJ5peQEBZqtHytRUC+FLaSfd3+66QNxIBlDwQIRzUGPaU6fvErVDSfMUf8WpkwnPz36fCQnyLypqe/5mbox9pt3RCbbXcYqnR/4poYGr9M9Kymj4/PyX9xGeiXwbgzOOHNIU5M/aAs0rulXz948bZla0eXABgEcp6mDkTzweLPZTbmOhX+eA==</signAC><numeroCaixa>001</numeroCaixa></ide><emit/><dest></dest><total/></infCFe></CFeCanc>
      * ~~~~~~~
      */

     ///@cond
     E1_SATSHARED_EXPORT STDCALL
     ///@endcond
     char* CancelarUltimaVenda(int numSessao, const char* codAtivacao, const char* numeroCFe, const char* dadosCancelamento);

    /*! \ingroup g2
     *
     * Função utilizada para testar comunicação com SAT.
     *
     * \param numSessao - Parâmetro tipo numérico que informa o numero de sessão
     *
     * \return
     * O retorno em caso de sucesso será um string informando resultado da operação.
     *
     *
     * \n\n
     * > <b><i> Exemplo json para uso com Serviço.</b></i>
     * ~~~~~~~.json
     *  {
     *      "Modulo": "SAT",
     *      "Comando": "ConsultarSat",
     *      "Parametros": [{
     *          "numSessao": 00004
     *       }]
     *  }
     * ~~~~~~~
     *
     * \n
     * > <b><i> Exemplo de comando com separadores para uso do Serviço no modo troca de arquivos.</b></i>
     * ~~~~~~~.json
     * SAT:|ConsultarSat:|00004
     * ~~~~~~~
     *
     */

     ///@cond
     E1_SATSHARED_EXPORT STDCALL
     ///@endcond
     char* ConsultarSAT(int numSessao);

    /*! \ingroup g2
     *
     * Função utilizada para realizar a emissão de um CFe de teste e verificar se os processo de emissão de CFes e de comunicação \n
     * com a Secretaria da Fazenda estão funcionando.
     *
     * \param numSessao - Parâmetro do tipo numérico que informa o numero de sessão.
     *
     * \param codAtivacao - Parâmetro do tipo caracter que informa o codigo de ativação definido pelo usuário.
     *
     * \param dadosVenda - Parâmetro do tipo caracter que recebe o xml com so dados da venda de teste.
     *
     * \return
     * O retorno em caso de sucesso será um string informando resultado da operação.
     *
     *
     * \n\n
     * > <b><i> Exemplo json para uso com Serviço.</b></i>
     * ~~~~~~~.json
     *  {
     *      "Modulo": "SAT",
     *      "Comando": "TesteFimAFim",
     *      "Parametros": [{
     *          "numSessao": 00002
     *       }]
     *  }
     * ~~~~~~~
     *
     * \n
     * > <b><i> Exemplo de comando com separadores para uso do Serviço no modo troca de arquivos.</b></i>
     * ~~~~~~~.json
     * SAT:|TesteFimAFim:|00002
     * ~~~~~~~
     *
     */

     ///@cond
     E1_SATSHARED_EXPORT STDCALL
     ///@endcond
     char* TesteFimAFim(int numSessao, const char* codAtivacao, const char* dadosVenda);

    /*! \ingroup g2
     *
     * Função utilzada para obter informações do estado de operação do SAT.
     *
     * \param numSessao - Parâmetro do tipo numérico que informa o numero de sessão.
     *
     * \param codAtivacao - Parâmetro do tipo caracter que informa o código de ativação definido pelo usuário.
     *
     * \return
     * O retorno em caso de sucesso será um string com as informações do SAT separadas por pipe.
     *
     * \n\n
     * > <b><i> Exemplo json para uso com Serviço.</b></i>
     * ~~~~~~~.json
     *  {
     *      "Modulo": "SAT",
     *      "Comando": "ConsultarStatusOperacional",
     *      "Parametros": [{
     *          "numSessao": 00002,
     *          "codAtivacao": "123456789"
     *       }]
     *  }
     * ~~~~~~~
     *
     * \n
     * > <b><i> Exemplo de comando com separadores para uso do Serviço no modo troca de arquivos.</b></i>
     * ~~~~~~~.json
     * SAT:|ConsultarStatusOperacional:|00002:|123456789
     * ~~~~~~~
     *
     */

     ///@cond
     E1_SATSHARED_EXPORT STDCALL
     ///@endcond
     char* ConsultarStatusOperacional(int numSessao, const char* codAtivacao);

    /*! \ingroup g2
     *
     * Função utilizada para obter o número de sessão a ser consultado.
     *
     * \param numSessao - Parâmetro do tipo numérico que informa o numero de sessão.
     *
     * \param codAtivacao - Parâmetro do tipo caracter que informa o código de ativação definido pelo usuário.
     *
     * \param cNumeroDeSessao - Parâmetro do tipo numérico que informa o numero da sessão a ser consultada.
     *
     * \return
     *
     *
     * \n\n
     * > <b><i> Exemplo json para uso com Serviço.</b></i>
     * ~~~~~~~.json
     *  {
     *      "Modulo": "SAT",
     *      "Comando": "ConsultarNumeroSessao",
     *      "Parametros": [{
     *          "numSessao": 00002,
     *          "codAtivacao": "123456789",
     *          "cNumeroDeSessao": "1800"
     *       }]
     *  }
     * ~~~~~~~
     *
     * \n
     * > <b><i> Exemplo de comando com separadores para uso do Serviço no modo troca de arquivos.</b></i>
     * ~~~~~~~.json
     * SAT:|ConsultarNumeroSessao:|00002:|123456789:|1800
     * ~~~~~~~
     *
     */

     ///@cond
     E1_SATSHARED_EXPORT STDCALL
     ///@endcond
     char* ConsultarNumeroSessao(int numSessao, const char* codAtivacao, int cNumeroDeSessao);

     /*! \ingroup g2
      *
      * Função utilizada para consultar o resultado da última sessão fiscal processada, isto é,
      * o resultado da última venda ou do último cancelamento de venda processado.
      *
      * \param numSessao - Parâmetro do tipo numérico que informa o número de sessão.
      *
      * \param codAtivacao - Parâmetro do tipo caractere que informa o código de ativação definido pelo usuário.
      *
      * \return
      * O retorno, em caso de sucesso, será uma string informando o resultado da operação.
      * \n
      *
      * > <b><i> Exemplo JSON para uso com Serviço. </b></i>
      * ~~~~~~~.json
      *  {
      *      "Modulo": "SAT",
      *      "Comando": [
      *          {"Funcao": "ConsultarUltimaSessaoFiscal",
      *          "Parametros": [
      *              {"numSessao": 00001,
      *              "codAtivacao": "123456789"
      *              }
      *          ]}
      *      ]
      *  }
      * ~~~~~~~
      * \n
      *
      * > <b><i> Exemplo de comando com separadores para uso com Serviço. </b></i>
      * ~~~~~~~.json
      * SAT:|ConsultarUltimaSessaoFiscal:|00001:|123456789
      * ~~~~~~~
      */

     ///@cond
     E1_SATSHARED_EXPORT STDCALL
     ///@endcond
     char* ConsultarUltimaSessaoFiscal(int numSessao, const char* codAtivacao);

  /*! \ingroup g2
     *
     * Função utilizada para configurar o tipo de conexão de rede.
     *
     * \param numSessao - Parâmetro do tipo numérico que informa o numero de sessão.
     *
     * \param codAtivacao - Parâmetro do tipo caracter que informa o código de ativação definido pelo usuário.
     *
     * \param dadosConfiguracao- Parâmetro do tipo caracter que informa os dados a serem configurados em forma de XML.
     *
     * \return
     * O retorno em caso de sucesso será uma string informando o resultado da operação.
     *
     *
     * \n\n
     * > <b><i> Exemplo json para uso com Serviço.</b></i>
     * ~~~~~~~.json
     *  {
     *      "Modulo": "SAT",
     *      "Comando": "ConfigurarInterfaceDeRede",
     *      "Parametros": [{
     *          "numSessao": 00001,
     *          "codAtivacao": "123456789",
     *          "dadosConfiguracao": "<?xml version=\"1.0\" encoding=\"UTF - 8\"?><config><tipoInter>ETHE</tipoInter><tipoLan>DHCP</tipoLan></config>"
     *       }]
     *  }
     * ~~~~~~~
     *
     * \n
     * > <b><i> Exemplo de comando com separadores para uso do Serviço no modo troca de arquivos.</b></i>
     * ~~~~~~~.json
     * SAT:|ConfigurarInterfaceDeRede:|00001:|123456789:|<?xml version=\"1.0\" encoding=\"UTF - 8\"?><config><tipoInter>ETHE</tipoInter><tipoLan>DHCP</tipoLan></config>
     * ~~~~~~~
     *
     */

     ///@cond
     E1_SATSHARED_EXPORT STDCALL
     ///@endcond
     char* ConfigurarInterfaceDeRede(int numSessao, const char* codAtivacao, const char* dadosConfiguracao);

   /*! \ingroup g2
     *
     * Função utilizada para associar uma assinatura de Software House junto ao Sat.
     *
     * \param numSessao - Parâmetro do tipo numérico que informa o numero de sessão.
     *
     * \param codAtivacao - Parâmetro do tipo caracter que informa o código de ativação definido pelo usuário.
     *
     * \param cnpjSH - Parâmetro do tipo caracter que informa o cnpj da Software House.
     *
     * \param assinaturaAC - Parâmetro do tipo caracter que informa a assinatura gerada e fornecida pela software house.
     *
     * \return
     *
     *
     * \n\n
     * > <b><i> Exemplo json para uso com Serviço.</b></i>
     * ~~~~~~~.json
     *  {
     *      "Modulo": "SAT",
     *      "Comando": "AssociarAssinatura",
     *      "Parametros": [{
     *          "numSessao": 00002,
     *          "codAtivacao": "123456789",
     *          "cnpjSH": "16716114000172",
     *          "assinaturaAC": "SGR-SAT SISTEMA DE GESTAO E RETAGUARDA DO SAT"
     *       }]
     *  }
     * ~~~~~~~
     *
     *
     * \n
     * > <b><i> Exemplo de comando com separadores para uso do Serviço no modo troca de arquivos.</b></i>
     * ~~~~~~~.json
     * SAT:|AssociarAssinatura:|00002:|123456789:|16716114000172:|SGR-SAT SISTEMA DE GESTAO E RETAGUARDA DO SAT
     * ~~~~~~~

     *
     */

     ///@cond
     E1_SATSHARED_EXPORT STDCALL
     ///@endcond
     char* AssociarAssinatura(int numSessao, const char* codAtivacao, const char* cnpjSH, const char* assinaturaAC);

    /*! \ingroup g2
     *
     * Função utilizada na atualização do software básico do SAT.
     *
     * \param numSessao - Parâmetro do tipo numérico que informa o numero de sessão.
     *
     * \param codAtivacao - Parâmetro do tipo caracter que informa o código de ativação definido pelo usuário.
     *
     * \return
     *
     *
     * \n\n
     * > <b><i> Exemplo json para uso com Serviço.</b></i>
     * ~~~~~~~.json
     *  {
     *      "Modulo": "SAT",
     *      "Comando": "AtualizarSoftwareSAT",
     *      "Parametros": [{
     *          "numSessao": 00005,
     *          "codAtivacao": "123456789",
     *       }]
     *  }
     * ~~~~~~~
     *
     * \n
     * > <b><i> Exemplo de comando com separadores para uso do Serviço no modo troca de arquivos.</b></i>
     * ~~~~~~~.json
     * SAT:|AtualizarSoftwareSAT:|00005:|123456789
     * ~~~~~~~
     *
     */

     ///@cond
     E1_SATSHARED_EXPORT STDCALL
     ///@endcond
     char* AtualizarSoftwareSAT(int numSessao, const char* codAtivacao);

   /*! \ingroup g2
     *
     * Função utilizada para consultar o log gerado pelo equipamento SAT.
     *
     * \param numSessao - Parâmetro do tipo numérico que informa o numero de sessão.
     *
     * \param codAtivacao - Parâmetro do tipo caracter que informa o código de ativação definido pelo usuário.
     *
     * \return
     *
     *
     * \n\n
     * > <b><i> Exemplo json para uso com Serviço.</b></i>
     * ~~~~~~~.json
     *  {
     *      "Modulo": "SAT",
     *      "Comando": "ExtrairLogs",
     *      "Parametros": [{
     *          "numSessao": 00006,
     *          "codAtivacao": "123456789"
     *       }]
     *  }
     * ~~~~~~~
     *
     * \n
     * > <b><i> Exemplo de comando com separadores para uso do Serviço no modo troca de arquivos.</b></i>
     * ~~~~~~~.json
     * SAT:|ExtrairLogs:|00006:|123456789
     * ~~~~~~~
     *
     */

     ///@cond
     E1_SATSHARED_EXPORT STDCALL
     ///@endcond
     char* ExtrairLogs(int numSessao, const char* codAtivacao);

   /*! \ingroup g2
     *
     * Função utilizada para efetuar o bloqueio do equipamento caso tenha uma solicitação junto a Secretaria da Fazenda.
     *
     * \param numSessao - Parâmetro do tipo numérico que informa o numero de sessão.
     *
     * \param codAtivacao - Parâmetro do tipo caracter que informa o código de ativação definido pelo usuário.
     *
     * \return
     *
     *
     * \n\n
     * > <b><i> Exemplo json para uso com Serviço.</b></i>
     * ~~~~~~~.json
     *  {
     *      "Modulo": "SAT",
     *      "Comando": "BloquearSAT",
     *      "Parametros": [{
     *          "numSessao": 00008,
     *          "codAtivacao": "123456789"
     *       }]
     *  }
     * ~~~~~~~
     *
     * \n
     * > <b><i> Exemplo de comando com separadores para uso do Serviço no modo troca de arquivos.</b></i>
     * ~~~~~~~.json
     * SAT:|BloquearSAT:|00008:|123456789
     * ~~~~~~~
     *
     */

     ///@cond
     E1_SATSHARED_EXPORT STDCALL
     ///@endcond
     char* BloquearSAT(int numSessao, const char* codAtivacao);

    /*! \ingroup g2
     *
     * Função utilizada para efetuar o desbloqueio de SAT.
     *
     * \param numSessao - Parâmetro do tipo numérico que informa o numero de sessão.
     *
     * \param codAtivacao - Parâmetro do tipo caracter que informa o código de ativação definido pelo usuário.
     *
     * \return
     *
     *
     * \n\n
     * > <b><i> Exemplo json para uso com Serviço.</b></i>
     * ~~~~~~~.json
     *  {
     *      "Modulo": "SAT",
     *      "Comando": "DesbloquearSAT",
     *      "Parametros": [{
     *          "numSessao": 00009,
     *          "codAtivacao": "123456789"
     *       }]
     *  }
     * ~~~~~~~
     *
     * \n
     * > <b><i> Exemplo de comando com separadores para uso do Serviço no modo troca de arquivos.</b></i>
     * ~~~~~~~.json
     * SAT:|DesbloquearSAT:|00008:|123456789
     * ~~~~~~~
     *
     */

     ///@cond
     E1_SATSHARED_EXPORT STDCALL
     ///@endcond
     char* DesbloquearSAT(int numSessao, const char* codAtivacao);

    /*! \ingroup g2
     *
     * Função utilizada para efetuar a troca do código de ativação do SAT.
     *
     * \param numSessao - Parâmetro do tipo numérico que informa o numero de sessão.
     *
     * \param codAtivacao - Parâmetro do tipo caracter que informa o código de ativação definido pelo usuário.
     *
     * \param opcao - Parâmetro do tipo inteiro que especifica qual opcao da troca : (1) Troca de Código tradicional \n
     *                                                                               (2) Troca usando Código de Emergência.
     * \return
     *
     *
     * \n\n
     * > <b><i> Exemplo json para uso com Serviço.</b></i>
     * ~~~~~~~.json
     *  {
     *      "Modulo": "SAT",
     *      "Comando": "TrocarCodigoDeAtivacao",
     *      "Parametros": [{
     *          "numSessao": 00009,
     *          "codAtivacao": "123456789",
     *          "opcao": 1,
     *          "novoCodigo": "1234567890",
     *          "confNovoCodigo": "1234567890"
     *       }]
     *  }
     * ~~~~~~~
     *
     *
     * \n
     * > <b><i> Exemplo de comando com separadores para uso do Serviço no modo troca de arquivos.</b></i>
     * ~~~~~~~.json
     * SAT:|TrocarCodigoDeAtivacao:|00009:|123456789:|1:|1234567890:|1234567890
     * ~~~~~~~
     *
     */

     ///@cond
     E1_SATSHARED_EXPORT STDCALL
     ///@endcond
     char* TrocarCodigoDeAtivacao(int numSessao, const char* codAtivacao, int opcao, const char* novoCodigo, const char* confNovoCodigo);

     /*! \ingroup g2
      * \brief Retorna a versão da DLL E1_SAT.
      *
      * \return
      * O retorno da função é do tipo caractere.\n
      * \n
      *
      * A função bem-sucedida deve retornar ??.??.??, que representa a versão da DLL
      * em que esta função foi chamada; cada <b>?</b> é um dígito entre 0 e 9.
      * \n
      *
      * > <b><i> Exemplo JSON para uso com Serviço. </b></i>
      * ~~~~~~~.json
      *  {
      *      "Modulo": "SAT",
      *      "Comando": [
      *          {"Funcao": "GetVersaoDLL",
      *          "Parametros": [
      *              {
      *              }
      *          ]}
      *      ]
      *  }
      * ~~~~~~~
      * \n
      *
      * > <b><i> Exemplo de comando com separadores para uso com Serviço. </b></i>
      * ~~~~~~~.json
      * SAT:|GetVersaoDLL
      * ~~~~~~~
      */

     ///@cond
     E1_SATSHARED_EXPORT STDCALL
     ///@endcond
     char *GetVersaoDLL();

     /*!
      * \ingroup g2
      * \brief Permite que a biblioteca mantenha a conexão USB aberta
      * até que a aplicação seja finalizada
      *
      * Esse modo é habilitado por padrão
      *
      */
     ///@cond
     E1_SATSHARED_EXPORT STDCALL
     ///@endcond
     void HabilitarConexaoContinua(void);

     /*!
      * \ingroup g2
      * \brief Fecha a conexao USB apos cada resposta ser recebida,
      * permitindo que outras aplicacoes acessem o mesmo dispositivo
      *
      * Aviso: Nesse modo de operação o número de sessão
      * deve ser controlado externamente
      *
      */
     ///@cond
     E1_SATSHARED_EXPORT STDCALL
     ///@endcond
     void DesabilitarConexaoContinua(void);

     /*!
      * \ingroup g2
      * \brief Configura a biblioteca para utilizar um SAT com o numero de serie
      * especificado.
      *
      * \param numero_serie - Número de série do equipamento a ser utilizado, Ex: 900020819-03
      *
      * \return 0 = Sucesso\n 1 = Falha
      *
      */
     ///@cond
     E1_SATSHARED_EXPORT STDCALL
     ///@endcond
     int FiltraSATNumSerie(const char *numero_serie);

     /*!
      * \ingroup g2
      * \brief Configura a biblioteca para utilizar um SAT na porta USB especificada.
      *
      * \param bus - Número do barramento em que o SAT está conectado.
      *
      * \param port - Número da porta em que o equipamento está conectado.
      *
      * \return 0 = Sucesso\n 1 = Falha
      *
      */
     ///@cond
     E1_SATSHARED_EXPORT STDCALL
     ///@endcond
     int FiltraSATUsb(unsigned int bus, unsigned int port);


     /*!
      * \ingroup g2
      * \brief Configura a biblioteca para utilizar o primeiro SAT encontrado.
      *
      * Esse modo é habilitado por padrão.
      *
      */
     ///@cond
     E1_SATSHARED_EXPORT STDCALL
     ///@endcond
     void LimpaFiltrosSAT(void);

     /*!
      * \ingroup g2
      * \brief Lista todos os dispositivos SAT livres encontrados na máquina identificado
      * o seu modelo, hub e port usb e número de série retornado em uma string json.
      *
      * \return Ex:
      * ~~~~~~~.json
      * [
      *    {
      *       "device":"SatGo",
      *       "bus":1,
      *       "port":1
      *    },
      *    {
      *       "device":"SmartSat",
      *       "bus":1,
      *       "port":4,
      *       "serial":"900021403"
      *    }
      * ]
      * ~~~~~~~
      */
     ///@cond
     E1_SATSHARED_EXPORT STDCALL
     ///@endcond
     char *ListAvailableSatAsJson(void);


    ///FUNCOES DE CRIAÇÃO DE XML SAT DA BIBLIOTECA E1_SAT
     /*! \defgroup s0 XML SAT
      * \ingroup g2
      *
      * \brief Funções reponsaveis pela geração dos xmls do sat para operações de venda e cancelamento.\n
      * Abaixo é apresentado um fluxograma a ser seguido pela autoamação no processo de geração do xml para o SAT.
      * \image html Fluxograma01.JPG
      * \image html Fluxograma02.JPG
      */

     /*!
      * \ingroup s0
      * \brief AbreCupomVenda
      * Esssa função deve ser a primeira a ser chamada pela aplicação para iniciar a criação do xml de venda para o SAT
      *
      * \param path_file
      * Caminho absoluto onde o arquivo xml será gerado.\n
      * EX:\n
      * > C:/sat/venda_0001.xml
      *
      *  \param versaoDadosEnt
      * Versão do leiautedo arquivo dedados do AC. (Ex: 0.07 ou 0.08).\n
      * > <b>TAG:</b> A03\n
      * > <b>Parametro obrigatório</b>\n
      * > <b>Tipo:</b> Alfanumérico\n
      * > <b>Tamanho:</b> 1-4 \n
      * > <b>Casas decimais:</b> 2\n
      *
      * \param CNPJ_SH
      * CNPJ Software House.\n
      * Deve ser informado apenas números. Caracteres (ponto, barra, hífen, etc.) serão removidos.\n
      * Caso o CNPJ tenha menos que 14 digitos a tag será preenchida com 0 não significativos.\n
      * Nos casos de teste fim-a-fim de ativação, completar com 14 dígitos “0”(zero).\n
      * > <b>TAG:</b> B11\n
      * > <b>Parametro obrigatório</b>\n
      * > <b>Tipo:</b> Numérico\n
      * > <b>Tamanho:</b> 14\n
      *
      * \param signAC
      * Assinatura do Aplicativo Comercial\n
      * Assinatura de (CNPJ Software House + CNPJ Emitente) que gerou o CF-e.\n
      * Nos casos de teste fim-a-fim de ativação, completar com 344 dígitos “0”(zero).\n
      * > <b>TAG:</b> B12\n
      * > <b>Parametro obrigatório</b>\n
      * > <b>Tipo:</b> Alfanumérico\n
      * > <b>Tamanho:</b> 1-344 \n
      *
      * \param numeroCaixa
      * Número de 0 a 999 referente ao Caixa em que o SAT está conectado.\n
      * > <b>TAG:</b> B14\n
      * > <b>Parametro obrigatório</b>\n
      * > <b>Tipo:</b> Numérico\n
      * > <b>Tamanho:</b> 3 \n
      *
      * \param CNPJ_emit
      * CNPJ do emitente.\n
      * Deve ser informado apenas números. Caracteres (ponto, barra, hífen, etc.) serão removidos.\n
      * Caso o CNPJ tenha menos que 14 digitos a tag será preenchida com 0 não significativos.\n
      * > <b>TAG:</b> C02\n
      * > <b>Parametro obrigatório</b>\n
      * > <b>Tipo:</b> Numérico\n
      * > <b>Tamanho:</b> 14 \n
      *
      * \param IE
      * Deve ser informado apenas caracteres alfanumérico. Caracteres (ponto, barra, hífen, etc.) serão removidos.\n
      * Caso IE tenha menos que 12 digitos a tag será preenchida com espaços a direita.\n
      * > <b>TAG:</b> C12\n
      * > <b>Parametro obrigatório</b>\n
      * > <b>Tipo:</b> Numérico\n
      * > <b>Tamanho:</b> 2-14 \n
      *
      * \param IM
      * Inscrição Municipal.\n
      * Este campo deve ser informado, quando ocorrer a emissão de CF-e conjugada, com prestação
      * de serviços sujeitos ao ISSQN e fornecimento de peças sujeitos ao ICMS.\n
      * > <b>TAG:</b> C13\n
      * > Essa TAG não é obrigatória e para que não seja incluida no XML deve-se passar parametro vazio.\n
      * > <b>Tipo:</b> Numérico\n
      * > <b>Tamanho:</b> 1-15 \n
      *
      * \param cRegTribISSQN
      * Regime Especial de Tributação do ISSQN\n
      * 1 - Microempresa Municipal;\n
      * 2 - Estimativa;\n
      * 3 - Sociedade de Profissionais;\n
      * 4 - Cooperativa;\n
      * 5 - Microempresário Individual(MEI);\n
      * > <b>TAG:</b> C15\n
      * > Essa TAG não é obrigatória e para que não seja incluida no XML deve-se passar parametro vazio.\n
      * > <b>Tipo:</b> Numérico\n
      * > <b>Tamanho:</b> 1 \n
      *
      * \param indRatISSQN
      * Indicador de rateio do Desconto sobre subtotal entre itens sujeitos à tributação pelo ISSQN.
      * Informa se o Desconto sobre subtotal deve ser rateado entre os itens sujeitos à tributação pelo ISSQN.\n
      * 'S' - Desconto sobre subtotal será rateado entre os itens sujeitos ao ISSQN.\n
      * 'N' - Desconto sobre subtotal não será rateado entre os itens sujeitos ao ISSQN.\n
      * > <b>TAG:</b> C16\n
      * > <b>Parametro obrigatório</b>\n
      * > <b>Tipo:</b> Alfanumérico\n
      * > <b>Tamanho:</b> 1 \n
      *
      * \param CNPJ_dest
      * CNPJ do destinatário.\n
      * Deve ser informado apenas números. Caracteres (ponto, barra, hífen, etc.) serão removidos.\n
      * Caso o CNPJ tenha menos que 14 digitos a tag será preenchida com 0 não significativos.\n
      * > <b>TAG:</b> E02\n
      * > Essa TAG não é obrigatória e para que não seja incluida no XML deve-se passar parametro vazio.\n
      * > <b>Tipo:</b> Numérico\n
      * > <b>Tamanho:</b> 14 \n
      *
      * \param CPF_dest
      * CPF do destinatário.\n
      * Deve ser informado apenas números. Caracteres (ponto, barra, etc.) serão removidos.\n
      * Caso o CPF tenha menos que 11 digitos a tag será preenchida com 0 não significativos.\n
      * > <b>TAG:</b> E03\n
      * > Essa TAG não é obrigatória e para que não seja incluida no XML deve-se passar parametro vazio.\n
      * > <b>Tipo:</b> Numérico\n
      * > <b>Tamanho:</b> 11 \n
      * * Caso o CNPJ do destinatário tenha sido informado, a tag CPF não será incluida.\n
      *
      * \param xNome_dest
      * Razão Social ou Nome do destinatário
      * > <b>TAG:</b> E04\n
      * > Essa TAG não é obrigatória e para que não seja incluida no XML deve-se passar parametro vazio.\n
      * > <b>Tipo:</b> Alfanumérico\n
      * > <b>Tamanho:</b> 2-60 \n
      *
      * \return
      * O retorno da função é do tipo numérico.\n
      * A função bem sucedida deve retornar 0.\n
      * * Para mais informações consulte a sessão de codigo de erros.
      */
     ///@cond
     E1_SATSHARED_EXPORT STDCALL
     ///@endcond
     int AbreCupomVenda(const char *path_file,
                        const char *versaoDadosEnt,
                        const char *CNPJ_SH,
                        const char *signAC,
                        int numeroCaixa,
                        const char *CNPJ_emit,
                        const char *IE,
                        const char *IM,
                        const char *cRegTribISSQN,
                        const char *indRatISSQN,
                        const char *CNPJ_dest,
                        const char *CPF_dest,
                        const char *xNome_dest);

     /*!
      * \ingroup s0
      * \brief AbreCupomVenda2
      * Essa função cria o arquivo de vanda organizando os arquivos a partir do diretório informado em 'path_root'.\n
      *
      * A Estrutura criada deve ser: /XML/SAT/VENDA/yyyy/MM/dd/yyyyMMddhhmmss.xml\n
      * onde:
      * > yyyy = ANO\n
      * > MM = MÊS\n
      * > dd = DIA\n
      * > hh = HORA\n
      * > mm = MINUTO\n
      * > ss = SEGUNDO\n
      *
      * \param path_root
      * Caminho raiz onde a estrutura de pasta e o arquivo será gerado.
      * \note
      * Os demais parametros são identicos aos da função #AbreCupomVenda
      *
      * \return
      * O retorno dessa função deve ser o caminho absoluto onde o arquivo foi gerado.
      */
     ///@cond
     E1_SATSHARED_EXPORT STDCALL
     ///@endcond
     char *AbreCupomVenda2(const char *path_root,
                           const char *versaoDadosEnt,
                           const char *CNPJ_SH,
                           const char *signAC,
                           int numeroCaixa,
                           const char *CNPJ_emit,
                           const char *IE,
                           const char *IM,
                           const char *cRegTribISSQN,
                           const char *indRatISSQN,
                           const char *CNPJ_dest,
                           const char *CPF_dest,
                           const char *xNome_dest);

     /*!
      * \ingroup s0
      * \brief InformaEntrega -
      * Função para identificação do local de entrega. Informar apenas no caso de entrega da mercadoria em domicílio.
      *
      * \param path_file
      * Caminho absoluto onde o arquivo xml será gerado.\n
      * EX:\n
      * > C:/sat/venda_0001.xml
      *
      * \param xLgr
      * Logradouro
      * > <b>TAG:</b> G02\n
      * > <b>Parametro obrigatório</b>\n
      * > <b>Tipo:</b> Alfanumérico\n
      * > <b>Tamanho:</b> 2-60 \n
      *
      * \param nro
      * Número
      * > <b>TAG:</b> G03\n
      * > <b>Parametro obrigatório</b>\n
      * > <b>Tipo:</b> Numérico\n
      * > <b>Tamanho:</b> 1-60 \n
      *
      * \param xCpl
      * Complemento
      * > <b>TAG:</b> G04\n
      * > Essa TAG não é obrigatória e para que não seja incluida no XML deve-se passar parametro vazio.\n
      * > <b>Tipo:</b> Alfanumérico\n
      * > <b>Tamanho:</b> 1-60 \n
      *
      * \param xBairro
      * Bairro
      * > <b>TAG:</b> G05\n
      * > <b>Parametro obrigatório</b>\n
      * > <b>Tipo:</b> Alfanumérico\n
      * > <b>Tamanho:</b> 1-60 \n
      *
      * \param xMun
      * Nome do município
      * > <b>TAG:</b> G06\n
      * > <b>Parametro obrigatório</b>\n
      * > <b>Tipo:</b> Alfanumérico\n
      * > <b>Tamanho:</b> 2-60 \n
      *
      * \param UF
      * Sigla da UF
      * > <b>TAG:</b> G07\n
      * > <b>Parametro obrigatório</b>\n
      * > <b>Tipo:</b> Alfanumérico\n
      * > <b>Tamanho:</b> 2 \n
      *
      * \return
      * O retorno da função é do tipo numérico.\n
      * A função bem sucedida deve retornar 0.\n
      * * Para mais informações consulte a sessão de codigo de erros.
      */
     ///@cond
     E1_SATSHARED_EXPORT STDCALL
     ///@endcond
     int InformaEntrega(const char *path_file, const char *xLgr, const char *nro, const char *xCpl, const char *xBairro, const char *xMun, const char *UF);


     /*!
      * \ingroup s0
      * \brief InformaProduto
      * Adiciona produto ao xml de venda. 500 ocorrencias no maximo.
      *
      * \param path_file
      * Caminho absoluto onde o arquivo xml será gerado.\n
      * EX:\n
      * > C:/sat/venda_0001.xml
      *
      * \param cProd
      * Código do produto ou serviço, interno do contribuinte.
      * > <b>TAG:</b> I02\n
      * > <b>Parametro obrigatório</b>\n
      * > <b>Tipo:</b> Alfanumérico\n
      * > <b>Tamanho:</b> 1-60 \n
      *
      * \param cEAN
      * GTIN (Global Trade Item Number) do produto, antigo código EAN ou código de barras.\n
      * Preencher com o código GTIN-8, GTIN-12, GTIN-13 ou GTIN-14 (antigos códigos EAN, UPC e\n
      * DUN-14), não informar o conteúdo da TAG em caso de o produto não possuir este código.
      * > <b>TAG:</b> I03\n
      * > Essa TAG não é obrigatória e para que não seja incluida no XML deve-se passar parametro vazio.\n
      * > <b>Tipo:</b> Alfanumérico\n
      * > <b>Tamanho:</b> 8, 12, 13, 14\n
      *
      * \param xProd
      * Descrição detalhada do produto para possibilitar a sua perfeita identificação.
      * > <b>TAG:</b> I04\n
      * > <b>Parametro obrigatório</b>\n
      * > <b>Tipo:</b> Alfanumérico\n
      * > <b>Tamanho:</b> 1-120 \n
      *
      * \param NCM
      * Código NCM (8 posições), informar o gênero (posição do capítulo do NCM) quando a
      * operação não for de comércio exterior (importação/ exportação) ou o produto não seja tributado
      * pelo IPI. Em caso de serviço informar o código 99.
      * > <b>TAG:</b> I05\n
      * > Essa TAG não é obrigatória e para que não seja incluida no XML deve-se passar parametro vazio.\n
      * > <b>Tipo:</b> Alfanumérico\n
      * > <b>Tamanho:</b> 2, 8.\n
      *
      * \param CEST
      * Código Especificador da Substituição Tributária
      * Código CEST que identifica a mercadoria sujeita aos regimes de substituição tributária e de
      * antecipação do recolhimento do imposto.
      * > <b>TAG:</b> I05w\n
      * > Essa TAG não é obrigatória e para que não seja incluida no XML deve-se passar parametro vazio.\n
      * > <b>Tipo:</b> Numérico\n
      * > <b>Tamanho:</b> 7\n
      *
      * \param CFOP
      * Código Fiscal de Operações e Prestações
      * > <b>TAG:</b> I06\n
      * > <b>Parametro obrigatório</b>\n
      * > <b>Tipo:</b> Numérico\n
      * > <b>Tamanho:</b> 4 \n
      *
      * \param uCom
      * Unidade Comercial
      * Informar a unidade de comercialização do produto. No caso de combustíveis, utilizar a unidade
      * de medida da codificação de produtos do Sistema de Informações de Movimentação de produtos -
      * SIMP (http://www.anp.gov.br/simp).
      * > <b>TAG:</b> I07\n
      * > <b>Parametro obrigatório</b>\n
      * > <b>Tipo:</b> Alfanumérico\n
      * > <b>Tamanho:</b> 1-6 \n
      *
      * \param qCom
      * Quantidade Comercial
      * Informar a quantidade de comercialização do produto.
      * > <b>TAG:</b> I08\n
      * > <b>Parametro obrigatório</b>\n
      * > <b>Tipo:</b> Numérico\n
      * > <b>Tamanho:</b> 5-15 \n
      * > <b>Casas decimais:</b> 4\n
      *
      * \param vUnCom
      * Valor Unitário de Comercialização.
      * Informar o valor unitário de comercialização do produto.
      * > <b>TAG:</b> I09\n
      * > <b>Parametro obrigatório</b>\n
      * > <b>Tipo:</b> Numérico\n
      * > <b>Tamanho:</b> 3-15\n
      * > <b>Casas decimais:</b> 3\n
      * * Deve ser informado com 3 decimais no caso de combustíveis (Art. 20, da Resolução ANP nº 41/2013),
      *  para os demais com 2 decimais.
      *
      * \param indRegra
      * Regra de cálculo
      * Indicador da regra de cálculo utilizada para Valor Bruto dos Produtos e Serviços:
      * A - Arredondamento
      * T - Truncamento
      * > <b>TAG:</b> I11\n
      * > <b>Parametro obrigatório</b>\n
      * > <b>Tipo:</b> Alfanumérico\n
      * > <b>Tamanho:</b> 1 \n
      *
      * \param vDesc
      * Valor do Desconto sobre item
      * Valor do desconto incidente sobre o valor do item com duas casas decimais
      * > <b>TAG:</b> I12\n
      * > Essa TAG não é obrigatória e para que não seja incluida no XML deve-se passar parametro vazio.\n
      * > <b>Tipo:</b> Numérico\n
      * > <b>Tamanho:</b> 3-15 \n
      * > <b>Casas decimais:</b> 2\n
      *
      * \param vOutro
      * Outras despesas acessórias sobre item
      * Valor de acréscimos sobre valor do item
      * > <b>TAG:</b> I13\n
      * > Essa TAG não é obrigatória e para que não seja incluida no XML deve-se passar parametro vazio.\n
      * > <b>Tipo:</b> Numérico\n
      * > <b>Tamanho:</b> 3-15 \n
      * > <b>Casas decimais:</b> 2\n
      *
      * \return
      * O retorno dessa função será o nItem do produto adicionado ao XML
      * Em casos de erros será retornado um valor negativo com base na sessão códigos de erros.
      */
     ///@cond
     E1_SATSHARED_EXPORT STDCALL
     ///@endcond
     int InformaProduto(const char *path_file,
                        const char *cProd,
                        const char *cEAN,
                        const char *xProd,
                        const char *NCM,
                        const char *CEST,
                        const char *CFOP,
                        const char *uCom,
                        const char *qCom,
                        const char *vUnCom,
                        const char *indRegra,
                        const char *vDesc,
                        const char *vOutro);

     /*!
      * \ingroup s0
      * \brief InformaObsFiscoDet
      * Grupo do campo de uso livre do Fisco com 10 ocorrencias no maximo.
      *
      * \param path_file
      * Caminho absoluto onde o arquivo xml será gerado.\n
      * EX:\n
      * > C:/sat/venda_0001.xml
      *
      * \param nItem
      * Identificação do produto ao qual será acrecentado a tag obsFiscoDet.
      * Este parametro é retornado da função #informaProduto
      * > <b>Parametro obrigatório</b>
      *
      * \param xCampoDet
      * Identificação do campo
      * No caso de combustíveis, preencher com “Cod. Produto ANP”
      * > <b>TAG:</b> I18\n
      * > <b>Parametro obrigatório</b>
      * > <b>Tipo:</b> Alfanumérico\n
      * > <b>Tamanho:</b> 1-20 \n
      * * Apenas para o layout 0.07
      * * No caso de produtos sujeitos à substituição tributária, preencher com “Cod. CEST”.
      *
      * \param xTextoDet
      * Conteúdo do campo. No caso de combustíveis e/ou lubrificantes,
      * quando informado “CFOP 5656 – Venda de combustível ou lubrificante adquirido ou recebido
      * de terceiros destinado a consumidor ou usuário final”, informar código de produto do
      * Sistema de Informações de Movimentação de produtos - SIMP (http://www.anp.gov.br/simp).
      * Informar 999999999 se o produto não possuir código de produto ANP.
      * > <b>TAG:</b> I19\n
      * > <b>Parametro obrigatório</b>
      * > <b>Tipo:</b> Alfanumérico\n
      * > <b>Tamanho:</b> 1-60 \n
      * * Apenas para o layout 0.07:
      * * No caso de produtos sujeitos à substituição tributária, informar o Código CEST.,
      * conforme definido no Convênio ICMS 92, de 20-08-2015.
      *
      *
      * \return
      * O retorno da função é do tipo numérico.\n
      * A função bem sucedida deve retornar 0.\n
      * * Para mais informações consulte a sessão de codigo de erros.
      */
     ///@cond
     E1_SATSHARED_EXPORT STDCALL
     ///@endcond
     int InformaObsFiscoDet(const char *path_file, int nItem, const char *xCampoDet, const char *xTextoDet);

     /*!
      * \ingroup s0
      *
      * \brief IformaImposto
      * Abre a tag imposto - M01.
      * A automação não é obrigada a chamar essa função antes de informar os demais impostos,
      * apenas quando for necessário informar vItem12741
      *
      * \param path_file
      * Caminho absoluto onde o arquivo xml será gerado.\n
      * EX:\n
      * > C:/sat/venda_0001.xml
      *
      * \param nItem
      * Identificação do produto ao qual será acrecentado a tag imposto.
      * Este parametro é retornado da função #informaProduto
      * > <b>Parametro obrigatório</b>
      *
      * \param vItem12741
      * Valor aproximado dos tributos do Produto ou serviço – Lei 12741/12.
      * Valor aproximado dos tributos do produto ou serviço, declarado pelo emitente, conforme Lei
      * 12741/2012.
      * Valor deve ser maior ou igual a zero. Campo de preenchimento:
      * - opcional, caso o contribuinte opte por informar o valor em painel afixado no estabelecimento,
      * conforme artigo 2º, §2º da referida lei.
      * - obrigatório, caso o contribuinte não opte por informar o valor em painel afixado no
      * estabelecimento, conforme artigo 2º, §2º da referida lei.
      * > <b>TAG:</b> M02\n
      * > Essa TAG não é obrigatória e para que não seja incluida no XML deve-se passar parametro vazio.\n
      * > <b>Tipo:</b> Numérico\n
      * > <b>Tamanho:</b> 3-15 \n
      * > <b>Casas decimais:</b> 2\n
      *
      * \return
      * O retorno da função é do tipo numérico.\n
      * A função bem sucedida deve retornar 0.\n
      * * Para mais informações consulte a sessão de codigo de erros.
      */
     ///@cond
     E1_SATSHARED_EXPORT STDCALL
     ///@endcond
     int InformaImposto(const char *path_file, int nItem, const char *vItem12741);

     /*!
      * \ingroup s0
      *
      * \brief InformaICMS00
      * Cria Tag ICMS e ICMS00
      * CampocRegTrib=3 – Regime Normal
      * Grupo de Tributação do ICMS= 00, 20, 90
      * Tributação do ICMS:
      * > 00 – Tributada integralmente
      * > 20 - Com redução de base decálculo
      * > 90 - Outros
      *
      * \param path_file
      * Caminho absoluto onde o arquivo xml será gerado.\n
      * EX:\n
      * > C:/sat/venda_0001.xml
      *
      * \param nItem
      * Identificação do produto ao qual será acrecentado a tag ICMS00.
      * Este parametro é retornado da função #informaProduto
      * > <b>Parametro obrigatório</b>
      *
      * \param Orig
      * Origem da mercadoria.
      * Origem da mercadoria:\n
      * 0 - Nacional, exceto as indicadas nos códigos 3, 4, 5 e 8;\n
      * 1 - Estrangeira - Importação direta, exceto a indicada no código 6;\n
      * 2 - Estrangeira - Adquirida no mercado interno, exceto a indicada no código 7;\n
      * 3 - Nacional, mercadoria ou bem com Conteúdo de Importação superior a 40% (quarenta por
      * cento) e inferior ou igual a 70% (setenta por cento);\n
      * 4 - Nacional, cuja produção tenha sido feita em conformidade com os processos produtivos
      * básicos de que tratam as legislações citadas nos Ajustes;\n
      * 5 - Nacional, mercadoria ou bem com Conteúdo de Importação inferior ou igual a 40%;\n
      * 6 - Estrangeira - Importação direta, sem similar nacional, constante em lista da CAMEX;\n
      * 7 - Estrangeira - Adquirida no mercado interno, sem similar nacional, constante em lista da
      * CAMEX;\n
      * 8 – Nacional, mercadoria ou bem com Conteúdo de Importação superior a 70% (setenta por
      * cento).\n
      * > <b>TAG:</b> N06\n
      * > <b>Parametro obrigatório</b>\n
      * > <b>Tipo:</b> Numérico\n
      * > <b>Tamanho:</b> 1\n
      *
      * \param CST
      * Tributação do ICMS = 00, 20, 90
      * Tributação do ICMS:
      * 00 – Tributada integralmente
      * 20 - Com redução de base de cálculo
      * 90 - Outros
      * > <b>TAG:</b> N07\n
      * > <b>Parametro obrigatório</b>\n
      * > <b>Tipo:</b> Numérico\n
      * > <b>Tamanho:</b> 2\n
      *
      * \param pICMS
      * Alíquota efetiva do imposto
      * > <b>TAG:</b> N08\n
      * > <b>Parametro obrigatório</b>\n
      * > <b>Tipo:</b> Numérico\n
      * > <b>Tamanho:</b> 3-15\n
      * > <b>Casas decimais:</b> 2\n
      *
      * \return
      * O retorno da função é do tipo numérico.\n
      * A função bem sucedida deve retornar 0.\n
      * * Para mais informações consulte a sessão de codigo de erros.
      */
     ///@cond
     E1_SATSHARED_EXPORT STDCALL
     ///@endcond
     int InformaICMS00(const char *path_file, int nItem, int Orig, const char *CST, const char *pICMS );

     /*!
      * \ingroup s0
      *
      * \brief InformaICMS40
      * Cria Tag ICMS e ICMS40
      * Campo cRegTrib=3 – Regime Normal Grupo de Tributação do
      * ICMS = 40, 41, 60
      * Tributação do ICMS:
      * 40 - Isenta
      * 41 - Não tributada
      * 60 - ICMS cobrado anteriormente por substituição tributária
      *
      * \param path_file
      * Caminho absoluto onde o arquivo xml será gerado.\n
      * EX:\n
      * > C:/sat/venda_0001.xml
      *
      * \param nItem
      * Identificação do produto ao qual será acrecentado a tag ICMS40.
      * Este parametro é retornado da função #informaProduto
      * > <b>Parametro obrigatório</b>
      *
      * \param Orig
      * Origem da mercadoria
      * Origem da mercadoria:\n
      * 0 - Nacional, exceto as indicadasnos códigos 3, 4, 5 e 8;\n
      * 1 - Estrangeira - Importação direta, exceto a indicada no código 6;\n
      * 2 - Estrangeira - Adquirida no mercado interno, exceto a indicada no código 7;\n
      * 3 - Nacional, mercadoria ou bem com Conteúdo de Importação superior a 40% (quarenta por
      * cento) e inferior ou igual a 70% (setenta por cento);\n
      * 4 - Nacional, cuja produção tenha sido feita em conformidade com os processos produtivos
      * básicos de que tratam as legislações citadas nos Ajustes;\n
      * 5 - Nacional, mercadoria ou bem com Conteúdo de Importação inferior ou igual a 40%;\n
      * 6 - Estrangeira - Importação direta, sem similar nacional, constante em lista da CAMEX;\n
      * 7 - Estrangeira - Adquirida no mercado interno, sem similar nacional, constante em lista da
      * CAMEX;\n
      * 8 – Nacional, mercadoria ou bem com Conteúdo de Importação superior a 70% (setenta por
      * cento).\n
      *
      * > <b>TAG:</b> N06\n
      * > <b>Parametro obrigatório</b>\n
      * > <b>Tipo:</b> Numérico\n
      * > <b>Tamanho:</b> 1\n
      *
      * \param CST
      * Tributação do ICMS = 40, 41, 60
      * Tributação do ICMS:
      * 40 - Isenta
      * 41 - Não tributada
      * 60 - ICMS cobrado anteriormente por substituição tributária
      * > <b>TAG:</b> N07\n
      * > <b>Parametro obrigatório</b>\n
      * > <b>Tipo:</b> Numérico\n
      * > <b>Tamanho:</b> 2\n
      *
      * \return
      * O retorno da função é do tipo numérico.\n
      * A função bem sucedida deve retornar 0.\n
      * * Para mais informações consulte a sessão de codigo de erros.
      */
     ///@cond
     E1_SATSHARED_EXPORT STDCALL
     ///@endcond
     int InformaICMS40(const char *path_file, int nItem, int Orig, const char *CST);

     /*!
      * \ingroup s0
      * \brief InformaICMSSN102
      * Cria TAG ICMS e ICMSSN102
      * Campo cRegTrib=1 – Simples Nacional e CSOSN=102, 300, 400, 500
      * As funções do grupo ICMS são mutuamente exclusivo com ISSQN,
      * isto é se ISSQN for informado o grupo ICMS não será informado e vice-versa.
      *
      * \param path_file
      * Caminho absoluto onde o arquivo xml será gerado.\n
      * EX:\n
      * > C:/sat/venda_0001.xml
      *
      * \param nItem
      * Identificação do produto ao qual será acrecentado a tag ICMSSN102.
      * Este parametro é retornado da função #informaProduto
      * > <b>Parametro obrigatório</b>
      *
      * \param Orig
      * Origem da mercadoria
      * Origem da mercadoria:\n
      * 0 - Nacional, exceto as indicadasnos códigos 3, 4, 5 e 8;\n
      * 1 - Estrangeira - Importação direta, exceto a indicada no código 6;\n
      * 2 - Estrangeira - Adquirida no mercado interno, exceto a indicada no código 7;\n
      * 3 - Nacional, mercadoria ou bem com Conteúdo de Importação superior a 40% (quarenta por
      * cento) e inferior ou igual a 70% (setenta por cento);\n
      * 4 - Nacional, cuja produção tenha sido feita em conformidade com os processos produtivos
      * básicos de que tratam as legislações citadas nos Ajustes;\n
      * 5 - Nacional, mercadoria ou bem com Conteúdo de Importação inferior ou igual a 40%;\n
      * 6 - Estrangeira - Importação direta, sem similar nacional, constante em lista da CAMEX;\n
      * 7 - Estrangeira - Adquirida no mercado interno, sem similar nacional, constante em lista da
      * CAMEX;\n
      * 8 – Nacional, mercadoria ou bem com Conteúdo de Importação superior a 70% (setenta por
      * cento).\n
      * > <b>TAG:</b> N06\n
      * > <b>Parametro obrigatório</b>\n
      * > <b>Tipo:</b> Numérico\n
      * > <b>Tamanho:</b> 1\n
      *
      * \param CSOSN
      * Código de Situação da peração – Simples Nacional
      * 102 - Tributada pelo Simples Nacional sem permissão de crédito.
      * 300 – Imune
      * 400 – Não tributada
      * 500 – ICMS cobrado anteriormente por substituição tributária (substituído) ou por
      * antecipação.
      * > <b>TAG:</b> N10\n
      * > <b>Parametro obrigatório</b>\n
      * > <b>Tipo:</b> Numérico\n
      * > <b>Tamanho:</b> 3\n
      *
      * \return
      * O retorno da função é do tipo numérico.\n
      * A função bem sucedida deve retornar 0.\n
      * * Para mais informações consulte a sessão de codigo de erros.
      */
     ///@cond
     E1_SATSHARED_EXPORT STDCALL
     ///@endcond
     int InformaICMSSN102(const char *path_file, int nItem, int Orig, const char *CSOSN);

     /*!
      * \ingroup s0
      *
      * \brief InformaICMSSN900
      * Cria a tag ICMS e ICMSSN900\n
      * Campo cRegTrib=1 – Simples Nacional e CSOSN=900
      *
      * \param path_file
      * Caminho absoluto onde o arquivo xml será gerado.\n
      * EX:\n
      * > C:/sat/venda_0001.xml
      *
      * \param nItem
      * Identificação do produto ao qual será acrecentado a tag ICMSSN900.\n
      * Este parametro é retornado da função #informaProduto
      * > <b>Parametro obrigatório</b>
      *
      * \param Orig
      * Origem da mercadoria\n
      * Origem da mercadoria:\n
      * 0 - Nacional, exceto as indicadasnos códigos 3, 4, 5 e 8;\n
      * 1 - Estrangeira - Importação direta, exceto a indicada no código 6;\n
      * 2 - Estrangeira - Adquirida no mercado interno, exceto a indicada no código 7;\n
      * 3 - Nacional, mercadoria ou bem com Conteúdo de Importação superior a 40% (quarenta por
      * cento) e inferior ou igual a 70% (setenta por cento);\n
      * 4 - Nacional, cuja produção tenha sido feita em conformidade com os processos produtivos
      * básicos de que tratam as legislações citadas nos Ajustes;\n
      * 5 - Nacional, mercadoria ou bem com Conteúdo de Importação inferior ou igual a 40%;\n
      * 6 - Estrangeira - Importação direta, sem similar nacional, constante em lista da CAMEX;\n
      * 7 - Estrangeira - Adquirida no mercado interno, sem similar nacional, constante em lista da
      * CAMEX;\n
      * 8 – Nacional, mercadoria ou bem com Conteúdo de Importação superior a 70% (setenta por
      * cento).\n
      * > <b>TAG:</b> N06\n
      * > <b>Parametro obrigatório</b>\n
      * > <b>Tipo:</b> Numérico\n
      * > <b>Tamanho:</b> 1\n
      *
      * \param CSOSN
      * Código de Situação da Operação – SIMPLES NACIONAL\n
      * Tributação pelo ICMS 900 - Outros\n
      * > <b>TAG:</b> N10\n
      * > <b>Parametro obrigatório</b>\n
      * > <b>Tipo:</b> Numérico\n
      * > <b>Tamanho:</b> 3\n
      *
      * \param pICMS
      * Alíquota efetiva do imposto\n
      * > <b>TAG:</b> N08\n
      * > <b>Parametro obrigatório</b>\n
      * > <b>Tipo:</b> Numérico\n
      * > <b>Tamanho:</b> 3-5\n
      * > <b>Casas decimais:</b> 2\n
      *
      * \return
      * O retorno da função é do tipo numérico.\n
      * A função bem sucedida deve retornar 0.\n
      * * Para mais informações consulte a sessão de codigo de erros.
      */
     ///@cond
     E1_SATSHARED_EXPORT STDCALL
     ///@endcond
     int InformaICMSSN900(const char *path_file, int nItem, int Orig, const char *CSOSN, const char *pICMS);

     /*!
      * \ingroup s0
      *
      * \brief InformaPISAliq
      * Cria TAG PIS e PISAliq. \n
      * Grupo de PIS tributado pela alíquota.
      *
      * \param path_file
      * Caminho absoluto onde o arquivo xml será gerado.\n
      * EX:\n
      * > C:/sat/venda_0001.xml

      * \param nItem
      * Identificação do produto ao qual será acrecentado a tag PISAliq.
      * Este parametro é retornado da função #informaProduto
      * > <b>Parametro obrigatório</b>
      *
      * \param CST
      * Código de Situação Tributária do PIS.\n
      * 01 – Operação Tributável (base de cálculo = valor da operação alíquota normal (cumulativo/não cumulativo));\n
      * 02 - Operação Tributável (base de cálculo = valor da operação (alíquota diferenciada));\n
      * 05 - Operação Tributável por Substituição Tributária;\n
      * > <b>TAG:</b> Q07\n
      * > <b>Parametro obrigatório</b>\n
      * > <b>Tipo:</b> Numérico\n
      * > <b>Tamanho:</b> 2\n
      *
      * \param vBC
      * Valor da Base de Cálculo do PIS.
      * > <b>TAG:</b> Q08\n
      * > <b>Parametro obrigatório</b>\n
      * > <b>Tipo:</b> Numérico\n
      * > <b>Tamanho:</b> 3-15\n
      * > <b>Casas decimais:</b> 2\n
      *
      * \param pPIS
      * Alíquota do PIS (em percentual).\n
      * Ex. Se a alíquota for 0,65% informar 0,0065
      * > <b>TAG:</b> Q09\n
      * > <b>Parametro obrigatório</b>\n
      * > <b>Tipo:</b> Numérico\n
      * > <b>Tamanho:</b> 5\n
      * > <b>Casas decimais:</b> 4\n
      *
      * \return
      * O retorno da função é do tipo numérico.\n
      * A função bem sucedida deve retornar 0.\n
      * * Para mais informações consulte a sessão de codigo de erros.
      */
     ///@cond
     E1_SATSHARED_EXPORT STDCALL
     ///@endcond
     int InformaPISAliq(const char *path_file, int nItem, const char *CST, const char *vBC, const char *pPIS);

     /*!
      * \ingroup s0
      *
      * \brief InformaPISQtde
      * Cria TAG PIS e PISQtde.\n
      * Grupo de PIS tributado por Qtde.
      *
      * \param path_file
      * Caminho absoluto onde o arquivo xml será gerado.\n
      * EX:\n
      * > C:/sat/venda_0001.xml
      *
      * \param nItem
      * Identificação do produto ao qual será acrecentado a tag PISQtde.\n
      * Este parametro é retornado da função #informaProduto
      * > <b>Parametro obrigatório</b>
      *
      * \param CST
      * Código de Situação Tributária do PIS.
      * 03 - Operação Tributável (base de cálculo = quantidade vendida x alíquota por unidade de
      * produto);
      * > <b>TAG:</b> Q07\n
      * > <b>Parametro obrigatório</b>\n
      * > <b>Tipo:</b> Numérico\n
      * > <b>Tamanho:</b> 2\n
      *
      * \param qBCProd
      * Quantidade Vendida.
      * > <b>TAG:</b> Q11\n
      * > <b>Parametro obrigatório</b>\n
      * > <b>Tipo:</b> Numérico\n
      * > <b>Tamanho:</b> 3-16\n
      * > <b>Casas decimais:</b> 4\n

      * \param vAliqProd
      * Alíquota do PIS (em reais)
      * > <b>TAG:</b> Q12\n
      * > <b>Parametro obrigatório</b>\n
      * > <b>Tipo:</b> Numérico\n
      * > <b>Tamanho:</b> 3-15\n
      * > <b>Casas decimais:</b> 4\n
      *
      * \return
      * O retorno da função é do tipo numérico.\n
      * A função bem sucedida deve retornar 0.\n
      * * Para mais informações consulte a sessão de codigo de erros.
      */
     ///@cond
     E1_SATSHARED_EXPORT STDCALL
     ///@endcond
     int InformaPISQtde(const char *path_file, int nItem, const char *CST, const char *qBCProd, const char *vAliqProd);

     /*!
      * \ingroup s0
      *
      * \brief InformaPISNT
      * Cria TAG PIS e PISNT.\n
      * Grupo de PIS não tributado.
      *
      * \param path_file
      * Caminho absoluto onde o arquivo xml será gerado.\n
      * EX:\n
      * > C:/sat/venda_0001.xml
      *
      * \param nItem
      * Identificação do produto ao qual será acrecentado a tag PISNT.\n
      * Este parametro é retornado da função #informaProduto
      * > <b>Parametro obrigatório</b>
      *
      * \param CST
      * Código de Situação Tributária do PIS
      * 04 - Operação Tributável(tributação monofásica (alíquotazero));\n
      * 06 - Operação Tributável(alíquota zero);\n
      * 07 - Operação Isenta da Contribuição;\n
      * 08 - Operação Sem Incidência da Contribuição;\n
      * 09 - Operação com Suspensão da Contribuição;\n
      * > <b>TAG:</b> Q07\n
      * > <b>Parametro obrigatório</b>\n
      * > <b>Tipo:</b> Numérico\n
      * > <b>Tamanho:</b> 2\n
      *
      * \return
      * O retorno da função é do tipo numérico.\n
      * A função bem sucedida deve retornar 0.\n
      * * Para mais informações consulte a sessão de codigo de erros.
      */
     ///@cond
     E1_SATSHARED_EXPORT STDCALL
     ///@endcond
     int InformaPISNT(const char *path_file, int nItem, const char *CST);

     /*!
      * \ingroup s0
      *
      * \brief InformaPISSN
      * Cria TAG PIS e PISSN.\n
      * Grupo de PIS para contribuinte do SIMPLES NACIONAL
      *
      * \param path_file
      * Caminho absoluto onde o arquivo xml será gerado.\n
      * EX:\n
      * > C:/sat/venda_0001.xml
      *
      * \param nItem
      * Identificação do produto ao qual será acrecentado a tag PISSN.
      * Este parametro é retornado da função #informaProduto
      * > <b>Parametro obrigatório</b>
      *
      * \param CST
      * Código de Situação Tributária do PIS.\n
      * 49 - Outras Operações de saída;
      * > <b>TAG:</b> Q07\n
      * > <b>Parametro obrigatório</b>\n
      * > <b>Tipo:</b> Numérico\n
      * > <b>Tamanho:</b> 2\n
      *
      * \return
      * O retorno da função é do tipo numérico.\n
      * A função bem sucedida deve retornar 0.\n
      * * Para mais informações consulte a sessão de codigo de erros.
      */
     ///@cond
     E1_SATSHARED_EXPORT STDCALL
     ///@endcond
     int InformaPISSN(const char *path_file, int nItem, const char *CST);

     /*!
      * \ingroup s0
      *
      * \brief InformaPISOutr
      * Cria TAG PIS e PISOutr.\n
      * Grupo de PIS Outras Operações.\n
      * CST = 99\n
      * Informar campos para cálculo do PIS com aliquota em percentual
      * (Q08 e Q09) ou campos para PIS com aliquota em valor (Q11 e Q12).
      *
      * \param path_file
      * Caminho absoluto onde o arquivo xml será gerado.\n
      * EX:\n
      * > C:/sat/venda_0001.xml
      *
      * \param nItem
      * Identificação do produto ao qual será acrecentado a tag PISOutr.\n
      * Este parametro é retornado da função #informaProduto
      * > <b>Parametro obrigatório</b>
      *
      * \param grupo
      * Informar ZERO para campos do PIS com aliquota em percentual\n
      * ou UM para campos do PIS com aliquota em valor.
      * > <b>Parametro obrigatório</b>
      *
      * \param CST
      * Código de Situação Tributária do PIS.\n
      * 99 - Outras Operações;
      * > <b>TAG:</b> Q07\n
      * > <b>Parametro obrigatório</b>\n
      * > <b>Tipo:</b> Numérico\n
      * > <b>Tamanho:</b> 3-15\n
      * > <b>Casas decimais:</b> 2\n
      *
      * \param vBC_qBCProd
      * Caso o grupo informado seja ZERO o valor considerado será para TAG vBC (Q08).
      * > Q08 : Valor da Base de Cálculo do PIS\n
      * > <b>Tipo:</b> Numérico\n
      * > <b>Tamanho:</b> 3-15\n
      * > <b>Casas decimais:</b> 2\n
      * Caso o grupo informado seja UM o valor considerado será para TAG qBCProd(Q11).
      * > Q11 : Quantidade Vendida\n
      * > <b>Tipo:</b> Numérico\n
      * > <b>Tamanho:</b> 3-14\n
      * > <b>Casas decimais:</b> 4\n
      *
      * \param pPIS_vAliqProd
      * Caso o grupo informado seja ZERO o valor considerado será para TAG pPIS (Q09).
      * > Q09 : Alíquota do PIS (em percentual)\n
      * > <b>Tipo:</b> Numérico\n
      * > <b>Tamanho:</b> 5\n
      * > <b>Casas decimais:</b> 4\n
      * caso o grupo informado seja UM o valor considerado será para a TAG vAliqProd(Q12)
      * > Q12 : Alíquota do PIS (em reais).\n
      * > <b>Tipo:</b> Numérico\n
      * > <b>Tamanho:</b> 3-15\n
      * > <b>Casas decimais:</b> 4\n
      *
      * \return
      * O retorno da função é do tipo numérico.\n
      * A função bem sucedida deve retornar 0.\n
      * * Para mais informações consulte a sessão de codigo de erros.
      */
     ///@cond
     E1_SATSHARED_EXPORT STDCALL
     ///@endcond
     int InformaPISOutr(const char *path_file, int nItem, int grupo , const char *CST, const char *vBC_qBCProd, const char *pPIS_vAliqProd);

     /*!
      * \ingroup s0
      *
      * \brief InformaPISST
      * Grupo de PIS Substituição Tributária.\n
      * Informar campos para cálculo do PIS com aliquota em percentual
      * (R02 e R03) ou campos para PIS com aliquota em valor (R04 eR05).\n
      *
      * \param path_file
      * Caminho absoluto onde o arquivo xml será gerado.\n
      * EX:\n
      * > C:/sat/venda_0001.xml
      *
      * \param nItem
      * Identificação do produto ao qual será acrecentado a tag PISST.\n
      * Este parametro é retornado da função #informaProduto
      * > <b>Parametro obrigatório</b>
      *
      * \param grupo
      * Informar ZERO para campos do PIS com aliquota em percentual\n
      * ou UM para campos do PIS com aliquota em valor.
      * > <b>Parametro obrigatório</b>
      *
      * \param vBC_qBCProd
      * Caso o grupo informado seja ZERO o valor considerado será para TAG vBC (R02).
      * > R02 : Valor da Base de Cálculo do PIS\n
      * > <b>Tipo:</b> Numérico\n
      * > <b>Tamanho:</b> 3-15\n
      * > <b>Casas decimais:</b> 2\n
      * Caso o grupo informado seja UM o valor considerado será para TAG qBCProd(R04).
      * > R04 : Quantidade Vendida\n
      * > <b>Tipo:</b> Numérico\n
      * > <b>Tamanho:</b> 3-16\n
      * > <b>Casas decimais:</b> 4\n
      *
      * \param pPIS_vAliqProd
      * Caso o grupo informado seja ZERO o valor considerado será para TAG pPIS (R03).
      * > R03 : Alíquota do PIS (em percentual)\n
      * > <b>Tipo:</b> Numérico\n
      * > <b>Tamanho:</b> 5\n
      * > <b>Casas decimais:</b> 4\n
      * caso o grupo informado seja UM o valor considerado será para a TAG vAliqProd(R05)
      * > R05 : Alíquota do PIS (em reais).\n
      * > <b>Tipo:</b> Numérico\n
      * > <b>Tamanho:</b> 3-15\n
      * > <b>Casas decimais:</b> 4\n
      *
      * \return
      * O retorno da função é do tipo numérico.\n
      * A função bem sucedida deve retornar 0.\n
      * * Para mais informações consulte a sessão de codigo de erros.
      */
     ///@cond
     E1_SATSHARED_EXPORT STDCALL
     ///@endcond
     int InformaPISST(const char *path_file, int nItem, int grupo, const char *vBC_qBCProd, const char *pPIS_vAliqProd);

     /*!
      * \ingroup s0
      *
      * \brief InformaCOFINSAliq
      * Cria TAG COFINS e COFINSAliq.\n
      * Grupo de COFINS tributado pela alíquota.\n
      * CST = 01, 02 e 05.
      *
      * \param path_file
      * Caminho absoluto onde o arquivo xml será gerado.\n
      * EX:\n
      * > C:/sat/venda_0001.xml

      * \param nItem
      * Identificação do produto ao qual será acrecentado a tag COFINSAliq.
      * Este parametro é retornado da função #informaProduto
      * > <b>Parametro obrigatório</b>
      *
      * \param CST
      * Código de Situação Tributária da COFINS.\n
      * 01 – Operação Tributável (base de cálculo = valor da operação alíquota normal (cumulativo/não cumulativo));\n
      * 02 - Operação Tributável (base de cálculo = valor da operação (alíquota diferenciada));\n
      * 05 - Operação Tributável por Substituição Tributária;\n
      * > <b>TAG:</b> S07\n
      * > <b>Parametro obrigatório</b>\n
      * > <b>Tipo:</b> Numérico\n
      * > <b>Tamanho:</b> 2\n
      *
      * \param vBC
      * Valor da Base de Cálculo da COFINS.\n
      * > <b>TAG:</b> S08\n
      * > <b>Parametro obrigatório</b>\n
      * > <b>Tipo:</b> Numérico\n
      * > <b>Tamanho:</b> 3-15\n
      * > <b>Casas decimais:</b> 2\n
      *
      * \param pCOFINS
      * Alíquota da COFINS (em percentual).\n
      * Ex. Se a alíquota for 0,65% informar 0,0065.\n
      * > <b>TAG:</b> S09\n
      * > <b>Parametro obrigatório</b>\n
      * > <b>Tipo:</b> Numérico\n
      * > <b>Tamanho:</b> 5\n
      * > <b>Casas decimais:</b> 4\n
      *
      * \return
      * O retorno da função é do tipo numérico.\n
      * A função bem sucedida deve retornar 0.\n
      * * Para mais informações consulte a sessão de codigo de erros.
      */
     ///@cond
     E1_SATSHARED_EXPORT STDCALL
     ///@endcond
     int InformaCOFINSAliq(const char *path_file, int nItem, const char *CST, const char *vBC, const char *pCOFINS);

     /*!
      * \ingroup s0
      *
      * \brief InformaCOFINSQtde
      * Cria TAG COFINS e COFINSQtde.\n
      * Grupo de COFINS tributado por Qtde.\n
      * CST = 03.
      *
      * \param path_file
      * Caminho absoluto onde o arquivo xml será gerado.\n
      * EX:\n
      * > C:/sat/venda_0001.xml
      *
      * \param nItem
      * Identificação do produto ao qual será acrecentado a tag COFINSQtde.
      * Este parametro é retornado da função #informaProduto
      * > <b>Parametro obrigatório</b>
      *
      * \param CST
      * Código de Situação Tributária da COFINS.\n
      * 03 - Operação Tributável (base de cálculo = quantidade vendida x alíquota por unidade de produto);
      * > <b>TAG:</b> S07\n
      * > <b>Parametro obrigatório</b>\n
      * > <b>Tipo:</b> Numérico\n
      * > <b>Tamanho:</b> 2\n
      *
      * \param qBCProd
      * Quantidade Vendida.\n
      * > <b>TAG:</b> S11\n
      * > <b>Parametro obrigatório</b>\n
      * > <b>Tipo:</b> Numérico\n
      * > <b>Tamanho:</b> 3-16\n
      * > <b>Casas decimais:</b> 4\n
      *
      * \param vAliqProd
      * Alíquota da COFINS (em reais).
      * > <b>TAG:</b> S12\n
      * > <b>Parametro obrigatório</b>\n
      * > <b>Tipo:</b> Numérico\n
      * > <b>Tamanho:</b> 3-15\n
      * > <b>Casas decimais:</b> 4\n
      *
      * \return
      * O retorno da função é do tipo numérico.\n
      * A função bem sucedida deve retornar 0.\n
      * * Para mais informações consulte a sessão de codigo de erros.
      */
     ///@cond
     E1_SATSHARED_EXPORT STDCALL
     ///@endcond
     int InformaCOFINSQtde(const char *path_file, int nItem, const char *CST, const char *qBCProd, const char *vAliqProd);

     /*!
      * \ingroup s0
      *
      * \brief InformaCOFINSNT
      * Cria TAG COFINS e COFINSNT.\n
      * Grupo de COFINS não tributado.\n
      * CST = 04, 06, 07, 08 ou 09
      *
      * \param path_file
      * Caminho absoluto onde o arquivo xml será gerado.\n
      * EX:\n
      * > C:/sat/venda_0001.xml
      *
      * \param nItem
      * Identificação do produto ao qual será acrecentado a tag COFINSNT.
      * Este parametro é retornado da função #informaProduto
      * > <b>Parametro obrigatório</b>
      *
      * \param CST
      * Código de Situação Tributária da COFINS.\n
      * 04 - Operação Tributável(tributação monofásica (alíquotazero));\n
      * 06 - Operação Tributável(alíquota zero);\n
      * 07 - Operação Isenta da Contribuição;\n
      * 08 - Operação Sem Incidência da Contribuição;\n
      * 09 - Operação com Suspensão da Contribuição;\n
      * > <b>TAG:</b> S07\n
      * > <b>Parametro obrigatório</b>\n
      * > <b>Tipo:</b> Numérico\n
      * > <b>Tamanho:</b> 2\n
      *
      * \return
      * O retorno da função é do tipo numérico.\n
      * A função bem sucedida deve retornar 0.\n
      * * Para mais informações consulte a sessão de codigo de erros.
      */
     ///@cond
     E1_SATSHARED_EXPORT STDCALL
     ///@endcond
     int InformaCOFINSNT(const char *path_file, int nItem, const char *CST);

     /*!
      * \ingroup s0
      *
      * \brief InformaCOFINSSN Cria TAG COFINS e COFINSSN.\n
      * Grupo de COFINS para contribuinte do SIMPLES.\n
      * CST = 49
      *
      * \param path_file
      * Caminho absoluto onde o arquivo xml será gerado.\n
      * EX:\n
      * > C:/sat/venda_0001.xml
      *
      * \param nItem
      * Identificação do produto ao qual será acrecentado a tag COFINSSN.
      * Este parametro é retornado da função #informaProduto
      * > <b>Parametro obrigatório</b>
      *
      * \param CST
      * Código de Situação Tributária da COFINS.\n
      * 49 - Outras Operações de saída;
      * > <b>TAG:</b> S07\n
      * > <b>Parametro obrigatório</b>\n
      * > <b>Tipo:</b> Numérico\n
      * > <b>Tamanho:</b> 2\n
      *
      * \return
      * O retorno da função é do tipo numérico.\n
      * A função bem sucedida deve retornar 0.\n
      * * Para mais informações consulte a sessão de codigo de erros.
      */
     ///@cond
     E1_SATSHARED_EXPORT STDCALL
     ///@endcond
     int InformaCOFINSSN(const char *path_file, int nItem, const char *CST);

     /*!
      * \ingroup s0
      *
      * \brief InformaCOFINSOutr Cria TAG COFINS e COFINSOutr.\n
      * Grupo de COFINS Outras Operações.\n
      * CST = 99\n
      * Informar campos para cálculo da COFINS com aliquota em percentual (S08 e S09)
      * ou campos para COFINS com aliquota em valor (S11 e S12).
      *
      * \param path_file
      * Caminho absoluto onde o arquivo xml será gerado.\n
      * EX:\n
      * > C:/sat/venda_0001.xml
      *
      * \param nItem
      * Identificação do produto ao qual será acrecentado a tag obsFiscoDet.
      * Este parametro é retornado da função #informaProduto
      * > <b>Parametro obrigatório</b>
      *
      * \param grupo
      * Informar ZERO para campos do CONFINS com aliquota em percentual\n
      * ou UM para campos do CONFINS com aliquota em valor.
      * > <b>Parametro obrigatório</b>
      *
      * \param CST
      * Código de Situação Tributária da COFINS.\n
      * 99 - Outras Operações;
      * > <b>TAG:</b> S07\n
      * > <b>Parametro obrigatório</b>\n
      * > <b>Tipo:</b> Numérico\n
      * > <b>Tamanho:</b> 2\n
      *
      * \param vBC_qBCProd
      * Caso o grupo informado seja ZERO o valor considerado será para TAG vBC(S08).
      * > S08 : Valor da Base de Cálculo da COFINS.\n
      * > <b>Tipo:</b> Numérico\n
      * > <b>Tamanho:</b> 3-15\n
      * > <b>Casas decimais:</b> 2\n
      * Caso o grupo informado seja UM o valor considerado será para TAG qBCProd(S11).
      * > S11 : Quantidade Vendida\n
      * > <b>Tipo:</b> Numérico\n
      * > <b>Tamanho:</b> 3-16\n
      * > <b>Casas decimais:</b> 4\n
      *
      * \param pCOFINS_vAliqProd
      * Caso o grupo informado seja ZERO o valor considerado será para TAG pCOFINS(S09).\n
      * Ex. Se a alíquota for 0,65% informar 0,0065.
      * > S09 : Alíquota do COFINS (em percentual).\n
      * > <b>Tipo:</b> Numérico\n
      * > <b>Tamanho:</b> 5\n
      * > <b>Casas decimais:</b> 4\n
      * Caso o grupo informado seja UM o valor considerado será para a TAG vAliqProd(S12)
      * > S12 : Alíquota do COFINS (em reais).\n
      * > <b>Tipo:</b> Numérico\n
      * > <b>Tamanho:</b> 3-15\n
      * > <b>Casas decimais:</b> 4\n
      *
      * \return
      * O retorno da função é do tipo numérico.\n
      * A função bem sucedida deve retornar 0.\n
      * * Para mais informações consulte a sessão de codigo de erros.
      */
     ///@cond
     E1_SATSHARED_EXPORT STDCALL
     ///@endcond
     int InformaCOFINSOutr(const char *path_file, int nItem, int grupo, const char *CST, const char *vBC_qBCProd, const char *pCOFINS_vAliqProd);

     /*!
      * \ingroup s0
      *
      * \brief InformaCOFINSST Grupo de COFINS Substituição Tributária.\n
      * Informar campos para cálculo do COFINS Substituição Tributária com aliquota em percentual \n
      * (T02 e T03) ou campos para COFINS com aliquota em valor (T04 e T05).
      *
      * \param path_file
      * Caminho absoluto onde o arquivo xml será gerado.\n
      * EX:\n
      * > C:/sat/venda_0001.xml
      *
      * \param nItem
      * Identificação do produto ao qual será acrecentado a tag obsFiscoDet.\n
      * Este parametro é retornado da função #informaProduto
      * > <b>Parametro obrigatório</b>
      *
      * \param grupo
      * Informar ZERO para campos do CONFINS com aliquota em percentual\n
      * ou UM para campos do CONFINS com aliquota em valor.
      * > <b>Parametro obrigatório</b>
      *
      * \param vBC_qBCProd
      * Caso o grupo informado seja ZERO o valor considerado será para TAG vBC (T02).
      * > T02 : Valor da Base de Cálculo do COFINS\n
      * > <b>Tipo:</b> Numérico\n
      * > <b>Tamanho:</b> 3-15\n
      * > <b>Casas decimais:</b> 2\n
      * Caso o grupo informado seja UM o valor considerado será para TAG qBCProd(T04).
      * > T04 : Quantidade Vendida\n
      * > <b>Tipo:</b> Numérico\n
      * > <b>Tamanho:</b> 3-16\n
      * > <b>Casas decimais:</b> 4\n
      *
      * \param pCOFINS_vAliqProd
      * Caso o grupo informado seja ZERO o valor considerado será para TAG pCOFINS (T03).
      * > T03 : Alíquota do COFINS (em percentual)\n
      * > <b>Tipo:</b> Numérico\n
      * > <b>Tamanho:</b> 5\n
      * > <b>Casas decimais:</b> 4\n
      * Caso o grupo informado seja UM o valor considerado será para a TAG vAliqProd(T05)
      * > T05 : Alíquota do COFINS (em reais).\n
      * > <b>Tipo:</b> Numérico\n
      * > <b>Tamanho:</b> 3-15\n
      * > <b>Casas decimais:</b> 4\n
      *
      * \return
      * O retorno da função é do tipo numérico.\n
      * A função bem sucedida deve retornar 0.\n
      * * Para mais informações consulte a sessão de codigo de erros.
      */
     ///@cond
     E1_SATSHARED_EXPORT STDCALL
     ///@endcond
     int InformaCOFINSST(const char *path_file, int nItem, int grupo, const char *vBC_qBCProd, const char *pCOFINS_vAliqProd);

     /*!
      * \ingroup s0
      *
      * \brief InformaISSQN
      * \details
      * Informar os campos para cálculo do ISSQN. O grupo de ISSQN é mutuamente exclusivo com o
      * grupo ICMS, isto é se ISSQN for informado o grupo ICMS não será informado e vice-versa.
      *
      * \param path_file
      * Caminho absoluto onde o arquivo xml será gerado.\n
      * EX:\n
      * > C:/sat/venda_0001.xml

      * \param nItem
      * Identificação do produto ao qual será acrecentado a tag obsFiscoDet.
      * Este parametro é retornado da função #informaProduto
      * > <b>Parametro obrigatório</b>
      *
      * \param vDeducISSQN
      * Valor das deduções para ISSQN.\n
      * Valor das deduções para Redução da Base de Cálculo em R$.\n
      * > <b>TAG:</b> U02\n
      * > <b>Parametro obrigatório</b>\n
      * > <b>Tipo:</b> Numérico\n
      * > <b>Tamanho:</b> 3-15\n
      * > <b>Casas decimais:</b> 2\n
      *
      * \param vAliq
      * Alíquota do ISSQN.
      * > <b>TAG:</b> U04\n
      * > <b>Parametro obrigatório</b>\n
      * > <b>Tipo:</b> Numérico\n
      * > <b>Tamanho:</b> 5\n
      * > <b>Casas decimais:</b> 4\n
      *
      * \param cMunFG
      * Informar o município de ocorrência do fato gerador do ISSQN. Utilizar a Tabela do
      * IBGE; se exterior utilizar 9999999.
      * > <b>TAG:</b> U06\n
      * > Essa TAG não é obrigatória e para que não seja incluida no XML deve-se passar parametro vazio.\n
      * > <b>Tipo:</b> Numérico\n
      * > <b>Tamanho:</b> 7\n
      *
      * \param cListServ
      * Informar o Item da lista de serviços da LC 116/03 em que se classifica o serviço.
      * > <b>TAG:</b> U07\n
      * > Essa TAG não é obrigatória e para que não seja incluida no XML deve-se passar parametro vazio.\n
      * > <b>Tipo:</b> Alfanumérico\n
      * > <b>Tamanho:</b> 5\n
      *
      * \param cServTribMun
      * Codigo de tributação pelo ISSQN do municipio.
      * > <b>TAG:</b> U08\n
      * > Essa TAG não é obrigatória e para que não seja incluida no XML deve-se passar parametro vazio.\n
      * > <b>Tipo:</b> Alfanumérico\n
      * > <b>Tamanho:</b> 20\n
      *
      * \param cNatOp
      * Natureza da Operação de ISSQN.\n
      * 01 - Tributação no município; \n
      * 02 - Tributação fora do município;\n
      * 03 - Isenção;\n
      * 04 - Imune; \n
      * 05 - Exigibilidade suspensa por decisão judicial; \n
      * 06 - Exigibilidade suspensa por procedimento administrativo; \n
      * 07 - Não tributável ou não incidência;\n
      * 08 - Exportação de Serviço. \n
      * > <b>TAG:</b> U09\n
      * > <b>Parametro obrigatório</b>\n
      * > <b>Tipo:</b> Numérico\n
      * > <b>Tamanho:</b> 2\n
      *
      * \param indIncFisc
      * Indicador de Incentivo Fiscal do ISSQN.\n
      * 1 - Sim; 2 - Não.
      * > <b>TAG:</b> U10\n
      * > <b>Parametro obrigatório</b>\n
      * > <b>Tipo:</b> Numérico\n
      * > <b>Tamanho:</b> 1\n
      *
      * \return
      * O retorno da função é do tipo numérico.\n
      * A função bem sucedida deve retornar 0.\n
      * * Para mais informações consulte a sessão de codigo de erros.
      */
     ///@cond
     E1_SATSHARED_EXPORT STDCALL
     ///@endcond
     int InformaISSQN(const char *path_file, int nItem, const char *vDeducISSQN, const char *vAliq, const char *cMunFG, const char *cListServ, const char *cServTribMun, const char *cNatOp, const char *indIncFisc);

     /*!
      * \ingroup s0
      *
      * \brief InformainfAdProd
      * Informações Adicionais do Produto.\n
      *
      * \param path_file
      * Caminho absoluto onde o arquivo xml será gerado.\n
      * EX:\n
      * > C:/sat/venda_0001.xml
      *
      * \param nItem
      * Identificação do produto ao qual será acrecentado a tag obsFiscoDet.
      * Este parametro é retornado da função #informaProduto
      * > <b>Parametro obrigatório</b>
      *
      * \param infAdProd
      * Informações Adicionais do Produto.\n
      * Norma referenciada, informações complementares,etc.
      * > <b>TAG:</b> V01\n
      * > Essa TAG não é obrigatória e para que não seja incluida no XML deve-se passar parametro vazio.\n
      * > <b>Tipo:</b> Alfanumérico\n
      * > <b>Tamanho:</b> 1-500\n
      *
      * \return
      * O retorno da função é do tipo numérico.\n
      * A função bem sucedida deve retornar 0.\n
      * * Para mais informações consulte a sessão de codigo de erros.
      */
     ///@cond
     E1_SATSHARED_EXPORT STDCALL
     ///@endcond
     int InformaInfAdProd(const char *path_file, int nItem, const char *infAdProd);

     /*!
      * \ingroup s0
      *
      * \brief InformaTotal
      * Informa Grupo de Valores Totais do CF-e.
      *
      * \param path_file
      * Caminho absoluto onde o arquivo xml será gerado.\n
      * EX:\n
      * > C:/sat/venda_0001.xml
      *
      * \param vDescSubtot
      * Valor de Entrada de Desconto sobre Subtotal.\n
      * Se informado, deve conter desconto concedido sobre total dos itens.\n
      * Valor deverá ser distribuido pelo SAT proporcionalmen te ao valor de cada item, já considerado o\n
      * desconto ou acréscimo do item. Distribuição incidirá sobre os itens sujeitos ao ISSQN somente \n
      * se o campo indRatISSQN (id:C16) = 'S'.
      * > <b>TAG:</b> W20\n
      * > Essa TAG não é obrigatória e para que não seja incluida no XML deve-se passar parametro vazio.\n\n
      * > <b>Tipo:</b> Numérico\n
      * > <b>Tamanho:</b> 3-15\n
      * > <b>Casas decimais:</b> 2\n
      * * TAG mutuamente exclusiva com a TAG W21. Se informada, a TAG21 não será incluida e vice-versa.
      *
      *
      * \param vAcresSubtot
      * Valor de Entrada de Acréscimo sobre Subtotal.\n
      * Se informado, deve conter acréscimo sobre total dos itens, Valor deverá ser distribuido pelo\n
      * SAT proporcionalmente ao valor de cada item, já considerado o desconto ou acréscimo do item.
      * > <b>TAG:</b> W21\n
      * > Essa TAG não é obrigatória e para que não seja incluida no XML deve-se passar parametro vazio.\n
      * > <b>Tipo:</b> Numérico\n
      * > <b>Tamanho:</b> 3-15\n
      * > <b>Casas decimais:</b> 2\n
      * * TAG mutuamente exclusiva com a TAG W20. Se informada, a TAG20 não será incluida e vice-versa.
      *
      * \param vCFeLei12741
      * Valor aproximado dos tributos do CFe-SAT – Lei 12741/12.\n
      * Valor aproximado dos tributos do CF-e-SAT, declarado pelo emitente, conforme Lei 12741/2012.\n
      * Valor deve ser maior ou igual a zero. Campo de preenchimento:\n
      * - opcional, caso o contribuinte opte por informar o valor em painel afixado no estabelecimento, \n
      * conforme artigo 2º, §2º da referida lei.
      * - obrigatório, caso o contribuinte não opte por informar o valor em painel afixado no \n
      * estabelecimento, conforme artigo 2º, §2º da referida lei.
      * > <b>TAG:</b> W22\n
      * > Essa TAG não é obrigatória e para que não seja incluida no XML deve-se passar parametro vazio.\n
      * > <b>Tipo:</b> Numérico\n
      * > <b>Tamanho:</b> 3-15\n
      * > <b>Casas decimais:</b> 2\n
      *
      * \return
      * O retorno da função é do tipo numérico.\n
      * A função bem sucedida deve retornar 0.\n
      * * Para mais informações consulte a sessão de codigo de erros.
      */
     ///@cond
     E1_SATSHARED_EXPORT STDCALL
     ///@endcond
     int InformaTotal(const char *path_file, const char *vDescSubtot, const char *vAcresSubtot, const char *vCFeLei12741);

     /*!
      * \ingroup s0
      *
      * \brief Informapgto
      * Informa Grupo de informações sobre Pagamento do CFe.
      *
      * \param path_file
      * Caminho absoluto onde o arquivo xml será gerado.\n
      * EX:\n
      * > C:/sat/venda_0001.xml
      *
      * \param cMP
      * Código do Meio de Pagamento empregado para quitação do CF-e.\n
      * 01 - Dinheiro\n
      * 02 - Cheque\n
      * 03 - Cartão de Crédito\n
      * 04 - Cartão de Débito\n
      * 05 - Crédito Loja\n
      * 10 - Vale Alimentação\n
      * 11 - Vale Refeição\n
      * 12 - Vale Presente\n
      * 13 - Vale Combustível\n
      * 99 - Outros \n
      * > <b>TAG:</b> WA03\n
      * > <b>Parametro obrigatório</b>\n
      * > <b>Tipo:</b> Numérico\n
      * > <b>Tamanho:</b> 2\n

      * \param vMP
      * Valor do Meio de Pagamento empregado para quitação do CF-e.
      * > <b>TAG:</b> WA04\n
      * > <b>Parametro obrigatório</b>\n
      * > <b>Tipo:</b> Numérico\n
      * > <b>Tamanho:</b> 3-15\n
      * > <b>Casas decimais:</b> 2\n
      *
      * \param cAdmC
      * Credenciadora de cartão de débito ou crédito.\n
      * Código da Credenciadora de cartão de débito ou crédito conforme tabela disponível no
      * Anexo 3 - Tabela de credenciadoras de cartão de débito ou crédito Exemplos:
      * 001, 002, 003. .
      * > <b>TAG:</b> WA05\n
      * > Essa TAG não é obrigatória e para que não seja incluida no XML deve-se passar parametro vazio.\n
      * > <b>Tipo:</b> Numérico\n
      * > <b>Tamanho:</b> 3\n
      *
      *  \image html C:\Users\bruno.cruz\Pictures\anexo03.JPG
      *  \image html C:\Users\bruno.cruz\Pictures\anexo03-a.JPG
      *
      * \return
      * O retorno da função é do tipo numérico.\n
      * A função bem sucedida deve retornar 0.\n
      * * Para mais informações consulte a sessão de codigo de erros.
      */
     ///@cond
     E1_SATSHARED_EXPORT STDCALL
     ///@endcond
     int InformaPgto(const char *path_file, const char *cMP, const char *vMP, const char *cAdmC);

     /*!
      * \ingroup s0
      *
      * \brief InformainfAdic
      * Informa Grupo de Informações Adicionais.
      *
      * \param path_file
      * Caminho absoluto onde o arquivo xml será gerado.\n
      * EX:\n
      * > C:/sat/venda_0001.xml
      *
      * \param infCpl
      * Informações Complementares de interesse do Contribuinte.
      * > <b>TAG:</b> Z02\n
      * > Essa TAG não é obrigatória e para que não seja incluida no XML deve-se passar parametro vazio.\n
      * > <b>Tipo:</b> Alfanumérico\n
      * > <b>Tamanho:</b> 1-5000\n
      *
      * \return
      * O retorno da função é do tipo numérico.\n
      * A função bem sucedida deve retornar 0.\n
      * * Para mais informações consulte a sessão de codigo de erros.
      */
     ///@cond
     E1_SATSHARED_EXPORT STDCALL
     ///@endcond
     int InformaInfAdic(const char *path_file, const char *infCpl);

     /*!
      * \ingroup s0
      *
      * \brief FechaCupomVenda -
      * Função de fechamento da venda. Usada para enviar o XML criado para o equipamento SAT .\n
      * Caso a função seja processada com sucesso o XML usado sera atualizado com os dados de processamento da venda no SAT.\n
      *
      * Essa função depende do arquivo <b>e1_conf.ini</b> no diretório da aplicação com a chave <b>caminho_biblioteca_sat</b>\n
      * Ex.\n
      *  ~~~~~~~.ini
      *  [configuracao_sat]
      *  caminho_biblioteca_sat=C:\\Program Files (x86)\\sat\\satelgin 6.0.0\\lib\\dllsat.dll
      *  ~~~~~~~
      *
      *
      * \param path_file
      * Informa o caminho do XML. O arquivo será enviado ao SAT e atualizado com a resposta.\n
      *
      * \param codigo_ativacao_sat
      * Código de ativação do equipamento para precessamento do XML!\n
      *
      * \return
      * A função retorna a resposta do SAT.\n
      * Caso ocorra algum erro será retornado um código númerico de erro.\n
      * * Para mais informações consulte a sessão de codigo de erros.
      * \n\n
      *
      * > Essa Função está disponível apenas para Equipamentos SAT Elgin e Bematech quando não estiver integrado com a plataforma Veraciti.
      */
     ///@cond
     E1_SATSHARED_EXPORT STDCALL
     ///@endcond
     char *FechaCupomVenda(const char *path_file, const char *codigo_ativacao_sat);

     /*!
      * \ingroup s0
      *
      * \brief AbreCupomCancelamento
      * Gera XML de Cancelamento para o SAT.
      *
      * \param path_file
      * Caminho absoluto onde o arquivo xml será gerado.\n
      * EX:\n
      * > C:/sat/venda_0001.xml
      *
      * \param chCanc
      * informar a chave de acesso do CF-e a ser cancelado, precedida do literal ‘CFe’,\n
      * acrescentada a validação do formato.
      * > TAG : A06\n
      * > <b>Parametro obrigatório</b>\n
      * > <b>Tipo:</b> Alfanumérico\n
      * > <b>Tamanho:</b> 47\n
      *
      * \param CNPJ
      * Informar o CNPJ da empresa desenvolvedora do Aplicativo Comercial.\n
      * Deve ser informado apenas números. Caracteres (ponto, barra, hífen, etc.) serão removidos.\n
      * Caso o CNPJ tenha menos que 14 digitos a tag será preenchida com 0 não significativos.\n
      * zeros não significativos.
      * > <b>TAG:</b> B10\n
      * > <b>Parametro obrigatório</b>\n
      * > <b>Tipo:</b> Numérico\n
      * > <b>Tamanho:</b> 14\n
      *
      * \param signAC
      * Assinatura de (CNPJ Software House + CNPJ Emitente) que gerou o CF-e de cancelamento.
      * > <b>TAG:</b> B11\n
      * > <b>Parametro obrigatório</b>\n
      * > <b>Tipo:</b> Alfanumérico\n
      * > <b>Tamanho:</b> 1-344\n
      *
      * \param numeroCaixa
      * Número de 0 a 999 referente ao caixa em que o SAT está conectado.
      * > <b>TAG:</b> B13\n
      * > <b>Parametro obrigatório</b>\n
      * > <b>Tipo:</b> Numérico\n
      * > <b>Tamanho:</b> 3\n
      *
      * \return
      * O retorno da função é do tipo numérico.\n
      * A função bem sucedida deve retornar 0.\n
      * * Para mais informações consulte a sessão de codigo de erros.
      */
     ///@cond
     E1_SATSHARED_EXPORT STDCALL
     ///@endcond
     int AbreCupomCancelamento(const char *path_file, const char *chCanc, const char *CNPJ, const char *signAC, int numeroCaixa);

     /*!
      * \ingroup s0
      * \brief AbreCupomCancelamento2
      * Essa função cria o arquivo de cancelamento organizando os arquivos a partir do diretório informado em 'path_root'.\n
      *
      * A Estrutura criada deve ser: /XML/SAT/CANCELAMENTO/yyyy/MM/dd/yyyyMMddhhmmss.xml\n
      * onde:
      * > yyyy = ANO\n
      * > MM = MÊS\n
      * > dd = DIA\n
      * > hh = HORA\n
      * > mm = MINUTO\n
      * > ss = SEGUNDO\n
      *
      * \param path_root
      * Caminho raiz onde a estrutura de pasta e o arquivo será gerado.
      * \note
      * Os demais parametros são identicos aos da função #AbreCupomCancelamento
      *
      * \return
      * O retorno dessa função deve ser o caminho absoluto onde o arquivo foi gerado.
      */
     ///@cond
     E1_SATSHARED_EXPORT STDCALL
     ///@endcond
     char *AbreCupomCancelamento2(const char *path_root, const char *chCanc, const char *CNPJ, const char *signAC, int numeroCaixa);

     /*!
      * \ingroup s0
      *
      * \brief FechaCupomCancelamento
      * Função de fechamento para cancelamento de venda. Usada para enviar o XML criado para o equipamento SAT.\n
      * Caso a função seja processada com sucesso o XML usado sera atualizado com os dados de processamento do cancelamento no SAT.\n
      *
      * Essa função depende do arquivo <b>e1_conf.ini</b> no diretório da aplicação com a chave <b>caminho_biblioteca_sat</b>\n
      * Ex.\n
      *  ~~~~~~~.ini
      *  [configuracao_sat]
      *  caminho_biblioteca_sat=C:\\Program Files (x86)\\sat\\satelgin 6.0.0\\lib\\dllsat.dll
      *  ~~~~~~~
      * \n
      * \param path_file
      * Informa o caminho do XML. O arquivo será enviado ao SAT e atualizado com a resposta.\n
      *
      * \param codigo_ativacao_sat
      * Código de ativação do equipamento para precessamento do XML!\n
      *
      * \return
      * A função retorna a resposta do SAT.\n
      * Caso ocorra algum erro será retornado um código númerico de erro.\n
      * * Para mais informações consulte a sessão de codigo de erros.
      * \n\n
      *
      * > Essa Função está disponível apenas para Equipamentos SAT Elgin e Bematech quando não estiver integrado com a plataforma Veraciti.
      */
     ///@cond
     E1_SATSHARED_EXPORT STDCALL
     ///@endcond
     char *FechaCupomCancelamento(const char *path_file, const char *codigo_ativacao_sat);

     /*!
      * \ingroup s0
      *
      * \brief TrataTimeoutComunicacao
      * Função para Tratamento de Timeout de Comunicação. Usada para recuperar um processamento que foi interrompido durante uma ocorrência de timeout no SAT.\n
      * Caso a função seja processada com sucesso o arquivo será atualizado com os dados do ultima operação processada pelo SAT.\n
      *
      * Essa função depende do arquivo <b>e1_conf.ini</b> no diretório da aplicação com as chaves <b>caminho_biblioteca_sat</b> e <b>ultimo_cfe_processado</b>\n
      *
      * Ex.\n
      *  ~~~~~~~.ini
      *  [configuracao_sat]
      *  caminho_biblioteca_sat=C:/Program Files (x86)/satelgin 7.0.1/lib/dllsat.dll
      *  ultimo_cfe_processado=CFe35220114200166000166599000208640000612906931
      *  ~~~~~~~
      * \n
      * \param path_file
      * Informa o caminho do arquivo que será atualizado em caso de sucesso da operação.\n
      *
      * \param codigo_ativacao_sat
      * Código de ativação do equipamento para realização da operação\n
      *
      * \param *resultadoOperacao
      * Ponteiro do tipo int que guarda a referência do resultado da operação!\n
      *
      * \return
      * A função retorna em caso de sucesso a resposta do SAT.\n
      * Caso ocorra algum erro será retornado um código númerico de erro no parâmetro enviado por referência *resultadoOperacao.\n
      * * Para mais informações consulte a sessão de codigo de erros.
      * \n\n
      *
      * > Essa Função está disponível apenas para Equipamentos Smart Sat Elgin.
      */

     ///@cond
     E1_SATSHARED_EXPORT STDCALL
     ///@endcond
     char *TrataTimeoutComunicacao(const char *path_file, const char *codigo_ativacao_sat, int* resultadoOperacao);




     /*!
     * \brief outFile Grava dados em arquivo
     * \param data ponteiro para os dados a serem gravados
     * \param file ponteiro para o caminho do arquivo a ser usado na gravação.
     * \return Deve retornar 0 para função executada com sucesso.
     */

     ///@cond
     E1_SATSHARED_EXPORT STDCALL
     ///@endcond
     int outFile(void* data, void* file);

}
#endif // EXPORTAFUNCOES_H
