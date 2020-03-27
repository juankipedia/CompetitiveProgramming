# include <bits/stdc++.h>

using namespace std;

int n, i;

int main(){
    cin >> n;
    while(n--){
        cin >> i;
        if(i == 1) cout << -1 << endl;
        else cout << string(i - 1, '5') + '8' << endl;
    }
 
    return 0;
}