#include "container/container.h"

void container::push(std::unique_ptr<filesAVI> file)
{
    this->files.push_back(std::move(file));
}

filesAVI* container::at(int indx)
{
    return files.at(indx).get();
}

void container::rem(dict& arg)
{
    this->files.erase(
        std::remove_if(
            files.begin(),
            files.end(),
            [&](const std::unique_ptr<filesAVI>& file)
            {
                return file.get()->check_arg_for_del(arg);
            }
        ), files.end());
}


size_t container::size()
{
    return files.size();
}