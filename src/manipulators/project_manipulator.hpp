#ifndef MILX_PROJECT_MANIPULATOR
#define MILX_PROJECT_MANIPULATOR

#include "base.hpp"

namespace Milx
{
	namespace Manipulators
	{
		class ProjectManipulator : public Base
		{
		public:
			void create(std::string, int, char**);
			void destroy(std::string, int, char**);
			void help(std::string, int, char**);
		private:
			void create_project_cmake(boost::filesystem::path);
		};
	}
}

#endif