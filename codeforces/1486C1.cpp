#include <bits/stdc++.h>
using namespace std;

# define endl "\n"
# define io_boost std::ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
typedef unsigned long long int ulli;
typedef long long int lli;
typedef unsigned int ui;

int n, q;

int query(int l, int r){
    int pos = l;
    if(l == r) return pos;
    cout << "? " << l << " " << r << endl;
    cout.flush();
    cin >> pos;
    q++;
    return pos;
}

void ans(int p){
    //if(n == 100000) cout << "! " <<  q << endl;
    //else 
    cout << "! " << p << endl;
}

int main(){
    cin >> n;
    int snd = query(1, n);
    bool left = false;
    if(snd == n) left = true;
    else if(snd != 1){
        int p = query(snd, n);
        if(p != snd) left = true;
    }
    //cout << left << endl;
    if(left){
        int lo = 1, hi = snd, mid;
        while(lo < hi){
            mid = lo + (hi - lo + 1) / 2;
            int p;
            if(lo + 1 == hi){
                p = query(lo, hi);
                if(p == lo) lo = hi;
                break;
            }
            p = query(mid, snd);

            if(p == snd) lo = mid;
            else hi = mid - 1;
        }
        ans(lo);
    }
    else{
        int lo = snd, hi = n, mid;
        while(lo < hi){
            mid = lo + (hi - lo + 1) / 2;
            int p;

            if(lo + 1 == hi){
                p = query(lo, hi);
                if(p == lo) lo = hi;
                break;
            }
            p = query(snd, mid);

            if(p == snd) hi = mid;
            else lo = mid + 1;
        }
        ans(lo);
    }
    return 0;
}