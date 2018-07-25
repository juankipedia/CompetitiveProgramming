# include <bits/stdc++.h>

using namespace std;

int main(){
	short r,l;
	do{
		scanf("%hu %hu", &r, &l);
		if(r + l != 0)
			printf("%hu\n", r + l); 
	}while(r != 0 and l != 0);
	
	return 0;
}