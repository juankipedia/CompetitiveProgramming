#include <bits/stdc++.h>
using namespace std;

# define endl "\n"
# define io_boost std::ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
typedef unsigned long long int ulli;
typedef long long int lli;
typedef unsigned int ui;

const lli oo = numeric_limits<lli>::max();
const int MAXN = 2000000;
int N;
lli stl[3 * MAXN], stu[3 * MAXN];
 
# define R 2 * si + 2
# define L 2 * si + 1
# define MID ss + (se - ss) / 2
# define NEUTRAL 0

void merge(int sc, int sp){
    stl[sc] = min(stl[sc], stl[sp]);
    stl[sc] = max(stl[sc], stu[sp]);
    stu[sc] = max(stu[sc], stu[sp]);
    stu[sc] = min(stu[sc], stl[sp]);
}

void propagate(int ss, int se, int si){
    if(ss == se) return;
    merge(L, si);
    merge(R, si);
    stl[si] = oo; 
    stu[si] = 0;
}
 
void update(int ss, int se, int si, int qs, int qe, lli val, bool in){
    propagate(ss, se, si);
    if(ss > qe || se < qs) return;
    if(qs <= ss && se <= qe){
        if(in){
            stl[si] = max(stl[si], val);
            stu[si] = max(stu[si], val);
        }
        else{
            stl[si] = min(stl[si], val);
            stu[si] = min(stu[si], val);
        }
        propagate(ss, se, si);
        return;
    }
    update(ss, MID, L, qs, qe, val, in);
    update(MID + 1, se, R, qs, qe, val, in);
}

void get(int ss, int se, int si){
    propagate(ss, se, si);
    if(ss == se){
        cout << min(stl[si], stu[si]) << endl;
        return;
    }
    get(ss, MID, L);
    get(MID + 1, se, R);
}

int main(){
    io_boost;
    int k, t, l , r;
    lli val;
    for(int i = 0; i < 3 * MAXN; i++) stl[i] = oo;
    cin >> N >> k;
    for(int i = 0; i < k; i++){
        cin >> t >> l >> r >> val;
        update(0, N - 1, 0, l, r, val, t == 1 ? true : false);
    }
    get(0, N - 1, 0);
    return 0;
}