#include <bits/stdc++.h>
using namespace std;
 
# define endl "\n"
# define io_boost std::ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
typedef unsigned long long int ulli;
typedef long long int lli;
typedef unsigned int ui;
 
int t;
string w;

int main()
{
    string s_inp, s = "";
    getline(cin, s_inp);
    for (int i = 0; i < (int) s_inp.size(); i++) {
        if (s_inp[i] == '.') {
            s += " 1 ";
        } else if (s_inp[i] == ',') {
            s += " 2 ";
        } else if (s_inp[i] == '?') {
            s += " 3 ";
        } else if (s_inp[i] == '!') {
            s += " 4 ";
        } else {
            s += s_inp[i];
        }
    }
 
    stringstream ss(s);
    string sout = "";
 
    bool first = true;
    while(ss >> s) {
        if (s == "1") sout += ".";
        else if (s == "2") sout += ",";
        else if (s == "3") sout += "?";
        else if (s == "4") sout += "!";
        else {
            if (first) {
                first = false;
            } else {
                sout += " ";
            }
            sout += s;
        }
    }
 
    cout << sout;
    return 0;
}