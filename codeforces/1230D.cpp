#include <bits/stdc++.h>
using namespace std;

# define endl "\n"
# define io_boost std::ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
typedef unsigned long long int ulli;
typedef long long int lli;


int n;
ulli a[7000];
ulli b[7000];
unordered_map<ulli, ulli> m1, m2;

int main() {
	cin >> n;
	for (int i = 0; i < n; ++i) cin >> a[i]; 

	for (int i = 0; i < n; ++i) cin >> b[i];
    
    for (int i = 0; i < n; ++i){
    	if(m1.find(a[i]) == m1.end()){
    		m1[a[i]] = b[i];
    		++m2[a[i]];
    	}
    	else{
    		m1[a[i]] += b[i];
    		++m2[a[i]];
    	}
    }

    ulli r = 0, ri = 0;
    unordered_set<ulli> c;
    for(const auto &p2 : m2){
    	if(p2.second < 2 or c.find(p2.first) != c.end()) continue;
    	c.insert(p2.first);
    	//cout << p2.first << endl;
    	ri = m1[p2.first];
    	for (const auto &p1 : m1){
    		if(p1.first != p2.first and (p2.first & p1.first) == p1.first and c.find(p1.first) == c.end()){
    			ri += p1.second;
    			c.insert(p1.first);
    		}
    	}
    	r += ri;
    	//cout << ri << endl;
    }
    cout << r << endl;
    return 0;
}