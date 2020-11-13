#include <cstdio>
#include <cstdlib>
#include <vector>

int main(){
	int x;
	std::vector<int> v;
	for(int i = 0; i < 10; ++i){
		scanf("%d", &x);
		if(x != 0){
			v.push_back(i);
			v.push_back(x);
		}
	}
	if(abs(v[3] - v[1]) % (v[2] - v[0]) != 0){
		printf("-1");
		return 0;
	}
	int d = (v[3] - v[1]) / (v[2] - v[0]);
	for(int i = 0; i < 10; ++i){
		printf("%d ", v[1] + (i - v[0]) * d);
	}
	return 0;
}
