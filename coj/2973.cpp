# include <bits/stdc++.h>
using namespace std;


int main(){
	unsigned int n;

	while(cin >> n and n != 0){
		unsigned short d[n];
		unsigned int z = 0;
		for (unsigned int i = 0; i < n; ++i){
			cin >> d[i];
			if(d[i] == 0)
				z++;
		}
		sort(d, d + n);
		unsigned int b = d[z], a = d[z + 1];
		for (unsigned int i = 0; i < z; i++){
	 		if (i & 1) 
	            a = a * 10; 
	        else
	            b = b * 10;
		}
		for (unsigned int i = z + 2; i < n; i++){
	 		if (i & 1) 
	            a = a * 10 + d[i]; 
	        else
	            b = b * 10 + d[i];
		}
		cout << a + b << endl;
	}
	
	return 0;
}