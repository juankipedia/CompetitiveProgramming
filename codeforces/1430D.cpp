#include <bits/stdc++.h>
using namespace std;

# define endl "\n"
# define io_boost std::ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
typedef unsigned long long int ulli;
typedef long long int lli;
typedef unsigned int ui;

int t, N;
string s;
int memo[200000];

int main(){
    io_boost;
    cin >> t;
    while(t--){
        cin >> N;
        cin >> s;
        int in[N];
        for(int i = 0; i < N; i++) in[i] = 1;
        
        vector<pair<int, int>> pl;
        for(int i = 1; i < N;){
            if(s[i] == s[i - 1]){
                int len = 0, j = i;
                while(i < N && s[i] == s[i - 1]){
                    i++;
                    len++;
                }
                in[j - 1] = len + 1;
                pl.push_back({j - 1, len + 1});
            }
            else i++;
        }
        int i = 0, j = 0, op = 0;
        while(i < N && j < pl.size()){
            if(i != pl[j].first){
                pl[j].second--;
                op++;
                if(pl[j].second == 1) j++;
            }
            else{
                j++;
                op++;
            }
            i += in[i];
        }
        
        int cnt = 0;
        while(i < N){
            cnt++;
            i += in[i];
        }

        op += (cnt + 2 - 1) / 2;

        cout << op << endl;

    }
    return 0;
}