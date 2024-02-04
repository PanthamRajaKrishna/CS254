#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

double findMedianSortedArrays(const vector<long long>& nums1, const vector<long long>& nums2) {
    if (nums1.size() > nums2.size()) {
        return findMedianSortedArrays(nums2, nums1);
    }

    int x = nums1.size();
    int y = nums2.size();

    int low = 0, high = x;

    while (low <= high) {
        int partitionX = (low + high) / 2;
        int partitionY = (x + y + 1) / 2 - partitionX;

        long long maxX = (partitionX == 0) ? INT16_MIN : nums1[partitionX - 1];
        long long minX = (partitionX == x) ? INT16_MAX : nums1[partitionX];

        long long maxY = (partitionY == 0) ? INT16_MIN : nums2[partitionY - 1];
        long long minY = (partitionY == y) ? INT16_MAX : nums2[partitionY];

        if (maxX <= minY && maxY <= minX) {
            if ((x + y) % 2 == 0) {
                return (max(maxX, maxY) + min(minX, minY)) / 2.0;
            } else {
                return max(maxX, maxY);
            }
        } else if (maxX > minY) {
            high = partitionX - 1;
        } else {
            low = partitionX + 1;
        }
    }

    return 0.0;
}

int main() {
    freopen("input_Q2.txt", "r", stdin);
    freopen("output_Q2.txt", "w", stdout);

    int t;
    cin >> t;

    while (t--) {
        long long m, n;
        cin >> m >> n;

        vector<long long> nums1(m);
        vector<long long> nums2(n);

        for (long long i = 0; i < m; i++) {
            cin >> nums1[i];
        }

        for (long long i = 0; i < n; i++) {
            cin >> nums2[i];
        }

        double median = findMedianSortedArrays(nums1, nums2);
        cout << median << endl;
    }

    return 0;
}
