// Copyright (c) 2010 Satoshi Nakamoton

// Copyright (c) 2009-2014 The Bitcoin developers

// Copyright (c) 2014-2015 The Dash developers

// Copyright (c) 2015-2018 The PIVX developers

// Distributed under the MIT software license, see the accompanying

// file COPYING or http://www.opensource.org/licenses/mit-license.php.



#include "libzerocoin/Params.h"

#include "chainparams.h"

#include "random.h"

#include "util.h"

#include "utilstrencodings.h"



#include <assert.h>



#include <boost/assign/list_of.hpp>


using namespace std;

using namespace boost::assign;



struct SeedSpec6 {

    uint8_t addr[16];

    uint16_t port;

};



#include "chainparamsseeds.h"



/**

 * Main network

 */



//! Convert the pnSeeds6 array into usable address objects.

static void convertSeed6(std::vector<CAddress>& vSeedsOut, const SeedSpec6* data, unsigned int count)

{

    // It'll only connect to one or two seed nodes because once it connects,

    // it'll get a pile of addresses with newer timestamps.

    // Seed nodes are given a random 'last seen time' of between one and two

    // weeks ago.

    const int64_t nOneWeek = 7 * 24 * 60 * 60;

    for (unsigned int i = 0; i < count; i++) {

        struct in6_addr ip;

        memcpy(&ip, data[i].addr, sizeof(ip));

        CAddress addr(CService(ip, data[i].port));

        addr.nTime = GetTime() - GetRand(nOneWeek) - nOneWeek;

        vSeedsOut.push_back(addr);

    }

}



//   What makes a good checkpoint block?

// + Is surrounded by blocks with reasonable timestamps

//   (no blocks before with a timestamp after, none after with

//    timestamp before)

// + Contains no strange transactions

static Checkpoints::MapCheckpoints mapCheckpoints =

    boost::assign::map_list_of

    (0, uint256("0x00335f26e1075f9b551bbd79a448237d98b5712015637567a966d0aa97164773"))

    (594, uint256("0x0e3ec1334720ab5b0c0dfb44a5c2ae2105f0c044ac58f6ca67041d26b4900775"));


static const Checkpoints::CCheckpointData data = {

    &mapCheckpoints,

    1526550051, // * UNIX timestamp of last checkpoint block

    992,          // * total number of transactions between genesis and last checkpoint

                //    (the tx=... number in the SetBestChain debug.log lines)

    2000        // * estimated number of transactions per day after checkpoint

};



static Checkpoints::MapCheckpoints mapCheckpointsTestnet =

    boost::assign::map_list_of(0, uint256("0x000a9cd524c5d984165a05ac14bc6d6899380dbf39bf5def75df6d4daf8b0511"));

static const Checkpoints::CCheckpointData dataTestnet = {

    &mapCheckpointsTestnet,

    1526511400,

    0,

    250

};



static Checkpoints::MapCheckpoints mapCheckpointsRegtest =

    boost::assign::map_list_of(0, uint256("0x459439a5882d4ac338877907b79cce3d1e077bbe20f1d004eee4e44fc053135d"));

static const Checkpoints::CCheckpointData dataRegtest = {

    &mapCheckpointsRegtest,

    1526511800,

    0,

    100

};



libzerocoin::ZerocoinParams* CChainParams::Zerocoin_Params(bool useModulusV1) const

{

    assert(this);

    static CBigNum bnHexModulus = 0;

    if (!bnHexModulus)

        bnHexModulus.SetHex(zerocoinModulus);

    static libzerocoin::ZerocoinParams ZCParamsHex = libzerocoin::ZerocoinParams(bnHexModulus);

    static CBigNum bnDecModulus = 0;

    if (!bnDecModulus)

        bnDecModulus.SetDec(zerocoinModulus);

    static libzerocoin::ZerocoinParams ZCParamsDec = libzerocoin::ZerocoinParams(bnDecModulus);



    if (useModulusV1)

        return &ZCParamsHex;



    return &ZCParamsDec;

}



