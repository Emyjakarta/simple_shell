#!/bin/bash

for file in _custom_functions*.c; do
    mv "$file" "${file%.c}.txt"
    done

