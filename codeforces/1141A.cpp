#include <bits/stdc++.h>
using namespace std;

# define endl "\n"


size_t solve(size_t n, size_t m, size_t s){
	if(n > m)
		return 0;
	if(n == m)
		return s;
	s++;
	size_t r = solve(2 *n , m, s);
	if(r != 0)	
		return r;
	else
		return solve(3 *n, m, s);

}

int main() {
	size_t n, m, s;
	cin >> n >> m;
	if(n == m)
		cout << 0 << endl;
	else{
		size_t r = solve(n,m,0);
		if(r != 0)
			cout << solve(n,m,0) << endl;
		else
			cout << -1 << endl;
	}
    return 0;
}