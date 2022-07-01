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

int rand(int a, int b){
  return a + rand() % (b-a+1);
}

int main(int argc, char* argv[]){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  srand(atoi(argv[1]));
  
  int n = rand(1,4);
  int perms = 1;
  for (int i = 1; i <= 2*n; i++) perms *= i;
  int rnd_perm = rand(0,perms-1);
  cout << 2*n << endl;
  vector<int> res(2*n);
  iota(res.begin(), res.end(), 1);
  while(rnd_perm--) next_permutation(res.begin(), res.end());
  for (int i = 0; i < 2*n; i++) {
    cout << res[i];
    if (i != 2*n-1) cout << " ";
    else cout << endl;
  }
  return 0;
}
