@defgroup t24 Descrição das Chaves
@ingroup t2

# Chaves {#tef_api_chaves}

## INFORMAÇÕES {#tef_api_informacoes}

`loja`:
Conterá o código da loja cadastrado dentro do estabelecimento no ElginTef para a qual as transações serão realizadas. A automação comercial cadastrará esse dado apenas uma vez usando a função @ref ConfigurarDadosPDV

<!-- versao -->
`vercaoAc`:
Contém a versão da automação comercial. A automação comercial cadastrará esse dado apenas uma vez usando a função @ref ConfigurarDadosPDV
Enviado obrigatoriamente no serviçoiniciar.

<!-- estado, statusClient -->
<!-- servico, servico -->

<!-- retorno, retorno -->
<!-- tabela -->
`retorno`:
Contém o código com a solicitação ou resultado do serviço, onde:

| Código | Situação | ElginTef -> Aplicação Comercial            | Aplicação Comercial -> ElginTef |
| :----: | :------: | :----------------------------------------- | :------------------------------ |
|    0   | sucesso  | Com confirmação da **Aplicação Comercial** | Confirmar transação             |
|    1   | sucesso  | Sem confirmação da **Aplicação Comercial** | Executar serviço                |
|    2   | erro     | Sequencial inválido                        |                                 |
|    3   | erro     | Transação cancelada pelo operador          |                                 |
|    4   | erro     | Transação cancelada pelo cliente           |                                 |
|    5   | erro     | Parâmetros insuficientes ou inválidos      |                                 |
|    6   | erro     | Problemas na conexão do ElginTef           |                                 |
|    7   | erro     | Problemas entre o ElginTef e a Rede        |                                 |
|    8   | erro     | Tempo limite de espera excedido            | Tempo limite de espera excedido |
|    9   | erro     | Problema desconhecido                      | Cancelar transação              |

As mensagens enviadas do ElginTef para a Aplicação Comercial com sucesso (retorno="0"ou "1") diferem por necessitar uma resposta (se sucesso ou  não)  por  parte  da Aplicação  Comercial ou  não,  respectivamente. Normalmente, as transações que necessitam de confirmação, são as que fazem movimentação  de  dinheiro  (ex.:  Vendas,  Pagamentos,  etc.),  sendo  que  asdemais não necessitam.

<!-- terminal,  -->
`identificadorPontoCaptura`:
Enviado pela Aplicação  Comercial  para  o ElginTef em  todos  os serviços e conterá o código do terminal cadastrado dentro da loja no ElginTef através do qual as transações serão realizadas.

<!-- mensagem -->
`mensagemResultado`:
Mensagem complementar do serviço executado. Pode estar presente tanto em caso de sucesso quanto em caso de erro. Pode ser enviada pela Aplicação Comercial para o ElginTef e vice-versa. No caso do serviço coletar ela é obrigatória.

<!-- aplicacao -->
<!-- `nomeAC`: -->
<!-- Contém o nome da aplicação. Quando enviado pela Aplicação Comercial deve conter o seu nome. -->

<!-- `transacao`: -->
<!-- No servico=”consultar“oElginTefretornará  a  lista  de  transaçõeshabilitadas. Exemplo:transacao="Administracao Cancelar";"Cartao Vender";"Cheque Garantir";”Banco Pagar”;”Digital Pagar”N oservico=”executar”aAplicação  Comercial  deve  enviar  aoElginTef a transação a ser executada. -->

`sequencial`:
Deve estar presente em todas as mensagens. É um número sequencial único crescente, enviado pela Aplicação  Comercial para o ElginTef a cada novo  serviço  solicitado,  e  que  deve  permanecer  o  mesmo  durante  toda  a execução  daquele  serviço.  O ElginTef responderá  com  o  mesmo sequencial.  Se a Aplicação Comercial enviar um sequencial inválido para iniciar um novo serviço, isto é, menor ou igual ao último utilizado, receberá como resposta o `retorno="2"` e o próximo sequencial válido. Este procedimento é  útil  quando  a Aplicação  Comercial for  reiniciada,  perdendo  o  último sequencial utilizado.

