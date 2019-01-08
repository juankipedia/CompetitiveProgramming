#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long int ulli;
typedef long long int lli;
typedef unsigned int ui;
typedef vector<int> v_i;
typedef vector<long long int> v_lli;
typedef vector<unsigned int> v_ui;
typedef vector<unsigned long long int> v_ulli;
typedef set<int> s_i;
typedef set<long long int> s_lli;
typedef set<unsigned int> s_ui;
typedef set<unsigned long long int> s_ulli;
typedef unordered_set<int> u_s_i;
typedef unordered_set<long long int> u_s_lli;
typedef unordered_set<unsigned int> u_s_ui;
typedef unordered_set<unsigned long long int> u_s_ulli;

int main() {
    unordered_map<int, int> l , r;
    int n, li, ri, max, min;
    stack <int> ls;
    cin >> n;
    cin >> li >> ri;
    l[li] = 1; r[ri] = 1;
    max = ri, min = li;
    for (int i = 1; i < n; ++i){
    	cin >> li >> ri;
    	if(li < min) min = li;
    	if(ri > max) max = ri;
    	++l[li]; ++r[ri];
    }
    int c = 0;
    for (int i = min; i <= max; ++i){
    	//cout << i << endl;
    	if(l.find(i) != l.end()){
    		c += l[i];
    		for (int k = 0; k < l[i]; ++k) ls.push(i);
    	}	
    	if(r.find(i) != r.end()) for (int k = 0; k < r[i]; ++k) ls.pop();
    	if(not ls.empty() or l.find(i) != l.end() or r.find(i) != r.end())
    		cout << i << " " << c << "\n";
    	if(r.find(i) != r.end()){
    		c -= r[i];
    	}
    }
    return 0;
}