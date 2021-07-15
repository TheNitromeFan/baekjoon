#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, k;
	cin >> n >> k;
	vector<string> cards(n + 1);
	vector<bool> seen(n + 1), matched(n + 1);
	for(int a0 = 0; a0 < k; ++a0){
		int c1, c2;
		string p1, p2;
		cin >> c1 >> c2 >> p1 >> p2;
		cards[c1] = p1;
		cards[c2] = p2;
		seen[c1] = true;
		seen[c2] = true;
		if(p1 == p2){
			matched[c1] = true;
			matched[c2] = true;
		}
	}
	unordered_map<string, int> m;
	int a = 0, b = 0, c = 0;
	for(int i = 1; i <= n; ++i){
		if(seen[i] && !matched[i]){
			++m[cards[i]];
			++b;
			if(m[cards[i]] == 2){
				c += 2;
				b -= 2;
			}
		}else if(!seen[i]){
			++a;
		}
	}
	int pairs = c / 2;
	if(a == 2 && b == 0){
		pairs += 1;
	}else if(a == b){
		pairs += a;
	}
	cout << pairs << '\n';
	return 0;
}
