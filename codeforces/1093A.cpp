#include <bits/stdc++.h>
using namespace std;

int main() {
    long long unsigned int n;
    cin >> n;
    long long unsigned int b[n / 2 + 1], a[n + 1];
    for(long long unsigned int i = 1; i <= n / 2; i++)
        cin >> b[i];

    a[n/2] = b[n / 2] / 2;
    a[n/2 + 1] = (b[n / 2 ] + 1) / 2;

    for (long long unsigned int i = n / 2; i >= 1; i--){
    	a[i] = a[i + 1];
    	a[n - i + 1] = b[i] - a[i];
    	if(a[n - i + 1] < a[n - i]){
    		a[n - i + 1] = a[n - i];
    		a[i] = b[i] - a[n - i + 1];
    	}
    }

    for(long long unsigned int i = 1; i <= n; i++)
        cout << a[i] << " ";
    cout << endl;
    return 0;
}