<!-- aplicacao_tela -->
`textoPinpad`:
Enviado pela Aplicação Comercial e conterá a informação a ser exibida na telado PIN-Pad. Deve ter no máximo 32 posições.

<!-- estabelecimento -->
`nomeEstabelecimento`:
Conterá o código do estabelecimento cadastrado no ElginTef para o qual as transações serão realizadas. A automação comercial cadastrará esse dado apenas uma vez usando a função @ref ConfigurarDadosPDV

## TRANSAÇÕES {#tef_api_transacoes}

<!-- transacao_nsu -->
`nsuTerminal`:
É  o Número  Sequencial  Único  (NSU)  gerado  pelo ElginTef  usado  para identificar uma transação dentro de uma rede em uma data especifica. Enviado pelo ElginTef para a Aplicação Comercial ao executar uma transação. Pode  ser  enviado pela Aplicação  Comercial  para  o ElginTef nas transações  de  cancelamento,  reimpressão  e  tratamento  de  pendências, evitando assim sua coleta. Para processar a última transação deve-se enviar zero.

<!-- transacao_rede -->
<!-- `nomeProvedor`: -->
<!-- É  a  rede  responsável  pelo  roteamento  e/ou  execução  da  transação  (ex.:Banrisul,Cielo,Redecard,Tecban,  etc.),  também  conhecida  comocredenciadora.  Quando  enviado  pelaAplicação  Comercialconterá as redesque  podem  ser  utilizadas  na  transação  solicitada.  Quando  enviado  peloElginTef  conterá a rede que foi utilizada na execução da transação.No servico=”consultar” retornará as redes habilitadas. -->

<!-- transacao_valor -->
`valorTotal`:
Quando informado deve ser maior que zero e contém o valor da transação a ser ou  que  foi  executada.  Quando  enviado  pelo ElginTef,  é  o  valor  da transação que foi executada. Quando enviado pela Aplicação Comercial, é o valor  a  ser  apresentado  no  campo  de  coleta  do  valor  da  transação.

<!-- transacao_parcela -->
`numeroParcelas`:
Quando  informado  conterá  a  quantidade  de  parcelas.  Quando  enviado  pela Aplicação  Comercial conterá  a  quantidade  de  parcelas  a  ser  utilizada  na execução  da  transação  solicitada.  Quando  enviado  pelo ElginTef conterá a quantidade de parcelas da transação executada.

<!-- transacao_produto -->
<!-- `nomeProduto`: -->
<!-- Produto é uma denominação muito utilizada hoje pelas redes de cartões, para personalizar  os  seus  produtos  (ex.:VisaVale,Voucher,VisaCash,CDC,PrivateLabel, etc.), e que se são ramificações das opçõesCréditoeDébito, seconfundindo com eles próprios. Quando especificado deve conter um produtoválido.  Quando  enviado  pelaAplicação  Comercialpara  oElginTefconterá  os  produtos  que  podem  ser  utilizados  na  execução  da  transaçãosolicitada.  Quando  enviado  peloElginTef  paraAplicação  Comercialconterá o produto utilizado na transação executada.Noservico=”consultar” será enviado peloElginTef para aAplicaçãoComercial os produtos disponiveis e suas respectivas redes.Exemplo:transacao_produto="VisaCash-Cielo”;”Credito-Redecard”;”Debito-Banrisul”;”PIX-Bradesco”;”PIX-Shipay” ... -->

<!-- transacao_nsu_rede -->
`nsuTransacao`:
É o Número Sequencial Único (NSU) gerado por algumas Redes usado para identificar  uma  transação.  Enviado  pelo ElginTef para  a Aplicação Comercial  ao  executar  uma  transação  quando  o  mesmo  existir,  isto  é,  for gerado pela Rede.

