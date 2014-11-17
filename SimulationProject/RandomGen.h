#include <array>

#ifndef JDK_RANDOM_GEN
#define JDK_RANDOM_GEN

namespace JDK
{

	class randomNumberGeneration
	{
	public:
		randomNumberGeneration();
		int rollD20();
		int rollDie(const std::array<int, 2>& input);

	};


}
#endif
