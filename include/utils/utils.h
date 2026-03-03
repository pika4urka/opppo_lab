#ifndef _UTILS_
#define _UTILS_

#include <stdexcept>
#include <string>

struct dict
{
    std::string arg_;
    std::string val_;
    char oprt_;
};

struct pairVals
{
    std::string first;
    std::string second;
};

namespace utils
{

    void check_num(const char* str);
    //checking for a numbers

    void parser_resolution(pairVals& pr, std::string& str);

    void parser_duration(pairVals& pr, std::string& str);

    int mult(std::string& str1, std::string& str2);

    void check_str(const char* str);
    //checking for a string

    bool check_less(const char* f_num, const char* s_num);

    bool check_more(const char* f_num, const char* s_num);

    bool check_equal(const char* f_num, const char* s_num);

};

#endif //_UTILS_