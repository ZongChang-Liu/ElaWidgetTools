#ifndef ELAMESSAGEBAR_H
#define ELAMESSAGEBAR_H

#include <QWidget>

#include "ElaDef.h"
#include "ElaProperty.h"

class ElaMessageBarPrivate;
class ELA_EXPORT ElaMessageBar : public QWidget
{
    Q_OBJECT
    Q_Q_CREATE(ElaMessageBar)

public:
    static ElaMessageBar* success(ElaMessageBarType::PositionPolicy policy, QString title, QString text, int displayMsec, QWidget* parent = nullptr);
    static ElaMessageBar* warning(ElaMessageBarType::PositionPolicy policy, QString title, QString text, int displayMsec, QWidget* parent = nullptr);
    static ElaMessageBar* information(ElaMessageBarType::PositionPolicy policy, QString title, QString text, int displayMsec, QWidget* parent = nullptr);
    static ElaMessageBar* error(ElaMessageBarType::PositionPolicy policy, QString title, QString text, int displayMsec, QWidget* parent = nullptr);

    Q_SIGNALS:
    Q_SIGNAL void clicked();
protected:
    virtual void paintEvent(QPaintEvent* event) override;
    virtual bool eventFilter(QObject* watched, QEvent* event) override;

private:
    friend class ElaMessageBarManager;
    explicit ElaMessageBar(ElaMessageBarType::PositionPolicy policy, ElaMessageBarType::MessageMode messageMode, QString& title, QString& text, int displayMsec, QWidget* parent = nullptr);
    ~ElaMessageBar();
};

#endif // ELAMESSAGEBAR_H
