#include <bits/stdc++.h>
using namespace std;

int main(){
    string s;
    cin>>s;
    map<char, char> cls={
        {'}','{'},
        {')','('},
        {']','['}
    };
    stack<char>stk;
    for(char b:s){
        if(b=='(' ||b=='{' ||b=='['){
            stk.push(b);
        }
        else if(b==')' ||b=='}' ||b==']'){
            if(stk.empty()){
                cout<<"false";
                return 0;
            }
            if(stk.top()==cls[b]){
                stk.pop();
            }
            else{
                cout<<"false";
                return 0;
            }
        }
    }
    if(stk.empty()){
        cout<<"true";
    }
    else cout<<"false";
    return 0;
}