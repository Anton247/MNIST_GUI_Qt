#include "neuralnetwork.h"

NeuralNetwork::NeuralNetwork(int inputNum, int hiddenNum, int outputNum)
{
  m_inputSize = inputNum;
  m_hiddenSize = hiddenNum;
  m_outputSize = outputNum;

  //заполнение весов между входным и скрытым слоями
  m_inputHiddenWeight.resize(m_inputSize);
  for(int i=0; i<m_inputSize; ++i){
    m_inputHiddenWeight[i].resize(m_hiddenSize);
    for(int j = 0; j<m_hiddenSize; ++j){
      m_inputHiddenWeight[i][j] =  m_randomGenerator.generateDouble() * 2 - 1;
    }
  }

  //заполнение весов между скрытым и выходным слоями
  m_hiddenOutputWeight.resize(m_hiddenSize);
  for(int i=0; i<m_hiddenSize; ++i){
    m_hiddenOutputWeight[i].resize(m_outputSize);
    for(int j = 0; j<m_outputSize; ++j){
      m_hiddenOutputWeight[i][j] =  m_randomGenerator.generateDouble() * 2 - 1;
    }
  }

  //заполнение смещений скрытого слоя
  m_hiddenBiases.resize(m_hiddenSize);
  for(int i=0; i<m_hiddenSize; ++i){
    m_hiddenBiases[i] = m_randomGenerator.generateDouble() * 2 - 1;
  }

  //заполнение смещений выходного слоя
  m_outputBiases.resize(m_outputSize);
  for(int i=0; i<m_outputSize; ++i){
    m_outputBiases[i] = m_randomGenerator.generateDouble() * 2 - 1;
    qDebug() << m_outputBiases[i];
  }

}
