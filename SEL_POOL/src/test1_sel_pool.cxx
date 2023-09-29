#include "sel_fd.h"
#include "sel_pool.h"
#include "dgb.h"
#include <unistd.h> // read

using namespace BASE::SEL_POOL;

class sel_fd_stdin_test : public sel_fd {
 public:

 	sel_fd_stdin_test() {}
 virtual
 	~sel_fd_stdin_test() {}

	bool sel_says_read()
	{
		if(!is_open()) return FAIL("not open");
		char buff[2048];
		int N = sizeof(buff) - 1;
		N = ::read( fd, buff, N );
		if( N > 0 ) {
			::write(1,buff,N);
			return true;
		}
		return true;
	}
};

obj_hold<obj_ref> keep_fd_obj;

sel_fd_stdin_test * fd;

int main(int argc, char ** argv )
{
	keep_fd_obj = fd = new sel_fd_stdin_test();
	fd->fd_set_nonsocket(0); // WIN32 needs to know these things
	WARN("HERE");
	return 0;
}

