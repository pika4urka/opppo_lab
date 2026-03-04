#include <gtest/gtest.h>
#include "container/container.h"

class ContainerTest : public ::testing::Test {
protected:
    void SetUp() override {
        // Создаем контейнер и добавляем несколько файлов перед каждым тестом
        cont.push(std::make_unique<audiof>("song1.mp3", "01.03.2026", "128", "130"));
        cont.push(std::make_unique<audiof>("song2.mp3", "02.03.2026", "256", "230"));
        cont.push(std::make_unique<videof>("video1.mp4", "01.03.2026", "1920x1080", "60"));
        cont.push(std::make_unique<imagef>("photo1.jpg", "03.03.2026", "jpg", "800x600"));
    }
    
    container cont;
};

TEST_F(ContainerTest, Push) {
    size_t old_size = cont.size();
    cont.push(std::make_unique<audiof>("song3.mp3", "04.03.2026", "320", "200"));
    EXPECT_EQ(cont.size(), old_size + 1);
}

TEST_F(ContainerTest, At) {
    filesAVI* file = cont.at(0);
    EXPECT_NE(file, nullptr);
    
    // Проверяем, что это действительно аудиофайл
    audiof* audio = dynamic_cast<audiof*>(file);
    EXPECT_NE(audio, nullptr);
}

TEST_F(ContainerTest, RemByType) {
    dict arg;
    arg.arg_ = "type";
    arg.val_ = "AUDIO";
    
    cont.rem(arg);
    // Должны удалиться оба аудиофайла
    EXPECT_EQ(cont.size(), 2);  // остались видео и фото
    
    // Проверяем, что аудио действительно нет
    for (int i = 0; i < cont.size(); i++) {
        filesAVI* file = cont.at(i);
        EXPECT_FALSE(dynamic_cast<audiof*>(file));
    }
}