# include <bits/stdc++.h>
using namespace std;

int main(){
	std::ios::sync_with_stdio(false);
	cin.tie(0);
	unsigned int i =0;
	char s[21];
	cin >> s;
	while(s[i] != '\0'){
		if(s[i] == 'i'){
			cout << "N\n";
			return 0;
		}
		i++;
	}
	cout << "S\n";
	return 0;
}