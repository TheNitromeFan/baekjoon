#include <cstdio>

bool vowel(char c){
	bool ret = false;
	switch(c){
		case 'a':
		case 'e':
		case 'i':
		case 'o':
		case 'u':
			ret = true;
			break;
	}
	return ret;
}

char closest_vowel(char c){
	char a = c - 1, b = c + 1;
	while(true){
		if(vowel(a)){
			return a;
		}
		if(vowel(b)){
			return b;
		}
		if(a > 'a'){
			--a;
		}
		if(b < 'z'){
			++b;
		}
	}
	return c;
}

char next_consonant(char c){
	if(c == 'z'){
		return 'z';
	}
	char ret;
	for(ret = c + 1; ret <= 'z'; ++ret){
		if(!vowel(ret)){
			break;
		}
	}
	return ret;
}

int main(){
	char s[31];
	scanf("%s", s);
	for(int i = 0; s[i] != '\0'; ++i){
		printf("%c", s[i]);
		if(!vowel(s[i])){
			printf("%c%c", closest_vowel(s[i]), next_consonant(s[i]));
		}
	}
	return 0;
}
