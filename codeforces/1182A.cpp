#include <bits/stdc++.h>
using namespace std;

# define endl "\n"


int n;

int main() {
	cin >> n;
	if(n % 2)
		cout << 0 << endl;
	else
		cout << (1 << (n / 2)) << endl;
    return 0;
}