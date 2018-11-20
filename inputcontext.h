#ifndef INPUTCONTEXT_H
#define INPUTCONTEXT_H

#include <qpa/qplatforminputcontext.h>

class InputView;

class InputContext : public QPlatformInputContext
{    
    Q_OBJECT

public:
    InputContext();
    ~InputContext();

    // QPlatformInputContext interface
public:
    void commit() override;
    bool isValid() const;
    QRectF keyboardRect() const;
    bool isInputPanelVisible() const;
    void setFocusObject(QObject *object);

public slots:
    void hideInputPanel();
    void showInputPanel();

private:
    InputView* m_inputView;
};

#endif // INPUTCONTEXT_H
