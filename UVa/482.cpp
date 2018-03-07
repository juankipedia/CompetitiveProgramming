# include <bits/stdc++.h>

using namespace std;

int main(){

	unsigned int n;
	cin >> n;
	vector<string> r;
	for (int i = 0; i < n; ++i)
	{
		getchar();
		char temp;
		unsigned int i_aux;
		string e_aux;
		vector<unsigned int> index;

	    do{
	        scanf("%d%c", &i_aux, &temp); 
	        index.push_back(i_aux);
	    } while(temp!= '\n');

	    string l[index.size()];

	    for (unsigned int i = 0; i < index.size(); ++i){
	        	cin >> e_aux;
	        	l[index[i] - 1] = e_aux;
	    }    

		
	    for (int i = 0; i < index.size(); ++i)
	    	r.push_back(l[i] + "\n");
	   
	   	if (i + 1 != n)
	    	r.push_back("\n");
	}

	for (unsigned int i = 0; i < r.size(); ++i)
		cout << r[i];

	return 0;
}