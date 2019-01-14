#include <bits/stdc++.h>
using namespace std;

int main() {
	unsigned int a, b, c, d;
	cin >> a >> b >> c >> d;
	unsigned short count = 0;
	double max = a/b + c/d;
	if(c/a + d/b > max){max = c/a + d/b; count = 1;};
	if(d/c + b/a > max){max = d/c + b/a; count = 2;};
	if(b/d + a/c > max){max = b/d + a/c; count = 3;};
	cout << count << endl;
    return 0;
}