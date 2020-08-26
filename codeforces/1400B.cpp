#include <bits/stdc++.h>
using namespace std;

# define endl "\n"
# define io_boost std::ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
typedef unsigned long long int ulli;
typedef long long int lli;
typedef unsigned int ui;

int t;

lli p, f, s, w, cnts, cntw;
 
int fn(int j, int v){
	if(j * s >= f) return f / s;
	lli lf = f - (j * s);
	return min(lf / w, (lli)v)  + j;
}
 
int solve(){
    lli maxi = 0;
    for(int i = 0; i <= cnts; i++){
        if(i * s > p) break;
        lli lp = p - s * i;
        lli k = min(lp / w, cntw);
        maxi = max(maxi, i + k + fn(cnts - i, cntw - k));
    }
    return maxi;
} 

int main(){
	int t;
    cin >> t;
	while(t--){
		cin >> p >> f >> cnts >> cntw >> s >> w;
		if(s > w){ swap(s, w); swap(cnts, cntw);}
		cout << solve() << endl;
	}
}