CFLAGS = -Wall -fpic -coverage -lm

rngs.o: rngs.h rngs.c
	gcc -c rngs.c -g  $(CFLAGS)

dominion.o: dominion.h dominion.c rngs.o
	gcc -c dominion.c -g  $(CFLAGS)

playdom: dominion.o playdom.c
	gcc -o playdom playdom.c -g dominion.o rngs.o $(CFLAGS)
#To run playdom you need to entere: ./playdom <any integer number> like ./playdom 10*/
testDrawCard: testDrawCard.c dominion.o rngs.o
	gcc  -o testDrawCard -g  testDrawCard.c dominion.o rngs.o $(CFLAGS)

badTestDrawCard: badTestDrawCard.c dominion.o rngs.o
	gcc -o badTestDrawCard -g  badTestDrawCard.c dominion.o rngs.o $(CFLAGS)

testBuyCard: testDrawCard.c dominion.o rngs.o
	gcc -o testDrawCard -g  testDrawCard.c dominion.o rngs.o $(CFLAGS)

testAll: dominion.o testSuite.c
	gcc -o testSuite testSuite.c -g  dominion.o rngs.o $(CFLAGS)

interface.o: interface.h interface.c
	gcc -c interface.c -g  $(CFLAGS)

runtests: testDrawCard 
	./testDrawCard &> unittestresult.out
	gcov dominion.c >> unittestresult.out
	cat dominion.c.gcov >> unittestresult.out

unittestresults.out: dominion.o rngs.o
	gcc -o u1 -g unittest1.c dominion.o rngs.o $(CFLAGS)
	./u1 &> unittestresults.out
	gcov dominion.c -b >> unittestresults.out
	
	gcc -o u2 -g unittest2.c dominion.o rngs.o $(CFLAGS)
	./u2 >> unittestresults.out
	gcov dominion.c -b >> unittestresults.out
	
	gcc -o u3 -g unittest3.c dominion.o rngs.o $(CFLAGS)
	./u3 >> unittestresults.out
	gcov dominion.c -b >> unittestresults.out
	
	gcc -o u4 -g unittest4.c dominion.o rngs.o $(CFLAGS)
	./u4 >> unittestresults.out
	gcov dominion.c -b >> unittestresults.out
	
	gcc -o c1 -g cardtest1.c dominion.o rngs.o $(CFLAGS)
	./c1 >> unittestresults.out
	gcov dominion.c -b >> unittestresults.out
	
	gcc -o c2 -g cardtest2.c dominion.o rngs.o $(CFLAGS)
	./c2 >> unittestresults.out
	gcov dominion.c -b >> unittestresults.out
	
	gcc -o c3 -g cardtest3.c dominion.o rngs.o $(CFLAGS)
	./c3 >> unittestresults.out
	gcov dominion.c -b >> unittestresults.out
	
	gcc -o c4 -g cardtest4.c dominion.o rngs.o $(CFLAGS)
	./c4 >> unittestresults.out
	gcov dominion.c -b >> unittestresults.out
	
	cat dominion.c.gcov >> unittestresults.out
	

player: player.c interface.o
	gcc -o player player.c -g  dominion.o rngs.o interface.o $(CFLAGS)

all: playdom player testDrawCard testBuyCard badTestDrawCard

clean:
	rm -f *.o playdom.exe playdom player player.exe u1 u2 u3 u4 c1 c2 c3 c4 *.gcov *.gcda *.gcno *.so *.out testDrawCard testDrawCard.exe
