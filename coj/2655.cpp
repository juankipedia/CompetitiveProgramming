# include <bits/stdc++.h>

using namespace std;

int main(){
    std::vector<int> v;
    string w1, w2, w3, w4, w5;
    cin >> w1 >> w2 >> w3 >> w4 >> w5;
    if(w1.find("FBI") != string::npos)
        v.push_back(1);
    if(w2.find("FBI") != string::npos)
        v.push_back(2);
    if(w3.find("FBI") != string::npos)
        v.push_back(3);
    if(w4.find("FBI") != string::npos)
        v.push_back(4);
    if(w5.find("FBI") != string::npos)
        v.push_back(5);
    if(v.size() == 0)
        cout << "HE GOT AWAY!" << endl;
    else{
        for (unsigned int i = 0; i < v.size(); ++i)
            cout << v[i] << " ";
        cout << endl;
    }

    return 0;
}