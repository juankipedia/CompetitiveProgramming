#include <bits/stdc++.h>
using namespace std;

# define endl "\n"

typedef unsigned int ui;


int main() {
	ui c1, c2, c3, c4;
	cin >> c1 >> c2 >> c3 >> c4;
	if(c1 != c4)
		cout << 0 << endl;
	else if(c1 == 0 and c3 != 0)
		cout << 0 << endl;
	else
		cout << 1 << endl;
    return 0;
}