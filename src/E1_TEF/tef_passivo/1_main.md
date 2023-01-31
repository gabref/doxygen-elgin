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

![Diagrama de sequencia para fluxo de comunicação entre PDV e Módulo de troca de arquivos](https://user-images.githubusercontent.com/78883867/117910368-2fc08100-b2b2-11eb-8b97-952024370e13.png)
