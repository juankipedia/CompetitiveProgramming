#include <bits/stdc++.h>
using namespace std;

# define endl "\n"
# define io_boost std::ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
typedef unsigned long long int ulli;
typedef long long int lli;
typedef unsigned int ui;

int t, n;
string a, b, f;

int main(){
    io_boost;
    cin >> t;
    while(t--){
        cin >> n;
        cin >> a >> b;
        f = "";
        for(int i = 0; i < n; i++)
            if(a[i] == '0') f += "1";
            else f += "0";
        reverse(f.begin(), f.end());
        vector<int> op;
        bool first = true; 
        int la = 0, lf = -1;
        int i_a = n - 1, i_f = n - 1;
        for(int i = n - 1; i >= 0; i--){
            if(first){
                if((a[la] != a[i_a] && b[i] != a[i_a]) || (a[la] == a[i_a] && b[i] == a[i_a]))
                    op.push_back(1);
                lf++;
                i_a--;
            }
            else{
                if((f[lf] != f[i_f] && b[i] != f[i_f]) || (f[lf] == f[i_f] && b[i] == f[i_f]))
                    op.push_back(1);
                la++;
                i_f--;
            }
            op.push_back(i + 1);
            first = !first;
        }
        cout << op.size() << " ";
        for(int &o: op) cout << o << " ";
        cout << endl;

    }
    return 0;
}