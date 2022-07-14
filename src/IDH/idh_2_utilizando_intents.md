@defgroup idh12 Utilizando Intents
@ingroup idh1

# Utilizando Intents

Nesta seção veremos:
   1. Envio de dados ao IntentDigitalHub
   2. Retorno dos processamentos feitos pelo IntentDigitalHub

Agora que já tivemos uma breve definição de Intent, vamos ver como utilizar no nosso contexto.
<br>

@mermaidc{intent-idh}

## Envio

Vamos fazer um exemplo de instância de um Intent com caminho para o módulo da Impressora Térmica. O conteúdo que será enviado (mais informações na seção @ref idh14 ) deve ser adicionado ao `putExtra` com a chave **comando**.

**Exemplo**
@code{.java}
@Override 
protected void onCreate(Bundle savedInstanceState) { 
    super.onCreate(savedInstanceState); 
    setContentView(R.layout.activity_main); 
    
    try { 
        // 1) definição do filtro para falar com Activity de TERMICA em E1_DigitalHub 
        String TERMICA = "com.elgin.e1.digitalhub.TERMICA";
        // 1.1) realiza a instancia do objeto 
        Intent intent = new Intent(TERMICA); 
        // 2) adiciona o putExtra com o Payload de Envio 
        intent.putExtra("comando", "[{...}]"); 
        // 3) envio de dados para o E1_DigitalHub 
        startActivityForResult(intent, 1);
    } catch (Exception e) { 
        Toast.makeText(getApplicationContext(), e.getMessage(), Toast.LENGTH_LONG).show(); 
    } 
}
@endcode

## Retorno

Após realizar o envio, vamos obter o retorno. São **2 passos**:
   1. Implementar a sobrecarga da função `onActivityResult()`
   2. Obter o valor de `getStringExtra` com a chave **retorno** com o valor de @ref idh14 com o Array (Json) de retorno dos métodos invocados

Vamos realizar a implementação da sobrecarga do método `onActivityResult()`.

**Exemplo**
@code{.java}
@Override 
// 1) sobrecarga da função onActivityResult() 
protected void onActivityResult(int requestCode, int resultCode, @Nullable Intent data) { 
    super.onActivityResult(requestCode, resultCode, data); 

    try { 
        // 2) recebe o retorno do E1_DigitalHub (um Intent de retorno) 
        String retorno = data.getStringExtra("retorno"); 
        Toast.makeText(getApplicationContext(), "Retorno = " + retorno, Toast.LENGTH_LONG).show(); 
    } catch (Exception e) { 
        Toast.makeText(getApplicationContext(), e.getMessage(), Toast.LENGTH_LONG).show(); 
    } 
}
@endcode

Agora com o conteúdo do retorno, basta realizar os devidos tratamentos para utilizar em sua Automação.
<br>

Entenda como funciona o @ref idh13