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
 
int T, tc;
string A, B;
int memo[2001][2001];
int case_memo[2001][2001];
 
int f(int i, int j){
	if(i >= A.length() and j >= B.length()) return 0; // end
	
	if(case_memo[i][j] == tc) return memo[i][j];
	case_memo[i][j] = tc;
	
	//delete from B <=> insert on A
	if(i == A.length()){
		memo[i][j] = 1 + f(i, j + 1);
		return memo[i][j];
	}
 
	//delete from A <=> insert on B
	if(j == B.length()){
		memo[i][j] =  1 + f(i + 1, j); 
		return memo[i][j];
	}
 
	//no operation needed
	if(A[i] == B[j]){
		memo[i][j] = f(i + 1, j + 1); 
		return memo[i][j];
	}
 
	// min between delete from A/insert on B   and    delete from B/insert on A
	memo[i][j] = min(min(1 + f(i + 1, j), 1 + f(i, j + 1)), 1 + f(i + 1, j + 1)); 
	return memo[i][j];
}
 
int main() {
	cin >> T;
	for (tc = 1; tc <= T ; ++tc){
		cin >> A >> B;
		cout << f(0, 0) << endl;
		/*for (int i = 0; i < A.length(); ++i){
			for (int j = 0; j < B.length(); ++j){
				cout << memo[i][j] << " ";
			}
			cout << endl;
		}*/
	}
	return 0;
} 