#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
	vector<int> v(8, 0);
	for(int i = 0; i < 8; ++i){
		scanf("%d", &v[i]);
	}
	int ans = 0;
	for(int i = 0; i < 8; ++i){
		if(ans < v[0] + v[1] + v[2] + v[3]){
			ans = v[0] + v[1] + v[2] + v[3];
		}
		rotate(v.begin(), v.begin() + 1, v.end());
	}
	printf("%d", ans);
	return 0;
}
