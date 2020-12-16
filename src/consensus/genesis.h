// Copyright (c) 2016-2020 The CryptoCoderz Team / AgentSmithCoin
// Distributed under the MIT/X11 software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.
#ifndef AGENTSMITHCOIN_GENESIS_H
#define AGENTSMITHCOIN_GENESIS_H

#include "primitives/bignum.h"

/** Genesis Start Time */
static const unsigned int timeGenesisBlock = 1608156000; // Mon, 05 Sep 2016 07:00:00 GMT
/** Genesis RegNet Start Time */
static const unsigned int timeRegNetGenesis = 1608156000; // Mon, 05 Sep 2016 07:00:00 GMT
/** Genesis Nonce */
static const unsigned int nNonceMain = 0;
/** Genesis Nonce Testnet */
static const unsigned int nNonceTest = 0;
/** Genesis Nonce Regnet */
static const unsigned int nNonceReg = 8;
/** Main Net Genesis Block */
static const uint256 nGenesisBlock("0x");
/** Test Net Genesis Block */
static const uint256 hashTestNetGenesisBlock("0x");
/** Reg Net Genesis Block */
static const uint256 hashRegNetGenesisBlock("0x");
/** Genesis Merkleroot */
static const uint256 nGenesisMerkle("0x");

#endif
