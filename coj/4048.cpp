# include <bits/stdc++.h>
using namespace std;

int main(){
	unsigned int t, n;
	cin >> t;
	string s;
	while(t--){
		cin >> n >> s;
		unsigned int count = 0;
		for (int i = 0; i < n - 1; ){
			if(s[i] == '>' and s[i + 1] == '<'){
				count ++;
				swap(s[i], s[i + 1]);
				if(i > 0)
					i--;
			}
			else i++;
		}
		cout << count << endl;
	}	
	return 0;
}