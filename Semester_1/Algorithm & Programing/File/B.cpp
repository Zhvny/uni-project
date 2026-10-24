#include <stdio.h>
#include <string.h>
#define SIZE 1001

struct Data{
    int K;
    char S[SIZE];
};

int main(){
    FILE *fp;
    fp = fopen("testdata.in", "r");
    struct Data data[SIZE];
    
    int T;
    fscanf(fp, "%d", &T);
    
    for(int i = 0; i < T; i++){
        fscanf(fp, "%d", &data[i].K);
        fscanf(fp, " %[^\n]", data[i].S);
        
        printf("Case #%d: ", i + 1);
        int length = strlen(data[i].S);
        for(int j = 0; j < length; j++){
            char ch = data[i].S[j];
            
            if(ch >= 'A' && ch <= 'Z'){
                printf("%c", (ch - 'A' - data[i].K + 26) % 26 + 'A');
            }
            else if(ch >= '0' && ch <= '9'){
                if(ch == '0'){
                    printf("%c", ('O' - 'A' - data[i].K + 26) % 26 + 'A');
                } 
                else if(ch == '1'){
                    printf("%c", ('I' - 'A' - data[i].K + 26) % 26 + 'A');
                } 
                else if(ch == '3'){
                    printf("%c", ('E' - 'A' - data[i].K + 26) % 26 + 'A');
                } 
                else if(ch == '4'){
                    printf("%c", ('A' - 'A' - data[i].K + 26) % 26 + 'A');
                } 
                else if(ch == '5'){
                    printf("%c", ('S' - 'A' - data[i].K + 26) % 26 + 'A');
                } 
                else if(ch == '6'){
                    printf("%c", ('G' - 'A' - data[i].K + 26) % 26 + 'A');
                } 
                else if(ch == '7'){
                    printf("%c", ('T' - 'A' - data[i].K + 26) % 26 + 'A');
                } 
                else if(ch == '8'){
                    printf("%c", ('B' - 'A' - data[i].K + 26) % 26 + 'A');
                } 
                else {
                    printf("%c", ch);
                }
            } 
            else { 
                printf("%c", ch);
            }
        }
        printf("\n");
    }
    fclose(fp);
    return 0;
}

