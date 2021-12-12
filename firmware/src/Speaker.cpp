#include "Speaker.h"
#include "I2SOutput.h"
#include "WAVFileReader.h"

Speaker::Speaker(I2SOutput *i2s_output)
{
    m_i2s_output = i2s_output;
    m_ok = new WAVFileReader("/ok.wav");
    m_ready_ping = new WAVFileReader("/ready_ping.wav");
    m_cantdo = new WAVFileReader("/cantdo.wav");
    m_life = new WAVFileReader("/life.wav");
    m_jokes[0] = new WAVFileReader("/joke0.wav");
    m_jokes[1] = new WAVFileReader("/joke1.wav");
    m_jokes[2] = new WAVFileReader("/joke2.wav");
    //m_jokes[3] = new WAVFileReader("/joke3.wav");
    //m_jokes[4] = new WAVFileReader("/joke4.wav");
    apresentacao = new WAVFileReader("/pd16.wav", 0, true);//new WAVFileReader("/apresentacao.wav");
    fernanda = new WAVFileReader("/fernanda.wav");
}

Speaker::~Speaker()
{
    delete m_ok;
    delete m_ready_ping;
    delete m_cantdo;
    delete m_life;
    delete apresentacao;
    delete m_jokes[0];
    delete m_jokes[1];
    delete m_jokes[2];
    delete m_jokes[3];
    //delete m_jokes[4];
}

void Speaker::playOK()
{
    m_ok->reset();
    m_i2s_output->setSampleGenerator(m_ok);
}

void Speaker::playOK2(int joke)
{
    m_ok->reset();
    m_i2s_output->setSampleGenerator(m_jokes[joke]);
}

void Speaker::playReady()
{
    m_ready_ping->reset();
    m_i2s_output->setSampleGenerator(m_ready_ping);
}

void Speaker::playCantDo()
{
    m_cantdo->reset();
    m_i2s_output->setSampleGenerator(m_cantdo);
}

void Speaker::playRandomJoke()
{
    int joke = random(3);
    m_i2s_output->setSampleGenerator(m_jokes[joke]);
}

void Speaker::playLife()
{
    m_life->reset();
    m_i2s_output->setSampleGenerator(m_life);
}
void Speaker::playApresentacao()
{
    m_life->reset();
    m_i2s_output->setSampleGenerator(apresentacao);
}
void Speaker::playFernanda()
{
    m_life->reset();
    m_i2s_output->setSampleGenerator(fernanda);
}