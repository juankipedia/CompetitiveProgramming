#include <bits/stdc++.h>
using namespace std;

# define endl "\n"
# define io_boost std::ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
typedef unsigned long long int ulli;
typedef long long int lli;
typedef unsigned int ui;
typedef vector<int> vector_i;
typedef vector<long long int> vector_lli;
typedef vector<unsigned int> vector_ui;
typedef vector<unsigned long long int> vector_ulli;
typedef set<int> set_i;
typedef set<long long int> set_lli;
typedef set<unsigned int> set_ui;
typedef set<unsigned long long int> set_ulli;
typedef unordered_set<int> u_set_i;
typedef unordered_set<long long int> u_set_lli;
typedef unordered_set<unsigned int> u_set_ui;
typedef unordered_set<unsigned long long int> u_set_ulli;

int t, n, pi, p[100000], r[100000], c[100000], m[100001], maxc, u;

int main() {
    io_boost;
    cin >> t;
    while(t--){
        cin >> n;
        for(int i = 0; i < n; i ++){
            cin >> pi;
            p[pi - 1] = i; 
            r[i] = i;
            c[i] = 1;
            m[i + 1] = 0;
        }
        m[1] = n;
        maxc = 1;
        u = n;
        bool f = true;
        for(int i = 0; i < n; i++){
            pi = p[i];
            if(c[pi] != maxc){
                f = false;
                //cout << "W" << endl;
                break;
            }
            else{
                r[pi] ++;
                //cout << i << " " << r[pi] << " " << u << endl;
                if(r[pi] >= u){
                    r[pi] = -1;
                    u--;
                    //cout << u << endl;
                    while(r[u - 1] >= u && c[u - 1] == 0) r[u - 1] = -1, u--;
                    //for(int i = 0; i < n; i++) cout << r[i] << " ";
                    //cout << endl;   
                }
                m[maxc]--;
                if(r[pi] != -1){
                    c[r[pi]] += c[pi];
                    maxc++;
                    m[maxc]++;
                }
                else{
                    if(m[maxc] == 0){
                        maxc--;
                        if(m[maxc] == 0){f = true; break;}
                    }
                }
                c[pi] = 0;
            }
        }
        if(f) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
    return 0;
}