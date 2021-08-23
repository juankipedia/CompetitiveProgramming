# include <bits/stdc++.h>
using namespace std;
/*************************************************************************************/
# define endl "\n"
# define io_boost std::ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
typedef unsigned long long int ulli;
typedef long long int lli;
/*************************************JUANKIPEDIA*************************************/

int t, N, m[26];
string T;
vector<int> order;

void find_order(){
    bool m2[26] = {false};
    for(int i = N - 1; i >= 0; i--)
        if(!m2[T[i] - 'a'])
            m2[T[i] - 'a'] = true,
            order.push_back(T[i] - 'a');
    std::reverse(order.begin(), order.end());
}

bool check(int p){
    int len = p + 1, ans = 0;
    for(int c : order)
        len -= m[c],
        ans += len;
    return (N - p - 1) == ans;
}

int main(){
    cin >> t;
    while(t--){
        order.clear();
        cin >> T;
        N = T.size();
        find_order();
        int p = -1;
        for(int i = 0; i < 26; i++) m[i] = 0;
        for(int i = 0; i < N; i++){
            m[T[i] - 'a']++;
            if(check(i)){
                p = i;
                break;
            }
        }
        if(p == -1) cout << -1 << endl;
        else{
            string pre = T.substr(0, p + 1);
            string tt = pre;
            for(int c : order){
                string s = "";
                for(char cc : pre)
                    if((cc - 'a') == c) continue;
                    else s += cc;
                pre = s;
                tt += s;
            }
            if(tt != T){
                cout << -1 << endl;
                continue;
            }
            cout << T.substr(0, p + 1) << " ";
            for(int c : order) cout << char(c + 'a');
            cout << endl;
        }
    }
    return 0;
}