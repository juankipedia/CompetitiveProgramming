# include <bits/stdc++.h> 
using namespace std;

unsigned long long int matrix_chain(unsigned long long int p[], unsigned long long int n) {
    unsigned long long int m[n][n]; 
    unsigned long long int i, j, k, L, q; 
    for (i=1; i<n; i++) 
        m[i][i] = 0; 

    for (L=2; L<n; L++){ 
        for (i=1; i<n-L+1; i++){ 
            j = i+L-1; 
            m[i][j] = std::numeric_limits<unsigned long long int>::max(); 
            for (k=i; k<=j-1; k++){  
                q = m[i][k] + m[k+1][j] + p[i-1]*p[k]*p[j]; 
                if (q < m[i][j]) 
                    m[i][j] = q; 
            } 
        } 
    } 
    return m[1][n-1]; 
} 
  
int main(){ 
    unsigned long long int n;
    cin >> n;
    unsigned long long int m[n + 1]; 
    for (unsigned long long int i = 0; i <= n; ++i) cin >> m[i];
    cout << matrix_chain(m, n + 1) << "\n";
    return 0; 
} 