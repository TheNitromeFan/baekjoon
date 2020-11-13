#include <cstdio>
#include <vector>
#include <algorithm>
#include <functional>

using namespace std;

void arrange(vector<int> &boxes, int height){
	sort(boxes.begin(), boxes.end(), greater<int>());
	vector<int> bitmask(3, 1);
	bitmask.resize(6, 0);
	do{
		int sum = 0;
		for(int i = 0; i < 6; ++i){
			if(bitmask[i]){
				sum += boxes[i];
			}
		}
		if(sum == height){
			for(int i = 0; i < 6; ++i){
				if(bitmask[i]){
					printf("%d ", boxes[i]);
				}
			}
			for(int i = 0; i < 6; ++i){
				if(!bitmask[i]){
					printf("%d ", boxes[i]);
				}
			}
			return;
		}
	}while(prev_permutation(bitmask.begin(), bitmask.end()));
}

int main(){
	vector<int> boxes(6, 0);
	int h1, h2;
	for(int i = 0; i < 6; ++i){
		scanf("%d", &boxes[i]);
	}
	scanf("%d %d", &h1, &h2);
	arrange(boxes, h1);
	return 0;
}
