#include "Square.h"
Square::Square()
{
    //Fill with 0 points
    for (char i = 0; i < 4; i++)
        points.push_back({0, 0});
    size = 0;
}

Square::Square(const Point &pos, float size)
{
    SetOrig(pos);
    this->size = size;
    points.push_back(GetOrig().Add(-0.5 * size, -0.5 * size)); // top left
    points.push_back(GetOrig().Add(0.5 * size, -0.5 * size));
    points.push_back(GetOrig().Add(-0.5 * size, 0.5 * size));
    points.push_back(GetOrig().Add(0.5 * size, 0.5 * size));
}

Point &Square::TL()
{
    return points.at(0);
}

Point &Square::TR()
{
    return points.at(1);
}

Point &Square::BL()
{
    return points.at(2);
}

Point &Square::BR()
{
    return points.at(3);
}

void Square::Draw()
{
    glVertex2f(TL().X, TL().Y);
    glVertex2f(TR().X, TR().Y);
    glVertex2f(BR().X, BR().Y);

    glVertex2f(TL().X, TL().Y);
    glVertex2f(BR().X, BR().Y);
    glVertex2f(BL().X, BL().Y);
}

std::vector<Point> &Square::Points()
{
    return points;
}

bool test_Square()
{
    try
    {
        Square &sq = *(new Square({0, 0}, 0.3f));
        if (sq.TL().X != -0.15f || sq.BR().Y != 0.15f)
            throw "SQUARE ERROR";
        return true;
    }
    catch (const char *e)
    {
        return false;
    }
}

bool test_Shape()
{
    try
    {
        Square &sq = *(new Square({5.0f, 3.0f}, 3.0f));
        //Test GetOrig
        if (sq.GetOrig().X != 5.0f || sq.GetOrig().Y != 3.0f)
        {
            throw "SHAPE ERROR (GETORIG)";
        }
        //Test Move
        sq.Move(2.0f, 1.0f);
        if (sq.GetOrig().X != 7.0f || sq.GetOrig().Y != 4.0f)
        {
            throw "SHAPE ERROR (MOVE)";
        }
        //Test SetOrig
        sq.SetOrig({0, 0});
        if (sq.GetOrig().X != 0 || sq.GetOrig().Y != 0)
        {
            throw "SHAPE ERROR (SETORIG)";
        }

        return true;
    }
    catch (const char *e)
    {
        return false;
    }
}