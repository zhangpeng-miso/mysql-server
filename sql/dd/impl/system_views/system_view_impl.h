/* Copyright (c) 2017 Oracle and/or its affiliates. All rights reserved.

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; version 2 of the License.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software Foundation,
   51 Franklin Street, Suite 500, Boston, MA 02110-1335 USA */

#ifndef DD_SYSTEM_VIEWS__SYSTEM_VIEW_IMPL_INCLUDED
#define DD_SYSTEM_VIEWS__SYSTEM_VIEW_IMPL_INCLUDED

#include "sql/dd/types/system_view.h"                   // System_view

namespace dd {
namespace system_views {

template <typename T>
class System_view_impl : virtual public System_view
{
public:
  virtual const System_view_definition *view_definition() const
  {
    return &m_target_def;
  }

  virtual bool hidden() const
  { return false; }

protected:
  T m_target_def;
};

}
}

#endif // DD_SYSTEM_VIEWS__SYSTEM_VIEW_IMPL_INCLUDED
