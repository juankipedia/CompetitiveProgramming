#include <bits/stdc++.h>
using namespace std;


int main() {
	unsigned int w1, h1, w2, h2;
	cin >> w1 >> h1 >> w2 >> h2;
	tuple<int, int, int, int> f_c = make_tuple(1,1, 1, h1 + 1);
	tuple<int, int, int, int> s_c = make_tuple(1,h1 + 1, w2, h1 + h2);

	unsigned int r = 0;
	if(w1 == w2){
		r += w1 + 2;
		r += h1 + h2 + 1;
		r += w1 + 1;
		r += h1 + h2;
	}
	else{
		r += w1 + 2;
		r += h1 + h2 + 1;
		r += w2 + 1;
		r += h1 + h2;
		r += w1 - w2;
	}

	cout << r << endl;
    return 0;
}