#include <bits/stdc++.h>
using namespace std;

# define endl "\n"
# define io_boost std::ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
typedef unsigned long long int ulli;
typedef long long int lli;
typedef unsigned int ui;

ulli N;

int main(){
    cin >> N;
    ulli c = 0;
    set<ulli> s;
    for(ulli i = 2; i * i <= N; i++){
        ulli n = i * i;
        while(n <= N){
            if(!s.count(n)){
                c++;
                s.insert(n);
            }
            n *= i;
        }
        //cout << c << endl;
    }
    //cout << c << endl;
    cout << N - c << endl;
}