# include <bits/stdc++.h>
using namespace std;

int main(){
	unsigned int n;
	string s;
	cin >> n;
	while(n--){
		cin >> s;
		for (unsigned int i = 0; i < s.length() - 1; ++i){
			char b = s[i];
			unsigned int j = i + 1, count = 1;
			while(j < s.length() and s[j] == b){
				count++;
				j++;
			}
			if(count > 3){
				cout <<  "@";
				unsigned int k = 0;
				for (unsigned int l = 0; l < count; ++l){
					k++;
					if(k == 9){
						cout << k << b;
						k = 0;
					}
				}
				if(k > 3) cout << k << b;
				else if(k > 0){for(unsigned int l = 0; l < k; l ++) cout << b;}
				i = j - 1;
				if(i + 1 == s.length() - 1)
					cout << s[i + 1];
			}
			else if(count > 1){
				for(unsigned int l = 0; l < count; l ++) cout << b;
				i = j - 1;
				if(i + 1 == s.length() - 1)
					cout << s[i + 1];
			}
			else{
				cout << s[i];
				if(i + 1 == s.length() - 1)
					cout << s[i + 1];
			}
		}
		cout << endl;
	}
	return 0;
}