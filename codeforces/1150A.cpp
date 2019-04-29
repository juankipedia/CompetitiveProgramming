#include <bits/stdc++.h>
using namespace std;


int main() {
	int n, m, r;
	cin >> n >> m >> r;
	int min = 1000 + 1, max = 0;
	int s;
	for (int i = 0; i < n; ++i){
		cin >> s;
		if(s < min)
			min = s;
	}

	for (int i = 0; i < m; ++i){
		cin >> s;
		if(s > max)
			max = s;
	}

	if(min > max){
		cout << r << endl;
		return 0;
	}
	int p = r;
	int n_s = r / min; 
	p -= n_s * min;
	//cout << p << endl;
	p += n_s * max;
	cout << p << endl;
    return 0;
}