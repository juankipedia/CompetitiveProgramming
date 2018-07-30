# include <bits/stdc++.h>
using namespace std;

int main(){
	unsigned int n;
	unsigned int s[3] = {0};
	unsigned int pizzas = 1;

	scanf("%u", &n);

	while(n --){
		char actual_s[4];
		scanf("%s", actual_s);
		if (actual_s[0] == '3'){
			s[0]++;
		}
		else if(actual_s[2] == '2'){
			s[1]++;
		}
		else{
			s[2]++;
		}
		
	}

	pizzas += (s[1] / 2) + s[0];
	unsigned int q = s[0];
	if(s[1] % 2){
		q += 2;
		pizzas += 1;
	}

	if (q >= s[2])
		printf("%u\n", pizzas);
	else{
		pizzas += (s[2] - q)/4;
		if ((s[2] - q) % 4){
			pizzas += 1;
		}
		printf("%u\n", pizzas);

	}

	return 0;
}