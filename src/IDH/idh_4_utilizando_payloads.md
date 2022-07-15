@defgroup idh14 Utilizando Payloads
@ingroup idh1

# Utilizando Payloads

Nesta seção veremos:
   1. Payload de envio
   2. Payload de retorno

## ENVIO

Os componentes Json para realizar o Payload de envio serão os seguintes:
   * String
   * Array
   * Object

**Exemplo**
@code{.json}
[                       // Array
    {                   // Object
        "key": "value"  // String
    }
]
@endcode

<br>

O componente raiz é o `Array`, ele terá 1 ou mais `Objects`, ou seja, o Array representará uma lista de **comandos** que serão invocados. Estes comandos serão compostos por Objects. Cada um desdes Objects deve ter dois componentes:
   1. String - será o nome do método a ser chamado
   2. Object - serão os parâmetros desde método.   

Para melhor contextualização, vamos fazer um exemplo com o método `AbreConexaoImpressora` do módulo @ref ma0 : #AbreConexaoImpressora.

**Exemplo**
@code{.json}
[// início do Array (Json)
    {                                       // início do Object (Json) 
        "funcao": "AbreConexaoImpressora",  // String com nome da função 
        "parametros": {                     // início do Object com os parâmetro 
            "tipo": 5,                      // chave: tipo e valor: 5 (int)
            "modelo": "",                   // chave: modelo e valor: vazio (String) 
            "conexao": "",                  // chave: conexao e valor: vazio (String) 
            "parametro": 0                  // chave: parametro e valor: 0 (int) 
        }                                   // final do Object com os parâmetro 
    }                                       // final do Object (Json) 
]                                           // final do Array (Json)
@endcode

@note Veja, estamos fazendo a chamada de somente 1 método.

Agora vamos ver como ficaria um caso real para realizar uma impressão de texto. Vamos chamar 2 funções:
   1. #AbreConexaoImpressora
   2. #ImpressaoTexto
   3. #FechaConexaoImpressora

**Exemplo**
@code{.json}
[ 
    { 
        "funcao": "AbreConexaoImpressora", 
        "parametros": { 
            "tipo": 5, 
            "modelo": "", 
            "conexao": "", 
            "parametro": 0 
    } 
    }, 
    { 
        "funcao": "ImpressaoTexto", 
        "parametros": { 
            "dados": "teste de impressão", 
            "posicao": 0, 
            "stilo": 0, 
            "tamanho": 0 
    } 
    }, 
    { 
        "funcao": "FechaConexaoImpressora", 
        "parametros": {} 
    } 
]
@endcode

@note Basta seguir estes modelos para realizar as chamadas dos métodos.

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