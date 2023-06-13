@defgroup t22 Payloads
@ingroup t2

## Payloads

O envio de um payload ao iniciar a operação é opcional, porém durante o estado de coleta o envio dos payloads é imprescindível para que a operação não seja cancelada.

A seguir, **exemplos** de payloads que podem ser enviados nas funções:

1. Payload para funções `IniciarOperacaoTEF()`
    - envio opcional, quando não enviado, assume-se os parâmetros do arquivo de configuração se houver
    
    @code{.json}

        {
            "textoPinpad": "Meu PDV",
            "versaoAC": "v0.0.01",
            "nomeEstabelecimento": "Elgin",
            "loja": "01",
            "identificadorPontoCaptura": "T0004"
        }

    @endcode

2. Payload para função `RealizarPagamentoTEF()` (quando `novaTransacao == true`)
    - envio opcional, quando não enviado, a API solicita os dados durante a coleta
    
    @code{.json}

        {
            "sequencial": "2",
            "valorTotal": "1000",
        }

    @endcode

3. Payload para a função `RealizarAdmTEF()` (quando `novaTransacao == true`)
    - envio opcional, quando não enviado, a API solicita os dados durante a coleta

    @code{.json}

        {
            "sequencial": "2",
            "admUsuario": "admin",
            "admSenha": "admin"
        }

    @endcode
