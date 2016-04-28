#pragma once

#include <string> // One of the small pleasures in life, not dealing with c-strings.

namespace mEngine {
	namespace toolkit {
		namespace debug {
			namespace logger { // Long ago the coders of egypt build great scope pyramids
				enum color { // American spelling because freedom
					WHITE = 0
				};

				bool CreateConsole(); // TODO: Create own console window and only display default when own fails to create
				bool Log(color Color, std::string szOut);
			}
		}
	}
}