<!-- transacao_rede_cnpj -->
`cnpjCredenciadora`:
Enviado  pelo ElginTef  para Aplicação  Comercial,  normalmente  em uma transação aprovada, e contém o CNPJ da  Rede (chamada também de Credenciadora)  responsável  pelo  roteamento  e/ou  execução  da  transação, quando o CNPJ estiver cadastrado no ElginTef. Está implementação é para atender às exigências das Secretarias da Fazenda dos Estados referente ao PAF, ECF, NFC-e, SAT, etc..

<!-- transacao_pagamento -->
`formaPagamento`:
Quando informado deve ser "A vista", "Parcelado" ou "Pre-datado". Quando enviado  pela Aplicação  Comercial conterá  a  forma  de  pagamento  a  ser utilizado na transação solicitada. Quando enviado pelo ElginTef conterá a forma de pagamento utilizado na transação executada.

<!-- transacao_financiado -->
`tipoFinanciamento`:
Aplica-se somente para pagamento="Parcelado". Quando especificado deve ser "Estabelecimento" ou "Administradora". Quando enviado pela Aplicação Comercial conterá  quem  deve  ser  o  financiador  utilizado  na  transação solicitada. Quando enviado pelo ElginTef conterá o financiador utilizado na transação executada.

<!-- transacao_tipo_cartao -->
`tipoCartao`:
Quando  informado  deve  ser "Debito"  ou "Credito".  Quando  enviado  pela Aplicação  Comercial conterá os tipos de cartão que podem ser utilizados na execução  da  transação  solicitada.  Quando  enviado  pelo ElginTef conterá o tipo de cartão utilizado na transação executada. 

<!-- transacao_autorizacao -->
`codigoAutorizacao`:
Quando existir conterá o código de autorização da transação que foi executada, normalmente gerado pela administradora.

<!-- transacao_cartao_numero -->
`panMascarado`:
Enviado pela Aplicação Comercial para o ElginTef. Contém o número impresso  no  cartão  e  é  utilizado  normalmente  em  transações  digitadas.

<!-- transacao_administradora -->
`nomeBandeira`:
É  a  administradora  responsável  pela  autorização  da  transação  (ex.: Banricompras, Mastercard, Santander, Visa,  etc.),  também  conhecida  como bandeira.  Quando  enviada  pela Aplicação  Comercial conterá  as administradoras  que  podem  ser  utilizadas  na  transação  solicitada.  Quando enviado  pelo ElginTef conterá  a  administradora  que  foi  utilizada  na execução da transação.

<!-- transacao_codigo_vspague -->
<!-- `uniqueID`: -->
<!-- É um código único de transação criado pelo sistema ElginTef, e enviado pelo ElginTef para Aplicação Comercial. Ao solicitar um cancelamento ou re-impressão, a Aplicação  Comercial pode enviar este código para execução da  transação.  A uniqueID não deve ser mais utilizada e será descontinuada em versões futuras. -->

<!-- transacao_comprovante_1via -->
`comprovanteDiferenciadoPortador`:
Quando especificado conterá(ão) o(s) comprovantes gerados pela execução da transação,  enviados  pelo ElginTef para  a Aplicação  Comercial.  A sequência  de  caracteres Carriage-Return/Line-Feed (CR/LFou0x0D/0x0A) serão utilizados para separar as linhas.

<!-- transacao_comprovante_2via -->
`comprovanteDiferenciadoLoja`:
Quando especificado conterá(ão) o(s) comprovantes gerados pela execução da transação,  enviados  pelo ElginTef para  a Aplicação  Comercial.  A sequência  de  caracteres Carriage-Return/Line-Feed (CR/LFou0x0D/0x0A) serão utilizados para separar as linhas.

<!-- transacao_administracao_senha -->
`admSenha`:
É  a  senha  do  usuário  enviado  pela Aplicação  Comercial para  o ElginTef para autenticação nas transações administrativas.

<!-- transacao_administracao_usuario -->
`admUsuario`:
É  o  código  do  usuário  enviado  pela Aplicação  Comercial para  o ElginTef para autenticação nas transações administrativas.


