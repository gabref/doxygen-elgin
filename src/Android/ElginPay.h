/**
 * \defgroup sp20 Funções
 * \ingroup sp2
*/

/**
 * \ingroup sp20
 * Função para retornar o ID da Transação
 * @return string com o valor configurado pela função setIdTransacao ou um valor randomico gerado
 * em casos onde o id não foi setado;
 */
public String getIdTransacao();

/**
 * \ingroup sp20
 * Configura o ID da transação
 * @param midTransacao String a ser usada como Identificador da transação
 */
public void setIdTransacao(String midTransacao);

/**
 * \ingroup sp20
 * Função utilizada para retornar o código do PDV
 * @return retorno tipo string, podendo ser vazio caso não tenha sido configurado pela função setPdv;
 */
public String getPdv();

/**
 * \ingroup sp20
 * Configura o código do pdv que sera acrescentado no retorno das operações
 * @param mpdv Tipo String com o valor a ser utilizado;
 */
public void setPdv(String mpdv);

/**
 * \ingroup sp20
 * Retorna o tipo de impressão a ser realizado;
 * @return Enum TipoImpressao
 */
public TipoImpressao getTipoImpressao();

/**
 * \ingroup sp20
 * Configura qual o tipo de impressão a ser realizado;
 * @param tipoImpressao - Enum TipoImpressao
 */
public void setTipoImpressao(TipoImpressao tipoImpressao);

/**
 * \ingroup sp20
 * Habilida/Desabilita popup para operador informar se o cupom fiscal deve ser emitido;
 * @param coletarInfoCupomFiscal - True para habilitar e false para desabilitar;
 */
public void setColetarInfoCupomFiscal(boolean coletarInfoCupomFiscal);

/**
 * \ingroup sp20
 * Função para retornar se esta Habilitado o popup para operador informar se deve ser emitido cupom fiscal
 * Essa informação será retornada ao PDV para que possa ser emitido o cupom fiscal e em seguida seja impresso
 * o danfe para o Cliente.
 * Para impressão dos documentos podem ser utilizadas as funções de impressão de xml presentes no
 * modulo termica ou no modulo brigde.
 * @return true caso o popup esteja habilidado.
 */
public boolean isColetarInfoCupomFiscal();

/**
 * \ingroup sp20
 * Inicia uma transação. A modalidade (débito ou crédito) sera escolhido pelo operador
 * @param valorTotal - Valor total da venda em centavos, ex: 100 para venda de R$1,00
 * @param context - Activity atual utilizada para apresentação de Dialogos com o usuário
 * @param handler - Objeto handler utilizado para receber a resposta do transação atravez do método
 *                handleMessage. A resposta será enviada como String no formato JSON. Consulte \ref sp21
 */
public void iniciaVenda(String valorTotal, Context context, Handler handler);



/**
 * \ingroup sp20
 * Inicia uma transação de débito
 * @param valorTotal - Valor total da venda em centavos, ex: 100 para venda de R$1,00
 * @param context - Activity atual utilizada para apresentação de Dialogos com o usuário
 * @param handler - Objeto handler utilizado para receber a resposta do transação atravez do método
 *                handleMessage. A resposta será enviada como String no formato JSON. Consulte \ref sp21
 */
public void iniciaVendaDebito(String valorTotal, Context context, Handler handler);

/**
 * \ingroup sp20
 * Inicia uma transação de crédito
 * @param valorTotal - Valor total da venda em centavos, ex: 100 para venda de R$1,00
 * @param tipoFinanciamento - Tipo do financiamento (A vista(1), parcelado emissor(2) ou parcelado estabelecimento(3))
 * @param numeroParcelas - Quantidade de parcelas para as transações parcelada. Para transação a vista o valor sera desconsiderado. 
 * @param context - Activity atual utilizada para apresentação de Dialogos com o usuário
 * @param handler - Objeto handler utilizado para receber a resposta do transação atravez do método
 *                handleMessage. A resposta será enviada como String no formato JSON. Consulte \ref sp21
 */
