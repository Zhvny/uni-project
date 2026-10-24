#include <stdio.h>
#include <string.h>

int main() {
    char input[169];
    char reverse[169];
    char result[169];
    int length = 0, error = 0, i;
    
    while (error == 0) {
        printf ("Enter a string (max. 100 characters): ");

    	scanf ("%s", input);
    	getchar();
    	length = strlen(input);
    	error = 1;
    	
    	if (length > 100) {
    		printf("\nError: String length must be between 1 and 100 characters.\nPlease try again!\n\n");
    		error = 0;
		}
    }
    
    for (i = 0; i < length; i++) {
    	reverse[i] = input[length - 1 - i];
	}
	reverse[length] = '\0';
    
    for (i = 0; i < length; i++) {
    	char invert = input[length - 1 - i];
    	if (invert >= 'A' && invert <= 'Z') {
    		result[i] = invert + ('a' - 'A');
		}
		else if (invert >= 'a' && invert <= 'z') {
			result[i] = invert - ('a' - 'A');
		}
	}
	result[length] = '\0';
	
	printf ("\n====================  Result  ====================\n");
	printf ("Inputed string: %s\n", input);
	printf ("Reserved string: %s\n", reverse);
	printf ("Converted string: %s\n", result);
	printf ("==================================================\n");
	
    return 0;
}
//SuniBVerse
//abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789
