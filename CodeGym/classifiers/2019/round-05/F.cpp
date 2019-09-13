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


constexpr ulli M = 10000007ll;
std::map<ulli, ulli> Found_F{ { 0, 1 }, { 1, 1 } };

ulli Fib(ulli n){
  auto item { Found_F.find(n) };
  if(item != Found_F.end())
    return std::get<1>(*item);
  ulli k { n >> 1 };
    if(n & 1)
        return Found_F[n] = (Fib(k) * Fib(k + 1) + Fib(k - 1) * Fib(k)) % ::M;
    return Found_F[n] = (Fib(k) * Fib(k) + Fib(k - 1) * Fib(k - 1)) % ::M;
}
ulli Fibonacci(ulli n){
    return n == 0 ? 0 : Fib(n - 1);
}

int main() {
	cout << Fibonacci(1e5) << endl;
}