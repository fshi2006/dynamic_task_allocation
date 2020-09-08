#!/bin/bash
color=white #black white red green blue
j=1
# case $color in
# red)   r=1 g=0 b=0 ;;
# green) r=0 g=1 b=0 ;; # 不需要在red上面加上引号,即"red"也可以识别
# blue)  r=0 g=0 b=1 ;; # 连续赋值语句不可以r=1,g=0,b=0,只能r=1 g=0 b=0,中间有空格或者分号
# black) r=1 g=1 b=1 ;;
# white) r=0 g=0 b=0 ;;
# esac

for ((i=40; i<50; i++)); do
  filename="Robot${i}"
  cp -r Robot0 ${filename}
  cd ${filename}
  sed -i "s/Robot0/"Robot${i}"/g" model.config
  sed -i "s/Robot0/"Robot${i}"/g" model.sdf
  sed -i "s/nubot_frame1.dae/"nubot_frame${j}_$color.dae"/g" model.sdf
  ((j++))
  cd ..
done

