#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll,ll> ii;
typedef pair<ii, int> iii;


// see http://www.boost.org/doc/libs/1_35_0/doc/html/hash/combine.html template 
template < typename T> 
inline  void  hash_combine(size_t &seed, const T &val)  { 
  seed ^= hash<T>()(val) + 0x9e3779b9 + (seed << 6 ) + (seed >> 2 ); 
} 
// auxiliary generic functions to create a hash value using a seed 
template < typename T> 
inline  void  hash_val (size_t &seed, const T &val)  { 
  hash_combine(seed, val); 
} 
template < typename T, typename ...Types> 
inline void hash_val(size_t &seed, const T &val, const Types& ...args) { 
  hash_combine(seed, val); 
  hash_val (seed, args...); 
}

template <typename ... Types> 
inline size_t  hash_val(const Types &... args) { 
  size_t seed = 0; 
  hash_val (seed, args...); 
  return seed;
}

struct pair_hash { 
  template < class T1 ,class T2> 
  size_t operator () (const std::pair<T1, T2> &p) const { 
    return hash_val(p.first, p.second);     
  }
};
      
       
vector<ii> points;

ll gcd(ll a, ll b) {
  if (b == 0) return a;
  return gcd(b, a%b);
}

ii simplify(ll a, ll b) {
  ll g = gcd(a, b);
  a /= g;
  b /= g;
  if (b < 0) {
    a *= -1;
    b *= -1;
  }
  return {a, b};
}

ll solve(vector<ii> &p, int pivot) {
  unordered_map<ii, ll, pair_hash> slope_count;
  ll ans = 2;
  int n = p.size();

  auto &[x, y] = p[pivot];
  for (int i = 0; i < n; i++) {
    if (i == pivot) continue;
    auto &[x1, y1] = p[i];
    ll a = y1-y;
    ll b = x1-x;

    ii simplified = simplify(a, b);
    slope_count[simplified] += 1;
    ans = max(slope_count[simplified]+1, ans);
  }

  return ans;
}

void testcase() {
  int n; cin >> n;
  points.resize(n);
  for (auto &[x, y]: points) cin >> x >> y;
  vector<int> indices;
  iota(indices.begin(), indices.end(), 0);
  random_shuffle(indices.begin(), indices.end());

  ll best = 2;
  for (int i = 0; i < min(n, 50); i++) {
    best = max(best, solve(points, i));
  }
  cout << n-best << "\n";
}

void main_() {
  cin.tie(0)->sync_with_stdio(false);
  int T; cin >> T;
  for (int t = 1; t <= T; t++){
    cout << "Case #" << t << ": ";
    testcase();
  }
}

static void run_with_stack_size(void (*func)(void), size_t stsize) {
  char *stack, *send;
  stack = (char *)malloc(stsize);
  send = stack + stsize - 16;
  send = (char *)((uintptr_t)send / 16 * 16);
  asm volatile(
    "mov %%rsp, (%0)\n"
    "mov %0, %%rsp\n"
    :
    : "r"(send));
  func();
  asm volatile("mov (%0), %%rsp\n" : : "r"(send));
  free(stack);
}

int main() {
  run_with_stack_size(main_, 1024 * 1024 * 1024); // run with a 1 GiB stack
  return 0;
}