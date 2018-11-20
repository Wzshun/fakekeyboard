#include "inputview.h"
#include "ui_inputview.h"
#include "inputcontext.h"
#include <QKeyEvent>
#include <QDebug>

InputView::InputView(InputContext *inputContext, QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::InputView)
    , m_inputContext(inputContext)
    , m_focusItem(NULL)
{
    ui->setupUi(this);
    Q_ASSERT(m_inputContext != NULL);

    //setWindowModality(Qt::WindowModal);
    setWindowFlags(/*windowFlags() |*/ Qt::Tool | Qt::FramelessWindowHint | Qt::WindowStaysOnTopHint | Qt::WindowDoesNotAcceptFocus);

    connect(ui->btn1, &QPushButton::clicked, [&](){
       qDebug() << "btn1 click!";
       normalBtn_onClick(ui->btn1);
    });
    connect(ui->btn2, &QPushButton::clicked, [&](){
       normalBtn_onClick(ui->btn2);
    });
    connect(ui->backspaceBtn, &QPushButton::clicked, [&](){
       sendKeyToFocusItem("\x7F");
    });
    connect(ui->hideBtn, &QPushButton::clicked, [&](){
        m_inputContext->hideInputPanel();
    });

}

InputView::~InputView()
{
    delete ui;
}

void InputView::normalBtn_onClick(QPushButton* btn)
{
    sendKeyToFocusItem(btn->text());
}

void InputView::setFocusItem(QObject* focusItem)
{
    m_focusItem = focusItem;
}

void InputView::sendKeyToFocusItem(const QString& text)
{
    qDebug() << "focusItem:" << m_focusItem;
    if(!m_focusItem)
        return;
    if(text == QString("\x7F")) //backspace
    {
        QCoreApplication::sendEvent(m_focusItem, new QKeyEvent(QEvent::KeyPress, Qt::Key_Backspace, Qt::NoModifier));
        QCoreApplication::sendEvent(m_focusItem, new QKeyEvent(QEvent::KeyRelease, Qt::Key_Backspace, Qt::NoModifier));
    }
    else
    {
        QCoreApplication::sendEvent(m_focusItem, new QKeyEvent(QEvent::KeyPress, 0, Qt::NoModifier, text));
        QCoreApplication::sendEvent(m_focusItem, new QKeyEvent(QEvent::KeyRelease, 0, Qt::NoModifier, text));
    }
}
