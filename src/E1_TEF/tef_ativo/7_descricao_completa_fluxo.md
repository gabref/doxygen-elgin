@defgroup t25 Descrição Completa Fluxo
@ingroup t2

# Fluxo TEF {#fluxo_tef}

1. Inciar conexão com Client: `IniciarOperacaoTEF()`<sup>(1)</sup> 
    1. Se as funções `SetClientTCP()` e `ConfigurarDadosPDV()` já tiverem sido chamadas, a função IniciarOperacaoTEF() pode ser chamada com um payload vazio, se não, passar como argumento um payload [inicial de configuração](@ref t23).
    2. no json de retorno, se a chave `retorno` for diferente de `0` ou `1` significa que ocorreu algum erro. Se não, continuar o fluxo.
<hr/>

2. Realizar operação: `RealizarPagamentoTEF()`/`RealizarAdmTEF()`/`RealizarPixTEF()`
    1. Realizar primeira chamada da operação passando um [payload inicial](@ref t22). Por exemplo: 
        um payload inicial da função RealizarPagamentoTEF poderia ser: 
        @code{.json}
            {
                "sequencial": "2",
                "valorTotal": "12.99"
            }
        @endcode

        Verificar se nenhum erro ocorreu, e então prosseguir com o fluxo.

    2. **Fase da coleta de dados** (Fluxo sugerido)
        1. Fazer o parse do json de retorno da chamada anterior da função da operação
        2. Verificar que a chave retorno não está presente (o que indicaria que a transação finalizou, conforme a [documentação](@ref tef_api_identifica_erro_sucesso)) e então continuar o fluxo de coleta
        3. **Fase de coleta a ser repetida até a finalização da coleta**
            1. Extrair as chaves do json do retorno da chamada anterior da função da operação que está sendo realizada. Para um breve descrição das chaves e seus usos veja a [documentação da API](@ref tef_api_chaves_importantes) ou para entender mais a fundo veja [aqui](@ref tef_api_coleta).
            2. Verificar se a chave `automacao_coleta_retorno = 0`, se não, encerrar coleta 
            3. Criar um novo payload a ser enviado para à API com as chaves e os valores de `automacao_coleta_retorno` e `automacao_coleta_sequencial`
            4. **Coletar Dados do Usuário**: 
                1. se `automacao_coleta_tipo` for diferente de nulo, significa que deve algum dados deve ser coletado do usuário
                2. se `automacao_coleta_opcao` for nulo, a coleta do usuário é do tipo texto, ou seja, usuário deve digitar a informação pedida
                3. se `automacao_coleta_opcao` for direrente de nulo, o usuário precisará escolher uma das opções fornecidadas.
                4. qualquer que seja o tipo de coleta, uma vez que o usuário digitou ou escolheu uma opção, adicionar valor ao payload com a chave `automacao_coleta_informacao`
                5. caso o usuário queira cancelar a operação, apenas alterar o valor da chave `automacao_coleta_retorno` para '9'.
            5. Informar os dados coletados chamando a função da operação (por exemplo a `RealizarPagamentoTEF()`) passando como argumento o payload.
            6. Verificar que a chave retorno não está presente (o que indicaria que a transação finalizou, conforme a [documentação](@ref tef_api_identifica_erro_sucesso)) e então continuar o fluxo
            7. Repetir a fase de coleta passando o json de retorno.
<hr/>

3. Confirmar a operação: `ConfirmarOperacaoTEF()`
    1. Fazer o parse do retorno da coleta
    2. Verificar pela chave `retorno` se algum erro ocorreu, se não, pode-se extrair do json de retorno os valores que forem necessários para aplicação, como por exemplo, os comprovantes.
    3. Se a chave `retorno` for `1`, não será necessário realizar a confirmação da transação. Se for `0`, passar o valor do sequencial retornado na função anterior como argumento da função `ConfirmarOperacaoTEF()` e também `1` como segundo argumento para identificar a ação de confirmação.
<hr/>

4. Finalizar a operação: `FinalizarOperacaoTEF()`
