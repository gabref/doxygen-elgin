@defgroup t03 Descrição das Chaves
@ingroup t0

# TRANSACOES SUPORTADAS
| Sigla | Descrição |
| :---: | :--- |
| ADM | Operacoes administrativas |
| CRT | Operacoes de venda |
| CNC | Cancelamento de venda |
| CNF | Confirmacao de venda |
| NCN | Nao confirmacao de venda |
| ATV | Ativacao |
| PIX | PIX |
| CLT | Coleta de dados no PinPad |

# CHAVES USADAS NO PROTOCOLO DE TROCA DE ARQUIVO

   * (I) = PRESENTE NO ARQUIVO DE ENTRADA
   * (O) = PRESENTE NO ARQUIVO DE SAIDA
   *  *  = PRESENCA OBRIGATORIA

<br>

|  Chave  | Nome da Funçao               | In / Out | Descrição |
| :-----: | :--------------------------- | :------: | :---- |
| 000&minus;000 | HEADER                       | (*I)(*O) | Contém o tipo de operação e marca o início do arquivo |
| 001&minus;000 | IDENTIFICACAO                | (*I)(*O) | Contém um número de controle da operação. Gerado pala automacao |
| 002&minus;000 | DOCUMENTO_FISCAL             | (I)(O)   | Número do documento fiscal ao qual a operação de TEF está vinculada. Caso seja usada uma Impressora Fiscal, o preenchimento deste campo é obrigatório para transações de venda. |
| 003&minus;000 | VALOR_TRANSACAO              | (I)(O)   | Valor da venda relativa ao pagamento com cartão. Valor com duas casas decimais e sem virgula separadora. Caso não enviado o GP deve solicitar o preenchimento pelo operador |
| 004&minus;000 | MOEDA                        | (I)(O)   | Indica a moeda utilizada na operação. Este campo é numérico de 1 byte e pode assumir os seguintes valores: “0” para indicar que a moeda é o Real |
| 005&minus;000 | CMC7                         | (I)      | Contém os dados do cheque no mesmo formato obtido por uma leitura do CMC-7 |
| 006&minus;000 | TIPO_PESSOA                  | (I)      | Tipo do cliente: F – para pessoa física – CPF J – para pessoa jurídica - CNPJ |
| 007&minus;000 | DOCUMENTO_PESSOA             | (I)      | Indica a pessoa que esta sendo atendida na operação por meio do CNPJ ou CPF. |
| 008&minus;000 | DATA_CHEQUE                  | (I)      | Data do cheque |
| 009&minus;000 | STATUS_TRANSACAO             | (O)      | Indica se a transação foi aprovada ou recusada e qual o motivo da recusa |
| 010&minus;000 | NOME_REDE                    | (I)(O)   | Contém o nome da rede em que a transação foi processada. |
| 010&minus;001 | CODIGO_REDE                  | (O)      | Código da rede que autorizou a transação |
| 010&minus;002 | NOME_BANDEIRA                | (O)      | Nome da bandeira |
| 010&minus;003 | CODIGO_BANDEIRA              | (O)      | Código da bandeira |
| 010&minus;004 | BIN                          | (O)      | Devolve os 6 primeiros dígitos do número do cartão |
| 010&minus;005 | EMBOSSO                      | (O)      | Código dos quatro últimos dígitos do bin do cartão |
| 010&minus;007 | CODIGO_SERVICO               | (O)      | Indica o código do serviço. |
| 011&minus;000 | CODIGO_DA_TRANSACAO          | (I)(O)   | Código identificador do tipo da transação. |
| 012&minus;000 | NUMERO_TRANSACAO_NSU         | (I)(O)   | Contém o Número Sequencial Único (NSU) da transação. |
| 013&minus;000 | CODIGO_AUTORIZACAO           | (O)      | Contém um número de autorização de transação gerado pelo emissor do cartão |
| 013&minus;001 | CODIGO_AUTORIZACAO_ORIGINAL  | (O)      | Contém um número de autorização de transação cancelada gerado pelo emissor do cartão |
| 017&minus;000 | TIPO_PARCELAMENTO            | (I)(O)   | Contém o tipo de parcelamento associado à operação.[ 0: Parcelado estabelecimento. 1: Parcelado emissor] |
| 018&minus;000 | QUANTIDADE_PARCELAS          | (I)(O)   | Contém o número de parcelas associado a operação |
| 022&minus;000 | DATA_TRANSACAO               | (I)(O)   | Indica a data da transação. Este campo é numérico, tem tamanho de 8 bytes e tem obrigatoriamente o formato DDMMAAAA. |
| 023&minus;000 | HORA_TRANSACAO               | (I)(O)   | Indica a hora da transação. Este campo é numérico, tem tamanho de 6 bytes e tem obrigatoriamente o formato HHMMSS. |
| 024&minus;000 | DATA_PREDATADO               | (O)      | Data de agendamento da transação. Formato DDMMAAAA. |
| 025&minus;000 | NUMERO_TRANSACAO_ORIGINAL_NSU| (O)      | Contém o Número Sequencial Único (NSU) da transação cancelada. |
| 026&minus;000 | DATA_HORA_TRANSACAO_ORIGINAL | (O)      | Contém a data e hora da transação cancelada no Host. Formato DDMMHHMMSS. |
| 027&minus;000 | FINALIZACAO                  | (I)(O)   | Dados recebidos do GP que devem ser devolvidos no comando de confirmação ou não-confirmação de uma venda. |
| 028&minus;000 | NUMERO_LINHAS_CUPOM          | (O)      | Quantidade de linhas da via única do comprovante. |
| 028&minus;001 | MARCA_RECORTE                | (O)      | Indica a(s) linha(s) do comprovante onde há recorte |
| 030&minus;000 | TEXTO_OPERADOR               | (O)      | Texto que, quando presente, deve ser apresentado pelo Terminal solicitador de TEF ao operador |
| 040&minus;000 | NOME_CARTAO                  | (O)      | Nome do cartão ou do Emissor. O mesmo cartão pode ter nomes diferentes de acordo com a Rede Adquirente utilizada. |
| 043&minus;000 | NSU_HOST                     | (O)      | Indica o número de seqüência (NSU – Número Seqüencial Único) da transação atribuído pelo GP. |
| 043&minus;001 | NSU_HOST_TRANSACAO_ORIGINAL  | (O)      | Indica o número de seqüência (NSU – Número Seqüencial Único) da transação atribuído pelo GP referente a venda cancelada |
| 047&minus;000 | CODIGO_RESPOSTA              | (O)      | Código de resposta alfanumérico, validado em situações específicas. |
| 050&minus;000 | TAXA_SERVICO                 | (O)      | Valor referente à taxa de serviço. |
| 050&minus;001 | TAXA_EMBARQUE                | (O)      | Valor referente à taxa de embarque. |
| 150&minus;000 | CODIGO_ESTABELECIMENTO       | (O)      | Código do estabelecimento registrado no cadastro. |
| 150&minus;001 | CODIGO_CONTRATO              | (O)      | Código do contrato no servidor. |
| 150&minus;003 | CODIGO_AREA                  | (O)      | É um campo para informar o Código de Área da Cidade. |
| 200&minus;000 | VALOR_SAQUE                  | (O)      | Valor do saque realizado |
| 210&minus;004 | NUMERO_TRILHA2               | (O)      | Indica o número do cartão utilizado na transação para pagamento |
| 210&minus;052 | NUMERO_PDV                   | (I)(O)   | Informa o número do PDV para o registro de ocorrência. Normalmente esta relacionado com o computador |
| 210&minus;065 | SALDO_DISPONIVEL             | (O)      | Indica o valor do Saldo Disponível no cartão. |
| 300&minus;001 | DATA_VALIDADE_CARTAO         | (O)      | Informa a data de vencimento do cartão |
| 375&minus;000 | CODIGO_OPERACAO              | (*O)     | Código de retorno da operação realizada no produto de tef, normalmente retorno da DLL do produto configurado para chamada da operação |
| 375&minus;001 | MENSAGEM_OPERACAO            | (*O)     | Mensagem referente ao código de retorno |
| 375&minus;002 | SOLICITA_CUPOM_FISCAL        | (O)      | Chave utilizada para indicar ao POS ElginPay que deve ser questionado ao cliente se o mesmo deseja cupom fiscal |
| 375&minus;008 | MODO_ENTRADA_CARTAO          | (O)      | Indica o modo como foi realizado a captura do cartão |
| 375&minus;016 | ESTABELECIMENTO              | (I)(O)   | Nome do estabelecimento |
| 375&minus;017 | APLICACAO                    | (I)      | Nome da aplicação usado nos arquivos de entrada |
| 375&minus;018 | VERSAO_APLICACAO             | (I)      | Versão da aplicação usado nos arquivos de entrada |
| 375&minus;019 | LOJA                         | (I)(O)   | Nome da Loja |
| 375&minus;023 | TEXTO_PINPAD                 | (O)      | Texto a ser apresentado no PINPAD |
| 375&minus;024 | ADM_USUARIO                  | (I)      | Usuario para operações administrativas |
| 375&minus;025 | ADM_SENHA                    | (I)      | Senha para operações administrativas |
| 375&ndash;028 | RETORNO                      | (O)      | 0 = Requer confirmação da transação com CNF ou NCN/ 1 = não requer confirmação/ if >= 2 = Erro |
| 376&ndash;000 | OPCAO_COLETA                 | (*I)     | Tipo da coleta a ser realizada no pinpad ( 1 = RG, 2 = CPF, 3 = CNPJ, 4 = FONE) |
| 376&ndash;001 | DADO_COLETADO                | (O)      | Resultado da captura no pinpad de acordo com a solicitação 376-000 |
| 504&minus;000 | CODIGO_OP_CELULAR            | (O)      | Informa o código da operadora recarregado |
| 600&minus;000 | CNPJ_CREDENCIADORA           | (O)      | É o CNPJ da rede credenciadora do cartão de débito/crédito. |
| 707&minus;000 | VALOR_ORIGINAL               | (O)      | Valor original da transação informado pela AC no campo 003-000 do arquivo de solicitação, em centavos. Este campo é informado pelo GP caso seja diferente do valor final da transação informado no campo 003-000 do arquivo de resposta. |
| 708&minus;000 | VALOR_TROCO                  | (O)      | Valor de retirada em dinheiro (saque no cartão) realizada em conjunto com a transação de venda, em centavos. |
| 709&minus;000 | VALOR_DESCONTO               | (O)      | Valor do desconto concedido ao Cliente pela Rede Adquirente ou pelo Emissor para uma transação de venda, em centavos. |
| 718&minus;000 | TERMINAL                     | (I)(O)   | Número lógico do terminal. Normalmente esta ligado ao PINPAD ou POS |
| 729&minus;000 | REQUER_CONFIRMACAO           | (*O)     | Indica o status da confirmação da transação. 1: transação não requer confirmação, ou já confirmada. 2: transação requer confirmação/ Se campo não presente o AC pode confirmar a transação se houver cupom a ser impresso ou pela chave 375-028. |
| 731&minus;000 | TIPO_CARTAO                  | (I)(O)   | Tipo de cartão [0: qualquer / não definido (padrão) 1: crédito 2: débito 3: voucher] |
| 737&minus;000 | VIAS_IMPRIMIR                | (O)      | Indica quais vias devem ser impressas: 0: NENHUM, 1: imprimir a via do Cliente, 2: imprimir a via do Estabelecimento, 3: imprimir vias do Cliente e do Estabelecimento |
| 740&minus;000 | PAN_MASCARADO                | (O)      | Número do cartão utilizado na transação, sempre mascarado. |
| 741&minus;000 | NOME_PORTADOR_CARTAO         | (O)      | Nome do Cliente, extraído do cartão ou informado pelo emissor. |
| 742&minus;000 | NOME_PRODUTO                 | (O)      | Nome do Produto. Transações de venda: CREDITO, MASTERCARD DEBITO, etc. |
| 743&minus;000 | VALOR_DEVIDO                 | (O)      | Valor restante a pagar, em centavos. |
| 748&minus;000 | NOME_CARTAO_PADRAO           | (O)      | Nome do cartão padronizado, este campo poderá ser utilizado pelo AC para gerar relatório com base no nome do cartão. Caso o intuito for esse, utilizar este campo ao invés do 040-000. |
| 749&minus;000 | MODALIDADE_PAGAMENTO         | (O)      | Modalidade de pagamento: Cartão, carteira digital |
| 750&minus;000 | ID_PORTADOR_CARTEIRA_DIGITAL | (O)      | Forma de identificação do portador da carteira digital |
| 805&minus;000 | NUMERO_TELEFONE              | (O)      | Campo que fornece o telefone do cliente, informação retornada do Autorizador. |
| 999&minus;999 | REGISTRO_FINAL               | (*I)(*O) | Indica o final do arquivo. |
