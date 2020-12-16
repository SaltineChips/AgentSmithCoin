// Copyright (c) 2010 Satoshi Nakamoto
// Copyright (c) 2009-2012 The Bitcoin developers
// Copyright (c) 2016-2018 The AgentSmithCoin developers
// Distributed under the MIT/X11 software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#include "assert.h"

#include "chainparams.h"
#include "main.h"
#include "../util/util.h"

#include <boost/assign/list_of.hpp>

using namespace boost::assign;

struct SeedSpec6 {
    uint8_t addr[16];
    uint16_t port;
};

#include "chainparamsseeds.h"

//
// Main network
//

// Convert the pnSeeds6 array into usable address objects.
static void convertSeed6(std::vector<CAddress> &vSeedsOut, const SeedSpec6 *data, unsigned int count)
{
    // It'll only connect to one or two seed nodes because once it connects,
    // it'll get a pile of addresses with newer timestamps.
    // Seed nodes are given a random 'last seen time' of between one and two
    // weeks ago.
    const int64_t nOneWeek = 7*24*60*60;
    for (unsigned int i = 0; i < count; i++)
    {
        struct in6_addr ip;
        memcpy(&ip, data[i].addr, sizeof(ip));
        CAddress addr(CService(ip, data[i].port));
        addr.nTime = GetTime() - GetRand(nOneWeek) - nOneWeek;
        vSeedsOut.push_back(addr);
    }
}

class CMainParams : public CChainParams {
public:
    CMainParams() {
        // The message start string is designed to be unlikely to occur in normal data.
        // The characters are rarely used upper ASCII, not valid as UTF-8, and produce
        // a large 4-byte int at any alignment.
        pchMessageStart[0] = 0x41;
        pchMessageStart[1] = 0x1b;
        pchMessageStart[2] = 0x21;
        pchMessageStart[3] = 0xaf;
        vAlertPubKey = ParseHex("01a22ffae96c9056be6b659c91a94fbfebeb5d5257feac3548695c62f7c2f812356131a669df3be611393f454852a2d08c6314bba5ca3cbe5616262da3d4a6efac");
        nDefaultPort = 92012; // When China Uncensored was started
        nRPCPort = 12351; // Total number of episodes available at http://www.chinauncensored.tv/episodes/
        bnProofOfWorkLimit = CBigNum(~uint256(0) >> 20);
        bnProofOfStakeLimit = CBigNum(~uint256(0) >> 20);

        const char* pszTimestamp = "Selenium Java – How to avoid bot detection by websites when using chromedriver.exe | Mark | December 15, 2020";
        std::vector<CTxIn> vin;
        vin.resize(1);
        vin[0].scriptSig = CScript() << 0 << CBigNum(42) << vector<unsigned char>((const unsigned char*)pszTimestamp, (const unsigned char*)pszTimestamp + strlen(pszTimestamp));
        std::vector<CTxOut> vout;
        vout.resize(1);
        vout[0].SetEmpty();
        CTransaction txNew(1, 1608156000, vin, vout, 0);
        genesis.vtx.push_back(txNew);
        genesis.hashPrevBlock = 0;
        genesis.hashMerkleRoot = genesis.BuildMerkleTree();
        genesis.nVersion = 1;
        genesis.nTime    = 1608156000;
        genesis.nBits    = bnProofOfWorkLimit.GetCompact();
        genesis.nNonce   = 0;
        /** Genesis Block MainNet */
        /*
        Hashed MainNet Genesis Block Output
        block.hashMerkleRoot == cb39b483854e186064521b110b88a59ef273902f5dbc6f8dc0ed9e9982d285f4
        block.nTime = 1597839206
        block.nNonce = 2782705
        block.GetHash = 00000713be12f38f916c01efee76e609589c92732c1ec0925801746c0e147019
        */

        hashGenesisBlock = genesis.GetHash();
        assert(hashGenesisBlock == uint256("0x"));
        assert(genesis.hashMerkleRoot == uint256("0x"));

        /** DEPRICATED IN QT 5.6+ (To compile on Qt5.5.1 and lower uncomment  */
        /*
        base58Prefixes[PUBKEY_ADDRESS] = list_of(33);
        base58Prefixes[SCRIPT_ADDRESS] = list_of(92);
        base58Prefixes[SECRET_KEY] =     list_of(144);
        base58Prefixes[EXT_PUBLIC_KEY] = list_of(0x04)(0x88)(0xB2)(0x1E);
        base58Prefixes[EXT_SECRET_KEY] = list_of(0x04)(0x88)(0xAD)(0xE4);
        */
        /** REQUIRED IN QT 5.6+  (To compile on Qt5.5.1 and lower comment out below) */
        base58Prefixes[PUBKEY_ADDRESS] = std::vector<unsigned char>(1,23);//A for Agent Smith
        base58Prefixes[SCRIPT_ADDRESS] = std::vector<unsigned char>(1,50);//M for Matt
        base58Prefixes[SECRET_KEY] =     std::vector<unsigned char>(1,63);//S for Shelly
        base58Prefixes[EXT_PUBLIC_KEY] = boost::assign::list_of(0x04)(0x88)(0xB2)(0x1E).convert_to_container<std::vector<unsigned char> >();
        base58Prefixes[EXT_SECRET_KEY] = boost::assign::list_of(0x04)(0x88)(0xAD)(0xE4).convert_to_container<std::vector<unsigned char> >();

        // AgentSmithCoin dns seeds
        //vSeeds.push_back(CDNSSeedData("cryptocoderz.com",  "esp.cryptocoderz.com"));

        convertSeed6(vFixedSeeds, pnSeed6_main, ARRAYLEN(pnSeed6_main));

        // Initial block spacing, attempted 40 second block time
        nTargetSpacing = 1 * 40;
        // Block rate reduced for ~40 Second block times
        // Due to hybrid mining blocktime still varied wildly during
        // this time between 15 seconds and 1 minute
        if(nBestHeight > nBlocktimeregress)
            nTargetSpacing = 2.5 * 60;
        // Block rate reduced for 3-5 Minute block times
        // this is in conjunction with DGW-v3 retarget fork
        if(nBestHeight > nGravityFork)
            nTargetSpacing = BLOCK_SPACING * 1;
        nTargetTimespan = 10 * nTargetSpacing;
        nStartPoSBlock = 80; // Delay PoS start until swap start

    }

