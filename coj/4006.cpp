# include <bits/stdc++.h>
using namespace std;

string n[21] = {"zero","un", "deux", "trois", "quatre", "cinq", 
"six", "sept", "huit", "neuf", "dix", "onze", "douze", "treize",
"quatorze", "quinze", "seize", "dix-sept", "dix-huit", "dix-neuf",
"vingt"};


int main(){
	unsigned int m, mi;
	cin >> m;
	while(m --){
		cin >> mi;
		cout << n[mi] << endl;
	}
	return 0;
}