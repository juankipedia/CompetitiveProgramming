#include <bits/stdc++.h>
using namespace std;

# define endl "\n"
# define io_boost std::ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);


int main() {
	int x;
	cin >> x;
	int c = 0, c1 = 0, c2 = 2;
	char ct, ct1, ct2;
	if(x % 4 == 1){
		cout << 0 << " A" << endl;
		return 0;
	}
	else if (x % 4 == 2){
		c = 3;
		ct = 'C';
	}
	else if (x % 4 == 3){
		c = 2;
		ct = 'B';
	}
	else if (x % 4 == 0){
		c = 4;
		ct = 'D';
	}

	

	if((x + 1) % 4 == 1){
		c1 = 1;
		cout << 1 << " A" << endl;
		return 0;
	}
	else if ((x + 1) % 4 == 2){
		c1 = 3;
		ct1 = 'C';
	}
	else if ((x + 1) % 4 == 3){
		c1 = 2;
		ct1 = 'B';
	}
	else if ((x + 1) % 4 == 0){
		c1 = 4;
		ct1 = 'D';
	}


	if((x + 2) % 4 == 1){
		cout << 2 << " A" << endl;
		return 0;
	}
	else if ((x + 2) % 4 == 2){
		c2 = 3;
		ct2 = 'C';
	}
	else if ((x + 2) % 4 == 3){
		c2 = 2;
		ct2 = 'B';
	}
	else if ((x + 2) % 4 == 0){
		c2 = 4;
		ct2 = 'D';
	}

	if(c <= c1 and c <= c2){
		cout << 0 << " " << ct << endl;
		return 0;
	}

	if(c1 <= c2 and c1 <= c){
		cout << 1 << " " << ct1 << endl;
		return 0;
	}

	if(c2 <= c1 and c2 <= c){
		cout << 2 << " " << ct2 << endl;
		return 0;
	}
    return 0;
}