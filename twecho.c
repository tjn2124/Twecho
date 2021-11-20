/*
 * twecho
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

static char **duplicateArgs(int argc, char **argv);

static void freeDuplicatedArgs(char **copy);

static char **duplicateArgs(int argc, char **argv)
{

	char** p = malloc((argc+1)*(sizeof(char*)));
	if (p == NULL) {
		perror("malloc returned NULL");
		exit(1);
       	}

	int i, k;
	for (i=0, k=0; i<argc; i++)
	{
		int strLen = strlen(argv[i]);
		p[i] = malloc(((strLen+1)*(sizeof(char))));
		if (p[i] == NULL){
			perror("malloc error returned NULL");
			exit(1);
		}
		
		if(i==0){
			
			strcpy(p[0], argv[0]);
		}

		else
		{
			while (k <strLen){
				char pword = argv[i][k];
				p[i][k] = toupper(pword);
				++k;
			}
			if(k == strLen){
				p[i][strLen] =  '\0';
				k=0;
		}
		}
	}
	p[argc] = '\0';
	return p;
}

static void freeDuplicatedArgs(char **copy)
{
	int i=0;
	while (copy[i++] != NULL){
		free(copy[i]);
	}	
	free(*copy);
	free(copy);
}


int main(int argc, char **argv)
{
    if (argc <= 1)
        return 1;

    char **copy = duplicateArgs(argc, argv);
    char **p = copy;

    argv++;
    p++;
    while (*argv) {
	    printf("%s %s\n", *argv++, *p++);

    }
    freeDuplicatedArgs(copy);

    return 0;
}