    virtual const CBlock& GenesisBlock() const { return genesis; }
    virtual Network NetworkID() const { return CChainParams::MAIN; }

    virtual const vector<CAddress>& FixedSeeds() const {
        return vFixedSeeds;
    }
protected:
    CBlock genesis;
    vector<CAddress> vFixedSeeds;
};
static CMainParams mainParams;


//
// Testnet
//

class CTestNetParams : public CMainParams {
public:
    CTestNetParams() {
        // The message start string is designed to be unlikely to occur in normal data.
        // The characters are rarely used upper ASCII, not valid as UTF-8, and produce
        // a large 4-byte int at any alignment.
        pchMessageStart[0] = 0xac;
        pchMessageStart[1] = 0x36;
        pchMessageStart[2] = 0x78;
        pchMessageStart[3] = 0x3a;
        bnProofOfWorkLimit = CBigNum(~uint256(0) >> 16);
        bnProofOfStakeLimit = CBigNum(~uint256(0) >> 16);

        vAlertPubKey = ParseHex("01a22531e96c9056be6b123561a94fbfebeb5d5257fe044b88695c62f7c2f81f85d131a669df3be611393f45485457698c6314bba5ca3cbe5616262db3d4a6efac");
        nDefaultPort = 22019; // Hong Kong Protests
        nRPCPort = 30620; // 30^th day of June, 2020 we all know what happened on this date.
        strDataDir = "testnet";

        // Modify the testnet genesis block so the timestamp is valid for a later start.
        genesis.nBits  = bnProofOfWorkLimit.GetCompact();
        genesis.nNonce = 0;

        /** Genesis Block TestNet */
        /*
        Hashed Testnet Genesis Block Output
        block.hashMerkleRoot == cb39b483854e186064521b110b88a59ef273902f5dbc6f8dc0ed9e9982d285f4
        block.nTime = 1597839206
        block.nNonce = 140804
        block.GetHash = 0000d84ce949ea2f89cff1ca3feb95f41ad0cc8d00f6f240879d91a865732c24
        */

        hashGenesisBlock = genesis.GetHash();
        assert(hashGenesisBlock == uint256("0x"));

        vFixedSeeds.clear();
        vSeeds.clear();

        /** DEPRICATED IN QT 5.6+ (To compile on Qt5.5.1 and lower uncomment  */
        /*
        base58Prefixes[PUBKEY_ADDRESS] = list_of(34);
        base58Prefixes[SCRIPT_ADDRESS] = list_of(94);
        base58Prefixes[SECRET_KEY]     = list_of(143);
        base58Prefixes[EXT_PUBLIC_KEY] = list_of(0x04)(0x35)(0x87)(0xCF);
        base58Prefixes[EXT_SECRET_KEY] = list_of(0x04)(0x35)(0x83)(0x94);
        */
        /** REQUIRED IN QT 5.6+  (To compile on Qt5.5.1 and lower comment out below */
        base58Prefixes[PUBKEY_ADDRESS] = std::vector<unsigned char>(1,24);
        base58Prefixes[SCRIPT_ADDRESS] = std::vector<unsigned char>(1,64);
        base58Prefixes[SECRET_KEY] =     std::vector<unsigned char>(1,65);
        base58Prefixes[EXT_PUBLIC_KEY] = boost::assign::list_of(0x04)(0x35)(0x87)(0xCF).convert_to_container<std::vector<unsigned char> >();
        base58Prefixes[EXT_SECRET_KEY] = boost::assign::list_of(0x04)(0x35)(0x83)(0x94).convert_to_container<std::vector<unsigned char> >();

        convertSeed6(vFixedSeeds, pnSeed6_test, ARRAYLEN(pnSeed6_test));

        nTargetSpacing = 20;
        nStartPoSBlock = 3;
    }
    virtual Network NetworkID() const { return CChainParams::TESTNET; }
};
static CTestNetParams testNetParams;


