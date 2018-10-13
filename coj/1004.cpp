#include <iostream>
#include <cstdio>
using namespace std;

int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int t, b, n, m;
    cin >> t;
    for(int k = 1; k <= t; k++){
        cin >> n >> m;
        b = min(m, n) - 1;
        if(b % 2 != 0)
            b--;
        n = n - b;
        m = m - b;
        if(n == 1 and m == 1)
            cout << 'R' << endl;
        else{
            if(n == 2 and m == 2)
                cout << 'L' << endl;
            else{
                if(n == 1)
                    cout << 'R' << endl;
                else{
                    if(m == 1)
                        cout << 'D' << endl;
                    else{
                        if(n == 2)
                            cout << 'L' << endl;
                        else{ 
                            if(m == 2)
                                cout << 'U' << endl;
                        }
                    }
                }
            }
        }
    }
    return 0;
}