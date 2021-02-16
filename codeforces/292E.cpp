#include <bits/stdc++.h>
using namespace std;

# define endl "\n"
# define io_boost std::ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
typedef unsigned long long int ulli;
typedef long long int lli;
typedef unsigned int ui;

const int MAXN = 100000;
int N;

struct Node{
    int l, r;
};

lli a[MAXN], b[MAXN];
Node sta[3 * MAXN];
bool stb[3 * MAXN];
 
# define R 2 * si + 2
# define L 2 * si + 1
# define MID(l, r) l + (r - l) / 2
# define NEUTRAL 0


void propagate(int ss, int se, int si){
    if(!stb[si]) return;
    if(ss == se) return;
    stb[si] = false;
    
    int mid = MID(sta[si].l, sta[si].r);

    sta[L].l = sta[si].l;
    sta[L].r = mid;

    sta[R].r = sta[si].r;
    sta[R].l = mid + 1;

    stb[L] = stb[R] = true;
}
 
void update(int ss, int se, int si, int qs, int qe, int l, int r){
    propagate(ss, se, si);
    if(ss > qe || se < qs) return;
    if(qs <= ss && se <= qe){
        stb[si] = true;
        int ll = ss - qs, rr = qe - se;
        sta[si].l = l + ll;
        sta[si].r = r - rr;
        propagate(ss, se, si);
        return;
    }
    update(ss, MID(ss, se), L, qs, qe, l, r);
    update(MID(ss, se) + 1, se, R, qs, qe, l, r);
}
 
lli get(int ss, int se, int si, int i){
    propagate(ss, se, si);
    if(ss == se){
        //cout << "SSSSS " << ss << " " << se << endl;
        if(stb[si]) return a[sta[si].l];
        else return b[ss];
    }
    if(i <= MID(ss, se)) return get(ss, MID(ss, se), L, i);
    else return get(MID(ss, se) + 1, se, R, i);
}

int M;

int main(){
    io_boost;
    cin >> N >> M;
    for(int i = 0; i < N; i++) cin >> a[i];
    for(int i = 0; i < N; i++) cin >> b[i];
    for(int i = 0, t, x, y, k; i < M; i++){
        cin >> t;
        if(t == 1){
            cin >> x >> y >> k;
            x--; y--; k--;
            update(0, N - 1, 0, y, y + k, x, x + k);
        }
        else{
            cin >> x;
            x--;
            cout << get(0, N - 1, 0, x) << endl;
        }
    }
    return 0;
}