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

#include <cstdint>
#include <utility>

namespace CryptoNote {

class IFusionManager {
public:
  struct EstimateResult {
    size_t fusionReadyCount;
    size_t totalOutputCount;
  };

  virtual ~IFusionManager() {}

  virtual size_t createFusionTransaction(uint64_t threshold, uint16_t mixin,
    const std::vector<std::string>& sourceAddresses = {}, const std::string& destinationAddress = "") = 0;
  virtual bool isFusionTransaction(size_t transactionId) const = 0;
  virtual EstimateResult estimate(uint64_t threshold, const std::vector<std::string>& sourceAddresses = {}) const = 0;
};

}
