# include <bits/stdc++.h>
using namespace std;

# define endl "\n"
# define io_boost std::ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
typedef unsigned long long int ulli;
typedef long long int lli;
typedef unsigned int ui;

long long int t, N, M;
string aux_string;
int a[105];

int main(){
    cin >> t;
    while(t--){
        cin >> N;
        int maxi = -200;
        bool l = false;
        for(int i = 0; i < N; i++){
            cin >> a[i];
            maxi = max(a[i], maxi);
            if(a[i] < 0) l = true;
        }
        if(l) cout << "no" << endl;
        else{
            cout << "yes" << endl;
            cout << maxi + 1 << endl;
            for(int i = 0; i <= maxi; i++) cout << i << " ";
            cout << endl;
        }

    
    }
    return 0;
}