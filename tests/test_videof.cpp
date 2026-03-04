#include <gtest/gtest.h>
#include "files/videof.h"

TEST(VideofTest, Constructor) {
    std::string filename = "video.mp4";
    std::string date = "01.03.2026";
    std::string resolution = "1920x1080";
    std::string frame_rate = "60";
    
    videof v(filename, date, resolution, frame_rate);
    
    EXPECT_EQ(v.get_filename(), filename);
    EXPECT_EQ(v.get_date(), date);
    EXPECT_EQ(v.get_res(), resolution);
    EXPECT_EQ(v.get_frame_rate(), frame_rate);
}

TEST(VideofTest, CheckByName) {
    videof v("video.mp4", "01.03.2026", "1920x1080", "60");
    dict arg;
    arg.arg_ = "filename";
    arg.val_ = "video.mp4";
    
    EXPECT_TRUE(v.check_arg_for_del(arg));
}

TEST(VideofTest, CheckByType) {
    videof v("video.mp4", "01.03.2026", "1920x1080", "60");
    dict arg;
    arg.arg_ = "type";
    arg.val_ = "VIDEO";
    arg.oprt_ = '=';
    
    EXPECT_TRUE(v.check_arg_for_del(arg));
}

TEST(VideofTest, CheckByResolutionLess) {
    videof v("video.mp4", "01.03.2026", "1920x1080", "60");
    dict arg;
    arg.arg_ = "resolution";
    arg.val_ = "3840x2160";  // больше
    arg.oprt_ = '<';          // наше разрешение меньше?
    
    EXPECT_TRUE(v.check_arg_for_del(arg));  // 1920*1080 < 3840*2160
}

TEST(VideofTest, CheckByFrameRate) {
    videof v("video.mp4", "01.03.2026", "1920x1080", "60");
    dict arg;
    arg.arg_ = "frame_rate";
    arg.val_ = "60";
    arg.oprt_ = '=';
    
    EXPECT_TRUE(v.check_arg_for_del(arg));
}