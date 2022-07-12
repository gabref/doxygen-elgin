@defgroup t2 Modo Ativo
@ingroup g7
@brief Descrição do modo ativo


# TEF Ativo

## Funcionamento API TEF Elgin
A **API TEF Elgin** fornece a Automação Comercial uma integração para que seja possível a captura de transações financeiras através de diversos concentradores TEF do mercado. Os ambientes atendidos são Windows e Linux.
A solução **API TEF Elgin** foi pensada para facilitar a utilização de Transferências Eletrônicas de Fundos (TEF) por parte da Automação Comercial, oferecendo um pacote completo para atender da melhor forma possível o mercado.

A seguir um fluxograma básico do funcionamento da **API TEF Elgin** independemente do ambiente em que esteja executando.

@mermaidc{fluxo-basico-tef}


## Fluxo de Operação

1. Inciar conexão com Client: `IniciarOperacaoTEF()`<sup>(1)</sup> 
2. Realizar operação: `RealizarPagamentoTEF()`/`RealizarAdmTEF()`
    * **Fase da coleta de dados**: API retorna um JSON, automação comercial entrega dados pedidos chamando recursivamente o método da operação.
3. Confirmar a operação: `ConfirmarOperacaoTEF()`
4. Finalizar a operação: `FinalizarOperacaoTEF()`

> <sup>(1)</sup>  -  As funções de inicialização / finalização não necessitam ser chamadas a cada operação, como no caso de várias operações seguidas.<br>
> i.e., os seguintes fluxos de operação são possíveis:<br>
> a. [1, 2, 3, 4]; [1, 2, 3, 4]; [1, 2, 3, 4]; ...<br>
> b. {1}; [2, 3]; [2, 3]; [2, 3]; ... {4}<br>

## API

### Identificando erro / sucesso nas operações TEF

A chave `tef: { resultadoTransacao: ... }` indica se a operação TEF foi bem-sucedida ou não:
    * **0** - Sucesso, confirmação necessária
    * **1** - Sucesso, não precisa confirmar
    * Valores diferentes de 0 / 1 indicam erros.

### Fase de Coleta
A operação se encontra em estado de coleta sempre que a resposta da API contiver chaves do tipo `tef: { automacao_coleta_xxx: ... }` 

Normalmente a coleta incia após as chamadas bem sucedidas das funções `IniciarOperacaoTEF()` e `RealizarPagamentoTEF()`/`RealizarAdmTEF()` (passando o parâmetro `novaTransacao = true`) e encerra quando:
* A chave `tef: { resultadoTransacao: ... }` for retornada, indicando o término da coleta.
* A chave `tef: { automacao_coleta_retorno: ... }` for diferente de 0, indicando erro durante a coleta.

#### Chaves importantes de retorno da API durante a coleta
* `automacao_coleta_mensagem` : Mensagem sobre o dado a ser coletado, para exibir ao usuário
* `automacao_coleta_palavra_chave` : Indica a chave correspondente ao dado sendo coletado
* `automacao_coleta_tipo` : Indica o tipo de dado que se espera coletar (numérico, alfanumérico, data, etc) e, portanto, <u>se o dado a ser coletado precisa ser passado no payload da próxima chamada ou não</u>:
    * Se esta chave estiver presente, significa que o dado solicitado precisa ser informado no payload da próxima chamada na chave `automacao_coleta_informacao`
* `automacao_coleta_opcao` : Chave retornada somente quando a chave `automacao_coleta_tipo` estiver presente.
    * Se esta chave estiver presente, indica uma lista de valores válidos (separados por ponto e vírgula) que o usuário deverá escolher e enviar na chave `automacao_coleta_informacao` do payload seguinte.
* `automacao_coleta_mascara` : Se estiver presente, indica o formato em que o dado da coleta deverá ser informado. i.e. :
    * datas devem ser enviadas no formato dd/MM/yy
    * valores monetários devem ser enviados no formato .## 
* `automacao_coleta_retorno` : Indica o resultado do último dado coletado
    * Se for 0 - sucesso e aguarda dados da próxima coleta
    * Diferente de 0 - erro e fim da operação
* `automacao_coleta_sequencial` : Sequencial ou "passo" atual da coleta (1, 2, 3, ...). Esse mesmo valor deverá ser informado nesta chave no payload da próxima chamada de coleta.

#### Chaves que devem ser enviadas no payload durante a coleta
* `automacao_coleta_sequencial` : deve-se enviar o mesmo valor que é recebido no JSON durante a coleta, caso contrário a operação será cancelada.
* `automacao_coleta_retorno` : indica continuidade ou cancelamento da coleta
    * se 0, indica que a coleta deve continuar
    * se 9, indica que a coleta / operação deve ser cancelada
* `automacao_coleta_informacao` : sempre que a chave `automacao_coleta_tipo` estiver no retorno da API, deve-se retornar essa chave com o dado solicitado.

## Payloads

O envio de um payload ao iniciar a operação é opcional, porém durante o estado de coleta o envio dos payloads é imprescindível para que a operação não seja cancelada.

A seguir, **exemplos** de payloads que podem ser enviados nas funções:

1. Payload para funções `IniciarOperacaoTEF()` / `RecuperarOperacaoTEF()` 
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

## Arquivo de Configuração

As funções `SetClientTCP()` e `ConfigurarDadosPDV()` gerar/atualizam um arquivo com a seguinte estrutura:

@code{.json}
    {​​​​​
        "identificadorPontoCaptura": "T0004",
        "ipClientTCP": "127.0.0.1",
        "loja": "01",
        "nomeEstabelecimento": "Elgin",
        "portaClientTCP": 60906,
        "textoPinpad": "Meu PDV",
        "versaoAC": "v1.0.000"
    }​​​​​
@endcode

Os valores no arquivo serão passados como parâmetros das funções, porém o arquivo só será gerar/atualizado se os valores informados forem válidos.

Essas funções podem ser chamadas na primeira vez que o PDV for executado, após a criação do arquivo não é necessário atualizá-lo toda vez.

* Por padrão, o nome do arquivo é `e1_tef_configs.json` e é gerenciado no **workdir**, porém é possível definir outro caminho onde esse arquivo será manipulado por meio da variável de ambiente e1_tef_configfile.
    * i.e. se a variável de ambiente **e1_tef_configfile** (no Windows) estiver configurada com o valor `%userprofile%\Desktop\elgin_tef.json`, será utilizado esse caminho.
    * O caminho definido na variável **e1_tef_configfile** possui prioridade sobre o **e1_tef_configfile** do **workdir**.

Esse arquivo é lido sempre que a função `IniciarOperacaoTEF()` for chamado.