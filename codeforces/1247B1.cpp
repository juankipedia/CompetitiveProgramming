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

int t, n, k, d;


int main() {
	io_boost;
	cin >> t;
	while(t --){
		cin >> n >> k >> d;
		int a[n], pr = 0, r;
		map<int, int> p;
		for (int i = 0; i < n; ++i){
			cin >> a[i];
			a[i] --;
			if(i < d){
				if(p[a[i]] == 0) pr++;
				++ p[a[i]];
			}
		} 
		int mini = pr;
		
		for (int i = d; i < n; ++i){
			if(p.find(a[i]) == p.end() or p[a[i]] == 0) pr++;
			++p[a[i]];
			p[a[i - d]]--;
			if(p[a[i - d]] == 0) pr --;
			mini  = min(pr, mini);
		}
		cout << mini << endl;
	}
    return 0;
}