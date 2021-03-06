# include <bits/stdc++.h>
using namespace std;

# define endl "\n"
# define io_boost std::ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
typedef unsigned long long int ulli;
typedef long long int lli;
typedef unsigned int ui;

bool wr[] = {true, true, true, false, false, true, false, false, true, false};
int ma[] = {'0', '1', '5', '3', '4', '2', '6', '7', '8', '9'};
int t, h, m;
string T;

bool check(int hi, int mi){
    string hs = to_string(hi);
    string ms = to_string(mi);
    if(hi < 10) hs = "0" + hs;
    if(mi < 10) ms = "0" + ms;

    
    for(char c: hs)
        if(!wr[c - '0']) return false;
    for(char c: ms)
        if(!wr[c - '0']) return false;
    
    string rh = "", rm = "";
    for(int i = hs.size() - 1; i >= 0; i--) rh += ma[hs[i] - '0'];
    for(int i = ms.size() - 1; i >= 0; i--) rm += ma[ms[i] - '0']; 
    
    if(stoi(rm) >= h) return false;
    if(stoi(rh) >= m) return false;
    return true;
}

int main(){
    cin >> t;
    while(t--){
        cin >> h >> m;
        cin >> T;
        int H = stoi(T.substr(0, 2)), M = stoi(T.substr(3, 2));

        while(!check(H, M)){
            M++;
            if(M == m){
                M = 0;
                H++;
            }
            if(H == h){
                H = 0;
            }
        }
        if(H < 10) cout << 0;
        cout << H << ":" ;
        if(M < 10) cout << 0;
        cout << M << endl;

    }
    return 0;
}