nasm -felf32 boot.s -o boot.o

gcc -m32 main.m -c -o main.o -Wno-write-strings -nostdlib -nostartfiles -ffreestanding \
				-fno-stack-protector -nostdlib -nostdinc -fno-builtin -nodefaultlibs -fno-exceptions
gcc -m32 video.m -c -o video.o -Wno-write-strings -nostdlib -nostartfiles -ffreestanding \
				-fno-stack-protector -nostdlib -nostdinc -fno-builtin -nodefaultlibs -fno-exceptions
ld -melf_i386 boot.o main.o video.o -o kernel -Tlink.ld

mkdir isofiles
mkdir isofiles/boot/
mkdir isofiles/boot/grub/
cp stage2_eltorito isofiles/boot/grub
cp kernel isofiles/kernel
cp menu.lst isofiles/boot/grub
mkisofs -R -b boot/grub/stage2_eltorito -no-emul-boot -boot-load-size 4 -boot-info-table -o image.iso isofiles
rm -r isofiles

sleep 1
qemu-system-x86_64 -cdrom image.iso -m 700