class CMainParams : public CChainParams

{

public:

    CMainParams()

    {

        networkID = CBaseChainParams::MAIN;

        strNetworkID = "main";

        /**

         * The message start string is designed to be unlikely to occur in normal data.

         * The characters are rarely used upper ASCII, not valid as UTF-8, and produce

         * a large 4-byte int at any alignment.

         */

        pchMessageStart[0] = 0x72;

        pchMessageStart[1] = 0xa6;

        pchMessageStart[2] = 0xef;

        pchMessageStart[3] = 0xc9;

        vAlertPubKey = ParseHex("049f4d69d9546edb8e9db402a6d022952c64f460dac7a323df223e42e9d827c9db35b0bd656c592f89a601919b1158db9ecbb1b37f7f49b03132ae6f3d7aba87df");

        nDefaultPort = 21461;

        bnProofOfWorkLimit = ~uint256(0) >> 10; // DRIP starting difficulty is 1 / 2^12

        nSubsidyHalvingInterval = 210000;

        nMaxReorganizationDepth = 100;

        nEnforceBlockUpgradeMajority = 750;

        nRejectBlockOutdatedMajority = 950;

        nToCheckBlockUpgradeMajority = 1000;

        nMinerThreads = 0;

        nTargetTimespan = 1 * 60; // DRIP: 1 day

        nTargetSpacing = 1 * 60;  // DRIP: 1 minute

        nMaturity = 50;

        nMasternodeCountDrift = 20;

        nMaxMoneyOut = 100000000 * COIN;



        /** Height or Time Based Activations **/

        nLastPOWBlock = 200;

        nModifierUpdateBlock = 999999999;

        nZerocoinStartHeight = 150;

        nZerocoinStartTime = 1526520200; // Sat, 05 May 2018 15:30:00

        nBlockEnforceSerialRange = 153; //Enforce serial range starting this block

        nBlockRecalculateAccumulators = 999999999; //Trigger a recalculation of accumulators

        nBlockFirstFraudulent = 999999999; //First block that bad serials emerged

        nBlockLastGoodCheckpoint = 999999999; //Last valid accumulator checkpoint

        nBlockEnforceInvalidUTXO = 999999999; //Start enforcing the invalid UTXO's

        nInvalidAmountFiltered = 0*COIN; //Amount of invalid coins filtered through exchanges, that should be considered valid

        nBlockZerocoinV2 = 150; //!> The block that zerocoin v2 becomes active - roughly Tuesday, May 8, 2018 4:00:00 AM GMT

        nEnforceNewSporkKey = 1525982400; //!> Sporks signed after (GMT): Tuesday, May 1, 2018 7:00:00 AM GMT must use the new spork key

        nRejectOldSporkKey = 1527811200; //!> Fully reject old spork key after (GMT): Friday, June 1, 2018 12:00:00 AM



        /**

         * Build the genesis block. Note that the output of the genesis coinbase cannot

         * be spent as it did not originally exist in the database.

         *

         * CBlock(hash=00000ffd590b14, ver=1, hashPrevBlock=00000000000000, hashMerkleRoot=e0028e, nTime=1390095618, nBits=1e0ffff0, nNonce=28917698, vtx=1)

         *   CTransaction(hash=e0028e, ver=1, vin.size=1, vout.size=1, nLockTime=0)

         *     CTxIn(COutPoint(000000, -1), coinbase 04ffff001d01044c5957697265642030392f4a616e2f3230313420546865204772616e64204578706572696d656e7420476f6573204c6976653a204f76657273746f636b2e636f6d204973204e6f7720416363657074696e6720426974636f696e73)

         *     CTxOut(nValue=50.00000000, scriptPubKey=0xA9037BAC7050C479B121CF)

         *   vMerkleTree: e0028e

         */

        const char* pszTimestamp = "Trump: Well see if North Korea summit still on";

        CMutableTransaction txNew;

        txNew.vin.resize(1);

        txNew.vout.resize(1);

        txNew.vin[0].scriptSig = CScript() << 486604799 << CScriptNum(4) << vector<unsigned char>((const unsigned char*)pszTimestamp, (const unsigned char*)pszTimestamp + strlen(pszTimestamp));

        txNew.vout[0].SetEmpty();

        txNew.vout[0].scriptPubKey = CScript() << ParseHex("040b17bbb256159c522c7c17cb76f2eb64ce44209359c1e988efb0bd8f73a2c3768a4f2bbfa0e2980980618f0cd94f68fa2c475387587d951c07fcf28da46b8f81") << OP_CHECKSIG;

        genesis.vtx.push_back(txNew);

        genesis.hashPrevBlock = 0;

        genesis.hashMerkleRoot = genesis.BuildMerkleTree();

        genesis.nVersion = 1;

	genesis.nTime = 1526511200;

	genesis.nBits = bnProofOfWorkLimit.GetCompact();

	genesis.nNonce = 1309;


        hashGenesisBlock = genesis.GetHash();



	assert(hashGenesisBlock == uint256("0x00335f26e1075f9b551bbd79a448237d98b5712015637567a966d0aa97164773"));

	assert(genesis.hashMerkleRoot == uint256("0xe21dd14249a975413f17a9629850b35527d4130c7e5507caa20002ee06ce9f53"));



        vSeeds.push_back(CDNSSeedData("0", "dns0.dripcoin.tech"));     // Primary DNS Seeder

        vSeeds.push_back(CDNSSeedData("1", "dns0.lottereth.com"));    // Secondary DNS Seeder



        base58Prefixes[PUBKEY_ADDRESS] = std::vector<unsigned char>(1, 30);

        base58Prefixes[SCRIPT_ADDRESS] = std::vector<unsigned char>(1, 13);

        base58Prefixes[SECRET_KEY] = std::vector<unsigned char>(1, 212);

        base58Prefixes[EXT_PUBLIC_KEY] = boost::assign::list_of(0x02)(0x2D)(0x25)(0x33).convert_to_container<std::vector<unsigned char> >();

        base58Prefixes[EXT_SECRET_KEY] = boost::assign::list_of(0x02)(0x21)(0x31)(0x2B).convert_to_container<std::vector<unsigned char> >();

        // 	BIP44 coin type is from https://github.com/satoshilabs/slips/blob/master/slip-0044.md

        base58Prefixes[EXT_COIN_TYPE] = boost::assign::list_of(0x80)(0x00)(0x00)(0x77).convert_to_container<std::vector<unsigned char> >();



        convertSeed6(vFixedSeeds, pnSeed6_main, ARRAYLEN(pnSeed6_main));



        fMiningRequiresPeers = true;

        fAllowMinDifficultyBlocks = false;

        fDefaultConsistencyChecks = false;

        fRequireStandard = true;

        fMineBlocksOnDemand = false;

        fSkipProofOfWorkCheck = false;

        fTestnetToBeDeprecatedFieldRPC = false;

        fHeadersFirstSyncingActive = false;



        nPoolMaxTransactions = 3;

        strSporkKey = "0268ac189143726749a5c56d4358e45b47ec914ae07898bd3ae4a5acb0dbf7fd11";

        strObfuscationPoolDummyAddress = "DLMT3JZmBEuoE6bwpJYL4Q5WtThzMce3E9";

        strSporkKeyOld = "04B433E6598390C992F4F022F20D3B4CBBE691652EE7C48243B81701CBDB7CC7D7BF0EE09E154E6FCBF2043D65AF4E9E97B89B5DBAF830D83B9B7F469A6C45A717";

        nStartMasternodePayments = 1403728576; //Wed, 25 Jun 2014 20:36:16 GMT



        /** Zerocoin */

        zerocoinModulus = "25195908475657893494027183240048398571429282126204032027777137836043662020707595556264018525880784"

            "4069182906412495150821892985591491761845028084891200728449926873928072877767359714183472702618963750149718246911"

            "6507761337985909570009733045974880842840179742910064245869181719511874612151517265463228221686998754918242243363"

            "7259085141865462043576798423387184774447920739934236584823824281198163815010674810451660377306056201619676256133"

            "8441436038339044149526344321901146575444541784240209246165157233507787077498171257724679629263863563732899121548"

            "31438167899885040445364023527381951378636564391212010397122822120720357";

        nMaxZerocoinSpendsPerTransaction = 7; // Assume about 20kb each

        nMinZerocoinMintFee = 1 * CENT; //high fee required for zerocoin mints

        nMintRequiredConfirmations = 20; //the maximum amount of confirmations until accumulated in 19

        nRequiredAccumulation = 1;

        nDefaultSecurityLevel = 100; //full security level for accumulators

        nZerocoinHeaderVersion = 4; //Block headers must be this version once zerocoin is active

        nZerocoinRequiredStakeDepth = 200; //The required confirmations for a zdrip to be stakable



        nBudget_Fee_Confirmations = 6; // Number of confirmations for the finalization fee

    }



