#include <cstdio>

void rsp(char ml, char mr, char tl, char tr){
	if(ml == mr && ((ml == 'S' && (tl == 'R' || tr == 'R')) || (ml == 'R' && (tl == 'P' || tr == 'P')) || (ml == 'P' && (tl == 'S' || tr == 'S')))){
		printf("TK");
	}else if(tl == tr && ((tl == 'S' && (ml == 'R' || mr == 'R')) || (tl == 'R' && (ml == 'P' || mr == 'P')) || (tl == 'P' && (ml == 'S' || mr == 'S')))){
		printf("MS");
	}else{
		printf("?");
	}
}

int main(){
	char ml, mr, tl, tr;
	scanf("%c %c %c %c", &ml, &mr, &tl, &tr);
	rsp(ml, mr, tl, tr);
	return 0;
}
