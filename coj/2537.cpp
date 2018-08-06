# include <bits/stdc++.h>
using namespace std;

bool win(unsigned int *p, unsigned int *c,const unsigned int & n){
	int t = 0;
	for (unsigned int i = 0; i < n; ++i){
		for (unsigned int j = 0; j < n; ++j)
			if(not (t & (1 << ((c[p[i]] + j) % n)) )){
				t += (1 << ((c[p[i]] + j) % n));
				break;
			}
		
		if(t & (1 << c[0])){
			if (p[i] == 0){
				return true;;
			}
			else{
				return false;
			}
		}
	}
	return false;
}

int main(){
	ios::sync_with_stdio(false); cin.tie(0);
    unsigned int t;

    cin >> t;
    while(t --){
    	unsigned int n;
    	cin >> n;
    	unsigned int p[n], c[n], sum = 0;
    	for (unsigned int i = 0; i < n; ++i){
    		cin >> c[i];
    		p[i] = i;
    	}
    	do {
    		if(p[0] == 0)
    			sum ++;
	    	else if(win(p, c ,n))
	    		sum ++;
	  	} while (next_permutation(p, p + n));
	  	cout << sum << "\n";
    }
	    
	return 0;
}