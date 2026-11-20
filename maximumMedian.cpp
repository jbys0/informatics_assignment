#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    long long k;
    cin>>n>>k;
    vector<long long> nums(n);
    for(int i=0;i<n;i++){
        cin>>nums[i];
    }
    sort(nums.begin(),nums.end());
    int mid=n/2;
    long long low=nums[mid], high=nums[mid]+k+1;
    while(low+1<high){
        long long m=(low+high)/2;
        long long cnt=0;
        for(int i=mid;i<n;i++){
            if(nums[i]<m){
                cnt+=m-nums[i];
            }
        }
        if(cnt<=k){
            low=m;
        }
        else{
            high=m;
        }
    }
    cout<<low<<endl;
    return 0;
}
