#ifndef _VIDEO_FILE_
#define _VIDEO_FILE_

#include "files/filesAVI.h"
#include <string>

class videof : public filesAVI
{
    std::string res;
    std::string fr_rt;

    bool check_by_name(const dict& arg);

    bool check_by_date(const dict& arg);

    bool check_by_type(const dict& arg);

    bool check_by_res(const dict& arg);

    bool check_by_fr_rt(const dict& arg);

public:
    videof(const std::string filename_, const std::string date_, std::string res_,
        std::string frame_rate_) :
        filesAVI(filename_, date_), res(res_), fr_rt(frame_rate_)
        {
            utils::check_num(frame_rate_.c_str());
        }

    const std::string& get_res() const;
    
    const std::string& get_frame_rate() const;

    bool check_arg_for_del(dict& arg) override;

    ~videof() override
    {}
};

#endif //_VIDEO_FILE_