    const Checkpoints::CCheckpointData& Checkpoints() const

    {

        return data;

    }

};

static CMainParams mainParams;



/**

 * Testnet (v3)

 */

class CTestNetParams : public CMainParams

{

public:

    CTestNetParams()

    {

        networkID = CBaseChainParams::TESTNET;

        strNetworkID = "test";

        pchMessageStart[0] = 0x27;

        pchMessageStart[1] = 0x58;

        pchMessageStart[2] = 0x47;

        pchMessageStart[3] = 0xfc;

        vAlertPubKey = ParseHex("04c195fafde7680d0f8412265ae7c63a97c702116805a5598f4e5149f4333aba83949939875bce49df8250286e72be148c1c873755efc6d640738ab2069a297fd4");

        nDefaultPort = 21463;

        nEnforceBlockUpgradeMajority = 51;

        nRejectBlockOutdatedMajority = 75;

        nToCheckBlockUpgradeMajority = 100;

        nMinerThreads = 0;

        nTargetTimespan = 1 * 60; // DRIP: 1 day

        nTargetSpacing = 1 * 60;  // DRIP: 1 minute

        nLastPOWBlock = 200;

        nMaturity = 15;

        nMasternodeCountDrift = 4;

        nModifierUpdateBlock = 51197; //approx Mon, 17 Apr 2017 04:00:00 GMT

        nMaxMoneyOut = 43199500 * COIN;

        nZerocoinStartHeight = 150;

        nZerocoinStartTime = 1526459600;

        nBlockEnforceSerialRange = 153; //Enforce serial range starting this block

        nBlockRecalculateAccumulators = 999999999; //Trigger a recalculation of accumulators

        nBlockFirstFraudulent = 999999999; //First block that bad serials emerged

        nBlockLastGoodCheckpoint = 999999999; //Last valid accumulator checkpoint

        nBlockEnforceInvalidUTXO = 999999999; //Start enforcing the invalid UTXO's

        nInvalidAmountFiltered = 0; //Amount of invalid coins filtered through exchanges, that should be considered valid

        nBlockZerocoinV2 = 150; //!> The block that zerocoin v2 becomes active

        nEnforceNewSporkKey = 1525982400; //!> Sporks signed after Wednesday, March 21, 2018 4:00:00 AM GMT must use the new spork key

        nRejectOldSporkKey = 1522454400; //!> Reject old spork key after Saturday, March 31, 2018 12:00:00 AM GMT



        //! Modify the testnet genesis block so the timestamp is valid for a later start.

        genesis.nTime = 1526511400;

        genesis.nNonce = 3122;



        hashGenesisBlock = genesis.GetHash();

        assert(hashGenesisBlock == uint256("0x000a9cd524c5d984165a05ac14bc6d6899380dbf39bf5def75df6d4daf8b0511"));



        vFixedSeeds.clear();

        vSeeds.clear();

        vSeeds.push_back(CDNSSeedData("0", "dns0.dripcoin.tech"));

        vSeeds.push_back(CDNSSeedData("1", "dns0.lottereth.com"));



        base58Prefixes[PUBKEY_ADDRESS] = std::vector<unsigned char>(1, 139); // Testnet drip addresses start with 'x' or 'y'

        base58Prefixes[SCRIPT_ADDRESS] = std::vector<unsigned char>(1, 19);  // Testnet drip script addresses start with '8' or '9'

        base58Prefixes[SECRET_KEY] = std::vector<unsigned char>(1, 239);     // Testnet private keys start with '9' or 'c' (Bitcoin defaults)

        // Testnet drip BIP32 pubkeys start with 'DRKV'

        base58Prefixes[EXT_PUBLIC_KEY] = boost::assign::list_of(0x3a)(0x80)(0x61)(0xa0).convert_to_container<std::vector<unsigned char> >();

        // Testnet drip BIP32 prvkeys start with 'DRKP'

        base58Prefixes[EXT_SECRET_KEY] = boost::assign::list_of(0x3a)(0x80)(0x58)(0x37).convert_to_container<std::vector<unsigned char> >();

        // Testnet drip BIP44 coin type is '1' (All coin's testnet default)

        base58Prefixes[EXT_COIN_TYPE] = boost::assign::list_of(0x80)(0x00)(0x00)(0x01).convert_to_container<std::vector<unsigned char> >();



        convertSeed6(vFixedSeeds, pnSeed6_test, ARRAYLEN(pnSeed6_test));



        fMiningRequiresPeers = true;

        fAllowMinDifficultyBlocks = true;

        fDefaultConsistencyChecks = false;

        fRequireStandard = true;

        fMineBlocksOnDemand = false;

        fTestnetToBeDeprecatedFieldRPC = true;



        nPoolMaxTransactions = 2;

        strSporkKeyOld = "036ca7f9740457d58822becf6a1c72fb8f1ec3b68f9186b381ff873d2c1013d61d";

        strSporkKey = "036ca7f9740457d58822becf6a1c72fb8f1ec3b68f9186b381ff873d2c1013d61d";

        strObfuscationPoolDummyAddress = "DEvyGnCULfpLfcsyuoLBXjXA5BxpvewTiV";

        nStartMasternodePayments = 1420837558; //Fri, 09 Jan 2015 21:05:58 GMT

        nBudget_Fee_Confirmations = 3; // Number of confirmations for the finalization fee. We have to make this very short

                                       // here because we only have a 8 block finalization window on testnet

    }