## COLETA {#tef_api_coleta}

`automacao_coleta_tipo`:
Enviado  pelo ElginTef para Aplicação  Comercial sempre quando for coletar alguma informação, e conterá o tipo de informação a ser coletada, onde:
   * (*) Não exibivel podendo ser alfanumérico ou caracter especial;
   * (A) Alfabético;
   * (D) Data/hora;
   * (N) Numérico com casas decimais ou não;
   * (X) Alfanumérico;

Quando informado e `automacao_coleta_mascara` não informado, as máscaras padrões serão:
   * (*) Não exibivel com tamanho ilimitado;
   * (A) Letras com tamanho ilimitado;
   * (D) Data no formato "dd/MM/yy";
   * (N) Numérico no formato ".";
   * (X) Alfanumérico com tamanho ilimitado.

`automacao_coleta_opcao`:
Enviado  pelo ElginTef  para Aplicação  Comercial. Quando informado conterá a lista com as opções permitidas para seleção. Uma delas deverá ser selecionada. Os valores serão separados por ponto e virgula.  Seguem alguns exemplos:
   * `automacao_coleta_opcao="1.00";”2.00”;”3.00”` indica  os  valores dos  quais um deve ser selecionado ou coletado;
   * `automacao_coleta_opcao="Redecard";"Cielo";"Hipercard"`  lista  as  redes, das quais uma deve ser coletada;

`automacao_coleta_timeout`:
Pode ser enviado do ElginTef para Aplicação Comercial e vice-versa. Quando  informado  conterá  o  tempo  máximo  em  segundos  que  o  enviador aguardará  a  resposta  do  recebedor.  Quando  o  tempo  for  ultrapassado  a transação será abortada com retorno=”8”.

`automacao_coleta_retorno`:
Código utilizado na interação entre o ElginTef e a Aplicação Comercial. Estará presente em todas as mensagens, e será utilizado para conduzir todo o processo. Após o ElginTef receber a solicitação de execução de uma transação da Aplicação Comercial, e este estiver configurado para coletar as informações através da Aplicação Comercial, o ElginTef coletará as informações enviando `automacao_coleta_retorno='0'` e recebendo a resposta com `automacao_coleta_retorno='0'` com os dados solicitados até a coleta de todas as informações necessárias para execução da transação.

<!-- automacao_coleta_mascara -->
<!-- Enviado pelo ElginTef para a Aplicação Comercial. Quando informado conterá a máscara de coleta, que determinará também o tamanho máximo da informação. Os 3 pontos (...) indica tamanho variável. Segue:
   * *...*  Utilizado na coleta de informações confidenciais. A cada caracter digitado deve ser exibido um asterisco (*) na tela;
   * X...X  Utilizado na coleta de campos alfabéticos e alfanuméricos;
   * dd?MM?y...y hh?mm?ss?SSS  Utilizado na coleta de data e/ou hora, onde:
       * dd    é o dia do mês;
       * MM    é o mês;
       * y...y é o ano;
       * hh    é a hora;
       * mm    é o minuro;
       * ss    é o segundos
       * SSS   são os milésimos de segundos;
       * ?     qualquer símbolo delimitador;
   * ###...##.#...#  Utilizado na coleta de campos numéricos. A máscara constitui de "#" para  os  digitos  numéricos  (0  a  9),  e  do "."  para  indicar  a possibilidade de casas decimais. Por exemplo:
       * "###.##"  indica que o valor deve ter no máximo 3 casas inteiras e 2 decimais;
       * "###"     indica que o valor deve ter no máximo 3 casas inteiras;
       * ""        indica  que  o  valor  pode  ter  quantidade  ilimitada  de casas;
       * "."       indica  que  o  valor  pode  ter  quantidade  ilimitada  de casas inteiras e casas decimais;
       * ".##"     indica  que  o  valor  pode  ter  quantidade  ilimitada  de casas inteiras e até 2 casas decimais;
       * "#."      indica que o valor pode ter quantidade de até 1 casa inteira e quantidade ilimitada de casas decimais;
   * x...A?a...N?x...N?n...X  Utilizado para coleta de campos alfanuméricos com pré-definição do tipo  do  dado  para  cada  posição.  O  caracter  maiúsculo  indica  a obrigatoriedade  de  preenchimento  e  o  minúsculo  não.  Pode-se inserir  caracteres  especiais  na  máscara  para  auxiliar  no entendimento. Onde:
       * A ou a é um caractere alfabético;
       * H ou h é um caractere hexadecimal (0 a 9 e A a F);
       * N ou n é um caractere numérico;
       * X ou x é um caractere alfanumérico;
       * ?      qualquer simbolo especial a ser apresentado com a máscara para auxiliar o entendimento do usuário.
   * Exemplos:
       * xxXXXXXX      coleta de um código de autorização;
       * hh.hh.HH      coleta de um valor hexadecimal;
       * NN.NNN-NNN    coleta do CEP;
       * nnn.nnN-X     coleta de número de conta bancária;
       * (NN) nNNNN-NNNN coleta de telefone;NNN.NNN.NNN-NNcoleta do CPF;
       * NN.NNN.NNN/NNNN-NN coleta do CNPJ;
       * HHHHHHHH-HHHH-HHHH-HHHH-HHHHHHHHHHHH coleta de chave PIX aleatória. -->


