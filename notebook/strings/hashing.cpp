#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long int ulli;
typedef long long int lli;

ulli MODS[] = {1000000007, 10657331232548839, 790738119649411319};

/**
 * ROLLING HASH
 * s: string to hash
 * b: base constant, normally set as the size of the alphabet
 * p: prime number to take the modulo.
 * 
 * hash(s) = sum(s[i] * b ^ i) % p, for all i in [i, n = s.size()]
 * or
 * hash(s) = sum(s[i] * b ^ (n - 1 - i)) % p, for all i in [i, n = s.size()]
 * 
 * NOTE: some times it is useful to use double hash one with, b1 = alphabet size, 
*        and another with, b2 = alphabet size + 5.
*/

// Using single variable.
ulli rolling_hash(string &&s, ulli b, ulli p){
    //hash(s) = sum(s[i] * b ^ (n - 1 - i)) % p, for all i in [i, n = s.size()]
    ulli hash = (s[0] - 'a' + 1);
    for(int i = 1; i < s.size(); i++)
        hash = ((hash * b) % p + (s[i] - 'a' + 1ULL)) % p;
    return hash;
}

// Using array. Useful for getting hash of a subsegment, complete hash at get_hash(0, s.size() - 1)
// hash stored in h[] and B ^ i = b[i]
void rolling_hash(string &&s, lli h[], lli b[], lli B, lli p){
    h[0] = 0;
    h[1] = (s[0] - 'a' + 1);
    b[0] = 1;
    for(int i = 1; i < s.size(); i++){
        h[i + 1] = ((h[i] * B) % p + (s[i] - 'a' + 1LL)) % p;
        b[i] = (B * b[i - 1]) % p;   
    }
}


lli get_hash(int l, int r, lli h[], lli b[], lli p){
    return (h[r + 1] - ((h[l] * b[r - l + 1]) % p) + p) % p;
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