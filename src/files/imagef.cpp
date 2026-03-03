#include "files/imagef.h"


std::string imagef::get_res()
{
    return res;
}

std::string imagef::get_format()
{
    return format;
}

bool imagef::check_arg_for_del(dict& arg)
{
    if (arg.arg_ == "filename")
    {
        return check_by_flnm(arg);
    } else if (arg.arg_ == "date")
    {
        return check_by_date(arg);
    } else if (arg.arg_ == "type")
    {
        return check_by_type(arg);
    } else if (arg.arg_ == "resolution")
    {
        return check_by_res(arg);
    } else if (arg.arg_ == "format")
    {
        return check_by_format(arg);
    } else
        return false;
}

bool imagef::check_by_flnm(dict& arg)
{
    return (arg.val_ == this->filename)? true : false;
}

bool imagef::check_by_date(dict& arg)
{
    return (arg.val_ == this->date)? true : false;
}

bool imagef::check_by_type(dict& arg)
{
    return (arg.val_ == "IMAGE")? true : false;
}

bool imagef::check_by_res(dict& arg)
{
    pairVals pr1, pr2;
    utils::parser_resolution(pr1, this->res);
    utils::parser_resolution(pr2, arg.val_);
    int val1 = utils::mult(pr1.first, pr1.second);
    int val2 = utils::mult(pr2.first, pr2.second);

    if (((arg.oprt_ == '=')&&(val1 == val2))||
        ((arg.oprt_ == '<')&&(val1 < val2))||
        ((arg.oprt_ == '>')&&(val1 > val2)))
        return true;
    else
        throw std::invalid_argument("invalid operator");
        
} //<>=

bool imagef::check_by_format(dict& arg)
{
    return (arg.val_ == this->format)? true : false;
}