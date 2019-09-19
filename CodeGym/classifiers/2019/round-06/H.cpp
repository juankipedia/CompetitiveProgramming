#include <bits/stdc++.h>
using namespace std;

# define endl "\n"
# define io_boost std::ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
typedef unsigned long long int ulli;
typedef long long int lli;
typedef unsigned int ui;
typedef vector<int> vector_i;
typedef vector<long long int> vector_lli;
typedef vector<unsigned int> vector_ui;
typedef vector<unsigned long long int> vector_ulli;
typedef set<int> set_i;
typedef set<long long int> set_lli;
typedef set<unsigned int> set_ui;
typedef set<unsigned long long int> set_ulli;
typedef unordered_set<int> u_set_i;
typedef unordered_set<long long int> u_set_lli;
typedef unordered_set<unsigned int> u_set_ui;
typedef unordered_set<unsigned long long int> u_set_ulli;

const ulli mod = 998244353;

int main(){
   int n, m, k;
   cin >> n >> m >> k;
   lli memo[n + 5][k + 5] = {}; 
   if(m == 1){
      if(k == 0)
         cout << 1 << endl;
      else
         cout << 0 << endl;
      return 0;
   }
 
   memo[0][0] = m;
   memo[1][1] = m - 1;
   memo[1][0] = m;
 
   for(int i = 1; i < n; ++i){
      for(int j = 0; j <= k; ++j){
      	 if(j > 0)
      	 	memo[i][j] = (memo[i - 1][j] + memo[i - 1][j - 1] * (m - 1) % mod) % mod;
      	 else 
      	 	memo[i][j] = memo[i - 1][j] % mod;

      }
   }
   cout << memo[n - 1][k] << endl;
   return 0;	 
}



