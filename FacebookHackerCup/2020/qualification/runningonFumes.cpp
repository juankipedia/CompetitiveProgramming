#include <bits/stdc++.h>
using namespace std;

# define endl "\n"
# define io_boost std::ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
typedef unsigned long long int ulli;
typedef long long int lli;
typedef unsigned int ui;
const lli INF = 1e15 + 1;

int T, N, M, ti;
lli C[1000000], m[1000000], st[3000000];

lli build(int ss, int se, int si){
    if(ss == se){
        st[si] = m[ss];
        return st[si];
    }
    int mid = ss + (se - ss) / 2;
    st[si] = min(build(ss, mid, 2 * si +  1), build(mid + 1, se, 2 * si +  2));
    return st[si];
}

lli min_cost(int ss, int se, int si, int qs, int qe){
    if(qe < ss || se < qs) return INF;
    if(qs <= ss && se <= qe) return st[si];
    int mid = ss + (se - ss) / 2;
    return min(min_cost(ss, mid, 2 * si + 1, qs, qe), min_cost(mid + 1, se, 2 * si + 2, qs, qe));
}

void update(int ss, int se, int index, lli value, int si){       
    if (ss == se){
        m[index] = value; 
        st[si] = value; 
    } 
    else { 
        int mid = ss + (se - ss) / 2;
        if (index >= ss && index <= mid) 
            update(ss, mid, index, value, 2 * si + 1); 
        else
            update(mid + 1, se, index, value, 2 * si + 2); 
        st[si] = min(st[2 * si + 1], st[2 * si + 2]); 
    } 
    return; 
} 

int main(){
    io_boost;
    cin >> T;
    for(ti = 1; ti <= T; ti++){
        cin >> N >> M;
        for(int i = 0; i < N; i++){
            cin >> C[i];
            m[i] = INF;
        }
        cout << "Case #" << ti << ": ";
        m[N - 1] = 0;
        C[0] = 0;
        for(int i = N - 2; i >= N - (M + 1); i--)
            if(C[i] != 0)
                m[i] = C[i];
        
        build(0, N - 1, 0);
        bool f = false;
        for(int i = N - (M + 2); i >= 0; i--){
            if(i == 0) f = true;
            if(C[i] != 0 || i == 0){
                lli r  = min_cost(0, N - 1, 0, i + 1, i + M);
                if(r != INF) update(0, N - 1, i, C[i] + r, 0);
            }
        }
        if(!f) m[0] = 0;
        if(m[0] != INF) cout << m[0] << endl;
        else cout << -1 << endl;
    }
    return 0;
}