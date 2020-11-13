#include <stdio.h>
#define MAX_SIZE 100000
#define COMMENT_START(s) (*(s) == '/' && *((s) + 1) == '*')
#define COMMENT_END(s) (*(s) == '*' && *((s) + 1) == '/')

int main(){
	char str_in[MAX_SIZE] = {0};
	char str_out[MAX_SIZE] = {0};
	char *p_in, *p_out;
	int level;
	level = 0;
	p_out = str_out;
	while(gets(str_in)){
		p_in = str_in;
		while(*p_in){
			if(level == 0){
				while(*p_in && !COMMENT_START(p_in)){
					*p_out++ = *p_in++;
				}
				if(*p_in){
					p_in += 2; level++;
				}
			}else{
				while(*p_in && !COMMENT_START(p_in) && !COMMENT_END(p_in)) p_in++;
				if(COMMENT_START(p_in)){
					p_in += 2; level++;
				}else if(COMMENT_END(p_in)){
					p_in += 2; level--;
				}
			}
		}
		if(level == 0) *p_out++ = '\n';
	}
	*p_out = 0;
	printf("Case #1:\n%s", str_out);
	return 0;
}
