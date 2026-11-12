#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long n, k;
    if (!(cin >> n >> k)) return 0;

    vector<long long> num(n);
    for (int i = 0; i < n; i++) {
        cin >> num[i];
    }

    sort(num.begin(), num.end());

    vector<int> max_case(n, 0);
    int rptr = 0;
    for (int i = 0; i < n; i++) {
        while (rptr < n && num[rptr] - num[i] <= k) {
            rptr++;
        }
        max_case[i] = rptr - i;
    }

    vector<int> max_from_right(n + 1, 0);
    for (int i = n - 1; i >= 0; i--) {
        max_from_right[i] = max(max_from_right[i + 1], max_case[i]);
    }

    int mx = 0;
    for (int i = 0; i < n; i++) {
        int cur = max_case[i] + max_from_right[i + max_case[i]];
        mx = max(mx, cur);
    }

    cout << mx << "\n";
    return 0;
}
