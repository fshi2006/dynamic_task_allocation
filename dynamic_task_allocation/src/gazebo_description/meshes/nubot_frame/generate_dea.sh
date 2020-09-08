#!/bin/bash
color=white #black white red green blue
num=11 # how many files to generate

case $color in
red)   r=1 g=0 b=0 ;;
green) r=0 g=1 b=0 ;; # 不需要在red上面加上引号,即"red"也可以识别
blue)  r=0 g=0 b=1 ;; # 连续赋值语句不可以r=1,g=0,b=0,只能r=1 g=0 b=0,中间有空格或者分号
black) r=1 g=1 b=1 ;;
white) r=1 g=1 b=1 ;;
esac


for ((i=1; i<$num; i++)); do
  filename="nubot_frame${i}_${color}.dae"
  cp "nubot_frame${i}.dae" ${filename}
  sed -i "s/0.1372549 0.1372549 0.1372549/${r} ${g} ${b}/g" ${filename}
done

