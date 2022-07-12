

/**
 * @brief Informa à API qual produto TEF será utilizado 
 * 
 * No momento temos apenas um produto implementado, logo, este será o produto padrão e essa função pode ser ignorada.
 * 
 * @param produtoTef 
 */
void SetProdutoTef(int produtoTef);



//# balança
/**
 * \param leituraContinua - Parâmetro do tipo booleano que define o tipo de leitura a ser realizada.\n
 * Passe <b>true</b> caso esteja trabalhando com protocolo contínuo; passe <b>false</b> caso esteja
 * trabalhando com protocolo demanda.\n
 * @note <b>Parâmetro utilizado/disponível somente na versão Android desta biblioteca.</b>\n
 *

int DirectIO(const char* wbuffer, unsigned int wlen, char* rdbuffer, unsigned int rdlen);

