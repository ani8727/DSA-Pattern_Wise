// 295. Find Median from Data Stream

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class MedianFinder {
    vector<int> nums;   // store all numbers

public:
    MedianFinder() {}

    void addNum(int num) {
        // Insert number in sorted position
        auto it = lower_bound(nums.begin(), nums.end(), num);
        nums.insert(it, num);
    }

    double findMedian() {
        int n = nums.size();

        if (n % 2 == 1)
            return nums[n / 2];
        else
            return (nums[n / 2 - 1] + nums[n / 2]) / 2.0;
    }
};

int main() {
    MedianFinder md;
    vector<double> medians;

    md.addNum(2);
    md.addNum(3);
    medians.push_back(md.findMedian());

    md.addNum(5);
    medians.push_back(md.findMedian());

    md.addNum(10);
    md.addNum(5);
    md.addNum(20);
    medians.push_back(md.findMedian());

    for (double x : medians)
        cout << x << " ";

    return 0;
}
