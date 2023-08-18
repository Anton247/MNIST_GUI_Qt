#ifndef NEURALNETWORK_H
#define NEURALNETWORK_H

#include <QObject>
#include <QVector>
#include <QRandomGenerator>
#include <QDebug>

class NeuralNetwork : public QObject
{
  Q_OBJECT
  public:
    NeuralNetwork(int inputNum, int hidenNum, int outputNum);
  private:
    int m_inputSize; //количество входных нейронов
    int m_hiddenSize; //количество скрытых нейронов
    int m_outputSize; //количество выходных нейронов

    QVector<double> m_inputNeurons; //входные нейроны
    QVector<double> m_hiddenNeurons; //скрытые нейроны
    QVector<double> m_outputNeurons; //выходные нейроны

    QVector<QVector<double>> m_inputHiddenWeight; //веса между вх и скр слоями
    QVector<QVector<double>> m_hiddenOutputWeight; //веса между скр и вых слоями

    QVector<double> m_hiddenBiases; //смещение скрытых нейронов
    QVector<double> m_outputBiases; //смещение выходных нейронов

    double ReLU(double x); //функция активации

    QRandomGenerator m_randomGenerator;

    const double m_weight = 0.005;

};

#endif // NEURALNETWORK_H
