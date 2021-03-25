#include <bits/stdc++.h>
using namespace std;

# define endl "\n"
# define io_boost std::ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
typedef unsigned long long int ulli;
typedef long long int lli;
typedef unsigned int ui;
typedef pair<string, int> word_time;

const int MAXN = 2000005;
int n, m;
lli a[MAXN], b[MAXN];


lli gcd(lli a, lli b){
	if(b == 0) return a;
	return gcd(b, a % b);
}


int main(){
    cin >> n >> m;
    for(int i = 0; i < n; i++) cin >> a[i];
    for(int i = 0; i < m; i++) cin >> b[i];

    if(n == 1){
        for(int i = 0; i < m; i++) cout << a[0] + b[i] << " ";
        cout << endl;
    }
    else{
        lli g = a[1] - a[0];
        for(int i = 2; i < n; i++) g = gcd(g, a[i] - a[0]);

        for(int i = 0; i < m; i++) cout << abs(gcd(g, a[0] + b[i])) << " ";
        cout << endl;
    }


    return 0;
}
