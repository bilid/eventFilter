#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    button=new QPushButton(this);
    _button=button;
    button->installEventFilter(this);
    QObject::connect(button,SIGNAL(clicked(bool)),this,SLOT(close()));

}

MainWindow::~MainWindow()
{
    delete ui;
}

bool MainWindow::eventFilter(QObject *watched, QEvent *event)
{
    if(watched==(QObject *)_button&&(event->type()==QEvent::MouseButtonPress||
                                     event->type()==QEvent::MouseButtonRelease||
                                     event->type()==QEvent::MouseButtonDblClick))
    {
        return true;
    }
   return QWidget::eventFilter( watched,  event);
}
