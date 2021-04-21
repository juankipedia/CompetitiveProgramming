# include <bits/stdc++.h>
using namespace std;
# define endl "\n"
 
int main(){
    int t, n, arr[105];
    cin >> t;
    while(t--){
        cin >> n;
        for(int i = 0; i < n; i++){
            cin >> arr[i];
        }
        bool la = false;
        for(int i = 0; i < n; i++){
            int aux = sqrt(arr[i]);
            if(aux * aux != arr[i]){
                la = true;
                break;
            }
        }
        if(!la){
            cout << "NO" << endl;
        }
        else{
            cout << "YES" << endl;
        }
    }
    return 0;
}