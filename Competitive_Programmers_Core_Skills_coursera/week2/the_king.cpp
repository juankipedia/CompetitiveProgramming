using namespace std;
#include <bits/stdc++.h>
int r,c;
int val(int x){
	if(x % 3 == 0 || x % 3 == 1) return (x / 3) * 2;		 	
	else return 1 + (x / 3) * 2;
}
int find(){
	int res = 0;
	int r_ = val(r);
	int c_ = val(c);
	if(r * c == 1) return 0;
	else if(r == 1) return c_;
	else if(c == 1)	return r_;
	else return r_ * c + (r - r_) * c_; 
}
int main(){
	ios_base::sync_with_stdio(false); cin.tie(0);
   	cin >> r >> c;
   	cout << find() << endl;
	return 0;
}