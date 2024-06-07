#pragma once
#include <Object.hpp>

namespace mt
{
	class Comet : public Object
	{
	public:
		Comet() = default;
		virtual ~Comet() {}

		void Attack() override
		{
			std::cout << "Comet Attack" << std::endl;
		}

		void SpecialAbility() override
		{
			std::cout << "Comet Special Ability" << std::endl;
		}

		void Test() {}
	};
}