#include <bits/stdc++.h>
using namespace std;

# define endl "\n"
# define io_boost std::ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
typedef unsigned long long int ulli;
typedef long long int lli;
typedef unsigned int ui;
const int INF = numeric_limits<int>::max();
int t, n;
string s;

int main(){
    io_boost;
    cin >> t;
    while(t--){
        cin >> s;
        int m[10] = {0};
        n = s.size();
        for(int i = 0; i < n; i++) m[s[i] - '0']++;
        int mini = INF;
        for(int i = 0; i < 10; i++){
            int ps = 0;
            for(int j = 0; j < 10; j++)
                if(i != j) ps += m[j];
            mini = min(mini, ps);
        }
        for(int i = 0; i < 10; i++){
            for(int j = 0; j < 10; j++){
                if(i != j){
                    int k = 0, ps = 0;
                    while(s[k] - '0' != i && k < n) k++;
                    bool f = true;
                    ps = k;
                    string r = " ";
                    r[0] = s[k];
                    k ++;
                    for(; k < n; k++){
                        if(f){
                            if(s[k] - '0' != j) ps++;
                            else{ f = !f; r += s[k]; }
                        }
                        else{
                            if(s[k] - '0' != i) ps++;
                            else{ f = !f; r += s[k]; }
                        }
                    }
                    if(r.size() % 2) ps++;
                    mini = min(mini, ps);
                }
            }
        }

        cout << mini << endl;

    }
    return 0;
}