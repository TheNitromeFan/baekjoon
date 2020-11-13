#include <cstdio>
#include <cstdlib>
#include <cstring>


int rom_to_arab(char *rom){
	
	int answer = 0, place = 0;
	while(*(rom+place) == 'M'){
		answer += 1000;
		place++;
	}
	if(*(rom+place) == 'C'){  
        if(*(rom+place+1) == 'M'){  
            answer += 900;  
            place += 2;  
        }else if(*(rom+place+1) == 'D'){  
            answer += 400;  
            place += 2;  
        }else{   
            while(*(rom+place) == 'C'){
                answer += 100;  
                place++;  
            }  
        }  
    }else if(*(rom+place) == 'D'){  
        answer += 500;  
        place++;  
        while(*(rom+place) == 'C'){
            answer += 100;  
            place++;  
        }  
    }
    if(*(rom+place) == 'X'){
        if(*(rom+place+1) == 'C'){ 
            answer += 90;  
            place += 2;  
        }else if(*(rom+place+1) == 'L'){  
            answer += 40;  
            place += 2;  
        }else{  
            while(*(rom+place) == 'X'){ 
                answer += 10;  
                place++;  
            }  
        }  
    }else if(*(rom+place) == 'L'){
        answer += 50;  
        place++;  
        while(*(rom+place) == 'X'){  
            answer += 10;  
            place++;  
        }  
    }
    if(*(rom+place) == 'I'){  
        if(*(rom+place+1) == 'X'){ 
            answer += 9;  
            place += 2;  
        }else if(*(rom+place+1) == 'V'){ 
            answer += 4;  
            place += 2;  
        }else{
            while(*(rom+place) == 'I'){
                answer += 1;  
                place++;  
            }  
        }  
    }else if(*(rom+place) == 'V'){  
        answer += 5;  
        place++;  
        while(*(rom+place) == 'I'){ 
            answer += 1;  
            place++;  
        }  
    }
    return answer;
}

char *arab_to_rom(int n){
	
	char *answer = (char *)malloc(50 * sizeof(char));
	*answer = '\0';
    switch(n / 1000){
        case 1: strcat(answer, "M"); break;
        case 2: strcat(answer, "MM"); break;
        case 3: strcat(answer, "MMM"); break;
    }
    n %= 1000;
    switch(n / 100){
        case 1: strcat(answer, "C"); break;
        case 2: strcat(answer, "CC"); break;
        case 3: strcat(answer, "CCC"); break;
        case 4: strcat(answer, "CD"); break;
        case 5: strcat(answer, "D"); break;
        case 6: strcat(answer, "DC"); break;
        case 7: strcat(answer, "DCC"); break;
        case 8: strcat(answer, "DCCC"); break;
        case 9: strcat(answer, "CM"); break;
    }
    n %= 100;
    switch(n / 10){
        case 1: strcat(answer, "X"); break;
        case 2: strcat(answer, "XX"); break;
        case 3: strcat(answer, "XXX"); break;
        case 4: strcat(answer, "XL"); break;
        case 5: strcat(answer, "L"); break;
        case 6: strcat(answer, "LX"); break;
        case 7: strcat(answer, "LXX"); break;
        case 8: strcat(answer, "LXXX"); break;
        case 9: strcat(answer, "XC"); break;
    }
    n %= 10;
    switch(n){
        case 1: strcat(answer, "I"); break;
        case 2: strcat(answer, "II"); break;
        case 3: strcat(answer, "III"); break;
        case 4: strcat(answer, "IV"); break;
        case 5: strcat(answer, "V"); break;
        case 6: strcat(answer, "VI"); break;
        case 7: strcat(answer, "VII"); break;
        case 8: strcat(answer, "VIII"); break;
        case 9: strcat(answer, "IX"); break;
    }
    return answer;
}

int main(void){
	
	char *a = (char *)malloc(50 * sizeof(char)), *b = (char *)malloc(50 * sizeof(char));
	scanf("%s", a);
	scanf("%s", b);
	int m = strlen(a), n = strlen(b);
	*(a+m) = ' ';
	*(b+n) = ' ';
	int sum = rom_to_arab(a) + rom_to_arab(b);
	free(a);
	free(b);
	printf("%d\n%s", sum, arab_to_rom(sum));
	return 0;
}
