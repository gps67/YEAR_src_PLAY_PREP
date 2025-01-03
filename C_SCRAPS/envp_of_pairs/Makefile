N=envp_of_pairs

$N.exe: $N.cxx
	g++ -o $@ $<
	./$@ | less

$N.elf: $N.c
	gcc -o $@ $<
	./$@
