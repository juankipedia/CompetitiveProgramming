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
typedef std::numeric_limits< double > dbl;

int sieve[10000001] = {0};

int t;
ulli A, B, K;

int main() {
	io_boost;
	cin >> t;


	for (int x = 2; x <= 10000000; x++) {
		if (sieve[x]) continue;
		for (int u = 2*x; u <= 10000000; u += x) sieve[u]++;
	}

	for (int k = 0; k < t; ++k){
		
			cin >> A >> B >> K;
			ulli c = 0;
			for(lli i = A; i <= B; i++)
				if(K == sieve[i]) c ++;
				else if(sieve[i] == 0 and K == 1) c++;

			cout << "Case #" << k + 1 << ": ";
			cout << c << endl;

		
	}
    return 0;
}