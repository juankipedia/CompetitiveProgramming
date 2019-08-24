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

int n;

void SieveOfEratosthenes() { 

    bool prime[n+1]; 
    memset(prime, true, sizeof(prime)); 
  
    for (int p=2; p*p<=n; p++) 
    { 
        if (prime[p] == true) { 
            for (int i=p*p; i<=n; i += p) 
                prime[i] = false; 
        } 
    } 


    for (int i = 2, j = n - 1; i <= n / 2;){ 
    	
        if (prime[i] and prime[j] and (i + j) == n){ 
            cout << i << " " << j << endl; 
            return; 
        } 
        else if(prime[i] and prime[j]){
        	i++; j++;
        }
        if(not prime[j]) j--;
        if(not prime[i]) i++;
    }

    cout << -1 << endl; 
} 


int main() {
	cin >> n;
	SieveOfEratosthenes();
    return 0;
}