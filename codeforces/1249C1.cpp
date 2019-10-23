# include <bits/stdc++.h>
 
using namespace std;
 
using mem = map<int, bool>;
 
// Prints sums of all subsets of array 
void init_mem(mem &m, int n) 
{ 
    long long total = 1<<n; 
  
    // Consider all numbers from 0 to 2^n - 1 
    for (long long i=0; i<total; i++) 
    { 
        long long sum = 0; 
  
        for (int j=0; j<n; j++) 
            if (i & (1<<j)) 
                sum += pow(3, j); 
  
        m[sum] = true; 
    } 
} 
 
 
int main()
{
    int q;
    mem m;
 
    init_mem(m, 10);
    cin >> q;
 
    while(q--)
    {
        int n;
        cin >> n;
 
        int diff = INT_MAX;
        int current_val = -1;
 
        for (auto &data : m)
        {
            int d = abs(data.first - n);
            
            if ( data.first >= n and d < diff)
            {
                diff = data.first - n;
                current_val = data.first;
            }
        }
            
 
        cout << current_val << "\n";
                
    }
 
    return 0;
}