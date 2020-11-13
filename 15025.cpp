#include <cstdio>
#include <algorithm>

int main(){
	int left, right;
	scanf("%d %d", &left, &right);
	if(left == 0 && right == 0){
		printf("Not a moose");
	}else if(left == right){
		printf("Even %d", left * 2);
	}else{
		printf("Odd %d", std::max(left, right) * 2);
	}
	return 0;
}
