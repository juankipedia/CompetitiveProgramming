# include <bits/stdc++.h>
using namespace std;

const char * numbers[12] = {"one", "two", "three", "four", "five", "six", "seven" , "eight", "nine", "ten", "eleven", "twelve"};

int main(){
	std::ios::sync_with_stdio(false);
	cin.tie(0);
	unsigned int t, n;
	cin >> t;
	while(t --){
		cin >> n;
		cout << numbers[n - 1] << "\n";
	}
	return 0;
}