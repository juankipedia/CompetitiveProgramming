#include <bits/stdc++.h>
using namespace std;

# define endl "\n"
# define io_boost std::ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
typedef unsigned long long int ulli;
typedef long long int lli;
typedef unsigned int ui;



struct  Elephant{
    lli h, iq;
    int idx;
    Elephant(lli h, lli iq, int idx) : h(h), iq(iq), idx(idx){}
    Elephant(){}
};

const lli oo = numeric_limits<lli>::max();
const int MAXN = 1005;
int N, m[MAXN];
Elephant a[MAXN];

int dp(int last){
    if(m[last] != -1) return m[last];
    m[last] = 0;
    for(int i = last + 1; i < N; i++)
        if(a[i].h > a[last].h && a[i].iq < a[last].iq)
            m[last] = max(1 + dp(i), m[last]);
    
    return m[last];
}

void print_dp(int last){
    for(int i = last + 1; i < N; i++){
        if(a[i].h > a[last].h && a[i].iq < a[last].iq && m[last] - 1 == m[i]){
            cout << a[i].idx << endl;
            print_dp(i);
            break;
        }
    }
}

int main(){
    io_boost;
    memset(m, -1, sizeof(m));
    N = 1;
    a[0] = Elephant(0, oo, 0);
    while(cin >> a[N].h >> a[N].iq) a[N].idx = N, N++;
    sort(a, a + N, [](const Elephant &e1, const Elephant &e2){ return e1.h < e2.h; });
    cout << dp(0) << endl;
    print_dp(0);
    return 0;
}