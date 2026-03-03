#ifndef _FILES_AVI_
#define _FILES_AVI_

#include <string>
#include "utils/utils.h"


class filesAVI
{
protected:
    std::string filename;
    std::string date;
 
public:
    filesAVI(const std::string filename_, const std::string date_) :
        filename(filename_), date(date_) {}

    std::string get_filename();
    //getter of filename

    std::string get_date();
    //getter of the last change date

    //virtual void display();
    //info output to console

    virtual bool check_arg_for_del(dict& arg){return false;}
    //чек аргументов на удаление объекта

    virtual ~filesAVI(){}
};

#endif //_FILES_AVI_