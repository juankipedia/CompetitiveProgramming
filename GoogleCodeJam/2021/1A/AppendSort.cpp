# include <bits/stdc++.h>
using namespace std;

# define endl "\n"
# define io_boost std::ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
typedef unsigned long long int ulli;
typedef long long int lli;
typedef unsigned int ui;

int t, N;
string X[105];

bool lq(string &n1, string &n2){
    if(n1.size() < n2.size()) return true;
    if(n1.size() > n2.size()) return false;
    for(int i = 0; i < n1.size(); i++)
        if(n1[i] < n2[i]) return true;
        else if(n1[i] > n2[i]) return false;
    return true;
}

int main(){
    io_boost;
    cin >> t;
    for(int ti = 1; ti <= t; ti++){
        cin >> N;
        for(int i = 0; i < N; i++) cin >> X[i];
        int ans = 0;
        for(int i = 1; i < N; i++){
            if(lq(X[i], X[i - 1]) && X[i - 1].size() == X[i].size()){
                ans++;
                X[i] += '0';
            }
            else if(lq(X[i], X[i - 1])){
                string x = X[i], p = X[i - 1];
                int pos = x.size();
                for(int j = pos; j < p.size(); j++){
                    x += p[j];
                    ans++;
                }
                if(!lq(x, X[i - 1])){
                    for(int j = x.size() - 1; j >= pos; j--){
                        char aux = x[j];
                        x[j] = '0';
                        if(lq(x, p)){
                            x[j] = aux;
                            while(!lq(x, p)){
                                x[j]--;
                            }
                            x[j]++;
                            break;
                        }
                    }
                    X[i] = x;
                    //cout << x << endl;
                }
                else if(x == X[i - 1]){
                    bool c = false;
                    for(int j = x.size() - 1; j >= pos; j--)
                        if(x[j] < '9'){
                            x[j]++;
                            for(int k = j + 1; k < x.size(); k++) x[k] = '0';
                            c = true;
                            break;
                        }
                    if(c) X[i] = x;
                    else{
                        X[i] = X[i] + string(p.size() - pos + 1, '0'); 
                        ans++;
                    }
                    //cout << X[i] << endl;
                }
                else{
                    X[i] = X[i] + string(p.size() - pos + 1, '0');
                    ans++;
                }
            }
        }
        cout << "Case #" << ti << ": " <<  ans << endl;
    }
    return 0;
}