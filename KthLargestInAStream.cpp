#include <bits/stdc++.h>
using namespace std;

int k = 3;
priority_queue<int, vector<int>, greater<int>> pq;
int add(int val) {
    pq.push(val);
    if (pq.size() > k) pq.pop();
    return pq.top();
}
int main() {
    vector<int> nums = {4, 5, 8, 2};
    for (int x : nums) add(x);
    cout << add(3) << "\n";
    cout << add(5) << "\n";
    cout << add(10) << "\n";
    cout << add(9) << "\n";
    cout << add(4) << "\n";
    return 0;
}