    const Checkpoints::CCheckpointData& Checkpoints() const

    {

        return dataTestnet;

    }

};

static CTestNetParams testNetParams;



/**

 * Regression test

 */

class CRegTestParams : public CTestNetParams

{

public:

    CRegTestParams()

    {

        networkID = CBaseChainParams::REGTEST;

        strNetworkID = "regtest";

        strNetworkID = "regtest";

        pchMessageStart[0] = 0xf2;

        pchMessageStart[1] = 0xbe;

        pchMessageStart[2] = 0x6f;

        pchMessageStart[3] = 0xfd;

        nSubsidyHalvingInterval = 150;

        nEnforceBlockUpgradeMajority = 750;

        nRejectBlockOutdatedMajority = 950;

        nToCheckBlockUpgradeMajority = 1000;

        nMinerThreads = 1;

        nTargetTimespan = 24 * 60 * 60; // DRIP: 1 day

        nTargetSpacing = 1 * 60;        // DRIP: 1 minutes

        bnProofOfWorkLimit = ~uint256(0) >> 1;

        genesis.nTime = 1526511800;

        genesis.nBits = 0x207fffff;

        genesis.nNonce = 0;


        hashGenesisBlock = genesis.GetHash();

        nDefaultPort = 21465;

        assert(hashGenesisBlock == uint256("0x459439a5882d4ac338877907b79cce3d1e077bbe20f1d004eee4e44fc053135d"));



        vFixedSeeds.clear(); //! Testnet mode doesn't have any fixed seeds.

        vSeeds.clear();      //! Testnet mode doesn't have any DNS seeds.



        fMiningRequiresPeers = false;

        fAllowMinDifficultyBlocks = true;

        fDefaultConsistencyChecks = true;

        fRequireStandard = false;

        fMineBlocksOnDemand = true;

        fTestnetToBeDeprecatedFieldRPC = false;

    }

