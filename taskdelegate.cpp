#include "taskdelegate.h"
#include <QApplication>
#include <QFont>
#include <QFontMetrics>
#include <QStyleOptionViewItem>
#include <QDateTime>

TaskDelegate::TaskDelegate(QWidget *parent)
    : QStyledItemDelegate(parent)
{
}

//implementation of the paint function

void TaskDelegate::paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const
{

  painter->save();


  //extracting data from the TaskModel
  QString title = index.data(Qt::UserRole + 1).toString();
  QString category = index.data(Qt::UserRole +2).toString();
  QString description = index.data(Qt::UserRole +3).toString();
  QString deadlinestr = index.data(Qt::UserRole + 4).toString();
  QString priority = index.data(Qt::UserRole +5 ).toString();
  QString status = index.data(Qt::UserRole + 6).toString();



  QRect rect = option.rect.adjusted(5,5,-5,-5); //main rectangle of the card. works like div.

 //set background color.
  QColor bgcolor = (option.state &  QStyle::State_Selected)? QColor("#D6EAF8") : QColor("#E8F5E9");
  painter->setRenderHint(QPainter::Antialiasing);
  painter->setBrush(bgcolor);
  painter->setPen(QPen(QColor("BDBDBD"),1));
  painter->drawRoundedRect(rect,10,10);


  //title
  QFont titleFont = option.font; //copies the font to make changes only in it
   titleFont.setBold(true);
  titleFont.setPointSize(titleFont.pointSize() + 2);
  painter->setFont(titleFont);

  painter->setPen(Qt::black);
  QRect titleRect (rect.left()+10,rect.top()+10,rect.width() - 150 , 25);
  painter->drawText(titleRect,Qt::AlignLeft | Qt::AlignVCenter , title);

  //priority
  QFont priofont = option.font;
   priofont.setItalic(true);
   painter->setFont(priofont);
   QRect prioRect(rect.right() - 150 , rect.top() + 10 ,120 , 20 );
   painter->drawText(prioRect,Qt::AlignRight |  Qt::AlignVCenter , "[" + priority + "]");

  //doted line as a seperator
  painter->setPen(QPen(Qt::gray , 1 , Qt::DotLine));
  int dividerY = rect.top() + 38;
  painter->drawLine(rect.left()+ 10 , dividerY , rect.right()-10 , dividerY);

  //description.
  painter->setFont(option.font);
  painter->setPen(Qt::black);
 QRect descRect(rect.left()+10 , dividerY,rect.width() - 20 , dividerY +2);
 painter->drawText(descRect,Qt::AlignLeft | Qt::AlignVCenter , description);

 //due logic
 QDateTime deadline = QDateTime::fromString(deadlinestr,Qt::ISODate);
 QDateTime now = QDateTime::currentDateTime();

 QString dueText;
 QColor dueColor;

 if(deadline.isValid())
 {
     qint64 seconds = now.secsTo(deadline);

     if(seconds > 0)
     {
         if(seconds < 3600)
         {
             dueText =  QString("⏰ Due in %1 min").arg(seconds/60);
         }
         else if (seconds < 84600)
         {
             dueText = QString("⏰ Due in %1 h").arg(seconds/3600);
         }
         else
         {
             dueText = QString("⏰ Due in %1 d").arg(seconds/84600);
         }
         dueColor = Qt::green;
     }
     else
     {
         seconds = -seconds;
         if(seconds < 3600)
         {
             dueText =  QString("⏰ Overdue in %1 min").arg(seconds/60);
         }
         else if (seconds < 84600)
         {
             dueText = QString("⏰ Overdue in %1 hr").arg(seconds/3600);
         }
         else
         {
             dueText = QString("⏰ Overdue in %1  d").arg(seconds/84600);
         }
         dueColor = Qt::red;
     }
 }
 else
 {
     dueText = "No Deadline 😀🥳";
     dueColor = Qt::gray;
 }

 //drawing bottom line
 //due date
 painter->setPen(dueColor);
 int bottomY = rect.top() + 85;
 QRect dueRect(rect.left()+10, bottomY , rect.width()/3 -20 , 20);
 painter->drawText(dueRect, Qt::AlignLeft | Qt::AlignVCenter , dueText);

 //category
 painter->setPen(Qt::gray);
 QRect catRect(rect.left() + rect.width()/3 + 10, bottomY , rect.width()/3 - 20 , 20);
 painter->drawText(catRect, Qt::AlignLeft | Qt::AlignVCenter , "Category : " + category);

 //status
 QRect priorRect(rect.right() - rect.width()/3 + 10, bottomY , rect.width()/3 - 20 , 20);
 painter->drawText(priorRect, Qt::AlignRight | Qt::AlignVCenter , "Status : " + status);


painter->restore();
}

QSize TaskDelegate::sizeHint(const QStyleOptionViewItem &, const QModelIndex &) const
{
    return QSize(400, 130);  // Enough height to include 3 clean rows
}
