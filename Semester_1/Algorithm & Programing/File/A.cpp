#include <stdio.h>
#include <string.h>
#define SIZE 100

struct Data {
	char friends[SIZE];
	char trees[SIZE];
};

int main(){
	FILE *fp;
	fp = fopen("testdata.in", "r");
    struct Data data[SIZE];
	
    int N;
    fscanf(fp, "%d\n", &N);
    
    for(int i = 0; i < N; i++){
    	char line[SIZE];
    	gets(line, sizeof(line), fp);
    	sscanf(line, "%[^#]#%[^\n]", data[i].friends, data[i].trees);
	}
	
	int T;
	 fscanf(fp, "%d\n", &T);

    for (int i = 1; i <= T; i++) {
        char fQuery[SIZE];
        fgets(fQuery, sizeof(fQuery), fp);
        fQuery[strcspn(fQuery, "\n")] = 0;

        int found = 0;
        for (int j = 0; j < N; j++) {
            if (strcmp(data[j].friends, fQuery) == 0) {
                printf("Case #%d: %s\n", i, data[j].trees);
                found = 1;
                break;
            }
        }
        if (!found) {
            printf("Case #%d: N/A\n", i);
        }
    }
    return 0;
}
