#include <cstdio>

bool good(char spotty[][101], char plain[][101], int n, int col){
	bool acgt[4] = {};
	for(int i = 0; i < n; ++i){
		if(spotty[i][col] == 'A'){
			acgt[0] = true;
		}else if(spotty[i][col] == 'C'){
			acgt[1] = true;
		}else if(spotty[i][col] == 'G'){
			acgt[2] = true;
		}else{
			acgt[3] = true;
		}
	}
	for(int i = 0; i < n; ++i){
		if(plain[i][col] == 'A' && acgt[0]){
			return false;
		}else if(plain[i][col] == 'C' && acgt[1]){
			return false;
		}else if(plain[i][col] == 'G' && acgt[2]){
			return false;
		}else if(plain[i][col] == 'T' && acgt[3]){
			return false;
		}
	}
	return true;
}

int main(){
	int n, m;
	scanf("%d %d", &n, &m);
	char spotty[101][101], plain[101][101];
	for(int i = 0; i < n; ++i){
		scanf("%s", spotty[i]);
	}
	for(int i = 0; i < n; ++i){
		scanf("%s", plain[i]);
	}
	int cnt = 0;
	for(int j = 0; j < m; ++j){
		if(good(spotty, plain, n, j)){
			++cnt;
		}
	}
	printf("%d", cnt);
	return 0;
}
