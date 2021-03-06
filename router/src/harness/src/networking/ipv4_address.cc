/*
  Copyright (c) 2016, 2020, Oracle and/or its affiliates. All rights reserved.

  This program is free software; you can redistribute it and/or modify
  it under the terms of the GNU General Public License, version 2.0,
  as published by the Free Software Foundation.

  This program is also distributed with certain software (including
  but not limited to OpenSSL) that is licensed under separate terms,
  as designated in a particular file or component or in included license
  documentation.  The authors of MySQL hereby grant you an additional
  permission to link the program and your derivative works with the
  separately licensed software that they have included with MySQL.

  This program is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU General Public License for more details.

  You should have received a copy of the GNU General Public License
  along with this program; if not, write to the Free Software
  Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
*/

#include "mysql/harness/networking/ipv4_address.h"

#ifndef _WIN32
#include <arpa/inet.h>
#include <netinet/in.h>
#include <sys/socket.h>
#else
#include <windows.h>
#include <winsock2.h>
#include <ws2tcpip.h>
#endif
#include <array>
#include <stdexcept>
#include <string>
#include <system_error>

#include "mysql/harness/net_ts/impl/resolver.h"

namespace mysql_harness {

IPv4Address::IPv4Address(const char *data) {
  if (inet_pton(AF_INET, data, &address_) <= 0) {
    throw std::invalid_argument(std::string("ipv4 parsing error"));
  }
}

std::string IPv4Address::str() const {
  std::array<char, INET_ADDRSTRLEN> tmp;

  const auto ntop_res = net::impl::resolver::inetntop(
      AF_INET, const_cast<in_addr *>(&address_), tmp.data(), tmp.size());

  if (!ntop_res) {
    throw std::system_error(ntop_res.error(), "inet_ntop failed");
  }

  return ntop_res.value();
}

}  // namespace mysql_harness
