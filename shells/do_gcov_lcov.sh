#!/bin/bash
rm -rf gcov gcov_html
mkdir gcov gcov_html

find ../ -name "*.gc*" |xargs -i cp {} gcov/

gcno_files=(`ls gcov/*.gcno |sed 's/gcno/gcda/'`)
for gcno in ${gcno_files[*]}
do
if [ ! -e ${gcno} ]
then
touch ${gcno}
fi
done

lcov -c -d ./gcov -o libmx.info

./strip_stl_cov.sh libmx.info "c++"

rm -r gcov_html
genhtml --highlight --num-spaces 4 libmx.info -o gcov_html 

rm -f libmx.info

