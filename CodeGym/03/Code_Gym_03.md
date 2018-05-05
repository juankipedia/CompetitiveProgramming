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


## Find Set
This function recursively calls itself whenever pset[i] is not yet itself (‘i’). 
Then, once it finds the main representative item (e.g. ‘x’) for that set, it will
compress the path by saying pset[i] = x. Thus subsequent calls of findSet(i) will
be O(1). This simple heuristic strategy is aptly named as ‘Path Compression’.
Lets look at a quick example:

