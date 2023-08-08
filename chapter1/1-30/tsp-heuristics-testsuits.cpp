#include <gtest/gtest.h>
#include "tsp-heuristics.hpp"
#include <vector>

using namespace std;

TEST(TSPHeuristics, NearestNeighbor)
{
        list<Point> inputPoints;
        vector<Point> inputPointsVector;
	inputPointsVector.push_back({0, 0});
	inputPointsVector.push_back({-21, 0});
	inputPointsVector.push_back({-5, 0});
	inputPointsVector.push_back({-1, 0});
	inputPointsVector.push_back({1, 0});
	inputPointsVector.push_back({3, 0});
	inputPointsVector.push_back({11, 0});

        std::copy(inputPointsVector.begin(), inputPointsVector.end(),
                  std::back_inserter(inputPoints));

	auto pointOrdering = tspNearestNeighbor(inputPoints);

        auto it = pointOrdering.begin();
        EXPECT_EQ(*it, inputPointsVector[0]);
        it = next(it);
        EXPECT_EQ(*it, inputPointsVector[3]);
        it = next(it);
        EXPECT_EQ(*it, inputPointsVector[4]);
        it = next(it);
        EXPECT_EQ(*it, inputPointsVector[5]);
        it = next(it);
        EXPECT_EQ(*it, inputPointsVector[2]);
        it = next(it);
        EXPECT_EQ(*it, inputPointsVector[1]);
        it = next(it);
        EXPECT_EQ(*it, inputPointsVector[6]);
        it = next(it);
        EXPECT_EQ(*it, inputPointsVector[0]);
}

TEST(TSPHeuristics, ClosestPair)
{
        list<Point> inputPoints;
        vector<Point> inputPointsVector;
	inputPointsVector.push_back({0, 0});
	inputPointsVector.push_back({-21, 0});
	inputPointsVector.push_back({-5, 0});
	inputPointsVector.push_back({-1, 0});
	inputPointsVector.push_back({1, 0});
	inputPointsVector.push_back({3, 0});
	inputPointsVector.push_back({11, 0});

        std::copy(inputPointsVector.begin(), inputPointsVector.end(),
                  std::back_inserter(inputPoints));

	auto pointOrdering = tspClosestPair(inputPoints);

        auto it = pointOrdering.begin();
        EXPECT_EQ(*it, inputPointsVector[1]);
        it = next(it);
        EXPECT_EQ(*it, inputPointsVector[2]);
        it = next(it);
        EXPECT_EQ(*it, inputPointsVector[3]);
        it = next(it);
        EXPECT_EQ(*it, inputPointsVector[0]);
        it = next(it);
        EXPECT_EQ(*it, inputPointsVector[4]);
        it = next(it);
        EXPECT_EQ(*it, inputPointsVector[5]);
        it = next(it);
        EXPECT_EQ(*it, inputPointsVector[6]);
        it = next(it);
        EXPECT_EQ(*it, inputPointsVector[1]);
}

TEST(TSPHeuristics, TotalDistance)
{
        list<Point> inputPoints;
        vector<Point> inputPointsVector;
	inputPointsVector.push_back({-21, 0});
	inputPointsVector.push_back({-5, 0});
	inputPointsVector.push_back({-1, 0});
	inputPointsVector.push_back({0, 0});
	inputPointsVector.push_back({1, 0});
	inputPointsVector.push_back({3, 0});
	inputPointsVector.push_back({11, 0});
	inputPointsVector.push_back({-21, 0});

        std::copy(inputPointsVector.begin(), inputPointsVector.end(),
                  std::back_inserter(inputPoints));

        EXPECT_EQ(tspCalculateTotalDistance(inputPoints), 64);
}