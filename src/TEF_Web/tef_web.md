@defgroup g14 Tef Web
@brief API do Tef Web

# Tef Web
O Elgin Tef Web permite que você faça transações de TEF em um equipamento a partir de uma aplicação Web, basta ter instalado os módulos mais recentes do Tef Elgin (IDH no Android).

Tendo o ElginTef instalado no equipamento, será possível fazer chamadas GET e POST para realizar as operações de TEF.

## Start e Stop do Plugin
No Android, o plugin para Tef Web precisa ser iniciado uma vez para começar a realizar as operações. Isso pode ser feito por exemplo no evento `window.onload`, ou então ter um botão específico para isso. 
<br>
Para dar o start e stop no plugin, são utilizados os **deeplink**, portanto existem 2 maneiras de fazer isso. Por anchor tag, ou por windows location.

### Anchor Tag

@code{.html}
<a href="intent://connect/start">Start</a>
<a href="intent://connect/stop">Stop</a>
@endcode

### Window location

@code{.html}
<script>
    function start() { window.location.href = 'intent://connect/start' }
    function stop()  { window.location.href = 'intent://connect/stop' }
</script>
...
<button onclick="start()">Start</button>
<button onclick="stop()">Stop</button>
@endcode

# Endpoints Operações

URL Base para todos os endpoints: `http://localhost:2001/tef/v1`
<br>
Headers necessários para todas as chamadas API:

@code{.json}
headers: {
    'Accept': 'application/json',
    'Content-Type': 'application/json'
},
@endcode

## Configuração
Função responsável por coletar informações que serão utilizadas internamente para realizar configurações do produto TEF

URL: `http://localhost:2001/tef/v1/configuracao`
<br>
Método: `POST`
<br>
body:

@code{.json}
{
    nome: string                // nome da aplicação
    versao: string              // versão da aplicação, será exibido no visor do pinpad
    textoPinpad: string         // texto que será exibido no visor do pinpad
    macPinpad: string           // Endereço Mac do PIN-PAD pareado com dispositivo (Preencher somente quando houver dispositivos)
    producao: string            // Flag para indicação do ambiente de transação (0 - Testes e 1 - Produção)
    estabelecimento: string     // Nome do estabelecimento definido com a operadora de TEF (Opcional)    
    terminal: string            // Nome da loja definida com a operadora de TEF (Opcional)    
    loja: string                // Número do terminal definido com a operadora de TEF (Opcional)
}
@endcode

## Ativação
Função responsável pela ativação do terminal para realizar as transações e operações com ElginTef

URL: `http://localhost:2001/tef/v1/ativacao`
<br>
Método: `POST`
<br>
body:

@code{.json}
{
    cnpjCpf: string // Documento (CNPJ ou CPF) que foi informado para cadastro
}
@endcode

## Reimpressão
Função responsável pela reimpressão do último comprovante autorizado em uma transação

URL: `http://localhost:2001/tef/v1/adm/reimpressao`
<br>
Método: `GET`
<br>
body: não existe

## Relatório
Função responsável pela impressão do relatorio de transações (débito, crédito e cancelamentos) do dia atual

URL: `http://localhost:2001/tef/v1/adm/relatorio`
<br>
Método: `GET`
<br>
body: não existe

## Venda
Função responsável por iniciar uma venda e obter os dados dinâmicamente

URL: `http://localhost:2001/tef/v1/venda`
<br>
Método: `POST`
<br>
body: não existe

## Débito
Função responsável por iniciar uma transação TEF com tipo de pagamento em débito

URL: `http://localhost:2001/tef/v1/venda/debito`
<br>
Método: `POST`
<br>
body:

@code{.json}
{
    valor: string           // Valor do pagamento realizado na operação com TEF (formato 00.00)
}
@endcode

## Crédito
Função responsável por iniciar uma transação TEF com tipo de pagamento em crédito

URL: `http://localhost:2001/tef/v1/venda/credito`
<br>
Método: `POST`
<br>
body:

@code{.json}
{
    valor: string           // Valor do pagamento realizado na operação com TEF (formato 00.00)
    parcelas: string        // Quantidade de parcelas para as transações parcelada
    financiamento: string   // Tipo do financiamento (A vista(1), parcelado emissor(2) ou parcelado estabelecimento(3))
}
@endcode

## Cancelamento
Função responsável por realizar o processo de cancelamento de uma transação autorizada

URL: `http://localhost:2001/tef/v1/adm/cancelamento`
<br>
Método: `POST`
<br>
body:

@code{.json}
{
    valor: string       // Valor do pagamento da transação autorizada TEF (formato 00.00)
    nsu: string         // Documento NSU da transação autorizada TEF com 6 dígitos
    data: string        // Data da transação autorizada TEF (formato dd/MM/yy)
}
@endcode

## IntPos

@note Esse endpoint pode ser chamado apenas em ambientes integrados com o TEF GP Elgin, ou seja, Windows e Linux.

URL: `http://localhost:2001/tef/v1/intpos`
<br>
Método: `POST`
<br>
body:

@code{.json}
{
    intpos: string       // chaves iguais as enviadas em uma integração com o GP, porém as linhas devem ser separadas por \n ou \r\n
}
@endcode

Exemplo:

@code{.javascript}
        const responseData = await fetch(BASE_URL + rota, {
            headers: {
                'Accept': 'application/json',
                'Content-Type': 'application/json'
            },
            method: 'POST',
            body: JSON.stringify({
                'intpos': '000-000 = ADM\n001-000 = 123\n999-999 = 0\n'
            })
        })
        const data = await responseData.json()
        console.log('data json post', data)
        alert(JSON.stringify(data))
@endcode
