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


#include "VectorMainChainStorage.h"

#include <CryptoNoteCore/CryptoNoteTools.h>

namespace CryptoNote {

void VectorMainChainStorage::pushBlock(const RawBlock& rawBlock) {
  storage.push_back(rawBlock);
}

void VectorMainChainStorage::popBlock() {
  storage.pop_back();
}

RawBlock VectorMainChainStorage::getBlockByIndex(uint32_t index) const {
  return storage.at(index);
}

uint32_t VectorMainChainStorage::getBlockCount() const {
  return static_cast<uint32_t>(storage.size());
}

void VectorMainChainStorage::clear() {
  storage.clear();
}

std::unique_ptr<IMainChainStorage> createVectorMainChainStorage(const Currency& currency) {
  std::unique_ptr<IMainChainStorage> storage(new VectorMainChainStorage());

  RawBlock genesis;
  genesis.block = toBinaryArray(currency.genesisBlock());
  storage->pushBlock(genesis);

  return storage;
}

}
