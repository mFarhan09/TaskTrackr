#ifndef TASKMODEL_H
#define TASKMODEL_H


#include <QAbstractListModel>
#include "task.h"



class TaskModel: public QAbstractListModel
{
    Q_OBJECT

public:
    explicit TaskModel(QObject *parent = nullptr );

     int rowCount (const QModelIndex &parent =QModelIndex()) const override;
    QVariant data(const QModelIndex &index,int role = Qt::DisplayRole) const override;

    enum TaskRoles
    {
        TitleRole = Qt::UserRole + 1,
        CategoryRole,
        DescriptionRole,
        DeadlineRole,
        PriorityRole,
        StatusRole
    };

   void addTask(const Task &task);
   void removeTask(int row);

protected:
   QHash<int,QByteArray> roleNames() const override;
private:
   QList <Task> m_tasks;

};

#endif // TASKMODEL_H


