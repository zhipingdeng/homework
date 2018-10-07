---
layout: default
title: 制作html5游戏
---

# 制作html5游戏

## 成品GIF

![fdgh](\新手游戏.gif)

## 开始

设置,启动construct2。单击文件按钮,并选择“NEW”

![fdgh](https://www.scirra.com/images/articles/filenew.png)

弹出对话框

![fdgh](https://www.scirra.com/images/articles/newprojdialog65.png)

选择“New empty project”

## 插入对象

### 背景


![fdgh](https://www.scirra.com/images/articles/bg.png)

选以上图片作为背景,并保存在电脑上

点击layout，设置layout的size为1280，1024

然后，右键选择“Insert New Object”，出现

如图对话框，选择“Tiled Background”

![fdgh](https://www.scirra.com/images/articles/insertobject.png)

然后会出现一个十字表示物体的位置。点击附

近的layout，弹出“Edit Texture”对话框,选择“Lo

ad an image from a file”并导入之前保存的背景

图像

![fdgh](https://www.scirra.com/images/articles/loadtexturefromfile.png)

点击右上角的X，关闭“Edit Texture”。

调整图片覆盖整个layout

### 添加layer

![fdgh](https://www.scirra.com/images/articles/layerstab.png)

如图，点击“Layers”

![fdgh](https://www.scirra.com/images/articles/layersbar.png)

将原图层重命名为Background并锁定，再单击

绿色“添加”图标添加一个新图层“Main”，并选

中该图层

### 添加输入对象

右键选择“Insert New Object”,选择“Mouse”对象

同样插入“Keyboard”对象

注意:这些对象不需要放置在layout。 他们是隐藏的,项目范围的自动工作。 现在所有的layout在我们的项目可以接受鼠标和键盘输入。

### 游戏对象

以下是游戏对象的图片，将它们保存在电脑上

玩家：

![fdgh](https://www.scirra.com/images/articles/player.png)

炮弹：

![fdgh](https://timgsa.baidu.com/timg?image&quality=80&size=b9999_10000&sec=1538828517967&di=7dcb90de37fdca017e50f019d61bfee9&imgtype=0&src=http%3A%2F%2Fa0.att.hudong.com%2F84%2F88%2F01000000000000119088821593984_s.jpg)

敌人：

![fdgh](https://www.scirra.com/images/articles/monster.png)

金币：

![fdgh](https://timgsa.baidu.com/timg?image&quality=80&size=b9999_10000&sec=1538828456428&di=2b0cff5f9609bd96badee6abd8350a74&imgtype=0&src=http%3A%2F%2Fimg.sucaifengbao.com%2Fvector%2Fepssctp%2F313_032_al.jpg)

双击插入一个“sprite”对象，当鼠标变成一个十字时，

在layout上单击，弹出“Edit Texture”对话框,将四张

图片导入

将子弹和爆炸移动到layout的外边,使它们在游戏开始时

不会被看到

将这四个对象重命名为“玩家”“子弹”“僵尸”“金币”

## 添加“behaviors”

选择一个“sprite”对象

![fdgh](https://www.scirra.com/images/articles/openbehaviors.png)

如图，添加“behavior”

![fdgh](https://www.scirra.com/images/articles/add8dir.png)

如图，在“玩家”对象上添加“8 Direction”

![fdgh](https://www.scirra.com/images/articles/playerbehaviors_2.png)

如图，在“玩家”对象上添加以上3个behavior

然后，在子弹和怪物上添加“Bullet Movement”，在爆炸上添加“Fade”

选中怪物，将speed下调；选中子弹，将speed上调

### 创建更多的怪物

按住ctrl键，拖动怪物，产生新的怪物,共产生7~8个怪物

## event事件

1。 双击插入一个新的事件,或单击一个添加操作链接添加一个操作。

2。 双击对象条件/行动。


 3。双击你想要的条件/操作。

 4。输入任何需要的参数



![fdgh](https://www.scirra.com/images/articles/eventsheettab.png)

如图，单击Event sheet 1选项卡切换到顶部Event sheet editor

![fdgh](https://www.scirra.com/images/articles/newevent_2.png)

双击，插入system事件

![fdgh](https://www.scirra.com/images/articles/everytickcnd.png)

点击every tick条件

![fdgh](https://www.scirra.com/images/articles/addactiondlg.png)

双击给玩家添加action

![fdgh](https://www.scirra.com/images/articles/playersetanglepos.png)

选择set angle toward position

![fdgh](https://www.scirra.com/images/articles/setangleposparams.png)

设定参数Mouse.X,Mouse.Y

![fdgh](https://www.scirra.com/images/articles/alwayslookatmouse.png)

完成后如图

## 添加游戏功能

### 炮弹射击

![fdgh](https://www.scirra.com/images/articles/spawnbullet1.png)

如图，添加事件使玩家能射出炮弹

![fdgh](https://www.scirra.com/images/articles/spawnbullet1.png)

### 消灭怪物

Condition: 炮弹 -> On collision with another object -> pick 怪物.

Action: 怪物 -> Destroy

Action: 炮弹 -> Spawn another object -> 金币, layer 1

Action: 炮弹 -> Destroy

### 使怪物更加聪明

在system的every tick中再加入action

Action: 怪物 -> set angle toward (玩家.X,玩家.Y)

这会使怪物一直瞄准玩家前进

## 实例变量（instance variable）

### 增加怪物生命

选中怪物

![fdgh](https://www.scirra.com/images/articles/instvars.png)

如图，点击add new

![fdgh](https://www.scirra.com/images/articles/healthinstvar.png)

如图，给怪物增加health变量

再将

Condition: 炮弹 -> On collision with another object -> pick 怪物.

Action: 怪物 -> Destroy

中的Destroy改变为subtract 1 from health

然后添加下列事件

Condition: 怪物 -> Compare instance variable -> Health, Less or equal, 0

Action: 怪物 -> Spawn another object -> 金币, layer 1

Action: 怪物 -> Destroy

## 计分&Game over

### 计分

右键单击event sheet的底部空白处，并选择添加全局变量（global variable）

![fdgh](https://www.scirra.com/images/articles/addglobal.png)

如图

![fdgh](https://www.scirra.com/images/articles/addglobalscore.png)

输入初始值0

![fdgh](https://www.scirra.com/images/articles/scoreeevent.png)

如图，添加事件

### Game over

双击一个空间插入另一个对象。 这一次选择文本对象。

![fdgh](https://www.scirra.com/images/articles/textinlayout.png)

如图，将其放置在顶层

在system的every tick中添加

Condition: 玩家 -> is on layer 1 

Action：Textbox ->set text to "score:"&score

然后添加事件：

Condition: 玩家 -> On collision with another object -> pick 怪物.

Action: 玩家 -> Destroy

Action: 炮弹 -> Spawn another object -> 金币, layer 1

Action: 炮弹 -> Destroy

Action: 炮弹 -> Destroy

Action：Textbox ->set text to "Game over"

## 怪物生成

添加事件：

Condition: System -> Every X seconds -> 3

Action: System -> Create object -> 怪物, layer 1, 1400 (for X), random(1024) (for Y)