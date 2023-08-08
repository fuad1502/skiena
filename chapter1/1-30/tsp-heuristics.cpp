#include <iostream>
#include <limits>
#include <math.h>
#include <algorithm>
#include "tsp-heuristics.hpp"

using namespace std;

float pointDistance(Point p1, Point p2);

float tspCalculateTotalDistance(list<Point> inputPoints)
{
	float totalDistance = 0;
	for(auto it = inputPoints.begin(); it != prev(inputPoints.end());
	    it = next(it)) {
		totalDistance += pointDistance(*it, *next(it));
	}
	return totalDistance;
}

list<Point> tspNearestNeighbor(list<Point> inputPoints)
{
	list<Point> pointOrdering;

	// simply return if the input list is empty
	if(inputPoints.size() == 0) {
		return pointOrdering;
	}

	// take whatever the supplied first point as the first point selected
	pointOrdering.push_back(inputPoints.front());
	inputPoints.pop_front();

	int numberOfPoints = inputPoints.size() + 1;
	for(int i = 0; i < numberOfPoints - 1; i++) {
		Point lastPoint = pointOrdering.back();
		Point selectedPoint;
		list<Point>::iterator selectedPointIt;
		float maximumDistance = numeric_limits<float>::infinity();

		// find point closest to the last point added
		for(auto it = inputPoints.begin(); it != inputPoints.end();
		    it = next(it)) {
			auto d = pointDistance(lastPoint, *it);
			if(d < maximumDistance) {
				maximumDistance = d;
				selectedPointIt = it;
				selectedPoint = *it;
			}
		}	
		pointOrdering.push_back(selectedPoint);
		inputPoints.erase(selectedPointIt);
	}

	pointOrdering.push_back(pointOrdering.front());

	return pointOrdering;
}

list<Point> tspClosestPair(list<Point> inputPoints)
{
	// simply return if the input list is empty
	if(inputPoints.size() == 0) {
		return list<Point>();
	}

	// initialize vertexChains with single-vertex chains
	list<list<Point>> vertexChains;
	for(auto it = inputPoints.begin(); it != inputPoints.end();
	    it = next(it)) {
		vertexChains.push_back(list<Point>{*it});
	}

	for(int i = 0; i < inputPoints.size() - 1; i++) {
		float maximumDistance = numeric_limits<float>::infinity();
		list<list<Point>>::iterator destinationChainIt;
		list<list<Point>>::iterator sourceChainIt;
		bool toFront, reverseSource;

		// find pair of end point vertices from different chains that 
		// are closest to each other
		for(auto it0 = vertexChains.begin(); it0 != vertexChains.end();
		    it0 = next(it0)) {
			if((*it0).empty()) 
				continue;
			for(auto it1 = next(it0); it1 != vertexChains.end();
			    it1 = next(it1)) {
				if((*it1).empty())
					continue;
				for(int i = 0; i < 2; i++) {
				for(int j = 0; j < 2; j++) {
					auto p1 = i == 0? (*it0).front() :
					   		  (*it0).back();
					auto p2 = j == 0? (*it1).front() :
					   		  (*it1).back();
					auto d = pointDistance(p1, p2);
					if(d < maximumDistance) {
						destinationChainIt = it0;
						sourceChainIt = it1;
						toFront = i == 0;
						reverseSource = j == 0;
						maximumDistance = d;
					}	
				}
				}
			}
		}

		// connect source list to destination list
		auto destinationVertexIt = (*destinationChainIt).end();
		if(toFront) {
			destinationVertexIt = 
			(*destinationChainIt).begin();
		}
		if(reverseSource) {
			(*sourceChainIt).reverse();
		}
		(*destinationChainIt).splice(destinationVertexIt, 
		                             (*sourceChainIt));
		(*sourceChainIt).clear();
	}	 

	// return the non-empty chain
	for(auto &vertexChain: vertexChains) {
		if(!vertexChain.empty()) {
			vertexChain.push_back(vertexChain.front());
			return vertexChain;
		}
	}

	return list<Point>();
}

float pointDistance(Point p1, Point p2)
{
	// return sqrt(pow(p1.x - p2.x, 2) + pow(p1.y - p2.y, 2));
	return abs(p1.x - p2.x) + abs(p1.y - p2.y);
}