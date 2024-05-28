#!/bin/bash

for file in ./maps/invalid_maps/*; do
    valgrind --leak-check=full ./cub3d "$file" 2>&1 | sed -e 's/^==[0-9]*== //' -e '/^Memcheck, a memory error detector/d' -e '/^Copyright (C) 2002-2017, and GNU GPL'\''d, by Julian Seward et al./d' -e '/^Using Valgrind-3.18.1 and LibVEX; rerun with -h for copyright info/d' -e '/^Command: ./d' -e '/For lists of detected and suppressed errors, rerun with: -s/d'
done