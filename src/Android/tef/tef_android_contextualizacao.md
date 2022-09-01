@defgroup ma62 Contextualização ElginTef
@ingroup ma6
@brief Contextualização do Projeto

Desenvolvemos uma API nativa para Android, ou seja, deixamos tudo preparado para que sua aplicação tenha o máximo de eficiência na plataforma, nada de conversões de Desktop (reaproveitamento de código). Aqui tudo é direcionado de ponta a ponta para Android.

Para isso acontecer de forma fluida, tivemos que analisar e entender alguns pontos básicos que são fornecidos pela plataforma, tais como: 
    * Ciclo de vida das aplicações
    * Funcionamento da Thread principal
    * Tecnologias que faz sentido utilizar
    * Arquitetura de software voltada ao mobile
    * Tipos de dados, paradigmas e metodologias
    * Facilidade de integração na outra ponta

## O que é o ElginTef?
O ElginTef é a integração dos meios de pagamento nas modalidades débito e crédito para a plataforma Android.

## Como funciona o ElginTef?
Aqui vamos falar um pouco do ElginTef, passando pelo fluxo de operação, comparando com a versão Desktop e configurando as dependências e integração da API. 

### Fluxo de Operação
A operação com ElginTef Android tem algumas particularidades, devido a plataforma, muitas de suas operações são assíncronas, ou seja, enviamos uma solicitação que será respondida por meio de um sistema com alguns passos:
    * Mensagens de progresso
    * Recebimento e informação de opções de coleta
    * Dados da transação autorizada

### Desktop X Mobile

**DESKTOP** \n
Para realizar a operação temos um gerenciador padrão que recebe as solicitações e nos devolve qual é o próximo passo.

@image html tef-desktop.jpg


**ANDROID** \n
A seguir temos um diagrama para exemplificar o fluxo, que será mais bem detalhado na próxima sessão.
@image html tef-android.jpg