#include "2.h"
#include <iostream>
#include <fstream>
#include <algorithm>
#include <numeric>
#include <iterator>

namespace math_utils {
    double distance(const Point& p1, const Point& p2) {
        return std::sqrt((p2.x - p1.x) * (p2.x - p1.x) + (p2.y - p1.y) * (p2.y - p1.y));
    }
    
    Point centroid(const std::vector<Point>& points) {
        double sum_x = std::accumulate(points.begin(), points.end(), 0.0, 
            [](double acc, const Point& p) { return acc + p.x; });
        double sum_y = std::accumulate(points.begin(), points.end(), 0.0,
            [](double acc, const Point& p) { return acc + p.y; });
        return {sum_x / static_cast<double>(points.size()), 
                sum_y / static_cast<double>(points.size())};
    }
}

int main() {
    std::ifstream file("points.txt");
    std::vector<math_utils::Point> points;
    double x, y;
    while (file >> x >> y) {
        points.push_back({x, y});
    }
    
    math_utils::Point origin = {0, 0};
    std::sort(points.begin(), points.end(), [&origin](const auto& p1, const auto& p2) {
        return math_utils::distance(origin, p1) < math_utils::distance(origin, p2);
    });
    
    int first_quadrant = std::count_if(points.begin(), points.end(), 
        [](const auto& p) { return p.x > 0 && p.y > 0; });
    std::cout << "tocke u prvom kvadrantu: " << first_quadrant << std::endl;
    
    math_utils::Point c = math_utils::centroid(points);
    std::cout << "centroid: (" << c.x << ", " << c.y << ")" << std::endl;
    
    std::transform(points.begin(), points.end(), points.begin(), 
        [](const auto& p) { return math_utils::Point{p.x + 5, p.y + 3}; });
    
    points.erase(std::remove_if(points.begin(), points.end(),
        [](const auto& p) { return p.x < 0 && p.y < 0; }), points.end());
    
    std::cout << "tocke nakon transformacije:" << std::endl;
    for (const auto& p : points) {
        std::cout << "(" << p.x << ", " << p.y << ")" << std::endl;
    }
    
    return 0;
}
