# Rolling Dice

#### An Interesting Game with lots of Hidden Tasks

![Board Image](/images/3.png)
*Figure*: *Preview of the Game*.

## Introduction

*Rolling Dice* is a game just like snake and ladder, made in C++. This is a multi player game in which you have to reach the final score, also having some hidden task at some points that you will get to know when you will land on them like moving 10 points ahead or start from 1 and many more. There are some rules for the players also. This game can only be played using keyboard keys.

## Snapshots of the Game

Here is the glimpse of how the users can enjoy the game.

![Board Image](/images/1.png)
*Fig. 1*: *Start Screen*.

![Board Image](/images/2.png)
*Fig. 2*: *Rule Book*.

![Board Image](/images/4.png)
*Fig. 3*: *Player 2 leading Player 1*.

![Board Image](/images/5.png)
*Fig. 4*: *Again Player 2 is leading*.

![Board Image](/images/6.png)
*Fig. 5*: *Warning message when a player tries to cheat the opposition*.

![Board Image](/images/7.png)
*Fig. 6*: *Hidden task: Move 10 steps forward*.

![Board Image](/images/8.png)
*Fig. 7*: *Hidden task: Move 10 steps backward*.

![Board Image](/images/9.png)
*Fig. 8*: *Hidden task: Move to 50*.

![Board Image](/images/10.png)
*Fig. 9*: *Hidden task: Move 10 steps forward*.

![Board Image](/images/11.png)
*Fig. 10*: *Hidden task: Player gets a chance*.

![Board Image](/images/12.png)
*Fig. 11*: *Hidden task: Miss 1 chance*.

![Board Image](/images/13.png)
*Fig. 11*: *Player wins*.

## How to use this repository

This repository is a worked example of a game made using C++ in TurboC++.
Follow below steps to make a working model of the game.

Firstly, copy this repository to your local directory by executing:

```
git clone https://github.com/RupalJain97/Rolling-Dice.git
```

### TurboC++ setup

Here I am using TurboC++ to develop this game using *graphics.h* library. To download TurboC++, first unzip a folder in this repository named as **'Turbo.C.3.2.zip'** and run 'Turbo C++ 3.2' installer. This will instal TurboC++ in the default folder having its BGI path as **'C:\\TURBOC3\\BGI'**.

Now to get our STEPU.cpp run successfully with graphics, we need to copy this cpp file in the path: **'C:\TURBOC3\Projects'**. After copying, run TurboC++ application and select 'open source file' and select STEPU.cpp. This will launch TurboC++ in full screen mode with the file STEPU.cpp.

## Execution

Before execution, if you have installed TurboC++ in any path other than defaut path, then change line no 37 with below line by replacing path with your TurboC++ BGI folder path:

```
initgraph(&gdriver, &gmode, " [Path_To_your_TurboC++_BGI_folder] ");
```

Now to play the game, press 'Alt+F9' for compiling and then press 'Ctrl+F9' for execution. Enjoy the game!!
