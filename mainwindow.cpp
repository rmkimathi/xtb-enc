#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QDebug>
#include <QString>
#include <QProcess>
#include <QScrollBar>
#include <QMessageBox>
#include <QFileInfo>
#include <QFileDialog>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    connect (&commandProcess, SIGNAL(readyReadStandardOutput()),this, SLOT(outputCommand()));
    connect (&commandProcess, SIGNAL(readyReadStandardError()),this, SLOT(outputCommand()));

    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}



void MainWindow::setQSV()
{
    ui->ComboBox_VCodec->clear();
    ui->ComboBox_ICQ->clear();
    ui->ComboBox_VBitrate->clear();
    ui->ComboBox_GoP->clear();
    ui->ComboBox_ACodec->clear();
    ui->ComboBox_ABitrate->clear();
    ui->ComboBox_VCodec->addItem("h264_qsv");
    ui->ComboBox_ICQ->addItem("27");
    ui->ComboBox_ICQ->addItem("33");
    ui->ComboBox_GoP->addItem("24");
    ui->ComboBox_GoP->addItem("25");
    ui->ComboBox_GoP->addItem("30");
    ui->ComboBox_GoP->addItem("60");
    ui->ComboBox_ACodec->addItem("libfdk_aac");
    ui->ComboBox_ACodec->addItem("ac3_fixed");
    ui->ComboBox_ABitrate->addItem("128k");
    ui->ComboBox_ABitrate->addItem("192k");
    ui->ComboBox_ABitrate->addItem("384k");
    ui->lineEdit_Destination->setText("M4V80113.mp4");

}

void MainWindow::setX264()
{
    ui->ComboBox_VCodec->clear();
    ui->ComboBox_ICQ->clear();
    ui->ComboBox_VBitrate->clear();
    ui->ComboBox_GoP->clear();
    ui->ComboBox_ACodec->clear();
    ui->ComboBox_ABitrate->clear();
    ui->ComboBox_VCodec->addItem("libx264");
    ui->ComboBox_VBitrate->addItem("1000k");
    ui->ComboBox_VBitrate->addItem("1500k");
    ui->ComboBox_GoP->addItem("24");
    ui->ComboBox_GoP->addItem("25");
    ui->ComboBox_GoP->addItem("30");
    ui->ComboBox_GoP->addItem("60");
    ui->ComboBox_ACodec->addItem("libfdk_aac");
    ui->ComboBox_ACodec->addItem("ac3_fixed");
    ui->ComboBox_ABitrate->addItem("128k");
    ui->ComboBox_ABitrate->addItem("192k");
    ui->ComboBox_ABitrate->addItem("384k");
    ui->lineEdit_Destination->setText("M4V80113.mp4");

}

void MainWindow::setHEVC()
{
    ui->ComboBox_VCodec->clear();
    ui->ComboBox_ICQ->clear();
    ui->ComboBox_VBitrate->clear();
    ui->ComboBox_GoP->clear();
    ui->ComboBox_ACodec->clear();
    ui->ComboBox_ABitrate->clear();
    ui->ComboBox_VCodec->addItem("hevc_qsv");
    ui->ComboBox_ICQ->addItem("27");
    ui->ComboBox_ICQ->addItem("33");
    ui->ComboBox_GoP->addItem("24");
    ui->ComboBox_GoP->addItem("25");
    ui->ComboBox_GoP->addItem("30");
    ui->ComboBox_GoP->addItem("60");
    ui->ComboBox_ACodec->addItem("libfdk_aac");
    ui->ComboBox_ACodec->addItem("ac3_fixed");
    ui->ComboBox_ABitrate->addItem("128k");
    ui->ComboBox_ABitrate->addItem("192k");
    ui->ComboBox_ABitrate->addItem("384k");
    ui->lineEdit_Destination->setText("M4V80113.mp4");

}

void MainWindow::setVAAPI()
{
    ui->ComboBox_VCodec->clear();
    ui->ComboBox_ICQ->clear();
    ui->ComboBox_VBitrate->clear();
    ui->ComboBox_GoP->clear();
    ui->ComboBox_ACodec->clear();
    ui->ComboBox_ABitrate->clear();
    ui->ComboBox_VCodec->addItem("h264_vaapi");
    ui->ComboBox_ICQ->addItem("27");
    ui->ComboBox_ICQ->addItem("33");
    ui->ComboBox_GoP->addItem("24");
    ui->ComboBox_GoP->addItem("25");
    ui->ComboBox_GoP->addItem("30");
    ui->ComboBox_GoP->addItem("60");
    ui->ComboBox_ACodec->addItem("libfdk_aac");
    ui->ComboBox_ACodec->addItem("ac3_fixed");
    ui->ComboBox_ABitrate->addItem("128k");
    ui->ComboBox_ABitrate->addItem("192k");
    ui->ComboBox_ABitrate->addItem("384k");
    ui->lineEdit_Destination->setText("M4V80113.mp4");

}

