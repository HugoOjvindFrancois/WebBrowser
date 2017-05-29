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
    ui->progressBar->setContentsMargins(0,0,0,0);
    ui->centralwidget->layout()->setSpacing(0);
    ui->tabWidget->removeTab(1);
    setContentsMargins(0,0,0,0);
    layout()->setSpacing(0);

    connect(view,SIGNAL(loadFinished(bool)),this,SLOT(on_page_load(bool)));
    connect(view,SIGNAL(loadProgress(int)),ui->progressBar,SLOT(setValue(int)));
    connect(ui->progressBar,SIGNAL(valueChanged(int)),this,SLOT(on_progressbar_finish(int)));

    settings = new SettingDialog(this);
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
    viewList.at(index)->load(("http://" + ui->lineEdit->text()));
}


void MainWindow::on_tabWidget_tabCloseRequested(int index)
{
    QWebEngineView *ancient = viewList.at(index);
    ancient->disconnect();
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
    connect(view,SIGNAL(loadFinished(bool)),this,SLOT(on_page_load(bool)));
    connect(view,SIGNAL(loadProgress(int)),ui->progressBar,SLOT(setValue(int)));
}

void MainWindow::on_page_load(bool load)
{
    if(load) {
        int index = ui->tabWidget->currentIndex();
        ui->tabWidget->setTabText(index,viewList.at(index)->title());
        ui->tabWidget->setTabIcon(index,viewList.at(index)->icon());
        ui->tabWidget->update();
        ui->tabWidget->tabBar()->update();
    }
}

void MainWindow::on_progressbar_finish(int value)
{
    if(value == ui->progressBar->maximum())
        ui->progressBar->setValue(0);
}

void MainWindow::on_pushButton_6_clicked()
{
    settings->show();
}

void MainWindow::closeEvent (QCloseEvent *event)
{
    if (settings->isActiveWindow()) {
        settings->close();
    }
    event->accept();
}

void MainWindow::on_lineEdit_returnPressed()
{
    on_pushButton_4_clicked();
}

void MainWindow::on_lineEdit_clicked()
{
    ui->lineEdit->selectAll();
}

void MainWindow::on_pushButton_7_clicked()
{
    int index = ui->tabWidget->currentIndex();
    viewList.at(index)->load(QUrl("http://google.com"));
}

void MainWindow::on_pushButton_8_clicked()
{
    bool ok = false;
    QString input = QInputDialog::getText(this, "Search", "Search something ?", QLineEdit::Normal, QString(), &ok);
    if (ok && !input.isEmpty()) {
        QMessageBox::information(this, "Search", "Hi, I will search " + input + " in a minute.");
    } else {
        QMessageBox::critical(this, "Search", "It's empty you bastard !");
    }
}
