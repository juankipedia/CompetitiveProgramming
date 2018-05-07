# Union-Find Disjoint Sets.

Union-Find Disjoint Sets is a data structure to model a collection of disjoint 
sets which has abilities to efficiently.
Find refers to: Find witch set n item belongs to, or test whether two items belong 
to the same set.
Union refers to: Union two Disjoint sets in to a bigger set.

These seemingly simple operations are not efficiently supported by C++ STL 
set which only deals with a single set and C++ STL algorithm’s set union is also 
not efficient enough.

The key ideas of this data structure are like this: Keep a representative 
(‘parent’) item of each set. This information is stored in std::vector pset, 
where pset[i] tells the representative item of the set that contains item i.

## Union Set
When we want to merge two sets, we call unionSet(i, j) which make both items ‘i’ 
and ‘j’ to have the same representative item. This is done by calling 
findSet(j),what is the representative of item ‘j’, and assign that value to
pset[findSet(i)], update the parent of the representative item of item ‘i’.
Lets look at a quick example:

supose that we have following disjoint sets:

![disjoint_set_1](/CodeGym/03/images/disjoint_set_nodes_1.png)

Initially there are 10 subsets and each subset has single element in it. 



When each subset contains only single element, the vector pset is: 

![disjoint_set_1](/CodeGym/03/images/disjoint_set_array_1.png)

if we perform unionSet(2,1), we have:

![disjoint_set_1](/CodeGym/03/images/disjoint_set_nodes_2.png)


and pset looks like:

![disjoint_set_1](/CodeGym/03/images/disjoint_set_array_2.png)


now performing unionSet(4, 3), unionSet(8, 4), unionSet(9, 3):

![disjoint_set_1](/CodeGym/03/images/disjoint_set_nodes_3.png)


for pset:

![disjoint_set_1](/CodeGym/03/images/disjoint_set_array_3.png)


## Find Set
This function recursively calls itself whenever pset[i] is not yet itself (‘i’). 
Then, once it finds the main representative item (e.g. ‘x’) for that set, it will
compress the path by saying pset[i] = x. Thus subsequent calls of findSet(i) will
be O(1). This simple heuristic strategy is aptly named as ‘Path Compression’.
Lets look at a quick example:


## Code
If we implement all theory we have seen above we have following code:

~~~
# include <bits/stdc++.h>
using namespace std;

vector<int> pset(1000);

void initSet(int _size){ 
	pset.resize(_size); 
	for(size_t i = 0; i < size; i++) 
		pset[i] = i; 
}

int findSet(int i){ 
	return (pset[i] == i) ? i : (pset[i] = findSet(pset[i])); 
}

void unionSet(int i, int j){ 
	pset[findSet(i)] = findSet(j); 
}

bool isSameSet(int i, int j){ 
	return findSet(i) == findSet(j); 
}

int main(){

	return 0;
}
~~~