#ifndef ELATOOLBARPRIVATE_H
#define ELATOOLBARPRIVATE_H
#include <QObject>

#include "ElaDef.h"
class ElaToolBarStyle;
class ElaToolBar;
class ElaToolBarPrivate : public QObject
{
    Q_OBJECT
    Q_D_CREATE(ElaToolBar)
public:
    explicit ElaToolBarPrivate(QObject* parent = nullptr);
    ~ElaToolBarPrivate() override;

private:
    ElaToolBarStyle* _toolBarStyle{nullptr};
    ElaThemeType::ThemeMode _themeMode;
    int _shadowBorderWidth{6};
};

#endif // ELATOOLBARPRIVATE_H
