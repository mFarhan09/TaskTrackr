#include "taskmodel.h"

TaskModel::TaskModel(QObject * parent) : QAbstractListModel(parent)
{

}


 int TaskModel::rowCount(const QModelIndex &parent) const
 {
     if(parent.isValid())  // returns 0 if it is a child request, we are flat list
     {
         return 0;
     }
     return m_tasks.count();

 }



 QVariant TaskModel::data(const QModelIndex &index, int role) const
 {
     if(!index.isValid() || index.row() < 0 || index.row() >= m_tasks.size())
     {
         return QVariant(); // don't render anything if index is not valied or out of bound from any end
     }

     const Task &task = m_tasks[index.row()]; //get the task of  current row.


     switch (role)
     {
      case (TitleRole) : return task.getTitle();
      case(CategoryRole) : return task.getCategory();
      case (DescriptionRole): return task.getDescription();
      case (DeadlineRole):  return task.getDeadline();
      case (PriorityRole) : return task.getPriority();
      case (StatusRole) : return task.getStatus();
      case Qt::DisplayRole: return task.getTitle();
       default : return QVariant();
     }
 }

void TaskModel::addTask(const Task &task)
{
    beginInsertRows(QModelIndex(),m_tasks.size(),m_tasks.size());
    m_tasks.append(task);
    endInsertRows();
}


void TaskModel::removeTask(int row)
{
  if(row < 0 || row>=m_tasks.size())
      return;

  beginRemoveRows(QModelIndex(), row, row);
  m_tasks.removeAt(row);
  endRemoveRows();
}

QHash<int,QByteArray> TaskModel::roleNames() const
{
    QHash <int,QByteArray> roles ;

    roles[TitleRole] = "title";
    roles[CategoryRole] = "category";
    roles[DescriptionRole] = "description";
    roles[DeadlineRole] = "deadline";
    roles[PriorityRole] = "priority";
    roles[StatusRole] = "status";


    return roles;
}
