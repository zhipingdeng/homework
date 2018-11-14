---
layout: default
title: lab08
---
# 编程方法：自顶向下，逐步求精（Top-down design）

## 简介
A top-down approach (also known as stepwise design and in some cases used as a synonym of decomposition) is essentially the breaking down of a system to gain insight into its compositional sub-systems in a reverse engineering fashion. In a top-down approach an overview of the system is formulated, specifying, but not detailing, any first-level subsystems. Each subsystem is then refined in yet greater detail, sometimes in many additional subsystem levels, until the entire specification is reduced to base elements. A top-down model is often specified with the assistance of "black boxes", which makes it easier to manipulate. However, black boxes may fail to clarify elementary mechanisms or be detailed enough to realistically validate the model. Top down approach starts with the big picture. It breaks down from there into smaller segments.


## Top-down design的应用

Top-down design是一种应用很广泛的思想。除了编程外，它还出现在生产车间，产品包装等地方。

以下为产品包装Top-down design图：

![fdgh](https://ss0.bdstatic.com/70cFuHSh_Q1YnxGkpoWK1HF6hhy/it/u=2097789968,2383457928&fm=26&gp=0.jpg)

洗衣机也有Top-down design的思想

# 洗衣机案例
## 提供的洗衣程序
water_in_switch(open_close) // open 打开上水开关，close关闭

water_out_switch(open_close) // open 打开排水开关，close关闭

get_water_volume() //返回洗衣机内部水的高度

motor_run(direction) // 电机转动。left左转，right右转，stop停

time_counter() // 返回当前时间计数，以秒为单位

halt(returncode) //停机，success 成功 failure 失败
## 正常洗衣程序的大步骤
```
READ 洗衣模式

READ 对应水位

注水

浸洗

洗涤

电机转动

排水

电机转动

停机
```
## 洗衣机伪代码
```
READ Mode

WHILE 水位 < Mode对应水位

　　　　water_in_switch(open)

ENDWHILE

water_in_switch(close)

SET time_counter() to 0(ms)

WHILE time_counter() < 180000(ms)(30min)

　　　　motor_run(stop)

ENDWHILE

SET time_counter() to 0

WHILE time_counter() <36000(ms)(6min)

　　　　IF time_counter() < 18000(ms)(3min) THEN

　　　　　　　　motor_run(left)

　　　　ELSE

　　　　　　　　motor_run(right)

　　　　ENDIF

ENDEHILE

motor_run(stop)

WHILE 水位 > 0

　　　　water_out_switch(open)

ENDWHILE

water_out_switch(close)

SET time_counter() to 0

WHILE time_counter() < 24000(ms)(4min)

　　　　motor_run(left)

ENDWHILE

HALT(success)
```
# 总结
在洗衣案例中，将整个洗衣程序划分为选择模式、注水、浸水、电机转动、等板块，体现了自顶向下，逐步求精的思想