# include <bits/stdc++.h>
using namespace std;

# define endl "\n"
# define io_boost std::ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
typedef unsigned long long int ulli;
typedef long long int lli;
typedef unsigned int ui;

const int MAXN = 200005;
int N, a[MAXN], b[MAXN];

int main(){
    cin >> N;
    for(int i = 0; i < N; i++) cin >> a[i];
    for(int i = 0; i < N; i++) cin >> b[i];
    multiset<int> s;
    for(int i = 0; i < N; i++) s.insert(b[i]);
    for(int i = 0; i < N; i++){
        int e = 0;
        if(a[i] != 0) e = N - a[i];
        auto it = s.lower_bound(e);
        if(it == s.end()) it = s.begin();
        cout << (*it + a[i]) % N << " ";
        s.erase(it);
    }
    cout << endl;

    return 0;
}