void MainWindow::executeCommand()

{
    {
        qDebug() << "executeCommand()";
    }

    QStringList args;

    if (ui->radioButton_QSV->isChecked()){

    args << "-i";
    args << ui->lineEdit_Source->text();
    args << "-y";
    args << "-global_quality"; args << ui->ComboBox_ICQ->currentText();
    args << "-g"; args << ui->ComboBox_GoP->currentText();
    //args << "-c:v"; args << ui->lineEdit_VBitrate->text();
    args << "-c:v"; args << ui->ComboBox_VCodec->currentText();
    args << "-b:a"; args << ui->ComboBox_ABitrate->currentText();
    args << "-loglevel"; args << "verbose";
    args << "-map_metadata"; args << "-1";
    args << "-metadata:s:a"; args << "language=eng";
    args << "-metadata"; args << "creation_time=now";
    args << ui->lineEdit_Destination->text();
    qDebug() << args;

    commandProcess.start("ffmpeg", args);

    }

    if (ui->radioButton_X264->isChecked()){

    args << "-i";
    args << ui->lineEdit_Source->text();
    args << "-y";
    args << "-b:v"; args << ui->ComboBox_VBitrate->currentText();
    args << "-g"; args << ui->ComboBox_GoP->currentText();
    //args << "-c:v"; args << ui->lineEdit_VBitrate->text();
    args << "-c:v"; args << ui->ComboBox_VCodec->currentText();
    args << "-b:a"; args << ui->ComboBox_ABitrate->currentText();
    args << "-loglevel"; args << "verbose";
    args << "-map_metadata"; args << "-1";
    args << "-metadata:s:a"; args << "language=eng";
    args << "-metadata"; args << "creation_time=now";
    args << ui->lineEdit_Destination->text();
    qDebug() << args;

    commandProcess.start("ffmpeg", args);
    }

    if (ui->radioButton_HEVC->isChecked()){

    args << "-i";
    args << ui->lineEdit_Source->text();
    args << "-y";
    args << "-global_quality"; args << ui->ComboBox_ICQ->currentText();
    args << "-g"; args << ui->ComboBox_GoP->currentText();
    //args << "-c:v"; args << ui->lineEdit_VBitrate->text();
    args << "-c:v"; args << ui->ComboBox_VCodec->currentText();
    args << "-b:a"; args << ui->ComboBox_ABitrate->currentText();
    args << "-loglevel"; args << "verbose";
    args << "-map_metadata"; args << "-1";
    args << "-metadata:s:a"; args << "language=eng";
    args << "-metadata"; args << "creation_time=now";
    args << ui->lineEdit_Destination->text();
    qDebug() << args;

    commandProcess.start("ffmpeg", args);
    }

    if (ui->radioButton_VAAPI->isChecked()){

    args << "-vaapi_device"; args << "/dev/dri/renderD128";
    args << "-i";
    args << ui->lineEdit_Source->text();
    args << "-y";
    args << "-vf"; args << "format=nv12,hwupload";
    args << "-qp"; args << ui->ComboBox_ICQ->currentText();
    args << "-g"; args << ui->ComboBox_GoP->currentText();
    //args << "-c:v"; args << ui->lineEdit_VBitrate->text();
    args << "-c:v"; args << ui->ComboBox_VCodec->currentText();
    args << "-b:a"; args << ui->ComboBox_ABitrate->currentText();
    args << "-loglevel"; args << "verbose";
    args << "-map_metadata"; args << "-1";
    args << "-metadata:s:a"; args << "language=eng";
    args << "-metadata"; args << "creation_time=now";
    args << ui->lineEdit_Destination->text();
    qDebug() << args;

    commandProcess.start("ffmpeg", args);
    }

}

void MainWindow::outputCommand()
{
    QByteArray cmdoutput = commandProcess.readAllStandardOutput();
    QString txtoutput = cmdoutput;
    ui->textBrowser->append(txtoutput);
    cmdoutput = commandProcess.readAllStandardError();
    txtoutput = cmdoutput;
    ui->textBrowser->append(txtoutput);

}

void MainWindow::setDestination()
{
    QString file = QFileDialog::getSaveFileName (this, tr("Select Destination"),
         QStandardPaths::standardLocations(QStandardPaths::MoviesLocation).last());
    ui->lineEdit_Destination->setText(file);
}

void MainWindow::setSource()
{
     QString file = QFileDialog::getOpenFileName(this, tr("Select Source File"),
         QStandardPaths::standardLocations(QStandardPaths::MoviesLocation).last());
    ui->lineEdit_Source->setText(file);

}
