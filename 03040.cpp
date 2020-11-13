#include <cstdio>
#include <algorithm>
#include <string>

using namespace std;

int main(){
	int dwarves[9];
	for(int i = 0; i < 9; ++i){
		scanf("%d", &dwarves[i]);
	}
	string bitmask(7, 1);
	bitmask.resize(9, 0);
	int correct[7];
	do{
		int j = 0;
		int sum = 0;
		for(int i = 0; i < 9 && j < 7; ++i){
			if(bitmask[i]){
				sum += dwarves[i];
				correct[j] = dwarves[i];
				++j;
			}
		}
		if(sum == 100){
			break;
		}
	}while(prev_permutation(bitmask.begin(), bitmask.end()));
	sort(correct, correct+7);
	for(int j = 0; j < 7; ++j){
		printf("%d\n", correct[j]);
	}
	return 0;
}