<!-- automacao_coleta_mensagem, mensagemResultado -->
`mensagemResultado`:
Enviado pelo ElginTef para Aplicação Comercial e vice-versa. 
Quando enviado pelo ElginTef para a Aplicação Comercial e coletando alguma informação conterá o título do campo a ser coletado, e se não coletando conterá  uma  mensagem  a  ser  exibida  pela Aplicação  Comercial  para  o operador. Pode  ser  enviado  pela Aplicação  Comercial para  ElginTef,  por exemplo quando uma transação for abortada e a Aplicação Comercial quer informar o motivo. 
Esta mensagem poderá conter mais de uma linha, quando existirão a sequênciade caracteres Carriage-Return/Line-Feed (CR/LFou0x0D/0x0A) para separá-las, e neste caso deve ser exibida semelhante a um comprovante, de forma que o operador possa visualizar todo seu conteúdo.

`automacao_coleta_informacao`:
Enviado  pela Aplicação  Comercial para  o ElginTef.  Contém  a informação coletada pela Aplicação Comercial.

`automacao_coleta_sequencial`:
Número  sequencial  único  enviado  em  todas  as  mensagens,  para  garantir  a consistencia na troca de informações entre o ElginTef e  a Aplicação Comercial.  Ao  iniciar  uma  nova  coleta  de  informações  o ElginTef iniciará  este  valor  em  1  (um),  incrementando  de  1  em  1  a  cada  nova mensagem, e a Aplicação Comercial deve devolver na mensagem de resposta o mesmo valor recebido.

`automacao_coleta_palavra_chave`:
Enviada  pelo ElginTef  para Aplicação Comercial quando solicitado a coleta de alguma informação, e conterá a palavra-chave referente à informação que está sendo coletada. Exemplos: `automacao_coleta_palavra_chave="transacao_valor"`  indica  a  coleta  do valor da transação;`automacao_coleta_palavra_chave="transacao_cartao_numero"` indica  a coleta do número do cartão.

<!-- `automacao_coleta_mensagem_tipo`: -->
<!-- Pode ser enviado pelo ElginTef para Aplicação Comercial e vice-versa. Conterão os tipos de dados informados em automacao_coleta_mensagem, e estão  diretamente  relacionados  às  suas  respectivas  ocorrências.  Os  tipos permitidos são os mesmos definidos em transacao_binario_tipo.ATENÇÃO: quando esta palavra-chave não estiver presente assumir o tipo TXT para manter a compatibilidade com versões anteriores. -->
