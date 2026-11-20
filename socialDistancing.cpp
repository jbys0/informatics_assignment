#include <bits/stdc++.h>
using namespace std;

int main(){
    freopen("socdist.in","r",stdin);
    freopen("socdist.out","w",stdout);
    int n,m;
    cin>>n>>m;
    vector<pair<long long,long long>> nums(m);
    for(int i=0;i<m;i++){
        cin>>nums[i].first>>nums[i].second;
    }
    sort(nums.begin(), nums.end());
    if(n==1){
        cout<<nums[0].second-nums[0].first+1;
        return 0;
    }
    long long low, high,mx=0;
    low=1;
    high=(nums[m-1].second-nums[0].first)/(n-1);
    while(low<=high){
        long long d = low + (high - low) / 2;
        long long cur = nums[0].first;
        int itrv=0;
        bool cn=true;
        for(int i=1;i<n;i++){
            cur+=d;
            while(itrv<m && cur>nums[itrv].second){
                itrv+=1;
            }
            if(itrv==m){
                cn=false;
                break;
            }
            cur=max(nums[itrv].first,cur);
        }
        if(cn){
            mx=max(d,mx);
            low=d+1;
        }
        else{
            high = d - 1;
        }
    }
    cout<<mx;
    return 0;
}