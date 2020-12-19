#include<bits/stdc++.h>
using namespace std;
 
int n;
 
int main() {
	scanf("%d",&n);
	int a=n/2, b=(n+1)/2, ans=(a+1)*(b+1);
	if(n&1) ans*=2;
	cout<<ans; return 0;
}
