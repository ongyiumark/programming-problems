#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;

template <typename T>
using ordered_set = __gnu_pbds::tree<T,null_type, less<T>,rb_tree_tag, tree_order_statistics_node_update>;

int n, m;

void testcase(){
    cin >> n >> m;
    //cout << n <<" " << m << endl;
    vector<int> S(m, 0);
    vector<int> cnts(m, 0);
    vector<vector<int>> P(n, vector<int>(m, 0));
    for (int i = 0; i < m; i++){
        cin >> S[i];
        //cout << S[i] << " ";
    }
    //cout << endl;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            cin >> P[i][j];
            //cout << P[i][j] << " ";
        }
        //cout << endl;
    }

    for (int i = 0; i < n; i++){
        map<int, vector<pair<int,int>>> currclothes;
        map<int, int> curridx;
        for (int k = 0; k < m; k++){
            currclothes[S[k]].push_back({cnts[k], k});
        }

        for (auto it : currclothes){
            if (currclothes[it.first].size() == 0) continue;
            sort(currclothes[it.first].begin(),currclothes[it.first].end(), greater<pair<int,int>>());
        }

        vector<int> need;
        vector<bool> used(m, 0);

        for (int j = 0; j < m; j++){
            if (currclothes[P[i][j]].size() == curridx[P[i][j]]) {
                need.push_back(P[i][j]);
            }
            else {
                int idx = currclothes[P[i][j]][curridx[P[i][j]]].second;
                curridx[P[i][j]]++;
                used[idx] = 1;
            }
        }

        
        int j = 0;
        for (int k = 0; k < (int)need.size(); k++){
            while(used[j]){
                j++;
            }
            //currclothes[S[idx]].pop();
            S[j] = need[k];
            cnts[j]++;
            used[j] = 1;
        }

    }

    int cnt = 0;
    for (int i = 0; i < m; i++){
        cnt += max(cnts[i]-1, 0);
    }
    cout << cnt << endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin >> t;
    for (int x = 1; x <= t; x++){
        cout << "Case #" << x << ": ";
        testcase();
    }
    return 0;
}