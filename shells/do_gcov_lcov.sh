#!/bin/bash
rm -rf gcov
mkdir gcov

find ../ -name "*.gc*" |xargs -i cp {} gcov/
lcov -c -d ./gcov -o libmx.info

rm -r gcov_html
genhtml libmx.info -o gcov_html 

rm -f libmx.info

