#include <bits/stdc++.h>
using namespace std;
int main(){
    int n,x;
    cin>>n>>x;
    vector<pair<long long,long long>>num(n+1);
    for(int i=1;i<n+1;i++){
        cin>>num[i].first;
        num[i].second=i;
    }
    sort(num.begin()+1, num.end());
    for(int i=1;i<n;i++){
        int l=i+1;
        int r=n;
        while(l<r){
            if(num[i].first+num[l].first+num[r].first<x){
                l++;
            }
            else if(num[i].first+num[l].first+num[r].first>x){
                r--;
            }
            else{
                cout<<num[i].second<<" "<<num[l].second<<" "<<num[r].second;
                return 0;
            }
        }
    }
cout<<"IMPOSSIBLE";
return 0;  
}