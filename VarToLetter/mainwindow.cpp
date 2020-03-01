#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QDebug>
#include <QStringList>
#include <QPixmap>
#include <QPicture>
#include <QSize>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    setButtonPicture(ui->pb_varToLetter,":/Pictures/Buttons/Files/Pictures/downArrow.png");
    setButtonPicture(ui->pb_letterToVar,":/Pictures/Buttons/Files/Pictures/upArrow.png");
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pb_varToLetter_clicked()
{
    if(ui->te_calc_var->toPlainText().isEmpty())
        return;

    auto varMap{Conversions::getLetterListFromVars(ui->le_varList->text(),alphabet)};

    auto newText{Conversions::get_eq_varsToLetters(ui->te_calc_var->toPlainText(),varMap)};

    ui->te_calc_letter->setText(newText);
}

void MainWindow::on_pb_letterToVar_clicked()
{
    if(ui->te_calc_letter->toPlainText().isEmpty())
        return;


    auto varMap{Conversions::getLetterListFromVars(ui->le_varList->text(),alphabet)};

    auto newText{Conversions::get_eq_lettersToVars(ui->te_calc_var->toPlainText(),varMap)};

    ui->te_calc_var->setText(newText);
}






void setButtonPicture(QPushButton *bp, const QString &picPath, int size)
{
    QPixmap pixmap{picPath};
    QIcon icon{pixmap};

    bp->setIcon(icon);
    bp->setIconSize(QSize{size,size});

}
