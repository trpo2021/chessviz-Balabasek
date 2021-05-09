#include "ctest.h"
#include "libchessviz/desk.h"
#include "libchessviz/move.h"

CTEST(move_pown, correct_move)
{
    figure desk[8][8];
    createDesk(desk);
    char arr[] = {'e', '2', '-', 'e', '4'};

    coordinate a = parserCoord(arr);
    coordinate b = parserCoord(&arr[3]);

    int expect = 0;
    int result = move_pown(desk, a, b);

    ASSERT_EQUAL(expect, result);
}

CTEST(move_pown, correct_move2)
{
    figure desk[8][8];
    createDesk(desk);
    char arr[] = {'a', '2', '-', 'a', '3'};

    coordinate a = parserCoord(arr);
    coordinate b = parserCoord(&arr[3]);

    int expect = 0;
    int result = move_pown(desk, a, b);

    ASSERT_EQUAL(expect, result);
}

CTEST(move_pown, uncorrect_move)
{
    figure desk[8][8];
    createDesk(desk);
    char arr[] = {'b', '2', '-', 'e', '5'};

    coordinate a = parserCoord(arr);
    coordinate b = parserCoord(&arr[3]);

    int expect = 1;
    int result = move_pown(desk, a, b);

    ASSERT_EQUAL(expect, result);
}

CTEST(move_pown, uncorrect_move2)
{
    figure desk[8][8];
    createDesk(desk);

    char arr[] = {'d', '1', '-', 'e', '3'};

    coordinate a = parserCoord(arr);
    coordinate b = parserCoord(&arr[3]);

    int expect = 1;
    int result = move_pown(desk, a, b);

    ASSERT_EQUAL(expect, result);
}

CTEST(move_pown, uncorrect_move3)
{
    figure desk[8][8];
    createDesk(desk);

    char arr[] = {'e', '2', '-', 'e', '4'};

    coordinate a = parserCoord(arr);
    coordinate b = parserCoord(&arr[3]);
    move_pown(desk, a, b);

    char arr2[] = {'e', '4', '-', 'e', '2'};
    a = parserCoord(arr2);
    b = parserCoord(&arr2[3]);

    int expect = 1;
    int result = move_pown(desk, a, b);

    ASSERT_EQUAL(expect, result);
}

CTEST(move_pown, uncorrect_move4)
{
    figure desk[8][8];
    createDesk(desk);
    char arr[] = {'a', '1', '-', 'a', '3'};

    coordinate a = parserCoord(arr);
    coordinate b = parserCoord(&arr[3]);

    int expect = 1;
    int result = move_pown(desk, a, b);

    ASSERT_EQUAL(expect, result);
}

CTEST(move_king, correct_move)
{
    figure desk[8][8];
    createDesk(desk);

    char arr[] = {'e', '7', '-', 'e', '5'};

    coordinate a = parserCoord(arr);
    coordinate b = parserCoord(&arr[3]);
    move_pown(desk, a, b);

    char arr2[] = {'e', '8', '-', 'e', '7'};

    coordinate a2 = parserCoord(arr2);
    coordinate b2 = parserCoord(&arr2[3]);

    int expect = 0;
    int result = move_king(desk, a2, b2);

    ASSERT_EQUAL(expect, result);
}

CTEST(move_king, correct_move2)
{
    figure desk[8][8];
    createDesk(desk);

    char arr[] = {'e', '7', '-', 'e', '5'};

    coordinate a = parserCoord(arr);
    coordinate b = parserCoord(&arr[3]);
    move_pown(desk, a, b);

    char arr2[] = {'e', '8', '-', 'e', '7'};

    a = parserCoord(arr2);
    b = parserCoord(&arr2[3]);
    move_king(desk, a, b);

    char arr3[] = {'e', '7', '-', 'e', '8'};

    a = parserCoord(arr3);
    b = parserCoord(&arr3[3]);

    int expect = 0;
    int result = move_king(desk, a, b);

    ASSERT_EQUAL(expect, result);
}

CTEST(move_king, uncorrect_move)
{
    figure desk[8][8];
    createDesk(desk);

    char arr[] = {'e', '8', '-', 'e', '7'};

    coordinate a = parserCoord(arr);
    coordinate b = parserCoord(&arr[3]);

    int expect = 1;
    int result = move_king(desk, a, b);

    ASSERT_EQUAL(expect, result);
}

CTEST(move_king, uncorrect_move2)
{
    figure desk[8][8];
    createDesk(desk);

    char arr[] = {'e', '2', '-', 'e', '5'};

    coordinate a = parserCoord(arr);
    coordinate b = parserCoord(&arr[3]);

    int expect = 1;
    int result = move_king(desk, a, b);

    ASSERT_EQUAL(expect, result);
}

