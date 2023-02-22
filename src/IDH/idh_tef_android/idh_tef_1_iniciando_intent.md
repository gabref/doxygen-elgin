@defgroup idh200 Iniciando o Intent TEF
@ingroup idh20

O primeiro passo é instanciar um objeto Intent passando o nome da aplicação como argumento, neste caso, o nome é `com.elgin.e1.digitalhub.TEF`. Através desta informação, o Android buscará o aplicativo do IDH entre os aplicativos instalados no dispositivo. 

Em seguida, devem ser configurados três parâmetros obrigatórios através da função putExtra(String, String):
empresaSitef, CNPJ_CPF e modalidade. Esses e outros parâmetros estão detalhados *REFERENCIA TODO*.

Por fim, se executa a função nativa do Android `startActivityForResult(Intent, int) passando como parâmetros o objeto Intent e um número arbitrário. Este número será utilizado como um ID para a recuperação de informações que o IDH enviará ao aplicativo que o acionou. Nesta documentação, utilizaremos o ID = 1234.

O exemplo abaixo mostra uma chamada simples do fluxo de venda.

@code{.java}
    Intent i = new Intent("com.elgin.e1.digitalhub.TEF");
    i.putExtra("empresaSitef", "00000001");
    i.putExtra("modalidade", "0");
    i.putExtra("valor", "9000");
    i.putExtra("CNPJ_CPF", "12345678912345");
    startActivityForResult(i,1234); // ID = 1234
@endcode

Exemplos de chamada do IDH ElginTef

a) Pagamento
Para realizar o pagamento, a automação comercial pode fazer a seguinte chamada intent:

@code{.java}
    Intent i = new Intent("com.elgin.e1.digitalhub.TEF");
    i.putExtra("empresaSitef", "00000001");
    i.putExtra("operador", "0001");
    i.putExtra("data", "20140312");
    i.putExtra("hora", "150000");
    i.putExtra("numeroCupom", "1");
    i.putExtra("numParcelas", "3");
    i.putExtra("modalidade", "0");
    i.putExtra("valor", "9000");
    i.putExtra("CNPJ_CPF", "12345678912345");
    startActivityForResult(i,1234);
@endcode

b) Débito à vista

@code{.java}
    Intent i = new Intent("com.elgin.e1.digitalhub.TEF");
    i.putExtra("empresaSitef", "00000001");
    i.putExtra("operador", "0001");
    i.putExtra("data", "20140312");
    i.putExtra("hora", "150000");
    i.putExtra("numeroCupom", "1");
    i.putExtra("modalidade", "2");
    i.putExtra("valor", "9000");
    i.putExtra("restricoes", "TransacoesHabilitadas=16");
    i.putExtra("CNPJ_CPF", "12345678912345");
    startActivityForResult(i,1234);
@endcode

b) Cancelamento

@code{.java}
    Intent i = new Intent("com.elgin.e1.digitalhub.TEF");
    i.putExtra("empresaSitef", "00000001");
    i.putExtra("modalidade", "200");
    i.putExtra("CNPJ_CPF", "12345678912345");
    startActivityForResult(i,1234);
@endcode