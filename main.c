#include "raylib.h"
#include <stdint.h>
#include <stdlib.h>

//------------------------------------------------------------------------------------
// Entity definitions
//------------------------------------------------------------------------------------
enum {
        EF_ALIVE = 1<<0,
        EF_VISIBLE = 1<<1,
        EF_COLLIDABLE = 1<<2
};

typedef enum {
        ENTITY_INVADER,
        ENTITY_PICKUP,
        ENTITY_BULLET
} EntityKind;

typedef struct {
        EntityKind kind;
        Vector2 position;
        int width;
        int height;
} Entity;

typedef struct {
        Entity* entity;
} Paddle;

typedef struct {
        Entity* entity;
} Invader;

typedef struct {
        Entity* entity;
} Bullet;

//------------------------------------------------------------------------------------
// Constants
//------------------------------------------------------------------------------------
#define MAX_INVADERS 128
#define MAX_BULLETS 128

static Invader* live_invader[MAX_INVADERS];
static Bullet* live_bullet[MAX_BULLETS];


//------------------------------------------------------------------------------------
// Rendering
//------------------------------------------------------------------------------------
static Paddle* paddle_create() {
        Paddle* paddle = malloc(sizeof(Paddle));

        if (!paddle)
                return NULL;

        Rectangle paddle_rect = (Rectangle) {
                paddle->entity->position.x,
                paddle->entity->position.y,
                paddle->entity->width,
                paddle->entity->height
        };

        return paddle;
}

static void paddle_destroy(Paddle* paddle) {
        if(!paddle)
                return;

        free(paddle);
}

static void paddle_handle_input(const Paddle* paddle) {
        if (IsKeyDown(KEY_W) || IsKeyDown(KEY_UP)) {
        }

        if (IsKeyDown(KEY_A) || IsKeyDown(KEY_LEFT)) {
        }

        if (IsKeyDown(KEY_D) || IsKeyDown(KEY_RIGHT)) {
        }
}

static void paddle_update(const Paddle* paddle) {
        k
}

static void paddle_draw(const Paddle* paddle) {
        Rectangle paddle_rect = (Rectangle) {
                paddle->entity->position.x,
                paddle->entity->position.y,
                paddle->entity->width,
                paddle->entity->height
        };
}

//------------------------------------------------------------------------------------
// Program main entry point
//------------------------------------------------------------------------------------
int main(void)
{
        // Initialization
        //--------------------------------------------------------------------------------------
        const int screenWidth = 800;
        const int screenHeight = 450;

        InitWindow(screenWidth, screenHeight, "raylib [core] example - basic window");

        Paddle* paddle = paddle_create();

        SetTargetFPS(60);               // Set our game to run at 60 frames-per-second
        //--------------------------------------------------------------------------------------

        // Main game loop
        while (!WindowShouldClose())    // Detect window close button or ESC key
        {
                // Update
                //----------------------------------------------------------------------------------
                paddle_update(paddle);


                // Draw
                //----------------------------------------------------------------------------------
                BeginDrawing();

                ClearBackground(RAYWHITE);

                paddle_draw(paddle);

                DrawText("Congrats! You created your first window!", 190, 200, 20, LIGHTGRAY);

                EndDrawing();
                //----------------------------------------------------------------------------------
        }

        // De-Initialization
        //--------------------------------------------------------------------------------------
        CloseWindow();        // Close window and OpenGL context
        //--------------------------------------------------------------------------------------

        return 0;
}
