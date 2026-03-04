#include "utils/utils.h"

void utils::check_num(const char* str)
{
    int i = 0; //counter
    while(*(str + i) != '\0')
    {
        if (((int)*(str + i) < 48) || ((int)*(str + i) > 57))
        {
            //printf("\nstr[%d](ascii): %d\nstr[%d]: %c\n", i, (int)*(str + i), i, *(str + i));
            throw std::invalid_argument("invalid num");
        }
        ++i;
    }
}

// void utils::check_str(const char* str)
// {
//     int i = 0; //counter
//     while(*(str + i) != '\0')
//     {
//         if (((int)*(str + i) >= 48) && ((int)*(str + i) <= 57))
//             throw std::invalid_argument("invalid str");
//     }
// }

bool utils::check_less(const char* f_num, const char* s_num)
{
    int first = std::atoi(f_num);
    int second = std::atoi(s_num);
    
    if (first < second)
        return true;
    else
        return false;
}

bool utils::check_more(const char* f_num, const char* s_num)
{
    int first = std::atoi(f_num);
    int second = std::atoi(s_num);
    
    if (first > second)
        return true;
    else
        return false;
}

bool utils::check_equal(const char* f_num, const char* s_num)
{
    int first = std::atoi(f_num);
    int second = std::atoi(s_num);
    
    if (first == second)
        return true;
    else
        return false;
}

void utils::parser_resolution(pairVals& pr, const std::string& str)
{
    int i = 0;
    while(str.at(i++) != 'x')
        if ((i == str.size() - 1)||(str.at(0) == 0))
            throw std::invalid_argument("invalid resolution");

    pr.first = str.substr(0, i - 1);
    pr.second = str.substr(i);
}

// void utils::parser_duration(pairVals& pr, std::string& str)
// {
//     int i = 0;
//     while(str.at(i++) != ':') {}
//     pr.first = str.substr(0, i - 1);
//     pr.second = str.substr(i);
// }

int utils::mult(const std::string& str1, const std::string& str2)
{
    int first = std::atoi(str1.c_str());
    int second = std::atoi(str2.c_str());
    return first * second;
}