@defgroup sp30 JSON Retorno PIX
@brief Detalhes do retorno da transação PIX
@ingroup sp3

# Detalhes do Retorno da Transação PIX
 
Para as transações executadas no modo Ativo o retorno será enviado para a implementação do Handler.handlerMessage em uma string no formato Json.
Ex:

@code{.java}
    private Handler handler = new Handler(Looper.getMainLooper()){​​​​
        @Override
        public void handleMessage(@NonNull Message msg) {​​​​
            super.handleMessage(msg);
            String saida = (String) msg.obj;
        }​​​​
    }​​​​;
@endcode
 
Abaixo estão detalhados os campos retornados:
 
| Chave | Tipo de dado |	Descrição |
| :---- | :----------- | :----------- |
| statusTransacaoPIX |	int | Status de processamento da transação PIX<br>PROCESSADA_SUCESSO = 0 <br>NAO_PROCESSADA = -1 <br>ERRO_AUTENTICACAO = -2 <br>ERRO_GERACAO_QRCODE = -3 <br>CANCELADA_OPERADOR = -4 <br>ERRO_DESCONHECIDO = -5 |
| informacoesQRCode.dataHoraCriacao | String | Data da criação da transação |
| informacoesQRCode.idConsultaQRCode |	String |	Id de consulta da transação |
| informacoesQRCode.imageBase64 |	String |	Conteúdo em base64 do bitmap do QRCode |
| informacoesQRCode.pixCopiaCola |	String |	Chave utilizada para realizar o pagamento na impossibilidade de fazer a leitura do QR Code gerado no Pix |
| informacoesQRCode.tipoQRCode |	String |	Tipo do QRCode |
| informacoesQRCode.validade |	int |	Tempo de validade da transação em segundos |
| informacoesQRCode.valor |	double |	Valor com descontos |
| informacoesQRCode.valorOriginal |	double |	Valor original |
| statusTransacao.chave |	String |	Chave da consulta |
| statusTransacao.codigoStatusTransacao |	int |	Código de status da transação |
| statusTransacao.id |	int |	ID de consulta |
| statusTransacao.mensagem |	String |	Mensagem |
| statusTransacao.statusTransacao |	String |	Status da transação (="APROVED" quando a transação estiver paga) ou (= "Transferência {​​​​mensagem}​​​​​​​​ não confirmada" quando não estiver paga) |
| statusTransacao.sucesso |	bool |	True se estiver Pago ou false caso contrario |