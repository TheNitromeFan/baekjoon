#include <cstdio>
#define MAX 51

using namespace std;

int main(){
	int n;
	scanf("%d", &n);
	char cities[MAX][MAX];
	for(int i = 0; i < n; ++i){
		scanf("%s", cities[i]);
	}
	int city_count = 0;
	for(int i = 0; i < n; ++i){
		for(int j = 0; j < n; ++j){
			if(cities[i][j] == 'C'){
				++city_count;
			}
		}
	}
	int city_count1 = 0;
	for(int i = 0; i < n; ++i){
		for(int j = 0; j < n; ++j){
			if(cities[i][j] == 'C'){
				++city_count1;
			}
			if(city_count1 <= city_count / 2){
				printf("1");
			}else{
				printf("2");
			}
		}
		printf("\n");
	}
	return 0;
}
