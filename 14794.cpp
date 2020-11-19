#include <iostream>
#include <algorithm>
#include <map>
#include <iterator>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin >> t;
	for(int i = 1; i <= t; ++i){
		long long k, n;
		cin >> n >> k;
		map<long long, long long> spaces;
		spaces[n] = 1;
		long long ls = -1, rs = -1;
		while(k > 0){
			map<long long, long long>::iterator it = prev(spaces.end());
			long long size = it->first, count = it->second;
			spaces.erase(it);
			ls = (size - 1) / 2;
			rs = size / 2;
			spaces[ls] += count;
			spaces[rs] += count;
			k -= count;
		}
		cout << "Case #" << i << ": " << max(ls, rs) << " " << min(ls, rs) << "\n";
	}
	return 0;
}
