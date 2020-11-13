#include <cstdio>
#include <cstdlib>
#include <cstring>


int substitutions(char *sascha, char *word, int len){
	
	int s = 0;
	for(int i = 0; i < len; i++)
		s += (*(sascha+i) != *(word+i));
	return s;
}

char *likely(char *sascha, char **words, int w, int len){
	
	int min_subs = len+1;
	char *min_sub_word;
	for(int i = 0; i < w; i++){
		int subs = substitutions(sascha, *(words+i), len);
		if(subs < min_subs){
			min_subs = subs;
			min_sub_word = *(words+i);
		}
	}
	return min_sub_word;
}

int main(void){
	
	int n;
	scanf("%d", &n);
	for(int i = 0; i < n; i++){
		char *sascha = (char *)malloc(128 * sizeof(char));
		scanf("%s", sascha);
		int w;
		scanf("%d", &w);
		char **words = (char **)malloc(w * sizeof(char *));
		for(int j = 0; j < w; j++){
			*(words+j) = (char *)malloc(128 * sizeof(char));
			scanf("%s", *(words+j));
		}
		int len = strlen(*words);
		printf("%s\n", likely(sascha, words, w, len));
		for(int j = 0; j < w; j++) free(*(words+j));
		free(words);
	}
	return 0;
}
