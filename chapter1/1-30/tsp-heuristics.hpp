#pragma once

#include <list>

class Point {
public:
	int x;
	int y;
	Point(int x = 0, int y = 0): x(x), y(y) {};
	friend bool operator==(const Point &lhs, const Point &rhs)
	{
		return (lhs.x == rhs.x) && (lhs.y == rhs.y);
	}
};

typedef struct Point Point; 

float tspCalculateTotalDistance(std::list<Point> inputPoints);
std::list<Point> tspNearestNeighbor(std::list<Point> inputPoints);
std::list<Point> tspClosestPair(std::list<Point> inputPoints);