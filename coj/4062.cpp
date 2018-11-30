# include <bits/stdc++.h>
using namespace std;

int main(){
	unsigned int t;
	cin >> t;
	string c;
	while(t--){
		cin >> c;
		if(c == "P=NP")
			cout << "skipped" << endl;
		else{
			unsigned int p = c.find('+');
			string b = c.substr(p + 1, c.length() - p + 1), a =  c.substr(0, p);
			cout << atoi(a.c_str()) + atoi(b.c_str()) << endl;
		}
	}	
	return 0;
}