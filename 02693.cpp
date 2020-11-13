#include <cstdio>
#include <vector>
#include <algorithm>
#include <functional>

using namespace std;

int main(){
	int p;
	scanf("%d", &p);
	for(int i = 0; i < p; ++i){
		vector<int> v(10, 0);
		for(int j = 0; j < 10; ++j){
			scanf("%d", &v[j]);
		}
		sort(v.begin(), v.end(), greater<int>());
		printf("%d\n", v[2]);
	}
	return 0;
}
