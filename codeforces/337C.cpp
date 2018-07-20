# include <bits/stdc++.h>
using namespace std;

long long power(long long x, long long y, long long p){
    long long res = 1;      
    x = x % p;               
    while (y > 0){
        if (y & 1)
            res = (res*x) % p;
        y = y>>1;
        x = (x*x) % p;  
    }
    return res;
}

int main () {
  long long n, m, k, score = 0;
  cin >> n >> m >> k;
  long long p = (m - (n - m) * (k - 1)) / k;
  if (p > 0){
    long long sub_score = m % 1000000009ll - (p % 1000000009ll * k % 1000000009ll);
    score += (power(2, p + 1, 1000000009ll));
    score *= k;
    score -= 2 * k;
    score += sub_score;
    if(score < 0)
     score += 1000000009ll;
    cout << score % 1000000009ll << "\n";
  }
  else{
    cout << m % 1000000009ll << "\n";
  }  
  return 0;
}