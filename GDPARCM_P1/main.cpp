#include "PrimeNumberThread.h"
#include <iostream>
#include <vector>

int main()
{
	//PrimeNumberThread::maxCount = 1;

	std::vector<PrimeNumberThread*> threads;
	int maxCount = 8;

	for (int i = 0; i < maxCount; i++)
	{
		PrimeNumberThread* thread = new PrimeNumberThread(58151);
		thread->count = i;
		thread->maxCount = maxCount;
		thread->start();
		threads.push_back(thread);
	}

	bool isDone = false;

	while (!isDone)
	{
		isDone = true;
		for (auto* thread : threads)
		{
			if (thread->isRunning)
			{
				isDone = false;
				break;
			}
		}
	}

	return 0;
}