#include <gtest/gtest.h>
#include <iostream>

#include "../circle_que.h"

TEST(test_case_name, test_name) {
    CircleQue circleQue(3);
    circleQue.push(2);
    EXPECT_EQ(circleQue.size(), 0);
    EXPECT_EQ(circleQue.pop(), 2);
}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
