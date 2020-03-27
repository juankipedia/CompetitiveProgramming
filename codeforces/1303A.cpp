# include <bits/stdc++.h>

using namespace std;
# define io_boost std::ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
const int INF = std::numeric_limits<int>::max();
string s;
int t, r, i, ri;

int main(){
    io_boost;
    cin >> t;
    while(t--){
        cin >> s;
        ri = r = i = 0;
        while(i < s.size() && s[i] != '1') i++;
        for(; i < s.size(); i++){
            if(s[i] == '0') ri++;
            else{
                r += ri;
                ri = 0;
            }
        }

        cout << r << endl;
    }

    return 0;
}