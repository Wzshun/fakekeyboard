#include "inputcontext.h"
#include "inputview.h"
#include <QDesktopWidget>
#include <QDebug>
#include <QApplication>

InputContext::InputContext()
    : m_inputView(NULL)
{

}

InputContext::~InputContext()
{
}

bool InputContext::isValid() const
{
    return true;
}

QRectF InputContext::keyboardRect() const
{
    return (m_inputView) ? m_inputView->rect() : QRectF();
}

void InputContext::showInputPanel()
{
    if (!m_inputView)
    {
        m_inputView = new InputView(this);
    }

    QRect rect = QApplication::desktop()->availableGeometry();
    //pos to bottom center of screen
    QRect resultRect = rect;
    resultRect.setTop((rect.height() - m_inputView->geometry().height()));
    int x = rect.width() / 2 - m_inputView->geometry().width() / 2;
    resultRect.setLeft(rect.x() + x);
    m_inputView->setGeometry(resultRect);
    m_inputView->show();

    QPlatformInputContext::showInputPanel();
}

void InputContext::hideInputPanel()
{
    if (m_inputView)
    {
        m_inputView->hide();
    }

    QPlatformInputContext::hideInputPanel();
}

bool InputContext::isInputPanelVisible() const
{
    return (m_inputView) ? m_inputView->isVisible() : false;
}


void InputContext::setFocusObject(QObject *object)
{
    if (!m_inputView)
    {
        m_inputView = new InputView(this);
    }
    m_inputView->setFocusItem(object);
}


void InputContext::commit()
{
    qDebug() << "external commit";
}
