#include <bits/stdc++.h>
using namespace std;

# define endl "\n"
# define io_boost std::ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
typedef unsigned long long int ulli;
typedef long long int lli;
typedef unsigned int ui;

ulli N;

ulli combination(ulli n, ulli k) { 
  if (k==0 || k==n) return 1; 
  return  combination(n-1, k-1) + combination(n-1, k); 
}

ulli factorial(ulli n){
    ulli p = 1;
    for(ulli i = 2; i <= n; i++) p = i * p;
    return p;
}

int main(){
    cin >> N;
    ulli ans = combination(N, N / 2) / 2;
    ulli f = factorial(N / 2 - 1);
    cout << f * f * ans << endl; 
    return 0;
}