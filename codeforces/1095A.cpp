#include <bits/stdc++.h>
using namespace std;

typedef long long unsigned int ulli;
typedef long long int lli;
typedef unsigned int ui;

int main() {
    string s, r = "";
    int n;
    cin >> n;
    cin >> s;
    int j = 1;
    for (int i = 0; i < n;){
        r += s[i];
        for (int k = 0; k < j; ++k){
            i++;
        }
        j++;
    }

    cout << r << endl;
    return 0;
}