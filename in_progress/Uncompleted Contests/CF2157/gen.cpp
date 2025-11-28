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

int rand(int a, int b){
  return a + rand() % (b-a+1);
}

int main(int argc, char* argv[]){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  srand(atoi(argv[1]));
  
  cout << 1 << "\n";
  int n = rand(3,10);
  int k = rand(1,n-2);
  int q = rand(1,5);
  cout << n << " " << k << " " << q << "\n";
  for (int i = 0; i < q; i++) {
    int c = 2;
    int l = rand(1,n-k);
    int r = rand(l+k-1,n);
    cout << c << " " << l << " " << r << "\n";
  }

  
  return 0;
}