CTEST(move_knight, correct_move)
{
    figure desk[8][8];
    createDesk(desk);

    char arr[] = {'b', '8', '-', 'a', '6'};

    coordinate a = parserCoord(arr);
    coordinate b = parserCoord(&arr[3]);

    int expect = 0;
    int result = move_knight(desk, a, b);

    ASSERT_EQUAL(expect, result);
}

CTEST(move_knight, correct_move2)
{
    figure desk[8][8];
    createDesk(desk);

    char arr[] = {'b', '8', '-', 'a', '6'};

    coordinate a = parserCoord(arr);
    coordinate b = parserCoord(&arr[3]);
    move_knight(desk, a, b);
    char arr2[] = {'a', '6', '-', 'c', '5'};

    a = parserCoord(arr2);
    b = parserCoord(&arr2[3]);

    int expect = 0;
    int result = move_knight(desk, a, b);

    ASSERT_EQUAL(expect, result);
}

CTEST(move_knight, correct_move3)
{
    figure desk[8][8];
    createDesk(desk);

    char arr[] = {'b', '8', '-', 'a', '6'};

    coordinate a = parserCoord(arr);
    coordinate b = parserCoord(&arr[3]);
    move_knight(desk, a, b);
    char arr2[] = {'a', '6', '-', 'b', '8'};

    a = parserCoord(arr2);
    b = parserCoord(&arr2[3]);

    int expect = 0;
    int result = move_knight(desk, a, b);

    ASSERT_EQUAL(expect, result);
}

CTEST(move_knight, uncorrect_move)
{
    figure desk[8][8];
    createDesk(desk);

    char arr[] = {'b', '8', '-', 'a', '5'};

    coordinate a = parserCoord(arr);
    coordinate b = parserCoord(&arr[3]);

    int expect = 1;
    int result = move_knight(desk, a, b);

    ASSERT_EQUAL(expect, result);
}

CTEST(move_knight, uncorrect_move2)
{
    figure desk[8][8];
    createDesk(desk);

    char arr[] = {'b', '8', '-', 'a', '7'};

    coordinate a = parserCoord(arr);
    coordinate b = parserCoord(&arr[3]);

    int expect = 1;
    int result = move_knight(desk, a, b);

    ASSERT_EQUAL(expect, result);
}

CTEST(move_knight, uncorrect_move3)
{
    figure desk[8][8];
    createDesk(desk);

    char arr[] = {'e', '2', '-', 'c', '8'};

    coordinate a = parserCoord(arr);
    coordinate b = parserCoord(&arr[3]);

    int expect = 1;
    int result = move_knight(desk, a, b);

    ASSERT_EQUAL(expect, result);
}

CTEST(move_rook, correct_move)
{
    figure desk[8][8];
    createDesk(desk);

    char arr[] = {'h', '7', '-', 'h', '5'};

    coordinate a = parserCoord(arr);
    coordinate b = parserCoord(&arr[3]);
    move_pown(desk, a, b);

    char arr2[] = {'h', '8', '-', 'h', '6'};
    a = parserCoord(arr2);
    b = parserCoord(&arr2[3]);

    int expect = 0;
    int result = move_rook(desk, a, b);

    ASSERT_EQUAL(expect, result);
}

CTEST(move_rook, correct_move2)
{
    figure desk[8][8];
    createDesk(desk);

    char arr[] = {'h', '7', '-', 'h', '5'};

    coordinate a = parserCoord(arr);
    coordinate b = parserCoord(&arr[3]);
    move_pown(desk, a, b);

    char arr2[] = {'h', '8', '-', 'h', '6'};
    a = parserCoord(arr2);
    b = parserCoord(&arr2[3]);
    move_rook(desk, a, b);

    char arr3[] = {'h', '6', '-', 'h', '8'};
    a = parserCoord(arr3);
    b = parserCoord(&arr3[3]);

    int expect = 0;
    int result = move_rook(desk, a, b);

    ASSERT_EQUAL(expect, result);
}

CTEST(move_rook, correct_move3)
{
    figure desk[8][8];
    createDesk(desk);

    char arr[] = {'h', '7', '-', 'h', '5'};

    coordinate a = parserCoord(arr);
    coordinate b = parserCoord(&arr[3]);
    move_pown(desk, a, b);

    char arr2[] = {'h', '8', '-', 'h', '6'};
    a = parserCoord(arr2);
    b = parserCoord(&arr2[3]);

    char arr3[] = {'h', '6', '-', 'a', '6'};
    a = parserCoord(arr3);
    b = parserCoord(&arr3[3]);

    int expect = 0;
    int result = move_rook(desk, a, b);

    ASSERT_EQUAL(expect, result);
}

