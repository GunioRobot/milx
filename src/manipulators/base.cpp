#include <boost/filesystem/fstream.hpp>
#include <iostream>
#include "base.hpp"

void Milx::Manipulators::Base::create_dir(boost::filesystem::path path)
{
    if (create_info(path))
        boost::filesystem::create_directory(path);
}

void Milx::Manipulators::Base::append_file(boost::filesystem::path path, std::string content, bool append)
{
    if (create_info(path) || append) {
		boost::filesystem::ofstream file(path, std::ios_base::app);
		file << content;
		file.close();
	}
}

bool Milx::Manipulators::Base::create_info(boost::filesystem::path path)
{
    bool exist = exists(path);
    std::cout << "\t" << (exist ? "exists" : "create");
    std::cout << " " << path << std::endl;

    return !exist;
}

void Milx::Manipulators::Base::display_help(std::string verb, int argc, char* argv[])
{
	std::cout << std::endl << "help for " << verb << " verb" << std::endl << std::endl;
	std::cout << "Call " << argv[0] << " in the following way:" << std::endl << std::endl;
	this->help(verb, argc, argv);
	std::cout << std::endl;
}

