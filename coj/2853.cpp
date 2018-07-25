# include <bits/stdc++.h>
using namespace std;
# define SQUARE2 1.414213562373095048801688724
int main(){
	float l;
	do{
		scanf("%f", &l);
		if(l != 0)
			printf("%.3lf\n", (2 * (SQUARE2 - 1) * l * l));
	}while(l != 0);
	return 0;
}