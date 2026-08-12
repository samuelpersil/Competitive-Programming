// Set e Multiset ordenados
// Operações em O(log n)
// https://codeforces.com/blog/entry/123624

// functions:
//      order_of_key(k): Gives the count of elements smaller than k. — O(log n)
//      find_by_order(k): Returns the iterator for the kth element (use k = 0 for the first element). — O(log n)

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

template<class T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template<class T> using ordered_set = tree<T, null_type, greater<T>, rb_tree_tag, tree_order_statistics_node_update>; // descending order
template<class T> using ordered_multiset = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;

// Deletar elemento em multiset
ss.erase(ss.find_by_order(ss.order_of_key(x)));