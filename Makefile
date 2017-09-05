CC=gcc
CFLAGS=-Wall

random: lcrandom.o histograma-1.o histograma-2.o periodo-1.o periodo-2.o
	$(CC) -o histograma-1 histograma-1.o lcrandom.o $(CFLAGS)
	$(CC) -o histograma-2 histograma-2.o lcrandom.o $(CFLAGS)
	$(CC) -o periodo-1 periodo-1.o lcrandom.o $(CFLAGS)
	$(CC) -o periodo-2 periodo-2.o lcrandom.o $(CFLAGS)

histograma-1: histograma-1.o lcrandom.o
	$(CC) -o histograma-1 histograma-1.o lcrandom.o $(CFLAGS)

histograma-2: histograma-2.o lcrandom.o
	$(CC) -o histograma-2 histograma-2.o lcrandom.o $(CFLAGS)

periodo-1: periodo-1.o lcrandom.o
	$(CC) -o periodo-1 periodo-1.o lcrandom.o $(CFLAGS)	

periodo-2: periodo-2.o lcrandom.o
	$(CC) -o periodo-2 periodo-2.o lcrandom.o $(CFLAGS)	

histograma-1.o: histograma-1.c lcrandom.c
histograma-2.o:	histograma-2.c lcrandom.c
periodo-1.o: periodo-1.c lcrandom.c
periodo-2.o: periodo-2.c lcrandom.c
lcrandom.o: lcrandom.c

.PHONY: clean compress 
clean:
	rm *.o
	rm histograma-1 histograma-2 periodo-1 periodo-2

compress:
	tar -cvzf projeto_01.tar.gz *.c
