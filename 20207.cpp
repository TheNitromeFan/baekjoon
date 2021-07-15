#include <iostream>
#include <algorithm>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int plans[366] = {};
	int n;
	cin >> n;
	for(int i = 0; i < n; ++i){
		int start, end;
		cin >> start >> end;
		for(int x = start; x <= end; ++x){
			++plans[x];
		}
	}
	int area = 0;
	int i = 1;
	while(i <= 365){
		while(i <= 365 && plans[i] == 0){
			++i;
		}
		int start = i;
		int height = plans[i];
		while(i <= 365 && plans[i] > 0){
			height = max(height, plans[i]);
			++i;
		}
		area += (i - start) * height;
	}
	cout << area << '\n';
	return 0;
}
