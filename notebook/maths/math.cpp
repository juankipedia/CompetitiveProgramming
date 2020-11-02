# include <bits/stdc++.h>
using namespace std;

//######################################### Gratest Common Divisor ##############################################
int gcd(int a, int b){
	if(b == 0) return a;
	return gcd(b, a % b);
}
//######################################### Fibonacci ###########################################################
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
//######################################### Power ################################################################
template<typename T>
T pow(T n, T e){
    T res { 1 };
    while(e > T(0)){
      if (e & 1)
        res = res * n;
      e >>= 1;
      n = n * n;
    }
    return res;
}
//####################################### Power with Mod ##########################################################
template <typename T>
T modpow(T n, T e, T m) {
  n %= m;
  T result = 1;
  while (e > 0) {
    if (e & 1) result = (result * n) % m;
    n = (n * n) % m;
    e >>= 1;
  }
  return result;
}
//######################################### Check if Number Is Prime ##############################################
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
//################################################ Combination #####################################################
int combination(int n, int k) { 
  if (k==0 || k==n) return 1; 
  return  combination(n-1, k-1) + combination(n-1, k); 
}

//################################################ Combination iterative with modulo ###############################
int nCr_mod_M(int n, int r, int MOD){ 
    int C[r+1]; 
    memset(C, 0, sizeof(C)); 
    C[0] = 1; 
    for (int i = 1; i <= n; i++) { 
        for (int j = min(i, r); j > 0; j--) 
            C[j] = (C[j] + C[j-1])%MOD; 
    } 
    return C[r]; 
} 

//############################################## Combination iterative ##############################################
ulli binomialCoeff(ulli n, ulli k){ 
    ulli C[k+1] = {0}; 
    C[0] = 1;
    for (ulli i = 1; i <= n; i++){ 
        for (ulli j = min(i, k); j > 0; j--) 
            C[j] = C[j] + C[j-1]; 
    } 
    return C[k]; 
} 

//############################################## Print All Divisors #################################################
void printDivisors(int n){  
    for (int i=1; i<=sqrt(n); i++){ 
        if (n%i == 0){ 
            if (n/i == i) 
                printf("%d ", i); 
            else
                printf("%d %d ", i, n/i); 
        } 
    } 
} 

//############################################# al primes from 2 to n ################################################

void SieveOfEratosthenes(int n){ 
    bool prime[n+1]; 
    memset(prime, true, sizeof(prime)); 
  
    for (int p=2; p*p<=n; p++) { 
        if (prime[p] == true){ 
            for (int i=p*p; i<=n; i += p) 
                prime[i] = false; 
        } 
    } 

    for (int p=2; p<=n; p++) 
       if (prime[p]) 
          cout << p << " "; 
} 


int main(){

	return 0;
}