// #include "STO_ARRAY_u8_of_EIGHT.h"
// #include "main_calls_bool_main.h"

	#include "dgb.h"
	bool bool_main( int argc, char ** argv ); // forward decl
extern	bool bool_main_test1( int argc, char ** argv ); // forward decl

	int main( int argc, char ** argv ) { // AUTO
		if( bool_main( argc, argv ) )
			return 0;

		if( errno )
			return errno;

		return 1;
	}

// AUTO moves above to AUTO_main_to_bool_main.h

	bool bool_main( int argc, char ** argv ) { // envp
		return bool_main_test1( argc, argv );

	}


