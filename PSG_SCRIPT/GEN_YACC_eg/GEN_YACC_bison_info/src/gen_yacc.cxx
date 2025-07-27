
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

// TODO // OBJV // how to tell if WORD == PTR == STR0 // WEIGHT
// TODO // WRAP ARGV into OBJV

// TODO // PARSE_SCRIPT _into_TREE // CALL ARGV or CALL SCRIPT as_SESS
// TODO // STO SESS_STO // STO = SESS_STO // local ABBR for ITEM AVAR

// TODO // PSG SUB_LEX // 

bool parse_ARGV_bool_main( int argc, char ** argv ) {
	//
	// Parse_ARGV
	// call BOOL_MAIL // CT_RT has VALUE= PICK MACRO from LIST and WRAP CODE
	//
	// PID EXIT is errno // via_FILTER // ZERO_means_PASS _DONE //
	//
	lex_yaxx_UDEF_ONE_t UDEF_ONE;
	if(! UDEF_ONE.build_tree() ) return FAIL_FAILED();

	FAIL("TODO - unwritten");
	// FAIL("ENOENT_is_2 == %d TODO", ENOENT);
	return ENOENT;
}

bool bool_main( int argc, char ** argv ) {
	// 
	// sweep_environ_once(); // called from here // loaded to table
	// or called from main()
	// 
	/*
		every mini app provides %s_bool_main(argc, argv) // envp 
		//  extern char **environ; // NULL terminated array of STR0
		// STR0 == NULL // end_of_list_marker // OPTION ABSENT NULL
		// STR0 == "NAME=VALUE" // 
		// so there is no reason to require enp from main
		// OPTION set environ from PRE_LOAD or FILTER
		// avoid use in code other than as glibc feature
		// we sweep environ once 

		TODO ADD envp and C_STACK has introspection

		SESS has what Tcl would call ClientData a 64_bit LOHI WORD
		LOHI is required 
		EXPR is ALWAYS as the i48 needs to be extraced from the i64
		EXPR is i8_i8_OPCODE i16_Payload i32_Payload i64_WORD u64_WORD
		ADDR is when i48 is i64 is PTR # ALIAS PTR EA ADDR AREF IDX
		EXPR is i8_i8_OPCODE i16_zero i16_one i16_two

		 i8_i8 OPCODE is enough to perform entire CPU TRANSACTION BATCH

			 i8_i8 OPCODE 
		EXPR is
			i8_i8_OPCODE
			i16_Payload
			i32_Payload
		or
			i64_WORD
		OPTION or -see LIBR_SIGN // AUTO $next_line is ENTIRE WORD

			// LIBR_CPU uses u64 a LOT
			// BITFIELD u16_i16_i16_i16 // SIGNED under UNSIGNED
			// BITFIELD usually uses 2 shifts second SIGNED or NOT
			// BITFIELD_TOP only needs 1 shift SIGNED obvs
			// BITFIELD ENTIRE needs 0 shifts CPU provides SIGN
			// BITFIELD ENTIRE LIBR.SIGN 
			// BITFIELD ENTIRE LIBR.SIGNED // BYTE_FIELD ENTIRE
			// BITFIELD ENTIRE LIBR.UNSIGNED // ENTIRE UNS
			// BITFIELD CPU_MODE _HALF
			// _HALF _or_PARTIAL or_BITFIELD or_COMPLETE
			//
			// HALF_HALF
			// HALF_HIGH
			// 
			// HIGH_HALF // BIT order in DIAG // LOHI in MEM
			// i32_i32 provides 
			// 
			// We wrote LIBR with 2 mindsets
			// CPU_32 can load HALF_HIGH
			needs 0 shifts CPU provides SIGN
			//
			u64_WORD
	*/
	return parse_ARGV_bool_main( argc, argv );
}

// USAGE STYLE { before EOLN AUTO catches { HERE } } // not next line
// USAGE STYLE { AFTER BOLN AUTO catches { HERE } } // needs next line AVAIL

bool sweep_environ_one ( int argc, char ** argv ) {
	return PASS("copy environ to MMAP area register EA_NAME in TABLE");;
	return TRUE;
	return INFO("TEMPLATE of APP_MAIN # it creates TOKEN of SPELLING");;
	return INFO("ROM reuses SPELLING as P0P2 or STR0");
	return INFO("SPELLING as P0P2 from STR0");
	return INFO("PARSABLE SPELLING as P0P2 from P0"); // cident97 
	return INFO("see libs_apps TOPAPP_Task.h"); // TODO

	// C_ident_97 // _97 is SESS_says_PICK_97_for_99 // 99 is iso_99
	// vfs_ident_97 // vfs is users prefs adds +-= adds SP _or_NOT
	// CXX_ident_97 // CXX can start with DIGIT and AUTO rename
	// CXX_intro ALWAYS_adds_DUNDER_prefix // so a1 = a2
	// SUB_LEX ALWAYS_adds_LHS // so a1 = a2 // of whatever _97 says
	return TRUE;
	return FAIL("unwritten");;
}


int main( int argc, char ** argv ) {
	if( !sweep_environ_one(argc,argv) ) {
		goto failed; // perfectly acceptable in DIALECT
	}
	if( bool_main( argc, argv ) ) {
		return 0; // nothing more to say // DONE // OK //
	}

	// C++ can goto failed // very easy just call END_SCOPE DTOR
	// C++ can endscope // all in funcs anyway // nothing to do
	// LIBR should if(!errno) then search for APP LIBR API error
	// LIBR should if(!errno) then set it to 22 then ask LIBR
	// UDEF this is what libs_apps TOPAPP_Task.h should wrap

 failed:
	FAIL_FAILED();
	INFO("errno %d", (int) errno );
	if(errno) return errno;
	return 1;
}
