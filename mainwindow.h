#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "neuralnetwork.h"

class MainWindow : public QMainWindow
{
  Q_OBJECT

  public:
  MainWindow(QWidget *parent = nullptr);
  ~MainWindow();

  private:
    NeuralNetwork *m_neutalNetwork;
};
#endif // MAINWINDOW_H
