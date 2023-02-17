#include "PrimeNumberThread.h"
#include <iostream>
#include <string>

PrimeNumberThread::PrimeNumberThread(int _prime) : IETThread()
{
	prime = _prime;
}

void PrimeNumberThread::run()
{	
	IETThread::sleep(500 * count);
	isRunning = true;

	int inc = ((1.0f / maxCount)) * prime;

	//std::cout << inc << std::endl;

	int start = count * inc;

	int end = start + inc;
	if (start < 2)
		start = 2;

	if (end < 0)
		end = prime;

	std::cout << "Start: " << start << '\n';
	std::cout << "End: " << end << '\n';

	bool isPrime = true;

	for (int i = start; i < end; i++)
	{
		if (prime % i == 0)
		{
			isPrime = false;
			break;
		}
	}

	std::cout << prime;
	if (isPrime)
		std::cout << " is PRIME\n";
	else
		std::cout << " is NOT PRIME\n";
	
	isRunning = false;
}
