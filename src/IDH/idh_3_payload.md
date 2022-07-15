@defgroup idh13 Payloads
@ingroup idh1

# Payload

De forma rasa, os payloads são as informações em um bloco de dados que você envia ou recebe de um servidor ao fazer solicitações. Estes blocos podem estar em vários formatos e um deles é o **Json**, que é o que usamos para criar nosso protocolo de comunicação com o IntentDigitalHub.
<br>

O Json é um formato de texto simples para armazenar e transmitir dados. Este formato é muito utilizado para enviar e receber dados de um servidor, talvez o mais usado. Uma de suas características mais relevantes são os formatos que podem ser gravados em um json:
   * String
   * Number
   * Boolean
   * Null / Empty
   * Array (Json)
   * Object (Json)

Para gerar e manipular os Json que representam o **Payload**, use as biblioteca de preferência para facilitar o processo de serialização e desserialização, o nosso objetivo aqui é deixar claro o formato que o **IntentDigitalHub** espera receber e retorna.

Vamos ver como é composto nosso protocolo proprietário e quais são os atributos que são utilizados para o **IntentDigitalHub**.
<br>

Como utilizar os payloads com o IDH? @ref idh14