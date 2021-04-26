/*
  Keep track of the state of each 2 by 2 square. That is, which of the 4 tiles needs changing.
  Then, for each of the tiles, try J, O, and I.
  We just need to check how many gets added to the count and how many gets removed from the count.
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

int m, n;
const int N = 1000;
char flag[N][N], emblem[2][2];
bool hasemblem[N][N];
vector<int> misses[N][N];
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> m >> n;
  for (int i = 0; i < m; i++){
    for (int j = 0; j < n; j++){
      cin >> flag[i][j];
    }
  }

  for (int i = 0; i < 2; i++){
    for (int j = 0; j < 2; j++){
      cin >> emblem[i][j];
    }
  }

  int cnt = 0;
  for (int i = 0; i < m-1; i++){
    for (int j = 0; j < n-1; j++){
      bool valid = 1;
      for (int di = 0; di < 2; di++){
        for (int dj = 0; dj < 2; dj++){
          if (emblem[di][dj] != flag[i+di][j+dj]){
            valid = 0;
            misses[i][j].push_back(di*2+dj);
          }
        }
      }
      cnt += valid;
      hasemblem[i][j] = valid;
    }
  }

  int add = 0;
  for (int i = 0; i < m; i++){
    for (int j = 0; j < n; j++){
      for (char c : {'J','O','I'}){
        int tmp = 0;
        for (int di = 0; di < 2; di++){
          for (int dj = 0; dj < 2; dj++){
            int x = i-di;
            int y = j-dj;
            if (x < 0 || x >= m-1 || y < 0 || y >= n-1) continue;
            if (hasemblem[i-di][j-dj]){
              if (c != emblem[di][dj]) {
                tmp--;
              }
            }
            else {
              if (c == emblem[di][dj] && misses[i-di][j-dj].size() == 1 && misses[i-di][j-dj][0] == di*2+dj){
                tmp++;
              }
            }
          }
        }
        add = max(add, tmp);
      }
    }
  }
  cout << cnt + add << endl;
  return 0;
}
