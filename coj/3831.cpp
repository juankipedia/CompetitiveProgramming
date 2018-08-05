# include <bits/stdc++.h>
using namespace std;

int main (){
	std::ios::sync_with_stdio(false);
	cin.tie(0);
	char e[301];
	cin >> e;
	unsigned int i = 0, sum = 0, mod;
	while(e[i] != '\0'){
		mod = i % 3;
		if (mod == 0){
			if(e[i] != 'P')
				sum ++;
		}
		else if (mod == 1){
			if(e[i] != 'E')
				sum ++;
		}
		else{
			if(e[i] != 'R')
				sum ++;
		}
		i ++;
	}

	cout << sum << endl;

	return 0;
}