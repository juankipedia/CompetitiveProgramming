    #include <bits/stdc++.h>
    using namespace std;
     
    # define endl "\n"
     
     
     
    int a[4];
     
    int main() {
    vector<int> v(4);
      for (int &i : v)
        cin >> i;
     
      int aux{0}, aux2{v[0] + v[1] + v[2] + v[3]};
     
      for (size_t i{0}; i < 4; ++i)
      {
        aux += v[i];
        aux2 -= v[i];
     
        if (aux == aux2)
        {
          cout << "YES" << endl;
          return 0;
        }
     
        aux -= v[i];
        aux2 += v[i];
      }
     
      if (v[0] + v[1] == v[2] + v[3] || v[0] + v[2] == v[1] + v[3] || v[0] + v[3] == v[1] + v[2])
      {
        cout << "YES" << endl;
        return 0;
      }
     
      cout << "NO" << endl;
      return 0;
    }