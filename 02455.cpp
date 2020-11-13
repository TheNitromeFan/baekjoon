#include <cstdio>


int main(void){
	
	int people = 0, max = 0;
	for(int i = 0; i < 4; i++){
		int out, in;
		scanf("%d %d", &out, &in);
		people += (in - out);
		if(people > max) max = people;
	}
	printf("%d", max);
	return 0;
}
