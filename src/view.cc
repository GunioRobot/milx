/*
 * Copyright 2010 Carlos Junior
 *
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

#include <sstream>
#include <string>
#include <map>
#include <memory>

#include "view.h"
#include "view/renderer.h"

std::map<std::string, std::tr1::shared_ptr<milx::view::FactoryBase> > milx::view::instances;

milx::view::Renderer* milx::view::create_view(const milx::Path& p) {
  return instances[p.extension()]->create_view(p);
}

