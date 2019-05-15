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

lli t, n;

bool count(lli x, lli d[]) {
	lli c = 0;
	unordered_set<lli> s;
    for (lli i=1; i<=sqrt(x); i++) { 
        if (x%i == 0){ 
            if (x/i == i)
            	s.insert(i);
            else{
            	s.insert(i); s.insert(x / i);
            }
        } 
    } 

    //cout << s.size() << " " << n << endl;
    if(s.size() - 2 != n)
    	return false;
    int size = s.size();
   	for (int i = 0; i < n; ++i) s.insert(d[i]);
   	if(size != s.size())
   		return false;


   	return true;
} 

int main(){
	//io_boost;
	cin >> t;
	while(t--){
		cin >> n;
		lli d[n];
		for (int i = 0; i < n; ++i) cin >> d[i];
		sort(d, d + n);
		lli x;
		int i = 0, j = n - 1;
		if(n % 2 == 0) x = d[i] * d[j];
		else x = d[n /2] * d[n / 2];
		bool b = false;
		for (; i < n / 2 ; ++i, j--){
			if(d[i] * d[j] != x){
				cout << - 1 << endl; b = true; break;
			}
		}

		if(not b){
			if (not count(x, d))
				cout << -1 << endl;
			else
				cout << x << endl;
		}
	}
    return 0; 
}