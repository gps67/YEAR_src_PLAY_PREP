#include <stdio.h>

extern char** environ;
// obtain from libc via (RTFM)

int main(void) {
  size_t i = 0;
  while(1) {
  // environ is an array of STR eg "NAME=VALUE" // NUL terminator STR0
  // final environ[N] is set to NULL by LIBC // break //
   char * pair = environ[i++];
   if(!pair) break ;

    // Parse NAME=VALUE NUL
    char * P = pair;
    while(char c1 = * P ++ ) { // while not nul
    	if( c1 == '=' ) {
	// PREV P was where = was found
	// UPTO = was NAME optional GAPS
	// *(P-1) = EXPR // overwrie BYTE where "=" was
	// STR0 pair = "NAME=VALUE" NUL of STR0
	// STR0 pair = "NAME"X<---- NUL of STR0 // original mangled // UNDO
	// ABOVE needs a lock, or LIST
	// VALUE = P
		*(P-1) = 0x00; // ASCII_NUL
		printf(" %30s = %-13s \n", pair, P  );
//		printf(" NAME %-30s VALUE %-13s CMNT %s\n", pair, P, "%s" );
//
// eg           SSH_AUTH_SOCK = /run/user/1016/keyring/ssh 
//
//

		*(P-1) = '=' ; // ASCII_NUL // UNDO //
		break; // while looking for =
	}
    }

  }
  return 0;
}
