#include <iostream>
#include <algorithm>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t, s, n;
	cin >> t >> s >> n;
	int a;
	cin >> a;
	int top = s, bottom = 0;
	int prev = a;
	for(int i = 1; i < n; ++i){
		cin >> a;
		bottom += min(top, a - prev);
		top -= min(top, a - prev);
		swap(top, bottom);
		prev = a;
	}
	bottom += min(top, t - prev);
	top -= min(top, t - prev);
	cout << top;
	return 0;
}
