@defgroup idh203 Retorno ElginTEF IDH
@ingroup idh20

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