CTEST(move_rook, uncorrect_move)
{
    figure desk[8][8];
    createDesk(desk);

    char arr[] = {'h', '8', '-', 'h', '6'};

    coordinate a = parserCoord(arr);
    coordinate b = parserCoord(&arr[3]);

    int expect = 1;
    int result = move_rook(desk, a, b);

    ASSERT_EQUAL(expect, result);
}

CTEST(move_rook, uncorrect_move2)
{
    figure desk[8][8];
    createDesk(desk);

    char arr[] = {'h', '8', '-', 'a', '8'};

    coordinate a = parserCoord(arr);
    coordinate b = parserCoord(&arr[3]);

    int expect = 1;
    int result = move_rook(desk, a, b);

    ASSERT_EQUAL(expect, result);
}

CTEST(move_rook, uncorrect_move3)
{
    figure desk[8][8];
    createDesk(desk);

    char arr[] = {'h', '8', '-', 'h', '7'};

    coordinate a = parserCoord(arr);
    coordinate b = parserCoord(&arr[3]);

    int expect = 1;
    int result = move_rook(desk, a, b);

    ASSERT_EQUAL(expect, result);
}

CTEST(move_rook, uncorrect_move4)
{
    figure desk[8][8];
    createDesk(desk);

    char arr[] = {'e', '1', '-', 'e', '5'};

    coordinate a = parserCoord(arr);
    coordinate b = parserCoord(&arr[3]);

    int expect = 1;
    int result = move_rook(desk, a, b);

    ASSERT_EQUAL(expect, result);
}

CTEST(move_bishop, correct_move)
{
    figure desk[8][8];
    createDesk(desk);

    char arr[] = {'d', '7', '-', 'd', '5'};
    coordinate a = parserCoord(arr);
    coordinate b = parserCoord(&arr[3]);
    move_pown(desk, a, b);

    char arr2[] = {'c', '8', '-', 'e', '6'};
    a = parserCoord(arr2);
    b = parserCoord(&arr2[3]);

    int expect = 0;
    int result = move_bishop(desk, a, b);

    ASSERT_EQUAL(expect, result);
}

CTEST(move_bishop, correct_move2)
{
    figure desk[8][8];
    createDesk(desk);

    char arr[] = {'d', '7', '-', 'd', '5'};
    coordinate a = parserCoord(arr);
    coordinate b = parserCoord(&arr[3]);
    move_pown(desk, a, b);

    char arr2[] = {'c', '8', '-', 'e', '6'};
    a = parserCoord(arr2);
    b = parserCoord(&arr2[3]);
    move_bishop(desk, a, b);

    char arr3[] = {'e', '6', '-', 'c', '8'};
    a = parserCoord(arr3);
    b = parserCoord(&arr3[3]);

    int expect = 0;
    int result = move_bishop(desk, a, b);

    ASSERT_EQUAL(expect, result);
}

CTEST(move_bishop, correct_move3)
{
    figure desk[8][8];
    createDesk(desk);

    char arr[] = {'d', '7', '-', 'd', '6'};
    coordinate a = parserCoord(arr);
    coordinate b = parserCoord(&arr[3]);
    move_pown(desk, a, b);

    char arr2[] = {'c', '8', '-', 'e', '6'};
    a = parserCoord(arr2);
    b = parserCoord(&arr2[3]);
    move_bishop(desk, a, b);

    char arr3[] = {'e', '6', '-', 'c', '4'};
    a = parserCoord(arr3);
    b = parserCoord(&arr3[3]);

    int expect = 0;
    int result = move_bishop(desk, a, b);

    ASSERT_EQUAL(expect, result);
}

CTEST(move_bishop, uncorrect_move)
{
    figure desk[8][8];
    createDesk(desk);

    char arr[] = {'c', '8', '-', 'e', '6'};

    coordinate a = parserCoord(arr);
    coordinate b = parserCoord(&arr[3]);

    int expect = 1;
    int result = move_bishop(desk, a, b);

    ASSERT_EQUAL(expect, result);
}

CTEST(move_bishop, uncorrect_move2)
{
    figure desk[8][8];
    createDesk(desk);

    char arr[] = {'c', '8', '-', 'c', '6'};

    coordinate a = parserCoord(arr);
    coordinate b = parserCoord(&arr[3]);

    int expect = 1;
    int result = move_bishop(desk, a, b);

    ASSERT_EQUAL(expect, result);
}

