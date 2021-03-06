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

unordered_map<int, int> T;

int main() {
	int n;
	cin >> n;
	int a[n];
	for (int i = 0; i < n; ++i) cin >> a[i];

    for (int i = 0; i < n; ++i){
    	T[i] = 1;
        for (int j = 0; j < i; ++j) if (a[j] < a[i] and T[i] < T[j] + 1) T[i] = T[j] + 1;
    }
    
	int max = T[0];
	for (int i = 1; i < n; ++i) if(T[i] > max) max = T[i];
    cout << max << endl;
    return 0;
}