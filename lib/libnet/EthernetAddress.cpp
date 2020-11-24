/*
 * Copyright (C) 2015 Niek Linnenbank
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include <Log.h>
#include "EthernetAddress.h"

EthernetAddress::EthernetAddress(Ethernet *eth)
{
    m_eth = eth;
}

EthernetAddress::~EthernetAddress()
{
}

FileSystem::Result EthernetAddress::read(IOBuffer & buffer,
                                         Size & size,
                                         const Size offset)
{
    Ethernet::Address addr;

    m_eth->getAddress(&addr);
    String s = Ethernet::toString(addr);

    if (offset >= s.length())
    {
        size = 0;
        return FileSystem::Success;
    }

    buffer.write(*s, s.length());
    size = s.length();
    return FileSystem::Success;
}

FileSystem::Result EthernetAddress::write(IOBuffer & buffer,
                                          Size & size,
                                          const Size offset)
{
    return FileSystem::NotSupported;
}
