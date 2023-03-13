@defgroup idh15 Retornos
@ingroup idh1

## RETORNO

Assim como no Envio, o Retorno também é composto por um componente raiz Array. Este contém um ou mais Objects, representando uma lista de **retornos** dos métodos que foram solicitados. 
Os Objects são compostos por 3 componentes:
   1. String - com o nome da função que foi invocada
   2. String - com uma mensagem de execução ou Exception gerada
   3. Object - com o resultado da função (se ela retorna um int, será int, se ela retorna String, será String, etc..)

**Exemplo**
@code{.json}
[                                   // início do Array (Json)
    {                               // início do Object (Json) 
        "funcao": "Método",         // String com nome da método 
        "mensagem": "Executado”,    // String com mensagem de retorno 
        "resultado": 0              // Object com resultado 
    }                               // final do Object (Json) 
]                                   // final do Array (Json) 
@endcode

Agora vamos ver como ficaria o retorno dos 3 métodos de impressão do exemplo Envio.

**Exemplo**
@code{.json}
[
    { 
        "funcao": "AbreConexaoImpressora", 
        "mensagem": "Método executado", 
        "resultado": 0 
    }, 
    { 
        "funcao": "ImpressaoTexto", 
        "mensagem": "Método executado", 
        "resultado": 0 
    }, 
    { 
        "funcao": "FechaConexaoImpressora", 
        "mensagem": "Método executado", 
        "resultado": 0 
    } 
]
@endcode

@note Note que o resultado é `int`, no caso de funções que retornam String, o campo **resultado** será uma String.

<br>

Próximo passo: usar em suas aplicações Android intents para usar o **IntentDigitalHUB**. Para saber quais caminhos de filtro usar e se basear em exemplos acesse a página @ref idh00 .