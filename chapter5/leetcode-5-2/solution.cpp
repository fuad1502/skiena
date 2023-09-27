#include <algorithm>
#include <iostream>
#include <vector>

using std::cout;
using std::endl;
using std::sort;
using std::vector;

class Solution {
public:
  int countRangeSum(vector<int> &nums, int l, int r, int lower, int upper);
  int countMidRangeSum(vector<int> &nums, int l, int m, int r, int lower,
                       int upper);
  int countRangeSum(vector<int> &nums, int lower, int upper) {
    return countRangeSum(nums, 0, nums.size() - 1, lower, upper);
  }
};

int main(int argc, char *argv[]) {
  Solution sol;
  vector<int> test{-3, 1, 2, -2, 2, -1};
  cout << sol.countRangeSum(test, -3, -1) << endl;
  return 0;
}

int Solution::countRangeSum(vector<int> &nums, int l, int r, int lower,
                            int upper) {
  int count = 0;

  if (l == r) {
    if (nums[l] >= lower && nums[l] <= upper) {
      count = 1;
    } else {
      count = 0;
    }
  } else {
    int m = (l + r) / 2;
    count += countRangeSum(nums, l, m, lower, upper);
    count += countRangeSum(nums, m + 1, r, lower, upper);
    count += countMidRangeSum(nums, l, m, r, lower, upper);
  }

  return count;
}

int Solution::countMidRangeSum(vector<int> &nums, int l, int m, int r,
                               int lower, int upper) {
  vector<int> midRightSums;
  long sum = 0;
  for (int i = m + 1; i <= r; i++) {
    sum += nums[i];
    midRightSums.push_back(sum);
  }

  int countCombined = 0;
  sum = 0;
  sort(midRightSums.begin(), midRightSums.end());
  for (int i = m; i >= l; i--) {
    sum += nums[i];
    auto itl =
        std::lower_bound(midRightSums.begin(), midRightSums.end(), lower - sum);
    auto itu =
        std::upper_bound(midRightSums.begin(), midRightSums.end(), upper - sum);
    if (std::distance(itl, itu) > 0) {
      countCombined += std::distance(itl, itu);
    }
  }

  return countCombined;
}
