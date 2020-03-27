# include <bits/stdc++.h>

using namespace std;
const int INF = std::numeric_limits<int>::max();

string s, f;
int m[3];

int main(){
    cin >> s;

    for(int i = 0; i < s.length(); i++){
        m[s[i]-'a']++;
        if(i != 0 && s[i] < s[i-1]){
            cout << "NO\n";
            return 0;
        }
    }
 
    if(m[0] == 0 || m[1] == 0 || m[2] == 0){
        cout << "NO\n";
    } else if(m[1] == m[2] || m[0] == m[2]){
        cout << "YES\n";
    } else{
        cout << "NO\n";
    }

    return 0;
}