#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include <QProcess>
#include <QByteArray>
#include <QTextBrowser>
#include <QFileDialog>
#include <QDesktopServices>
#include <QComboBox>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void executeCommand();
    void outputCommand();
    void setSource();
    void setDestination();
    void setQSV();
    void setX264();
    void setHEVC();
    void setVAAPI();

private:
    Ui::MainWindow *ui;
    QProcess commandProcess;
};
#endif // MAINWINDOW_H
