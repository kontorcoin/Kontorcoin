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

#include <array>
#include <memory>
#include <cstdint>

#include <boost/optional.hpp>

#include "INode.h"
#include "ITransaction.h"

namespace CryptoNote {

struct BlockchainInterval {
  uint32_t startHeight;
  std::vector<Crypto::Hash> blocks;
};

struct CompleteBlock {
  Crypto::Hash blockHash;
  boost::optional<CryptoNote::BlockTemplate> block;
  // first transaction is always coinbase
  std::list<std::shared_ptr<ITransactionReader>> transactions;
};

}
