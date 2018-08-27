
for ((i=1; i<=100; i ++))
do
	echo $i
    rm temp.txt
    ./test_case/bin/Debug/test_case.exe > temp.txt
    me=$(cat temp.txt | ./a1004/bin/Debug/a1004.exe)
    echo $me
    other=$(cat temp.txt | ./other_answer/bin/Debug/other_answer.exe)
    echo $other
    if [ "$me"x != "$other"x ]
    then
        echo "!!!!!!!!!!!!!!!!!!! NOT EQUAL !!!!!!!!!!!!!!!!!!!!!!"
        cp temp.txt error_case.txt
    fi
done
