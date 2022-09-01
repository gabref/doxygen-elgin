@defgroup ma5 Pix4
@ingroup g32

# Módulo para comunicação com Pix4.

Para utilizar essas funções em ambiente Android, é necessário importar
a classe referente a este módulo:
@code{.java}
import com.elgin.e1.DisplayPIX4.PIX4;
@endcode 

Após importar a classe, no evento da Activity `onCreate` deve ser criado o objeto que irá chamar os métodos, passando o context da aplicação:.\n
@code{.java}
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        mContext = this.getApplicationContext();

        display = new PIX4(mContext); // cria o objeto passando o context da activity
        // ....
    }
@endcode 

Feito isso, já será possível acessar os métodos com o operador (.) no objeto criado, no caso do exemplo, o objeto `display`. 

Por exemplo, para abrir a conexão com o Pix4 poderia-se fazer:
@code{.java}
    private void connect()  {
        result = display.AbreConexaoDisplay();

        if(result == 0){
            Toast.makeText(this, "Conexao realizada com sucesso" + result, Toast.LENGTH_SHORT).show();
        }else{
            Toast.makeText(this, "Não foi possivel realizar a conexão" + result, Toast.LENGTH_SHORT).show();
        }
    }
@endcode

### Funções do Pix4

AbreConexaoDisplay() \n
ObtemVersaoFirmware() \n
ObtemConexao() \n
DesconectarDisplay() \n
InicializaDisplay() \n
ReinicializaDisplay() \n
CarregaImagemDisplay() \n
ApresentaImagemDisplay() \n
ApresentaQRCode() \n
ApresentaTextoColorido() \n
ApresentaListaCompras() \n
InicializaLayoutPagamento() \n
AdicionaFormaPagamento() \n