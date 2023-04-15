#include "dgb.h"

bool bool_main() {
	return true;
}

int main( int argc, char ** argv ) {

	for(int i=0; i< argc; i++ ) {
		INFO("ARGV[%d] '%s'", i, argv[i] );
	}
	return 0;

}


