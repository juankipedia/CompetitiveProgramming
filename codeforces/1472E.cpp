#include <bits/stdc++.h>
using namespace std;

# define endl "\n"
# define io_boost std::ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
typedef unsigned long long int ulli;
typedef long long int lli;
typedef unsigned int ui;

typedef pair<lli, lli> plli;
typedef pair<lli, pair<lli, int>> person;

# define H(p) p.first
# define W(p) p.second.first
# define IDX(p) p.second.second

const int MAXN = 200000;
int N;
person v[MAXN], a[MAXN];

int st[3 * MAXN];

# define R 2 * si + 2
# define L 2 * si + 1
# define MID ss + (se - ss) / 2
# define NEUTRAL -1

int join(int lval, int rval){
    if(lval == NEUTRAL) return rval;
    if(rval == NEUTRAL) return lval;
    if(W(a[lval]) < W(a[rval])) return lval;
    else return rval;
}

void build(int ss, int se, int si){
    if(ss == se){
        st[si] = ss;
        return;
    }
    build(ss, MID, L);
    build(MID + 1, se, R);
    st[si] = join(st[L], st[R]); 
}


int get(int ss, int se, int si, int qs, int qe){
    if(qs <= ss && se <= qe) return st[si];
    if(ss > qe || se < qs) return NEUTRAL;
    return join(get(ss, MID, L, qs, qe), get(MID + 1, se, R, qs, qe));   
}

int t;

int main(){
    cin >> t;
    while(t--){
        cin >> N;
        for(int i = 0; i < N; i++){
            cin >> H(v[i]) >> W(v[i]);
            IDX(v[i]) = IDX(a[i]) = i;
            a[i] = v[i];
        }
        int ans[N];
        sort(a, a + N, [](auto &p1, auto &p2){ return H(p1) > H(p2);});
        build(0, N - 1, 0);

        //cout << " ======== " << endl;
        //for(int i = 0; i < N; i++) cout << H(a[i]) << " " << W(a[i]) << endl;
        //cout << " ======== " << endl;
        for(int i = 0; i < N; i++){
            int pos = upper_bound(a, a + N, v[i], [](auto &p1, auto &p2){ return H(p1) > H(p2);}) - a;
            if(pos == N) ans[i] = -1;
            else{
                
                pos = get(0, N - 1, 0, pos, N - 1); 
                //cout << pos << " " << i << endl;
                if(W(a[pos]) >= W(v[i])) ans[i] = -1;
                else ans[i] = IDX(a[pos]) + 1;
            }
        }

        for(int i = 0; i < N; i++) a[i] = {W(v[i]), {H(v[i]), i}};
        sort(a, a + N, [](auto &p1, auto &p2){ return H(p1) > H(p2);});
        build(0, N - 1, 0);

         for(int i = 0; i < N; i++){
            if(ans[i] != -1) continue;
            int pos = upper_bound(a, a + N, v[i], [](auto &p1, auto &p2){ return H(p1) > H(p2);}) - a;
            if(pos == N) ans[i] = -1;
            else{
                pos = get(0, N - 1, 0, pos, N - 1); 
                if(W(a[pos]) >= W(v[i])) ans[i] = -1;
                else ans[i] = IDX(a[pos]) + 1;
            }
        }


        for(int i = 0; i < N; i++) cout << ans[i] << " ";
        cout << endl;
    }
    
    return 0;
}