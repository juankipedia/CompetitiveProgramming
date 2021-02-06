#include <bits/stdc++.h>
using namespace std;

# define endl "\n"
# define io_boost std::ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
typedef unsigned long long int ulli;
typedef long long int lli;
typedef unsigned int ui;

int h, w;
string m[15];

int main(){
    cin >> h >> w;
    for(int i = 0; i < h; i++){
        cin >> m[i];
    }

    int r = -1, c = -1;
    for(int i = 1; i < w - 1; i++){
        for(int j = 1; j < h -1; j++){
            if(m[j][i] == '#'){
                c = i - 1;
                r = j;
                break;
            }
        }
        if(r != -1) break;
    }
    int d = 0, ir = r, ic = c;
    int sides = 0;
    while(true){
        if(d == 0){
            if(m[r][c] == '#'){
                d = 2;
                sides++;
                r--;
            }
            else{
                if(m[r][c + 1] == '#') r++;
                else{
                    d = 3;
                    sides++;
                    c++;
                }
            }
        }
        else if(d == 1){
            if(m[r][c] == '#'){
                d = 3;
                sides++;
                r++;
            }
            else{
                if(m[r][c - 1] == '#') r--;
                else{
                    d = 2;
                    sides++;
                    c--;
                }
            }
        }
        else if(d == 2){
            if(m[r][c] == '#'){
                d = 1;
                sides++;
                c++;
            }
            else{
                if(m[r + 1][c] == '#') c--;
                else{
                    d = 0;
                    sides++;
                    r++;
                }
            }
        }
        else{
            if(m[r][c] == '#'){
                d = 0;
                sides++;
                c--;
            }
            else{
                if(m[r - 1][c] == '#') c++;
                else{
                    d = 1;
                    sides++;
                    r--;
                }
            }
        }


        if(r == ir && ic == c) break;
    }
    
    cout << sides << endl;

    return 0;
}