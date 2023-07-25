#include "TimeManager.h"


void TimeManager::CreateAndRunThread(std::function<void()> func)
{
	Threads.push_back(std::thread(func));
}
