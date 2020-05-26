#include "Pen.h"

Pen::Pen(Shape *X, Shape *Y, ServoDriver *Z)
	: Square({ X->GetOrig().X , Y->GetOrig().Y }, 0.05f), PivotX(X), PivotY(Y), servo(Z) {};


void Pen::Routine(float time) {
	SetOrig({ PivotX->GetOrig().X, PivotY->GetOrig().Y });
}