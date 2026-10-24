#include <stdio.h>

int main() {
	
	char string[100];

	scanf("%100[^\n]", string);
	printf("#include <stdio.h>\n");
	printf("int main()\n");
	printf("{\n");
	printf("    printf(\"%%s\\n\", \"%s\");\n", string);
	printf("    return 0;\n");
	printf("}\n");
	
	return 0;
}

