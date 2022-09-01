@defgroup ma61 JSON Retorno TEF
@ingroup ma6
@brief Detalhes do retorno da transação TEF Android.

Aqui estão todas as chaves que são retornadas ao finalizar uma transação de venda ou cancelamento.

| Chave | Tipo de dado |	Descrição |
| :---- | :----------: | :----------- |
| autorizacao |	String | Quando existir conterá o código de autorização da transação que foi executada, normalmente gerado pela administradora. |
| numeroCartao |	String | Contém o número do cartão impresso e é utilizado normalmente em transações digitadas, tal como soluções WEB. |
| mensagem | String | Pode estar presente tanto em caso de sucesso quanto em caso de erro. |
| parcelas |	String | Quando enviado pela Aplicação Comercial conterá a quantidade de parcelas a ser utilizada na execução da transação solicitada. |
| nsu |	String | É o Número Sequencial Único (NSU) usado para identificar uma transação dentro de uma rede em uma data especifica. Enviado para a Aplicação Comercial ao executar uma transação. |
| nsuRede |	String | É o Número Sequencial Único (NSU) usado para identificar uma transação dentro de uma rede em uma data especifica. Enviado para a Aplicação Comercial ao executar uma transação. |
| viaCliente |	String | Via formatada pelo server do cliente. |
| viaEstabelecimento |	String | Via formatada pelo server do estabelecimento. |
| viaSMS |	String | Via formtada pelo server resumida para SMS. |
| data |	String | Enviado para a Aplicação Comercial com a(s) data(s) referente à transação em tratamento. Pode ser enviado pela Aplicação Comercial na transação de cancelamento. |
| pagamento |	String | Quando informado deve ser "A vista", "Parcelado" ou "Pre-datado". Quando enviado pela Aplicação Comercial conterá a forma de pagamento a ser utilizado na transação solicitada. |
| administradora |	String | É a administradora responsável pela autorização da transação (ex.: Banricompras, Mastercard, Santander, Visa, etc.), também conhecida como bandeira. |
| tipoCartao |	String | Quando informado deve ser "Debito" ou "Credito". Quando enviado pela Aplicação Comercial conterá os tipos de cartão que podem ser utilizados na execução da transação solicitada. |
| rede |	String | É a rede responsável pelo roteamento e/ou execução da transação (ex.: Banrisul, Cielo, Redecard, Tecban, etc.), também conhecida como credenciadora. |
| valor |	String | Quando informado deve ser maior que zero e contém o valor da transação a ser ou que foi executada. |
| vencimento |	String | Contém o vencimento da transação a ser ou que foi executada. Quando enviado pela Aplicação Comercial, é o vencimento máximo permitido para transação a ser executada. |
| relatorioTransacoes |	String | Contém os relatórios de vendas em débito e créditos (descarta das transações canceladas). Será retonada somente na consulta de relatório diário. |

@note no caso de erros, falhas ou cancelamentos será retornado o Json somente com a propriedade 'mensagem', com a definição do erro a partir do código.