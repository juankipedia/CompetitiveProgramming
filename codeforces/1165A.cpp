#include <bits/stdc++.h>
using namespace std;

# define endl "\n"


int main() {
	int n, x, y;
	cin >> n >> x >> y;
	string num;
	cin >> num;
	int op = 0;
	for (int i = n - 1; i >= n - y ; i--){
		if(num[i] == '1'){
			op++;
		}
	}

	if(num[n- y - 1] == '0')
		op++;

	for (int i = n- y - 2; i >= n - x ; i--){
		if(num[i] == '1'){
			op++;
		}
	}

	cout << op << endl;
    return 0;
}