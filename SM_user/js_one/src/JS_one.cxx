#include "dgb.h"

#if 0 // COMMENT
/*
  JS_one.cxx
	JS1

		CXX SCRIPT 
		 PARSED into PSG_TREE
		  GEN CXX_SCRIPT // loops into same
		  GEN cxx_of_SCRIPT // SUBSET EXACT SAME // LOTS MACROS //
		  // that loses CXX original but could keep along with XPOS
		  GEN FILE LINE in generated cxx // OPTION SHOW ORIGINAL CXX
		 RUN COVERAGE
		  RUN a list of tests 
		  maybe mark test code that is not to be cached
		  maybe mark test code that is to be cached
		  RUN a list of tests to PRE_LOAD and PRE_BUILD cache
		  GEN cxx to CTOR cache // add to LIBR and JIT_LIBR
		  // MODE == "PRE_RUN" || MODE == "RUN" || "RT" 
		 GEN_MODULE
		  GEN cxx and CXX above
		  ON NEXT RESTART
		  CTOR MODULE from EXE then DATA then KEPT_STUFF
		  STILL run the PRE_RUN stuff, but it is already fast
		  SHOULD TEST DATA IN PRE_RUN

		CXX MODULE 
		 WITHOUT any CXX special data, pure JS_OBJ and UDEF_TABLES
		 WITH CXX_STRUCT and CXX_VTBL or C_OBJ_by_IDX // cxx really

	 NODE is calling our MINI_MACHINE

	 	SCRIPT exports VARIABLES to global object of SUB_session

		SCRIPT exports THREAD_VARIABLES_MINI_MACHINE

			MINI_MACHINE
			 PRINT_HEAD
			  VARS
			  VARS
			  CONST_OPTS
			  LINK_PROFILE
			  LINK_DOCUMENT_BATCH_CTRL

		PAGE is SCROLL
		PAGE is A4 // or whatever
		  gen SCROLL with autodetect SPLIT_PAGE_NEAR_HERE
		  gen SCROLL in pass one
		  SPLIT_PAGES in pass two
		  EMIT_PAGES in pass DONE

		  OPTION attempt to not need ALL doc loaded, COMMIT_NEXT_PAGE
		  eg after 2xA4 infor must be SPLIT_PAGE_NEAR_HERE result
		  it should return when it is certain of best of 2 choices

		  often 1 paragraph into next page, wont fit on this page
		  split before that paragraph
		  reclaim layout from this most_fill_page

		  OPTION squashed --meets-- stretched PAGES
		  EXTRA pass, with FORK OPTIONAL ROUTES

		  optimise layout
		  print page // commit to PAGE_kept_in_STREAM_on_DISK // FIXED
		  OPTION next PASS reloads PAGE from saved MMAP
		  CACHE makes edit regen fast
		  CACHE makes RUN slight faster ONCE
		  A thousand times faster with DEVELOP_EDIT RE_RUNS
		  Directly to SIGNAL CSR to next error in source

		MINI_MACHINE
		  groff SUBSET
		  YACC_FSM_BUILDER
		  WEIGHT_BRANCH_X_COUNT_X_COST
		  GEN_LIST_in_SORT_ORDER // after run test suite // from db_load
		  db_save after running many samples
		  db_load with NEW_VALUES not in test set somehow

		  DIR FILE LINE XPOS CODE_POINT STREAM2
		  write CODE for MACRO into TREE_BUFF
		  pass MACRO as EXPR 
		  pass TEXT as EXPR
		  pass FILTERED_TEXT as TEXT

		  DECL MK_VAR  { u64 EA_VAR } { i64 VAL } } // { VAR VAL } // %s
		  %s INIT_VAL or CMNT // not easy to tell // {1234} 





		adds JS_EVAL _t EXPR_t VAL_t CPU_THREAD_JS_CXX
		adds_JS_CXX _t MODULE _t
		adds_CXX_MODULE
		adds_JS_CXX_MODULE // JS == SM == {" Spider Monkey "} // WK_LEX
		// FORCED SPACING // SIMPLEST EXACT or NB_NAME // TOKEN(" ( ")
		// CXX compiles LIST into { ITEM_t & ITEM = LIST[idx] }
		// MATCH 
		// CXX compiles LIST into
		// { ITEM_t & ITEM = LIST[idx] }
		ITEM_t & ITEM = LIST[idx] // CODE_POINT XPOS /* _of_ITEM */
		// BENCH += EA ITEM == "EA_ITEM" // BINGO // FIAT TOKEN is "OWN_NAME"
		// THIS THAT TOTHER // THIRD // UDEF // YOUR_SCOPE_HERE //

		AUTO_ADDS JS = new JS_t ( 
			RUNTIME_t RUNTIME
		); // CXX dialecl of CXX_MODULE_API ITEM_TYPE THIS THAT THIRD

		JS.EVAL( ARGV ) // ARGV is JS_OBJ_t // JS_OBJ == "JS_OBJ" "_t"
		// CXX compiler merges those Q2 adjacents / THATS HOW MUX
		// MUX // Q2 Q2_text Q2 Q2 // "JS_OBJ" // PSG_DETECT MATCH %s
		// MATCH // Q2 Q2_text Q2 Q2 // "JS_OBJ" // PSG_DETECT MATCH %s
		// FOUND // { "JS_OBJ" } // ATOM LOCN ITEM STO { %s ANYSTR }
		// USAGE ident TOKEN in MODULE in SESS RT == "RUNTIME"
		// USAGE NEW_ID "ident" TOKEN in MODULE in SESS RT == "RUNTIME"

		// INTERP "ident" as "EXPR" // COMPILER CACHES EA { "EXPR" }

		adds a module to V8

			"Module Name"

				GET "module.item" ...
				GET "module.func ARGS CODE_POINT" ...
				GET "second.expr" // "%s.%s" second expr //
				GEN "%s" expr // FILTER PRINT expr to "%s" //
				BENCH MK_TYPE "expr" "expr_t" "_t" "EXPR" "%s"
				ALIAS expr { STR0 expr } 
				  ALIAS
				  expr
				  { STR0 expr } 


			"include Module Name" // not cident - has sp_DETECT Q2

				DECL SPEC { SCRIPT } // ITEM_t & ITEM = NEW_EXPR ARGS
				API NEW CTOR ARGS 

				SPEC_LIST -alias- SPEC_POOL 

					choice of LIST as POOL
					choice of POOL as LIST

				SPEC_POOL

					DECL CLASS "OBJ_TYPE"

				SPEC_POOL

					DECL CLASS OBJ_TYPE 

					PSG += DECL_TYPE_STMT

					PSG gets CXX to near cxx

					GEN += hand_written_CXX_SCRIPT 

					CXX += PSG_UDEF { SCRIPT }

					// MK_VAR "SCRIPT" CTOR_VAR_CALLED 

			"include Module Name" // not cident - has sp_DETECT Q2

				// CONST TYPE SPEC FIELD CLASS VAR EXPR //

				As ITEM of type { MODULE_as_ITEM_t ITEM }

				As ITEM of data { nbytes ITEM } // BOUND PAIRS TWISTS
				PSG MATCH notes switch { PICK nbytes } { PICK ITEM }
				PSG MATCH notes switch { nbytes ITEM  }

				// LEX_POOL += ... { MODULE_as_ITEM_t ITEM } ...
				// LEX_POOL += ... { nbytes_t nbytes } ...
				// LEX_POOL += ... { nbytes_t ITEM } ...
				// LEX_POOL += ... { nbytes ITEM } ...
				// GEN has to imagine an available FABRIC
				// in doing so it uses an ALIAS "%s" ANYSTR
				// RESTRICT { ANYSTR cident99_t ANYSTR }
				// TUPLO NAME { ITEM_T ITEM }
				// TUPLO NAME { { ITEM_T_t ITEM_T } { ITEM_t ITEM } }
				 // TUPLO ITEM = ITEM || EXPR || EA_EXPR 



			"include Module Name" // not cident - has sp_DETECT Q2

				IDR LAYOUT

				 SRC/group
				  group == "lib_base"
				  feature == "buffer"
				  filename == "CLASS_NAME.cxx"

				  	named after primary struct

					global scoped so DIALECT += VOCAB
					also local_var local_name

					IDE require classname be plainfilename
					IDE require classname be %s
					IDE require classname be { classname be %s }
					{ classname %s } // ADJACENT ADD ON DATA

					LOCN += VAR
					LOCN += API // MODULE { TREE } { TREE ITEM }

			"include Module Name" // not cident - has sp_DETECT Q2

				EXAMPLE SCRIPT FRAGMENTS

					ITEM_t & ITEM = lookup( ANYSTR )

						if_absent retry with 

						{ int idx = N++; }

						ALLOC IDX = above.idx

							RT BIND ITEM
							above is VAR of HERE
							above.idx is HERE
							IDX == HERE

				EXAMPLE SCRIPT FTAGMENTS

					above.idx is HERE

						// IMPORTED // AUTOGEN //
						{ int idx = N++; }
						// EXPLAIN // idx = ALLOC idx
						// EXPLAIN // { i32 N } // plenty
						// EXPLAIN // BABEL has no _t //
						// EXPLAIN { int N init 0 }
						// EXPLAIN { int N init N } // PRESET
						// GEN AS_VAL "N" // GETTER
						// GEN AS_VAL "int N" // DECL

						// EXPLAIN // HERE is POS_in_TREE
						// EXPLAIN POS_t POS // EA_CSR //
					ALIAS this self THIS THAT OBJ "%s"

						// AUTO_LANG sees "%" as TOKEN
						// TOKEN MATCH "%s"
						// Q2 %s Q2 // SUBLEX_STEPS
						// { %s "\"%s\"" }
						// { %s "%s" } // WELLKNOWN

						ANYSTR is cident

						ANYSTR is TEXT incl cident_expr

						ANYSTR is "%s"
						ANYSTR is  %s 
						ANYSTR is  { %s }
						ANYSTR is "{ %s }"

						// NOT_USUALLY  "{%s}" // ODLY
					
					EXPR 
						VAR_FIELD
						VAR_FIELD.STEP
						VAR_FIELD_STEP_field_one

			"include Module Name" // not cident - has sp_DETECT Q2
			include field_of_struct

					EXPR

						field == "VAR_FIELD"
						name = field
						expr = CODE ARGS
						CODE == CODE_POINT
						CODE_POINT = "CSR_on_a_VAR_FIELD"
						DECODE CSR VAR_FIELD 
						// AUTO_JOIN _t using typedef or macro
						// PICK AUTO expand FIELD_NAME
						// PICK AUTO expand FIELD_TEXT
						// PICK AUTO expand FIELD_IDX
						// PICK AUTO expand FIELD_CODE

						// PICK_AUTO MATCH FIELD_IDX
						// PICK_AUTO MATCH CODE_POINT
						// PICK_AUTO XPOS_of_this_STMT
						// PICK_AUTO XPOS_of_this_ITEM
						// VAR_NAME = decode( ANYSTR )
						// VISITOR will have to RUN each OPT

					EXPLORE

						FILTER over entire SOURCE TEXT

						LIST all CT PRAGMAS

						BUILD via MAKEFILE

						 two files per class .h .cxx

						OPTIONS any number of CAT LIST 
						 
						 filename.ext

						 filename == name
						 name == "classname"
						 name == "groupname"
						 name == "ALIAS"
						 name == "ALIAS %s"
						 // MATCH and ACT_on_MATCH //
						 // "ATTRNAME ATTRVAL"
						 // EXPLAIN ATTRNAME "ALIAS"
						 // EXPLAIN ATTRVAL "%s"
						 // EXPLAIN ALIAS "{ %s }"
						 // FOOTPRINT TOES
						 // in LEX_LANDSCAPE from single

						 // PARSER gets optimised
						 // by putting the fastest first
						 // well hopefully
						 // and it is still a 2GHz CPUx2

						 // CACHE learns_ONE "%s"
						 // CACHE learns_TWO "{ %s }"
						 // CACHE learns_ELSE "PARSE { %s }"
						 // that auto knows SP // GAPS //

			"include Module Name" // 

				CXX declares a JS_MODULE // TODO whatever that is
				CXX declares a CXX_JS_MODULE // TODO actually quite clear
				CXX GEN writes a CXX_JS_MODULE // TODO actually macro AUTO options

					DECL CXX CLASS
					EXPR CXX CODE

					OBJ . EA_FIELD
					OBJ . EA_FIELD_VAR // ie 
					OBJ . SPEC_FIELD_BASE

					write code for VAR_POOL
					write code for VAR_NAMED
					write code for OBJ_FOUND # with expected subtype cxx checks!

					EVAL CALL ARGS
						global_object = OPTION_USE
						ARG starts with VAR _local _stack _global _future

				write CXX for each code path

					lots of callable expressions and macros
					GEN duplicate input // transparent filter
					GEN exact source // REGEN_CODE INIT_CODE SCRIPS DATA EXTRA
					GEN cxx for theose CXX steps, with API_TABLE goto STEP

					MINI_MACHINE

						STEP
						access to local variable
						LOCK ACCESS to STEP_KEPT
						get adequte match, YACC + good source means FAST
						only CTOR INIT ans stay within this thread

					 STEP { SCRIPT }

						if STEP_Q2 
						 OK
						else
						 NO_MATCH

					 JIT compiles SCRIPT and EMITS_CODE

					 	PARSER FOUND { ... }

						if CALL_NO_ARGS
						 OK
						else
						// OPTION FAIL_WITH NO_MATCH
						// OPTION CALL_DEFAULT or FAIL
						// OPTION FAIL is NO_MATCH // fast restart next alternate
							ACTIVATED by NO_MATCH
							MATCH NO_MATCH // found in MINI_MACHINE_SOURCE

					 JIT COMPILES SCRIPT and emits cxx

					 	thats not really JIT,
						but maybe it has to be

						simply throw generted JIT code away
						or run it to CTOR the SEGMENT in INIT RESTART ETC
						the main side effect it preparing to write the cxx
						build the tree of source 
						print the tree of compiled source

						call TEST1 to generate that code run with that data
						call 1a 1b 1c 1d 
						call DATA_ITERATE // PROPERLY //
						PRE_TRAVEL_CSR_BOTH_SIDES_OF_IF 
						GEN callable ON_TRUE ON FALSE // GOTO
						GEN callable EVAL_EB 
						 GEN GEN CODE_EB %s
						 GEN GEN CODE_THEN %s
						 GEN GEN CODE_ELSE %s
						 GEN GEN CODE_END_IF // PSG CODE_POINT in MACRO DECL
						 GEN GEN CODE_GOTO_NEXT_STATE_MENT // JOIN in SPACE

					 SLOW_JIT builds SCRIPT_COMPILED_99.dll // BATCH prepare

					 	calls gcc runs_GEN // IS_MODULE
						calls gcc links_module // DLL_MODULE_SEGMENT

					 SLOW_JIT_GEN_cxx

					 	Lots of CXX is simple cxx, repeat SELF

						REGEN_CXX is a clever thing,
						so to do something manually
						is maybe to write an EXPR that can be repeated
						BENCH EXPR optimises rebuild development

						CXX generated from parsed CXX
						outputs a PSG tree = PARSED_CXX
						outputs a prog that CTORS that CXX_TREE
						auto indent site style VAR_CAUSES_STANZA

						MUX // CT // pretty_print_code_to_page CODE PAGE
						




			"include Module Name" // not cident - has sp_DETECT Q2

		SP and GAPS

			The FAST PARSE includes

				direct utf8_match SUBSTR EXACT

			The MAIN PARSE is SCRIPTED

				try EACH from LIST // MATCH_first_match
				try EACH from LIST // MATCH_best_match
				try EACH from LIST // MATCH_LIST_EXPR

				SCORE MATCH 

					INTO AUTO_VAR field_of_self

					 EACH

						EXPR_SCORE_t SCORE; // VAL
						EA_CODE_t CODE_POINT; // PSG_DATA

					 POOL

					 	ITEM == POOL[ ITEM_idx ]

		CODE+=				XPOS == "CODE_POINT[ idx ]"
		CODE+=				XPOS ==  CODE_POINT[ idx ]
		CODE+= one_source_line || LINE || LIST || MULTI_PART_LINE || UDEF
		CODE+=PARSED_LINE ...

		AUTO_DETECT DOUBLE DIFFERING DECL of SAME THING
		{ CODE_POINT idx }
		XPOS { CODE_POINT idx }
		{ XPOS { CODE_POINT idx } }
		BENCH KNOWS they are the same but OPTION WITH/OUT BRACED
		BENCH KNOWS from PARSER choice of "SPELLING" 
		BENCH repeat MATCH SAME_WORD
		// manually specifying PARSE LIST (edit via UIF) then source
		//
		// LUCKY DECLS PARSED and RAN OK CTOR PRE START //
		// SPELLING == "SPELLING"
		// SPELLING == "Q2 NOSP SPELLING NOSP Q2" // "JS_OBJ" //
		// SPELLING == "Q2 SP cident SP Q2" // " cident_t " //
		// GEN AUTO upgrade ITEM_t to ITEM // .name // .EA // get_ABC()
		// cident_t VAR_NAME // KNOW += cidet == "cident" "_t"
		// cident_t VAR_NAME // KNOW += "VAR_NAME" // cident_t VAR_NAME;
		// DIALECT search own scripts for AUTO_GEN items
		// "VAR_NAME" created a node at CT // at RT it does ... API
		// SPELLING == "SPELLING"
		// VAR_NAME == SPELLING == "SPELLING" // BENCH //
		// SPELLING == "Q2 SP SPELLING SP Q2" // " JS_OBJ " //
		// SPELLING == "Q2 NOSP SPELLING GAP Q2" // ["JS[HERE GAP Q2
		// SPELLING == "Q2 SP SPELLING GAP Q2" // [" SPELLING[HERE GAP Q2
		// SPELLING == "Q2 GAP SPELLING GAP Q2" // "Q2 GAP SPELLING GAP Q2"
		// GAP == ONE_OF { NOGAP GAP SP TAB NUL RANGE_LIT /* DONT_STEP_OVER_NUL # NOT YET */
	
	RANGE_LIST

		0-9
		A-Z
		a-z
		_ - + 
		/ 
		Q2 // invoke some BIND search compile corouting - via Q2 TOKENISD BIND to name "Q2"
		Parse can then resolve that so that {"\""} triggers ON_Q2 from_as VAL_IS_Q2 

			SUBLEX { CH == Q2_ASCII } // Q2 //

			connect UPPER and LOWER PSG_FSM_TABLES // DONE by CTOR and from CT_RT

			emerge from SUB_MATCH_Q2

				parallel several emerge

					ZERO'th was never called it was KNOWN // '

						Q2_FOUND // CH passed by in STREAM at XPOS nearby

					ONE emerges with Q2_FOUND or FAIL to try TWO

					TWO emerges with Q2_FOUND or FAIL to try TWO
					LIST emerges with Q2_FOUND or FAIL to DEFAULT is to FAIL exit

				search

					dont be scared off by not matching "Q2_FOUND"
					the caller has already optimised its use in a PSG

					well not optimised but adequate
					followed up by searing cache speeds
					runtime int idx = PICK
					runtime call_DECODE_idx { idx_t idx } // BOTH_BIND idx
					// BOTH_BIND is a suggestion // you can switch with UDEF_VERN

					CPU i64 RET_VAL = CALL( A B C D ) ARGS 
					// 4 CPU WORDS yet to be written to STACK SHADOW
					// so doing nothing does nothing // CT calc stack offs
					// WE WILL NEED A CALL API // EXACT 4 args are FAST

		if CHR in CSET_SUBSET

		GEN_ASM
		if STEP_Q2 MATCHES
		 know_now_know Q2_FOUND
		if STEP_GAP_Q2
		 know_now_know Q2_FOUND
		else NO_MATCH

		// THEN

		if STEP_GAP GAP_FOUND
		 OK

		// THEN

		if STEP_cident cident
		 OK
		else
		 NO_MATCH

		if STEP_GAP   GAP_FOUND
		 OK

		 MATCH cident // MATCH_cident cident // CODE_POINT LANG_SAYS_exact_match_name

		 	cident taken from earlier AUTO_DECL - put into EXPORTED known as "cident"

		 MATCH { CIDENT ANYSTR }
		 MATCH { VAR_NAME "%s" } // but still OBJ_t & OBJ = EVAL THIS_VAL_VAR_known_as(STR0)
		 // BENCH creates varname "VAR_NAME"
		 // BENCH creates varname "UDEF"
		 // BENCH creates A_VAR TYPE NAME DATA EXPR


		 MATCH text // MATCH_text text // CODE_POINT LANG_SAYS_exact_match_name





						 ext == ".h"
						 ext == ".cxx"
						 ext == ".o"
						 ext == ".a"	// filename == "groupname"
						 // lib %s .a // JOIN THE GAPS
						 // multiplexor parser perpares
						 // WORD lib
						 // WORD %s cident // name
						 // WORD .a
						 ext == ".lib"
						 ext == ".dll"
						 ext == ".so"



			Q2 makes it not a coincidence "STR0" MATCH LEX



		adds a module to V8

			name
			const
			type
			var
			expr
			code
			funcs
			import_api
			export_api
			global_api

			type.t.func.f // least syntax surrounds "f" BIND_OBJ


		adds a module to V8

			module name

			module LIBR // API to LANG == "LIBR" // HERE_CODE //

			module CPU // API to THREAD { ACK = get_THREAD_API(REQ) }
			module ACK // VOCAB += ITEMS POOLS VARS UDEFS NOUNS VERBS LIBR DIALECTS EXPLAINED_as_CODE CODE TABLES IO STO ALIAS POOL

			module VOCAB // ITEM = ALLOC IDX ADDR // into NAMESPACE

			item IDX

			item STO // nbytes // ITEM_t ITEM // STO.ALLOC.item

			// PSG allows VOCAB to grow with UDEF PSG MATCH
			// VOCAB += PSG
			// PSG += { new ITEM_t }
			// PSG += { new ITEM_t  & ITEM }
			// PSG += { new ITEM_t  & ITEM } { NEW ITEM _t }
			// PSG += { new ITEM_t  & ITEM } { NEW ITEM _t } {
			// }
			//	ITEM_t == "ITEM_t"
			//	ITEM == "ITEM"
			//	ITEM == "ITEM_t & ITEM"
			//	_t == "_t" // LOCN == TOKEN == THIS_t("ITEM_t")
			// THIS_t(Q2_STR0) "ITEM" "_t" //
			// MACHINE created ITEM _t as { ITEM_t ITEM } 
			// FLEXI_MACHINE adds LOADABLE_TABLE_MACHINE API
			// MODULE == "API"
*/

#endif // COMMENT

bool bool_main() { return true;
}

int main( int argc, char ** argv ) {

 INFO("CALLED");
 return 0;

}