    const Checkpoints::CCheckpointData& Checkpoints() const

    {

        return dataRegtest;

    }

};

static CRegTestParams regTestParams;



/**

 * Unit test

 */

class CUnitTestParams : public CMainParams, public CModifiableParams

{

public:

    CUnitTestParams()

    {

        networkID = CBaseChainParams::UNITTEST;

        strNetworkID = "unittest";

        nDefaultPort = 21467;

        vFixedSeeds.clear(); //! Unit test mode doesn't have any fixed seeds.

        vSeeds.clear();      //! Unit test mode doesn't have any DNS seeds.



        fMiningRequiresPeers = false;

        fDefaultConsistencyChecks = true;

        fAllowMinDifficultyBlocks = false;

        fMineBlocksOnDemand = true;

    }



    const Checkpoints::CCheckpointData& Checkpoints() const

    {

        // UnitTest share the same checkpoints as MAIN

        return data;

    }



    //! Published setters to allow changing values in unit test cases

    virtual void setSubsidyHalvingInterval(int anSubsidyHalvingInterval) { nSubsidyHalvingInterval = anSubsidyHalvingInterval; }

    virtual void setEnforceBlockUpgradeMajority(int anEnforceBlockUpgradeMajority) { nEnforceBlockUpgradeMajority = anEnforceBlockUpgradeMajority; }

