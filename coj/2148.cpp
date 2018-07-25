# include <iostream>
using namespace std;

int main(){
	unsigned int n; 
	float a, b, c;
	scanf("%u", &n);
	while(n --){
		scanf("%f %f %f", &a, &b, &c);
		if ( b * b - 4 * a * c < 0)
			printf("%s\n", "NO");
		else
			printf("%s\n", "SI");
	}
	return 0;
}