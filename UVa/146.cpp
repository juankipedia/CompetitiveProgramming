# include <bits/stdc++.h>

using namespace std;

int main(){

	string a_code = "";
	cin >> a_code;
	while(a_code != "#"){
		char* code = const_cast<char*>(a_code.c_str());
		bool b  = next_permutation(code, code + a_code.size());
		if(b){
			for (int i = 0; i < a_code.size(); ++i)
				cout << code[i];
			cout << "\n";
		}
		else
			cout << "No Successor\n";
		cin >> a_code;
	}
	return 0;
}