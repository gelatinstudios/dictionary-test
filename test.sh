#!/bin/bash
rm *.txt
for n in {1..$1}; do ./dict >> dict.txt; ./mike >> mike.txt; done
./average
