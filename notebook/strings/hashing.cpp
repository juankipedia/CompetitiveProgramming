#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long int ulli;

ulli MODS[] = {1000000007, 10657331232548839, 790738119649411319};

/**
 * ROLLING HASH.
 * s: string to hash
 * b: base constant, normally set as the size of the alphabet + 1
 * p: prime number to take the modulo.
 * 
 * hash(s) = sum(s[i] * b ^ i) % p, for all i in [i, n = s.size()]
 * or
 * hash(s) = sum(s[i] * b ^ (n - 1 - i)) % p, for all i in [i, n = s.size()]
 * 
 * 
*/
ulli rolling_hash(string &&s, ulli b, ulli p){
    //hash(s) = sum(s[i] * b ^ (n - 1 - i)) % p, for all i in [i, n = s.size()]
    ulli hash = (s[0] - 'a' + 1);
    for(int i = 1; i < s.size(); i++)
        hash = ((hash * b) % p + (s[i] - 'a' + 1ULL)) % p;
    return hash;
}

/**
 * GENERATE RANDOM NUMBER IN [a, b]
*/

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
ulli random(ulli a, ulli b){
    return uniform_int_distribution<ulli>(a, b)(rng);
}

int main(){
    return 0;
}