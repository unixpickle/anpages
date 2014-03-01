all: build/anpages.o

build/anpages.o: build
	gcc -c src/anpages.c -o build/anpages.o

build:
	mkdir build

clean:
	rm -rf build/
