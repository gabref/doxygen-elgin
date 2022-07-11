@defgroup sp3 PIX
@brief Funções de PIX
@ingroup g31

# Módulo PIX


O processo de pagamento PIX ocorre por meio da biblioteca chamada `pagamentos-V1.0-dev-release.aar`. Essa biblioteca tem funções que facilitam o fluxo de uma transação PIX. 

## Fluxo da Transação

Os elementos necessários para que a transação PIX seja feita são: Autenticação, Geração do QRCode e Consulta do QRCode.
* **Autenticação**: irá identificar para quem é a transação
* **Geração QRCode**: irá gerar o QRCode da transação
* **Consulta QRCode**: irá verificar se a transação foi finalizada.

## Componentes

Para utilizar esse módulo deverão ser importados no projeto os seguintes componentes:

**Pagamentos**: Biblioteca padrão Android (aar), Modulo de Pagamento que contempla as funcionalidade de pix `pagamentos-V1.0-dev-release.aar`<br>
**Comunicação**: Biblioteca padrão Android (aar), Modulo de comunicação HTTP necessário para as requisições PIX `comunicacao-release.aar`

@warning
A biblioteca de pagamento possui versão de homologação e produção.
Certifique-se de usar a versão de homologação durante sua implementação e após finalizada altere para a versão de produção.
 * Versão de desenvolvimento: `pagamentos-V1.0-dev-release.aar`
 * Versão de produção: `pagamentos-V1.0-prod-release.aar`

### Modo Ativo

A transaçao acontece automaticamente.
1. envia para a API a chave e o valor
2. API toma controle até o final da transação: gera qr code, consulta o status do pagamento em intervalos de 1 segundo até que a transação seja finalizada. 
3. API retorna o Json.


## Por onde começar?
O primeiro passo será a importação das bibliotecas para o projeto. 
Para importar essas bibliotecas ao seu projeto, siga os passos abaixo.

- Copie as bibliotecas AAR listadas acima (<i>`pagamentos-V1.0-dev-release.aar`</i>, <i>`comunicacao-release.aar`</i>) para o diretório
<i>`libs`</i>, localizado no diretório do módulo que irá acessá-las.
Se o diretório <i>libs</i> não existir, crie-o.

- Adicione as seguintes linhas na seção <i>dependencies</i>, no arquivo
<i>build.gradle</i>, do módulo que usará as bibliotecas (esse arquivo está no
mesmo diretório da pasta <i>libs</i>):<br>

    @code{.java}
        implementation 'com.squareup.retrofit2:retrofit:2.9.0'
        implementation 'com.squareup.retrofit2:converter-gson:2.9.0'
        implementation 'com.squareup.retrofit2:converter-scalars:2.9.0'
        implementation 'com.squareup.okhttp3:okhttp:4.9.3'
        implementation 'com.squareup.okhttp3:logging-interceptor:4.9.3'
        implementation files('libs/pagamentos-debug.aar')
        implementation files('libs/comunicacao-debug.aar')
    @endcode

- Agora basta importar a classe pixElgin<br>
    @code{.java}
        import com.elgin.e1.pagamentos.pix.PIXElgin;
    @endcode
- E chamar a função de transação desejada<br>
    @code{.java}
        PIXElgin pixElgin = new PIXElgin("<chave-autenticação>");
        pixElgin.iniciarVendaPIX("1000", MainActivity.this, handler);
    @endcode
- O retorno será obtido conforme trecho abaixo
    @code{.java}
    private Handler handler = new Handler(Looper.getMainLooper()){
        @Override
        public void handleMessage(@NonNull Message msg) {
            super.handleMessage(msg);
            String saida = (String) msg.obj;
        }
    };
    @endcode
 