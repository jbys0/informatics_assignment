#include <bits/stdc++.h>
using namespace std;

int main(){
    int n,a,b;
    long long ans=-1e18,s=0;
    cin>>n>>a>>b;
    vector<int>num(n);
    vector<long long>sum(n+1);
    deque<int>q;
    for(int i=0;i<n;i++){
        cin>>num[i];
        s+=num[i];
        sum[i+1]=s;
    }
    for(int r=a;r<=n;r++){
        while(!q.empty()&&q.front()<r-b){
            q.pop_front();
        }
        while(!q.empty()&&sum[q.back()]>=sum[r-a]){
            q.pop_back();
        }
        q.push_back(r-a);
        ans=max(ans,sum[r]-sum[q.front()]);
    }
    cout<<ans<<"\n";
    return 0;
}