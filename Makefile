all: test

build/anpages.o:
	gcc -c src/anpages.c -o build/anpages.o

build:
	mkdir build

clean:
	rm -rf build/
