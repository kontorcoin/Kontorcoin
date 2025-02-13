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


#include <future>
#include <INode.h>

namespace Tests {

class NodeCallback {
public:
  CryptoNote::INode::Callback callback() {
    prom = std::promise<std::error_code>(); // reset std::promise
    result = prom.get_future();
    return [this](std::error_code ec) {
      std::promise<std::error_code> localPromise(std::move(prom));
      localPromise.set_value(ec);
    };
  }

  std::error_code get() {
    return result.get();
  }

private:
  std::promise<std::error_code> prom;
  std::future<std::error_code> result;
};

}
