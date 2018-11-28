#include"Timer.h"


Timer::Timer()
{
	is_pause = false; //初始化计时器状态 
	is_stop = true;
}

//包含开始、暂停、停止、显示等功能