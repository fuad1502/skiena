#include <random>
#include <iostream>
#include "tsp-heuristics.hpp"

using namespace std;

const int NUMBER_OF_TRIALS = 1;
const int NUMBER_OF_VERTICES = 1000;
const int MAX_VERTEX_VALUE = 1000;

int main()
{
        random_device rd;
        mt19937 rng(rd());
        uniform_int_distribution randomDistribution(-MAX_VERTEX_VALUE,
                                                    MAX_VERTEX_VALUE);

        float distanceDifference = 0;
        for(int i = 0; i < NUMBER_OF_TRIALS; i++) {
                list<Point> inputVertices;
                // fill input vertices with random numbers
                for(int j = 0; j < NUMBER_OF_VERTICES; j++) {
                        inputVertices.emplace_back(randomDistribution(rng),
                                                   randomDistribution(rng));
                }
                // calculate total travel distance
                auto nearestNeighborOrdering = tspNearestNeighbor(
                                               inputVertices);

                auto distanceNearestNeighbor = tspCalculateTotalDistance(
                                                nearestNeighborOrdering);

                auto closestPairOrdering = tspClosestPair(inputVertices);

                auto distanceClosestPair = tspCalculateTotalDistance(
                                                closestPairOrdering);

                distanceDifference += distanceNearestNeighbor
                                     - distanceClosestPair;
        }
        
        if(distanceDifference > 0) {
                cout << "Closest pair heuristics performs better\n";
        } else {
                cout << "Nearest neighbor heuristics performs better\n";
        }
        cout << "By " 
        << distanceDifference / NUMBER_OF_TRIALS / MAX_VERTEX_VALUE
        << " on average\n";

        return 0;
}