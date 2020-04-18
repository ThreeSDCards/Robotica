#include "Pen.h"

Pen::Pen(PivotPoint *X, PivotPoint *Y, ServoDriver *Z)
    : PivotX(X), PivotY(Y), servo(Z){};
