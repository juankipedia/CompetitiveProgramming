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
  
void zeller_rule(int day, int month, int year){ 
    if (month == 1){ 
        month = 13; 
        year--; 
    } 
    if (month == 2){ 
        month = 14; 
        year--; 
    } 
    int q = day, m = month, k = year % 100, j = year / 100; 
    int h = q + 13 * (m + 1) / 5 + k + k / 4 + j / 4 + 5 * j; 
    h = h % 7; 
    switch (h){ 
        case 0 : cout << "Saturday\n"; break; 
        case 1 : cout << "Sunday\n"; break; 
        case 2 : cout << "Monday\n"; break; 
        case 3 : cout << "Tuesday\n"; break; 
        case 4 : cout << "Wednesday\n"; break; 
        case 5 : cout << "Thursday\n"; break; 
        case 6 : cout << "Friday\n"; break; 
    } 
    return; 
} 

int main(){
    int n;
    cin >> n; 
    zeller_rule(22, 9, 1867 + n);
return 0; 
} 