@defgroup idh205 Transação PIX IDH
@ingroup idh20

## Envio

Para efetuar uma transação PIX via **Intent Digital Hub** é necessário realizar uma instância do Intent da seguinte forma:

@code{.java}
    @Override
    protected void onCreate(Bundle savedInstanceState) {​​​​​
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

    try {​​​​​​
        // 1) realiza uma instância do objeto do tipo Intent passando a rota no seu construtor 
        Intent intent = new Intent("com.elgin.e1.digitalhub.TEF");

        // 2) utilizando putExtra para definir qual modalidade ultilizar 
        intent.putExtra("modalidade","pix");

        // 3) utilizando putExtra para definir qual o valor da transação
        intent.putExtra("valor", "1000");

        // 4) Método Receiver para iniciar a Activity e receber o retorno da transação
        startActivityResultLauncher.launch(intent);
        }​​​​​​​​​​​​​​​​​​​​​​​​​​​​​​​​​​ catch (Exception e) {​​​​​​​​​​​​​​​​​​​​​​​​​​​​​​​​​​​​​​​​​​​​​​​​​​​​​​​
            Toast.makeText(getApplicationContext(), e.getMessage(), Toast.LENGTH_LONG).show();
        }​​​​​​​​​​​​​​​​​​​​​​​​​​​​​​​​​​​​​​​​​​​​​​​​​​​​​​​
    }​​​​​​​​​​​​​​​​​​​​​​​​​​​​​​​​​​​​​​​​​​​​​​​​​​​​​​​
@endcode

## Retorno

Após realizar o envio, vamos obter o retorno. São **2 passos**:

1. Implementar a sobrecarga da função

@code{.java}
    startActivityResultLauncher
@endcode

2. Obter os dados de retorno da transação via Intent através de getStringExtra():

@code{.java}
    String retornoIntent = result.getData().getStringExtra("VIA_CLIENTE");
@endcode
 
Exemplo de implementação da sobrecarga startActivityResultLauncher:
 
@code{.java}
    //Sobrecarga Método Receiver para iniciar e receber o retorno da Transação
    ActivityResultLauncher<Intent> startActivityResultLauncher = registerForActivityResult(
        new ActivityResultContracts.StartActivityForResult(), result -> {​​​​​​​​​​​​​​​​
            if (result.getResultCode() == Activity.RESULT_OK) {​​​​​​​​​​​​​​​​
                String retornoIntent = result.getData().getStringExtra("VIA_CLIENTE");
                Toast.makeText(getApplicationContext(), retornoIntent,Toast.LENGTH_LONG).show();
            }​​​​​​​​​​​​​​​​
        }​​​​​​​​​​​​​​​​);
    }​​​​​​​​​​​​​​​​
@endcode