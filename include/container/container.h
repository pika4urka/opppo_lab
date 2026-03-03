#ifndef _CONTAINER_
#define _CONTAINER_

#include "files/audiof.h"
#include "files/imagef.h"
#include "files/videof.h"
#include <vector>
#include <memory>
#include <algorithm>
#include "utils/utils.h"


class container
{
    std::vector<std::unique_ptr<filesAVI>> files;

public:
    container() 
    {}

    void push(std::unique_ptr<filesAVI> file);

    void rem(dict& arg);
      
    void display();

    size_t size();

    filesAVI* at(int indx);
    
    ~container() {}
};

#endif //_CONTAINER_


