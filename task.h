#ifndef TASK_H
#define TASK_H

#include <QObject>
#include <QDateTime>
#include <QString>
//#include <QGadget>

class Task
{
    Q_GADGET

public:
    Task();
    Task(const QString &title,const QString &category,const QString &description,const QDateTime &deadline,const QString &priority,const QString &status);

    //getters
    QString getTitle() const;
    QString getCategory() const;
    QString getDescription() const;
    QDateTime getDeadline() const;
    QString getPriority() const ;
    QString getStatus() const;

    //setters
    void setTitle(const QString &title);
    void setCategory(const QString &category);
    void setDescription(const QString &description);
    void setDeadline(const QDateTime &deadline);
    void setPriority(const QString &priority);
    void setStatus(const QString &status);

    bool isDueSoon(int minutes = 10) const;


private:
   QString title;
   QString category;
   QString description;
   QDateTime deadline;
   QString priority;
   QString status;

};

#endif // TASK_H
