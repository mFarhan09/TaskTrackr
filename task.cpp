#include "task.h"

Task::Task(const QString &title,const QString &category,const QString &description,const QDateTime &deadline,const QString &priority,const QString &status)
{
  this->title = title;
    this->category = category;
    this->description = description;
    this->deadline = deadline;
    this->priority = priority;
    this->status = status;
}

//getters
QString Task::getTitle() const
{
    return this->title;
}

QString Task::getCategory() const
{
    return this->category;
}
QString Task::getDescription() const
{
    return this->description;
}
QDateTime Task::getDeadline() const
{
    return this->deadline;
}
QString Task::getPriority() const
{
    return this->priority;
}
QString Task::getStatus() const
{
    return this->status;
}


//setters
void Task::setTitle(const QString &title)
{
    this->title = title;
}

void Task::setDescription(const QString &description)
{
    this->description = description;
}
void Task::setDeadline(const QDateTime &deadline)
{
    this->deadline = deadline;
}
void Task::setPriority(const QString &priority)
{
    this->priority = priority;
}
void Task::setStatus(const QString &status)
{
    this->status = status;
}

void Task::setCategory(const QString &category)
{
    this->category = category;
}

bool Task::isDueSoon(int minutes) const
{
    QDateTime now = QDateTime::currentDateTime();
    return !status.contains("Completed", Qt::CaseInsensitive) &&
           now.secsTo(deadline) <= minutes * 60 &&
           now < deadline;

}
