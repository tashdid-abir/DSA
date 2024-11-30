#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <limits>

struct Point {
    int x, y;
};

double distance(const Point& p1, const Point& p2) {
    return std::sqrt((p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y));
}

double bruteForce(const std::vector<Point>& points, int left, int right) {
    double minDist = std::numeric_limits<double>::max();
    for (int i = left; i < right; i++) {
        for (int j = i + 1; j <= right; j++) {
            minDist = std::min(minDist, distance(points[i], points[j]));
        }
    }
    return minDist;
}

double stripClosest(std::vector<Point>& strip, double d) {
    double minDist = d;
    std::sort(strip.begin(), strip.end(), [](const Point& p1, const Point& p2) {
        return p1.y < p2.y;
    });

    for (size_t i = 0; i < strip.size(); ++i) {
        for (size_t j = i + 1; j < strip.size() && (strip[j].y - strip[i].y) < minDist; ++j) {
            minDist = std::min(minDist, distance(strip[i], strip[j]));
        }
    }
    return minDist;
}

double closestPairRec(std::vector<Point>& points, int left, int right) {
    if (right - left + 1 <= 3) {
        return bruteForce(points, left, right);
    }

    int mid = left + (right - left) / 2;
    Point midPoint = points[mid];

    double dLeft = closestPairRec(points, left, mid);
    double dRight = closestPairRec(points, mid + 1, right);

    double d = std::min(dLeft, dRight);

    std::vector<Point> strip;
    for (int i = left; i <= right; i++) {
        if (std::abs(points[i].x - midPoint.x) < d) {
            strip.push_back(points[i]);
        }
    }

    return std::min(d, stripClosest(strip, d));
}

double closestPair(std::vector<Point>& points) {
    std::sort(points.begin(), points.end(), [](const Point& p1, const Point& p2) {
        return p1.x < p2.x;
    });

    return closestPairRec(points, 0, points.size() - 1);
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
