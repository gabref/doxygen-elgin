@defgroup idh211 Retorno
@ingroup idh21

# Retorno

Deverá ser implementado o método onActivityResult da classe AppCompatActivity (que estende a Activity).
A resposta será dada via Intent com o identificador "retorno", como já é conhecido do IDH.
o que permite realizar a deserialização e transformação em objetos do tipo ou uma classe.

Exemplo
@code{.java}
    @Override
    protected void onActivityResult(int requestCode, int resultCode, @Nullable Intent data) {
        super.onActivityResult(requestCode, resultCode, data);

        try {
            assert data != null;
			String retorno = data.getStringExtra("retorno");
        } catch (Exception e) {
		
        }
    }
@endcode