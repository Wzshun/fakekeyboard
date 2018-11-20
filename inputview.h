#ifndef INPUTVIEW_H
#define INPUTVIEW_H

#include <QWidget>

class InputContext;
class QPushButton;

namespace Ui {
class InputView;
}

class InputView : public QWidget
{
    Q_OBJECT

public:
    explicit InputView(InputContext* inputContext, QWidget *parent = 0);
    ~InputView();

    void setFocusItem(QObject *focusItem);

private:
    void normalBtn_onClick(QPushButton *btn);
    void sendKeyToFocusItem(const QString &text);

private:
    Ui::InputView *ui;
    InputContext* m_inputContext;
    QObject* m_focusItem;
};

#endif // INPUTVIEW_H
