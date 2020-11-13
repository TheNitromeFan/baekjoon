#include <cstdio>
#include <cstdlib>


struct country{
	
	int gold;
	int silver;
	int bronze;
	int rank;
};

void get_rank(struct country *countries, int size, int k){
	
	(countries+k)->rank = 1;
	for(int i = 1; i <= size; i++){
		if((countries+i)->gold > (countries+k)->gold)
			(countries+k)->rank++;
		else if((countries+i)->gold == (countries+k)->gold && (countries+i)->silver > (countries+k)->silver)
			(countries+k)->rank++;
		else if((countries+i)->gold == (countries+k)->gold && (countries+i)->silver == (countries+k)->silver && (countries+i)->bronze > (countries+k)->bronze)
			(countries+k)->rank++;
	}
}

int main(void){
	
	int n, k;
	scanf("%d %d", &n, &k);
	struct country *countries = (struct country *)malloc((n+1) * sizeof(struct country));
	for(int i = 0; i < n; i++){
		int label;
		scanf("%d", &label);
		scanf("%d %d %d", &(countries+label)->gold, &(countries+label)->silver, &(countries+label)->bronze);
	}
	get_rank(countries, n, k);
	printf("%d", (countries+k)->rank);
	free(countries);
	return 0;
}
