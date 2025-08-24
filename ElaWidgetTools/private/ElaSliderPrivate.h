//
// Created by liu_zongchang on 25-5-31 下午7:17.
// Email 1439797751@qq.com
//

#ifndef ELASLIDERPRIVATE_H
#define ELASLIDERPRIVATE_H

#include <QObject>
#include "ElaProperty.h"
class ElaSlider;
class ElaSliderStyle;
class ElaSliderPrivate : public QObject
{
    Q_OBJECT
    Q_D_CREATE(ElaSlider)
public:
    explicit ElaSliderPrivate(QObject* parent = nullptr);
    ~ElaSliderPrivate();

private:
    ElaSliderStyle* _sliderStyle{nullptr};
};



#endif //ELASLIDERPRIVATE_H
