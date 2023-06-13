@defgroup t20 Fluxo da Operação
@ingroup t2

## Fluxo de Operação

1. Inciar conexão com Client: `IniciarOperacaoTEF()`<sup>(1)</sup> 
2. Realizar operação: `RealizarPagamentoTEF()`/`RealizarAdmTEF()`/`RealizarPixTEF`
    * **Fase da coleta de dados**: API retorna um JSON, automação comercial entrega dados pedidos chamando recursivamente o método da operação.
3. Confirmar a operação: `ConfirmarOperacaoTEF()`
4. Finalizar a operação: `FinalizarOperacaoTEF()`

> <sup>(1)</sup>  -  As funções de inicialização / finalização não necessitam ser chamadas a cada operação, como no caso de várias operações seguidas.<br>
> i.e., os seguintes fluxos de operação são possíveis:<br>
> a. [1, 2, 3, 4]; [1, 2, 3, 4]; [1, 2, 3, 4]; ...<br>
> b. {1}; [2, 3]; [2, 3]; [2, 3]; ... {4}<br>
