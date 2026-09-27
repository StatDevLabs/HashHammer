#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <string>

class Hash_functions {
public:
    // It's good practice to make this static if it doesn't use instance-specific data.
    static std::string md5_of(const std::string &msg);
    static std::string sha1_of(const std::string &msg);
    static std::string sha256_of(const std::string &msg);
    static std::string bcrypt_of(const std::string &msg);
    static std::string NTLM_of(const std::string &msg);
    static std::string scrypt_of(const std::string &msg);
    

};


#endif //FUNCTIONS_H