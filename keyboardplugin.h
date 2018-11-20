#ifndef KEYBOARDPLUGIN_H
#define KEYBOARDPLUGIN_H

#include "fakekeyboard_global.h"
#include <qpa/qplatforminputcontextplugin_p.h>

class FAKEKEYBOARDSHARED_EXPORT KeyboardPlugin :  public QPlatformInputContextPlugin
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID QPlatformInputContextFactoryInterface_iid FILE "fakeKeyboard.json")

    // QPlatformInputContextPlugin interface
public:
    QPlatformInputContext *create(const QString &key, const QStringList &paramList) override;
};


#endif // KEYBOARDPLUGIN_H
