#include <bits/stdc++.h>
using namespace std;

bool pal(string s, int l, int r,bool del){
    if(l==r||r<l) {
        return true;
    }
     if(s[l]==s[r]){
        return pal(s,l+1,r-1,del);
    }
    if(!del ){
        del=true;
        return pal(s,l,r-1,del)||pal(s,l+1,r,del);
    }
    else return false;
}

int main(){
    string s;
    bool del=false;
    cin>>s;
    int l=0,r=s.size()-1;
    bool ans=pal(s, l,r,del);
    cout<<ans;
    return 0;
}