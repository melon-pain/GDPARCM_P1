#pragma once
#include "IETThread.h"

class PrimeNumberThread : public IETThread
{
public:
	PrimeNumberThread(int _prime);

	int count = 0;
	bool isRunning = true;
	int maxCount = 0;
protected:
	int prime;
	void run() override;
};

