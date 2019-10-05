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

int t, H1, M1, S1, H2, M2, S2;

int main() {
	cin >> t;
	while(t--){
		cin >> H1 >> M1 >> S1 >> H2 >> M2 >> S2;

		if(H1 < H2){
			cout << "Player1" << endl;
			continue;
		}
		else if(H2 < H1){
			cout << "Player2" << endl;
			continue;
		}
		else if(M1 < M2){
			cout << "Player1" << endl;
			continue;
		}
		else if(M2 < M1){
			cout << "Player2" << endl;
			continue;
		}
		else if(S1 < S2){
			cout << "Player1" << endl;
			continue;
		}
		else if(S2 < S1){
			cout << "Player2" << endl;
			continue;
		}
		else{
			cout << "Tie" << endl;
			continue;
		}
	}
}