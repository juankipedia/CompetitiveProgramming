#include <bits/stdc++.h>
using namespace std;

int main() {
    char c;
    bool f = false;
    long long unsigned int d = 0;
    while(scanf("%c", &c) and c != '\n'){if(c != '9') f = true; d++;}
    if(f) cout << d << endl;
    else cout << d + 1 << endl;
    return 0;
}