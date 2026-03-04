#include "files/videof.h"


const std::string& videof::get_res() const
{
    return res;
}

const std::string& videof::get_frame_rate() const
{
    return fr_rt;
}

bool videof::check_arg_for_del(dict& arg)
{
    if (arg.arg_ == "filename")
    {
        return check_by_name(arg);
    } else if (arg.arg_ == "date")
    {
        return check_by_date(arg);
    } else if (arg.arg_ == "type")
    {
        return check_by_type(arg);
    } else if (arg.arg_ == "resolution")
    {
        return check_by_res(arg);
    } else if (arg.arg_ == "frame_rate")
    {
        return check_by_fr_rt(arg);
    } else
        return false;
}

bool videof::check_by_name(const dict& arg)
{
    return (this->filename == arg.val_)? true : false;
}

bool videof::check_by_date(const dict& arg)
{
    return (this->date == arg.val_)? true : false;
}

bool videof::check_by_type(const dict& arg)
{
    return (arg.val_ == "VIDEO")? true : false;
}

bool videof::check_by_res(const dict& arg)
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

bool videof::check_by_fr_rt(const dict& arg)
{
    // printf("\narg.val: %s\n", arg.val_.c_str());
    utils::check_num(arg.val_.c_str());
    if (arg.oprt_ == '=')
        return utils::check_equal(this->fr_rt.c_str(), arg.val_.c_str());
    else if (arg.oprt_ == '<')
        return utils::check_less(this->fr_rt.c_str(), arg.val_.c_str());
    else if (arg.oprt_ == '>')
        return utils::check_more(this->fr_rt.c_str(), arg.val_.c_str());
    else
        throw std::invalid_argument("invalid operator");
        
} //<>=
