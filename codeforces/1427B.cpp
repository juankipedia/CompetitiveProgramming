#include <bits/stdc++.h>
using namespace std;

# define endl "\n"
# define io_boost std::ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
typedef unsigned long long int ulli;
typedef long long int lli;
typedef unsigned int ui;

int t, n, k;
string s;

int main(){
    cin >> t;
    while(t--){
        cin >> n >> k;
        cin >> s;
        int l = 0;
        while(s[l] == 'L') l++;
        int init = l - 1;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> in;
        int inl = 0;
        for(; l < n; l++){
            if(s[l] == 'L') inl ++;
            else if(inl != 0){
                in.push({inl, l - inl});
                inl = 0;
            }
        }
        int fin = l - inl;
        while(!in.empty() && k != 0){
            auto inter = in.top();
            in.pop();
            int j = inter.second;
            for(int i = 0; i < inter.first && k != 0; i++){
                s[j] = 'W';
                k--; j++;
            }
        }

        for(int i = init; i >= 0 && k != 0; i--){
            if(s[i] == 'L'){
                s[i] = 'W';
                k--;
            }
        }

        for(int i = fin; i < n && k != 0; i++){
            if(s[i] == 'L'){
                s[i] = 'W';
                k--;
            }
        }

        lli sum = s[0] == 'W' ? 1 : 0;
        for(int i = 1; i < n; i++){
            if(s[i] == 'W' && s[i - 1] == 'W') sum += 2;
            else if(s[i] == 'W') sum += 1;
        }
        cout << sum << endl;
    }
    return 0;
}