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

  int n = rand(2,5);
  vector<int> primes = {2,5,7,11,13};
  int p = primes[rand(0,4)];
  string s;
  for (int i = 0; i < n; i++) {
    if (i == 0) s.append(1, rand(1,9)+'0');
    else s.append(1, rand(0,9)+'0');
  }
  cout << n << " " << p << endl;
  cout << s << endl;
  
  return 0;
}
