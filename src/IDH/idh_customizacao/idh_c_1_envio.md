@defgroup idh210 Envio
@ingroup idh21

# Envio

## Path Filtro Customização

path - `com.elgin.e1.digitalhub.CUSTOM`

<hr />

# Funções para Intent

## Customizar aplicação (itens gerais)
Função responsável por adicionar customização de logotipo e backgrounds.

Grupo
- application

Parâmetros
- logotipo (String) - Caminho do path da imagem 
- background (String) - Hexadecimal com a cor sólida para o fundo das telas
- gradienteInicio (String) - Hexadecimal com a cor inicial para o gradiente
- gradienteFim (String) - Hexadecimal com a cor final para o gradiente

obs: para usar o background é recomendável que não informe as opções de gradiente e vice-versa.

Exemplo 1 - background (cor sólida)
@code{.java}
	Intent intent = new Intent(path);
	intent.putExtra("grupo", "application");
	intent.putExtra("logotipo", "/sdcard/Pictures/batman.png");
	intent.putExtra("background", "#0099FF");
	startActivity(intent);
@endcode


Exemplo 2 - gradiente
@code{.java}
	Intent intent = new Intent(path);
	intent.putExtra("grupo", "application");
	intent.putExtra("logotipo", "/sdcard/Pictures/batman.png");
	intent.putExtra("gradienteInicio", "#C6C6C6");
	intent.putExtra("gradienteFim", "##6F5E21");
	startActivity(intent);
@endcode

<hr />
	
## Customizar cabeçalhos (itens da parte superior da tela)
Função responsável por adicionar customização de botões, textos e icones.
* O logotipo é adicionado automaticamente.

Grupo 
- header

Parâmetros
- corBotao (String) - Hexadecimal com a cor para o botão
- corIcone (String) - Hexadecimal com a cor para o icone do botão
- corFonte (String) - Hexadecimal com a cor para fonte do botão

Exemplo 
@code{.java}
	Intent intent = new Intent(path);
	intent.putExtra("grupo", "header");
	intent.putExtra("corBotao", "#363636");
	intent.putExtra("corIcone", "#FFC321");
	intent.putExtra("corFonte", "#FFC321"); // não se aplica ao TEF atualmente neste grupo
	startActivity(intent);
@endcode
	
<hr />

## Customizar conteúdo (itens da parte central da tela)
Função responsável por adicionar customização de botões, textos de botões, icones de botões e mensagens.

Grupo
- content

Parâmetros
- corBotao (String) - Hexadecimal com a cor para o botão
- corIcone (String) - Hexadecimal com a cor para o icone do botão
- corFonte (String) - Hexadecimal com a cor para fonte do botão
- corFonteMensagem (String) Hexadecimal com a cor para as mensagens da tela

Exemplo 
@code{.java}
	Intent intent = new Intent(path);
	intent.putExtra("grupo", "content");
	intent.putExtra("corBotao", "#363636");
	intent.putExtra("corIcone", "#6F5E21");
	intent.putExtra("corFonte", "#FFC321"); 
	intent.putExtra("corFonteMensagem", "#4F5C7C"); 
	startActivity(intent);
@endcode
	
<hr />
	
## Limpar configurações da customização
Função responsável por resetar/limpar as configurações de customização.
* Caso precise limpar alguma especifica dos grupo acima, basta enviar o campo sem preencher ("").

Grupo 
- clear

Parâmetros
- Não existe

Exemplo
@code{.java}
	Intent intent = new Intent(path);
	intent.putExtra("funcao", "clear");
	startActivity(intent);
@endcode