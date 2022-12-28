#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef pair<int,pair<int,int>> iii;

template <typename T>
using ordered_set = __gnu_pbds::tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

// Hash tuples/pairs
struct key_hash {
  template<class T>
  void hash_combine(size_t &seed, T const& v) const {
    seed ^= hash<T>()(v) + 0x9e3779b9 + (seed<<6) + (seed>>2);
  }

  size_t operator()(const tuple<int,int> &k) const {
    size_t seed = 0;
    hash_combine(seed, get<0>(k));
    hash_combine(seed, get<1>(k));

    return seed;
  }
};

