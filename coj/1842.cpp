# include <bits/stdc++.h>
using namespace std;

unsigned int abs(const int &a, const int &b){
	if(a - b < 0)
		return (a - b) * (-1);
	else
		return a - b;
}

int main(){
	unsigned int n;
	int x1, y1, x2, y2;
	scanf("%u", &n);
	while(n--){
		scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
		printf("%u\n", abs(x1, x2) + abs (y1,y2));
	}
	return 0;
}