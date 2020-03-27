# include <bits/stdc++.h>

using namespace std;
const int INF = std::numeric_limits<int>::max();
const int MAXN = 1000;

long long int n, k1, k2, a[MAXN], b[MAXN], diff[MAXN], mi;

int main(){
    cin >> n >> k1 >> k2;
    for(int i = 0; i < n; i++) cin >> a[i];
    for(int i = 0; i < n; i++){
        cin >> b[i];
        diff[i] = abs(a[i] - b[i]);
    }
    for(int i = 0; i < (k1 + k2); i++){
        mi = 0;
        for(int i = 0; i < n; i++)
            if(diff[i] > diff[mi]) mi = i;
        if(diff[mi] == 0) diff[mi] = 1;
        else diff[mi]--;
    }
    long long int s = 0;
    for(int i = 0; i < n; i++) s += diff[i] * diff[i];
 
    cout << s << endl;
 
    return 0;
}