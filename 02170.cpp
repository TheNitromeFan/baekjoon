#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	vector<int> a(n), b(n);
	for(int i = 0; i < n; ++i){
		cin >> a[i] >> b[i];
	}
	sort(a.begin(), a.end());
	sort(b.begin(), b.end());
	int i = 0, j = 0;
	int ans = 0;
	int line = 0;
	int pos = -1000000001;
	while(i < n || j < n){
		if(i == n || b[j] < a[i]){
			int npos = b[j];
			++j;
			ans += npos - pos;
			--line;
			pos = npos;
		}else{
			int npos = a[i];
			++i;
			if(line > 0){
				ans += npos - pos;
			}
			++line;
			pos = npos;
		}
	}
	cout << ans << '\n';
	return 0;
}
