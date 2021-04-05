# include <bits/stdc++.h>
using namespace std;

# define endl "\n"
# define io_boost std::ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
typedef unsigned long long int ulli;
typedef long long int lli;
typedef unsigned int ui;

int h, w;
string m[505];

int main(){
    cin >> h >> w;
    for(int i = 0; i < h; i++) cin >> m[i];
    int ci = -1, cj = -1;
    for(int i = 1; i < h - 1; i++){
        for(int j = 1; j < w - 1; j++){
            if(m[i][j] == '*' && m[i - 1][j] == '*'
                && m[i + 1][j] == '*' && m[i][j - 1] == '*' && m[i][j + 1] == '*'){
                    ci = i;
                    cj = j;
                    break;
            }
        }
    }

    if(ci == -1){
        cout << "NO" << endl;
        return 0;
    }
    
    int i = ci - 1, j = cj;
    while(i >= 0 && m[i][j] == '*'){
        m[i][j] = '.';
        i--;
    }
    i = ci;
    while(i < h && m[i][j] == '*'){
        m[i][j] = '.';
        i++;
    }

    i = ci; j = cj + 1;
    while(j < w && m[i][j] == '*'){
        m[i][j] = '.';
        j++;
    }

    i = ci; j = cj - 1;
    while(j >= 0 && m[i][j] == '*'){
        m[i][j] = '.';
        j--;
    }

    for(int i = 0; i < h; i++)
        for(int j = 0; j < w; j++)
            if(m[i][j] == '*'){
                cout << "NO" << endl;
                return 0;
            }
    cout << "YES" << endl;
    return 0;
}