public void iniciaVendaCredito(String valorTotal, int tipoFinanciamento, int numeroParcelas, Context context, Handler handler);

/**
 * \ingroup sp20
 * Função para transação de cancelamento de uma transação débito ou crédito
 * @param valorTotal - Valor total da venda em centavos, ex: 100 para venda de R$1,00 (ValorTotal no json retornado da venda)
 * @param ref - Referencia da transação original (NSUTerminal no json retornado da venda)
 * @param data - Data da transação original no formato MMM dd, yyyy HH:mm:ss aaa (dataHoraTransacao no json retornado da venda)
 * @param context - Activity atual utilizada para apresentação de Dialogos com o usuário
 * @param handler - Objeto handler utilizado para receber a resposta do transação atravez do método
 *                handleMessage. A resposta será enviada como String no formato JSON. Consulte \ref sp21 
 */
public void iniciaCancelamentoVenda(String valorTotal, String ref, String data, Context context, Handler handler);

/**
 * \ingroup sp20
 * Inicia uma operação administrativa
 * @param context - Activity atual utilizada para apresentação de Dialogos com o usuário
 * @param handler - Objeto handler utilizado para receber a resposta do transação atravez do método
 *                handleMessage. A resposta será enviada como String no formato JSON. Consulte \ref sp21
 */
public void iniciaOperacaoAdministrativa(Context context,Handler handler);

/**
 * \ingroup sp20
 * Inicia uma operação definida pelo Usuario
 * @param operacoes - Enum de Operações disponiveis.
 * @param context - Activity atual utilizada para apresentação de Dialogos com o usuário
 * @param handler - Objeto handler utilizado para receber a resposta do transação atravez do método
 *                handleMessage. A resposta será enviada como String no formato JSON. Consulte \ref sp21
 */
public void iniciaOperacaoAdministrativa(Operacoes operacoes, Context context,Handler handler);

/**
 * \ingroup sp20
 * Função para personalização da interface de pagamento.\n
 * Por padrão o ElginPay tem a identidade visual da Elgin, azul com branco, mas isso
 * pode ser alterado de acordo com a necessidade da automação.\n
 * @param mPersonalizacao - Objeto com as informações de personalização.\n
 * \n
 *
 * Exemplo de personalização:\n
 * @code
 * // ...
 *
 * Personalizacao.Builder pb = new Personalizacao.Builder();
 * pb.informaIconeToolbar(new File("/sdcard/ic_launcher_round.png"));	// Altera o ícone
 * pb.informaFonte(new File("/system/fonts/Clockopia.ttf"));			// Altera a fonte
 * pb.informaCorFonte("#FC9F00");										// Altera a cor da fonte
 * pb.informaCorFonteTeclado("#FC9F00");								// Altera a cor da fonte do teclado
 * pb.informaCorFundoToolbar("#FC9F00");								// Altera a cor do fundo da barra superior
 * pb.informaCorFundoTela("#0C0807");									// Altera a cor do fundo da tela
 * pb.informaCorTeclaLiberadaTeclado("#464B4E");						// Altera a cor da tecla liberada do teclado
 * pb.informaCorFundoTeclado("#1B1A1C");								// Altera a cor do fundo do teclado
 * pb.informaCorTextoCaixaEdicao("#464B4E");							// Altera a cor do texto da caixa de edição
 * pb.informaCorSeparadorMenu("#FC9F00");								// Altera a cor dos separadores do menu
 * 
 * Personalizacao personalizacao = pb.build();	// Cria o objeto de personalização
 *
 * // ...
 *
 * ElginPay elginPay = new ElginPay();			// Cria o objeto do ElginPay
 * elginPay.setPersonalizacao(personalizacao);	// Configura a personalização do ElginPay
 *
 * // ...
 * @endcode
 * \n
 *
 * Notas:\n
 * - O ícone utilizado no exemplo está localizado no diretório sdcard do dispositivo;\n
 * - A fonte utilizada no exemplo é uma fonte do sistema Android;\n
 * - As cores devem ser informadas em #rgb.\n
 * \n
 */
 public void setPersonalizacao(Personalizacao mPersonalizacao);


