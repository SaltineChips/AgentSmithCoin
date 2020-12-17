// Copyright (c) 2016-2020 The CryptoCoderz Team / AgentSmithCoin
// Distributed under the MIT/X11 software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.
#ifndef AGENTSMITHCOIN_MINING_H
#define AGENTSMITHCOIN_MINING_H

#include "primitives/bignum.h"

/** Minimum nCoinAge required to stake PoS (v2) */
static const unsigned int nStakeMinAge = 2 * 60 * 60; // 2 hours
/** Minimum nCoinAge required to stake PoS (v3) */
static const int nStakeMinConfirmations = 20; // 5(minutes) × 20(confirms) ÷ 60(minutes) = less than 2 hours
/** Time to elapse before new modifier is computed */
static const unsigned int nModifierInterval = 10 * 60;
/** PoS Subsidy */
static const int64_t COIN_YEAR_REWARD = 10 * CENT; // 10% attempted annual stake
/** Block spacing preferred */
static const int64_t BLOCK_SPACING = 5 * 60; // 5 minute block time (average)
/** Block spacing minimum */
static const int64_t BLOCK_SPACING_MIN = 3.5 * 60;
/** Block spacing maximum */
static const int64_t BLOCK_SPACING_MAX = 7.5 * 60;
/** Genesis block subsidy */
static const int64_t nGenesisBlockReward = 1 * COIN;
/** Reserve block subsidy */
static const int64_t nBlockRewardReserve = 9600 * COIN; // 960000 / 100 as 9600 will be paid out per block throughout 100 blocks
/** Starting block subsidy */
static const int64_t nBlockPoWReward = 10 * COIN;
/** Invalid block subsidy */
static const int64_t nBlockRewardBuffer = 0.1 * COIN;
/** Coinbase transaction outputs can only be spent after this number of new blocks (network rule) */
static const int nCoinbaseMaturity = 10;

#endif
