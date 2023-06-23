@defgroup idh203 Retorno ElginTEF IDH
@ingroup idh20

# Retono IDH Tef {#retornos_idh}

## Retorno para Compatibilidade Sitef {#retornos_idh_tef_comp}
| Chaves | Descrição |
| :--- | :--- |
| COD_AUTORIZACAO | Código de autorização da transação de crédito. (Presente somente em transações com cartão de crédito) |
| VIA_ESTABELECIMENTO | Cupom referente à via do estabelecimento. |
| COMP_DADOS_CONF | Dados que deverão ser passados para a CliSiTef, a fim de realizar a confirmação da transação realizada. |
| BANDEIRA | Campo contendo a bandeira da transação TEF realizada. Os códigos estão no documento "Especificação Técnica –Interface com os meios de pagamento do SiTef", na Tabela de Código da Bandeira. |
| NUM_PARC | Campo contendo a quantidade de parcelas da transação. Caso ele esteja ausente, ou tiver valor “0” ou “1”, considerar venda àvista. |
| REDE_AUT | Campo contendo a rede autorizadora da transação TEF realizada. Os códigos estão no documento "Especificação Técnica –Interface com os meios de pagamento do SiTef", na Tabela de Código das RedesAutorizadoras. |
| NSU_SITEF | NSU doservidor SiTef. |
| NSU_HOST | NSU do Host Autorizador. |
| VIA_CLIENTE | Cupom referente à via do cliente. |
| TIPO_PARC | Valores possíveis: <br>**00**: À vista <br>**01**: Pré-Datado <br>**02**: ParceladoEstabelecimento <br>**03**: Parcelado Administradora | 
| CODRESP | Código de resposta da transação realizada com o SiTef.Veja a tabela a seguir para maiores detalhes |

## Retornos Protocolo Elgin {#retornos_idh_tef_elgin}

Os retornos estarão sempre no seguinte formato:

@code{.json}
    {
        "funcao": "<nome da função chamada>",
        "mensagem": "<mensagem 'Sucesso' ou com descrição do erro>",
        "resultado": "<chave com json de retorno da função>"
    }
@endcode

Nas descrições a seguir, as chaves que tiverem `[Opcional]` indica que são opcionais, e no caso de uma transação não bem sucedida podem não se encontrar no json de retorno. 

### Configuração

@code{.json}
{
    "funcao": string,
    "mensagem": string,
    "resultado": {
        "mensagem": string
    }
}
@endcode

### Ativação

@code{.json}
{
    "funcao": string,
    "mensagem": string,
    "resultado": { } // retorno vazio
}
@endcode

### Reimpressão

@code{.json}
{
    "funcao": string,
    "mensagem": string,
    "resultado": {
        "mensagem": string,               // [Opcional]
        "administradora": string,         // [Opcional]
        "autorizacao": string,            // [Opcional]
        "data": string,                   // [Opcional]
        "nsu": string,                    // [Opcional]
        "nsuRede": string,                // [Opcional]
        "numeroCartao": string,           // [Opcional]
        "pagamento": string,              // [Opcional]
        "rede": string,                   // [Opcional]
        "tipoCartao": string,             // [Opcional]
        "valor": string,                  // [Opcional]
        "vencimento": string,             // [Opcional]
        "viaCliente": string,             // [Opcional]
        "viaEstabelecimento": string,     // [Opcional]
        "viaSMS": string,                 // [Opcional]
    }
}
@endcode

### Relatório

@code{.json}
{
    "funcao": string,
    "mensagem": string,
    "resultado": {
        "mensagem": string,          
        "relatorioTransacoes": string
    }
}
@endcode

### Venda e Débito e Crédito

@code{.json}
{
    "funcao": string,
    "mensagem": string,
    "resultado": {
        "mensagem": string,
        "administradora": string,           // [Opcional]
        "autorizacao": string,              // [Opcional]
        "cnpjRede": string,                 // [Opcional]
        "data": string,                     // [Opcional]
        "nsu": string,                      // [Opcional]
        "nsuRede": string,                  // [Opcional]
        "numeroCartao": string,             // [Opcional]
        "pagamento": string,                // [Opcional]
        "rede": string,                     // [Opcional]
        "tipoCartao": string,               // [Opcional]
        "valor": string,                    // [Opcional]
        "vencimento": string,               // [Opcional]
        "viaCliente": string,               // [Opcional]
        "viaEstabelecimento": string,       // [Opcional]
        "viaSMS": string,                   // [Opcional]
    }
}
@endcode

### Cancelamento

@code{.json}
{
    "funcao": string,
    "mensagem": string,
    "resultado": {
        "mensagem": string,
        "administradora": string,           // [Opcional]
        "cnpjRede": string,                 // [Opcional]
        "data": string,                     // [Opcional]
        "nsu": string,                      // [Opcional]
        "nsuRede": string,                  // [Opcional]
        "numeroCartao": string,             // [Opcional]
        "pagamento": string,                // [Opcional]
        "rede": string,                     // [Opcional]
        "tipoCartao": string,               // [Opcional]
        "valor": string,                    // [Opcional]
        "vencimento": string,               // [Opcional]
        "viaCliente": string,               // [Opcional]
        "viaEstabelecimento": string,       // [Opcional]
        "viaSMS": string,                   // [Opcional]
    }
}
@endcode

