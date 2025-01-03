#include <stdio.h>

extern char** environ;
// obtain from libc via (RTFM)

int main(void) {
  size_t i = 0;
  while(1) {
   char * pair = environ[i++];
   if(!pair) break ;

    char * P = pair;
    while(char c1 = * P ++ ) {
    	if( c1 == '=' ) {
		*(P-1) = 0x00; // ASCII_NUL
		printf(" NAME %-30s VALUE %-13s CMNT %s\n", pair, P, "%s" );
		*(P-1) = '=' ; // ASCII_NUL // UNDO //
		break; // while looking for =
	}
    }

  }
  return 0;
}
