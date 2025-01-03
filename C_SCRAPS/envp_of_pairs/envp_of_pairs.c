#include <stdio.h>

extern char** environ;
// obtain from libc via (RTFM)

int main(void) {
  size_t i = 0;
  while(1) {
    printf("LOOP ");
   char * pair = environ[i++];
   if(!pair) break ;

    char * P = pair;
    while(char c1 = * P ++ ) {
    	if( c1 == '=' ) {
		*(P-1) = 0x00; // ASCII_NUL
		printf(" NAME %s VALUE %s \n", pair, P );
		break; // while looking for =
	}
    }
    printf("%s\n", pair );

  }
  return 0;
}
