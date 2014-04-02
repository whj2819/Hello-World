#
# taglist
# 

<space>    显示光标下tag的原型定义
u          更新taglist窗口中的tag.
x          taglist窗口放大缩小.
+          打开一个折叠.
-          将tag折叠起来.
*          打开所有折叠.
=          将所有tag折叠起来.


#
# vim
#
# http://www.thegeekstuff.com

# 添加行号
:%s/^/\=line(".") . ". "/g

'<,'>        我们所选中的区域 (:help '<，:help '> )
s            在选中的区域中进行替换 (:help :s )
\zs          指明匹配由此开始 (:help /\zs )
\d*          查找任意位数的数字 (:help /\d )
\ze          指明匹配到此为止 (:help /\ze )
\=           指明后面是一个表达式 (:help :s\= )
line(".")    当前光标所在行的行号 (:help line() )

# 用$Home 变量替换 ~
:%s!\~/!\=expand($HOME)!g

before:
Original Text: Current file path is ~/test/

after:
Original Text: Current file path is  /home/ramesh/test/
