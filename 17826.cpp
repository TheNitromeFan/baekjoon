#include <cstdio>
#include <map>

using namespace std;

int main(){
	map<int, int> rank;
	for(int i = 1; i <= 50; ++i){
		int score;
		scanf("%d", &score);
		rank[score] = i;
	}
	int score;
	scanf("%d", &score);
	if(rank[score] <= 5){
		printf("A+");
	}else if(rank[score] <= 15){
		printf("A0");
	}else if(rank[score] <= 30){
		printf("B+");
	}else if(rank[score] <= 35){
		printf("B0");
	}else if(rank[score] <= 45){
		printf("C+");
	}else if(rank[score] <= 48){
		printf("C0");
	}else{
		printf("F");
	}
	return 0;
}
