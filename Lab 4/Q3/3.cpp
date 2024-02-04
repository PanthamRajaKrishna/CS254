#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <vector>
using namespace std;

long long partition(vector<long long>& arr, long long l, long long r);

long long quickSelect(vector<long long>& arr, long long l, long long r, long long K) {
    if (K > 0 && K <= r - l + 1) {
        long long pos = partition(arr, l, r);
        if (pos - l == K - 1)
            return arr[pos];
        if (pos - l > K - 1)
            return quickSelect(arr, l, pos - 1, K);
        return quickSelect(arr, pos + 1, r, K - pos + l - 1);
    }
    return INT64_MIN;
}

void swap(long long& a, long long& b) {
    long long temp = a;
    a = b;
    b = temp;
}

long long partition(vector<long long>& arr, long long l, long long r) {
    long long randomIndex = l + rand() % (r - l + 1);
    swap(arr[randomIndex], arr[r]);

    long long x = arr[r], i = l;
    for (long long j = l; j <= r - 1; j++) {
        if (arr[j] >= x) {
            swap(arr[i], arr[j]);
            i++;
        }
    }
    swap(arr[i], arr[r]);
    return i;
}

int main() {
    freopen("input_Q3.txt", "r", stdin);
    freopen("output_Q3.txt", "w", stdout);
    int t;
    cin >> t;
    while (t--) {
        long long n, K;
        cin >> n >> K;
        vector<long long> arr(n);
        for (long long i = 0; i < n; i++) cin >> arr[i];
        cout << quickSelect(arr, 0, n - 1, K)<<'\n';
    }
    return 0;
}
