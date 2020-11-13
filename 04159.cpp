#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

bool can_drive(vector<int> &stops){
	for(unsigned i = 0; i + 1 < stops.size(); ++i){
		if(stops[i + 1] - stops[i] > 200){
			return false;
		}
	}
	if(1422 - stops[stops.size() - 1] > 100){
		return false;
	}
	return true;
}

int main(){
	while(true){
		int n;
		scanf("%d", &n);
		if(n == 0){
			break;
		}
		vector<int> stops(n, 0);
		for(int i = 0; i < n; ++i){
			scanf("%d", &stops[i]);
		}
		sort(stops.begin(), stops.end());
		printf("%s\n", can_drive(stops) ? "POSSIBLE" : "IMPOSSIBLE");
	}
	return 0;
}
