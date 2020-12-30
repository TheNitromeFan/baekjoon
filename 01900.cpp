#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	vector<pair<int, int>> wrestlers(n);
	vector<int> line(n);
	for(int i = 0; i < n; ++i){
		int x, y;
		cin >> x >> y;
		wrestlers[i] = make_pair(x, y);
		line[i] = i;
	}
	sort(line.begin(), line.end(), [&wrestlers](int a, int b){
		pair<int, int> wa = wrestlers[a], wb = wrestlers[b];
		return wa.first + wa.second * wb.first > wb.first + wb.second * wa.first;
	});
	for(int x : line){
		cout << x + 1 << '\n';
	}
	return 0;
}
