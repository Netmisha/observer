#ifndef TAGCLASS_H
#define TAGCLASS_H
#include <string>
#include <iostream>
#include <QPoint>
<<<<<<< HEAD
#include <QRect>
#include <QString>

using namespace  std;
class TagClass
{
public:
    QString tag_name;
    int tag_id;
    QRect TagPosition;
=======
using namespace  std;
class TagClass
{
private:
   string tag_name;
   int tag_id;
   QPoint Ax,Ay;
   int Width;
   int Heigth;
public:
>>>>>>> e5c87a470dae447102e6f6e38b83b461d38a34d8
    TagClass();

};

#endif // TAGCLASS_H
