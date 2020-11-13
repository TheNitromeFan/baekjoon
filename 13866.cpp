#include <cstdio>
#include <cstdlib>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
	vector<int> v(4, 0);
	for(int i = 0; i < 4; ++i){
		scanf("%d", &v[i]);
	}
	printf("%d", abs(v[0] + v[3] - v[1] - v[2]));
	return 0;
}
