#include <cstdio>

int main(){
	int nums[4];
	for(int i = 0; i < 4; ++i){
		scanf("%d", &nums[i]);
	}
	printf("%s", (nums[0] == 8 || nums[0] == 9) && (nums[3] == 8 || nums[3] == 9) && nums[1] == nums[2] ? "ignore" : "answer");
	return 0;
}
