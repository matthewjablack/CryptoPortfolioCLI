# Crypto Portfolio Cli

Crypto Portfolio Cli is a command line interface written in C++ that allows users to input their current crypto portfolio and display balance in currency of choice. 

[![GitHub stars](https://img.shields.io/github/stars/mattblackdesign/crypto-portfolio-cli.svg?style=social&label=Stars)](https://github.com/mattblackdesign/crypto-portfolio-cli)
[![GitHub code size in bytes](https://img.shields.io/github/size/mattblackdesign/crypto-portfolio-cli/main.cpp.svg)](https://raw.githubusercontent.com/mattblackdesign/crypto-portfolio-cli/master/main.cpp)
[![license](https://img.shields.io/github/license/mattblackdesign/crypto-portfolio-cli.svg)](https://github.com/mattblackdesign/crypto-portfolio-cli)

![screenshot](https://github.com/mattblackdesign/crypto-portfolio-cli/blob/master/screenshot.png)

Cryptocurrency prices are sourced from [coinmarketcap api](https://coinmarketcap.com/api/)

Exchange rates are sourced from [fixer api](https://api.fixer.io)

## Installation

Run the **following commmand** in your terminal:

```
git clone https://github.com/mattBlackDesign/crypto-portfolio-cli.git && cd crypto-portfolio-cli && make && mv portfolio /usr/local/bin && chmod +x /usr/local/bin/portfolio
```

## Usage

Enter your currency and the coins in your portfolio. 
```
portfolio USD BTC 1.1 ETH 2.3 LTC 4.5
```

The following currencies are supported 💰
```USD,CAD,EUR,AUD,BGN,BRL,CHF,CNY,CZK,DKK,GBP,HKD,HRK,HUF,IDR,ILS,INR,JPY,KRW,MXN,MYR,NOK,NZD,PHP,PLN,RON,RUB,SEK,SGB,THB,TRY,ZAR```


**Crypto Portfolio** supports the first 100 coins on [coinmarketcap](https://coinmarketcap.com)


## Development

```
git clone https://github.com/mattblackdesign/crypto-portfolio-cli.git
cd crypto-portfolio-cli
vim main.cpp
```

## License

MIT License