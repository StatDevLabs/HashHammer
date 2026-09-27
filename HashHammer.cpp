#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
#include <iomanip>
#include <list>
#include <algorithm>
#include <cctype>
#include "Functions.h"


#define CRYPTOPP_ENABLE_NAMESPACE_WEAK 1
#include <cryptopp/cryptlib.h>
#include <cryptopp/md5.h>
#include <cryptopp/hex.h>
#include <cryptopp/filters.h>
#include <cryptopp/sha.h>




using namespace CryptoPP;
using namespace std;


// checks for HASHABNK.txt




void check() {

    string filename = "HASHBANK.txt";
    ifstream file(filename);
    
    if (file.good()) {

        cout << "[EXECUTING PROGRAM] HASHBANK.txt found" << endl;
        cout << "NEW COMPILED" << endl;
        cout << endl;
        cout << endl;

    } else {

        exit(0);

    }  
}


// Between these comments is where the hashes will be cracked
string md5_hash(const string input, char Ver) {


    cout << "MD5 Hash is Chosen, Cracking now ..." << endl;
    ifstream file("HASHBANK.txt");
    

    if (!file) {
        cout << "ERROR: could not open HASHBANK.txt" << endl;
        return "";
    }

    if (Ver == 'y') {

        for (string line; getline(file, line); ) {
            if (line.empty()) continue;

            string line_From_list = Hash_functions::md5_of(line);

            cout << "Processing line: " << line_From_list << '\n';

            if (line_From_list == input) {
                cout << endl;
                cout << endl;
                cout << "Hash Hammered! The unhashed string is: " << line << endl;
                cout << endl;
                cout << input << " ---> " << line << endl;
                return line;
            }
        }

    } else {

        for (string line; getline(file, line); ) {
            if (line.empty()) continue;

            string line_From_list = Hash_functions::md5_of(line);

            if (line_From_list == input) {
                cout << endl;
                cout << endl;
                cout << "Hash Hammered! The unhashed string is: " << line << endl;
                cout << endl;
                cout << input << " ---> " << line << endl;
                return line;
            }
        }
    }

    cout << "No matching hash found in HASHBANK.txt (MD5)" << endl;
    return "";
}

string SHA1_hash(const string input, char Ver) {

    string line;
    cout << "SHA1 Hash is Chosen, Cracking now ..." << endl;
    ifstream file("HASHBANK.txt");

    if (!file) {
        cout << "ERROR: could not open HASHBANK.txt" << endl;
        return "";
    }

    if (Ver == 'y') {

        for (string line; getline(file, line); ) {
            if (line.empty()) continue;

            string compare = Hash_functions::sha1_of(line);

            cout << "Processing line: " << compare << '\n';

            if (compare == input) {

                cout << endl;
                cout << endl;
                cout << "Hash Hammered! The unhashed string is: " << line << endl;
                cout << endl;
                cout << input << " ---> " << line << endl;
                return line;
            }
        }

    } else {

        for (string line; getline(file, line); ) {
            if (line.empty()) continue;
            
            string compare = Hash_functions::sha1_of(line);

            if (compare == input) {
                cout << endl;
                cout << endl;
                cout << "Hash Hammered! The unhashed string is: " << line << endl;
                cout << endl;
                cout << input << " ---> " << line << endl;
                return line;
            }
        }
    }

    cout << "No matching hash found in HASHBANK.txt (SHA1)" << endl;
    return "";
}

