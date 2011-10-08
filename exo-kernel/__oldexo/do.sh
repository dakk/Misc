cd kernel
make wrap

cd ../lib/libos
python2 create_wrapper.py
make clean
make

cd ../../kernel
make clean
make

cd ../lib/libos/
python2 create_wrapper.py
make wrapper

cd ../../app/
make clean
make

cd ../kernel/
make iso
make test
