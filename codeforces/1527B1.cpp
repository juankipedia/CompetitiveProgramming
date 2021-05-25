# include <bits/stdc++.h>
using namespace std;

# define endl "\n"
# define io_boost std::ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
typedef unsigned long long int ulli;
typedef long long int lli;
typedef unsigned int ui;

int t, n;
string s;

bool palindrome(){
    for(int i = 0, j = s.size() - 1; i < j; i++, j--)
        if(s[i] != s[j]) return false;
    return true;
}

bool all_ones(){
    for(char c : s) if(c != '1') return false;
    return true;
}

int main(){
    cin >> t;
    while(t--){
        cin >> n >> s;
        int z = 0, o = 0;
        for(int i = 0; i < n; i++) if(s[i] == '1') o++; else z++;
        if(z % 2 && z != 1) cout << "ALICE" << endl;
        else cout << "BOB" << endl;
    }
    return 0;
}