//
// Regression test
//
class CRegTestParams : public CTestNetParams {
public:
    CRegTestParams() {
        pchMessageStart[0] = 0x21;
        pchMessageStart[1] = 0xd1;
        pchMessageStart[2] = 0x02;
        pchMessageStart[3] = 0x16;
        bnProofOfWorkLimit = CBigNum(~uint256(0) >> 1);
        genesis.nTime = timeRegNetGenesis;
        genesis.nBits  = bnProofOfWorkLimit.GetCompact();
        genesis.nNonce = 8;
        hashGenesisBlock = genesis.GetHash();
        nDefaultPort = 12201;
        strDataDir = "regtest";

        /** Genesis Block TestNet */
        /*
Hashed RegNet Genesis Block Output
block.hashMerkleRoot == cb39b483854e186064521b110b88a59ef273902f5dbc6f8dc0ed9e9982d285f4
block.nTime = 1473059000
block.nNonce = 8
block.GetHash = e1471b2fbe13d5283e84618359ad3a871a5358452921c156e29620f6142cc4a5
        */

        assert(hashGenesisBlock == uint256("0x"));

        vSeeds.clear();  // Regtest mode doesn't have any DNS seeds.
    }

    virtual bool RequireRPCPassword() const { return false; }
    virtual Network NetworkID() const { return CChainParams::REGTEST; }
};
static CRegTestParams regTestParams;

static CChainParams *pCurrentParams = &mainParams;

const CChainParams &Params() {
    return *pCurrentParams;
}

void SelectParams(CChainParams::Network network) {
    switch (network) {
        case CChainParams::MAIN:
            pCurrentParams = &mainParams;
            break;
        case CChainParams::TESTNET:
            pCurrentParams = &testNetParams;
            break;
        case CChainParams::REGTEST:
            pCurrentParams = &regTestParams;
            break;
        default:
            assert(false && "Unimplemented network");
            return;
    }
}

bool SelectParamsFromCommandLine() {
    bool fRegTest = GetBoolArg("-regtest", false);
    bool fTestNet = GetBoolArg("-testnet", false);

    if (fTestNet && fRegTest) {
        return false;
    }

    if (fRegTest) {
        SelectParams(CChainParams::REGTEST);
    } else if (fTestNet) {
        SelectParams(CChainParams::TESTNET);
    } else {
        SelectParams(CChainParams::MAIN);
    }
    return true;
}