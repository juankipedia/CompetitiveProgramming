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



int main(){
    int t, u;
    string m;

    pair<int, string> vec[(int)1e4];
    set<char> s;
    cin >> t;

    m.reserve(10);

    for (int i{1}; i <= t; ++i)
    {
        cout << "Case #" << i << ": ";

        m.clear();
        s.clear();

        m.resize(10);

        cin >> u;

        for (int j{0}; j < 1e4; ++j)
            cin >> vec[j].first >> vec[j].second;
        sort(vec, vec + (int)1e4);


        for (int j{0}; j < 1e4; ++j){
            if (vec[j].first <= 9){
                if (m.find(vec[j].second[0]) == -1)
                    m[vec[j].first] = vec[j].second[0];
                s.insert(m[vec[j].first]);
            }
        }

        for (int j{0}; j < 1e4; ++j){
            for (const char &c : vec[j].second){
                if (s.find(c) == s.end()){
                    m[0] = c;
                    break;
                }
            }
            if (m[0])
                break;
        }

        cout << m << "\n";
    }

    return 0;
}