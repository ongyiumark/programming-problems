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
  return a + rand()%(b-a+1);
}
int main(int argc, char* argv[]){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  
  srand(atoi(argv[1]));
  int t = 1;
  cout << t << endl;
  int r,c;
  do {
    r = rand(1,10);
    c = rand(1,10);
  } while(r*c > 5000 || r*c < 2);
  int k = rand(1,5);
  cout << r << " " << c << " " << k << endl;
  int si, sj, ti, tj;
  si = rand(0,r-1);
  sj = rand(0,c-1);
  do {
    ti = rand(0,r-1);
    tj = rand(0,c-1);
  } while(ti == si && sj == tj);

  string cells = ".#D";
  for (int i = 0; i < r; i++){
    for (int j = 0; j < c; j++){
      if (i == si && j == sj) cout << 'A';
      else if (i == ti && j == tj) cout << 'B';
      else {
        int x = rand(0,100);
        if (x < 10) cout << cells[1];
        else if (x < 50) cout << cells[2];
        else cout << cells[0];
      }
    }
    cout << endl;
  }
  return 0;
}
