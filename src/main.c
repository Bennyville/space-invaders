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
        Vector2 velocity;
        int width;
        int height;
} Entity;

typedef struct {
        Entity entity;
} Paddle;

typedef struct {
        Entity entity;
} Invader;

typedef struct {
        Entity entity;
} Bullet;

//------------------------------------------------------------------------------------
// Constants
//------------------------------------------------------------------------------------
#define MAX_INVADERS 128
#define MAX_BULLETS 128

#define PADDLE_HEIGHT 32
#define PADDLE_WIDTH 128

static Invader* live_invader[MAX_INVADERS];
static Bullet* live_bullet[MAX_BULLETS];


//------------------------------------------------------------------------------------
// Rendering
//------------------------------------------------------------------------------------
static Paddle* paddle_create() {
        Paddle* paddle = malloc(sizeof(Paddle));

        if (!paddle)
                return NULL;

        paddle->entity.position.x = 0;
        paddle->entity.position.y = 400;
        paddle->entity.velocity.x = 0;
        paddle->entity.velocity.y = 0;
        paddle->entity.width = PADDLE_WIDTH;
        paddle->entity.height = PADDLE_HEIGHT;

        return paddle;
}

static void paddle_destroy(Paddle* paddle) {
        if(!paddle)
                return;

        free(paddle);
}

static void paddle_handle_input(Paddle* paddle) {
        if (IsKeyDown(KEY_W) || IsKeyDown(KEY_UP)) {
        }

        if (IsKeyDown(KEY_A) || IsKeyDown(KEY_LEFT)) {
                paddle->entity.velocity.x = -3.0f;
        }

        if (IsKeyDown(KEY_D) || IsKeyDown(KEY_RIGHT)) {
                paddle->entity.velocity.x = 3.0f;
        }
}

static void paddle_update(Paddle* paddle) {
        paddle->entity.velocity.x = 0;

        paddle_handle_input(paddle);

        float next_pos_x += paddle->entity.velocity.x;

        paddle->entity.position.x += paddle->entity.velocity.x;
}

static void paddle_draw(const Paddle* paddle) {
        Rectangle paddle_rect = (Rectangle) {
                paddle->entity.position.x,
                paddle->entity.position.y,
                paddle->entity.width,
                paddle->entity.height
        };
        
        DrawRectangleRec(paddle_rect, RED);
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

                EndDrawing();
                //----------------------------------------------------------------------------------
        }

        // De-Initialization
        //--------------------------------------------------------------------------------------
        CloseWindow();        // Close window and OpenGL context
        //--------------------------------------------------------------------------------------
        
        paddle_destroy(paddle);

        return 0;
}
