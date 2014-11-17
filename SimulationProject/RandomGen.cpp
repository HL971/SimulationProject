#include "RandomGen.h"
#include <ctime>
#include <array>

namespace JDK{

	static int seed;

	/*******************************************************
	* roll()
	*
	* Randomly generates a number
	*******************************************************/
	unsigned int roll()
	{
		seed ^= seed << 5;
		seed ^= seed >> 9;
		seed ^= seed << 7;
		return seed;
	}

	/*******************************************************
	* JDK::randomNumberGeneration::randomNumberGeneration()
	*******************************************************/
	randomNumberGeneration::randomNumberGeneration()
	{
		seed = std::time(NULL);
	}
	
	/*******************************************************
	* JDK::randomNumberGeneration::rollD20()
	*
	* Simulates rolling a single 20 sided die
	*******************************************************/
	int randomNumberGeneration::rollD20()
	{
		return (roll() % 20) + 1;
	}

	/*******************************************************
	* JDK::randomNumberGeneration::rollDie(const std::array<int, 2>& input)
	*
	* Simulates rolling any number of dice that all have the
	* same number of sides.  Input is taken as {x, y} where
	* you have x number of y sided dice.
	*******************************************************/
	int randomNumberGeneration::rollDie(const std::array<int, 2>& input)
	{
		int total = 0;

		for (int x = 0; x < input[0]; x++)
		{
			total += ( (roll() % input[1]) + 1);
		}

		return total;
	}

}
