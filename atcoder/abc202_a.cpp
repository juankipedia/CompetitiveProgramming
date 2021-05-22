# include <bits/stdc++.h>
using namespace std;

# define endl "\n"
# define io_boost std::ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
typedef unsigned long long int ulli;
typedef long long int lli;
typedef unsigned int ui;

int a, b, c;

int f(int d){
    if(d == 6) return 1;
    if(d == 1) return 6;
    if(d == 5) return 2;
    if(d == 2) return 5;
    if(d == 4) return 3;
    if(d == 3) return 4;
    return 0;
}

int main(){
    cin >> a >> b >> c;
    a = f(a);
    b = f(b);
    c = f(c);
    cout << a + b + c << endl;
    return 0;
}