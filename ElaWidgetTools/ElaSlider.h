#ifndef ELASLIDER_H
#define ELASLIDER_H

#include <QSlider>

#include "ElaProperty.h"
class ElaToolTip;
class ElaSliderPrivate;
class ELA_EXPORT ElaSlider : public QSlider
{
    Q_OBJECT
    Q_Q_CREATE(ElaSlider)
public:
    explicit ElaSlider(QWidget* parent = nullptr);
    explicit ElaSlider(Qt::Orientation orientation, QWidget* parent = nullptr);
    ~ElaSlider();
protected:
    void mousePressEvent(QMouseEvent* event);
    void mouseMoveEvent(QMouseEvent* event);
    void mouseReleaseEvent(QMouseEvent* event);
private:
    ElaToolTip* _valueToolTip;
    bool _mousePressed{false};
};

#endif // ELASLIDER_H
