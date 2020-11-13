#include <iostream>

using namespace std;

int main(){
	int n, b, h, w;
	cin >> n >> b >> h >> w;
	int min_cost = b;
	bool found = false;
	for(int a0 = 0; a0 < h; ++a0){
		int p;
		cin >> p;
		for(int a1 = 0; a1 < w; ++a1){
			int available_beds;
			cin >> available_beds;
			if(available_beds >= n && p * n <= min_cost){
				min_cost = p * n;
				found = true;
			}
		}
	}
	if(found){
		cout << min_cost;
	}else{
		cout << "stay home";
	}
	return 0;
}