CTEST(move_bishop, uncorrect_move3)
{
    figure desk[8][8];
    createDesk(desk);

    char arr[] = {'d', '7', '-', 'd', '5'};
    coordinate a = parserCoord(arr);
    coordinate b = parserCoord(&arr[3]);
    move_pown(desk, a, b);

    char arr2[] = {'c', '8', '-', 'e', '6'};
    a = parserCoord(arr2);
    b = parserCoord(&arr2[3]);
    move_bishop(desk, a, b);

    char arr3[] = {'e', '6', '-', 'c', '4'};
    a = parserCoord(arr3);
    b = parserCoord(&arr3[3]);

    int expect = 1;
    int result = move_bishop(desk, a, b);

    ASSERT_EQUAL(expect, result);
}

CTEST(move_bishop, uncorrect_move4)
{
    figure desk[8][8];
    createDesk(desk);

    char arr[] = {'e', '2', '-', 'f', '1'};

    coordinate a = parserCoord(arr);
    coordinate b = parserCoord(&arr[3]);

    int expect = 1;
    int result = move_bishop(desk, a, b);

    ASSERT_EQUAL(expect, result);
}

CTEST(move_queen, uncorrect_move)
{
    figure desk[8][8];
    createDesk(desk);

    char arr[] = {'d', '8', '-', 'h', '7'};

    coordinate a = parserCoord(arr);
    coordinate b = parserCoord(&arr[3]);

    int expect = 1;
    int result = move_queen(desk, a, b);

    ASSERT_EQUAL(expect, result);
}

CTEST(move_queen, uncorrect_move2)
{
    figure desk[8][8];
    createDesk(desk);

    char arr[] = {'d', '8', '-', 'e', '6'};

    coordinate a = parserCoord(arr);
    coordinate b = parserCoord(&arr[3]);

    int expect = 1;
    int result = move_queen(desk, a, b);

    ASSERT_EQUAL(expect, result);
}

CTEST(move_queen, uncorrect_move3)
{
    figure desk[8][8];
    createDesk(desk);

    char arr[] = {'e', '7', '-', 'e', '5'};

    coordinate a = parserCoord(arr);
    coordinate b = parserCoord(&arr[3]);

    int expect = 0;
    int result = move_queen(desk, a, b);

    ASSERT_EQUAL(expect, result);
}

CTEST(move_queen, correct_move)
{
    figure desk[8][8];
    createDesk(desk);

    char arr[] = {'e', '7', '-', 'e', '5'};

    coordinate a = parserCoord(arr);
    coordinate b = parserCoord(&arr[3]);
    move_pown(desk, a, b);

    char arr2[] = {'d', '8', '-', 'f', '6'};

    a = parserCoord(arr2);
    b = parserCoord(&arr2[3]);

    int expect = 0;
    int result = move_queen(desk, a, b);

    ASSERT_EQUAL(expect, result);
}

CTEST(move_queen, correct_move2)
{
    figure desk[8][8];
    createDesk(desk);

    char arr[] = {'e', '7', '-', 'e', '5'};

    coordinate a = parserCoord(arr);
    coordinate b = parserCoord(&arr[3]);
    move_pown(desk, a, b);

    char arr2[] = {'d', '8', '-', 'f', '6'};

    a = parserCoord(arr2);
    b = parserCoord(&arr2[3]);
    move_queen(desk, a, b);

    char arr3[] = {'f', '6', '-', 'd', '8'};

    a = parserCoord(arr3);
    b = parserCoord(&arr3[3]);

    int expect = 0;
    int result = move_queen(desk, a, b);

    ASSERT_EQUAL(expect, result);
}

CTEST(move_queen, correct_move3)
{
    figure desk[8][8];
    createDesk(desk);

    char arr[] = {'e', '7', '-', 'e', '5'};

    coordinate a = parserCoord(arr);
    coordinate b = parserCoord(&arr[3]);
    move_pown(desk, a, b);

    char arr2[] = {'d', '8', '-', 'f', '6'};

    a = parserCoord(arr2);
    b = parserCoord(&arr2[3]);
    move_queen(desk, a, b);

    char arr3[] = {'f', '6', '-', 'h', '6'};

    a = parserCoord(arr3);
    b = parserCoord(&arr3[3]);

    int expect = 0;
    int result = move_queen(desk, a, b);

    ASSERT_EQUAL(expect, result);
}

CTEST(move_queen, correct_move4)
{
    figure desk[8][8];
    createDesk(desk);

    char arr[] = {'e', '7', '-', 'e', '5'};

    coordinate a = parserCoord(arr);
    coordinate b = parserCoord(&arr[3]);
    move_pown(desk, a, b);

    char arr2[] = {'d', '8', '-', 'f', '6'};

    a = parserCoord(arr2);
    b = parserCoord(&arr2[3]);
    move_queen(desk, a, b);

    char arr3[] = {'f', '6', '-', 'a', '6'};

    a = parserCoord(arr3);
    b = parserCoord(&arr3[3]);

    int expect = 0;
    int result = move_queen(desk, a, b);

    ASSERT_EQUAL(expect, result);
}
