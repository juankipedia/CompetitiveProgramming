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

int main(){
	int n;
	cin >> n;
	string s;
	cin >> s;
	int j = (n - 11) / 2;
	ui a[n] = {0};
	for(int i = 0; i < n;i++){
	  if(s[i] == '8'){
	      a[i] = 1;
	      j--;
	  }  
	  if(j == 0) break;
	}
	j = (n - 11) / 2;
	for(int i = 0; i < n; i++){
	    if(s[i] != '8'){
	        a[i] = 1;
	        j--;
	    }
	    if(j == 0) break;
	}

	for(int i = 0; i < n; i++){
	    if(a[i] == 0 and s[i] == '8'){
	         cout << "YES" << endl;
	         return 0;
	    }
	      
	    if(a[i] == 0 and s[i] != '8'){
	        cout << "NO" << endl;
	    	return 0;
	    }
	}
}