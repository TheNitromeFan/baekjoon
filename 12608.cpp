#include <iostream>
#include <utility>
#include <map>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	map<char, pair<int, int>> m;
	m['a'] = make_pair(2, 1);
	m['b'] = make_pair(2, 2);
	m['c'] = make_pair(2, 3);
	m['d'] = make_pair(3, 1);
	m['e'] = make_pair(3, 2);
	m['f'] = make_pair(3, 3);
	m['g'] = make_pair(4, 1);
	m['h'] = make_pair(4, 2);
	m['i'] = make_pair(4, 3);
	m['j'] = make_pair(5, 1);
	m['k'] = make_pair(5, 2);
	m['l'] = make_pair(5, 3);
	m['m'] = make_pair(6, 1);
	m['n'] = make_pair(6, 2);
	m['o'] = make_pair(6, 3);
	m['p'] = make_pair(7, 1);
	m['q'] = make_pair(7, 2);
	m['r'] = make_pair(7, 3);
	m['s'] = make_pair(7, 4);
	m['t'] = make_pair(8, 1);
	m['u'] = make_pair(8, 2);
	m['v'] = make_pair(8, 3);
	m['w'] = make_pair(9, 1);
	m['x'] = make_pair(9, 2);
	m['y'] = make_pair(9, 3);
	m['z'] = make_pair(9, 4);
	m[' '] = make_pair(0, 1);
	int n;
	cin >> n;
	string line;
	getline(cin, line);
	for(int i = 1; i <= n; ++i){
		getline(cin, line);
		cout << "Case #" << i << ": ";
		for(unsigned idx = 0; idx < line.length(); ++idx){
			auto p = m[line[idx]];
			for(int j = 0; j < p.second; ++j){
				cout << p.first;
			}
			if(idx + 1 < line.length() && p.first == m[line[idx + 1]].first){
				cout << ' ';
			}
		}
		cout << '\n';
	}
	return 0;
}
