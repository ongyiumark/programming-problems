/*
  Just do the Math. There are two edge cases to watch out for:
    1. To check for when the circles do not intersect, just check if the distance between the centers 
    are more than the sum of the radii.
    2. To check if one circle is inside another, just check if r1, r2, and d form a triangle.
  
  Use the fact that r1, r2, and d form a triangle to compute for the angles (cosine law).
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

bool not_triangle(ld a, ld b, ld c) {
  if (a+b <= c) return true;
  if (a+c <= b) return true;
  if (b+c <= a) return true;

  return false; 
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  
  ld x1, y1, r1; cin >> x1 >> y1 >> r1;
  ld x2, y2, r2; cin >> x2 >> y2 >> r2;
  
  ld dd = (x1-x2)*(x1-x2) + (y1-y2)*(y1-y2);

  cout << setprecision(12) << fixed;
  if (dd >= (r1+r2)*(r1+r2)) {
    cout << (ld)0 << endl;
    return 0;
  }

  ld d = sqrtl(dd);

  if (not_triangle(r1, r2, d)){
    cout << acos(-1)*min(r1,r2)*min(r1,r2) << endl;
    return 0;
  }
  
  ld theta1 = 2*acos((r1*r1+dd-r2*r2)/(2*r1*d));
  ld theta2 = 2*acos((r2*r2+dd-r1*r1)/(2*r2*d));

  cout << r1*r1/2*(theta1-sin(theta1)) + r2*r2/2*(theta2-sin(theta2)) << endl;

  return 0;
}
