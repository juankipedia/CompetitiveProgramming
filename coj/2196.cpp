# include <bits/stdc++.h>
using namespace std;
int main () {
	unsigned int n;
	string i;
	cin >> n;

	for (unsigned int j = 0; j < n; ++j){
		cin >> i;
		if(((((unsigned int )i[i.length() - 1]) - ((unsigned int )'0'))  & 1) == 0)
	    	printf("even\n");
		else
	    	printf("odd\n");		
	}	
	return 0;
}