all:
	rm -rf lingeling
	cp -r archives/lingeling lingeling
	cd lingeling && ./configure.sh -fPIC && make
	rm -rf boolector
	cp -r archives/boolector boolector
	cd boolector && ./configure && make

boolector:
	rm -rf boolector
	cp -r archives/boolector boolector
	cd boolector && ./configure && make

cleanBoolector:
	rm -rf boolector

clean:
	rm -rf lingeling boolector

.PHONY: all clean distclean
