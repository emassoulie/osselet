#!/bin/sh
make clean
make
if [ $? -eq 0 ]; then
    echo Build succeeded.
else
    echo Build failed.
fi
