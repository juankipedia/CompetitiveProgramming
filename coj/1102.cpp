# include <bits/stdc++.h>

using namespace std;

int main(){
	string num_c;
	long long int num = 0;
	cin >> num_c;
	while(num_c != "0"){
		num = 0;
		bool sum = true;
	    for (unsigned int i = 0; i < num_c.length(); i++){
	    	if (sum){
	    		num += static_cast<int>(num_c[i]) - 48;
	    		sum = false;
	    	}
	    	else{
	    		num -= (static_cast<int>(num_c[i]) - 48);
	    		sum = true;
	    	}

	    }	   
		if (num % 11)
			cout << num_c + " is not a multiple of 11.\n";
		else
			cout << num_c + " is a multiple of 11.\n";
		cin >> num_c;
	}
	return 0;
}