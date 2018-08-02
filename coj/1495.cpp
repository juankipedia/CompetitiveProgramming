# include <bits/stdc++.h>
using namespace std;

int main(){
	std::ios::sync_with_stdio(false);
	unsigned int n;
	cin >> n;
	unsigned int numbers[n], i = n;
	while(i --)
		cin >> numbers[i];
	sort(numbers, numbers + n);
	for (i = 0; i < n ; ++i)
		cout << numbers[i] << endl;

	return 0;
}