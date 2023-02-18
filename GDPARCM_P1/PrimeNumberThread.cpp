#include "PrimeNumberThread.h"
#include <iostream>
#include <string>

PrimeNumberThread::PrimeNumberThread(int _prime) : IETThread()
{
	prime = _prime;
}

void PrimeNumberThread::run()
{	
	IETThread::sleep(500);
	isRunning = true;

	int inc = ((1.0f / maxCount)) * prime;

	//std::cout << inc << std::endl;

	int start = count * inc;

	int end = start + inc;
	if (start < 2)
		start = 2;

	if (end < 0)
		end = prime;

	//std::cout << "Start: " << start << std::endl;
	//std::cout << "End: " << end << std::endl;

	bool isPrime = true;

	for (int i = start; i < end; i++)
	{
		if (prime % i == 0)
		{
			isPrime = false;
			break;
		}
	}
	std::string toPrint = "Thread #" + std::to_string(count) + ": " + std::to_string(count);
	if (isPrime)
		toPrint += " is PRIME\n";
	else
		toPrint += " is NOT PRIME\n";
	std::cout << toPrint;
	isRunning = false;
}
