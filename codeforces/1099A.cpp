#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long int ulli;
typedef long long int lli;
typedef unsigned int ui;
typedef vector<int> v_i;
typedef vector<long long int> v_lli;
typedef vector<unsigned int> v_ui;
typedef vector<unsigned long long int> v_ulli;
typedef set<int> s_i;
typedef set<long long int> s_lli;
typedef set<unsigned int> s_ui;
typedef set<unsigned long long int> s_ulli;
typedef unordered_set<int> u_s_i;
typedef unordered_set<long long int> u_s_lli;
typedef unordered_set<unsigned int> u_s_ui;
typedef unordered_set<unsigned long long int> u_s_ulli;

int main() {
 	int w, h, w1, h1, w2, h2;
 	cin >> w >> h;
 	cin >> w1 >> h1;
 	cin >> w2 >> h2;

 	for (int i = h; i >= 0; i -= 1){
 		w += i;
 		if(i == h1)
 			w -= w1;
 		else if(i == h2)
 			w -= w2;
 		if(w < 0)
 			w = 0;
 	}
 	cout << w << endl;
    return 0;
}