#!/usr/bin/env make

	CXX = g++
	OPTIM = -g
	INCLS = -I../
	INCLS = -I../buffer
#	INCLS = -I/tools/2000/X11R6/include
#	INCLS = `pkg-config --libs freetype2`
#	INCLS = `pkg-config --libs libs_Apps`

	dot_EXE=.exec

	# add any -D defines
	DEFS = 

#	# uncomment to see used
#	LINKS = -L/usr/X11R6/lib -lX11
#	LINKS = -L/tools/2000/X11R6/lib -lX11

	S=../src
	VPATH +=$S
	VPATH +=$S/buffer

	include ../MK/MK_with_libs_apps # OK - ish

	PKGS += libs_apps_base1
	PKGS += libs_apps_base2
	PKGS += libs_apps_base2_gtk
	PKGS += libs_apps_bench

#	HDRS += $S/A_point_plus.h
#	HDRS += $S/X_Colours.h
#	HDRS += $S/X_Display.h
#	HDRS += $S/X_Draw.h
#	HDRS += $S/X_STUBS.h
#	HDRS += $S/X_Window.h

#	# LOCAL objs

#	OBJS += A_point_plus.o
#	OBJS += A_Map_W.o
#	OBJS += X_Window.o
#	OBJS += X_Display.o
#	OBJS += X_FontStr.o
#	OBJS += X_ret_err.o
##	OBJS += SPOUT_argv_decoder.o
#	OBJS += STO_ARRAY_u8_of_EIGHT.o
#	OBJS += test_X_two.o

##	OBJS += gdb_invoke.o
##	OBJS += str0.o
##	OBJS += str1.o
##	OBJS += blk1.o
##	OBJS += buffer1.o
##	OBJS += e_print.o

	PROG1=bench_one
	PROG2=bench_two

	EXEC1=$(PROG1)$(dot_EXE)
	EXEC2=$(PROG2)$(dot_EXE)

	ARGV_GDB = INGDB=1 T gdb -tui --cd $(PWD)

all: run_test1

ifeq (0,1)
# include MK_SUFFIXES from MK_ext_lib
.SUFFIXES: .cxx .c .o                                                           
.cxx.o:                                                                         
	$(CXX) $(OPTIM) $(INCLS) $(DEFS) -c $<                                  
endif

# this adds OBJS twice via $^
# so dont use $^ use $(OBJS)
# see .o.exec in MK_SUFFIXES
# it should not hijack things but it does

$(EXEC1): $(OBJS)
$(EXEC2): $(OBJS)

$(OBJS): $(HDRS)

run_test1: $(EXEC1)
	./$(EXEC1)

run_test2: $(EXEC2)
	./$(EXEC2) # "GEN_DOC GEN_PS GEN_SVG"

dgb: $(EXEC1)
	# TODO # Tcl errout when INGDB # the universal main() #
	$(ARGV_GDB) ./$(EXEC1)

ifeq (1,0)
# we no-longer link it - the MK_SUFFIXES .o.exec does
# It uses .. duuno ... vars ...
$(EXEC1): $(OBJS) $(PROG1).o
	g++ $(PROG1).o $(OBJS) $(LINKS) -o $@

$(EXEC2): $(OBJS) $(PROG2).o
	g++ $(PROG2).o $(OBJS) $(LINKS) -o $@
endif

clean: 
	rm -f *.o $(EXEC1)  $(EXEC2)  test2 fa
