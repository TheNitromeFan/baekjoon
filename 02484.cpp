#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
	int n;
	scanf("%d", &n);
	int ans = 0;
	for(int i = 0; i < n; ++i){
		vector<int> v(4, 0);
		for(int j = 0; j < 4; ++j){
			scanf("%d", &v[j]);
		}
		sort(v.begin(), v.end());
		int points = 0;
		if(v[0] == v[1] && v[1] == v[2] && v[2] == v[3]){
			points = 50000 + v[1] * 5000;
		}else if((v[0] == v[1] && v[1] == v[2]) || (v[1] == v[2] && v[2] == v[3])){
			points = 10000 + v[1] * 1000;
		}else if(v[0] == v[1] && v[2] == v[3]){
			points = 2000 + v[1] * 500 + v[2] * 500;
		}else if(v[0] == v[1] || v[1] == v[2]){
			points = 1000 + v[1] * 100;
		}else if(v[2] == v[3]){
			points = 1000 + v[2] * 100;
		}else{
			points = v[3] * 100;
		}
		if(ans < points){
			ans = points;
		}
	}
	printf("%d", ans);
	return 0;
}
