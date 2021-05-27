#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

bool match(char a[][61], char b[][7], int pos){
	for(int i = 0; i < 7; ++i){
		for(int j = 0; j < 6; ++j){
			if(a[i][pos + j] != b[i][j]){
				return false;
			}
		}
	}
	return true;
}

int matching_number(char numbers[][7][7], char map[][61], int pos){
	for(int n = 0; n < 10; ++n){
		if(match(map, numbers[n], pos)){
			return n;
		}
	}
	return -1;
}

int main(){
	char numbers[10][7][7] = {
		{
			"000000",
			"001100",
			"010010",
			"010010",
			"010010",
			"001100",
			"000000"
		},
		{
			"000000",
			"000100",
			"001100",
			"000100",
			"000100",
			"000100",
			"000000"
		},
		{
			"000000",
			"011110",
			"000010",
			"011110",
			"010000",
			"011110",
			"000000"
		},
		{
			"000000",
			"011100",
			"000010",
			"000100",
			"000010",
			"011100",
			"000000"
		},
		{
			"000000",
			"000100",
			"001100",
			"010100",
			"111110",
			"000100",
			"000000"
		},
		{
			"000000",
			"011110",
			"010000",
			"011100",
			"000010",
			"010010",
			"001100",
		},
		{
			"000000",
			"010000",
			"010000",
			"011110",
			"010010",
			"011110",
			"000000"
		},
		{
			"000000",
			"011110",
			"000010",
			"000100",
			"000100",
			"000100",
			"000000"
		},
		{
			"000000",
			"011110",
			"010010",
			"011110",
			"010010",
			"011110",
			"000000"
		},
		{
			"011110",
			"010010",
			"010010",
			"011110",
			"000010",
			"000010",
			"000010"
		}
	};
	char lights[7][61];
	for(int i = 0; i < 7; ++i){
		scanf("%s", lights[i]);
	}
	vector<int> v;
	for(int j = 0; lights[0][j] != '\0'; j += 6){
		// printf("%d\n", matching_number(numbers, lights, j));
		v.push_back(matching_number(numbers, lights, j));
	}
	if(next_permutation(v.begin(), v.end())){
		for(int i = 0; i < 7; ++i){
			for(int x : v){
				for(int j = 0; j < 6; ++j){
					printf("%c", numbers[x][i][j]);
				}
			}
			printf("\n");
		}
	}else{
		printf("The End\n");
	}
	return 0;
}
