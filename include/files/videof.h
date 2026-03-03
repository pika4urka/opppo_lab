#ifndef _VIDEO_FILE_
#define _VIDEO_FILE_

#include "files/filesAVI.h"
#include <string>

class videof : public filesAVI
{
    std::string res;
    std::string fr_rt;

    bool check_by_flnm(dict& arg);

    bool check_by_date(dict& arg);

    bool check_by_type(dict& arg);

    bool check_by_res(dict& arg);

    bool check_by_fr_rt(dict& arg);

public:
    videof(const std::string filename_, const std::string date_, std::string res_,
        std::string frame_rate_) :
        filesAVI(filename_, date_), res(res_), fr_rt(frame_rate_)
        {}

    std::string get_res();
    
    std::string get_frame_rate();

    bool check_arg_for_del(dict& arg) override;

    ~videof() override
    {}
};

#endif //_VIDEO_FILE_
