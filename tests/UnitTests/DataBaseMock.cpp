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


#include "DataBaseMock.h"

using namespace CryptoNote;

DataBaseMock::~DataBaseMock() {

}

std::error_code DataBaseMock::write(IWriteBatch& batch) {
  auto append = batch.extractRawDataToInsert();
  for (auto pr : append) {
    baseState[pr.first] = pr.second;
  }
  auto remove = batch.extractRawKeysToRemove();
  for (auto key : remove) {
    baseState.erase(key);
  }
  return{};
}

std::error_code DataBaseMock::writeSync(IWriteBatch& batch) {
  return write(batch);
}

std::error_code DataBaseMock::read(IReadBatch& batch) {
  auto keys = batch.getRawKeys();
  std::vector<std::string> kvs;
  std::vector<bool> states;
  for (auto key : keys) {
    auto it = baseState.find(key);
    if (it != baseState.end()) {
      kvs.push_back(it->second);
      states.push_back(true);
    } else {
      kvs.push_back("");
      states.push_back(false);
    }
  }

  batch.submitRawResult(kvs, states);
  return{};
}

std::unordered_map<uint32_t, RawBlock> DataBaseMock::blocks() {
  BlockchainReadBatch req;
  for (int i = 0; i < 30; ++i) {
    req.requestRawBlock(i);
  }
  read(req);
  auto result = req.extractResult();
  return result.getRawBlocks();
}
