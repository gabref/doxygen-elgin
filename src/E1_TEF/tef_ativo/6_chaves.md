@defgroup t24 Descrição das Chaves
@ingroup t2

## INFORMAÇÕES

`loja`:
Enviadopela Aplicação  Comercial  para  o ElginTefem  todos  os serviços e conterá o código da loja cadastrado dentro do estabelecimento noElginTef para a qual as transações serão realizadas

<!-- versao -->
`vercaoAc`:
Enviado obrigatoriamente no serviçoiniciar. Contém a versão de quem enviou(ElginTef ou Aplicação Comercial).

<!-- estado, statusClient -->
<!-- servico, servico -->

<!-- retorno, resultadoTransacao -->
<!-- tabela -->
<!-- As mensagens enviadas doElginTefpara aAplicação Comercialcomsucesso(retorno=”0”ou “1”) diferem por necessitar uma resposta (se sucessoou  não)  por  parte  daAplicação  Comercialou  não,  respectivamente.Normalmente, as transações que necessitam de confirmação, são as que fazemmovimentação  de  dinheiro  (ex.:  Vendas,  Pagamentos,  etc.),  sendo  que  asdemais não necessitam  (ex.: Consulta, Manutenção, etc.).  -->

<!-- terminal, identificadorPontoCaptura -->

mensagem, mensagemResultado
Mensagem complementar do serviço executado. Pode estar presente tanto emcaso de sucesso quanto em caso de erro. Pode ser enviada pelaAplicaçãoComercial parao ElginTef e vice-versa.No caso dos serviços coletar, mostrar e perguntar ela é obrigatória. Para maisdetalhes de como utilizar estes serviços recorrer aos seus respectivos tópicos.

<!-- aplicacao -->
`nomeAC`:
Enviado  obrigatoriamente  no  serviçoiniciar e contém o nome da aplicação.Quando enviado pelaAplicação Comercial deve conter o seu nome, e quandoenviado pelo ElginTef conterá "ElginTef".

`transacao`:
No servico=”consultar“oElginTefretornará  a  lista  de  transaçõeshabilitadas. Exemplo:transacao="Administracao Cancelar";"Cartao Vender";"Cheque Garantir";”Banco Pagar”;”Digital Pagar”N oservico=”executar”aAplicação  Comercial  deve  enviar  aoElginTef a transação a ser executada.

`sequencial`:
Deve estar presente em todas as mensagens. É um número sequencial únicocrescente, enviado pelaAplicação  Comercialpara  oElginTefa cadanovo  serviço  solicitado,  e  que  deve  permanecer  o  mesmo  durante  toda  aexecução  daquele  serviço.  OElginTefresponderá  com  o  mesmosequencial.  Se  aAplicação  Comercialenviar  um  sequencial  inválido  parainiciar um novo serviço, isto é, menor ou igual ao último utilizado, receberácomo resposta oretorno=”2”e o próximo sequencial válido. Este procedimentoé  útil  quando  aAplicação  Comercialfor  reiniciada,  perdendo  o  últimosequencial utilizado.

<!-- aplicacao_tela -->
`textoPinpad`:
Enviado pelaAplicação Comercial e conterá a informação a ser exibida na telado PIN-Pad. Deve ter no máximo 32 posições.

<!-- estabelecimento -->
`nomeEstabelecimento`:
Enviado pela Aplicação Comercial para o ElginTef em todos os serviços e conterá o código do estabelecimento cadastrado no ElginTef para o qual as transações serão realizadas.

## TRANSAÇÕES

<!-- transacao_nsu -->
`nsuTerminal`:
É  oNúmero  Sequencial  Único  (NSU)  gerado  peloElginTef  usado  paraidentificar uma transação dentro de uma rede em uma data especifica. Enviadopelo ElginTef para a Aplicação Comercial ao executar uma transação. Pode  ser  enviadopelaAplicação  Comercial  para  oElginTefnas transações  de  cancelamento,  reimpressão  e  tratamento  de  pendências,evitando assim sua coleta. Para processar a última transação deve-se enviarzero.

<!-- transacao_rede -->
`nomeProvedor`:
É  a  rede  responsável  pelo  roteamento  e/ou  execução  da  transação  (ex.:Banrisul,Cielo,Redecard,Tecban,  etc.),  também  conhecida  comocredenciadora.  Quando  enviado  pelaAplicação  Comercialconterá as redesque  podem  ser  utilizadas  na  transação  solicitada.  Quando  enviado  peloElginTef  conterá a rede que foi utilizada na execução da transação.No servico=”consultar” retornará as redes habilitadas.

<!-- transacao_valor -->
`valorTotal`:
Quando informado deve ser maior que zero e contém o valor da transação a serou  que  foi  executada.  Quando  enviado  peloElginTef,  é  o  valor  datransação que foi executada.Quando enviado pelaAplicação Comercial, éovalor  a  ser  apresentado  no  campo  de  coleta  do  valor  da  transação.  Setransacao_valor_minimoe / o utransacao_valor_maximo  f o r (e m )especificado(s), será permitido a alteração do valor da transação na sua coleta, respeitando os limites especificados

