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

ulli M = 1000000007;
int t;
ulli A, B;

ulli sf(ulli a, ulli b, unordered_map<string , ulli> &memo){
	
	if(a > A or b > B) return 0;

	string p = to_string(a) + "-" + to_string(b);
	
	if(memo.find(p) != memo.end()) return memo[p];

	if(a == A and b == B) return 1;
	
	ulli c = 0;
	if(b + 1 < a)
		c += sf(a, b + 1, memo) % M;
	c += sf(a + 1, b, memo) % M;
	memo[p] = c;
	return c;
}



ulli s(ulli a, ulli b, unordered_map<string , ulli> &memo_s){
	
	if(a > A or b > B) return 0;

	string p = to_string(a) + "-" + to_string(b);
	
	if(memo_s.find(p) != memo_s.end()) return memo_s[p];

	if(a == A and b == B) return 1;
	
	ulli c = 0;

	c += s(a, b + 1, memo_s) % M;
	
	if(b == B or a + 1 <= b)
		c += s(a + 1, b, memo_s) % M;
	memo_s[p] = c;
	return c;
}

int main() {
	scanf("%d", &t);
	for (int k = 0; k < t; ++k){
		scanf("%llu-%llu", &A, &B);
		//cout << A << " " << B << endl;
		unordered_map<string, ulli> memo, memo_s;
		printf("Case #%d: %llu %llu\n", k + 1, sf(1, 0, memo), s(0, 0, memo_s));

	}

	/*cin >> A >> B;
	cout << sf(1, 0) << endl;
	cout << s(0,0) << endl;*/
    return 0;
}