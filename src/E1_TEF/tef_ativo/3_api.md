@defgroup t21 API
@ingroup t2

# API {#tef_api_api}

## Identificando erro / sucesso nas operações TEF {#tef_api_identifica_erro_sucesso}

A chave `tef: { retorno: ... }` indica se a operação TEF foi bem-sucedida ou não:
    * **0** - Sucesso, confirmação necessária
    * **1** - Sucesso, não precisa confirmar
    * Valores diferentes de 0 / 1 indicam erros. Veja a descrição dos códigos [aqui](@ref tef_api_informacoes)

@note A chave `tef: { retorno: ... }` não estará presente no json de retorno enquanto a operação estiver ocorrendo.

## Fase de Coleta
A operação se encontra em estado de coleta sempre que a resposta da API contiver chaves do tipo `tef: { automacao_coleta_xxx: ... }` 

Normalmente a coleta incia após as chamadas bem sucedidas das funções `IniciarOperacaoTEF()` e `RealizarPagamentoTEF()`/`RealizarAdmTEF()` (passando o parâmetro `novaTransacao = true`) e encerra quando:
* A chave `tef: { retorno: ... }` for retornada, indicando o término da coleta.
* A chave `tef: { automacao_coleta_retorno: ... }` for diferente de 0, indicando erro durante a coleta.

### Chaves importantes de retorno da API durante a coleta {#tef_api_chaves_importantes}
* `mensagemResultado` : Mensagem sobre o dado a ser coletado, para exibir ao usuário
* `automacao_coleta_palavra_chave` : Indica a chave correspondente ao dado sendo coletado
* `automacao_coleta_tipo` : Indica o tipo de dado que se espera coletar (numérico, alfanumérico, data, etc) e, portanto, <u>se o dado a ser coletado precisa ser passado no payload da próxima chamada ou não</u>:
    * Se esta chave estiver presente, significa que o dado solicitado precisa ser informado no payload da próxima chamada na chave `automacao_coleta_informacao`
* `automacao_coleta_opcao` : Chave retornada somente quando a chave `automacao_coleta_tipo` estiver presente.
    * Se esta chave estiver presente, indica uma lista de valores válidos (separados por ponto e vírgula) que o usuário deverá escolher e enviar na chave `automacao_coleta_informacao` do payload seguinte.
* `automacao_coleta_mascara` : Se estiver presente, indica o formato em que o dado da coleta deverá ser informado. i.e. :
    * datas devem ser enviadas no formato dd/MM/yy ou dd/MM/yyyy
    * valores monetários devem ser enviados no formato .## 
* `automacao_coleta_retorno` : Indica o resultado do último dado coletado
    * Se for 0 - sucesso e aguarda dados da próxima coleta
    * Diferente de 0 - erro e fim da operação
* `automacao_coleta_sequencial` : Sequencial ou "passo" atual da coleta (1, 2, 3, ...). Esse mesmo valor deverá ser informado nesta chave no payload da próxima chamada de coleta.

### Chaves que devem ser enviadas no payload durante a coleta {#tef_api_chaves_payload}
* `automacao_coleta_sequencial` : deve-se enviar o mesmo valor que é recebido no JSON durante a coleta, caso contrário a operação será cancelada.
* `automacao_coleta_retorno` : indica continuidade ou cancelamento da coleta
    * se 0, indica que a coleta deve continuar
    * se 9, indica que a coleta / operação deve ser cancelada
* `automacao_coleta_informacao` : sempre que a chave `automacao_coleta_tipo` estiver no retorno da API, deve-se retornar essa chave com o dado solicitado.
