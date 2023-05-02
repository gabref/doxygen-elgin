@defgroup idh202 Parâmetros
@ingroup idh20

| Parâmetro | Descrição |
| :--- | :--- |
| empresaSitef | Empresa Sitef. <br> O tamanho é de 8 dígitos alfanuméricos. |
| modalidade | Funcionalidade do ElginTef que deseja executar. Por exemplo: <br>0 - pagamento<br>200 - cancelamento <br>114 - reimpressão <br>? - configurações
| terminalSitef | Número de terminal Sitef. <br>Se não informado o IDH irá usar o número de série do APOS ou |
| operador | Código do operador. O campo é alfanumérico com tamanho até 20 caracteres. |
| data | Data fiscal no formato AAAAMMDD ou DD/MM/AA. |
| hora | Hora fiscal no formato HHMMSS. |
| numeroCupom | Número do cupom fiscal correspondente à venda. O campo é alfanumérico com tamanho até 20 caracteres. |
| valor | Valor da venda. O campo é numérico com tamanho até 12 algarismos, onde os dois últimos dígitos são decimais, com vírgula ou ponto |
| CNPJ_CPF | CNPJ ou CPF do estabelecimento.Este campo não deve conter caracteres especiais e pode ser utilizado nos dados de subadquirência e no ParmsClient. |
| numParcelas | Número de parcelas, em caso de compra parcelada. O campo é numérico e varia de acordo com o cartão utilizado. |
| transacoesHabilitadas | Opções de pagamento que serão habilitadas.  <br>16: Débito <br>26: A vista <br>27: Loja <br>28: ADM |
| comExterna | 0 |
