\defgroup sp2 E1_ElginPAY 
\brief Funções de pagamento simplificado
\ingroup g31

# Módulo E1_ElginPAY - Funções facilitadoras Elgin Pay

Todo o processo de pagamento usando a solução ElginPay ocorre atravez da biblioteca chamada `InterfaceAutomacao`, essa que possui muitos detalhes que precisam ser tratados pela aplicação que faz a integração, impressão de comprovantes, confirmação de transação, tratamento de transação pendente são alguns dos casos que precisam ser tratados quando a integração é feita via InterfaceAutomacao.
<br>Por esse motivo foi desenvolvido esse modulo de pagamento simplificado.<br>
Esse módulo tem como objetivo simplificar o processo de pagamento utilizando a solução ElginPay através de uma codificação simples e objetiva, onde é possivel realizar as principais transações com apenas uma chamada de função. Espera-se que esse modulo diminua o nivel de dificuldade na integração com a solução Elgin Pay e o tempo gasto para tal.


## Componentes

Para utilização desse módulo se faz necessário a importação dos componentes listados abaixo:

**E1** - Biblioteca padrão android(aar), onde estão definidas as funções facilitadoras. `e1-v1.0.14+`

**Interface Automacao** - Biblioteca padrão android(aar), onde estão exportadas todas as funções para iniciar uma transação de pagamento, cancelamento ou operações administrativas. `InterfaceAutomacao-v2.0.0.8+`

**cloud pos sdk** - Biblioteca padrão android(aar), dependência da biblioteca E1, responsável por acessar os periféricos do terminal de pagamento EP5855. `cloudpossdk-s-1.0.2+`

Todos os componentes acima devem ser adicionados como dependencias no projeto android. Normalmente são incluidos no arquivo build.gradle da aplicação.


## Por onde começar?
O primeiro passo será a importação das bibliotecas para o projeto. 
Para importar essas bibliotecas ao seu projeto, siga os passos abaixo.

- Copie as bibliotecas AAR listadas acima (<i>`e1-vx.y.z-release.aar`</i>,
<i>`cloudpossdk-s-1.0.2.aar`</i>, <i>`InterfaceAutomacao-v2.0.0.8.aar`</i>) para o diretório
<i>`libs`</i>, localizado no diretório do módulo que irá acessá-las.
Se o diretório <i>libs</i> não existir, crie-o.

- Adicione as seguintes linhas na seção <i>dependencies</i>, no arquivo
<i>build.gradle</i>, do módulo que usará as bibliotecas (esse arquivo está no
mesmo diretório da pasta <i>libs</i>):<br>

    > implementation files('libs/e1-vx.y.z-release.aar')
    > implementation files('libs/InterfaceAutomacao-v2.0.0.8.aar')
    > implementation files('libs/cloudpossdk-s-1.0.2.aar')
    > implementation "androidx.startup:startup-runtime:1.0.0"
    > implementation 'com.google.code.gson:gson:2.8.5'
    > implementation group: 'org.apache.commons', name: 'commons-lang3', version:'3.4'
    >
    > // https://mvnrepository.com/artifact/com.google.zxing/core
    > api group: 'com.google.zxing', name: 'core', version: '3.4.0'

- Agora basta importar a classe ElginPay<br>
    \code{.java}
    import com.elgin.e1.Pagamento.ElginPay;
    \endcode
- E chamar a função de transação desejada<br>
    \code{.java}
    ElginPay elginPay = new ElginPay();
    elginPay.IniciaVendaDebito("1000", MainActivity.this, handler);
    \endcode
- O retorno será obtido conforme trecho abaixo
    \code{.java}
    private Handler handler = new Handler(Looper.getMainLooper()){
        @Override
        public void handleMessage(@NonNull Message msg) {
            super.handleMessage(msg);
            String saida = (String) msg.obj;
        }
    };
    \endcode


\defgroup sp21 Retorno
\ingroup sp2

## Detalhes de Retorno Transação 
Todas as funções de transação são executadas em um processo paralelo para evitar que o app fique travado aguardando resposta. <br>
Por esse motivo as função exigem um parametro tipo Handler da classe  ```android.os.Handler``` com a implementação do metodo ```handleMessage(Message msg)```
que é para onde as respostas serão enviadas ao fim da transação.

A resposta da transação sera enviada em um objeto tipo String no formato JSON.<br>
Abaixo um exemplo da implementação
\code{.java}
    private Handler handler = new Handler(Looper.getMainLooper()){
        @Override
        public void handleMessage(@NonNull Message msg) {
            super.handleMessage(msg);
            String saida = (String) msg.obj;
        }
    };
\endcode

Abaixo estão listados todas informações do JSON retornado na saida da transação.

|           Parâmetro               |                           Descrição                                            |                     Retorno                        |   Tipo de Dado  |
| --------------------------------- | ------------------------------------------------------------------------------ | ---------------------------------------------------|-----------------|
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
|dataHoraTransacao                  |Data\\hora da transação                                                         |Data\\hora da transação-dd/MM/yyyy HH:mm:ss         |String           |
|comprovanteCompleto                |Comprovante completo da transação                                               |Comprovante completo                                |String           |
|dataHoraTransacaoOriginal          |Data\\hora da transação original                                                |Data\\hora da transação original-dd/MM/yyyy HH:mm:ss|String           |
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
