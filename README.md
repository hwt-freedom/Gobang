## C++五子棋控制台游戏设计
<p align="right">huangwentao@iie.ac.cn &nbsp &nbsp 2018.12.7</p>

#### 开发环境
* **Microsoft Visual Studio 2017**
#### 源码地址
[Gobang](https://github.com/hwt-freedom/Gobang)

### 基本类型介绍
##### 五子棋类 $Gobang$
* 组织游戏：准备游戏阶段包括选择游戏模式，选择人机模式先后顺序等；游戏开始阶段包括输入棋子，判断输赢等功能。
##### 棋子类 $Chess$
* 记录棋子的当前颜色和位置信息。
##### 棋盘类 $ChessBoard$
* 记录棋盘当前的标志信息，并且具有打印棋盘、判断棋盘是否为空（满）、判断当前棋子位置是否合法、添加与更新棋子状态信息等功能。
##### 裁判类 $Referee$
* 调用规则对象的方法判断当前棋子位置的禁手和输赢，显示禁手和输赢信息。
##### 规则类 $Rule$
* 基于棋型判断实现禁手，输赢判断实现。
##### 人类玩家类 $HumanPlayer$
* 完成人类玩家的棋子输入过程：控制玩家输入棋子坐标合法，并调用棋盘对象的方法判断落子坐标是否合法。
##### 计算机玩家类 $ComputerPlayer$
* 完成计算机玩家的棋子输入过程：调用人工智能对象的方法获得即将输入的棋子信息。
##### 人工智能类 $AI$
* 基于棋型判断实现打分功能。

<br/>

###关键部分设计思想
#### 棋型判断实现思想
1. 首先以当前落子位置为中心，获得横、竖、左上到右下、右上到左下共四个方向的连续9个棋子，若出界则用对手棋子填充出界的位置；  
2. 再统计以落子位置为中心向两端统计，并根据同类型棋子形成多连、五连、四连、三连、二连、一连等情况来判断具体的棋子类型；
3. 统计各个棋子类型的数目，作为后续判断禁手和人工智能对象打分的依据。
##### 具体棋型
```c++
static const int ChangLian = 1;		//长连为1
static const int Lian5 = 2;			//连5为2
static const int Huo4 = 3;			//活4为3
static const int DoubleChong4 = 4;  //冲4 同一方向上的双冲4为 4
static const int HighChong4 = 5;	//冲4 不间断为5
static const int LowChong4 = 6;		//冲4 间断为6
static const int Huo3 = 7;			//活3为7
static const int Tiao3 = 8;			//跳3为8
static const int Mian3 = 9;			//眠3为9
static const int Huo2 = 10;			//活2为10
static const int Tiao2 = 11;		//跳2为11
static const int Mian2 = 12;		//眠2为12
                                               //0代表无威胁的棋型
```
#### 打分实现思想
1. 基于棋型判断获得棋盘上所有未落子位置落子后的棋型；
2. 根据棋型获得所有位置己方和对手的分数，并将分数分别存放到两个打分矩阵中；
3. 根据分数的实际情况决定进攻还是防守，若有多个位置分数相同，则在所有分数相同的位置中选择最有利的位置。
##### 具体打分细则
```c++
//打分规则
    //若为棋子颜色为黑色，首先判断是否为禁手
      //连5       10000分     Lian5Num >= 1

      //活4       5000分      Huo4Num >= 1
     //双冲4_1   5000分      DoubleChong4Num >= 1
     //双冲4_2   5000分      Chong4Num >= 2
     //冲4活3    5000分      Chong4Num + Huo3Num + Tiao3Num>= 2

     //双活3     4500分       Huo3Num >= 2
    //双活3     4000分       Huo3Num + Tiao3Num >= 2
    //双活3     3500分       Tiao3Num >= 2         //优先考虑普通活3

    //活3眠3    2500分       Huo3Num + Mian3 >= 2
    //活3眠3    2000分       Tiao3Num + Huo3Num + Mian3 >= 2
    //活3眠3    1500分       Tiao3Num + Mian3 >= 2 //优先考虑普通活3

    //冲4       1000分       Chong4Num >= 1

    //活3       800分        Huo3Num >= 1

    //跳3       700分        Tiao3Num >= 1

    //双活2     550分        Huo2Num >= 2
   //双活2     500分        Huo2Num + Tiao2Num >= 2
   //双活2     450分        Tiao2Num >= 2        //优先考虑普通活2

     //活2眠2    250分        Huo2Num + Mian2Num >= 2
    //活2眠2    200分        Huo2Num + Tiao2Num + Mian2Num >= 2
   //活2眠2    150分        Tiao2Num + Mian2Num >= 2

    //眠3       100分        Mian3 >= 1
    //活2       80分         Huo2Num >= 1
   //跳2       70分         Tiao2Num >= 1
   //眠2       50分         Mian2Num >= 1
  //其他      10分
```
