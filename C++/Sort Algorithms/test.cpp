#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <limits>

struct Point {
    int x, y;
};

double closestPair(std::vector<Point>& points) {
    std::sort( points.begin(), points.end(), []( const Point& p1, const Point& p2 ) {
        return p1.x < p2.x;
    } );

}

void printPoints(const std::vector<Point>& points) {
    for (const Point& p : points) {
        std::cout << "(" << p.x << ", " << p.y << ") ";
    }
    std::cout << std::endl;
}



int main() {
    std::vector<Point> points = { {2, 3}, {12, 30}, {40, 50}, {5, 1}, {12, 10}, {3, 4} };

    std::cout << "Points: ";
    printPoints(points);

    double minDistance = closestPair(points);
    std::cout << "The smallest distance is: " << minDistance << std::endl;

    return 0;
}
