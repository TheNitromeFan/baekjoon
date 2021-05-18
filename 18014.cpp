#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;
using pii = pair<int, ll>;
int n, m;
vector<pii> vn, vm, ans;

void append(const pii &poi) {
	if (ans.size() && ans.back().first == poi.first) {
		ans.back().second += poi.second;
	} else {
		ans.push_back(poi);
	}
}

void solve() {
	vn.clear();
	vm.clear();
	ans.clear();
	cin >> n;
	pii poi;
	for (int i=1; i<=n; i++) {
		cin >> poi.second >> poi.first;
		vn.push_back(poi);
	}
	cin >> m;
	for (int i=1; i<=m; i++) {
		cin >> poi.second >> poi.first;
		vm.push_back(poi);
	}
	reverse(vn.begin(), vn.end());
	reverse(vm.begin(), vm.end());
	int pn = 0, pm = 0;
	bool carryon = 0;
	pii poin, poim;
	while (pn < vn.size() || pm < vm.size() || poin.second || poim.second) {
		if (!poin.second) poin = pn < vn.size() ? vn[pn++] : pii(0, 0);
		if (!poim.second) poim = pm < vm.size() ? vm[pm++] : pii(0, 0);
		if (!poin.second) poin.second = poim.second;
		if (!poim.second) poim.second = poin.second;
		ll len = min(poin.second, poim.second);
		int firstDigit = poin.first + poim.first + carryon;
		bool newcarryon = firstDigit >= 10;
		// printf("(%d %d) (%d %d) %d %d\n", poin.first, poin.second, poim.first, poim.second, carryon, newcarryon);
		if (carryon) {
			if (newcarryon) {
				append(pii(firstDigit - 10, len));
			} else {
				append(pii(firstDigit, 1));
				if (len > 1)
					append(pii(firstDigit - 1, len - 1));
			}
		} else {
			if (newcarryon) {
				append(pii(firstDigit - 10, 1));
				if (len > 1)
					append(pii(firstDigit - 9, len - 1));
			} else {
				append(pii(firstDigit, len));
			}
		}
		carryon = newcarryon;
		poin.second -= len;
		poim.second -= len;
	}
	if (carryon) {
		append(pii(1, 1));
	}
	reverse(ans.begin(), ans.end());
	cout << ans.size() << endl;
	for (auto &i: ans) {
		cout << i.second << " " << i.first << endl;
	}
}

int main() {
	int tt;
	scanf("%d", &tt);
	for (int i=1; i<=tt; i++) {
		printf("Data Set %d:\n", i);
		solve();
		puts("");
	}
	return 0;
}
