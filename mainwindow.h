#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QWebEngineView>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_pushButton_clicked();
    void on_pushButton_2_clicked();
    void on_pushButton_3_clicked();
    void on_pushButton_4_clicked();
    void on_tabWidget_tabCloseRequested(int index);
    void on_pushButton_5_clicked();
    void on_page_load(bool load);
    void on_progressbar_finish(int value);

    void on_textBrowser_textChanged();

private:
    Ui::MainWindow *ui;
    QList<QWebEngineView *> viewList;
};

#endif // MAINWINDOW_H
