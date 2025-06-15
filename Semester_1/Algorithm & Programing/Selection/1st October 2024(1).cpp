#include<stdio.h>
#include<string.h>

int main(){
	char m[50];
	int d;
	
	scanf("%s", m);
	scanf("%d", &d);
	
	if(strcmp(m, "March") == 0 && 20 <= d && d <= 31	||
	   strcmp(m, "Apri") == 0 && 1 <= d && d <= 30		||
	   strcmp(m, "May") == 0 && 1 <= d && d <= 31		||
	   strcmp(m, "June") == 0 && 1 <= d && d <= 30)
	 {
		printf("Spring\n");
	}
	
	return 0;
}
