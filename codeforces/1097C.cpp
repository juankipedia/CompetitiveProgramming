#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long int ulli;
typedef long long int lli;
typedef unsigned int ui;


pair<int, int> is_balanced(string expr){ 
    stack<char> s; 
    int r = 0; 
    for (int i = 0; i < expr.length(); i++) { 
        if (expr[i] == '(') { 
            s.push(expr[i]); 
            continue; 
        }  
        if (s.empty()){
        	r++;
        	continue;
        }
        if(expr[i] == ')'){ 
            s.pop(); 
        } 
    } 
    if(r != 0){
  		if(s.empty())
    		return make_pair(2, r);
    	else
    		return make_pair(3, 0);
    }
    else if(s.empty())
    	return make_pair(0, 0);
    else
    	return make_pair(1, s.size());
}


int main() {
	int n; string e;
	cin >> n;
	int b = 0;
    unordered_map<int, int> l, r, c;
    for (int i = 0; i < n; ++i){
    	cin >> e;
    	auto p =  is_balanced(e);
    	if(p.first == 0)
    		b ++;
    	else if(p.first == 1)
    		++r[p.second];
    	else if(p.first == 2)
    		++l[p.second];
    	else
    		continue;
    }
   
   	int t = b / 2;
   	for(const pair<int, int> p : l)
   		t += min(r[p.first], p.second);

   	cout << t << endl;

    return 0;
}