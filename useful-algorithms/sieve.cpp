/**
 *
 * SIEVE OF ERATOSTHENES
 * Time complexity: O(n)
 * 
 **/
const int MAXN = 1000000;
vector<int> pr;
int lp[MAXN];

void sieve(int N){
    for(int i = 2; i <= N; i++){
        if (lp[i] == 0) {
            lp[i] = i;
            pr.push_back(i);
        }
        for(int j = 0; j < pr.size() && pr[j] <= lp[i] && i * pr[j] <= N; j++)
            lp[i * pr[j]] = pr[j];
    }
}


/**
 *
 * SIEVE OF ERATOSTHENES CLASSIC SOLUTION
 * Time complexity: O(n log(log n))
 * 
 **/
void sieve_of_eratosthenes(int n){ 
    bool prime[n + 1]; 
    memset(prime, true, sizeof(prime)); 
    for(int p = 2; p * p <= n; p++){ 
        if(prime[p] == true){ 
            for(int i = p * p; i <= n; i += p) 
                prime[i] = false; 
        }
    } 
    for(int p = 2; p <= n; p++) 
        if(prime[p]) cout << p << " "; 
}