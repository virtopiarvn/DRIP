DRIP Core integration/staging repository
=====================================

[![Build Status](https://travis-ci.org/DRIP-Project/DRIP.svg?branch=master)](https://travis-ci.org/DRIP-Project/DRIP) [![GitHub 
version](https://badge.fury.io/gh/DRIP-Project%2FDRIP.svg)](https://badge.fury.io/gh/DRIP-Project%2FDRIP) 

DRIP is an open source crypto-currency focused on fast private transactions with low transaction fees & environmental footprint.  It utilizes a custom Proof of Stake protocol for securing its network and uses an innovative variable seesaw reward mechanism that dynamically balances 90% of its block reward size between masternodes and staking nodes and 10% dedicated for budget proposals. A further reward is assigned to the last person to whom the PoS winner of each block has sent coins to. The purpose of this is to incentivize merchants to accept DRIP - as acceptance of DRIP will result in being paid for their product or service AND getting an opportunity for further awards. Should the miner of a block not have sent DRIP before, i.e. they have only set up a wallet and received money, the reward that would normally go to the merchant will go to a DRIP address reserved for charity. Coins in this address will be sold off at regular intervals and the proceeds donated to various charities.  The goal of DRIP is to achieve a decentralized sustainable crypto currency with near instant full-time private transactions, fair governance and community intelligence. 
- Anonymized transactions using the [_Zerocoin Protocol_](http://www.drip.tech/zdrip). 
- Fast transactions featuring guaranteed zero confirmation transactions, we call it _SwiftX_. 
- Decentralized blockchain voting utilizing Masternode technology to form a DAO. The blockchain will distribute monthly treasury funds based on successful proposals submitted by the community and voted on by the DAO. 

More information at [dripcoin.tech](http://www.dripcoin.tech) Visit our ANN thread at [BitcoinTalk](http://www.bitcointalk.org/index.php?topic=1262920)

### Coin Specs
<table> 
<tr><td>Algo</td><td>N/A</td></tr> 
  <tr><td>Block Time</td><td>60 Seconds</td></tr> 
  <tr><td>Difficulty Retargeting</td><td>Every Block</td></tr> 
  <tr><td>Max Coin Supply (PoS Phase)</td><td>Infinite</td></tr> 
  <tr><td>Premine</td><td>290,000 DRIP*</td></tr> 
</table> 

*40,000 DRIP will be used to run four developer masternodes, resulting in a stable network. The other 250,000 coins will be distributed to the community using the various approaches detailed in our whitepaper and social media groups. These tokens will not be staked or used for masternodes during the disribution phase and any undistributed tokens will be burned on the day we list on an exchange.

### Reward Distribution

<table> 
  <th colspan=4>Genesis Block</th> 
  <tr><th>Block Height</th><th>Reward Amount</th><th>Notes</th></tr> 
  <tr><td>1</td><td>290,000 DRIP</td><td>Primarily for distribution to the community</td></tr> 
</table>

### PoW Rewards Breakdown

<table> 
  <th>Block Height</th><th>Team</th></th> 
  <tr><td>2-120</td><td>2 DRIP</td></tr> 
</table>

### PoS Rewards Breakdown

<table> 
  <th>Phase</th><th>Block Height</th><th>Reward</th><th>Masternodes & Stakers</th><th>Merchant/Charity</th><th>Budget</th> 
  <tr><td>Phase 1</td><td>121-43200</td><td>11 DRIP</td><td>10 DRIP (all staker)</td><td>1 DRIP</td><td>10%</td></tr> 
  <tr><td>Phase 2</td><td>43201-129600</td><td>151 DRIP</td><td>150 DRIP seesaw</td><td>1 DRIP</td><td>10%</td></tr> 
  <tr><td>Phase 3</td><td>129601-216000</td><td>131 DRIP</td><td>130 DRIP seesaw</td><td>1 DRIP</td><td>10%</td></tr> 
  <tr><td>Phase 4</td><td>216001-302400</td><td>111 DRIP</td><td>110 DRIP seesaw</td><td>1 DRIP</td><td>10%</td></tr> 
  <tr><td>Phase 5</td><td>302401-388800</td><td>91 DRIP</td><td>90 DRIP *</td><td>1 DRIP</td><td>10%</td></tr> 
  <tr><td>Phase 6</td><td>388801-475200</td><td>56 DRIP</td><td>55 DRIP *</td><td>1 DRIP</td><td>10%</td></tr> 
  <tr><td>Phase 7</td><td>475201-561600</td><td>46 DRIP</td><td>45 DRIP *</td><td>1 DRIP</td><td>10%</td></tr> 
  <tr><td>Phase 8</td><td>561601-648000</td><td>26 DRIP</td><td>25 DRIP *</td><td>1 DRIP</td><td>10%</td></tr> 
  <tr><td>Phase 9</td><td>648001-734400</td><td>11 DRIP</td><td>10 DRIP *</td><td>1 DRIP</td><td>10%</td></tr> 
  <tr><td>Phase X</td><td>734401-Infinite</td><td>5.5 DRIP</td><td>5 DRIP *</td><td>0.5 DRIP</td><td>10%</td></tr> 
</table>

*After block 302400, the reward split between masternode and staker will move from the seesaw algorithm to a fixed reward based upon whether the staker is staking DRIP or zDRIP. If the staker is staking zDRIP, they get 60% of the reward. Otherwise, they get 40%. The remainder goes to the masternode.
