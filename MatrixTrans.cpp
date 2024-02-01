#include "MatrixTrans.h"


Vector2 Add(Vector2& v, float num)
{
    Vector2 result;
    result.x = v.x + num;
    result.y = v.y + num;
    return result;
}

Vector2 Subtract(Vector2& v, float num)
{
    Vector2 result;
    result.x = v.x - num;
    result.y = v.y - num;
    return result;
}