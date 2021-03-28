#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

template <typename T>
using ordered_set = __gnu_pbds::tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;

const int N = 20;
int s[N+1];
int p[N+1][3], taken_p[3];
int f;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t; cin >> t;
    while(t--){
        cin >> f;
        for (int i = 1; i <= f; i++) cin >> s[i];
        for (int i = 0; i <= f; i++){
            for (int j = 0; j < 3; j++){
                cin >> p[i][j];
            }
        }

        memset(taken_p, 0, sizeof taken_p);
        int cnt = 0;
        for (int i = 1; i <= f; i++){
            int x = min(p[i][0], s[i]);
            s[i] -= x;
            taken_p[0] += x;
            cnt += x; 

            x = min(p[i][1], s[i]/3);
            s[i] -= 3*x;
            taken_p[1] += x;
            cnt += x;
            
            x = min(p[i][2], s[i]/6);
            s[i] -= 6*x;
            taken_p[2] += x;
            cnt += x;
        }

        int extra = 0;
        for (int i = 1; i <= f; i++){
            extra += s[i];
        }

        int x = min(p[0][0], extra);
        extra -= x;
        p[0][0] -= x;
        cnt += x;
        x = min(p[0][1], extra/3);
        extra -= 3*x;
        p[0][1] -= x;
        cnt += x;
        x = min(p[0][2], extra/6);
        extra -= 6*x;
        p[0][2] -= x;
        cnt += x;

        int y = min(taken_p[2], (p[0][0]+5)/6);
        cnt -= y;
        extra += 6*y;
        taken_p[2] -= y;
        x = min(p[0][0], extra);
        extra -= x;
        p[0][0] -= x;
        cnt += x;

        y = min(taken_p[1], (p[0][0]+2)/3);
        cnt -= y;
        extra += 3*y;
        taken_p[1] -= y;
        x = min(p[0][0], extra);
        extra -= x;
        p[0][0] -= x;
        cnt += x;
        
        x = min(p[0][0], extra);
        extra -= x;
        p[0][0] -= x;
        cnt += x;
        x = min(p[0][1], extra/3);
        extra -= 3*x;
        p[0][1] -= x;
        cnt += x;
        x = min(p[0][2], extra/6);
        extra -= 6*x;
        p[0][2] -= x;
        cnt += x;

        y = min(taken_p[2], max((3*p[0][1]-extra+5)/6, 0));
        cnt -= y;
        extra += 6*y;
        taken_p[2] -= y;
        x = min(p[0][1], extra/3);
        extra -= 3*x;
        p[0][1] -= x;
        cnt += x;

        x = min(p[0][0], extra);
        extra -= x;
        p[0][0] -= x;
        cnt += x;
        x = min(p[0][1], extra/3);
        extra -= 3*x;
        p[0][1] -= x;
        cnt += x;
        x = min(p[0][2], extra/6);
        extra -= 6*x;
        p[0][2] -= x;
        cnt += x;
        
        cout << cnt << endl;
    }
    return 0;
}