# include <bits/stdc++.h>
using namespace std;

# define endl "\n"
# define io_boost std::ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
typedef unsigned long long int ulli;
typedef long long int lli;

long double A, B;

int main(){
    cin >> A >> B;
    cout << std::fixed << setprecision(7) << (A - B) / 3 + B << endl;
    return 0;
}