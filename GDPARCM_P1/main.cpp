#include "PrimeNumberThread.h"
#include <iostream>
#include <vector>
#include <chrono>

int main()
{
	std::vector<PrimeNumberThread*> threads; // Thread List
	int maxCount = 4; // Number of threads

	// 2147483647
	std::cout << "Number of thread/s: " << maxCount << std::endl;
	// Get thread start time
	std::chrono::steady_clock::time_point timeStart = std::chrono::steady_clock::now();

	for (int i = 0; i < maxCount; i++)
	{
		PrimeNumberThread* thread = new PrimeNumberThread(2147483647);
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
	// Get end time
	std::chrono::steady_clock::time_point timeEnd = std::chrono::steady_clock::now();
	std::cout << "Time taken: " << std::chrono::duration_cast<std::chrono::milliseconds>(timeEnd - timeStart).count() << "ms" << std::endl;

	return 0;
}