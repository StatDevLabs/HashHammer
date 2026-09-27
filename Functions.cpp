#include "Functions.h"

#define CRYPTOPP_ENABLE_NAMESPACE_WEAK 1
#include <cryptopp/cryptlib.h>
#include <cryptopp/md5.h>
#include <cryptopp/hex.h>
#include <cryptopp/filters.h>
#include <cryptopp/sha.h>
#include <cryptopp/sha3.h>
#include <cryptopp/blake2.h>





using namespace CryptoPP;
using namespace std;

string Hash_functions::md5_of(const string &msg) {
    Weak::MD5 hash;
    string digest;

    StringSource(msg, true,
        new HashFilter(
            hash,
            new HexEncoder(
                new StringSink(digest),
                false // lowercase
            )
        )
    );
    return digest;
}


string Hash_functions::sha1_of(const string &msg){

    CryptoPP::SHA1 hash;
    string digest;

    CryptoPP::StringSource(msg, true,
        new CryptoPP::HashFilter(
            hash,
            new CryptoPP::HexEncoder(
                new CryptoPP::StringSink(digest),
                false
            )
        )
    );

    return digest;

}

string Hash_functions::sha256_of(const string &msg){
    CryptoPP::SHA256 hash;
    string digest;

    CryptoPP::StringSource(msg, true,
        new CryptoPP::HashFilter(
            hash,
            new CryptoPP::HexEncoder(
                new CryptoPP::StringSink(digest),
                false
            )
        )
    );

    return digest;
}