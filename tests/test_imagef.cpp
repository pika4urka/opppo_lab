#include <gtest/gtest.h>
#include "files/imagef.h"

TEST(ImagefTest, Constructor) {
    std::string filename = "photo.jpg";
    std::string date = "01.03.2026";
    std::string format = "jpg";
    std::string resolution = "1920x1080";
    
    imagef img(filename, date, format, resolution);
    
    EXPECT_EQ(img.get_filename(), filename);
    EXPECT_EQ(img.get_date(), date);
    EXPECT_EQ(img.get_format(), format);
    EXPECT_EQ(img.get_res(), resolution);
}

TEST(ImagefTest, CheckByFormat) {
    imagef img("photo.jpg", "01.03.2026", "jpg", "1920x1080");
    dict arg;
    arg.arg_ = "format";
    arg.val_ = "jpg";
    arg.oprt_ = '=';
    
    EXPECT_TRUE(img.check_arg_for_del(arg));
}

TEST(ImagefTest, CheckByType) {
    imagef img("photo.jpg", "01.03.2026", "jpg", "1920x1080");
    dict arg;
    arg.arg_ = "type";
    arg.val_ = "IMAGE";
    
    EXPECT_TRUE(img.check_arg_for_del(arg));
}