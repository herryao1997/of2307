#!/bin/bash
echo "Please guess the magic number"
read X
echo $X | grep "[^0-9]" > /dev/null 2>&1
if [ "$?" -eq "0" ]; then #因为 grep 命令在没有找到匹配时的退出状态码是1，找到匹配时的退出状态码是0。所以，当用户输入 $X 含有非数字字符时，grep 会找到匹配，退出状态码是0。这导致了 if [ "$?" -eq "0" ] 这个条件判断成立，执行 echo "Sorry wanted a number" 输出 "Sorry wanted a number"。
    echo "Sorry wanted a number"
else
    if [ "$X" -eq "6" ]; then
        echo "you got it"
    fi
fi
