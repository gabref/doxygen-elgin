@defgroup t0 Modo Passivo
@ingroup g7
@brief Descrição do modo passivo

## Módulo Passivo
O módulo passivo foi desenvolvido para facilitar a integração de parceiros que já possuem implementações no padrão **troca de arquivos**.
<br>
A troca de arquivos utiliza 2 diretórios. Um deles para a automação enviar os arquivos de requisição e outro para as respostas. 
<br>
Por meio de um processo contínuo, a API tenta ler o arquivo de requisição até que a Automação Comercial o crie. Após a leitura do arquivo e processamento da requisição, a API gera um arquivo de saída no diretório de saída para a Automação Comercial ler.
<br>
Os diretórios são criados na execução da aplicação caso não existam. Os caminhos default são:
- `C:\Cliente\Req` - para arquivo de requisição de transações.
- `C:\Cliente\Resp` - para arquivos de Status e de resposta para automação.

Há 2 tipos de arquivos para troca de dados entre automação e API TEF. Um deles serve para enviar dados e o outro para enviar uma resposta confirmando o recebimento dos dados. O arquivo de dados recebe o nome “INTPOS.001”. Já o arquivo de confirmação de recebimento de dados recebe o nome “INTPOS.STS”.

Abaixo segue um diagrama do fluxo de iterações entre PDV e E1_TEFPay_Passivo e logo adiante um exemplo dos arquivos de requisição e resposta:

![[Diagrama de sequencia para fluxo de comunicação entre PDV e Módulo de troca de arquivos](https://user-images.githubusercontent.com/78883867/117910368-2fc08100-b2b2-11eb-8b97-952024370e13.png)


Exemplo de Transação Venda Débito/Crédito 

Arquivo IntPos.001 gerado pela Automação na Etapa 1 de uma operação CRT.
`C:\Cliente\Req\IntPos.001`

Dados escritos:

    000-000 = CRT
    001-000 = 1
    002-000 = 123456
    003-000 = 4500
    004-000 = 0
    999-999 = 0

Arquivo IntPos.Sts gerado pelo Módulo E1_TEFPAY_Passivo na Etapa 2 de uma operação CRT.
`C:\Cliente\Resp\IntPos.Sts`

Dados retornados pela API:

    000-000 = CRT
    001-000 = 1
    999-999 = 0

Arquivo IntPos.001 gerado pelo Módulo E1_TEFPAY_Passivo na Etapa 4 de uma operação CRT. (Após a captura da transação na etapa 3)
`C:\Cliente\Resp\IntPos.001`

Dados retornados pela API:

    000-000 = CRT
    001-000 = 1
    002-000 = 123456
    003-000 = 4500
    010-000 = ELECTRON
    010-001 = 103
    010-003 = 21
    010-004 = 417402
    010-005 = 7578
    011-000 = 03603511027
    012-000 = 001315
    013-000 = 001315
    018-000 = 01
    022-000 = 0326
    023-000 = 192414
    028-000 = 37
    029-001 = ELGIN PAY TESTE BANRISUL
    029-002 = 92.702.067/0001-96   
    029-003 = R CAPITAO MONTANHA, 177
    029-004 = CENTRO PORTO ALEGRE RS
    029-005 = 
    029-006 = 
    029-007 = 
    029-008 = 
    029-009 =                  REDE                 
    029-010 = 
    029-011 = REDESHOP  -      OKI                  
    029-012 = 
    029-013 = 
    029-014 = COMPROV: 123456789 VALOR: 45,00
    029-015 = 
    029-016 = ESTAB:013932594 SCOPE TESTE SIMULADO  
    029-017 = DD.MM.AA-HH:MM:SS TERM:PV123456/pppnnn
    029-018 = CARTAO: ************7578
    029-019 = AUTORIZACAO: 123456                   
    029-020 = ARQC:36DEFEF9D3490BC5
    029-021 = 
    029-022 = **************************************
    029-023 =          D E M O N S T R A C A O      
    029-024 =  Transacao sem validade para reembolso
    029-025 =     Autorizacao gerada por simulador  
    029-026 = **************************************
    029-027 = 
    029-028 =     TRANSACAO AUTORIZADA MEDIANTE     
    029-029 =         USO DE SENHA PESSOAL.         
    029-030 =                                       
    029-031 = 0
    029-032 = CONTROLE 03603511027  OKI BRASIL SCOPE
    029-033 = 
    029-034 = 
    029-035 = 
    029-036 = 
    029-037 = 
    030-000 = Transação Finalizada com Sucesso
    043-000 = SIMULADOR
    047-000 = 00
    050-000 = 000
    150-000 = 000000000000002
    210-004 = 4174020000007578=25080000000000000000
    210-052 = 001
    210-052 = 001
    300-001 = 0825
    600-000 = 01425787000104
    701-016 = 0326
    999-999 = 0

Arquivo IntPos.001 gerado pela Automação na Etapa 6 de uma operação CRT. (Após a automação ter realizado a impressão e armazenado os dados da transação)
`C:\Cliente\Req\IntPos.001`

Dados Escritos pela automação para confirmação de uma venda:

    000-000 = CNF
    001-000 = 1
    027-000 = 123456
    999-999 = 0
    
Arquivo IntPos.Sts gerado pelo Módulo E1_TEFPAY_Passivo na Etapa 7 de uma operação CRT.
`C:\Cliente\Resp\IntPos.Sts`

Dados Retornados pela API:

    000-000 = CNF
    001-000 = 1
    999-999 = 0