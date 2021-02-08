/*
  Notice that the enclosing circle must intersect either 2 or 3 points.
  If it intersects 2 points, then the center is the midpoint.
  If it intersects 3 points, then the center is the circumcenter.
    I found a formula for this with a lot of algebra.

  For all n^3 triples, find the circumcenter and try to include all points.
  Be careful of precision errors. For equality checks, abs(a-b) <= EPS = 1e-10.
  Be careful with 3 collinear points. These three points cannot form a circle. 
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

const int N = 50;
const ld EPS = 1e-10;
struct point{
  ld x, y;
};

point p[N];
int n;

bool collinear(point a, point b, point c){
  return abs((c.x-b.x)*(b.y-a.y)-(b.x-a.x)*(c.y-b.y)) <= EPS;
}

point circumcenter(point a, point b, point c){
  if (abs(b.y-a.y) <= EPS) swap(b,c);
  ld num = (a.x-b.x)*(a.x+b.x)*(c.y-b.y) - (b.x-c.x)*(b.x+c.x)*(b.y-a.y) + (c.y-a.y)*(b.y-a.y)*(c.y-b.y);
  ld den = 2*((a.x-b.x)*(c.y-b.y) - (b.x-c.x)*(b.y-a.y));
  ld x = num/den;
  ld y = (a.x-b.x)/(b.y-a.y)*(x-(a.x+b.x)/2) + (a.y+b.y)/2;
  return {x,y};
}

ld d2(point a, point b){
  ld dx = a.x-b.x;
  ld dy = a.y-b.y;
  return dx*dx + dy*dy;
}

ld radius(point center){
  ld r2 = 0;
  for (int i = 0; i < n; i++) r2 = max(d2(center, p[i]),r2);
  return r2;
}

point midpoint(point a, point b){
  return {(a.x+b.x)/2, (a.y+b.y)/2};
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  
  cin >> n;
  for (int i = 0; i < n; i++){
    cin >> p[i].x >> p[i].y;
  }

  ld ans = 1e9;
  for (int i = 0; i < n; i++){
    for (int j = i+1; j < n; j++){
      for (int k = j+1; k < n; k++){
        if (collinear(p[i], p[j], p[k])) continue;
        point center = circumcenter(p[i], p[j], p[k]);
        ld r2 = radius(circumcenter(p[i], p[j], p[k]));
        ans = min(ans, r2);
      }
    }
  }

  for (int i = 0; i < n; i++){
    for (int j = i+1; j < n; j++){
      ld r2 = radius(midpoint(p[i], p[j]));
      ans = min(ans, r2);  
    }
  }
  cout << setprecision(10) << fixed;
  cout << sqrtl(ans) << endl;
  return 0;
}
