\defgroup g120 Detalhes do JSON de retorno
\ingroup g12

## Detalhes de Retorno Transação 
Todas as funções do módulo e1_brigde retornam em formato Json. As funções mais simples retornam um Json apenas com um código de operação e uma mensagem. <br>
Vide exemplo abaixo:<br>
\code{.json}
{
    "e1_bridge_code": 0,
    "e1_bridge_msg": "Sucesso"
}
\endcode

\note
Os valores de retorno para a chave e1_brigde_code em casos de falha ou o valores para as funções que retornam um int no output da função podem ser consultados na sessão \ref g1.

Abaixo estão listados todas informações do JSON retornado na saida da transação.

|           Parâmetro               |                           Descrição                                            |                     Retorno                        |   Tipo de Dado  |
| --------------------------------- | ------------------------------------------------------------------------------ | ---------------------------------------------------|-----------------|
|e1_bridge_code                     |Código de retorno da operação                                                   |Valor tipo int (0 = sucesso ou < 0 para falha)      |Int              |
|e1_bridge_msg                      |Mensagem referente ao processamento da operação                                 |Valor tipo String                                   |String           |
|e1_pdv                             |Código de identificação do PDV                                                  |Valor alfanumérico                                  |String           |
|e1_cupom_fiscal                    |Informa ao PDV que o cliente deseja cupom fiscal                                |True ou False                                       |Boolean          |
|aidCartao                          |Obtém o AID do cartão                                                           |AID do cartão                                       |String           |
|existeComprovanteGrafico           |Informa se os comprovantes  estão disponíveis no  formato gráfico               |True ou false                                       |Boolean          |
|comprovanteGraficoLojista          |O comprovante será disponibilizado no formato PNG,codificado em base-64         |Comprovante gráfico - via do lojista                |String           |   
|comprovanteGraficoPortador         |O comprovante será disponibilizado no formato PNG,codificado em base-64         |Comprovante gráfico - via do portador               |String           |
|modalidadeTransacao                |Modalidade da transação (online ou offline)                                     |Online ou Offline                                   |String           |
|codigoAutorizacao                  |Obtém o código de autorização.                                                  |Código de autorização                               |String           |
|codigoAutorizacaoOriginal          |Obtém o código de autorização original                                          |Código de autorização original                      |String           |   
|identificadorTransacaoAutomacao    |identificador da transação (informado pela Automação).                          |Identificador da transação                          |String           |
|modoEntradaCartao                  |Modo de entrada do cartão                                                       |Modo de entrada do cartão                           |String           |
|panMascarado                       |Pan do cartão, mascarado ou truncado, de acordo com a especificação do provedor.|Pan mascarado do cartão                             |String           |
|dataHoraTransacao                  |Data e hora da transação                                                        |Data\\hora da transação-dd/MM/yyyy HH:mm:ss         |String           |
|comprovanteCompleto                |Comprovante completo da transação                                               |Comprovante completo                                |String           |
|dataHoraTransacaoOriginal          |Data e hora da transação original                                               |Data\\hora da transação original-dd/MM/yyyy HH:mm:ss|String           |
|nomeCartao                         |Nome do cartão (ou nome da administradora).                                     |Nome do cartão(ou nome da administradora)           |String           | 
|comprovanteReduzidoPortador        |Comprovante reduzido para o portador do cartão                                  |Comprovante reduzido para o portador                |ArrayList<String>|
|documentoFiscal                    |Número do documento fiscal (informado pela Automação)                           |Número do documento fiscal                          |String           |
|valorTroco                         |Valor do troco, em centavos.                                                    |Valor do troco                                      |String           |
|valorDesconto                      |Valor do desconto, em centavos.                                                 |Valor do desconto                                   |String           |
|identificadorEstabelecimento       |Identificador do estabelecimento                                                |Identificador do estabelecimento                    |String           |
|nomeProvedor                       |Nome do provedor utilizado para processar a transação.                          |Nome do Provedor                                    |String           |
|operacao                           |Operação realizada.                                                             |Operação realizada.                                 |String           |
|tipoCartao                         |Tipo de cartão utilizado na transação.                                          |Tipo de cartão                                      |String           |
|tipoFinanciamento                  |Tipo de financiamento utilizado na transação.                                   |Tipo de financiamento                               |String           |
|numeroParcelas                     |Numero de parcelas da transação.                                                |Número de parcelas                                  |Int              |
|dataPredatado                      |Data do pré-datado.                                                             |Data do pré-datado                                  |String           | 
|comprovanteDiferenciadoLoja        |Compovante diferenciado para o lojista                                          |Via diferenciada para a loja                        |ArrayList<String>|
|comprovanteDiferenciadoPortador    |Compovante diferenciado para o portador do cartão                               |Comprovante diferenciada para o portador            |ArrayList<String>|
|mensagemResultado                  |Mensagem a ser exibida ao ao final da operação                                  |Mensagem a ser exibida                              |String           |
|codigoMoeda                        |Código da moeda utilizada (ISO 4217).                                           |Código da moeda                                     |String           |
|valorTotal                         |Valor total da transação, em centavos.                                          |Valor total da transação                            |String           |
|valorOriginal                      |Valor original da transação, em centavos.                                       |Valor original da transação                         |String           |
|identificadorPontoCaptura          |Identificador do ponto de captura.                                              |Identificador do ponto de captura                   |String           | 
|viasImprimir                       |Vias a serem impressas.                                                         |Vias a serem impressas                              |String           |
|resultadoTransacao                 |Resultado da operação realizada.                                                |Resultado da operação realizada                     |Int              |
|modoVerificacaoSenha               |Modo de verificação de senha.                                                   |Modo de verificação de senha                        |String           |
|identificadorConfirmacaoTransacao  |Identificador de confirmação da transação.                                      |Identificador de confirmação da transação           |String           |
|existeTransacaoPendente            |Retorna se existe transação pendente.                                           |True ou False                                       |Boolean          |
|saldoVoucher                       |Saldo do cartão voucher, recebido do autorizador                                |Saldo do cartão voucher                             |String           |
|valorDevido                        |Valor devido pelo usuário.                                                      |Valor devido pelo usuário                           |String           |
|nomeEstabelecimento                |Nome do estabelecimento em que o ponto de captura está cadastrado.              |Nome do estabelecimento                             |String           | 
|panMascaradoPadrao                 |Número do cartão, mascarado no formato BIN + *** + 4 últimos dígitos.           |Número do cartão padronizado                        |String           |
|nomeCartaoPadrao                   |Descrição do produto bandeira padrão relacionado ao BIN.                        |Descrição do produto bandeira padrão                |String           |
|nomePortadorCartao                 |Nome do portador do cartão utilizado.                                           |Nome do portador do cartão utilizado                |String           |
|modalidadePagamento                |Modalidade de pagamento (cartão, dinheiro, cheque ou carteira virtual).         |cartão, dinheiro, cheque ou carteira virtual        |String           |
|idPortadorCarteira                 |Tipo de identificação do portador da carteira virtual.                          |QRCode do checkout, CPF, outros                     |String           |
|nsuTransacao                       |NSU do host.                                                                    |NSU do host.                                        |String           |
|nsuTerminal                        |Informa o NSU local gerado na transação. Usado para realizar o cancelamento     |NSU local gerado na transação                       |String           |
|provedor                           |Obtém o nome do Provedor.                                                       |Provedor utilizado para processar a transação.      |String           |  
|uniqueID                           |Obtém ID único da transação armazenada no banco de dados.                       |ID único da transação armazenada no banco de dados. |String           |    
|requerConfirmacao                  |Informa se a transação requer confirmação.                                      |True ou false                                       |Boolean          |
|respostaRede                       |Código de resposta da transação, proveniente da rede adquirente.                |Código de resposta da rede                          |String           |
|nsuTransacaoOriginal               |NSU do Host original.                                                           |NSU do host original                                |String           |
|nsuTerminalOriginal                |NSU local gerado na transação original que foi cancelada.                       |NSU local gerado na transação cancelada             |String           |
|dadosTransacaoPendente             |Obtém os dados da transação pendente com o servidor, caso haja                  |Dados da transação pendente                         |String           |
