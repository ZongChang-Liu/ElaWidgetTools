#ifndef ELACOMPACTDELEGATE_H
#define ELACOMPACTDELEGATE_H

#include <QStyledItemDelegate>

#include "Def.h"
#include "stdafx.h"
class ElaNavigationNode;
class ElaListView;
class QPropertyAnimation;
class ElaCompactDelegate : public QStyledItemDelegate
{
    Q_OBJECT
    Q_PRIVATE_CREATE(ElaListView*, ElaListView);

public:
    explicit ElaCompactDelegate(QObject* parent = nullptr);
    ~ElaCompactDelegate();
    Q_SLOT void onThemeChanged(ElaApplicationType::ThemeMode themeMode);
    void navigationNodeStateChange(QMap<QString, QVariant> data);

protected:
    void paint(QPainter* painter, const QStyleOptionViewItem& option, const QModelIndex& index) const override;
    QSize sizeHint(const QStyleOptionViewItem& option, const QModelIndex& index) const override;

private:
    qreal _lastSelectMarkTop{10};
    qreal _lastSelectMarkBottom{10};
    qreal _selectMarkTop{10};
    qreal _selectMarkBottom{10};
    bool _isSelectMarkDisplay{true};
    ElaNavigationNode* _lastSelectedNode{nullptr};
    QLinearGradient* _hovergradient{nullptr};
    QLinearGradient* _selectedgradient{nullptr};
    QLinearGradient* _selectedHovergradient{nullptr};
    ElaApplicationType::ThemeMode _themeMode;
    QPropertyAnimation* _lastSelectMarkTopAnimation{nullptr};
    QPropertyAnimation* _lastSelectMarkBottomAnimation{nullptr};
    QPropertyAnimation* _selectMarkTopAnimation{nullptr};
    QPropertyAnimation* _selectMarkBottomAnimation{nullptr};
    bool _compareItemY(ElaNavigationNode* node1, ElaNavigationNode* node2);
};

#endif // ELACOMPACTDELEGATE_H
