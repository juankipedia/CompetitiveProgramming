#include <bits/stdc++.h>
using namespace std;

# define endl "\n"
# define io_boost std::ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
typedef unsigned long long int ulli;
typedef long long int lli;
typedef unsigned int ui;

int n;

int main(){
    while(cin >> n && n){
        int sum = 0, maxi = 0;
        for(int i = 0, ai; i < n; i++){
            cin >> ai;
            sum += ai;
            maxi = max(maxi, sum);
            if(sum < 0) sum = 0;
            
        }
        if(maxi > 0)
            cout << "The maximum winning streak is " <<  maxi << "." << endl;
        else cout << "Losing streak." << endl;
    }
    return 0;
}