#include "hand_commands/handCom.h"

void modific_com(std::string &com)
{
    com.erase(std::remove(com.begin(), com.end(), ' '), com.end());
}

dict parser_arg(std::string &arg, char* key)
{
    dict dictionary;

    for (size_t i = 0; i < arg.size(); i++)
    {
        char symb = arg[i];
        if ((symb == '=' )||(symb == '<')||(symb == '>'))
        {
            dictionary.arg_ = arg.substr(0, i);
            dictionary.val_ = arg.substr(i + 1);
            dictionary.oprt_ = symb;
            if ((key == "add")&&(symb != '='))
                throw std::invalid_argument("Invalid operator in the ADD statement. Expcted \"=\"");
            break;
        }
    }
    return dictionary;
}

void get_args(std::string &instr_args, std::vector<dict> &vargs, int indx, char* key)
{
    int sz = instr_args.size();
    for (int i = indx; i < sz; i++)
    {
        if (instr_args.at(i) == ',')
        {
            vargs.push_back(parser_arg(instr_args.substr(indx, i - indx), key));
            indx = i + 1;
        }

        if (instr_args.at(i) == '}')
        {
            vargs.push_back(parser_arg(instr_args.substr(indx, i - indx), key));
            break;
        }
    }
    if (vargs.size() > 4)
        throw std::invalid_argument("lot of arguments");
}

void add_audio(container &cont, std::vector<dict> &args)
{
    std::string filename, date, bitrate, duration;
    for (auto& i : args)
    {
        if (i.arg_ == "filename")
            filename = i.val_;
        else if (i.arg_ == "date")
            date = i.val_;
        else if (i.arg_ == "bitrate")
            bitrate = i.val_;
        else if (i.arg_ == "duration")
            duration = i.val_;
        else
            throw std::invalid_argument("invalid argument in audio");
    }
    if ((filename == "") || (date == "") || (bitrate == "") || (duration == ""))
        throw std::invalid_argument("not all arguments in audio");
    cont.push(std::make_unique<audiof>(filename, date, bitrate, duration));
}

void add_video(container &cont, std::vector<dict> &args)
{
    std::string filename, date, resolution, frame_rate;
    for (auto i : args)
    {
        if (i.arg_ == "filename")
            filename = i.val_;
        else if (i.arg_ == "date")
            date = i.val_;
        else if (i.arg_ == "resolution")
            resolution = i.val_;
        else if (i.arg_ == "frame_rate")
            frame_rate = i.val_;
        else
            throw std::invalid_argument("invalid argument in video");
    }
    if ((filename == "") || (date == "") || (resolution == "") || (frame_rate == ""))
        throw std::invalid_argument("not all arguments in video");
    cont.push(std::make_unique<videof>(filename, date, resolution, frame_rate));
}

void add_image(container &cont, std::vector<dict> &args)
{
    std::string filename, date, resolution, format;
    for (auto i : args)
    {
        if (i.arg_ == "filename")
            filename = i.val_;
        else if (i.arg_ == "date")
            date = i.val_;
        else if (i.arg_ == "resolution")
            resolution = i.val_;
        else if (i.arg_ == "format")
            format = i.val_;
        else
            throw std::invalid_argument("invalid argument in image");
    }
    if ((filename == "") || (date == "") || (resolution == "") || (format == ""))
        throw std::invalid_argument("not all arguments in image");
    cont.push(std::make_unique<imagef>(filename, date, format, resolution));
}

#ifdef TEST
void test_funk(std::vector<dict> vargs_test)            //TEST
{
    std::string ar, va;
    std::cout << "ARGS:\n";
    for(int i = 0; i < vargs_test.size(); i++)
    {
        ar = vargs_test.at(i).arg_;
        va = vargs_test.at(i).val_;

        printf("ARG: %s VAL: %s\n", ar.c_str(), va.c_str());
    }
}
#endif //check args in cont

void instr_add(container &cont, std::string &com)
{
    if (com.compare(com.size() - 2, 2, "}}") != 0)
        throw std::invalid_argument("invalid syntax. Expected \"}}\"");

    std::vector<dict> args;

    if (com.compare(4, 5, "AUDIO") == 0)
    {
        get_args(com, args, 10, (char*)"add");
        add_audio(cont, args);
    }
    else if (com.compare(4, 5, "VIDEO") == 0)
    {
        get_args(com, args, 10, (char*)"add");
        add_video(cont, args);
    }
    else if (com.compare(4, 5, "IMAGE") == 0)
    {
        get_args(com, args, 10, (char*)"add");
        add_image(cont, args);
    }
    else
        throw std::invalid_argument("invalid type");

    //test_funk(args);
}

void instr_rem(container &cont, std::string &com)
{
    if (com.compare(com.size() - 1, 1, "}") != 0)
        throw std::invalid_argument("invalid syntax.  Expected \"}\"");
    int indx = 4;
    std::vector<dict> args;
    get_args(com, args, indx, "rem");

    for (auto& arg : args)
    {
        // std::cout << arg.arg_ << arg.oprt_ << arg.val_;
        cont.rem(arg);
    }
}

void instr_print(container& cont)
{
    auto sz = cont.size();
    if (sz == 0)
        return;
    //     throw std::invalid_argument("There are no objects in the container");
    filesAVI* file;

    for (int i = 0; i < sz; i++)
    {
        file = cont.at(i);
        
        if (dynamic_cast<audiof*>(file))
        {
            auto* audiofile = dynamic_cast<audiof*>(file);
            std::cout << "\naudio\n";
            printf("name: %s\ndate: %s\nbitr: %s\ndur: %s\n\n", 
                audiofile->get_filename().c_str(),
                audiofile->get_date().c_str(),
                audiofile->get_bitrate().c_str(),
                audiofile->get_duration().c_str()
            );
        } else if (dynamic_cast<videof*>(file))
        {
            auto* audiofile = dynamic_cast<videof*>(file);
            std::cout << "\nvideo\n";
            printf("name: %s\ndate: %s\nfr_rate: %s\nres: %s\n\n", 
                audiofile->get_filename().c_str(),
                audiofile->get_date().c_str(),
                audiofile->get_frame_rate().c_str(),
                audiofile->get_res().c_str()
            );
        } else if (dynamic_cast<imagef*>(file))
        {
            auto* audiofile = dynamic_cast<imagef*>(file);
            std::cout << "\nimage\n";
            printf("name: %s\ndate: %s\nformat: %s\nres: %s\n\n", 
                audiofile->get_filename().c_str(),
                audiofile->get_date().c_str(),
                audiofile->get_format().c_str(),
                audiofile->get_res().c_str()
            );
        } else
        {
            std::cout << "\nxyeTa\n";
        }
    }
}

void handCom::exect_com(container &cont, std::string &com)
{
    modific_com(com);
    int size_instr = 0;
    while ((com.at(size_instr) != '{') && (size_instr++ != 4)) {}

    if (size_instr == 0)
        return;
    else if (size_instr < 3)
        throw std::invalid_argument("invalid syntax\n\tinstruction len is small");

    if (com.compare(0, size_instr, "ADD") == 0)
        instr_add(cont, com);
    else if (com.compare(0, size_instr, "REM") == 0)
       instr_rem(cont, com);
    else if (com.compare(0, size_instr, "PRINT") == 0)
        instr_print(cont);
    else
        throw std::invalid_argument("invalid syntax instruction");   
}

