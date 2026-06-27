//Binary search

//lower_bound(arr, arr + n, x) returns a pointer to the first array element whose value is at least x
//upper_bound(arr, arr + n, x) returns a pointer to the first array element whose value is larger than x.
//equal_range(arr, arr + n, x) returns both above pointers.

//Number of elements whose value is x
auto r = equal_range(array, array+n, x);
cout << r.second-r.first << "\n";

//Data structures

//Remove only one instance of a repeated number in a multiset
multiset<int> s;
s.erase(s.find(x));

//Checks if a key exists in a map
map<string, int> m;
m.count("OI");

//largest element in a set
set<int> s;
auto it = s.end(); it--;
cout << *it << "\n";

//Priority queue min-heap
priority_queue<int,vector<int>,greater<int>> q;