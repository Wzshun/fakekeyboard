#include "keyboardplugin.h"
#include "inputcontext.h"
#include <QDebug>

static const char PLUGINNAME[] = "FakeKeyboard";

static InputContext* s_inputContext = NULL;

QPlatformInputContext *KeyboardPlugin::create(const QString &key, const QStringList &paramList)
{
    Q_UNUSED(paramList)
    if(key.compare(QLatin1String(PLUGINNAME), Qt::CaseInsensitive) == 0){
        qDebug() << "create";
        s_inputContext = new InputContext();
    }
    qDebug() << "fuck!!!!!!";
    return s_inputContext;
}
