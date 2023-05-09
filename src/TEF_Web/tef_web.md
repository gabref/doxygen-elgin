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
    macPinpad: string           // opcional
    producao: string            //  0 ou 1 para homologação ou produção
    estabelecimento: string     // o nome do estabelecimento no qual a AC está em execução
    terminal: string            // o nome / código do terminal (pertencente ao estabelecimento) na qual a AC está em execução
    loja: string                // o nome / código da loja (pertencente ao estabelecimento) na qual a AC está em execução
}
@endcode

## Ativação
URL: `http://localhost:2001/tef/v1/ativacao`
<br>
Método: `POST`
<br>
body:

@code{.json}
{
    cnpjCpf: string // cnpj ou cpf cadastrado no ElginTEF com pontuação
}
@endcode

## Reimpressão
URL: `http://localhost:2001/tef/v1/adm/reimpressao`
<br>
Método: `GET`
<br>
body: não existe

## Relatório
URL: `http://localhost:2001/tef/v1/adm/relatorio`
<br>
Método: `GET`
<br>
body: não existe

## Venda
URL: `http://localhost:2001/tef/v1/venda`
<br>
Método: `POST`
<br>
body: não existe

## Débito
URL: `http://localhost:2001/tef/v1/venda/debito`
<br>
Método: `POST`
<br>
body:

@code{.json}
{
    valor: string           // valor maior que zero e contém valor da transação em R$ com ponto: '12.99
}
@endcode

## Crédito
URL: `http://localhost:2001/tef/v1/venda/credito`
<br>
Método: `POST`
<br>
body:

@code{.json}
{
    valor: string           // valor maior que zero e contém valor da transação em R$ com ponto: '12.99
    parcelas: string        // número de parcelas a ser utilizada an transação
    financiamento: string   // Somente aplicado quando parcelas for maior que 1, opções: "Estabelecimento" ou "Administradora"
}
@endcode

## Cancelamento
URL: `http://localhost:2001/tef/v1/adm/cancelamento`
<br>
Método: `POST`
<br>
body:

@code{.json}
{
    nsu: string         // nsu da transação a ser cancelada, deve conter 6 dígitos
    valor: string       // valor maior que zero e contém valor da transação em R$ com ponto: '12.99
    data: string        // data da transação no formato dd/mm/aa
}
@endcode