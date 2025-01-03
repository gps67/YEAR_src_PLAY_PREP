extern "C" bool bool_main( int argc, char ** argv );

#include "dgb.h"
// that imports errno.h // hmmm not so basic

int main( int argc, char ** argv ) {
	if( bool_main( argc, argv ) ) {
		PASS("OK");
		return 0;
	}

	if(errno) return errno;

	// FAIL("ENOENT_is_2 == %d TODO", ENOENT);
	return ENOENT;
}
