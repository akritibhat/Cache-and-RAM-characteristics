#include <stdio.h>
#include <unistd.h>

int main() {

    int size = 1024;
    int i = 1;

    while (1) {
         void *p = malloc(i * size);
         if (p == NULL)
            break;
       	    free(p);
            ++i;
    	}
    printf("RAM size: %d KB", (i-1) );
}
