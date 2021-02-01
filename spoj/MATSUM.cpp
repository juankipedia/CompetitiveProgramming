#include <bits/stdc++.h>
using namespace std;

# define endl "\n"
# define io_boost std::ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
typedef unsigned long long int ulli;
typedef long long int lli;
typedef unsigned int ui;

struct FenwickTree2D {
    vector<vector<lli>> bit;
    int n, m;

    FenwickTree2D(int N){
        n = m = N;
        bit.assign(N, vector<lli>(N, 0));
    }

    int sum(int x, int y) {
        lli ret = 0;
        for(int i = x; i >= 0; i = (i & (i + 1)) - 1)
            for(int j = y; j >= 0; j = (j & (j + 1)) - 1)
                ret += bit[i][j];
        return ret;
    }

    void add(int x, int y, lli delta) {
        for (int i = x; i < n; i = i | (i + 1))
            for (int j = y; j < m; j = j | (j + 1))
                bit[i][j] += delta;
    }
};

int t, N;

int main(){
    io_boost;
    cin >> t;
    while(t--){
        cin >> N;
        FenwickTree2D tree(N + 1);
        vector<vector<lli>> m(N + 1, vector<lli>(N + 1, 0));
        string q = "";
        int x1, y1, x2, y2;
        lli num;
        while(cin >> q && q != "END"){
            if(q == "SET"){
                cin >> x1 >> y1 >> num;
                x1++; y1++;
                tree.add(x1, y1, -m[x1][y1]);
                m[x1][y1] = num;
                tree.add(x1, y1, m[x1][y1]);
            }
            else{
                cin >> x1 >> y1 >> x2 >> y2;
                x1++; y1++; x2++; y2++;
                //cout << tree.sum(x2, y2) << " " << tree.sum(x1, y2) << " " << tree.sum(x2, y1) << " " << tree.sum(x1, y1) << " /*  */" << endl;
                cout << tree.sum(x2, y2) - tree.sum(x1 - 1, y2) - 
                                    tree.sum(x2, y1 - 1) + tree.sum(x1 - 1, y1 - 1) << endl;
            }
        }
        
    }
    return 0;
}