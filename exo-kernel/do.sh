cd lib/libos
make clean
make
cd ../..

cd app
make clean
make 
cd ..


cd kernel
make clean
make 
make iso
make test
