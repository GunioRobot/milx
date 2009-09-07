#ifndef MILX_MODULE_MANIPULATOR
#define MILX_MODULE_MANIPULATOR

#include "base.hpp"

namespace Milx
{
	namespace Manipulators
	{
		class ModuleManipulator : public Base
		{
		public:
			void create(std::string, int, char**);
			void destroy(std::string, int, char**);
			void help(std::string, int, char**);
		};
	}
}

#endif
