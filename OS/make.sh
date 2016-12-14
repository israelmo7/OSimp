#!/bin/bash
cd src
make
cp kernel.bin ../bin/kernel/kernel.bin
make clean
cd ..
genisoimage -R -input-charset utf8 -b boot/grub/stage2_eltorito -boot-info-table -no-emul-boot -boot-load-size 4 -o os.iso bin
qemu-system-x86_64 -cdrom os.iso
echo Done!
