_MAKE= && make && cd ..
_CLEAN= && make clean && cd ..

all:
	cd init $(_MAKE)
	cd bootsplash $(_MAKE)
	cd test $(_MAKE)
	cd ui $(_MAKE)
	#cd ewm && make && cd ..

clean:
	cd bootsplash $(_CLEAN)
	cd init $(_CLEAN)
	cd test $(_CLEAN)
	cd ui $(_MAKE)
	#cd ewm && make clean && cd ..

