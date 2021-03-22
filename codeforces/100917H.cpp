# include <bits/stdc++.h>
using namespace std;

# define endl "\n"
# define io_boost std::ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
typedef unsigned long long int ulli;
typedef long long int lli;
typedef unsigned int ui;

struct Person{
    string name;
    int day, month, year, k, d;
    
    bool operator<(const Person &p) const{
        if(year < p.year) return true;
        else if(year > p.year) return false;
        if(month < p.month) return true;
        else if(month > p.month) return false;
        if(day < p.day) return true;
        else if(day > p.day) return false;
        if(d < p.d) return true;
        else if(d > p.d) return false;
        return k < p.k;
    }
    
};

struct Department{
    map<int, Person> m;
    set<Person> s;
    int k = 1;
};

struct Office{
    map<int, Department> departments;
    set<Person> all;
};

int n, t;
Office office;

int main(){
    io_boost;
    cin >> n;
    while(n--){
        cin >> t;
        int d;
        if(t == 1){
            string n, bd;
            cin >> d >> n >> bd;
            string vd[3] = {"", "", ""};
            int j = 0;
            for(char c: bd){
                if(c == ':') j++;
                else vd[j] += c;
            }
            Person p;
            p.name = n;
            p.day = stoi(vd[0]);
            p.month = stoi(vd[1]);
            p.year = stoi(vd[2]);
            p.k = office.departments[d].k;
            p.d = d;
            office.departments[d].m[p.k] = p;
            office.departments[d].s.insert(p);
            office.departments[d].k++;
            office.all.insert(p);
        }
        else{
            int k;
            cin >> d >> k;
            Person p = office.departments[d].m[k];
            office.departments[d].m.erase(k);
            office.departments[d].s.erase(p);
            office.all.erase(p);
        }
        if(office.all.empty()) cout << "Vacant" << " ";
        else cout << office.all.begin()->name << " ";
        if(office.departments[d].s.empty()) cout << "Vacant" << endl;
        else cout << office.departments[d].s.begin()->name << endl;
    }
    return 0;
}