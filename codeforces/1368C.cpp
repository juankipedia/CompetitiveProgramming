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

int main()
{
	long long int k;
	scanf("%lld", &k);
	long long int i;
	printf("%lld\n", 4+3*k);
	printf("0 0\n");
	printf("0 1\n");
	printf("1 0\n");
	printf("1 1\n");
	for ( i = 0; i < k; ++i ){
		printf("%lld %lld\n", i+2, i+1);
		printf("%lld %lld\n", i+2, i+2);
		printf("%lld %lld\n", i+1, i+2);
	}
    return 0;
 
}