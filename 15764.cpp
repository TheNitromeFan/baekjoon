#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, m, k;
	cin >> n >> m >> k;
	vector<int> order(n + 1, -1);
	vector<int> pos(n + 1, -1);
	vector<int> hierarchy;
	bool flag1 = false;
	for(int a0 = 0; a0 < m; ++a0){
		int x;
		cin >> x;
		hierarchy.push_back(x);
		if(x == 1){
			flag1 = true;
		}
	}
	for(int a1 = 0; a1 < k; ++a1){
		int c, p;
		cin >> c >> p;
		order[p] = c;
		pos[c] = p;
	}
	if(pos[1] != -1){
		cout << pos[1] << '\n';
		return 0;
	}
	if(flag1){
		int y = 1;
		while(order[y] != -1){
			++y;
		}
		for(int x : hierarchy){
			if(pos[x] == -1){
				pos[x] = y;
				order[y] = x;
			}else{
				y = pos[x];
			}
			while(order[y] != -1){
				++y;
			}
		}
		cout << pos[1] << '\n';
		return 0;
	}
	reverse(hierarchy.begin(), hierarchy.end());
	int y = n;
	while(order[y] != -1){
		--y;
	}
	for(int x : hierarchy){
		if(pos[x] == -1){
			pos[x] = y;
			order[y] = x;
		}else{
			y = pos[x];
		}
		while(order[y] != -1){
			--y;
		}
	}
	int ans = 1;
	while(order[ans] != -1){
		++ans;
	}
	cout << ans << '\n';
	return 0;
}
