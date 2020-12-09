#include <iostream>
#include <set>
#include <utility>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin >> t;
	for(int a0 = 0; a0 < t; ++a0){
		int n;
		cin >> n;
		set<pair<int, int>> xy;
		set<int> x, y;
		for(int i = 0; i < n; ++i){
			int xi, yi;
			cin >> xi >> yi;
			xy.insert(make_pair(xi, yi));
			x.insert(xi);
			y.insert(yi);
		}
		cout << (xy.size() == x.size() * y.size() ? "BALANCED" : "NOT BALANCED") << "\n";
	}
	return 0;
}
