#include <gtest/gtest.h>
#include "hand_commands/handCom.h"


TEST(HandComTest, AddAudioCommand)
{
    container cont;
    
    std::string command = "ADD{AUDIO{filename=test.mp3,date=01.03.2026,bitrate=128,duration=130}}";
    
    handCom::exect_com(cont, command);

    EXPECT_EQ(cont.size(), 1);
    
    filesAVI* file = cont.at(0);
    audiof* audio = dynamic_cast<audiof*>(file);
    ASSERT_NE(audio, nullptr);
    EXPECT_EQ(audio->get_filename(), "test.mp3");
    EXPECT_EQ(audio->get_bitrate(), "128");
}

TEST(HandComTest, InvalidBitrateValue) {
    container cont;
    // В битрейте вместо числа - буква
    std::string command = "ADD{AUDIO{filename=test.mp3,date=01.03.2026,bitrate=abc,duration=3:30}}";
    
    // Ожидаем исключение
    EXPECT_THROW(handCom::exect_com(cont, command), std::invalid_argument);
    
    // Проверяем, что ничего не добавилось
    EXPECT_EQ(cont.size(), 0);
}