#include <bits/stdc++.h>
using namespace std;

# define endl "\n"
# define io_boost std::ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
typedef unsigned long long int ulli;
typedef long long int lli;
typedef unsigned int ui;

int n;
string s;

int main(){
    cin >> s;
    n = s.size();
    string t = "";
    for(int i = n - 2; i >= 1; i--) t += s[i];
    s = t + s + t;
    t = "";
    for(int i = s.size() - 2; i >= n - 2; i--) t += s[i];
    s+=t;
    t = "";
    int j = s.size() - 2;
    for(int i = 0; i < n - 2; i++){
        t += s[j];
        j--;
    }

    s+=t;
    cout << 4 << endl;
    cout << "R 2" << endl;
    cout << "L " << n - 1 << endl;
    cout << "R " << n - 2 + 1 << endl;
    cout << "R " << j + 2 << endl;
    return 0;
}