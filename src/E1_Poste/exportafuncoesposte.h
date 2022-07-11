#ifndef EXPORTAFUNCOESPOSTE_H
#define EXPORTAFUNCOESPOSTE_H

#include "E1_Poste_global.h"

#ifdef __linux__
    #define STDCALL
#elif _WIN32
    #define STDCALL __stdcall
#endif

extern  "C" {

  /*! \defgroup g10 Poste Sinalizador
   *  \brief Fornece funções para acionamento dos leds do poste sinalizador.
   *  # E1 Poste Elgin
   *  O E1 Poste Elgin é uma solução que fornece todas as funções comuniação com o poste sinalizador para acionamneto dos leds.
   *
   *  ## Por onde começar?
   *
   *  Baixe o pacote da solução E1 Poste Elgin neste link *aqui*. Através deste pacote, você poderá se comunicar com o poste sinalizador através da biblioteca (.dll).
   *
   * Convenções usadas nas chamadas das funções da biblioteca:\n
   * <b>Windows</b>\n
   *  > __stdcall
   * <b>Linux</b>\n
   *  > __cdecl\n
   */

  /*!
   * \ingroup g10
   * \brief AbrePortaSerial.
   *
   * Função responsável pela abertura da porta serial.
   * \param porta - Parâmetro do tipo caractere que define a porta serial a ser aberta.
   * \n
   *   Referência  |  Valor exemplo
   * ------------- | ---------------
   * RS232         | COM6
   * \n
   * \return
   * O retorno é numérico.\n
   * A função bem sucedida deve retornar 0.\n
   */

   ///@cond
   E1_POSTE_EXPORT STDCALL
   ///@endcond
   int AbrePortaSerial(const char *porta);

   /*!
    * \ingroup g10
    * \brief FechaPortaSerial.
    *
    * Função responsável pelo fechamento da conexão estabelecida pela função AbreConexaoSerial.
    * \n
    * \return
    * O retorno é numérico.\n
    * A função bem sucedida deve retornar 0.\n
    */

   ///@cond
   E1_POSTE_EXPORT STDCALL
   ///@endcond
   int FechaPortaSerial();

   /*!
    * \ingroup g10
    * \brief LigaLedVermelho.
    *
    * Função responsável pelo acendimento da luz vermelha do poste sinalizador.
    * \n
    * \return
    * O retorno é numérico.\n
    * A função bem sucedida deve retornar 0.\n
    */

   ///@cond
   E1_POSTE_EXPORT STDCALL
   ///@endcond
   int LigaLedVermelho();

   /*!
    * \ingroup g10
    * \brief DesligaLedVermelho.
    *
    * Função responsável pelo desligamento da luz vermelha do poste sinalizador.
    * \n
    * \return
    * O retorno é numérico.\n
    * A função bem sucedida deve retornar 0.\n
    */

   ///@cond
   E1_POSTE_EXPORT STDCALL
   ///@endcond
   int DesligaLedVermelho();

   /*!
    * \ingroup g10
    * \brief LigaLedAmarelo.
    *
    * Função responsável pelo acendimento da luz amarela do poste sinalizador.
    * \n
    * \return
    * O retorno é numérico.\n
    * A função bem sucedida deve retornar 0.\n
    */

   ///@cond
   E1_POSTE_EXPORT STDCALL
   ///@endcond
   int LigaLedAmarelo();

   /*!
    * \ingroup g10
    * \brief DesligaLedAmarelo.
    *
    * Função responsável pelo desligamento da luz amarela do poste sinalizador.
    * \n
    * \return
    * O retorno é numérico.\n
    * A função bem sucedida deve retornar 0.\n
    */

   ///@cond
   E1_POSTE_EXPORT STDCALL
   ///@endcond
   int DesligaLedAmarelo();

   /*!
    * \ingroup g10
    * \brief LigaLedVerde.
    *
    * Função responsável pelo acendimento da luz verde do poste sinalizador.
    * \n
    * \return
    * O retorno é numérico.\n
    * A função bem sucedida deve retornar 0.\n
    */

   ///@cond
   E1_POSTE_EXPORT STDCALL
   ///@endcond
   int LigaLedVerde();

   /*!
    * \ingroup g10
    * \brief DesligaLedVerde.
    *
    * Função responsável pelo desligamento da luz verde do poste sinalizador.
    * \n
    * \return
    * O retorno é numérico.\n
    * A função bem sucedida deve retornar 0.\n
    */

   ///@cond
   E1_POSTE_EXPORT STDCALL
   ///@endcond
   int DesligaLedVerde();

   /*!
    * \ingroup g10
    * \brief LigaSirene.
    *
    * Função responsável pelo acionamento da sirene do poste sinalizador.
    * \n
    * \return
    * O retorno é numérico.\n
    * A função bem sucedida deve retornar 0.\n
    */

   ///@cond
   E1_POSTE_EXPORT STDCALL
   ///@endcond
   int LigaSirene();

   /*!
    * \ingroup g10
    * \brief DesligaSirene.
    *
    * Função responsável pelo desacionamento da sirene do poste sinalizador.
    * \n
    * \return
    * O retorno é numérico.\n
    * A função bem sucedida deve retornar 0.\n
    */

   ///@cond
   E1_POSTE_EXPORT STDCALL
   ///@endcond
   int DesligaSirene();
}

#endif // EXPORTAFUNCOESPOSTE_H
