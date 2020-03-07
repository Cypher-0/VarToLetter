#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QString>
#include <QPushButton>

#include "conversions.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

#define BUILD_RELEASE 0

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pb_varToLetter_clicked();

    void on_pb_letterToVar_clicked();

private:
    Ui::MainWindow *ui;

    QList<QString> alphabet{"a","b","c","d","e","f","g","h","i","j","k","l","m","n","o","p","q","r","s","t","u","v","w","x","y","z",
                            "A","B","C","D","E","F","G","H","I","J","K","L","M","N","O","P","Q","R","S","T","U","V","W","X","Y","Z"};

    #if BUILD_RELEASE
        QString picDir{""};
    #else
        QString picDir{":/Pictures/Buttons/"};
    #endif

};

void setButtonPicture(QPushButton *bp, const QString &picPath, int size = 60);

#endif // MAINWINDOW_H
