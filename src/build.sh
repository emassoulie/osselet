#!/bin/sh
make clean
make
if [ $? -eq 0 ]; then
    echo Build succeeded.
    qemu-system-x86_64 -kernel myos.bin
else
    echo Build failed.
fi