<!-- transacao_parcela -->
`numeroParcelas`:
Quando  informado  conterá  a  quantidade  de  parcelas.  Quando  enviado  pelaAplicação  Comercialconterá  a  quantidade  de  parcelas  a  ser  utilizada  naexecução  da  transação  solicitada.  Quando  enviado  peloElginTefconterá a quantidade de parcelas da transação executada.

<!-- transacao_produto -->
`nomeProduto`:
Produto é uma denominação muito utilizada hoje pelas redes de cartões, parapersonalizar  os  seus  produtos  (ex.:VisaVale,Voucher,VisaCash,CDC,PrivateLabel, etc.), e que se são ramificações das opçõesCréditoeDébito, seconfundindo com eles próprios. Quando especificado deve conter um produtoválido.  Quando  enviado  pelaAplicação  Comercialpara  oElginTefconterá  os  produtos  que  podem  ser  utilizados  na  execução  da  transaçãosolicitada.  Quando  enviado  peloElginTef  paraAplicação  Comercialconterá o produto utilizado na transação executada.Noservico=”consultar” será enviado peloElginTef para aAplicaçãoComercial os produtos disponiveis e suas respectivas redes.Exemplo:transacao_produto="VisaCash-Cielo”;”Credito-Redecard”;”Debito-Banrisul”;”PIX-Bradesco”;”PIX-Shipay” ...

<!-- transacao_nsu_rede -->
`nsuTransacao`:
É oNúmero Sequencial Único (NSU) gerado por algumasRedes usado paraidentificar  uma  transação.  Enviado  peloElginTefpara  aAplicaçãoComercial  ao  executar  uma  transação  quando  o  mesmo  existir,  isto  é,  forgerado pela Rede.

<!-- transacao_rede_cnpj -->
`cnpjCredenciadora`:
Enviado  peloElginTef  paraAplicação  Comercial,  normalmente  emuma transação aprovada, e contém o CNPJ da  Rede(chamada também deCredenciadora)  responsável  pelo  roteamento  e/ou  execução  da  transação,quando o CNPJ estiver cadastrado noElginTef. Está implementação é paraatender às exigências das Secretarias da Fazenda dos Estados referente aoPAF, ECF, NFC-e, SAT, etc..

<!-- transacao_pagamento -->
`formaPagamento`:
Quando informado deve ser"A vista","Parcelado"ou"Pre-datado". Quandoenviado  pelaAplicação  Comercialconterá  a  forma  de  pagamento  a  serutilizado na transação solicitada. Quando enviado peloElginTefconteráa forma de pagamento utilizado na transação executada.

<!-- transacao_financiado -->
`tipoFinanciamento`:
Aplica-se somente parapagamento="Parcelado". Quando especificado deveser "Estabelecimento"ou "Administradora". Quando enviado pela AplicaçãoComercialconterá  quem  deve  ser  o  financiador  utilizado  na  transaçãosolicitada. Quando enviado peloElginTefconterá o financiador utilizadona transação executada.

<!-- transacao_tipo_cartao -->
`tipoCartao`:
Quando  informado  deve  ser"Debito"  ou"Credito".  Quando  enviado  pelaAplicação  Comercialconterá os tipos de cartão que podem ser utilizados naexecução  da  transação  solicitada.  Quando  enviado  peloElginTefconterá o tipo de cartão utilizado na transação executada. 

<!-- transacao_autorizacao -->
`codigoAutorizacao`:
Quando existir conterá o código de autorização da transação que foi executada,normalmente gerado pela administradora.

<!-- transacao_cartao_numero -->
`panMascarado`:
Enviado pelaAplicação Comercial para oElginTef. Contém o númeroimpresso  no  cartão  e  é  utilizado  normalmente  em  transações  digitadas,  talcomo soluções WEB.

<!-- transacao_administradora -->
`nomeBandeira`:
É  a  administradora  responsável  pela  autorização  da  transação  (ex.: Banricompras,Mastercard,Santander,Visa,  etc.),  também  conhecida  comobandeira.  Quando  enviada  pelaAplicação  Comercialconterá  asadministradoras  que  podem  ser  utilizadas  na  transação  solicitada.  Quandoenviado  peloElginTefconterá  a  administradora  que  foi  utilizada  naexecução da transação.

<!-- transacao_codigo_vspague -->
`uniqueID`:
É um código único de transação criado pelo sistemaElginTef, e enviado peloElginTefparaAplicação Comercial. Ao solicitar um cancelamento oure-impressão, aAplicação  Comercialpode enviar este código para execuçãoda  transação.  Atransacao_codigo_vespaguenão deve ser mais utilizada eserá descontinuada em versões futuras.

<!-- transacao_comprovante_1via -->
`comprovanteDiferenciadoPortador`:
Quando especificado conterá(ão) o(s) comprovantes gerados pela execução datransação,  enviados  peloElginTefpara  aAplicação  Comercial.  Asequência  de  caracteresCarriage-Return/Line-Feed(CR/LFou0x0D/0x0A)serão utilizados para separar as linhas.

