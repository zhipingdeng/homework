---
layout: default
title: 制作进阶html5游戏
---


# 游戏策划
## 游戏setting
某国的3只商船被一只海盗舰队追赶，不幸进入岛礁地带。某国的一艘救援船正好在附近巡逻。接收到商船的求救信号后，救援船立刻前往救援。救援船须在海盗船接触到商船前在不触碰岛礁的情况下接触三只商船，你只有5发导弹。。。
## 游戏设定
player：救援船

enemy：海盗船

胜利条件：接触3只商船

![fdgh](http://m.qpic.cn/psb?/V12ukENm2Puji7/aBJWHpXD.H3jh7fC0Pnv14AUCO96dhjSWq2rkFi1tiw!/b/dFIBAAAAAAAA&bo=UAYrAwAAAAACl80!&rf=viewer_4)

失败条件：

1.触碰岛礁 

![fdgh](http://m.qpic.cn/psb?/V12ukENm2Puji7/ZFA2CR0YpxZ19U4Pgp7BI7wpeC*D0iyVU1bexnmIEc0!/b/dC8BAAAAAAAA&bo=UAYrAwAAAAACl80!&rf=viewer_4)

2.任意一只商船被劫 

![fdgh](http://m.qpic.cn/psb?/V12ukENm2Puji7/Ao3wYvWgD3w7GOzyKayUPsI6DgjegDkNMRh9pnTnWiQ!/b/dGcBAAAAAAAA&bo=UAYrAwAAAAACh90!&rf=viewer_4)

3.使用导弹误伤商船

![fdgh](http://m.qpic.cn/psb?/V12ukENm2Puji7/J1Hz8Uex8UlYwVUYHdGi6VTHrK5cd13uKH0XKffPVoQ!/b/dEcBAAAAAAAA&bo=UAYrAwAAAAACh90!&rf=viewer_4)

Bonus条件：用导弹消灭海盗船

equipment：5发导弹（可破坏任意事物）

## 游戏操作
方向键：

控制救援船移动

鼠标：

1.移动时控制救援船射击方向

 2.左键射击


# 游戏设计CRC卡片
## 卡片1
Object Name：救援船

Attributes:
![fdgh](http://m.qpic.cn/psb?/V12ukENm2Puji7/17ZzyCxoPGPIGVHJw8AJ15OHFzzo7oW4VVI37VAoPcU!/b/dFQBAAAAAAAA&bo=ggBCAAAAAAADB.I!&rf=viewer_4)

Collaborator：Sprite

Events&Actions：

1.鼠标左键时，发射一颗导弹

2.与礁石碰撞后消失，游戏结束

3.与商船碰撞后商船消失，Goal加1

## 卡片2
Object Name：商船

Attributes:
![fdgh](http://m.qpic.cn/psb?/V12ukENm2Puji7/Z3I1UV*4cGfyQflQa*TyA*2knkZbp73slkPS9dOFLU4!/b/dFIBAAAAAAAA&bo=rwCjAAAAAAADFz4!&rf=viewer_4)

Collaborator：Sprite

Events&Actions：

1.与救援船碰撞后消失并生成金币

2.与海盗船碰撞后消失，游戏结束

3.与导弹碰撞后消失，导弹也消失，生成爆炸，游戏结束
## 卡片3
Object Name：海盗船

Attributes:
![fdgh](http://m.qpic.cn/psb?/V12ukENm2Puji7/0mvBUH3BHDKo8rdF3VwBhtYBMt6vvxyS2K25vp6KQdQ!/b/dFYAAAAAAAAA&bo=tACnAAAAAAADFyE!&rf=viewer_4)

Collaborator：Sprite

Events&Actions：

1.与商船碰撞后商船消失，游戏结束

2.与导弹碰撞后消失，导弹也消失，生成爆炸，Bonus加1

## 卡片4
Object Name：礁石

Attributes:
![fdgh](http://m.qpic.cn/psb?/V12ukENm2Puji7/w6EaB.iW045y5kRtBdnIZGpHMvu5P*hdNYtJi.BMyQo!/b/dDQBAAAAAAAA&bo=egB.AAAAAAADFzY!&rf=viewer_4)

Collaborator：Sprite

Events&Actions：

1.与救援船碰撞后救援船消失，游戏结束

2.与导弹碰撞后消失，导弹也消失
## 卡片5
Object Name：导弹

Attributes:
![fdgh](http://m.qpic.cn/psb?/V12ukENm2Puji7/yv*W*oMrDmD7eXkJMmdtiEGkpdEKCaGLRZxJVjmYjJk!/b/dDEBAAAAAAAA&bo=GQAQAAAAAAADFzs!&rf=viewer_4)

Collaborator：Sprite

Events&Actions：

1.与礁石碰撞后消失，礁石也消失，生成爆炸

2.与商船碰撞后消失，商船也消失，生成爆炸，游戏结束

3.与海盗船碰撞后消失，海盗船也消失，生成爆炸，Bonus加1
## 卡片6
Object Name：爆炸

Attributes:
![fdgh](http://m.qpic.cn/psb?/V12ukENm2Puji7/z6764q7KoklD.eZEM2q9JEU07Df.Krr6URelV8g86cc!/b/dDYBAAAAAAAA&bo=dgBlAAAAAAADFyE!&rf=viewer_4)

Collaborator：Sprite

Events&Actions：

1.在导弹与礁石碰撞时生成，逐渐消失

2.在导弹与商船碰撞时生成，逐渐消失

3.在导弹与海盗船碰撞时生成，逐渐消失
## 卡片7
Object Name：金币

Attributes:
![fdgh](http://m.qpic.cn/psb?/V12ukENm2Puji7/AIrvFIPZazYzcg62tAOX1SXq*YKRTOyT1dfe1G6CmrE!/b/dFMBAAAAAAAA&bo=ZABaAAAAAAADFww!&rf=viewer_4)

Collaborator：Sprite

Events&Actions：
1.在救援船与商船碰撞时生成，逐渐消失


