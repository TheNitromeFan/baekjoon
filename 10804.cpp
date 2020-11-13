#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
	vector<int> v(21, 0);
	for(int i = 1; i <= 20; ++i){
		v[i] = i;
	}
	for(int j = 0; j < 10; ++j){
		int s, e;
		scanf("%d %d", &s, &e);
		reverse(v.begin() + s, v.begin() + e + 1);
	}
	for(int i = 1; i <= 20; ++i){
		printf("%d ", v[i]);
	}
	return 0;
}
