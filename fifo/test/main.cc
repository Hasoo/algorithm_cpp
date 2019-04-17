#include <gtest/gtest.h>
#include <iostream>

#include "../circle_que.h"

TEST(test_case_name, test_name) {
    CircleQue circleQue(3);
    EXPECT_EQ(circleQue.size(), 1);
    // circleQue.push(2);
    // circleQue.push(3);
    // circleQue.push(4);
    // EXPECT_EQ(circleQue.size(), 3);
    // EXPECT_TRUE(circleQue.full());
    // EXPECT_EQ(circleQue.pop(), 2);
    // EXPECT_EQ(circleQue.pop(), 3);
    // EXPECT_EQ(circleQue.pop(), 4);
    // EXPECT_EQ(circleQue.pop(), 1);
}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
