# include <bits/stdc++.h>
using namespace std;

typedef unsigned int ui;

int main(){
	string a;
	cin >> a;
	ui ident = 0, i = 0;
	while(i < a.length()){
		if(a[i] == '}'){
			ident -= 2;
			i++;
			for (ui j = 0; j < ident; ++j)
				cout << " ";
			cout << '}';

		}
		else{
			for (ui j = 0; j < ident; ++j) cout << " ";
			if(a[i] == '{'){
				ident += 2;
				cout << '{';
				i++;
			}
			else
				while(a[i] != ',' and a[i] != '}'){cout << a[i]; i++;}
		}
		if(a[i] == ','){cout << ',' << endl; i++;}
		else cout << endl;
	}
	return 0;
}