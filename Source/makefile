circbuff : ring.o ring_test.o ../Include/ring.h 
	gcc -o circbuff ring_test.o ring.o

#ring_test : ring_test.c ../Include/ring.h
#	gcc -c ring_test.c 
	
ring.o :  ring.c ../Include/ring.h 
	gcc -c ring.c 

ring_test: ring_test.c ring.c ../Include/ring.h
	gcc ring_test.c ring.c -lm -lcunit -o ring_test

clean : 	
	rm -f circbuff ring_test.o ring.o

