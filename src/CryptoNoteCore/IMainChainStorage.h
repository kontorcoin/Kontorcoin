// Copyright (c) 2018, The CryptoNote developers, The Kontorcoin developers
//
// This file is part of Kontorcoin.
//
// Kontorcoin is free software: you can redistribute it and/or modify
// it under the terms of the GNU Lesser General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
//
// Kontorcoin is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU Lesser General Public License for more details.
//
// You should have received a copy of the GNU Lesser General Public License
// along with Kontorcoin.  If not, see <http://www.gnu.org/licenses/>.


#pragma once 

#include <CryptoNote.h>

namespace CryptoNote {

class IMainChainStorage {
public:
  virtual ~IMainChainStorage() { }

  virtual void pushBlock(const RawBlock& rawBlock) = 0;
  virtual void popBlock() = 0;

  virtual RawBlock getBlockByIndex(uint32_t index) const = 0;
  virtual uint32_t getBlockCount() const = 0;

  virtual void clear() = 0;
};

}
