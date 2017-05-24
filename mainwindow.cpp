#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QWebEngineView* view = new QWebEngineView(this);
    viewList << view;
    view->load(QUrl("http://google.com"));
    ui->frame_3->layout()->addWidget(view);
    ui->centralwidget->layout()->setContentsMargins(0,0,0,0);
    ui->frame_3->layout()->setContentsMargins(0,0,0,0);
    ui->tab->layout()->setContentsMargins(0,0,0,0);
    ui->tabWidget->removeTab(1);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    int index = ui->tabWidget->currentIndex();
    viewList.at(index)->back();
}

void MainWindow::on_pushButton_2_clicked()
{
    int index = ui->tabWidget->currentIndex();
    viewList.at(index)->forward();
}

void MainWindow::on_pushButton_3_clicked()
{
    int index = ui->tabWidget->currentIndex();
    viewList.at(index)->reload();
}

void MainWindow::on_pushButton_4_clicked()
{
    int index = ui->tabWidget->currentIndex();
    viewList.at(index)->load(("http://" + ui->textBrowser->toPlainText()));
}


void MainWindow::on_tabWidget_tabCloseRequested(int index)
{
    viewList.removeAt(index);
    ui->tabWidget->removeTab(index);
}

void MainWindow::on_pushButton_5_clicked()
{
    QFrame *newFrame = new QFrame(ui->tabWidget);
    QVBoxLayout* newLayout = new QVBoxLayout();
    newFrame->setLayout(newLayout);
    QWebEngineView* view = new QWebEngineView(this);
    viewList << view;
    newLayout->addWidget(view);
    newLayout->setContentsMargins(0,0,0,0);
    view->load(QUrl("http://messenger.com"));
    ui->tabWidget->addTab(newFrame, "Messenger");
    ui->tabWidget->setCurrentIndex(viewList.size() - 1);
}
