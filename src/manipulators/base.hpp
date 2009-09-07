#ifndef MILX_MANIPULATOR_BASE
#define MILX_MANIPULATOR_BASE

#include <string>
#include <map>
#include <boost/filesystem.hpp>

namespace Milx
{
	namespace Manipulators
	{
		class Base
		{
		public:
			virtual void create(std::string, int, char**)=0;
			virtual void destroy(std::string, int, char**)=0;
			virtual void help(std::string, int, char**)=0;
			void display_help(std::string, int, char**);
		protected:
			void create_dir(boost::filesystem::path);
			void append_file(boost::filesystem::path, std::string, bool=true);
		private:
			bool create_info(boost::filesystem::path);
		};
	}
}

#endif
