# include <bits/stdc++.h>
using namespace std;

int main(){
	unsigned int n;
	cin >> n;
	if(n < 2)
		cout << "WRONG ANSWER" << endl;
	else if(n > 3)
		cout << "RUNTIME ERROR" << endl;
	else
		cout << "ACCEPTED" << endl;
	return 0;
}