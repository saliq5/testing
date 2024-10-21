#include<bits/stdc++.h>

#define inf 1e18
#define pb push_back
#define popb pop_back
#define fi first
#define se second
#define sll set<long long>
#define vll vector<long long>
#define ll long long int
#define pll pair<long long,long long>
#define vp vector<pair<long long,long long>>
#define umpll unordered_map<long long,long long>
#define mpll map<long long>
#define maxpq priority_queue<long long>
#define minpq priority_queue<long long, vector<long long>, greater<long long>>
#define dq deque<long long>
#define qu queue<long long>
#define st stack<long long>
#define ms multiset<long long>
#define usll unordered_set<long long>

#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define take(t) int t; cin>>t;
#define mod 1000000007
#define clr(a,m) memset(a, m, sizeof(a))
#define sz(x) x.size()
#define rep(i,n) for (ll i = 0; i < n; i++)
#define myfor(i, x, y) for (int i = x; i < y; i++)
#define mydec(i, x, y) for (int i = x; i >= y; i--)
#define all(v) v.begin(), v.end()
#define min3(a, b, c) min(a, min(b, c))
#define max3(a, b, c) max(a, max(b, c))
#define haan cout<<"YES"<<endl;
#define nahi cout<<"NO"<<endl;

using namespace std;

class SGT {
    vll seg;
    public:
    SGT(ll n) {
        seg.resize(4*n+1);
    }

    void build(ll ind, ll low, ll high, vll &nums) {
        if (low == high) {
            seg[ind] = nums[low];
            return;
        }
        ll mid = low + (high - low) / 2;
        build(2*ind+1, low, mid, nums);
        build(2*ind+2, mid+1, high, nums);
        seg[ind] = min(seg[2*ind+1], seg[2*ind+2]);
    }

    ll query(ll ind, ll low, ll high, ll l, ll r) {
        if (r < low || high < l) return LLONG_MAX;
        else if (low >= l && high <= r) return seg[ind];
        else {
            ll mid = low + (high - low) / 2;
            ll left = query(2*ind+1, low, mid, l, r);
            ll right = query(2*ind+2, mid+1, high, l, r);
            return min(left, right);
        }
    }

    void update(ll ind, ll low, ll high, ll i, ll val) {
        if (low == high) {
            seg[ind] = val;
            return;
        }
        ll mid = low + (high - low) / 2;
        if (i <= mid) update(2*ind+1, low, mid, i, val);
        else update(2*ind+2, mid+1, high, i, val);
        seg[ind] = min(seg[2*ind+1], seg[2*ind+2]);
    }
};

void solve() {
    cout<<"Hello"<<endl;
}

int main() {
    fastio
    // take(t)
    int t = 1;
    while (t--) solve();
    return 0;
}