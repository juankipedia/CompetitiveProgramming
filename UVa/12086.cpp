#include <bits/stdc++.h>
using namespace std;

# define endl "\n"
# define io_boost std::ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
typedef unsigned long long int ulli;
typedef long long int lli;
typedef unsigned int ui;

struct FenwickTree{
    vector<lli> bit;
    int N;
    FenwickTree(lli a[], int n){
        N = n;
        bit.assign(N, 0);
        for(int i = 0; i < N; i++)
            add(a[i], i);

    }

    lli sum(int r){
        lli ret = 0;
        for(; r >= 0; r = (r & (r + 1)) - 1)
            ret += bit[r];
        return ret;
    }

    lli sum(int l, int r){
        return sum(r) - sum(l - 1);
    }

    void add(lli val, int i){
        for(; i < N; i = i | (i + 1))
            bit[i] += val;
    }
};

const int MAXN = 2e5 + 5;
lli A[MAXN], a[MAXN];
int N;

int main(){
    io_boost;
    bool f = true;
    int ti = 1;
    while(cin >> N && N){
        if(f) f = false;
        else cout << endl;
        for(int i = 0; i < N; i ++) cin >> A[i], a[i] = A[i];
        FenwickTree tree(A, N);
        string action = "";
        int l, r;
        cout << "Case " << ti << ":" << endl;
        while(cin >> action && action != "END"){
            cin >> l >> r;
            l--;
            if(action == "M"){
                r--;
                cout << tree.sum(l, r) << endl;
            }
            else{
                tree.add(-a[l] + r, l);
                a[l] = r;
            }
        }
        ti++;
    }
    
    return 0;
}