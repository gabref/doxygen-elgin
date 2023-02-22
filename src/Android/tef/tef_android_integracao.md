@defgroup ma63 Integração ElginTef
@ingroup ma6
@brief Integração com a ElginTef API

Neste ponto vamos explorar toda a API de ponta a ponta. O objetivo desta seção é:
    * Detalhar a configuração das dependências
    * Detalhar as assinaturas das funções
    * Explorar e exemplificar a utilização das tecnologias adotadas para integração.

## Configuração de dependências
Projetos desenvolvidos em Android em sua grande maioria necessita de dependências de bibliotecas prontas de terceiros para agilizar e facilitar o nosso trabalho. Estas dependências são adicionadas nas configurações do projeto. \n

A forma mais utilizada é adicionando em um diretório chamado `libs`. É recomendado que esse diretório seja adicionado dentro de `app`, conforme a figura abaixo.

@image html tef-libs.jpg

Após a criação deste diretório, vamos ao que interessa, adicionar as bibliotecas que utilizaremos no projeto. 

### Bibliotecas e dependências externas
As bibliotecas que utilizaremos no projeto são quatro `AAR` (um arquivo AAR contém uma biblioteca de software usada para desenvolver aplicativos Android). Dois são de nossa propriedade e os demais são fornecidos por parceiros, eles são:
    1. core-[versão atual].aar
    2. pagamentos-[versão atual].aar
    3. tef_componente1.arr
    4. tef_componente2.arrr


\n

Com estas bibliotecas configuradas no arquivo `build.gradle`(:app) do projeto você consegue iniciar o desenvolvimento da sua aplicação chamando as funções da seguinte maneira:
    * `import com.elgin.e1.pagamentos.tef.*;`

Mas ainda existe mais uma *lib* externa que devemos adicionar para dar suporte nas conversões internas:
    * `implementation 'com.squareup.retrofit2:converter-gson:2.9.0`

Sua configurações no arquivo build.gradle(:app) deve conter os componentes conforma abaixo:

@code{.java}
dependencies {
    // TEF
    implementation files('libs/core-v1_beta.aar')
    implementation files('libs/pagamentos-v1_beta.aar')
    implementation files('libs/tef_componente1.aar')
    implementation files('libs/tef_componente2.aar')
    // Default
    implementation 'com.squareup.retrofit2:converter-gson:2.9.0'
    // arquivos default
    // ...
}
@endcode

## Definição das Funções da API
A descrição de todas as funções disponíveis na API estão descritas na seção @ref ma60.

\n
setContext() \n
setHandler() \n
InformarDadosAutomacao() \n
AtivarTerminal() \n
ObterMensagemProgresso() \n
ObterDadosTransacao() \n
ObterOpcaoColeta() \n
InformarOpcaoColeta() \n
RealizarTransacaoDebito() \n
RealizarTransacaoCredito() \n
RealizarCancelamentoOperacao() \n
RealizarCancelamentoTransacao() \n
ImprimirRelatorioDiario() \n
ReimprimirUltimoComprovante() \n
iniciarTransacaoPIX() \n

## Handler - Como utilizar na API
Aqui vamos explorar este tipo de dado que é responsável direto por enviar e receber mensagens para a API após as transações (venda, cancelamento ou administrativas) serem inicializadas. Se a implementação estiver errada, provavelmente você receberá informações nos passos errados durante uma operação. Então vamos deixar claro a forma que estamos utilizando este componente em nossa API.

