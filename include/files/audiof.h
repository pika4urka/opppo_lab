#ifndef _AUDIO_FILE_
#define _AUDIO_FILE_

#include "files/filesAVI.h"
#include <string>

class audiof : public filesAVI
{
    std::string bitrate;
    std::string duration;

    bool check_by_name(dict& arg);

    bool check_by_date(dict& arg);

    bool check_by_type(dict& arg);

    bool check_by_bitr(dict& arg);

    bool check_by_dur(dict& arg);

public:
    audiof(const std::string filename_, const std::string date_,
        std::string bitrate_, std::string duration_) :
        filesAVI(filename_, date_), bitrate(bitrate_), duration(duration_) 
        {}

    std::string get_bitrate();
    
    std::string get_duration();

    //void display();

    bool check_arg_for_del(dict& arg) override;

    ~audiof() override
    {}
};

#endif //_AUDIO_FILE_