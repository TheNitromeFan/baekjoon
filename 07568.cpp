#include <cstdio>
#include <cstdlib>


struct bulk{
	
	int weight;
	int height;
	int rank;
};

int main(void){
	
	int n;
	scanf("%d", &n);
	struct bulk *people = (struct bulk *)malloc(n * sizeof(struct bulk));
	for(int i = 0; i < n; i++)
		scanf("%d %d", &(people+i)->weight, &(people+i)->height);
	for(int i = 0; i < n; i++){
		(people+i)->rank = 1;
		for(int j = 0; j < i; j++){
			if((people+j)->weight > (people+i)->weight && (people+j)->height > (people+i)->height) ++(people+i)->rank;
			else if((people+j)->weight < (people+i)->weight && (people+j)->height < (people+i)->height) ++(people+j)->rank;
		}
	}
	for(int i = 0; i < n; i++)
		printf("%d ", (people+i)->rank);
	free(people);
	return 0;
}
