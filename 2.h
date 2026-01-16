#ifndef 2_H
#define 2_H

#include <vector>
#include <cmath>

namespace math_utils {
    struct Point {
        double x, y;
    };
    
    double distance(const Point& p1, const Point& p2);
    Point centroid(const std::vector<Point>& points);
}

#endif
