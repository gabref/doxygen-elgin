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

> g0 - Impressoras (../e1_impressora/exportafuncoes.h)
>    M0 - Etiqueta (../E1_Etiqueta/exportafuncoes.h)
>       ge0 - Configuracao de Sistema
>       ge1 - Nivel de Sistema
>       ge2 - Formatacao de Label
>       ge3 - Campos da Etiqueta
>           ge30 - Texto
>           ge31 - Codigo de barras
>    M1 - Térmica (../e1_impressora/exportafuncoes.h)
>    M2 - Funcoes DLL HPRT (../e1_impressora/exportafuncoes.h)
> g1 - Codigos de erro (../Utilidades/Erros/codigoerro.h)
> g2 - SAT (../e1_sat-v01.00.01/exportafuncoes.h)
>    s0 - XML SAT
> g3 - Android (./android.doxy)
>    g30 - Mini PDV M8 (./minipdvm8.doxy)
>        m80 - Impressora do Mini PDV M8
>    g31 - SmartPOS (./smartPOS.doxy)
>        sp0 - Impressora do SmartPOS
>        sp1 - Scanner
>            sp10 - Inicializacao
>            sp11 - Retorno
>            sp12 - Exemplo
> 	   sp2 - E1_ElginPay (./ElginPay.h ./e1_elginpay.md)
>            sp20 - Retorno
>            sp21 - Funções
>    g32 - Modulos (./android.doxy)
>        ma0 - Impressora Termica
>        ma1 - Impressora de Etiquetas
>        ma2 - SAT
>            ma20 - XML SAT**
>        ma3 - Balanca
>        ma4 - Servico
>            ma40 - Termica
>            ma41 - Etiqueta
>            ma42 - SAT
> g4 - Changelog (./changelog.doxy)
>    g40 - Termica
>    g41 - HPRT
>    g42 - Etiqueta
>    g43 - SAT
>    g44 - Balanca
>    g45 - Servico
>    g46 - Android
>        g460 - SmartPOS
>        g461 - Mini PDV M8
>    g47 - Gerador PDF
>    g48 - Poste sinalizador
> g5 - Balanca (../E1_Balanca/exportafuncoes.h)
> g8 - Servico (../e1_servico/main.cpp)
> g9 - Gerador PDF (../E1_Pdf/exportafuncoes.h)
> g7 - E1_Tef (src/E1_TEF/e1_tef_funcoes.h)
> g10 - Poste sinalizador (../E1_Poste/exportafuncoesposte.h)
> g11 - NFCe - E1 (../E1_Brigde/exportafuncoes.h)
> g12 - E1_Brigde (../E1_Brigde/exportafuncoes.h)
