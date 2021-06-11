#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	unsigned n, k;
	cin >> n >> k;
	n *= 3;
	vector<string> v;
	unordered_map<string, int> cnt;
	unordered_map<string, unsigned> last;
	string s;
	getline(cin, s);
	for(unsigned i = 0; i < n; ++i){
		getline(cin, s);
		if(cnt[s] == 0){
			v.push_back(s);
		}
		++cnt[s];
		last[s] = i;
	}
	sort(v.begin(), v.end(), [&cnt, &last](string s, string t){
		return cnt[s] > cnt[t]
		|| (cnt[s] == cnt[t] && last[s] > last[t]);
	});
	for(unsigned idx = 0; idx < v.size() && idx < k; ++idx){
		cout << v[idx] << '\n';
	}
	return 0;
}
