
FASM_dir=/home/gps/YEAR/src_build/fasm
FASM=$(FASM_dir)/fasm.x64
NASM=nasm # does not compile
XASM=$(FASM)
# produces .o when "format ELF" is in source text # else .bin
#

# each dir is search PATH sep is .. what ...
INCLUDE += $(FASM_dir)/examples/elfexe/dynamic
export INCLUDE

test_a1: a1.dump a1.exec

test_c1: c1.dump c1.exec

c1.exec : c1.o
	gcc -o $@ ./$<

c1.o: c1.c
	gcc -c -o $@ ./$<

c1.dump: c1.c
	gcc -S c1.c -fverbose-asm -Os -o - | tee c1.dump



test: a1.exec a1.dump
	./$<

a1.exec : a1.o
	gcc -m32 -o $@ ./$<

a1.o: a1.asm
	$(XASM) $<

a1.dump: a1.o Makefile
	@# objdump -D -C -g -e -l -S a1.o > a1.dump
	objdump -D a1.o > a1.dump
#	@cat $@

Xa1.o: a1.asm
	$(XASM) a1.asm

clean:
	rm *.o *.exec *.dump
