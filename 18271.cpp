#include <cstdio>

int main(){
	int n;
	scanf("%d", &n);
	int goals[250];
	for(int i = 0; i < n; ++i){
		scanf("%d", &goals[i]);
	}
	int a = 0, b = 0;
	int ties = 1;
	int largestTurnover = 0;
	int index = 0;
	int cnt;
	while(index < n){
		bool aLosing = a < b;
		cnt = 0;
		while(index < n && goals[index] == 1){
			++index;
			++a;
			if(a == b){
				++ties;
			}
			++cnt;
		}
		if(aLosing && (a > b) && largestTurnover < cnt){
			largestTurnover = cnt;
		}
		bool bLosing = a > b;
		cnt = 0;
		while(index < n && goals[index] == 2){
			++index;
			++b;
			if(a == b){
				++ties;
			}
			++cnt;
		}
		if(bLosing && (a < b) && largestTurnover < cnt){
			largestTurnover = cnt;
		}
	}
	printf("%d %d\n%d\n%d", a, b, ties, largestTurnover);
	return 0;
}
