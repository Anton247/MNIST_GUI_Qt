#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "neuralnetwork.h"
#include <QLabel>
#include <QGridLayout>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QGroupBox>
#include <QProgressBar>>

class MainWindow : public QMainWindow
{
  Q_OBJECT

  public:
  MainWindow(QWidget *parent = nullptr);
  ~MainWindow();

  private:
    NeuralNetwork *m_neutalNetwork;

    //массивы элементов
    static const int m_outputNum = 10;
    QLabel *m_labelsGroup1[m_outputNum];
    QLabel *m_labelsGroup2[m_outputNum];
    QProgressBar *m_progressBars[m_outputNum];

    //Элементы интерфейса
    QWidget *m_centralWidget; //глаынй виджет окна
    QLabel *m_resultLabel; //решение нейросети
    QGroupBox *m_groupBox1; //первая группа виджетов (верхняя)
    QGroupBox *m_groupBox2; //вторая группа виджетов (центральная)

    //cлой для размещения виджетов
    QGridLayout *m_mainGridLayout;
    QHBoxLayout *m_HlGroup1;
    QVBoxLayout *m_VlGroup1;
    QHBoxLayout *m_HlGroup2;
    QVBoxLayout *m_VlGroup2;



};
#endif // MAINWINDOW_H
