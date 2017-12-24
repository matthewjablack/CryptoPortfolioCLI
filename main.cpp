#include <iostream>
#include <string>
#include <curl/curl.h>
#include <cassert>
#include <map>
#include <stdlib.h>
#include <stdio.h>
#include "json.hpp"

using namespace std;
using json = nlohmann::json;

static size_t writeCallback(void *contents, size_t size, size_t nmemb, void *userp) {
  ((std::string*)userp)->append((char*)contents, size * nmemb);
  return size * nmemb;
}

string curl(string url) {
  CURL *curl;
  CURLcode res;
  std::string readBuffer;

  curl = curl_easy_init();
  if (curl) {
    curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, writeCallback);
    curl_easy_setopt(curl, CURLOPT_WRITEDATA, &readBuffer);
    res = curl_easy_perform(curl);
    curl_easy_cleanup(curl);

  }
  return readBuffer;
}


int main(int argc, char *argv[]) {
  try {
    if (argc%2 != 0) throw 1;

    std::map<std::string, double> wallet;
    double total = 0.0;
    auto coinmarketcap = json::parse(curl("https://api.coinmarketcap.com/v1/ticker/?limit=100"));
    auto fixer = json::parse(curl("https://api.fixer.io/latest?base=USD"));
    string currency = string(argv[1]);
    double usd_to_currency = 0.0;

    for (int i = 2; i < argc; i += 2) wallet[string(argv[i])] = strtod(argv[i + 1], NULL);

    if (currency != "USD") usd_to_currency = fixer["rates"][currency];

    for (int i = 0; i < 100; i++) {
      string price_usd = coinmarketcap[i]["price_usd"];
      wallet[coinmarketcap[i]["symbol"]] *= stod(price_usd);
      if (currency != "USD") wallet[coinmarketcap[i]["symbol"]] *= usd_to_currency;
      total += wallet[coinmarketcap[i]["symbol"]];
      if (wallet[coinmarketcap[i]["symbol"]] != 0) {
        cout << coinmarketcap[i]["symbol"].get<string>() << ": " << wallet[coinmarketcap[i]["symbol"]];
        cout << " " << currency << endl;
      }
    }

    cout << "Total: " << total << " " << currency << endl;
  } catch(...) {
    cerr << "wallet: illegal option" << endl;
    cerr << "usage: wallet [currency...USD, CAD] ";
    cerr << "[coin...BTC, ETH] [amount...] [coin...BTC, ETH] [amount...]" << endl;
  }
}
