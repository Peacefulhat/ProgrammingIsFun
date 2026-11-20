#include <stdio.h>

typedef int int32;
typedef float real32;
typedef struct
{
    real32 PlayerX;
    real32 PlayerY;
    real32 tjump;
} game_state;

game_state DefaultArgs(real32 X, real32 Y, real32 tjump)
{
    game_state Result = {};
    Result.PlayerX = X;
    Result.PlayerY = Y;
    Result.tjump   = tjump;
    return (Result);
}

#define DEFAULT_ARGS(name) game_state name(real32 X, real32 Y, real32 tjump)

typedef DEFAULT_ARGS(default_args);

DEFAULT_ARGS(DefaultArgsStub)
{
    game_state Result = {};
    return (Result);
}

static default_args* DefaultArgs_ = DefaultArgsStub;


 
int main()
{
    DefaultArgs_ = DefaultArgs;
    game_state Result = DefaultArgs_(2.3f, 4.5f, 3.4f);
    printf("Player::\n");
    printf("%f, %f, %f", Result.PlayerX, Result.PlayerY, Result.tjump);
    return 0;
}