string SHA256_hash(const string input, char Ver) {

    string line;
    cout << "SHA256 Hash is Chosen, Cracking now ..." << endl;
    ifstream file("HASHBANK.txt");

    if (!file) {
        cout << "ERROR: could not open HASHBANK.txt" << endl;
        return "";
    }

    if (Ver == 'y') {

        for (string line; getline(file, line); ) {
            if (line.empty()) continue;

            string compare = Hash_functions::sha256_of(line);

            cout << "Processing line: " << compare << '\n';

            if (compare == input) {

                cout << endl;
                cout << endl;
                cout << "Hash Hammered! The unhashed string is: " << line << endl;
                cout << endl;
                cout << input << " ---> " << line << endl;
                return line;
            }
        }

    } else {

        for (string line; getline(file, line); ) {
            if (line.empty()) continue;

            string compare = Hash_functions::sha256_of(line);
            if (compare == input) {
                cout << endl;
                cout << endl;
                cout << "Hash Hammered! The unhashed string is: " << line << endl;
                cout << endl;
                cout << input << " ---> " << line << endl;
                return line;
            }
        }
    }

    cout << "No matching hash found in HASHBANK.txt (SHA1)" << endl;
    return "";
}



//Above this comments is the code where the hash is cracked

string CRACK(string Target, int Type, char Ver) {
    string word;
    string filename = "HASHBANK.txt";
    ifstream file(filename);

    // MD5 = 0
    // SHA1 = 1
    // SHA256 = 2
    // bycrypt = 3
    // NTLM = 4
    // scrypt = 5

    switch (Type) {
    
        case 0:
            cout << "MD5 selected" << endl;
            return md5_hash(Target, Ver);

        case 1:
            cout << "SHA1 selected" << endl;
            return SHA1_hash(Target, Ver);

        case 2:
            cout << "SHA256 selected" << endl;
            return SHA256_hash(Target, Ver);

        default:
            cout << "CHOICE INVALID" << endl;
            return "";
    }
}

list<int> HashTypeAvaliable = {0,1,2,71};

int main() {
 
    bool Switch = true;
    string UserHash;
    int HashType;
    char Verbose;
    check();

    cout << R"(
  _    _           _       _    _                                      
 | |  | |         | |     | |  | |                                     
 | |__| | __ _ ___| |__   | |__| | __ _ _ __ ___  _ __ ___   ___ _ __  
 |  __  |/ _` / __| '_ \  |  __  |/ _` | '_ ` _ \| '_ ` _ \ / _ \ '__| 
 | |  | | (_| \__ \ | | | | |  | | (_| | | | | | | | | | | |  __/ |    
 |_|  |_|\__,_|___/_| |_| |_|  |_|\__,_|_| |_| |_|_| |_| |_|\___|_|    
                                                                       
                                                                       
)" << endl;


    cout << endl;
    cout << endl;
    cout << endl;

    cout << "Insert Hash Here --> ";
    cin >> UserHash;

    while (Switch) {

        cout << endl;
        cout << endl;
        cout << "Insert Hash Type Here (type 71 for choices) --> ";
        cin >> HashType;

        if (HashType == 71) {
            cout << "Choices Below" << endl;
            cout << "0 --> MD5" << endl;
            cout << "1 --> SHA1" << endl;
            cout << "2 --> SHA256" << endl;
            cout << endl;
            cout << endl;
            continue;
        }

        auto it = find(HashTypeAvaliable.begin(), HashTypeAvaliable.end(), HashType);
        if (it == HashTypeAvaliable.end()) {
            cout << "INVALID HASH TYPE" << endl;
            HashType = 0;
            continue;
        }

        cout << endl;
        cout << endl;

        cout << "Hash is --> " << UserHash << endl;
        cout << "User Hash inputed --> " << HashType << endl;
        cout << endl;
        cout << endl;

        while (Switch) {

            cout << "Verbose Mode (y/n) --> ";
            cin >> Verbose;
            Verbose = tolower(Verbose);

            if (Verbose == 'y') {

                CRACK(UserHash, HashType, Verbose);

            } else if (Verbose == 'n') {

                CRACK(UserHash, HashType, Verbose);

            } else {

                cout << "INVALID INPUT, choose" << endl;
                cout << "y ---> yes" << endl;
                cout << "n ---> no" << endl;
                Verbose = '#';
                continue;
            }

            Switch = false;
        }
    }

    return 0;
}