    virtual void setRejectBlockOutdatedMajority(int anRejectBlockOutdatedMajority) { nRejectBlockOutdatedMajority = anRejectBlockOutdatedMajority; }

    virtual void setToCheckBlockUpgradeMajority(int anToCheckBlockUpgradeMajority) { nToCheckBlockUpgradeMajority = anToCheckBlockUpgradeMajority; }

    virtual void setDefaultConsistencyChecks(bool afDefaultConsistencyChecks) { fDefaultConsistencyChecks = afDefaultConsistencyChecks; }

    virtual void setAllowMinDifficultyBlocks(bool afAllowMinDifficultyBlocks) { fAllowMinDifficultyBlocks = afAllowMinDifficultyBlocks; }

    virtual void setSkipProofOfWorkCheck(bool afSkipProofOfWorkCheck) { fSkipProofOfWorkCheck = afSkipProofOfWorkCheck; }

};

static CUnitTestParams unitTestParams;





static CChainParams* pCurrentParams = 0;



CModifiableParams* ModifiableParams()

{

    assert(pCurrentParams);

    assert(pCurrentParams == &unitTestParams);

    return (CModifiableParams*)&unitTestParams;

}



const CChainParams& Params()

{

    assert(pCurrentParams);

    return *pCurrentParams;

}



CChainParams& Params(CBaseChainParams::Network network)

{

    switch (network) {

    case CBaseChainParams::MAIN:

        return mainParams;

    case CBaseChainParams::TESTNET:

        return testNetParams;

    case CBaseChainParams::REGTEST:

        return regTestParams;

    case CBaseChainParams::UNITTEST:

        return unitTestParams;

    default:

        assert(false && "Unimplemented network");

        return mainParams;

    }

}



void SelectParams(CBaseChainParams::Network network)

{

    SelectBaseParams(network);

    pCurrentParams = &Params(network);

}



bool SelectParamsFromCommandLine()

{

    CBaseChainParams::Network network = NetworkIdFromCommandLine();

    if (network == CBaseChainParams::MAX_NETWORK_TYPES)

        return false;



    SelectParams(network);

    return true;

}

