#ifndef _IMAGE_FILE_
#define _IMAGE_FILE_

#include "files/filesAVI.h"
#include <string>

class imagef : public filesAVI
{
    std::string res;
    std::string format;

    bool check_by_name(const dict& arg);

    bool check_by_date(const dict& arg);

    bool check_by_type(const dict& arg);

    bool check_by_res(const dict& arg);

    bool check_by_format(const dict& arg);

public:
    imagef(const std::string& filename_, const std::string& date_,
        std::string& format_, std::string& res_) :
        filesAVI(filename_, date_), res(res_), format(format_)
        {}

    const std::string& get_res() const;
    
    const std::string& get_format() const;

    bool check_arg_for_del(dict& arg) override;
    
    ~imagef() override
    {}
};

#endif //_IMAGE_FILE_
