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


#include "RpcNodeConfiguration.h"

namespace PaymentService {

namespace po = boost::program_options;

RpcNodeConfiguration::RpcNodeConfiguration() {
  daemonHost = "";
  daemonPort = 0;
}

void RpcNodeConfiguration::initOptions(boost::program_options::options_description& desc) {
  desc.add_options()
    ("daemon-address", po::value<std::string>()->default_value("localhost"), "kontorcoind address")
    ("daemon-port", po::value<uint16_t>()->default_value(8081), "kontorcoind port");
}

void RpcNodeConfiguration::init(const boost::program_options::variables_map& options) {
  if (options.count("daemon-address") != 0 && (!options["daemon-address"].defaulted() || daemonHost.empty())) {
    daemonHost = options["daemon-address"].as<std::string>();
  }

  if (options.count("daemon-port") != 0 && (!options["daemon-port"].defaulted() || daemonPort == 0)) {
    daemonPort = options["daemon-port"].as<uint16_t>();
  }
}

} //namespace PaymentService
