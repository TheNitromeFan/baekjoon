#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
	int t;
	scanf("%d", &t);
	for(int i = 1; i <= t; ++i){
		vector<int> v(3, 0);
		for(int j = 0; j < 3; ++j){
			scanf("%d", &v[j]);
		}
		sort(v.begin(), v.end());
		printf("Scenario #%d:\n%s\n\n", i, (v[2] * v[2] == v[0] * v[0] + v[1] * v[1] ? "yes" : "no"));
	}
	return 0;
}
