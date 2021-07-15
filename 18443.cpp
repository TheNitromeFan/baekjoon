#include <iostream>
#include <algorithm>
#include <vector>
#include <memory.h>
using namespace std;
#define ll long long
const ll MX = 105;
const ll INF = 1000000000000000000;
ll dp[MX][MX], a[MX], n, m, L, p[MX], ans = INF;
vector<ll> ansp;
pair<ll, ll> back[MX][MX];
vector<ll> v;
ll cal(ll s, ll e) {
	ll m = (s + e) / 2;
	ll r, l;
	r = p[e] - p[m] - v[m] * (e - m);
	if(s!=0) l = v[m] * (m - s + 1) - (p[m] - p[s-1]);
	else l = v[m] * (m - s + 1) - p[m];
	return r + l;
}
ll sol(ll cur, ll d) {
	if (d < 0) return INF;
	if (cur < 0) {
		if (d == 0) return 0;
		else return INF;
	}
	ll& ret = dp[cur][d];
	if (ret != -1) return ret;
	ret = INF;
	for (int i = d - 1; i <= cur; i++) {
		ll x = sol(i - 1, d - 1) + cal(i, cur);
		if (x < ret) {
			ret = x;
			back[cur][d] = { i - 1,d - 1, };
		}
	}
	return ret;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n >> m >> L;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	for (int i = 0; i < n; i++) {
		v.clear();
		for (int j = 0; j < n; j++) {
			if (i + j >= n) v.push_back(a[(i + j) % n] + L);
			else v.push_back(a[(i + j) % n]);
			if(j!=0) p[j] = p[j - 1] + v[j];
			else p[j] = v[j];
		}
		memset(back, 0, sizeof(back));
		memset(dp, -1, sizeof(dp));
		ll ret = sol(n - 1, m);
		if (ans > ret) {
			ans = ret;
			ansp.clear();
			ll sx = n - 1, sy = m;
			for (int j = 0; j < m; j++) {
				ll cx = back[sx][sy].first;
				ll cy = back[sx][sy].second;
				ll m = (sx + cx + 1) / 2;
				if (v[m] < L) {
					ansp.push_back(v[m]);
				}
				else {
					ansp.push_back(v[m] - L);
				}
				sx = cx;
				sy = cy;
			}
		}
	}
	cout << ans << "\n";
	sort(ansp.begin(), ansp.end());
	for (int i = 0; i < ansp.size(); i++) {
		cout << ansp[i] << " ";
	}
}
