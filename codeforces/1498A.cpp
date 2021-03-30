# include <bits/stdc++.h>
using namespace std;

size_t gcd(size_t a, size_t b){
	if(b == 0) return a;
	return gcd(b, a % b);
}

int main(){
    size_t n;
    int t;
    cin >> t;
    while(t--){
        cin >> n;
        string ns = to_string(n);
        size_t sum = 0;
        for(int i =0; i < ns.size(); i++){
            sum += ns[i] - '0';
        }
        while(gcd(sum, n) == 1){
            n++;
            ns = to_string(n);
            sum = 0;
        for(int i =0; i < ns.size(); i++){
            sum += ns[i] - '0';
        }
        }
        cout << n << endl;
    }
    return 0;
}