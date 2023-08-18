#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
  m_neutalNetwork = new NeuralNetwork(784, 100, 10);
}

MainWindow::~MainWindow()
{
  delete m_neutalNetwork;
}

