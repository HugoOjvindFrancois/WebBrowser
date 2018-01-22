#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QWebEngineView>
#include <QCloseEvent>
#include <QUrl>
#include <QInputDialog>
#include <QMessageBox>

#include "settingdialog.h"

namespace Ui {
    class MainWindow;
}

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void loadUrl(QString url);

private slots:
    void on_pushButton_clicked();
    void on_pushButton_2_clicked();
    void on_pushButton_3_clicked();
    void on_pushButton_4_clicked();
    void on_tabWidget_tabCloseRequested(int index);
    void on_pushButton_5_clicked();
    void on_page_load(bool load);
    void on_progressbar_finish(int value);
    void on_pushButton_6_clicked();
    void on_lineEdit_clicked();
    void on_lineEdit_returnPressed();

    void on_pushButton_7_clicked();

    void on_pushButton_8_clicked();

private:
    Ui::MainWindow *ui;
    QList<QWebEngineView *> viewList;
    SettingDialog *settings;
    void closeEvent (QCloseEvent *event);
};

#endif // MAINWINDOW_H
