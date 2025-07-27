//#include "amnt_t.h"
//#include "date_glib.h"
//#include "dset.h"

#include "w_widget0.h"
//#include "w_file_sel.h"
#include "bench_top_app.h"
#include "TOPAPP_Holder_gtk.h"
#include <locale.h>

using namespace APPS;

//! linux calls __START_RTFM_ libc calls main()
int main(int argc, char ** argv )
{
	// holder does this // setlocale(LC_ALL,"");
	// run the init functions in an incomplete environment
	// decode_argv() would recognise # COMMAND FILENAME //
	char * filename = NULL;
	if( argc == 2 ) {
		filename = argv[1];
	}
	// extra { braces } ensure local vars get CTOR done within function
	{
		// This does NOT change with each new applet, holds base_class
		// see LIBR for base_class options
		// your derived UDEF is bench_top_app 
		TOPAPP_Holder_gtk holder(&argc, &argv);
//		new BENCH::bench_top_app( &holder, filename );

		// based on a LIBR_base_class_for_any_app
		// you derive bench_top
		// the CTOR also installs SELF into HOLDER
		// TODO setup on_EXIT() to tell holder and DTOR happens
		// TODO delay DTORS into a HIGH_NEED_DTOR and SKIP_DTOR
		// filename would be argv_decoder or TASK scedule or SCRIPT
		new bench_top_app( &holder, filename );
		// bench_top CTOR installed a lot of CODE vectors
		// bench_top C++ class provides "app" as a class += code
		// you write bench_one_app( &holder, TODO_ARGV )

		// the main REPL loop is gx_main and installed onEvent vectors
		holder.call_gx_main_and_exit();
		// but exit means DTOR might never get called
		// so we adapt, knowing DTOR is called after exit() - ie not
	}
	ref_tally.print_leaked_report();
	return 0;
}



/*!
	bench_top_app is to be replaced with UDEF
	bench_top_app already is a GUI WINDOW with a MENU main PANEL and MORE
	bench_top_app is an APPLET or APP running within DESKTOP BENCH
	bench is currently DESKTOP # future BENCH as BENCH for TASK 
	TOP_APP is kept alive by main_window and some tasks
	TOP_APP can kill those tasks, if you are sure about that
	TOP_APP is a future APPLET # DESKTOP is shared GUI space
	GUI_TOP_APP is UDEF_BASE

	GUI_TREE_WALK is mc starter


	Initially each APP has it's own MAIN_WINDOW
	Already each APP has XCX own FILE or TASK
	Ticket becomes a TASK becomes an active APPLET





*/
