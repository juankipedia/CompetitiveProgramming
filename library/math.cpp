# include <bits/stdc++.h>
using namespace std;

int gcd(int a, int b){
	if(b == 0) return a;
	return gcd(b, a % b);
}
//###############################################################################################################
constexpr long long unsigned int M = 1000007ll;
std::map<long long unsigned int, long long unsigned int> Found_F{ { 0, 1 }, { 1, 1 } };

long long unsigned int Fib(long long unsigned int n){
  auto item { Found_F.find(n) };
  if(item != Found_F.end())
    return std::get<1>(*item);
  long long unsigned int k { n >> 1 };
    if(n & 1)
        return Found_F[n] = (Fib(k) * Fib(k + 1) + Fib(k - 1) * Fib(k)) % ::M;
    return Found_F[n] = (Fib(k) * Fib(k) + Fib(k - 1) * Fib(k - 1)) % ::M;
}
long long unsigned int Fibonacci(long long unsigned int n){
    return n == 0 ? 0 : Fib(n - 1);
}
//###############################################################################################################
template<typename T>
T pow(T n, T e)
{
    T res { 1 };

    while(e > T(0))
    {
      if (e & 1)
        res = res * n;

      e >>= 1;
      n = n * n;
    }

    return res;
}
//################################################################################################################
bool is_prime(int n) {
    if (n == 1)
        return false;
    int i = 2;
    while (i*i <= n) {
        if (n % i == 0)
            return false;
        i += 1;
    }
    return true;
}
int main(){

	return 0;
}