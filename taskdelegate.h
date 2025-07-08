#ifndef TASKDELEGATE_H
#define TASKDELEGATE_H

#include <QStyledItemDelegate>
#include <QPainter>


class TaskDelegate : public QStyledItemDelegate
{
    Q_OBJECT
public:
    explicit TaskDelegate(QWidget * parent = nullptr);


    void paint(QPainter * painter, const QStyleOptionViewItem &option , const QModelIndex &index) const override;

    QSize sizeHint(const QStyleOptionViewItem &option ,const QModelIndex &index) const override;
};

#endif // TASKDELEGATE_H
