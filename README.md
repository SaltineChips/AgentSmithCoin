AgentSmithCoin [ASC] 2020 integration/staging tree
===============================================

Website
Fan made (This blockchain): https://agentsmithcoin.xyz/
China Uncensored: http://www.chinauncensored.tv/



Youtube (OFFICIAL LINK)
America Uncovered: https://www.youtube.com/channel/UC_7vFlErTHxVD-IFNB-BFCg
China Uncensored: https://www.youtube.com/channel/UCgFP46yVT-GG4o1TgXn-04Q

What is the AgentSmithCoin [ASC] Blockchain?
------------------------------------
*TODO: Update documentation regarding implemented tech as this section is out of date and much progress and upgrades have been made to mentioned sections...*

### Overview
AgentSmithCoin is a blockchain project with the goal of offering Chris Chappel something to laugh about! We hope that you enjoy this silly thing!

### Blockchain Technology
Blockchain technology has the capabilities to change a variety of things in the world and can also be the backbone of a new internet. One place that blockchain technology has not had an impact on yet is website on the blockchain. However, AgentSmithCoin is a fan made blockchain to support the awesome folks at America Uncovered/China Uncensored.

### Custom Difficulty Retarget Algorithm “VRX”
VRX is designed from the ground up to integrate properly with the Velocity parameter enforcement system to ensure users no longer receive orphan blocks.

### Velocity Block Constraint System
Ensuring AgentSmithCoin stays as secure and robust as possible the CryptoCoderz team have implemented what's known as the Velocity block constraint system. This system acts as third and final check for both mined and peer-accepted blocks ensuring that all parameters are strictly enforced.

### HMQ1725 Algorithm
We use an custom internal algorithm known as HMQ1725 to sign blocks and conduct other functions, it takes its name from how it was designed: Highly-Modified-Quark 17-Algorithms 25-Scientific-Rounds

Specifications and General info
------------------
AgentSmithCoin uses:

		Boost1.73,
		OR Boost1.58,
		OpenSSL1.02u,
		OR OpenSSL1.1x,
		Berkeley DB 6.2.32,
		Qt5.14 to compile

General Info:


		Block Spacing: 5 Minutes
		Stake Minimum Age: 90 Confirmations (PoS-v3) | 2 Hours (PoS-v2)
		Port: 22012
		RPC Port: 12351

Compiling AgentSmithCoin daemon on Ubunutu 18.04 LTS Bionic
---------------------------
### Note: guide should be compatible with other Ubuntu versions from 14.04+

### Become poweruser
```
sudo -i
```

### Dependencies install
```
cd ~; sudo apt-get install ntp git build-essential libssl-dev libdb-dev libdb++-dev libboost-all-dev libqrencode-dev libcurl4-openssl-dev curl libzip-dev; apt-get update; apt-get upgrade; apt-get install git make automake build-essential libboost-all-dev; apt-get install yasm binutils libcurl4-openssl-dev openssl libssl-dev; sudo apt-get install libgmp-dev; cd ~;
```

### Dependencies build and link
```
cd ~; wget http://download.oracle.com/berkeley-db/db-6.2.32.NC.tar.gz; tar zxf db-6.2.32.NC.tar.gz; cd db-6.2.32.NC/build_unix; ../dist/configure --enable-cxx; make; sudo make install; sudo ln -s /usr/local/BerkeleyDB.6.2/lib/libdb-6.2.so /usr/lib/libdb-6.2.so; sudo ln -s /usr/local/BerkeleyDB.6.2/lib/libdb_cxx-6.2.so /usr/lib/libdb_cxx-6.2.so; export BDB_INCLUDE_PATH="/usr/local/BerkeleyDB.6.2/include"; export BDB_LIB_PATH="/usr/local/BerkeleyDB.6.2/lib"; cd ~;
```

### Personal upload EXAMPLE
```
cd ~; sudo cp -r /home/ftpuser/ftp/files/ASC-clean/. ~/AgentSmithCoin
```

### GitHub pull RECOMMENDED
```
cd ~; git clone https://github.com/SaltineChips/AgentSmithCoin
```

### Build AgentSmithCoin daemon
```
cd ~; cd ~/AgentSmithCoin/src; chmod a+x obj; chmod a+x leveldb/build_detect_platform; chmod a+x leveldb; chmod a+x ~/AgentSmithCoin/src; chmod a+x ~/AgentSmithCoin; make -f ~/AgentSmithCoin/src/makefile/makefile.unix USE_UPNP=-; cd ~; cp ~/AgentSmithCoin/src/AgentSmithCoind /usr/local/bin;
```

### Create config file for daemon
```
cd ~; sudo ufw allow 22012/tcp; sudo ufw allow 12351/tcp; sudo mkdir ~/.ASC; cat << "CONFIG" >> ~/.ASC/AgentSmithCoin.conf
listen=1
server=1
daemon=1
testnet=0
rpcuser=agentsmithcoinuser
rpcpassword=SomeCrazyVeryVerySecurePasswordHere
rpcport=12351
port=22012
rpcconnect=127.0.0.1
rpcallowip=127.0.0.1


CONFIG
chmod 700 ~/.ASC/AgentSmithCoin.conf; chmod 700 ~/.ASC; ls -la ~/.ASC
```

### Run AgentSmithCoin daemon
```
cd ~; AgentSmithCoind; AgentSmithCoind getinfo
```

### Troubleshooting
### for basic troubleshooting run the following commands when compiling:
### this is for minupnpc errors compiling
```
make clean -f makefile.unix USE_UPNP=-
make -f makefile.unix USE_UPNP=-
```

License
-------

AgentSmithCoin [ASC] is released under the terms of the MIT license. See [COPYING](COPYING) for more
information or see https://opensource.org/licenses/MIT.

Development Process
-------------------

The `master` branch is regularly built and tested, but is not guaranteed to be
completely stable. [Tags](https://github.com/SaltineChips/AgentSmithCoin/tags) are created
regularly to indicate new official, stable release versions of AgentSmithCoin [ASC].

The contribution workflow is described in [CONTRIBUTING.md](CONTRIBUTING.md).

The developer [mailing list](https://lists.linuxfoundation.org/mailman/listinfo/bitcoin-dev)
should be used to discuss complicated or controversial changes before working
on a patch set.

Developer Discord can be found at https://discord.gg/cn3AfPS .

Testing
-------

Testing and code review is the bottleneck for development; we get more pull
requests than we can review and test on short notice. Please be patient and help out by testing
other people's pull requests, and remember this is a security-critical project where any mistake might cost people
lots of money.

### Automated Testing

Developers are strongly encouraged to write [unit tests](/doc/unit-tests.md) for new code, and to
submit new unit tests for old code. Unit tests can be compiled and run
(assuming they weren't disabled in configure) with: `make check`

There are also [regression and integration tests](/qa) of the RPC interface, written
in Python, that are run automatically on the build server.

### Manual Quality Assurance (QA) Testing

Changes should be tested by somebody other than the developer who wrote the
code. This is especially important for large or high-risk changes. It is useful
to add a test plan to the pull request description if testing the changes is
not straightforward.
