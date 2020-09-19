#include <bits/stdc++.h>
using namespace std;

# define endl "\n"
# define io_boost std::ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
typedef unsigned long long int ulli;
typedef long long int lli;
typedef unsigned int ui;

int t, n;
string num;

int main(){
    cin >> t;
    while(t--){
        cin >> n;
        cin >> num;
        bool m[n] = {false};
        bool r = true; bool rw = true;
        for(int i = 0; i < n; i++){
            int cnt = 0, p;
            for(int j = 0; j < n; j++){
                if(!m[j]){
                    cnt ++;
                    p = j;
                }
            }

            if(cnt == 1 && (num[p] - '0') % 2){
                rw = true;
                break;
            }
            else if(cnt == 1){
                rw = false;
                break;
            }

            bool mark = false;

            for(int j = 1; j <= n; j++){
                if(j % 2 && r && (num[j - 1] - '0') % 2 == 0 && !m[j - 1]){
                    m[j - 1] = true;
                    mark = true;
                    //cout << j - 1 << " r" << endl;
                    break;
                }
                else if(j % 2 == 0 && !r && (num[j - 1] - '0') % 2 && !m[j - 1]){
                    m[j - 1] = true;
                    mark = true;
                    //cout << j - 1 << " b" << endl;
                    break;
                }
            }

            if(mark){
                r = !r;
                continue; 
            }

            for(int j = 1; j <= n; j++){
                if(j % 2 && r && !m[j - 1]){
                    m[j - 1] = true;
                    //cout << j - 1 << " r" << endl;
                    break;
                }
                else if(j % 2 == 0 && !r && !m[j - 1]){
                    m[j - 1] = true;
                    //cout << j - 1 << " b" << endl;
                    break;
                }
            }

            r = !r;
        }
        if(rw) cout << 1 << endl;
        else cout << 2 << endl;
    }
    return 0;
}