/**
 * \ingroup sp20
 * Função utilizada para personalizar a imagem do cupom, sendo defindo através do caminho onde se encontra a imagem.
 * @param caminhoImagem - Parâmetro do tipo String utilizado para informar o caminho absoluto da imagem.\n
 *
 * @return - o Retorno será do tipo inteiro, onde :
 * >  0 = SUCESSO\n
 * > -1 = O ARQUIVO NÃO EXISTE OU NÃO FOI ENCONTRADO\n
 *
 * Exemplo de personalização:\n
 * @code
 *	// ...
 *	ElginPay pay = new ElginPay();
 *	pay.configuraCupomPersonalizado( Environment.getExternalStorageDirectory().getPath() + "/Download/novoLogoElgin.png");
 *	// ...
 * @endcode
 */
public int configuraCupomPersonalizado(String caminhoImagem);

/**
 * \ingroup sp20
 * Função utilizada para personalizar a imagem do cupom, sendo defindo através de um objeto bitmap onde se encontra a imagem.
 * @param Imagembitmap - Parâmetro do tipo Bitmap, utilizado para informar a imagem de personalização.\n
 *
 * @return - o Retorno será do tipo inteiro, onde :
 * >  0 = SUCESSO\n
 * > -1 = O OBJETO BITMAP NÃO EXISTENTE\n
 *
 * Exemplo de personalização usando um bitmap presente na pasta asserts:\n
 * @code
 *	// ...
 *  AssetManager am = this.getAssets();
 *  InputStream inputStream = null;
 *  try {
 *		inputStream = am.open("novoLogoElgin.png");
 *		Bitmap bitmap = BitmapFactory.decodeStream(inputStream);
 *		ElginPay pay = new ElginPay();
 *		pay.configuraCupomPersonalizado(bitmap);
 *	// ...
 * @endcode
 */
public int configuraCupomPersonalizado(@NonNull Bitmap Imagembitmap);
	
//TODO: Descontinuar todas as funções abaixo pois não seguem o modelo da DLL

/**
 * \ingroup sp20
 * Inicia uma transação de débito
 * @deprecated Função descontinuada. Utilize {@link ElginPay#iniciaVendaDebito(String, Context, Handler)}
 * @param valorTransacao - Valor total da venda em centavos, ex: 100 para venda de R$1,00
 * @param context - Activity atual utilizada para apresentação de Dialogos com o usuário
 * @param handler - Objeto handler utilizado para receber a resposta do transação atravez do método
 *                handleMessage. A resposta será enviada como String no formato JSON
 */
@Deprecated
public void iniciarPagamentoDebito(String valorTransacao, Context context, Handler handler);

/**
 * \ingroup sp20
 * Inicia uma transação de crédito
 * @deprecated Função descontinuada. Utilize a função {@link ElginPay#iniciaVendaCredito(String, int, int, Context, Handler)}
 * @param valorTransacao - Valor total da venda em centavos, ex: 100 para venda de R$1,00
 * @param tipoFinanciamento - Tipo do financiamento (A vista(0), parcelado emissor(1) ou parcelado estabelecimento(2))
 * @param context - Activity atual utilizada para apresentação de Dialogos com o usuário
 * @param handler - Objeto handler utilizado para receber a resposta do transação atravez do método
 *                handleMessage. A resposta será enviada como String no formato JSON
 */
@Deprecated
public void inciarPagamentoCredito(String valorTransacao,int tipoFinanciamento,Context context,Handler handler);

