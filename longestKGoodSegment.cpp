#include <bits/stdc++.h>
using namespace std;

int cnt[1000005];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, k;
    if (!(cin >> n >> k)) return 0;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
        int l = 0, r = 0;
    int max_len = 0;
    int ans_l = 1, ans_r = 1;
    int unique_count = 0;
        while (r < n) {
            if (cnt[a[r]] == 0) {
                unique_count++;
            }
            cnt[a[r]]++;
        while (unique_count > k) {
            cnt[a[l]]--;
            if (cnt[a[l]] == 0) {
                unique_count--;
            }
            l++;
        }
        int current_len = r - l + 1;
        if (current_len > max_len) {
            max_len = current_len;
            ans_l = l + 1; 
            ans_r = r + 1;
        }
        r++;
    }
    cout << ans_l << " " << ans_r << "\n";
    return 0;
}
