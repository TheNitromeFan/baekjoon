#include <cstdio>

int main(){
	FILE *fp = fopen("20098.txt", "w");
	for(int block = 1; block <= 20; ++block){
		for(int i = 1; i <= 20; ++i){
			for(int j = 1; j <= 20 * 20; ++j){
				int n = (1 + (i - 1) * 20 + block - 1 + j - 1) % (20 * 20) + 1;
				fprintf(fp, "%d", n);
				if(j < 20 * 20){
					fprintf(fp, " ");
				}
			}
			fprintf(fp, "\n");
		}
	}
	fclose(fp);
	return 0;
}
