@defgroup t23 Arquivo de Configuração
@ingroup t2

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
Se algum valor do arquivo precisar ser alterado, é possível alterá-lo diretamente do arquivo, sem necessidade de chamar as funções da API (os novos valores entrarão em vigor após uma nova chamada do método IniciarOperacaoTEF).