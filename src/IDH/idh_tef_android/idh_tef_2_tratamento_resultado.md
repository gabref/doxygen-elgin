@defgroup idh201 Resposta Intent TEF
@ingroup idh20

Depois que o IDH tiver termiado o processo do ElginTef, o fluxo é retornado à automação comercial, onde é devolvido um conjunto de informações, entre elas informações se o processamento ocorreu com êxito.

Esses dados são retornados na função `protected void onActivityResult(int requestCode, int resultCode, Intent data)`, que é executada pois o método `startActivityForResult` foi chamado para iniciar o IDH.

O parâmetro `requestCode` é usado para verificar se o retorno corresponde à chamada. O `resultCode` identifica o status da execução do fluxo do idh elgintef (esses valores pertencem ao Android, *RESULT_OK (-1)* , *RESULT_CANCELED (0)*). O parâmetro `data` é para recuperar os dados enviados pelo IDH.

Dentro da implementação do `onActivityResult` deve existir um condicional comparando se o requestCode é igual ao ID passado no startActivityForResult, e dentro dessa condição verificar se o processo foi executado com sucesso para então recuperar os outros valores enviados por meio da função data.getExtras().getString().

A Automação Comercial poderá tratar apenas os parâmetros que precisar.