<!-- transacao_comprovante_2via -->
`comprovanteDiferenciadoLoja`:
Quando especificado conterá(ão) o(s) comprovantes gerados pela execução datransação,  enviados  peloElginTefpara  aAplicação  Comercial.  Asequência  de  caracteresCarriage-Return/Line-Feed(CR/LFou0x0D/0x0A)serão utilizados para separar as linhas.

<!-- transacao_administracao_senha -->
`admSenha`:
É  a  senha  do  usuário  enviado  pelaAplicação  Comercialpara  oElginTef para autenticação nas transações administrativas.

`admUsuario`:
transacao_administracao_usuario
É  o  código  do  usuário  enviado  pelaAplicação  Comercialpara  oElginTef para autenticação nas transações administrativas.


## COLETA

`automacao_coleta_tipo`:
Enviado  peloElginTefparaAplicação  Comercialsempre quando forcoletar alguma informação, e conterá o tipo de informação a ser coletada, onde:(*)Não exibivel podendo ser alfanumérico ou caracter especial;(A)Alfabético;(D)Data/hora;(N)Numérico com casas decimais ou não;(X)Alfanumérico;
Quando informado e automacao_coleta_mascara não informado, as máscaraspadrões serão:(*)Não exibivel com tamanho ilimitado;(A)Letras com tamanho ilimitado;(D)Data no formato "dd/MM/yy";(N)Numérico no formato ".";(X)Alfanumérico com tamanho ilimitado.

`automacao_coleta_opcao`:
Enviado  peloElginTef  paraAplicação  Comercial.Quando informadoconterá a lista com as opções permitidas para seleção. Uma delas deverá serselecionada. Os valores serão separados por ponto e virgula.  Seguem alguns exemplos:automacao_coleta_opcao="1.00";”2.00”;”3.00” indica  os  valores dos  quaisum deve ser selecionado ou coletado;
automacao_coleta_opcao="Redecard";"Cielo";"Hipercard"  lista  as  redes,das quais uma deve ser coletada;

`automacao_coleta_timeout`:
Pode ser enviado doElginTef paraAplicação Comercial e vice-versa.Quando  informado  conterá  o  tempo  máximo  em  segundos  que  o  enviadoraguardará  a  resposta  do  recebedor.  Quando  o  tempo  for  ultrapassado  atransação será abortada com retorno=”8”.

<!-- automacao_coleta_retorno -->
<!-- Código utilizado na interação entre o ElginTef e a Aplicação Comercial.Estará presente em todas as mensagens, e será utilizado para conduzir todo oprocesso. Após oElginTefreceber a solicitação de execução de uma transação daAplicação Comercial, e este estiver configurado para coletar as informaçõesatravés da Aplicação Comercial, chamado também de modoBackground.OV $ P a g u e C l i e n tco l e t a r á  a s  i n f o r ma ç õ e s  e n v i a n d oautomacao_coleta_retorno="0"e  r e c e b e n d o  a  r e sp o st a  c o mautomacao_coleta_retorno="0"  com  os  dados  solicitados  até  a  coleta  detodas informações necessárias para execução da transação. -->
<!-- adicionar coisas -->

<!-- automacao_coleta_mascara -->

<!-- automacao_coleta_mensagem, mensagemResultado -->

`automacao_coleta_informacao`:
Enviado  pelaAplicação  Comercialpara  oElginTef.  Contém  ainformação coletada pela Aplicação Comercial.

`automacao_coleta_sequencial`:
Número  sequencial  único  enviado  em  todas  as  mensagens,  para  garantir  aconsistencia na troca de informações entre oElginTefe  aAplicaçãoComercial.  Ao  iniciar  uma  nova  coleta  de  informações  oElginTefiniciará  este  valor  em  1  (um),  incrementando  de  1  em  1  a  cada  novamensagem, e a Aplicação Comercial deve devolver na mensagem de respostao mesmo valor recebido.

`automacao_coleta_palavra_chave`:
Enviada  peloElginTef  paraAplicação Comercial quando solicitado acoleta de alguma informação, e conterá a palavra-chave referente à informaçãoque está sendo coletada. Exemplos:automacao_coleta_palavra_chave="transacao_valor"  indica  a  coleta  dovalor da transação;automacao_coleta_palavra_chave="transacao_cartao_numero"indica  acoleta do número do cartão.

`automacao_coleta_mensagem_tipo`:
Pode ser enviado peloElginTef para Aplicação Comercial e vice-versa.Conterão os tipos de dados informados emautomacao_coleta_mensagem, eestão  diretamente  relacionados  às  suas  respectivas  ocorrências.  Os  tipospermitidos são os mesmos definidos em transacao_binario_tipo.ATENÇÃO: quando esta palavra-chave não estiver presente assumir o tipo TXTpara manter a compatibilidade com versões anteriores.