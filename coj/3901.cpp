# include <bits/stdc++.h>
using namespace std;

unsigned int abs(const int & a, const int & b){
	if (a - b < 0)
		return (a - b) * (-1);
	else
		return a - b;

}

int main(){
	int x1, y1, x2, y2, x3, y3, x4, y4;
	unsigned int w,h;
	scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
	scanf("%d %d %d %d", &x3, &y3, &x4, &y4);
	scanf("%u %u", &w, &h);

	if(abs(y3, y1) >= h or abs(y2, y4) >= h){
 		if(w <= abs(x2, x1)){
 			printf("%s\n", "Yes");
 			return 0;
 		}
 		else{
 			printf("%s\n", "No");
 			return 0;
 		}
 	}

 	else if(abs(x3, x1) >= w or abs(x2, x4) >= w){
 		if(h <= abs(y2, y1)){
 			printf("%s\n", "Yes");
 			return 0;
 		}
 		else{
 			printf("%s\n", "No");
 			return 0;
 		}
 	}
 	printf("%s\n", "No");
	return 0;
}