#include <iostream>
#include <vector>

using namespace std;

bool all_lights_off(vector<bool> &lights){
	for(bool x : lights){
		if(x){
			return false;
		}
	}
	return true;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, m;
	cin >> n >> m;
	vector<bool> lights(m);
	int l;
	cin >> l;
	for(int a0 = 0; a0 < l; ++a0){
		int x;
		cin >> x;
		lights[x - 1] = true;
	}
	vector<vector<int>> switches(n);
	for(int i = 0; i < n; ++i){
		int k;
		cin >> k;
		for(int a1 = 0; a1 < k; ++a1){
			int y;
			cin >> y;
			switches[i].push_back(y - 1);
		}
	}
	vector<bool> initial_lights = lights;
	int steps = 0;
	do{
		for(int i = 0; i < n; ++i){
			if(all_lights_off(lights)){
				cout << steps;
				return 0;
			}
			++steps;
			for(int x : switches[i]){
				lights[x] = !lights[x];
			}
		}
	}while(lights != initial_lights);
	cout << -1;
	return 0;
}
