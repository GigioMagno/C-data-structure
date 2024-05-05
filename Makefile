all:   wordfr fastsearch fork filestat testp testp2 maze hanoi  regine utree listasemplice fattoriale  files fsmsim tsort cerchio


pqueue.o: pqueue.c pqueue.h
	gcc -c pqueue.c

gmatlib.o: gmatlib.c gmatlib.h
	gcc -c gmatlib.c
	
fork:   fork.c
	gcc -o fork fork.c

filestat: filestat.c
	gcc -o filestat filestat.c

testp:  testp.c
	gcc -o testp testp.c

testp2:  testp2.c
	gcc -o testp2 testp2.c

maze:   maze.c uniter.h
	gcc -o maze maze.c

regine: regine.c
	gcc -o regine regine.c

utree:  utree.c
	gcc -o utree utree.c -lm

tsort:  tsort.c
	gcc -o tsort tsort.c

listasemplice : listasemplice.c
	gcc -o listasemplice listasemplice.c

matrix: matrix.c
	gcc -o matrix matrix.c

loadStrings:
	gcc -o loadStrings loadStrings.c
	
files:
	gcc -o files files.c 
	
fattoriale: fattoriale.c
	gcc -o fattoriale fattoriale.c

fsmsim : fsmsim.c
	gcc -o fsmsim fsmsim.c

wordfr: wordfr.c getword.c
	gcc -o wordfr wordfr.c getword.c

fastsearch : fastsearch.c
	gcc -o fastsearch fastsearch.c

cerchio: cerchio.c netpbm.c matrix.c matrix.h netpbm.h
	gcc -o cerchio netpbm.c cerchio.c matrix.c -lm

realclean:
	rm  fastsearch cerchio hanoi tsort listasemplice  fattoriale files fsmsim maze regine  utree fork testp testp2 wordfr filestat 

clean:
	echo "done."
