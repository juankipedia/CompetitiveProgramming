#include <bits/stdc++.h>
using namespace std;

# define endl "\n"
# define io_boost std::ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
typedef unsigned long long int ulli;
typedef long long int lli;
typedef unsigned int ui;

lli A, B, C;

lli power(lli x, lli y, lli p) 
{ 
    lli res = 1;     // Initialize result 
 
    x = x % p; // Update x if it is more than or 
                // equal to p
  
    if (x == 0) return 0; // In case x is divisible by p;
 
    while (y > 0) 
    { 
        // If y is odd, multiply x with result 
        if (y & 1) 
            res = (res*x) % p; 
 
        // y must be even now 
        y = y>>1; // y = y/2 
        x = (x*x) % p; 
    } 
    return res; 
} 

int find(int d){
    vector<int> p;
    p.push_back(d);
    int cd = (d * d) % 10;
    while(cd != d){
        p.push_back(cd);
        cd = (cd * d) % 10;
    }
    
    return p[(power(B, C, p.size()) - 1) % p.size()];
}

int main(){
    cin >> A >> B >> C;
    cout << find(A % 10) << endl;
    return 0;
}