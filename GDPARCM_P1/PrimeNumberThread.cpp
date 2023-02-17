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

	int start = count * inc;
	if (start < 2)
		start = 2;

	int end = start + inc;

	if (end < 0)
		end = prime;

	std::cout << "Start: " << start << '\n';
	std::cout << "End: " << end << '\n';

	bool isPrime = true;

	for (int i = start; i <= end; i++)
	{
		if (prime % i == 0)
		{
			isPrime = false;
			break;
		}
	}

	if (isPrime)
		std::cout << "prime\n";
	else
		std::cout << "not prime\n";
	
	isRunning = false;
}
