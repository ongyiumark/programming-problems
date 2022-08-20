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
  
  int n = rand(2,10);
  int a[n];
  for (int i = 0; i < n; i++) a[i] = rand(1,10);
  cout << n << endl;
  for (int i = 0; i < n; i++) {
    cout << a[i];
    if (i == n-1) cout << endl;
    else cout << " ";
  }

  return 0;
}
