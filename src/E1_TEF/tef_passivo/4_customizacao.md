@defgroup t02 Customização GP
@ingroup t0

## Customização do Gerenciador Padrão 
No arquivo de configuração `config_tef.json` pode ser adicionado um bloco opcional com várias possibilidades de customização.

### Descrição das chaves de customização 
`caminho_logo`: chave que define o caminho que se encontra a imagem que deve ser apresentada na aplicação. Exemplo: `C:/logo.png`
@note - Caso o caminho não seja um caminho válido, a imagem não será alterada
@n - Dimensões ideais para a imagem customizada: 800x200
@n - Formato ideal: PNG

`cor_destaque`: chave que recebe um valor hexadecimal para alteração da cor dos botões e da tarja principal da aplicação.
@n`cor_fonte1`: chave que recebe um valor hexadecimal para alteração da cor dos labels que são atualizados para o usuário.
@n`cor_fonte2`: chave que recebe um valor hexadecimal para alteração da cor da fonte dos botões e da tarja.
@n`cor_fundo`: chave que recebe um valor hexadecimal para alteração da cor de fundo da aplicação.
@n`cor_selecao`: chave que recebe um valor hexadecimal para alteração da cor da tarja de seleção de opções da operação.

@note Caso o valor passado não seja um valor hexadecimal válido a aplicação não sofrerá nenhuma alteração e será usada a cor definida por padrão.

Exemplo de arquivo de configuração com customização:
@code{.json}

	{
		"customizacao": {
			"caminho_logo": "Logo Elgin Pay - Azul.png",
			"cor_destaque": "#0093ff",
			"cor_fonte1": "#000000",
			"cor_fonte2": "#ffffff",
			"cor_fundo": "#ffffff",
			"cor_selecao": "#D5D5D5"
		}
		"file_req": "IntPos.001",
		"file_resp": "IntPos.Sts",
    	"log": 0,
    	"path_in": "C:/Cliente/Req",
    	"path_out": "C:/Cliente/Resp",
    	"pix4": 0,
    	"produto_tef": 2,
    	"tag_comprovante": 0
	}
@endcode