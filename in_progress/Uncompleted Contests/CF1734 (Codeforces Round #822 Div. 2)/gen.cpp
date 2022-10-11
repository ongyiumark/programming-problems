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
  int n = 6;
  int k = rand(1,n);
  cout << 1 << endl;
  cout << n << " " << k << endl;
  for (int i = 1; i <= n; i++) {
    if (i == k) cout << rand(0, 10) << " ";
    else if (rand(0,1) == 1) cout << rand(-10,-1) << " ";
    else cout << rand(1,10) << " ";
  }
  cout << endl;
  
  return 0;
}
