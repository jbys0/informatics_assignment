#include <bits/stdc++.h>
using namespace std;

stack<int> in, out;
void push(int x) {
    in.push(x);
}
int peek() {
    if (out.empty()) {
        while (!in.empty()) {
            out.push(in.top());
            in.pop();
        }
    }
    return out.top();
}
int pop() {
    int val = peek();
    out.pop();
    return val;
}
bool empty() {
    return in.empty() && out.empty();
}
int main() {
    push(1);
    push(2);
    cout << peek() << "\n";
    cout << pop() << "\n";
    cout << empty() << "\n";
    return 0;
}
