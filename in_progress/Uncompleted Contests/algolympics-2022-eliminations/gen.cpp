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

  cout << 1 << endl;
  int r = rand(1,10);
  int c = rand(1,10);
  cout << r << " " << c << endl;
  for (int i = 0; i < r; i++) {
    for (int j = 0; j < c; j++){
      int tmp = rand(1,3);
      cout << (tmp == 1 ? '#' : '.');
    }
    cout << endl;
  }
  
  return 0;
}
