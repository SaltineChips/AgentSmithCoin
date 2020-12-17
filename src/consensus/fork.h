// Copyright (c) 2016-2020 The CryptoCoderz Team / AgentSmithCoin
// Distributed under the MIT/X11 software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.
#ifndef AGENTSMITHCOIN_FORK_H
#define AGENTSMITHCOIN_FORK_H

#include "primitives/bignum.h"

/** Genesis Block Height */
static const int64_t nGenesisHeight = 0;
/** Reserve Phase start block */
static const int64_t nReservePhaseStart = 10;
/** Reserve Phase end block */
static const int64_t nReservePhaseEnd = 100; // rounded +95 blocks for ~17.2 Swap mine
/** Velocity toggle block */
static const int64_t VELOCITY_TOGGLE = 40; // Implementation of the Velocity system into the chain.
/** Velocity retarget toggle block */
static const int64_t VELOCITY_TDIFF = 0; // Use Velocity's retargetting method.
/** Proof-of-Stake Version 3.0 implementation fork */
inline bool IsProtocolV3(int64_t nTime) { return TestNet() || nTime > 1535673600; } // ON (TOGGLED Fri, 31 Aug 2018 00:00:00 GMT)

#endif
