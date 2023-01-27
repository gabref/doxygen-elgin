\defgroup ma7 Modo Kiosk
\brief Funções do Modo Kiosk
\ingroup g32

O modo Kiosk permite limitar o acesso a alguns recursos do dispositivo. Isso torna o dispositivo bastante adaptável para que o equipamento seja usado como um 'quiosque digital', mas pode ter outras utilidades.

Veja as seguintes imagens:

Por exemplo ao usar o MiniPDV M10, normalmente ele possui a seguinte aparência:
@image html modo-kiosk.jpg

Porém, após chamar a função @ref desabilitaBarraStatus :
@image html modo-kiosk-barra-status.jpg

E após chamar a função @ref desabilitaBarraNavegacao :
@image html modo-kiosk-barra-navegacao.jpg

Repare que tanto a barra de status quanto a barra de navegação não são mais visíveis para o usuário.

Também é possível desabilitar o botão liga/desliga usando a função @ref desabilitaBotaoPower.

Todas as funcionalidades que são desabilitadas podem também ser habilitadas, sempre por meio das funções presentes na biblioteca.

As funções que podem ser usadas são as seguintes:

@ref desabilitaBarraStatus <br>
@ref habilitaBarraStatus <br>
@ref desabilitaBarraNavegacao <br>
@ref habilitaBarraNavegacao <br>
@ref desabilitaBotaoPower <br>
@ref habilitaBotaoPower <br>