/**
 * 
 * FAST EXPONENTIATION.
 * 
 *  x ^ n = {
 *      x                     if n = 1;
 *      (x ^ (n / 2)) ^ 2     if n % 2 = 0;
 *      x * x ^ (n - 1)       if n % 2 != 0;
 * }
 *  
 **/
ull binpow(ull a, ull b, ull m) {
    a %= m;
    ull res = 1;
    while(b > 0){
        if(b & 1) res = res * a % m;
        a = a * a % m;
        b >>= 1;
    }
    return res;
}


/**
 * 
 * COMBINATION (Binomial coefficient). 
 *
 **/
ull combination(ull n, ull k){ 
  if(k == 0 || k == n) return 1; 
  return combination(n - 1, k - 1) + combination(n - 1, k); 
}

ull combination_iterative(ull n, ull k){ 
    ull C[k+1] = {0}; 
    C[0] = 1;
    for(ull i = 1; i <= n; i++) 
        for(ull j = min(i, k); j > 0; j--) 
            C[j] = C[j] + C[j - 1];
    return C[k]; 
} 


/**
 * 
 * GET ALL PRIME FACTORS
 * Time complexity: 
 *  O(sqrt(n)), upper bound, when n is prime then function 
 *  reaches worst case.
 * 
 **/

void prime_factors(int n){
    while(n % 2 == 0) cout << 2 << " ", n = n / 2;  
  
    for(int i = 3; i * i <= n; i += 2)  
        while(n % i == 0) cout << i << " ", n = n / i;
    
    if(n > 2) cout << n << " ";
}
