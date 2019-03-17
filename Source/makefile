circbuff : ring.o ring_test.o ../Include/ring.h 
	gcc -o circbuff ring_test.o ring.o

ring_test : ring_test.c ../Include/ring.h
	gcc -c ring_test.c 
	
ring.o :  ring.c ../Include/ring.h 
	gcc -c ring.c 

test_prac: test_prac.c ring.c ../Include/ring.h
	gcc test_prac.c ring.c -lm -lcunit -o test_prac
clean : 	
	rm -f circbuff ring_test.o ring.o

