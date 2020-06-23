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

int t, n;
int divisors(int n){
    int maxi = 0;
    for (int i=1; i<=sqrt(n); i++){ 
        if (n%i == 0){ 
            if (n/i == i) 
                maxi = max(i, maxi);
            else{
                if(n / i != n)  maxi = max(n / i, maxi);
                maxi = max(i, maxi); 
            }
                 
        } 
    }
    return maxi;
} 

int main() {
    cin >> t;
    while(t--){
        cin >> n;
        
        cout << max(divisors(n), divisors(n - 1)) << endl;
    }
    return 0;
}