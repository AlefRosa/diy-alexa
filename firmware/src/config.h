// WiFi credentials
//#define WIFI_SSID "Neubras Industria Eletronica"
//#define WIFI_PSWD "@Neubras03231980757"
#define WIFI_SSID "POCO M3"
#define WIFI_PSWD "12345678"

// are you using an I2S microphone - comment this out if you want to use an analog mic and ADC input
#define USE_I2S_MIC_INPUT

// I2S Microphone Settings

// Which channel is the I2S microphone on? I2S_CHANNEL_FMT_ONLY_LEFT or I2S_CHANNEL_FMT_ONLY_RIGHT
#define I2S_MIC_CHANNEL I2S_CHANNEL_FMT_ONLY_LEFT
// #define I2S_MIC_CHANNEL I2S_CHANNEL_FMT_ONLY_RIGHT
#define I2S_MIC_SERIAL_CLOCK GPIO_NUM_4
#define I2S_MIC_LEFT_RIGHT_CLOCK GPIO_NUM_26
#define I2S_MIC_SERIAL_DATA GPIO_NUM_33

//#define I2S_MIC_SERIAL_CLOCK GPIO_NUM_14
//#define I2S_MIC_LEFT_RIGHT_CLOCK GPIO_NUM_12
//#define I2S_MIC_SERIAL_DATA GPIO_NUM_27

// Analog Microphone Settings - ADC1_CHANNEL_7 is GPIO35
#define ADC_MIC_CHANNEL ADC1_CHANNEL_7

// speaker settings
#define I2S_SPEAKER_SERIAL_CLOCK GPIO_NUM_25
#define I2S_SPEAKER_LEFT_RIGHT_CLOCK GPIO_NUM_32
#define I2S_SPEAKER_SERIAL_DATA GPIO_NUM_27

// sdcard
#define SD_PIN_NUM_MISO GPIO_NUM_19
#define SD_PIN_NUM_CLK GPIO_NUM_18
#define SD_PIN_NUM_MOSI GPIO_NUM_23
#define SD_PIN_NUM_CS GPIO_NUM_5

// command recognition settings
#define COMMAND_RECOGNITION_ACCESS_KEY "SYV4SAWUFEMY7TQZFYQUORCXZ2EKIKUS"