### Definiçao de Handler
Um Handler permite que você envie e processe o `Message` e objetos `Runnable` associados a uma thread `MessageQueue`. Cada instância do Handler está associada a um único encadeamento e à fila de mensagens desse encadeamento. Quando você cria um Handler, ele é vinculado a um arquivo `Looper`. Ele entregará mensagens e executáveis para a fila de mensagens desse *Looper* e os executará no encadeamento desse *Looper*. Fonte [Handler Android](https://developer.android.com/reference/android/os/Handler).

@image html tef-looper.jpg

Em nosso exemplo vamos fazer a instância do objeto *Handler* com a sobrecarga de `Looper.getMainLooper()` (classe usada para executar um *loop* de mensagem para uma Thread, no caso a UI Thread para a aplicação Android) e implementar a sobrecarga de `handleMessage(Message msg)`. Por exemplo:

@code{.java}
class Teste {
    final Handler handler = new Handler(Looper.getMainLooper()) {
        @Override
        public void handleMessage(@NonNull Message message) {

        }
    }
}
@endcode

## Message - Como utilizar com a API
Agora que já vimos a definição e como instanciar um objeto *Handler*, vamos explorar um pouco o componente auxiliar *Message*, que será utilizado como parâmetro da função `handleMessage`. Ele vai nos indicar em qual passo a API está e com isso, receberemos valores que serão responsáveis por apresentar mensagens, apresentar opções para escolha do operador, receber os dados da transação (venda, cancelamento, reimpressão ou relatórios).

### Definição de Message
Define uma mensagem contendo uma descrição e um objeto de dados arbitrário que pode ser enviado para um arquivo *Handler*. Esse objeto contém dois campos `int` extras e um campo de objeto extra que permite que você não faça alocações em muitos casos. Fonte [Message - Android](https://developer.android.com/reference/android/os/Message).

### Propriedades do Message para API
**what**: Código de mensagem difinido pelo usuário para que o destinatário possa identificar do que se trata esta mensagem.

**obj**: Um objeto arbitrário para enviar ao destinatário.

A seguir, o código mostra que para cada valor de 1 - 4 que a propriedade `what` recebe uma ação diferente é tomada com conteúdo recebido na propriedade `obj`.

@code{.java}
public void handleMessage(@NonNull Message message) {
    switch (message.what) {
        case 1:
        teste1(message.obj);
        break;
    case 2:
        teste2(message.obj);
        break;
    case 3:
        teste3(message.obj);
        break;
    case 4:
        teste4(message.obj);
        break;
    }
}
@endcode

## Utilizando ElginTef & Handler & Message
Já tivemos uma visão geral dos componentes acima, agora chegou o momento de colocar a mão na massa. Muito conteúdo até aqui? Sim, você precisa entender o porquê está utilizando isto.

### Passo 1 - Definição dos `what` para o Message
Para que possa receber as mensagens de processo da transação, você deve definir em sua aplicação os seguintes `message.what`:
    * Mensagens de progresso = 1
    * Opções de coleta = 2 
    * Dados da transação = 3
    * Finalização = 4

O exemplo abaixo mostra como você deverá definir o `message.what` conforme o progresso da transação. 

@note Vale a pena ressaltar que essas mensagens não tem uma sequência a ser seguida e sim as respostas dos `callbacks` (função passada a outra função como argumento, que é então invocada dentro da função externa para completar algum tipo de rotina ou ação) internos da API.

@code{.java}
public void handleMessage(@NonNull Message message) {
    String value = null;

    try {
        if (message.what == 1) { // MENSAGEM DE PROGRESSO
        
        } else if (message.what == 2) { // OPÇÃO DE COLETA
        
        } else if (message.what == 3) { // DADOS DA TRANSAÇÃO
        
        } else if (message.what == 4) { // FINALIZAR
        
        } else {

        }
    } catch (Exception e) {

    }
}
@endcode

### Passo 2 - Adicionando as Funções da API
Vamos dividir este passo em duas etapas:
    1. Usando as funções da API
    2. Usando o retorno de `obj` (Opcional)

### Usando as funções da API
Este modelo foi desenvolvido para quem prefere utilizar algo mais verboso, com um nome e objetivos definidos na assinatura da função. O código a seguir mostra quais funções devem ser utilizadas em cada um dos códigos definidos anteriormente.

@code{.java}
public void handleMessage(@NonNull Message message) {
    String value = null;

    try {
        if (message.what == 1) { // MENSAGEM DE PROGRESSO
            value = ElginTef.ObterMensagemProgresso();
            // REALIZAR TRATAMENTO PARA APRESENTAÇÃO DA MENSAGEM    
        } else if (message.what == 2) { // OPÇÃO DE COLETA
            value = ElginTef.ObterOpcaoColeta();
            // REALIZAR TRATAMENTO PARA APRESENTAÇÃO DA LISTA    
        } else if (message.what == 3) { // DADOS DA TRANSAÇÃO
            value = ElginTef.ObterDadosTransacao();
            // REALIZAR TRATAMENTO PARA DESERIALIZAR STRING NO FORMATO JSON
        } else if (message.what == 4) { // FINALIZAR
            value = ElginTef.ObterMensagemProgresso();
            // REALIZAR TRATAMENTO PARA FINALIZAR SUA APLICAÇÃO OU APRESENTAÇÃO
        } else {

        }
    } catch (Exception e) {

    }
}
@endcode

### Utilizando o retorno de `obj` (Opcional)
Este modelo é opcional para quem prefere utilizar as propriedades que os tipos de dados oferecem, até mesmo para explorar novas tecnologias. A ideia é compartilhar conhecimento, trazer novas ideias para utilização de determinadas coisas que não são usuais para alguns desenvolvedores. A figura abaixo mostra como será utilizado o modelo, a diferença é bem sutil e mesmo utilizando o mesmo objeto os retornos são diferentes. **Fiquem atentos a isto quando utilizar esse modelo**.

@code{.java}
public void handleMessage(@NonNull Message message) {
    Object value = null

    try {
        if (message.what == 1) { // MENSAGEM DE PROGRESSO
            value = message.obj;
            // REALIZAR TRATAMENTO PARA APRESENTAÇÃO DA MENSAGEM    
        } else if (message.what == 2) { // OPÇÃO DE COLETA
            value = message.obj;
            // REALIZAR TRATAMENTO PARA APRESENTAÇÃO DA LISTA    
        } else if (message.what == 3) { // DADOS DA TRANSAÇÃO
            value = message.obj;
            // REALIZAR TRATAMENTO PARA DESERIALIZAR STRING NO FORMATO JSON
        } else if (message.what == 4) { // FINALIZAR
            // REALIZAR TRATAMENTO PARA FINALIZAR SUA APLICAÇÃO OU APRESENTAÇÃO
        } else {

        }
    } catch (Exception e) {

    }
}
@endcode