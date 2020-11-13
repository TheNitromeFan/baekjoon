#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

bool triangle(int x, int y, int z){
	return x + y > z && y + z > x && z + x > y;
}

int main(){
	vector<int> sides(5, 0);
	for(int i = 0; i < 5; ++i){
		scanf("%d", &sides[i]);
	}
	vector<int> bitmask(3, 1);
	bitmask.resize(5, 0);
	int ans = 0;
	do{
		vector<int> selected;
		for(int i = 0; i < 5; ++i){
			if(bitmask[i]){
				selected.push_back(sides[i]);
			}
		}
		if(triangle(selected[0], selected[1], selected[2])){
			++ans;
		}
	}while(prev_permutation(bitmask.begin(), bitmask.end()));
	printf("%d", ans);
	return 0;
}