/**
 * \ingroup sp20
 * Inicia uma transação de crédito
 * @deprecated Função descontinuada. Utilize a função {@link ElginPay#iniciaVendaCredito(String, int, int, Context, Handler)}
 * @param valorTransacao - Valor total da venda em centavos, ex: 100 para venda de R$1,00
 * @param tipoFinanciamento - Tipo do financiamento (A vista(1), parcelado emissor(2) ou parcelado estabelecimento(3))
 * @param numeroParcelas - Quantidade de parcelas para as transações parcelada. Para transação a vista o valor sera desconsiderado.                         
 * @param context - Activity atual utilizada para apresentação de Dialogos com o usuário
 * @param handler - Objeto handler utilizado para receber a resposta do transação atravez do método
 *                handleMessage. A resposta será enviada como String no formato JSON
 */
@Deprecated
public void iniciarPagamentoCredito(String valorTransacao, int tipoFinanciamento, int numeroParcelas, Context context, Handler handler);

/**
 * \ingroup sp20
 * Função para transação de cancelamento de uma transação débito ou crédito
 * @deprecated Função descontinuada. Utilize a função {@link ElginPay#iniciaCancelamentoVenda(String, String, String, Context, Handler)}
 * @param valorTotal - Valor total da venda em centavos, ex: 100 para venda de R$1,00
 * @param context - Activity atual utilizada para apresentação de Dialogos com o usuário
 * @param handler - Objeto handler utilizado para receber a resposta do transação atravez do método
 *                handleMessage. A resposta será enviada como String no formato JSON
 */
@Deprecated
public void iniciarCancelamentoVenda(String valorTotal, Context context,Handler handler);

/**
 * \ingroup sp20
 * Função para transação de cancelamento de uma transação débito ou crédito
 * @deprecated Função descontinuada. Utilize a função {@link ElginPay#iniciaCancelamentoVenda(String, String, String, Context, Handler)}
 * @param valorTotal - Valor total da venda em centavos, ex: 100 para venda de R$1,00
 * @param ref - Ref (NSU) da transação original
 * @param data - Data da transação original no formato MMM dd, yyyy HH:mm:ss aaa
 * @param context - Activity atual utilizada para apresentação de Dialogos com o usuário
 * @param handler - Objeto handler utilizado para receber a resposta do transação atravez do método
 *                handleMessage. A resposta será enviada como String no formato JSON
 */
@Deprecated
public void iniciarCancelamentoVenda(String valorTotal, String ref, String data, Context context, Handler handler);

/**
 * \ingroup sp20
 * Inicia uma operação administrativa
 * @deprecated Função descontinuada. Utilize a função {@link ElginPay#iniciaOperacaoAdministrativa(Context, Handler)}
 * @param context - Activity atual utilizada para apresentação de Dialogos com o usuário
 * @param handler - Objeto handler utilizado para receber a resposta do transação atravez do método
 *                handleMessage. A resposta será enviada como String no formato JSON
 */
@Deprecated
public void iniciarOperacaoAdministrativa(Context context,Handler handler);


/**
 * \ingroup sp20
 * Enum responsavel por configurar os tipos de impressão que podem ser utilizadas pela classe de
 * pagamento.
 */
public enum TipoImpressao {
	IMPRESSAO_PADRAO(0, "Padrao"),                                   /*!< IMPRIME DIRETO APENAS VIA DO ESTABELECIMENTO E PERGUNTA SOBRE VIA DO CLIENTE*/
    IMPRESSAO_DIRETA_VIA_CLIENTE_VIA_ESTABELECIMENTO(1, "Ambas"),    /*!< IMPRIME DIRETO TODAS AS VIAS*/
    IMPRESSAO_DIRETA_VIA_CLIENTE(2, "Cliente"),                      /*!< IMPRIME DIRETO APENAS VIA DO CLIENTE*/
    IMPRESSAO_DIRETA_VIA_ESTABELECIMENTO(3, "Estabelecimento"),      /*!< IMPRIME DIRETO APENAS VIA DO ESTABELECIMENTO*/
    IMPRESSAO_DESABILITADA(4, "Nenhum"),                             /*!< NÃO IMPRIME NENHUMA VIA*/
    IMPRESSAO_INDEFINIDA(5, "Perguntar");                            /*!< PERGUNTA AO USUÁRIOS QUAIS VIAS IMPRIMIR*/
}
	