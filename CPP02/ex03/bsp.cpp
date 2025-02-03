#include "bsp.hpp"
#include <cmath>  

Fixed area(Point const a, Point const b, Point const c) {
    return Fixed(0.5f) * ((a.getX() * (b.getY() - c.getY())) +
                           (b.getX() * (c.getY() - a.getY())) +
                           (c.getX() * (a.getY() - b.getY()))).toFloat();
}

bool bsp(Point const a, Point const b, Point const c, Point const point) {
    Fixed totalArea = area(a, b, c);
    Fixed area1 = area(point, a, b);
    Fixed area2 = area(point, b, c);
    Fixed area3 = area(point, c, a);

    bool isInside = (fabs(totalArea.toFloat() - (area1 + area2 + area3).toFloat()) < 0.0001f);
    if (area1.toFloat() < 0 || area2.toFloat() < 0 || area3.toFloat() < 0) {
        return false;
    }
    if (area1 == Fixed(0) || area2 == Fixed(0) || area3 == Fixed(0)) {
        return false;
    }
    return isInside;
}

