#include "ElaSlider.h"

#include <QMouseEvent>
#include <QStyleOptionSlider>

#include "ElaSliderPrivate.h"
#include "ElaToolTip.h"
#include "DeveloperComponents/ElaSliderStyle.h"
ElaSlider::ElaSlider(QWidget* parent)
    : QSlider(parent) ,d_ptr(new ElaSliderPrivate)
{
    Q_D(ElaSlider);
    d->q_ptr = this;
    setOrientation(Qt::Horizontal);
    d->_sliderStyle = new ElaSliderStyle(style());
    setStyle(d->_sliderStyle);

    _valueToolTip = new ElaToolTip(this);
    _valueToolTip->setToolTip(QString::number(this->value()));
    _valueToolTip->setOffSetX(-20);
    _valueToolTip->setOffSetY(-60);
    connect(this, &ElaSlider::valueChanged, this, [=](const int value) {
        _valueToolTip->setToolTip(QString::number(value));
    });
}

ElaSlider::ElaSlider(Qt::Orientation orientation, QWidget* parent)
    : QSlider(orientation, parent)
{
    setStyle(new ElaSliderStyle(style()));
}

ElaSlider::~ElaSlider()
{
}

void ElaSlider::mousePressEvent(QMouseEvent* event)
{
    QSlider::mousePressEvent(event);
    if (event->button() == Qt::LeftButton) {
        _mousePressed = true;
        QStyleOptionSlider opt;
        initStyleOption(&opt);
        QRect handleRect = style()->subControlRect(QStyle::CC_Slider, &opt, QStyle::SC_SliderHandle, this);
        if (handleRect.contains(event->pos())) {
            _valueToolTip->updatePos(QCursor::pos());
            _valueToolTip->show();
        } else {
            _valueToolTip->hide();
        }
    }
}

void ElaSlider::mouseMoveEvent(QMouseEvent* event)
{
    QSlider::mouseMoveEvent(event);
    if (_mousePressed)
    {
        QStyleOptionSlider opt;
        initStyleOption(&opt);
        QRect handleRect = style()->subControlRect(QStyle::CC_Slider, &opt, QStyle::SC_SliderHandle, this);
        if (handleRect.contains(event->pos())) {
            _valueToolTip->updatePos(QCursor::pos());
            _valueToolTip->show();
        } else {
            _valueToolTip->hide();
        }
    } else {
        _valueToolTip->hide();
    }
}

void ElaSlider::mouseReleaseEvent(QMouseEvent* event)
{
    QSlider::mouseReleaseEvent(event);
    _valueToolTip->hide();
    _mousePressed = false;
}
