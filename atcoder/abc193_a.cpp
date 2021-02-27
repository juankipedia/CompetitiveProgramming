#include <bits/stdc++.h>
using namespace std;

# define endl "\n"
# define io_boost std::ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
typedef unsigned long long int ulli;
typedef long long int lli;
typedef unsigned int ui;

long double A, B;

int main(){
    cin >> A >> B;
    long double c = 100;
    cout << std::fixed << c - (100 * B / A) << endl;
    return 0;
}