#pragma once
#include <vector>
#include <thread>
#include <functional>


class TimeManager
{
public:
	std::vector<std::thread> Threads;
	std::vector<std::function<void()>> Functions;

public:
	void CreateAndRunThread(std::function<void()> func);
};

