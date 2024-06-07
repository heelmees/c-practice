#pragma once
#include <Object.hpp>


namespace mt
{
	class Asteroid : public Object
	{
	public:
		Asteroid() = default;
		virtual ~Asteroid() {}

		void Attack() override
		{
			std::cout << "Asteroid Attack" << std::endl;
		}

		void SpecialAbility() override
		{
			std::cout << "Asteroid Special Ability" << std::endl;
		}

		void Test() {}
	};
}