# include <iostream>
# include <string>
# include <map>
# include <vector>
# include <algorithm>
using namespace std;

class Cmp
{

public: 
	
	map<string, unsigned int> alphabet;
	Cmp() 
	{
		alphabet["a"] = 0;
		alphabet["b"] = 1;
		alphabet["k"] = 2;
		alphabet["d"] = 3;
		alphabet["e"] = 4;
		alphabet["g"] = 5;
		alphabet["h"] = 6;
		alphabet["i"] = 7;
		alphabet["l"] = 8;
		alphabet["m"] = 9;
		alphabet["n"] = 10;
		alphabet["ng"] = 11;
		alphabet["o"] = 12;
		alphabet["p"] = 13;
		alphabet["r"] = 14;
		alphabet["s"] = 15;
		alphabet["t"] = 16;
		alphabet["u"] = 17;
		alphabet["w"] = 18;
		alphabet["y"] = 19;
	}
	
	bool operator()(string w1, string w2) 
	{
		size_t i = 0, j = 0;
		string empty = "";
		while(true)
		{
			if (j + 1 != w2.size() and w2[j] == 'n' and i + 1 != w1.size() and w1[i] == 'n'){
				if(w2[j + 1] == 'g' and w1[i + 1] == 'g'){
					++i;
					++j;
					continue;
				}
			}
			if (j + 1 != w2.size() and w2[j] == 'n'){
				if(w2[j + 1] == 'g'){
					if (alphabet[empty + w2[j] + w2[j + 1]] <
						alphabet[empty + w1[i]]){
						return false;
					}
					else{
						return true;
					}
				}
			}

			if (i + 1 != w1.size() and w1[i] == 'n'){
				if(w1[i + 1] == 'g'){
					if (alphabet[empty + w1[i] + w1[i + 1]] < 
						alphabet[empty + w2[j]]){
						return true;
					}
					else{
						return false;
					}
				}
			}

			if (alphabet[empty + w1[i]] > alphabet[empty + w2[j]]){
				return false;
			}
			else if (alphabet[empty + w1[i]] < alphabet[empty + w2[j]]){
				return true;
			}
			

			++i;
			++j;
			if (i == w1.size() and j != w2.size()){
				return true;
			}
			else if (i != w1.size() and j == w2.size()){
				return false;
			}
			else if (i == w1.size() and j == w2.size()){
				return true;
			}

		}
	}
	
};

int main()
{
	size_t n_words;
	cin >> n_words;
	vector<string> words;

	for (size_t i = 0; i < n_words; ++i)
	 {
	 	string aux;
	 	cin >> aux;
	 	words.push_back(aux);
	 } 

	 Cmp criteria;
	 sort(words.begin(), words.end(), criteria);

	for(auto elem: words)
		cout << elem << ' ';
	return 0;
}