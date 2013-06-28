#!/bin/bash
if [ $# -lt 2 ]
then
echo "require arguments"
else
INFO_FILE=$1
INFO_FILE_BK=${INFO_FILE}_bk
STRIP_WORD=$2
MATCH_RECORD=0

allines=(`cat ${INFO_FILE}`)
for line in ${allines[*]}
do
if [ $MATCH_RECORD == 0 ]
then
	if [[ "${line}" =~ "${STRIP_WORD}" ]]
	then
		MATCH_RECORD=1
	else
		echo ${line} >> ${INFO_FILE_BK}
	fi
else
	if [ "${line}" == "end_of_record" ]
	then
		MATCH_RECORD=0
	fi
fi
done

mv ${INFO_FILE_BK} ${INFO_FILE}

fi
