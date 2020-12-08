#include <iostream>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	int a[100001];
	for(int i = 1; i <= n; ++i){
		cin >> a[i];
	}
	int dist = 0;
	int money = 0, owed = 0;
	int pos = 10000000;
	for(int i = 1; i <= n; ++i){
		++dist;
		if(a[i] > 0){
			money += a[i];
			if(owed > 0 && money >= owed){
				money -= owed;
				dist += 2 * (i - pos);
				pos = 10000000;
				owed = 0;
			}
		}else if(a[i] < 0){
			if(money + a[i] >= 0){
				money += a[i];
			}else{
				if(pos > i){
					pos = i;
				}
				owed -= a[i];
			}
		}
	}
	cout << dist;
	return 0;
}
