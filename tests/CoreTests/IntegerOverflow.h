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
#include "Chaingen.h"

struct gen_uint_overflow_base : public test_chain_unit_base {
  gen_uint_overflow_base();

  bool check_tx_verification_context(bool tve, bool tx_added, size_t event_idx, const CryptoNote::Transaction& tx);
  bool check_block_verification_context(std::error_code bve, size_t event_idx, const CryptoNote::BlockTemplate& block);
  bool check_block_verification_context(std::error_code bve, size_t event_idx, const CryptoNote::RawBlock& block);

  bool mark_last_valid_block(CryptoNote::Core& c, size_t ev_index, const std::vector<test_event_entry>& events);

private:
  size_t m_last_valid_block_event_idx;
};

struct gen_uint_overflow_1 : public gen_uint_overflow_base {
  bool generate(std::vector<test_event_entry>& events) const;
};

struct gen_uint_overflow_2 : public gen_uint_overflow_base {
  bool generate(std::vector<test_event_entry>& events) const;
};
