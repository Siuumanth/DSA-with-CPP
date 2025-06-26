#include <iostream>
#include <vector>
using namespace std;

vector<int> vec = {2, 4, 6, 5};  // n = 4

int sum(int low, int high) {
    if (low == high) return vec[low];

    int mid = (low + high) / 2;
    return sum(low, mid) + sum(mid + 1, high);
}

int main() {
    int n = vec.size();
    cout << sum(0, n - 1) << endl;
    return 0;
}