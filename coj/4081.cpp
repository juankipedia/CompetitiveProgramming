# include <bits/stdc++.h>
using namespace std;

int main(){
	string co, uo;
	getline(cin, co);
	getline(cin, uo);
	if(co.compare(uo) == 0)
		cout << "Accepted" << endl;
	else{
		string b, b2;
		unsigned int i = 0,j = 0;
		while(true){
			if(i >= co.length() and j >= uo.length())
				break;
			if(co[i] != ' ' and co[i] != '\0')
				b += co[i];
			if(uo[j] != ' ' and uo[j] != '\0')
				b2 += uo[j];
			if(i < co.length())
				i++;
			if(j < uo.length())
				j++;
		}
		if (b.compare(b2) != 0)
			cout << "Wrong Answer" << endl;
		else
			cout << "Presentation Error" << endl;
	}
	return 0;
}