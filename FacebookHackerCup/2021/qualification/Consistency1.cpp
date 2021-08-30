# include <bits/stdc++.h>
using namespace std;
/*************************************************************************************/
# define endl "\n"
# define io_boost std::ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
typedef unsigned long long int ulli;
typedef long long int lli;
/*************************************JUANKIPEDIA*************************************/

char get(int c){ return c + 'A'; };
int get(char c){ return c - 'A'; };
set<int> vowels = {get('A'), get('E'), get('I'), get('O'), get('U')};

int main(){
    io_boost;
    int t;
    cin >> t;
    string s;
    for(int ti = 1; ti <= t; ti++){
        cin >> s;
        int n = s.size();
        int m[26] = {0};
        for(int i = 0; i < n; i++) m[get(s[i])]++;
        int ans = 1e9 + 5;
        for(int i = 0; i < 26; i++){
            int res = 0;
            for(int j = 0; j < 26; j++){
                if(i == j) continue;
                if(vowels.count(i) && vowels.count(j)) res += 2 * m[j];
                else if(vowels.count(i) && !vowels.count(j)) res += 1 * m[j];
                else if(!vowels.count(i) && vowels.count(j)) res += 1 * m[j];
                else res += 2 * m[j];
            }
            ans = min(ans, res);
        }
        cout << "Case #" << ti << ": " << ans << endl;
    }
    return 0;
}