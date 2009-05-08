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

#include <dlfcn.h>
#include "shared_module.hpp"

Milx::SharedModule::SharedModule(Application& app, const boost::filesystem::path file) :
    _app(app),
    Milx::Module(file.stem())
{
    _shared = dlopen(file.file_string().c_str(), RTLD_LAZY);
    if (_shared)
    {
        typedef void(*on_load_f)(Milx::Module&);
        on_load_f on_load = (on_load_f) dlsym(_shared, MILX_MODULE_LOAD);

        if (on_load)
            on_load(*this);
        else
            app.logger()->error(std::string(MILX_MODULE_LOAD) + " method not found in " + file.file_string());
    }
    else
        app.logger()->error("The module could not be loaded: " + file.file_string());
}

Milx::Application& Milx::SharedModule::application() const
{
    return _app;
}

Milx::SharedModule::~SharedModule()
{
    dlclose(_shared);
}
