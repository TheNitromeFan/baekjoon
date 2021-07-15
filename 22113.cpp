#include <iostream>
#define MAX 101

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, m;
	cin >> n >> m;
	int bus[MAX];
	for(int i = 0; i < m; ++i){
		cin >> bus[i];
	}
	int price[MAX][MAX];
	for(int s = 1; s <= n; ++s){
		for(int e = 1; e <= n; ++e){
			cin >> price[s][e];
		}
	}
	int ans = 0;
	for(int i = 0; i + 1 < m; ++i){
		ans += price[bus[i]][bus[i + 1]];
	}
	cout << ans << '\n';
	return 0;
}
