# include <bits/stdc++.h>
using namespace std;

# define endl "\n"
# define io_boost std::ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
typedef unsigned long long int ulli;
typedef long long int lli;
typedef unsigned int ui;

long double N;

struct Pt{
    long double x, y;
};

Pt P1, P2, O, OP1;

long double PI = 3.14159265359;

int main(){
    cin >> N;
    cin >> P1.x >> P1.y >> P2.x >> P2.y;
    O = {(P1.x + P2.x) / 2, (P1.y + P2.y) / 2};
    OP1 = {P1.x - O.x, P1.y - O.y};
    long double r = sqrt((P1.x - P2.x) * (P1.x - P2.x) + (P1.y - P2.y) * (P1.y - P2.y)) / 2;
    long double beta = std::arg(complex<long double>(OP1.x, OP1.y));
    long double theta  = beta + 2 * PI / N;
    cout << std::fixed << std::setprecision(10) << r * cos(theta) + O.x << " " << r * sin(theta) + O.y << endl;
    return 0;
}