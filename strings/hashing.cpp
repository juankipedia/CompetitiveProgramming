
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

struct Hash{
    vector<lli> h, b;
    lli B, p;
    string s;

    ulli MODS[] = {1000000007, 10657331232548839, 790738119649411319};


    Hash(const string &_s, int _B=31, int _p=MODS[0]){
        s = _s, B = _B, p = _p;
        h.assign(s.size() + 5, 0);
        b.assign(s.size() + 5, 0);
        rolling_hash();
    }

    void rolling_hash(){
        h[0] = 0;
        h[1] = (s[0] - 'a' + 1);
        b[0] = 1;
        for(int i = 1; i < s.size(); i++){
            h[i + 1] = ((h[i] * B) % p + (s[i] - 'a' + 1LL)) % p;
            b[i] = (B * b[i - 1]) % p;   
        }
    }


    lli get_hash(int l, int r){
        return (h[r + 1] - ((h[l] * b[r - l + 1]) % p) + p) % p;
    }

};


/**
 * GENERATE RANDOM NUMBER IN [a, b]
*/

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
ulli random(ulli a, ulli b){
    return uniform_int_distribution<ulli>(a, b)(rng);
}