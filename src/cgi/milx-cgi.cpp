/*
 * This file is part of Milx.
 *
 * Milx is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * Milx is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with Milx.  If not, see <http://www.gnu.org/licenses/lgpl-3.0.txt>.
 */

#include <boost/filesystem/operations.hpp>
#include <boost/filesystem/path.hpp>
#include <iostream>
#include <string>
#include "cgi_handler.hpp"
#include "../application.hpp"

int main(int, char**)
{
    Milx::Application app;

    boost::filesystem::path full_path(boost::filesystem::initial_path<boost::filesystem::path>());
    boost::filesystem::directory_iterator end_iter;

    for (boost::filesystem::directory_iterator dir_itr(full_path);
	 dir_itr != end_iter;
	 ++dir_itr )
    {
        try
        {
            if (boost::filesystem::is_regular_file(dir_itr->status()) &&
	        dir_itr->path().extension().compare(".so") == 0)
                app.loadModule(dir_itr->path());
        }
	catch (const std::exception & ex)
        {
            // TODO use Application logger
            std::cout << dir_itr->path().filename() << " " << ex.what() << std::endl;
	}
    }
    
    Milx::CGI::Handler::run(app);

    return 0;
}
