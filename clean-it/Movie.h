#pragma once

#include "expected.h"

import <string>;
import <chrono>;

namespace ci
{
	using namespace std::chrono_literals;

	class Movie
	{
	public:
		constexpr inline static std::chrono::seconds MaxDuration = 120s;

		std::string Name;
		std::chrono::seconds Duration;

		static expected<Movie> create(const std::string& name, int seconds) noexcept
		{

			if (const auto duration = std::chrono::seconds(seconds);
				duration > MaxDuration || duration < 1s)
			{
				return unexpected ("invalid duration");
			}
			return Movie(name, std::chrono::seconds(seconds));
		}

	private:

		// The default ctor is deleted.
		// All other special functions are defaulted and meet the invariant if their argument does,
		// so they do not need to be redefined.
		// Moreover, the cpp core guideline https://github.com/isocpp/CppCoreGuidelines/blob/master/CppCoreGuidelines.md#c21-if-you-define-or-delete-any-copy-move-or-destructor-function-define-or-delete-them-all
		// does not apply here.
		Movie(std::string name, std::chrono::seconds seconds) :
			Name(std::move(name)),
			Duration(seconds)
		{
		}
	};
}