#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
  m_neutalNetwork = new NeuralNetwork(784, 100, 10);

  //настройка интерфейса
  m_centralWidget = new QWidget();
  setCentralWidget(m_centralWidget);
  m_mainGridLayout = new QGridLayout();
  m_centralWidget->setLayout(m_mainGridLayout);

  //1-я группа виджетов (верхняя)
  m_resultLabel = new QLabel("-");
  m_resultLabel->setAlignment(Qt::AlignCenter);
  m_resultLabel->setFont(QFont("Arial", 35, QFont::Bold));

  m_HlGroup1 = new QHBoxLayout();
  for(int i=0; i<m_outputNum; ++i){
    m_labelsGroup1[i] = new QLabel(QString::number(i));
    m_labelsGroup1[i]->setAlignment(Qt::AlignCenter);
    m_HlGroup1->addWidget(m_labelsGroup1[i]);
  }
  m_VlGroup1 = new QVBoxLayout();
  m_VlGroup1->addWidget(m_resultLabel);
  m_VlGroup1->addLayout(m_HlGroup1);
  m_groupBox1 = new QGroupBox();
  m_groupBox1->setLayout(m_VlGroup1);

  m_mainGridLayout->addWidget(m_groupBox1, 0, 0);

  //2-я группа виджетов
  m_HlGroup2 = new QHBoxLayout();
  for(int i=0; i<m_outputNum; ++i){
    m_progressBars[i] = new QProgressBar();
    m_progressBars[i]->setRange(0, 100);
    m_progressBars[i]->setOrientation(Qt::Vertical);
    m_labelsGroup2[i] = new QLabel(QString::number(i));
    m_labelsGroup2[i]->setAlignment(Qt::AlignCenter);
    m_VlGroup2 = new QVBoxLayout();
    m_VlGroup2->addWidget(m_progressBars[i]);
    m_VlGroup2->addWidget(m_labelsGroup2[i]);
    m_HlGroup2->addLayout(m_VlGroup2);
  }
  m_groupBox2 = new QGroupBox;
  m_groupBox2->setLayout(m_HlGroup2);
  m_mainGridLayout->addWidget(m_groupBox2, 1, 0);

  // 3-я группа виджетов
  m_paintWidget = new PaintWidget();
  m_VlGroup3 = new QVBoxLayout();
  m_clearButton = new QPushButton("Очистить");
  m_VlGroup3->addWidget(m_paintWidget);
  m_VlGroup3->addWidget(m_clearButton);
  m_groupBox3 = new QGroupBox();
  m_groupBox3->setLayout(m_VlGroup3);
  m_mainGridLayout->addWidget(m_groupBox3, 2, 0);

}

MainWindow::~MainWindow()
{
  delete m_neutalNetwork;
  delete m_resultLabel;
  delete m_centralWidget;
  delete m_mainGridLayout;
  delete []m_labelsGroup1;
  delete m_HlGroup1;
  delete m_groupBox1;
}

