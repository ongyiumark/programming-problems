/*
  Let A be the sum of a's and B be the sum of b's
  Notice that the sum of the first column is 3b_1 + A.
  The sum of the second column is 3b_2 + A.
  The sum of the third column is 3b_3 + A.

  Finally, the sum of all the cells is 3(A+B).
  Thus, if we know A, we can determine the all of the cells.
  
  Add all the cells, divide by 3, and try all possible combinations of A and B.
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

int c[3][3];

bool valid(int a, int b){
  int bsum = 0;
  for (int j = 0; j < 3; j++){
    int col_sum = 0;
    for (int i = 0; i < 3; i++){
      col_sum += c[i][j];
    }
    col_sum -= a;
    if (col_sum%3 != 0) return false;
    bsum += col_sum/3;
  }
  return bsum == b;
}
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  
  int total = 0;
  for (int i = 0; i < 3; i++){
    for (int j = 0; j < 3; j++){
      cin >> c[i][j];
      total += c[i][j];
    }
  }

  if (total%3 != 0) {
    cout << "No" << endl;
    return 0;
  }
  total/=3;

  
  for (int a = 0; a <= total; a++){
    int b = total-a;
    if (valid(a,b)){
      cout << "Yes" << endl;
      return 0;
    }
  }

  cout << "No" << endl;
  return 0;
}
