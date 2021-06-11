#include <iostream>
#include <vector>
#include <string>
#include <utility>

using namespace std;

int ccw(pair<int, int> a, pair<int, int> b, pair<int, int> c){
	return (b.first - a.first) * (c.second - a.second) - (b.second - a.second) * (c.first - a.first);
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	for(int a0 = 0; a0 < n; ++a0){
		string s;
		cin >> s;
		int x = 0, y = 0;
		vector<pair<int, int>> p = {make_pair(0, 0)};
		for(char c : s){
			switch(c){
				case 'N':
					++y;
					break;
				case 'S':
					--y;
					break;
				case 'E':
					++x;
					break;
				case 'W':
					--x;
					break;
			}
			p.push_back(make_pair(x, y));
		}
		int area = 0;
		for(unsigned i = 1; i < s.length(); ++i){
			area += ccw(p[0], p[i], p[i + 1]);
		}
		cout << (area > 0 ? "CCW" : "CW") << '\n';
	}
	return 0;
}
