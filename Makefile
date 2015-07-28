all: testGenerator

testGenerator: testGenerator.o item.o test.o accounting.o
	g++ testGenerator.o item.o test.o accounting.o -o testGenerator

testGenerator.o: src/testGenerator.cc 
	g++ -c src/testGenerator.cc -o testGenerator.o

item.o: src/item.cc src/item.h
	g++ -c src/item.cc -o item.o

test.o: src/test.cc src/test.h
	g++ -c src/test.cc -o test.o

accounting.o: src/accounting.cc src/accounting.h
	g++ -c src/accounting.cc -o accounting.o

clean:
	rm *.o


