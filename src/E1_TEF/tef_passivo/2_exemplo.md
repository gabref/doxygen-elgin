@defgroup t00 Exemplo de Transação Venda Débito / Crédito
@ingroup t0

# Exemplo de Transação Venda Débito / Crédito 

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

# Exemplo de Coleta PinPad

Arquivo IntPos.001 gerado pela Automação Comercial:

Isso irá acionar o processo de coleta da informação escolhida, vide [Descrição das Chaves](@ref t03):

    000-000 = CLT
    001-000 = 0052660
    376-000 = 2
    999-999 = 0
