#include <gtest/gtest.h>
#include "files/audiof.h"


TEST(AudiofTest, AudiofCnstr_check_arg)
{
    std::string bitr("128"), dur("120"), flnm("file"), dt("04.03.2026");

    audiof file(flnm, dt, bitr, dur);
    
    EXPECT_EQ(file.get_filename(), "file");
    EXPECT_EQ(file.get_date(), "04.03.2026");
    EXPECT_EQ(file.get_bitrate(), "128");
    EXPECT_EQ(file.get_duration(), "120");

    dict dct;
    dct.arg_ = "bitrate";
    dct.oprt_ = '=';
    dct.val_ = "128";

    EXPECT_EQ(file.check_arg_for_del(dct), true);
}

TEST(AudiofTest, InvalidAudiofCnstr_check_arg)
{
    std::string bitr("12h"), dur("120"), flnm("file"), dt("04.03.2026");

    EXPECT_THROW(audiof(flnm, dt, bitr, dur), std::invalid_argument);

    bitr = "128";

    audiof file(flnm, dt, bitr, dur);

    dict dct;
    dct.arg_ = "bitrate";
    dct.oprt_ = '\0';
    dct.val_ = "128";

    EXPECT_THROW(file.check_arg_for_del(dct), std::invalid_argument);
}

