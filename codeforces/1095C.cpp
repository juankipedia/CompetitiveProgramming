#include <bits/stdc++.h>
using namespace std;

typedef long long unsigned int ulli;
typedef long long int lli;
typedef unsigned int ui;

void block(ui x, vector<ui> &p){ 
    vector<ui> v; 
    while (x > 0){ 
        v.push_back(x % 2); 
        x = x / 2; 
    } 
    for (int i = 0; i < v.size(); i++)
        if (v[i] == 1)  
            p.push_back((1 << i));
} 

int main() {
	ui n ,k;
	cin >> n >> k;
	vector<ui> p;
	block(n, p);
	if(k > n or k < p.size()) cout << "NO\n";
	else{
		cout << "YES\n";
		int i = 0;
		while(p.size() != k){
			if(p[i] % 2 != 0){
				i++;
			}
			else{
				p[i] >>= 1;
				p.push_back(p[i]);
			}
		}
		for (int i = 0; i < p.size(); ++i) cout << p[i] << " ";
		cout << endl;
	}
    return 0;
}
