#ifndef TAGCLASS_H
#define TAGCLASS_H
#include <string>
#include <iostream>
#include <QPoint>
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
    TagClass();

};

#endif // TAGCLASS_H
