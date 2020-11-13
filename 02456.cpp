#include <cstdio>
#include <cstdlib>


int max(int a, int b){
	
	if(a > b) return a;
	else return b;
}

int only(int *arr, int size){
	
	int answer = 0;
	for(int i = 0; i < size; i++){
		if(*(arr+i) && answer) return 0;
		else if(*(arr+i)) answer = i+1;
	}
	return answer;
}

int winner(int **votes){
	
	int contender[3] = {1, 1, 1};
	for(int i = 3; i > 0; i--){
		int v = 0;
		for(int j = 0; j < 3; j++)
			if(contender[j] && v < *(*(votes+j)+i)) v = *(*(votes+j)+i);
		for(int j = 0; j < 3; j++)
			if(contender[j] && v != *(*(votes+j)+i)) contender[j] = 0;
		int o = only(contender, 3);
		if(o) return o;
	}
	return 0;
}

int main(void){
	
	int n;
	scanf("%d", &n);
	int **votes = (int **)malloc(3 * sizeof(int *));
	for(int i = 0; i < 3; i++){
		*(votes+i) = (int *)malloc(4 * sizeof(int));
		for(int j = 0; j < 3; j++) *(*(votes+i)+j) = 0;
	}
	for(int i = 0; i < n; i++){
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);
		++*(*(votes+0)+a-1);
		++*(*(votes+1)+b-1);
		++*(*(votes+2)+c-1);
	}
	for(int i = 0; i < 3; i++)
		*(*(votes+i)+3) = **(votes+i) + *(*(votes+i)+1) * 2 + *(*(votes+i)+2) * 3;
	printf("%d %d", winner(votes), max(max(*(*(votes+0)+3), *(*(votes+1)+3)), *(*(votes+2)+3)));
	for(int i = 0; i < 3; i++) free(*(votes+i));
	free(votes);
	return 0;
}
