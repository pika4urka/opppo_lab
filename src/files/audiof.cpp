#include "files/audiof.h"


const std::string& audiof::get_bitrate() const
{
    return bitrate;
}

const std::string& audiof::get_duration() const
{
    return duration;
}

bool audiof::check_arg_for_del(dict& arg)
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
    } else if (arg.arg_ == "bitrate")
    {
        return check_by_bitr(arg);
    } else if (arg.arg_ == "duration")
    {
        return check_by_dur(arg);
    } else
        return false;
}

bool audiof::check_by_name(const dict& arg)
{
    return (arg.val_ == this->filename)? true : false;
}

bool audiof::check_by_date(const dict& arg)
{
    return (arg.val_ == this->date)? true : false;
}

bool audiof::check_by_type(const dict& arg)
{
    return (arg.val_ == "AUDIO")? true : false;
}

bool audiof::check_by_bitr(const dict& arg)
{
    if (arg.oprt_ == '=')
        return utils::check_equal(this->bitrate.c_str(), arg.val_.c_str());
    else if (arg.oprt_ == '<')
        return utils::check_less(this->bitrate.c_str(), arg.val_.c_str());
    else if (arg.oprt_ == '>')
        return utils::check_more(this->bitrate.c_str(), arg.val_.c_str());
    else
        throw std::invalid_argument("invalid operator");
        
} //<>=

bool audiof::check_by_dur(const dict& arg)
{
    //printf("\noperator: %c\n", arg.oprt_);
    if (arg.oprt_ == '=')
        return utils::check_equal(this->duration.c_str(), arg.val_.c_str());
    else if (arg.oprt_ == '<')
        return utils::check_less(this->duration.c_str(), arg.val_.c_str());
    else if (arg.oprt_ == '>')
        return utils::check_more(this->duration.c_str(), arg.val_.c_str());
    else
        throw std::invalid_argument("invalid operator");
} //<>=