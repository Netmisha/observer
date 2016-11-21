#ifndef TAGCLASS_H
#define TAGCLASS_H
#include <string>
#include <iostream>
#include <QPoint>
#include <QRect>
#include <QString>

using namespace  std;
class TagClass
{
public:
    QString tag_name;
    int tag_id;
    QRect TagPosition;
    TagClass();

};

#endif // TAGCLASS_H
