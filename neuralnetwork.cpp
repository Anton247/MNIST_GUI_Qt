#include "neuralnetwork.h"

NeuralNetwork::NeuralNetwork(int inputNum, int hiddenNum, int outputNum)
{
  m_inputSize = inputNum;
  m_hiddenSize = hiddenNum;
  m_outputSize = outputNum;

  m_hiddenNeurons.resize(hiddenNum);
  m_outputNeurons.resize(outputNum);

  //заполнение весов между входным и скрытым слоями
  m_inputHiddenWeight.resize(m_inputSize);
  for(int i=0; i<m_inputSize; ++i){
    m_inputHiddenWeight[i].resize(m_hiddenSize);
    for(int j = 0; j<m_hiddenSize; ++j){
      m_inputHiddenWeight[i][j] =  m_weight * (m_randomGenerator.generateDouble() * 2 - 1);
    }
  }

  //заполнение весов между скрытым и выходным слоями
  m_hiddenOutputWeight.resize(m_hiddenSize);
  for(int i=0; i<m_hiddenSize; ++i){
    m_hiddenOutputWeight[i].resize(m_outputSize);
    for(int j = 0; j<m_outputSize; ++j){
      m_hiddenOutputWeight[i][j] =  m_weight * (m_randomGenerator.generateDouble() * 2 - 1);
    }
  }

  //заполнение смещений скрытого слоя
  m_hiddenBiases.resize(m_hiddenSize);
  for(int i=0; i<m_hiddenSize; ++i){
    m_hiddenBiases[i] = m_weight * (m_randomGenerator.generateDouble() * 2 - 1);
  }

  //заполнение смещений выходного слоя
  m_outputBiases.resize(m_outputSize);
  for(int i=0; i<m_outputSize; ++i){
    m_outputBiases[i] = m_weight * (m_randomGenerator.generateDouble() * 2 - 1);
    qDebug() << m_outputBiases[i];
  }

}

double NeuralNetwork::ReLU(double x)
{
  if(x > 0)
    return x;
  else
    return 0;
}

void NeuralNetwork::feedForward(const QVector<double> &input)
{
  //расчёт значений скрытых нейронов
  for(int i = 0; i<m_hiddenSize; ++i){
    double activation = m_hiddenBiases[i];
    for(int j=0; j<m_inputSize; ++j){
      activation += input[j] * m_inputHiddenWeight[j][i];
    }
    m_hiddenNeurons[i] = ReLU(activation);
  }

  //расчёт значений выходных нейронов
  for(int i = 0; i<m_outputSize; ++i){
    double activation = m_outputBiases[i];
    for(int j=0; j<m_hiddenSize; ++j){
      activation += input[j] * m_hiddenOutputWeight[j][i];
    }
    m_outputNeurons[i] = ReLU(activation);
  }
}
