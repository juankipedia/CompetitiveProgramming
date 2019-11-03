#include <bits/stdc++.h>
using namespace std;

# define endl "\n"
# define io_boost std::ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
typedef unsigned long long int ulli;
typedef long long int lli;
typedef unsigned int ui;
typedef vector<int> vector_i;
typedef vector<long long int> vector_lli;
typedef vector<unsigned int> vector_ui;
typedef vector<unsigned long long int> vector_ulli;
typedef set<int> set_i;
typedef set<long long int> set_lli;
typedef set<unsigned int> set_ui;
typedef set<unsigned long long int> set_ulli;
typedef unordered_set<int> u_set_i;
typedef unordered_set<long long int> u_set_lli;
typedef unordered_set<unsigned int> u_set_ui;
typedef unordered_set<unsigned long long int> u_set_ulli;


int n, nums[200000], a, b;
int main(){
	cin >> n;
	if(n % 2 != 0){
		for(int i = 0; i < n; i++){
			a = (2 * i) + 1;
			b = (2 * i) + 2;
			if(i % 2 == 0){
				nums[i + n] = b;
				nums[i] = a;		
			}
			else{
				nums[i + n] = a;
				nums[i] = b;
			}
		}
		cout << "YES" << endl;
		for(int i = 0; i < 2 * n; i++) cout << nums[i] << " "; cout << endl;
	}
	else cout << "NO" << endl;
}