# Documentação Elgin
A partir de 13/05/2021 a documentação passa a estar disponível em
https://elgindevelopercommunity.github.io/

O diretório html é um recurso dentro do repositório integrado com o endereço
remoto do github, desse modo para realizar a atualização basta acessar o diretótio html
add todo o conteúdo e realizar o push

## Gráficos Mermaid
[Instruções para usar os gráficos Mermaid](https://github.com/tttapa/doxygen-mermaid)

## Tema Doxygen
[Projeto usado para o tema](https://jothepro.github.io/doxygen-awesome-css/)

## MAPA DA DOCUMENTAÇÃO
### Árvore simples para esquematizar como a documentação está organizada

> * g0 - Impressoras (../e1_impressora/exportafuncoes.h)<br>
>   * M0 - Etiqueta (../E1_Etiqueta/exportafuncoes.h)<br>
>      * ge0 - Configuracao de Sistema<br>
>       * ge1 - Nivel de Sistema<br>
>       * ge2 - Formatacao de Label<br>
>       * ge3 - Campos da Etiqueta<br>
>           * ge30 - Texto<br>
>           * ge31 - Codigo de barras<br>
>    * M1 - Térmica (../e1_impressora/exportafuncoes.h)<br>
>    * M2 - Funcoes DLL HPRT (../e1_impressora/exportafuncoes.h)<br>
> * g1 - Codigos de erro (../Utilidades/Erros/codigoerro.h)<br>
> * g2 - SAT (../e1_sat-v01.00.01/exportafuncoes.h)<br>
>    * s0 - XML SAT<br>
> * g3 - Android (./android.doxy)<br>
>    * idh1 - IntentDigitalHub
>    * g30 - Mini PDV M8 (./minipdvm8.doxy)<br>
>        * m80 - Impressora do Mini PDV M8<br>
>    * g31 - SmartPOS (./smartPOS.doxy)<br>
>        * sp0 - Impressora do SmartPOS<br>
>        * sp1 - Scanner<br>
>            * sp10 - Inicializacao<br>
>            * sp11 - Retorno<br>
>            * sp12 - Exemplo<br>
> 	   * sp2 - E1_ElginPay (./ElginPay.h ./e1_elginpay.md)<br>
>            * sp20 - Retorno<br>
>            * sp21 - Funções<br>
>      * sp3 - PIX
>            * sp30 - JSON Retorno PIX
>            * sp31 - Funções
>    * g32 - Modulos (./android.doxy)<br>
>        * ma0 - Impressora Termica<br>
>        * ma1 - Impressora de Etiquetas<br>
>        * ma2 - SAT<br>
>            * ma20 - XML SAT**<br>
>        * ma3 - Balanca<br>
>        * ma4 - Servico<br>
>            * ma40 - Termica<br>
>            * ma41 - Etiqueta<br>
>            * ma42 - SAT<br>
>        * ma5 - Pix4
> * g4 - Changelog (./changelog.doxy)<br>
>    * g40 - Termica<br>
>    * g41 - HPRT<br>
>    * g42 - Etiqueta<br>
>    * g43 - SAT<br>
>    * g44 - Balanca<br>
>    * g45 - Servico<br>
>    * g46 - Android<br>
>        * g460 - SmartPOS<br>
>        * g461 - Mini PDV M8<br>
>    * g47 - Gerador PDF<br>
>    * g48 - Poste sinalizador<br>
> * g5 - Balanca (../E1_Balanca/exportafuncoes.h)<br>
> * g8 - Servico (../e1_servico/main.cpp)<br>
> * g9 - Gerador PDF (../E1_Pdf/exportafuncoes.h)<br>
> * g7 - E1_Tef (src/E1_TEF/e1_tef_funcoes.h)<br>
> * g10 - Poste sinalizador (../E1_Poste/exportafuncoesposte.h)<br>
> * g11 - NFCe - E1 (../E1_Brigde/exportafuncoes.h)<br>
> * g12 - E1_Brigde (../E1_Brigde/exportafuncoes.h)<br>
> * g13 - PIX4