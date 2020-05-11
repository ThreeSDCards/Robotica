#include "Pen.h"

Pen::Pen(Shape *X, Shape *Y, ServoDriver *Z)
    : PivotX(X), PivotY(Y), servo(Z){};
