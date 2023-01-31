@defgroup t01 Operações com PIX
@ingroup t0

## Operações com Pix
Para realizar uma operação Pix, a automação deve gerar um arquivo IntPos.001 com os seguintes dados:

Dados escritos:

	000-000 = PIX
	001-000 = 1
	002-000 = 123456
	003-000 = 400
	999-999 = 0

## Utilizar o PIX4 para transações TEF Pix
Para utilizar o PIX4 para transações com Pix, basta alterar no arquivo de configurações `config_tef.json` a chave `"pix4": 0` para `"pix4": 1`.
<br>
Exemplo de arquivo de configuração:  
@code{.json}

	{
		"file_req": "IntPos.001",
		"file_resp": "IntPos.Sts",
    	"log": 1,
    	"path_in": "C:/Cliente/Req",
    	"path_out": "C:/Cliente/Resp",
    	"pix4": 1,
    	"produto_tef": 2,
    	"tag_comprovante": 0
	}
@endcode