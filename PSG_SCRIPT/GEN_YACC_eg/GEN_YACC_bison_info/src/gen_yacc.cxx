
#include "dgb.h"
// that imports errno.h // hmmm not so basic

#include "lex_yacc_UDEF.h"

// NOT in any NAMESPACE //


/*
	_ONE
	_TWO
	_MORE // _THREE is [2] of [4] then [u8] // LIMITS
*/

// class lex_yaxx_UDEF_ONE_t : lex_yacc_UDEF { public:
// #define lex_yacc_BASE lex_yacc_UDEF
#define lex_yacc_BASE lex_yacc
class lex_yaxx_UDEF_ONE_t : public lex_yacc_BASE { public:

	virtual bool build_tree_lex();
	virtual bool build_tree_yacc();

};

bool lex_yaxx_UDEF_ONE_t:: build_tree_lex()
{
	WARN("TODO");
	return PASS("continue");
}

bool lex_yaxx_UDEF_ONE_t:: build_tree_yacc()
{
	return FAIL("TODO");
}



bool bool_main( int argc, char ** argv ) {
	lex_yaxx_UDEF_ONE_t UDEF_ONE;
	if(! UDEF_ONE.build_tree() ) return FAIL_FAILED();

	FAIL("TODO - unwritten");
	// FAIL("ENOENT_is_2 == %d TODO", ENOENT);
	return ENOENT;
}

int main( int argc, char ** argv ) {
	if( bool_main( argc, argv ) ) {
		return 0;
	}
	FAIL_FAILED();
	INFO("errno %d", (int) errno );
	if(errno) return errno;
	return 1;
}
