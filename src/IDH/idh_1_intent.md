@defgroup idh11 Intent
@ingroup idh1

# Intent

Para quem ainda não teve a oportunidade de trabalhar com 
Intent, fique calmo, não é um bicho de sete cabeças. Vamos falar 
um pouco sobre. 
<br>

O *Intent* é um `objeto nativo Android`, muito utilizado para 
realizar troca de mensagens entre Activities de uma mesma 
aplicação ou entre Apps distintos. 
<br>

@mermaidc{intent}

<br>
Isto ocorre por conta de filtros 
definidos no `Manifest.xml` da aplicação, o sistema Android 
entende que determinada Activity pode receber mensagens 
quando algum Intent for instanciado com o caminho definido do 
filtro.
<br>

**Exemplo**
@code{.xml}
<manifest ...> 
    <application ...> 
        <activity 
            android:name=".MainActivity" 
            android:exported="true"> 
            // definição do filtro para troca de mensagens 
            <intent-filter> 
                // quando indicado este caminho ele está elegível a receber mensagens 
                <action android:name="teste.intent.action.MAIN" /> 
                <category android:name="android.intent.category.LAUNCHER" /> 
            </intent-filter> 
        </activity> 
    </application> 
</manifest>
@endcode

<br>

Na forma como vamos utilizar os intents, vamos seguir **3 passos**:
   1. Instanciar um objeto atribuindo o nome do componente (caminho do filtro)
   2. Adicionar os dados que deseja enviar (Payload)
   3. Realizar o envio

Como utilizar os intents com o IDH? @ref idh12