#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int next_lot(vector<int> &lot_to_car, int n){
	for(int i = 0; i < n; ++i){
		if(lot_to_car[i] == 0){
			return i;
		}
	}
	return -1;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, m;
	cin >> n >> m;
	vector<int> rate(n), weight(m + 1), order(2 * m);
	for(int i = 0; i < n; ++i){
		cin >> rate[i];
	}
	for(int j = 1; j <= m; ++j){
		cin >> weight[j];
	}
	for(int k = 0; k < 2 * m; ++k){
		cin >> order[k];
	}
	queue<int> cars;
	vector<int> car_to_lot(m + 1);
	vector<int> lot_to_car(n);
	int revenue = 0;
	for(int x : order){
		if(x > 0){
			int lot = next_lot(lot_to_car, n);
			if(lot != -1){
				lot_to_car[lot] = x;
				car_to_lot[x] = lot;
			}else{
				cars.push(x);
			}
		}else{
			x *= -1;
			int lot = car_to_lot[x];
			revenue += rate[lot] * weight[x];
			lot_to_car[lot] = 0;
			if(!cars.empty()){
				int car = cars.front();
				cars.pop();
				lot_to_car[lot] = car;
				car_to_lot[car] = lot;
			}
		}
	}
	cout << revenue << '\n';
	return 0;
}
