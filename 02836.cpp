#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	long long m;
	cin >> n >> m;
	vector<long long> a, b;
	for(int i = 0; i < n; ++i){
		long long x, y;
		cin >> x >> y;
		if(x > y){
			a.push_back(y);
			b.push_back(x);
		}
	}
	sort(a.begin(), a.end());
	sort(b.begin(), b.end());
	unsigned i = 0, j = 0;
	long long pos = -1;
	int line = 0;
	long long ans = m;
	while(i < a.size() || j < b.size()){
		if(i == a.size() || b[j] < a[i]){
			long long npos = b[j];
			++j;
			ans += 2 * (npos - pos);
			--line;
			pos = npos;
		}else{
			long long npos = a[i];
			++i;
			if(line > 0){
				ans += 2 * (npos - pos);
			}
			++line;
			pos = npos;
		}
	}
	cout << ans << '\n';
	return 0;
}
