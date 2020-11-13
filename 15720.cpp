#include <cstdio>
#include <vector>
#include <algorithm>
#include <functional>

using namespace std;

int main(){
	int b, c, d;
	scanf("%d %d %d", &b, &c, &d);
	vector<int> burgers(b, 0), sides(c, 0), drinks(d, 0);
	for(int i = 0; i < b; ++i){
		scanf("%d", &burgers[i]);
	}
	for(int i = 0; i < c; ++i){
		scanf("%d", &sides[i]);
	}
	for(int i = 0; i < d; ++i){
		scanf("%d", &drinks[i]);
	}
	int ans;
	ans = 0;
	for(int burger : burgers){
		ans += burger;
	}
	for(int side : sides){
		ans += side;
	}
	for(int drink : drinks){
		ans += drink;
	}
	printf("%d\n", ans);
	sort(burgers.begin(), burgers.end(), greater<int>());
	sort(sides.begin(), sides.end(), greater<int>());
	sort(drinks.begin(), drinks.end(), greater<int>());
	int m = min(min(b, c), d);
	for(int i = 0; i < m; ++i){
		burgers[i] /= 10;
		burgers[i] *= 9;
		sides[i] /= 10;
		sides[i] *= 9;
		drinks[i] /= 10;
		drinks[i] *= 9;
	}
	ans = 0;
	for(int burger : burgers){
		ans += burger;
	}
	for(int side : sides){
		ans += side;
	}
	for(int drink : drinks){
		ans += drink;
	}
	printf("%d\n", ans);
	return 0;
}
