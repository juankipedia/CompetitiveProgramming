# include <bits/stdc++.h>
using namespace std;

int main(){

	string s;
	cin >> s;
	string r = ""; 
	int i = 0;
	if(s.length() %2 == 0){
		i = s.length()/2 - 1;
		r += s[i];

	}
	else{
		i = s.length()/2;
		r += s[i];
	}

	int j = i;
	bool rigth = true;
	while(true){
		if(rigth){
			i++;
			if(i < s.length())
				r += s[i];
			rigth = false;
		}
		else{
			j--;
			if(j >= 0)
				r += s[j];
			rigth = true;
		}

		if(j<0 and i >= s.length())
			break;
	}

	/*for (unsigned int i = 1; i < s.length(); ++i){
		if(i%2 != 0)
			
		else
			r += s[i];
	}	*/

	cout << r << endl;
	return 0;
}