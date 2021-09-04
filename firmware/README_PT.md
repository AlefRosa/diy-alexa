Firmware DIY Alexa ESP32
Esta pasta contém o firmware para executar DIY Alexa no ESP32.

Estamos usando Platform.io para construir o firmware.

Se estiver tendo problemas para detectar a wakeword Marvin, você pode tentar diminuir o limite de detecção:

/src/state_machine/DetectWakeWordState.cpp linha 59.

if (output > 0.95)
Altere 0,95 para algo menor e você aumentará a sensibilidade. Também vale a pena registrar esse valor se você estiver tendo problemas, para que possa ver como o detector está captando o trabalho.

Para entender o código, o melhor lugar para começar é src/Application.cpp. Esta é uma máquina de estado muito simples que alterna entre esperar por uma palavra de ativação ou tentar interpretar o comando do usuário.

De lá, você pode olhar src/state_machine/DetectWakeWordState.cpp' and src / state_machine / RecogniseCommandState.cpp`.

Se você assistiu ao vídeo, o código deve ser bem fácil de seguir.

Opções de configuração
Para configurar as coisas por si mesmo, edite o config.harquivo e preencha seus dados de WiFi.

Existem várias opções neste arquivo que você pode modificar para se adequar à sua própria configuração.

Se você deseja usar um microfone analógico em vez de I2S, você precisa comentar esta linha:

// are you using an I2S microphone - comment this out if you want to use an analog mic and ADC input
#define USE_I2S_MIC_INPUT
E você precisará selecionar o canal ADC apropriado para ler os dados de:

// Analog Microphone Settings - ADC1_CHANNEL_7 is GPIO35
#define ADC_MIC_CHANNEL ADC1_CHANNEL_7
Se você estiver usando um microfone I2S, será necessário informar ao sistema em qual canal você configurou o microfone (esquerdo ou direito - geralmente esses dispositivos são predefinidos para a esquerda).

// Which channel is the I2S microphone on? I2S_CHANNEL_FMT_ONLY_LEFT or I2S_CHANNEL_FMT_ONLY_RIGHT
#define I2S_MIC_CHANNEL I2S_CHANNEL_FMT_ONLY_LEFT
// #define I2S_MIC_CHANNEL I2S_CHANNEL_FMT_ONLY_RIGHT
E você precisará dizer quais pinos você conectou ao microfone:

#define I2S_MIC_SERIAL_CLOCK GPIO_NUM_33
#define I2S_MIC_LEFT_RIGHT_CLOCK GPIO_NUM_26
#define I2S_MIC_SERIAL_DATA GPIO_NUM_25
Se você deseja ter saída de alto-falante, você precisará conectar ou alterar os seguintes pinos para o seu amplificador I2S:

// speaker settings
#define I2S_SPEAKER_SERIAL_CLOCK GPIO_NUM_14
#define I2S_SPEAKER_LEFT_RIGHT_CLOCK GPIO_NUM_12
#define I2S_SPEAKER_SERIAL_DATA GPIO_NUM_27
Finalmente, temos a chave de acesso para wit.ai - vou deixar minha chave ativa pelo maior tempo possível.

// command recognition settings
#define COMMAND_RECOGNITION_ACCESS_KEY "UFFEIMRQL7LH4T2DXRHKER4HPMFB4LNH"