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

#include "IBlockchainCacheFactory.h"

#include "BlockchainCache.h"

namespace CryptoNote {

class MemoryBlockchainCacheFactory: public IBlockchainCacheFactory {
public:
  MemoryBlockchainCacheFactory(const std::string& filename, Logging::ILogger& logger);
  virtual ~MemoryBlockchainCacheFactory() override;

  std::unique_ptr<IBlockchainCache> createRootBlockchainCache(const Currency& currency) override;
  std::unique_ptr<IBlockchainCache> createBlockchainCache(const Currency& currency, IBlockchainCache* parent, uint32_t startIndex = 0) override;

private:
  std::string filename;
  Logging::ILogger& logger;
};

} //namespace CryptoNote
