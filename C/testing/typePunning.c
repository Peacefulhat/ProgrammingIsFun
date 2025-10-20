#include <stdio.h>

// same width structs are need for typepunning
// manual access or via union (union safe option)
typedef struct {
    int x;// 4-bytes
    int y;// 4-bytes
} A;// 8-bytes

typedef struct {
    int x; // 4-bytes
    short int y; // 2-bytes
    char op; // 1-byte
    char padding; // 1-byte
} C; //8-bytes

typedef struct {
    int A;// 4-bytes
    char cord[4];// 4-bytes
} B; // 8-bytes

union {
    A a;
    B b;
    C c;
} All; // 8-bytes

int main(void)
{
    printf("Sizeof A:: %ld\nSizeof B:: %ld\nSizeof C:: %ld\n", sizeof(A), sizeof(B), sizeof(C));
    printf("Sizeof union All:: %ld\n\n", sizeof(All));

    // ─────────────────────────────────────────────
    // METHOD 1: Type punning via raw pointer cast
    // ─────────────────────────────────────────────
    C not_common;
    not_common.x = -10;
    not_common.y = 23;
    not_common.op = '+';
    not_common.padding = ' ';

    B *common = (B *)&not_common; // reinterpret memory as B

    printf("[Type punning via cast]\n");
    printf("Address of not_common :: %p\n", &not_common);
    printf("Address interpreted as B :: %p\n", common);
    printf("common->A   = %d\n", common->A);
    printf("common->cord bytes: %d %d %c %c\n",
           common->cord[0], common->cord[1],
           common->cord[2], common->cord[3]);
    printf("\n");

    // ─────────────────────────────────────────────
    // METHOD 2: Type punning via union (safe way)
    // ─────────────────────────────────────────────
    All.c.x = -10;
    All.c.y = 23;
    All.c.op = '+';
    All.c.padding = ' ';

    printf("[Type punning via union]\n");
    printf("All.c.x = %d\n", All.c.x);
    printf("All.c.y = %d\n", All.c.y);
    printf("All.c.op = %c\n", All.c.op);
    printf("All.c.padding = %c\n", All.c.padding);

    printf("Accessing same memory via All.b:\n");
    printf("All.b.A   = %d\n", All.b.A);
    printf("All.b.cord bytes: %d %d %c %c\n",
           All.b.cord[0], All.b.cord[1],
           All.b.cord[2], All.b.cord[3]);

    return 0;
}
