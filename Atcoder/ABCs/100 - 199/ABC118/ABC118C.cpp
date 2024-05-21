/*
  The answer is the gcd of the list of healths.
  This is because if d | a and d | b, then d | (a-b).

  If gcd(a,b) = d, then we can always reduce one of them to 1.
  This is because of Bezout's lemma: ax + by = d.

  Notice that when a attacks b, we have (a, b-a).
  Then, if b attacks a, we have (2a-b, b-a), and so on.
*/
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<int,pair<int,int>> piii;

template <typename T>
using ordered_set = __gnu_pbds::tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

const int N = 1e5+5;
int A[N];

int gcd(int a, int b){
  if (b == 0) return a;
  return gcd(b, a%b);
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n; cin >> n;

  int g = 0;
  for (int i = 0; i < n; i++){
    cin >> A[i];
    g = gcd(g, A[i]);
  }  

  cout << g << endl;

  return 0;
}
