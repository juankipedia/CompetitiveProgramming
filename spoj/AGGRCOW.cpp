#include <bits/stdc++.h>
using namespace std;

# define endl "\n"
# define io_boost std::ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
typedef unsigned long long int ulli;
typedef long long int lli;
typedef unsigned int ui;
typedef vector<int> vector_i;
typedef vector<long long int> vector_lli;
typedef vector<unsigned int> vector_ui;
typedef vector<unsigned long long int> vector_ulli;
typedef set<int> set_i;
typedef set<long long int> set_lli;
typedef set<unsigned int> set_ui;
typedef set<unsigned long long int> set_ulli;
typedef unordered_set<int> u_set_i;
typedef unordered_set<long long int> u_set_lli;
typedef unordered_set<unsigned int> u_set_ui;
typedef unordered_set<unsigned long long int> u_set_ulli;

int N, C, T;
lli x[100000];

lli bs(lli lo, lli hi){
    lli mid, f;
    int c;
    while(lo < hi){
        mid = lo + (hi - lo + 1)/2;
        f = x[0];
        c = 1;
        for(int i = 1; i < N; i++){
            if(c == C) break;
            if(x[i] - f >= mid){
                c++; f = x[i];
            }
        }
        if(c < C)
            hi = mid - 1;
        else
            lo = mid;
    }
    return lo;
}

int main() {
    cin >> T;
    while(T--){
        cin >> N >> C;
        for(int i = 0; i < N; i++) cin >> x[i];
        sort(x, x + N);
        cout << bs(x[1] - x[0], x[N - 1] - x[0]) << endl;
    }
    return 0;
}