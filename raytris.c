#include "raylib.h"
#include <stdio.h>
#include <stdlib.h>

typedef enum pieces {s, z, l, j, i, o, t} pieces;
typedef enum orientation {north, east, south, west} orientation;

struct coord {
    int x;
    int y;
};

struct piece_info {
    pieces piece;
    int x_pos;
    int y_pos;
    orientation rotation;
};

// window sizing
const int window_width = 800;
const int window_height = 450;

// grid sizing
const int unit_size = 18;

// draw each piece
void draw_piece(pieces piece, int x_pos, int y_pos, orientation rotation) {
    switch (piece) {
        case s: {
            if (rotation == north) {
                // draw squares
                DrawRectangle(x_pos - (unit_size / 2), y_pos - (unit_size / 2), unit_size, unit_size, GREEN); // center
                DrawRectangle(x_pos - (unit_size / 2), y_pos - (3 * (unit_size / 2)), unit_size, unit_size, GREEN); // top-middle
                DrawRectangle(x_pos - (3 * (unit_size / 2)), y_pos - (unit_size / 2), unit_size, unit_size, GREEN); // left
                DrawRectangle(x_pos + (unit_size / 2), y_pos - (3 * (unit_size / 2)), unit_size, unit_size, GREEN); // top-right
                
                // draw center
                //DrawCircle(x_pos, y_pos, 3, RAYWHITE);
                break;
            }
            else if (rotation == east) {
                // draw minos
                DrawRectangle(x_pos - (unit_size / 2), y_pos - (unit_size / 2), unit_size, unit_size, GREEN); // center
                DrawRectangle(x_pos + (unit_size / 2), y_pos - (unit_size / 2), unit_size, unit_size, GREEN); // right
                DrawRectangle(x_pos - (unit_size / 2), y_pos - (3 * (unit_size / 2)), unit_size, unit_size, GREEN); // top
                DrawRectangle(x_pos + (unit_size / 2), y_pos + (unit_size / 2), unit_size, unit_size, GREEN); // bottom-right
                
                // draw center
                //DrawCircle(x_pos, y_pos, 3, RAYWHITE);
                break;
            }
            else if (rotation == south) {
                // draw squares
                DrawRectangle(x_pos - (unit_size / 2), y_pos - (unit_size / 2), unit_size, unit_size, GREEN); // center
                DrawRectangle(x_pos - (unit_size / 2), y_pos + (unit_size / 2), unit_size, unit_size, GREEN); // bottom-middle
                DrawRectangle(x_pos + (unit_size / 2), y_pos - (unit_size / 2), unit_size, unit_size, GREEN); // right
                DrawRectangle(x_pos - (3 * (unit_size / 2)), y_pos + (unit_size / 2), unit_size, unit_size, GREEN); // bottom-right
                
                // draw center
                //DrawCircle(x_pos, y_pos, 3, RAYWHITE);
                break;
            }
            else if (rotation == west) {
                // draw squares
                DrawRectangle(x_pos - (unit_size / 2), y_pos - (unit_size / 2), unit_size, unit_size, GREEN); // center
                DrawRectangle(x_pos - (3 * (unit_size / 2)), y_pos - (unit_size / 2), unit_size, unit_size, GREEN); // left
                DrawRectangle(x_pos - (unit_size / 2), y_pos + (unit_size / 2), unit_size, unit_size, GREEN); // bottom
                DrawRectangle(x_pos - (3 * (unit_size / 2)), y_pos - (3 * (unit_size / 2)), unit_size, unit_size, GREEN); // top-right
                
                // draw center
                //DrawCircle(x_pos, y_pos, 3, RAYWHITE);
                break;
            }
        }
        case z: {
            if (rotation == north) {
                // draw squares
                DrawRectangle(x_pos - (unit_size / 2), y_pos - (unit_size / 2), unit_size, unit_size, RED); // center
                DrawRectangle(x_pos - (unit_size / 2), y_pos - (3 * (unit_size / 2)), unit_size, unit_size, RED); // top-middle
                DrawRectangle(x_pos + (unit_size / 2), y_pos - (unit_size / 2), unit_size, unit_size, RED); // right
                DrawRectangle(x_pos - (3 * (unit_size / 2)), y_pos - (3 * (unit_size / 2)), unit_size, unit_size, RED); // top-left
                
                // draw center
                //DrawCircle(x_pos, y_pos, 3, RAYWHITE);
                break;
            }
            else if (rotation == east) {
                // draw squares
                DrawRectangle(x_pos - (unit_size / 2), y_pos - (unit_size / 2), unit_size, unit_size, RED); // center
                DrawRectangle(x_pos + (unit_size / 2), y_pos - (unit_size / 2), unit_size, unit_size, RED); // right
                DrawRectangle(x_pos - (unit_size / 2), y_pos + (unit_size / 2), unit_size, unit_size, RED); // bottom
                DrawRectangle(x_pos + (unit_size / 2), y_pos - (3 * (unit_size / 2)), unit_size, unit_size, RED); // top-left
                
                // draw center
                //DrawCircle(x_pos, y_pos, 3, RAYWHITE);
                break;
            }
            else if (rotation == south) {
                // draw squares
                DrawRectangle(x_pos - (unit_size / 2), y_pos - (unit_size / 2), unit_size, unit_size, RED); // center
                DrawRectangle(x_pos - (unit_size / 2), y_pos + (unit_size / 2), unit_size, unit_size, RED); // bottom-middle
                DrawRectangle(x_pos - (3 * (unit_size / 2)), y_pos - (unit_size / 2), unit_size, unit_size, RED); // left
                DrawRectangle(x_pos + (unit_size / 2), y_pos + (unit_size / 2), unit_size, unit_size, RED); // bottom-right
                
                // draw center
                //DrawCircle(x_pos, y_pos, 3, RAYWHITE);
                break;
            }
            else if (rotation == west) {
                // draw squares
                DrawRectangle(x_pos - (unit_size / 2), y_pos - (unit_size / 2), unit_size, unit_size, RED); // center
                DrawRectangle(x_pos - (3 * (unit_size / 2)), y_pos - (unit_size / 2), unit_size, unit_size, RED); // left
                DrawRectangle(x_pos - (unit_size / 2), y_pos - (3 * (unit_size / 2)), unit_size, unit_size, RED); // top-middle
                DrawRectangle(x_pos - (3 * (unit_size / 2)), y_pos + (unit_size / 2), unit_size, unit_size, RED); // top-left
                
                // draw center
                //DrawCircle(x_pos, y_pos, 3, RAYWHITE);
                break;
            }
        }
        case l: {
            if (rotation == north) {
                // draw squares
                DrawRectangle(x_pos - (unit_size / 2), y_pos - (unit_size / 2), unit_size, unit_size, ORANGE); // center
                DrawRectangle(x_pos - (3 * (unit_size / 2)), y_pos - (unit_size / 2), unit_size, unit_size, ORANGE); // left
                DrawRectangle(x_pos + (unit_size / 2), y_pos - (unit_size / 2), unit_size, unit_size, ORANGE); // right
                DrawRectangle(x_pos + (unit_size / 2), y_pos - (3 * (unit_size / 2)), unit_size, unit_size, ORANGE); // top-right
                
                // draw center
                //DrawCircle(x_pos, y_pos, 3, RAYWHITE);
                break;
            }
            else if (rotation == east) {
                // draw squares
                DrawRectangle(x_pos - (unit_size / 2), y_pos - (unit_size / 2), unit_size, unit_size, ORANGE); // center
                DrawRectangle(x_pos - (unit_size / 2), y_pos - (3 * (unit_size / 2)), unit_size, unit_size, ORANGE); // top-middle
                DrawRectangle(x_pos - (unit_size / 2), y_pos + (unit_size / 2), unit_size, unit_size, ORANGE); // bottom-middle
                DrawRectangle(x_pos + (unit_size / 2), y_pos + (unit_size / 2), unit_size, unit_size, ORANGE); // bottom-right
                
                // draw center
                //DrawCircle(x_pos, y_pos, 3, RAYWHITE);
                break;
            }
            else if (rotation == south) {
                // draw squares
                DrawRectangle(x_pos - (unit_size / 2), y_pos - (unit_size / 2), unit_size, unit_size, ORANGE); // center
                DrawRectangle(x_pos + (unit_size / 2), y_pos - (unit_size / 2), unit_size, unit_size, ORANGE); // right
                DrawRectangle(x_pos - (3 * (unit_size / 2)), y_pos - (unit_size / 2), unit_size, unit_size, ORANGE); // left
                DrawRectangle(x_pos - (3 * (unit_size / 2)), y_pos + (unit_size / 2), unit_size, unit_size, ORANGE); // bottom-left
                
                // draw center
                //DrawCircle(x_pos, y_pos, 3, RAYWHITE);
                break;
            }
            else if (rotation == west) {
                // draw squares
                DrawRectangle(x_pos - (unit_size / 2), y_pos - (unit_size / 2), unit_size, unit_size, ORANGE); // center
                DrawRectangle(x_pos - (unit_size / 2), y_pos + (unit_size / 2), unit_size, unit_size, ORANGE); // bottom-middle
                DrawRectangle(x_pos - (unit_size / 2), y_pos - (3 * (unit_size / 2)), unit_size, unit_size, ORANGE); // top-middle
                DrawRectangle(x_pos - (3 * (unit_size / 2)), y_pos - (3 * (unit_size / 2)), unit_size, unit_size, ORANGE); // top-left
                
                // draw center
                //DrawCircle(x_pos, y_pos, 3, RAYWHITE);
                break;
            }
            
        }
        case j: {
            if (rotation == north) {
                // draw squares
                DrawRectangle(x_pos - (unit_size / 2), y_pos - (unit_size / 2), unit_size, unit_size, DARKBLUE); // center
                DrawRectangle(x_pos - (3 * (unit_size / 2)), y_pos - (unit_size / 2), unit_size, unit_size, DARKBLUE); // left
                DrawRectangle(x_pos + (unit_size / 2), y_pos - (unit_size / 2), unit_size, unit_size, DARKBLUE); // right
                DrawRectangle(x_pos - (3 * (unit_size / 2)), y_pos - (3 * (unit_size / 2)), unit_size, unit_size, DARKBLUE); // top-left
                
                // draw center
                //DrawCircle(x_pos, y_pos, 3, RAYWHITE);
                break;
            }
            else if (rotation == east) {
                // draw squares
                DrawRectangle(x_pos - (unit_size / 2), y_pos - (unit_size / 2), unit_size, unit_size, DARKBLUE); // center
                DrawRectangle(x_pos - (unit_size / 2), y_pos - (3 * (unit_size / 2)), unit_size, unit_size, DARKBLUE); // top-middle
                DrawRectangle(x_pos - (unit_size / 2), y_pos + (unit_size / 2), unit_size, unit_size, DARKBLUE); // bottom-middle
                DrawRectangle(x_pos + (unit_size / 2), y_pos - (3 * (unit_size / 2)), unit_size, unit_size, DARKBLUE); // top-right
                
                // draw center
                //DrawCircle(x_pos, y_pos, 3, RAYWHITE);
                break;
            }
            else if (rotation == south) {
                // draw squares
                DrawRectangle(x_pos - (unit_size / 2), y_pos - (unit_size / 2), unit_size, unit_size, DARKBLUE); // center
                DrawRectangle(x_pos + (unit_size / 2), y_pos - (unit_size / 2), unit_size, unit_size, DARKBLUE); // right
                DrawRectangle(x_pos - (3 * (unit_size / 2)), y_pos - (unit_size / 2), unit_size, unit_size, DARKBLUE); // left
                DrawRectangle(x_pos + (unit_size / 2), y_pos + (unit_size / 2), unit_size, unit_size, DARKBLUE); // bottom-right
                
                // draw center
                //DrawCircle(x_pos, y_pos, 3, RAYWHITE);
                break;
            }
            else if (rotation == west) {
                // draw squares
                DrawRectangle(x_pos - (unit_size / 2), y_pos - (unit_size / 2), unit_size, unit_size, DARKBLUE); // center
                DrawRectangle(x_pos - (unit_size / 2), y_pos + (unit_size / 2), unit_size, unit_size, DARKBLUE); // bottom-middle
                DrawRectangle(x_pos - (unit_size / 2), y_pos - (3 * (unit_size / 2)), unit_size, unit_size, DARKBLUE); // top-middle
                DrawRectangle(x_pos - (3 * (unit_size / 2)), y_pos + (unit_size / 2), unit_size, unit_size, DARKBLUE); // bottom-left
                
                // draw center
                //DrawCircle(x_pos, y_pos, 3, RAYWHITE);
                break;
            }
        }
        // the rotation center of the i and o pieces lay on intersections of gridlines
        case i: {
            if (rotation == north) {
                // draw squares
                DrawRectangle(x_pos - (2 * unit_size), y_pos, unit_size, unit_size, SKYBLUE); // left
                DrawRectangle(x_pos - unit_size, y_pos, unit_size, unit_size, SKYBLUE); // center-left
                DrawRectangle(x_pos, y_pos, unit_size, unit_size, SKYBLUE); // center-right
                DrawRectangle(x_pos + unit_size, y_pos, unit_size, unit_size, SKYBLUE); // right
                
                // draw center
                //DrawCircle(x_pos, y_pos + unit_size, 3, RAYWHITE);
                break;
            }
            else if (rotation == east) {
                // draw squares
                DrawRectangle(x_pos , y_pos - (2 * unit_size), unit_size, unit_size, SKYBLUE); // top
                DrawRectangle(x_pos, y_pos - unit_size, unit_size, unit_size, SKYBLUE); // center-top
                DrawRectangle(x_pos, y_pos, unit_size, unit_size, SKYBLUE); // center-bottom
                DrawRectangle(x_pos , y_pos + unit_size, unit_size, unit_size, SKYBLUE); // bottom
                
                // draw center
                //DrawCircle(x_pos, y_pos, 3, RAYWHITE);
                break;
            }
            else if (rotation == south) {
                // draw squares
                DrawRectangle(x_pos - (2 * unit_size), y_pos + unit_size, unit_size, unit_size, SKYBLUE); // left
                DrawRectangle(x_pos - unit_size, y_pos + unit_size, unit_size, unit_size, SKYBLUE); // center-left
                DrawRectangle(x_pos, y_pos + unit_size, unit_size, unit_size, SKYBLUE); // center-right
                DrawRectangle(x_pos + unit_size, y_pos + unit_size, unit_size, unit_size, SKYBLUE); // right
                
                // draw center
                //DrawCircle(x_pos, y_pos + unit_size, 3, RAYWHITE);
                break;
            }
            else if (rotation == west) {
                // draw squares
                DrawRectangle(x_pos, y_pos - (2 * unit_size), unit_size, unit_size, SKYBLUE); // top
                DrawRectangle(x_pos, y_pos - unit_size, unit_size, unit_size, SKYBLUE); // center-top
                DrawRectangle(x_pos, y_pos, unit_size, unit_size, SKYBLUE); // center-bottom
                DrawRectangle(x_pos, y_pos + unit_size, unit_size, unit_size, SKYBLUE); // bottom
                
                // draw center
                //DrawCircle(x_pos + unit_size, y_pos, 3, RAYWHITE);
                break;
            }
        }
        // o piece does not rotate
        case o: {
            // draw squares
            DrawRectangle(x_pos - unit_size, y_pos - unit_size, unit_size, unit_size, YELLOW); // top-left
            DrawRectangle(x_pos, y_pos - unit_size, unit_size, unit_size, YELLOW); // top-right
            DrawRectangle(x_pos - unit_size, y_pos, unit_size, unit_size, YELLOW); // bottom-left
            DrawRectangle(x_pos, y_pos, unit_size, unit_size, YELLOW); // bottom-right
            
            // draw center
            //DrawCircle(x_pos, y_pos, 3, RAYWHITE);
            break;
        }
        case t: {
            if (rotation == north) {
                // draw squares
                DrawRectangle(x_pos - (unit_size / 2), y_pos - (unit_size / 2), unit_size, unit_size, PURPLE); // center
                DrawRectangle(x_pos - (3 * (unit_size / 2)), y_pos - (unit_size / 2), unit_size, unit_size, PURPLE); // left
                DrawRectangle(x_pos + (unit_size / 2), y_pos - (unit_size / 2), unit_size, unit_size, PURPLE); // right
                DrawRectangle(x_pos - (unit_size / 2), y_pos - (3 * (unit_size / 2)), unit_size, unit_size, PURPLE); // top
                
                // draw center
                //DrawCircle(x_pos, y_pos, 3, RAYWHITE);
                break;
            }
            else if (rotation == east) {
                // draw squares
                DrawRectangle(x_pos - (unit_size / 2), y_pos - (unit_size / 2), unit_size, unit_size, PURPLE); // center
                DrawRectangle(x_pos - (unit_size / 2), y_pos - (3 * (unit_size / 2)), unit_size, unit_size, PURPLE); // top-middle
                DrawRectangle(x_pos - (unit_size / 2), y_pos + (unit_size / 2), unit_size, unit_size, PURPLE); // bottom-middle
                DrawRectangle(x_pos + (unit_size / 2), y_pos - (unit_size / 2), unit_size, unit_size, PURPLE); // right
                
                // draw center
                //DrawCircle(x_pos, y_pos, 3, RAYWHITE);
                break;
            }
            else if (rotation == south) {
                // draw squares
                DrawRectangle(x_pos - (unit_size / 2), y_pos - (unit_size / 2), unit_size, unit_size, PURPLE); // center
                DrawRectangle(x_pos + (unit_size / 2), y_pos - (unit_size / 2), unit_size, unit_size, PURPLE); // right
                DrawRectangle(x_pos - (3 * (unit_size / 2)), y_pos - (unit_size / 2), unit_size, unit_size, PURPLE); // left
                DrawRectangle(x_pos - (unit_size / 2), y_pos + (unit_size / 2), unit_size, unit_size, PURPLE); // bottom-middle
                
                // draw center
                //DrawCircle(x_pos, y_pos, 3, RAYWHITE);
                break;
            }
            else if (rotation == west) {
                // draw squares
                DrawRectangle(x_pos - (unit_size / 2), y_pos - (unit_size / 2), unit_size, unit_size, PURPLE); // center
                DrawRectangle(x_pos - (unit_size / 2), y_pos + (unit_size / 2), unit_size, unit_size, PURPLE); // bottom-middle
                DrawRectangle(x_pos - (unit_size / 2), y_pos - (3 * (unit_size / 2)), unit_size, unit_size, PURPLE); // top-middle
                DrawRectangle(x_pos - (3 * (unit_size / 2)), y_pos - (unit_size / 2), unit_size, unit_size, PURPLE); // left
                
                // draw center
                //DrawCircle(x_pos, y_pos, 3, RAYWHITE);
                break;
            }
        }
        default: {
            break;
        }
    }
}

void draw_board(int board_width, int board_height, int current_score, int next_piece) {
    ClearBackground(DARKGRAY);
    DrawRectangle(
    (window_width - board_width) / 2,
    (window_height - board_height) / 2,
    board_width,
    board_height,
    BLACK);
    
    DrawRectangle(
    ((window_width - board_width) / 2) + 1,
    ((window_height - board_height) / 2) + 1,
    board_width - 2,
    board_height - 2,
    LIGHTGRAY);
    
    for (int i = 1; i < 20; i++) {
        DrawLine(
        ((window_width - board_width) / 2) + 1,
        ((window_height - board_height) / 2) + (i * unit_size),
        ((window_width + board_width) / 2) - 1,
        ((window_height - board_height) / 2) + (i * unit_size),
        DARKGRAY);
    }
    for (int i = 1; i < 10; i++) {
        DrawLine(
        ((window_width - board_width) / 2) + (i * unit_size),
        ((window_height - board_height) / 2) + 1,
        ((window_width - board_width) / 2) + (i * unit_size),
        ((window_height + board_height) / 2) - 1,
        DARKGRAY);
    }
    
    // box with 14px top bezel
    DrawRectangle(
    ((window_width - board_width) / 2) - 120 - unit_size,
    ((window_height - board_height) / 2) + (17 * unit_size) - 6, 
    120, 
    60, 
    BLACK);
    
    DrawRectangle(
    ((window_width - board_width) / 2) - 120 - unit_size + 1, //171, 
    ((window_height - board_height) / 2) + (17 * unit_size) + 14 - 6,
    118,
    45,
    LIGHTGRAY);
    
    DrawText("score",
    ((window_width - board_width) / 2) - 120 - unit_size + 45,
    ((window_height - board_height) / 2) + (17 * unit_size) - 6,
    12,
    LIGHTGRAY);
    
    char score[24];
    sprintf(score, "%d", current_score);
    DrawText(score,
    ((window_width - board_width) / 2) - 120 - unit_size + 1 + 56,
    ((window_height - board_height) / 2) + (17 * unit_size) + 14 - 6 + 11,
    24,
    BLACK
    );
    
    DrawRectangle(
    ((window_width - board_width) / 2) + board_width + unit_size,
    ((window_height - board_height) / 2) + (17 * unit_size) - 6, 
    120, 
    60, 
    BLACK);
    
    DrawRectangle(
    ((window_width - board_width) / 2) + board_width + unit_size + 1, //171, 
    ((window_height - board_height) / 2) + (17 * unit_size) + 14 - 6,
    118,
    45,
    LIGHTGRAY);
    
    DrawText("next",
    ((window_width - board_width) / 2) + board_width + unit_size + 45,
    ((window_height - board_height) / 2) + (17 * unit_size) - 6,
    12,
    LIGHTGRAY);
    
    if (next_piece == 5) { // o piece spawns fine
        draw_piece(next_piece,
        ((window_width - board_width) / 2) + board_width + unit_size + 1 + 59,
        ((window_height - board_height) / 2) + (17 * unit_size) + 14 - 6 + 22,
        0);
    }
    else if (next_piece == 4) { // fix i piece spawing low
        draw_piece(next_piece,
        ((window_width - board_width) / 2) + board_width + unit_size + 1 + 59,
        ((window_height - board_height) / 2) + (17 * unit_size) + 14 - 6 + 12,
        0);
    }
    else { // all other pieces spawn too high
        draw_piece(next_piece,
        ((window_width - board_width) / 2) + board_width + unit_size + 1 + 59,
        ((window_height - board_height) / 2) + (17 * unit_size) + 14 - 6 + 31,
        0);
    }
}

struct coord get_pos (int board_width, int board_height, int piece_x, int piece_y) {
    struct coord grid;
    grid.x = (piece_x - ((window_width - board_width) / 2)) / unit_size;
    grid.y = (piece_y - ((window_height - board_height) / 2)) / unit_size;
    //printf("piece is at (%d, %d)\n", grid.x, grid.y);
    return grid;
}

void print_board(int ** board) {
    
    for (int i = 0; i < 20; i++) {
        for (int j = 0; j < 10; j++) {
            printf("%d ", board[i][j]);
        }
        printf("\n");
    }
}

void board_update(pieces piece_type, orientation piece_rotation, struct coord piece_pos, int ** board_state, int mode) {
    switch (piece_type) {
        case (s): {
            if (piece_rotation == north) {
                board_state[piece_pos.y][piece_pos.x] = mode; // center
                board_state[piece_pos.y - 1][piece_pos.x] = mode; // top-middle
                board_state[piece_pos.y][piece_pos.x - 1] = mode; // left
                board_state[piece_pos.y - 1][piece_pos.x + 1] = mode; // top-right
                //printf("north s\n");
                break;
            }
            else if (piece_rotation == east) {
                board_state[piece_pos.y][piece_pos.x] = mode; // center
                board_state[piece_pos.y][piece_pos.x + 1] = mode; // right
                board_state[piece_pos.y - 1][piece_pos.x] = mode; // top-middle
                board_state[piece_pos.y + 1][piece_pos.x + 1] = mode; // bottom-left
                //printf("east s\n");
                break;
            }
            else if (piece_rotation == south) {
                board_state[piece_pos.y][piece_pos.x] = mode; // center
                board_state[piece_pos.y + 1][piece_pos.x] = mode; // bottom-middle
                board_state[piece_pos.y][piece_pos.x + 1] = mode; // right
                board_state[piece_pos.y + 1][piece_pos.x - 1] = mode; // bottom-left
                //printf("south s\n");
                break;
            }
            else if (piece_rotation == west) {
                board_state[piece_pos.y][piece_pos.x] = mode; // center
                board_state[piece_pos.y][piece_pos.x - 1] = mode; // left
                board_state[piece_pos.y + 1][piece_pos.x] = mode; // bottom-middle
                board_state[piece_pos.y - 1][piece_pos.x - 1] = mode; // top-left
                //printf("west s\n");
                break;
            }
        }
        case (z): {
            if (piece_rotation == north) {
                board_state[piece_pos.y][piece_pos.x] = mode; // center
                board_state[piece_pos.y - 1][piece_pos.x] = mode; // top
                board_state[piece_pos.y][piece_pos.x + 1] = mode; // right
                board_state[piece_pos.y - 1][piece_pos.x - 1] = mode; // top-left
                break;
            }
            else if (piece_rotation == east) {
                board_state[piece_pos.y][piece_pos.x] = mode; // center
                board_state[piece_pos.y][piece_pos.x + 1] = mode; // right
                board_state[piece_pos.y + 1][piece_pos.x] = mode; // bottom
                board_state[piece_pos.y - 1][piece_pos.x + 1] = mode; // top-right
                break;
            }
            else if (piece_rotation == south) {
                board_state[piece_pos.y][piece_pos.x] = mode; // center
                board_state[piece_pos.y + 1][piece_pos.x] = mode; // bot
                board_state[piece_pos.y][piece_pos.x - 1] = mode; // left
                board_state[piece_pos.y + 1][piece_pos.x + 1] = mode; // bot-right
                break;
            }
            else if (piece_rotation == west) {
                board_state[piece_pos.y][piece_pos.x] = mode; // center
                board_state[piece_pos.y][piece_pos.x - 1] = mode; // left
                board_state[piece_pos.y - 1][piece_pos.x] = mode; // top
                board_state[piece_pos.y + 1][piece_pos.x - 1] = mode; // bot-left
                break;
            }
        }
        case (l): {
            if (piece_rotation == north) {
                board_state[piece_pos.y][piece_pos.x] = mode; // center
                board_state[piece_pos.y][piece_pos.x - 1] = mode; // left
                board_state[piece_pos.y][piece_pos.x + 1] = mode; // right
                board_state[piece_pos.y - 1][piece_pos.x + 1] = mode; // top-right
                break;
            }
            else if (piece_rotation == east) {
                board_state[piece_pos.y][piece_pos.x] = mode; // center
                board_state[piece_pos.y - 1][piece_pos.x] = mode; // top
                board_state[piece_pos.y + 1][piece_pos.x] = mode; // bot
                board_state[piece_pos.y + 1][piece_pos.x + 1] = mode; // bot-right
                break;
            }
            else if (piece_rotation == south) {
                board_state[piece_pos.y][piece_pos.x] = mode; // center
                board_state[piece_pos.y][piece_pos.x + 1] = mode; // right
                board_state[piece_pos.y][piece_pos.x - 1] = mode; // left
                board_state[piece_pos.y + 1][piece_pos.x - 1] = mode; // bot-left
                break;
            }
            else if (piece_rotation == west) {
                board_state[piece_pos.y][piece_pos.x] = mode; // center
                board_state[piece_pos.y + 1][piece_pos.x] = mode; // top
                board_state[piece_pos.y - 1][piece_pos.x] = mode; // bot
                board_state[piece_pos.y - 1][piece_pos.x - 1] = mode; // bot-right
                break;
            }
        }
        case (j): {
            if (piece_rotation == north) {
                board_state[piece_pos.y][piece_pos.x] = mode; // center
                board_state[piece_pos.y][piece_pos.x - 1] = mode; // left
                board_state[piece_pos.y][piece_pos.x + 1] = mode; // right
                board_state[piece_pos.y - 1][piece_pos.x - 1] = mode; // top-left
                break;
            }
            else if (piece_rotation == east) {
                board_state[piece_pos.y][piece_pos.x] = mode; // center
                board_state[piece_pos.y - 1][piece_pos.x] = mode; // top
                board_state[piece_pos.y + 1][piece_pos.x] = mode; // bot
                board_state[piece_pos.y - 1][piece_pos.x + 1] = mode; // top-right
                break;
            }
            else if (piece_rotation == south) {
                board_state[piece_pos.y][piece_pos.x] = mode; // center
                board_state[piece_pos.y][piece_pos.x + 1] = mode; // right
                board_state[piece_pos.y][piece_pos.x - 1] = mode; // left
                board_state[piece_pos.y + 1][piece_pos.x + 1] = mode; // bot-right
                break;
            }
            else if (piece_rotation == west) {
                board_state[piece_pos.y][piece_pos.x] = mode; // center
                board_state[piece_pos.y + 1][piece_pos.x] = mode; // top
                board_state[piece_pos.y - 1][piece_pos.x] = mode; // bot
                board_state[piece_pos.y + 1][piece_pos.x - 1] = mode; // top-right
                break;
            }
        }
        case (i): {
            if (piece_rotation == north) {
                board_state[piece_pos.y][piece_pos.x - 2] = mode; // left
                board_state[piece_pos.y][piece_pos.x - 1] = mode; // cen-left
                board_state[piece_pos.y][piece_pos.x] = mode; // cen-right
                board_state[piece_pos.y][piece_pos.x + 1] = mode; // right
                break;
            }
            else if (piece_rotation == east) {
                board_state[piece_pos.y - 2][piece_pos.x] = mode; // top
                board_state[piece_pos.y - 1][piece_pos.x] = mode; // top-mid
                board_state[piece_pos.y][piece_pos.x] = mode; // bot-mid
                board_state[piece_pos.y + 1][piece_pos.x] = mode; // bot
                break;
            }
            else if (piece_rotation == south) {
                board_state[piece_pos.y + 1][piece_pos.x - 2] = mode; // left
                board_state[piece_pos.y + 1][piece_pos.x - 1] = mode; // cen-left
                board_state[piece_pos.y + 1][piece_pos.x] = mode; // cen-right
                board_state[piece_pos.y + 1][piece_pos.x + 1] = mode; // right
                break;
            }
            else if (piece_rotation == west) {
                board_state[piece_pos.y - 2][piece_pos.x] = mode; // top
                board_state[piece_pos.y - 1][piece_pos.x] = mode; // top-mid
                board_state[piece_pos.y][piece_pos.x] = mode; // bot-mid
                board_state[piece_pos.y + 1][piece_pos.x] = mode; // bot
                break;
            }
        }
        case (o): {
            board_state[piece_pos.y - 1][piece_pos.x - 1] = mode; // tl
            board_state[piece_pos.y - 1][piece_pos.x] = mode; // tr
            board_state[piece_pos.y][piece_pos.x - 1] = mode; // bl
            board_state[piece_pos.y][piece_pos.x] = mode; // br
            break;
        }
        case (t): {
            if (piece_rotation == north) {
                board_state[piece_pos.y][piece_pos.x] = mode; // c
                board_state[piece_pos.y][piece_pos.x - 1] = mode; // l
                board_state[piece_pos.y][piece_pos.x + 1] = mode; // r
                board_state[piece_pos.y - 1][piece_pos.x] = mode; // t
                break;
            }
            else if (piece_rotation == east) {
                board_state[piece_pos.y][piece_pos.x] = mode; // c
                board_state[piece_pos.y - 1][piece_pos.x] = mode; // t
                board_state[piece_pos.y + 1][piece_pos.x] = mode; // b
                board_state[piece_pos.y][piece_pos.x + 1] = mode; // r
                break;
            }
            else if (piece_rotation == south) {
                board_state[piece_pos.y][piece_pos.x] = mode; // c
                board_state[piece_pos.y][piece_pos.x + 1] = mode; // r
                board_state[piece_pos.y][piece_pos.x - 1] = mode; // l
                board_state[piece_pos.y + 1][piece_pos.x] = mode; // b
                break;
            }
            else if (piece_rotation == west) {
                board_state[piece_pos.y][piece_pos.x] = mode; // c
                board_state[piece_pos.y + 1][piece_pos.x] = mode; // b
                board_state[piece_pos.y - 1][piece_pos.x] = mode; // t
                board_state[piece_pos.y][piece_pos.x - 1] = mode; // l
                break;
            }
        }
    }
    
    /*
    if (mode) {
        print_board(board_state);
    }
    */
}

bool collision (pieces piece_type, orientation piece_rotation, struct coord piece_pos, int ** board_state, int mode) {
    if (mode == 1) { // gravity
        switch (piece_type) {
            case (s): {
                if (piece_rotation == north) {
                    if (piece_pos.y == 19 ||
                    board_state[piece_pos.y + 1][piece_pos.x - 1] ||
                    board_state[piece_pos.y + 1][piece_pos.x] ||
                    board_state[piece_pos.y][piece_pos.x + 1]
                    ) { return true; }
                    else { return false; }
                    break;
                }
                else if (piece_rotation == east) {
                    if (piece_pos.y == 18 ||
                    board_state[piece_pos.y + 1][piece_pos.x] ||
                    board_state[piece_pos.y + 2][piece_pos.x + 1]
                    ) { return true; }
                    else { return false; }
                    break;
                }
                else if (piece_rotation == south) {
                    if (piece_pos.y == 18 ||
                    board_state[piece_pos.y + 2][piece_pos.x - 1] ||
                    board_state[piece_pos.y + 2][piece_pos.x] ||
                    board_state[piece_pos.y + 1][piece_pos.x + 1]
                    ) { return true; }
                    else { return false; }
                    break;
                }
                else if (piece_rotation == west) {
                    if (piece_pos.y == 18 ||
                    board_state[piece_pos.y + 1][piece_pos.x - 1] ||
                    board_state[piece_pos.y + 2][piece_pos.x]
                    ) { return true; }
                    else { return false; }
                    break;
                }
            }
            case (z): {
                if (piece_rotation == north) {
                    if (piece_pos.y == 19 ||
                    board_state[piece_pos.y][piece_pos.x - 1] ||
                    board_state[piece_pos.y + 1][piece_pos.x] ||
                    board_state[piece_pos.y + 1][piece_pos.x + 1]
                    ) { return true; }
                    else { return false; }
                    break;
                }
                else if (piece_rotation == east) {
                    if (piece_pos.y == 18 ||
                    board_state[piece_pos.y + 2][piece_pos.x] ||
                    board_state[piece_pos.y + 1][piece_pos.x + 1]
                    ) { return true; }
                    else { return false; }
                    break;
                }
                else if (piece_rotation == south) {
                    if (piece_pos.y == 18 ||
                    board_state[piece_pos.y + 1][piece_pos.x - 1] ||
                    board_state[piece_pos.y + 2][piece_pos.x] ||
                    board_state[piece_pos.y + 2][piece_pos.x + 1]
                    ) { return true; }
                    else { return false; }
                    break;
                }
                else if (piece_rotation == west) {
                    if (piece_pos.y == 18 ||
                    board_state[piece_pos.y + 2][piece_pos.x - 1] ||
                    board_state[piece_pos.y + 1][piece_pos.x]
                    ) { return true; }
                    else { return false; }
                    break;
                }
            }
            case (l): {
                if (piece_rotation == north) {
                    if (piece_pos.y == 19 ||
                    board_state[piece_pos.y + 1][piece_pos.x - 1] ||
                    board_state[piece_pos.y + 1][piece_pos.x] ||
                    board_state[piece_pos.y + 1][piece_pos.x + 1]
                    ) { return true; }
                    else { return false; }
                    break;
                }
                else if (piece_rotation == east) {
                    if (piece_pos.y == 18 ||
                    board_state[piece_pos.y + 2][piece_pos.x] ||
                    board_state[piece_pos.y + 2][piece_pos.x + 1]
                    ) { return true; }
                    else { return false; }
                    break;
                }
                else if (piece_rotation == south) {
                    if (piece_pos.y == 18 ||
                    board_state[piece_pos.y + 2][piece_pos.x - 1] ||
                    board_state[piece_pos.y + 1][piece_pos.x] ||
                    board_state[piece_pos.y + 1][piece_pos.x + 1]
                    ) { return true; }
                    else { return false; }
                    break;
                }
                else if (piece_rotation == west) {
                    if (piece_pos.y == 18 ||
                    board_state[piece_pos.y][piece_pos.x - 1] ||
                    board_state[piece_pos.y + 2][piece_pos.x]
                    ) { return true; }
                    else { return false; }
                    break;
                }
            }
            case (j): {
                if (piece_rotation == north) {
                    if (piece_pos.y == 19 ||
                    board_state[piece_pos.y + 1][piece_pos.x - 1] ||
                    board_state[piece_pos.y + 1][piece_pos.x] ||
                    board_state[piece_pos.y + 1][piece_pos.x + 1]
                    ) { return true; }
                    else { return false; }
                    break;
                }
                else if (piece_rotation == east) {
                    if (piece_pos.y == 18 ||
                    board_state[piece_pos.y + 2][piece_pos.x] ||
                    board_state[piece_pos.y][piece_pos.x + 1]
                    ) { return true; }
                    else { return false; }
                    break;
                }
                else if (piece_rotation == south) {
                    if (piece_pos.y == 18 ||
                    board_state[piece_pos.y + 1][piece_pos.x - 1] ||
                    board_state[piece_pos.y + 1][piece_pos.x] ||
                    board_state[piece_pos.y + 2][piece_pos.x + 1]
                    ) { return true; }
                    else { return false; }
                    break;
                }
                else if (piece_rotation == west) {
                    if (piece_pos.y == 18 ||
                    board_state[piece_pos.y + 2][piece_pos.x - 1] ||
                    board_state[piece_pos.y + 2][piece_pos.x]
                    ) { return true; }
                    else { return false; }
                    break;
                }
            }
            case (i): {
                if (piece_rotation == north) {
                    if (piece_pos.y == 19 ||
                    board_state[piece_pos.y + 1][piece_pos.x - 2] ||
                    board_state[piece_pos.y + 1][piece_pos.x - 1] ||
                    board_state[piece_pos.y + 1][piece_pos.x] ||
                    board_state[piece_pos.y + 1][piece_pos.x + 1]
                    ) { return true; }
                    else { return false; }
                    break;
                }
                else if (piece_rotation == east) {
                    if (piece_pos.y == 18 ||
                    board_state[piece_pos.y + 2][piece_pos.x]
                    ) { return true; }
                    else { return false; }
                    break;
                }
                else if (piece_rotation == south) {
                    if (piece_pos.y == 18 ||
                    board_state[piece_pos.y + 1][piece_pos.x - 2] ||
                    board_state[piece_pos.y + 1][piece_pos.x - 1] ||
                    board_state[piece_pos.y + 1][piece_pos.x] ||
                    board_state[piece_pos.y + 1][piece_pos.x + 1]
                    ) { return true; }
                    else { return false; }
                    break;
                }
                else if (piece_rotation == west) {
                    if (piece_pos.y == 18 ||
                    board_state[piece_pos.y + 2][piece_pos.x]
                    ) { return true; }
                    else { return false; }
                    break;
                }
            }
            case (o): {
                if (piece_pos.y == 19 ||
                    board_state[piece_pos.y + 1][piece_pos.x - 1] ||
                    board_state[piece_pos.y + 1][piece_pos.x]
                    ) { return true; }
                    else { return false; }
                    break;
            }
            case (t): {
                if (piece_rotation == north) {
                    if (piece_pos.y == 19 ||
                    board_state[piece_pos.y + 1][piece_pos.x - 1] ||
                    board_state[piece_pos.y + 1][piece_pos.x] ||
                    board_state[piece_pos.y + 1][piece_pos.x + 1]
                    ) { return true; }
                    else { return false; }
                    break;
                }
                else if (piece_rotation == east) {
                    if (piece_pos.y == 18 ||
                    board_state[piece_pos.y + 2][piece_pos.x] ||
                    board_state[piece_pos.y + 1][piece_pos.x + 1]
                    ) { return true; }
                    else { return false; }
                    break;
                }
                else if (piece_rotation == south) {
                    if (piece_pos.y == 18 ||
                    board_state[piece_pos.y + 1][piece_pos.x - 1] ||
                    board_state[piece_pos.y + 2][piece_pos.x] ||
                    board_state[piece_pos.y + 1][piece_pos.x + 1]
                    ) { return true; }
                    else { return false; }
                    break;
                }
                else if (piece_rotation == west) {
                    if (piece_pos.y == 18 ||
                    board_state[piece_pos.y + 1][piece_pos.x - 1] ||
                    board_state[piece_pos.y + 2][piece_pos.x]
                    ) { return true; }
                    else { return false; }
                    break;
                }
            }
        }
    }
    else if (mode == 2) { // player movement, left
        switch (piece_type) {
            case (s): {
                if (piece_rotation == north) {
                    if ((piece_pos.x == 1 || // left wall
                    board_state[piece_pos.y - 1][piece_pos.x] ||
                    board_state[piece_pos.y][piece_pos.x - 2])
                    ) { return true; }
                    else { return false; }
                    break;
                }
                else if (piece_rotation == east) {
                    if (piece_pos.x == 0 || // left wall
                    board_state[piece_pos.y - 1][piece_pos.x - 1] ||
                    board_state[piece_pos.y][piece_pos.x - 1] ||
                    board_state[piece_pos.y + 1][piece_pos.x]
                    ) { return true; }
                    else { return false; }
                    break;
                }
                else if (piece_rotation == south) {
                    if (piece_pos.x == 1 || // left wall
                    board_state[piece_pos.y][piece_pos.x - 1] ||
                    board_state[piece_pos.y][piece_pos.x - 2]
                    ) { return true; }
                    else { return false; }
                    break;
                }
                else if (piece_rotation == west) {
                    if (piece_pos.x == 1 || // left wall
                    board_state[piece_pos.y - 1][piece_pos.x - 2] ||
                    board_state[piece_pos.y][piece_pos.x - 2] ||
                    board_state[piece_pos.y + 1][piece_pos.x - 1]
                    ) { return true; }
                    else { return false; }
                    break;
                }
            }
            case (z): {
                if (piece_rotation == north) {
                    if (piece_pos.x == 1 || // left wall
                    board_state[piece_pos.y - 1][piece_pos.x - 2] ||
                    board_state[piece_pos.y][piece_pos.x - 1]
                    ) { return true; }
                    else { return false; }
                    break;
                }
                else if (piece_rotation == east) {
                    if (piece_pos.x == 0 || // left wall
                    board_state[piece_pos.y - 1][piece_pos.x] ||
                    board_state[piece_pos.y][piece_pos.x - 1] ||
                    board_state[piece_pos.y + 1][piece_pos.x - 1]
                    ) { return true; }
                    else { return false; }
                    break;
                }
                else if (piece_rotation == south) {
                    if (piece_pos.x == 1 || // left wall
                    board_state[piece_pos.y][piece_pos.x - 2] ||
                    board_state[piece_pos.y + 1][piece_pos.x - 1]
                    ) { return true; }
                    else { return false; }
                    
                    break;
                }
                else if (piece_rotation == west) {
                    if (piece_pos.x == 1 || // left wall
                    board_state[piece_pos.y - 1][piece_pos.x] ||
                    board_state[piece_pos.y][piece_pos.x - 2] ||
                    board_state[piece_pos.y + 1][piece_pos.x - 2]
                    ) { return true; }
                    else { return false; }
                    break;
                }
            }
            case (l): {
                if (piece_rotation == north) {
                    if (piece_pos.x == 1 ||
                    board_state[piece_pos.y - 1][piece_pos.x] ||
                    board_state[piece_pos.y][piece_pos.x - 2]
                    ) { return true; }
                    else { return false; }
                    break;
                }
                else if (piece_rotation == east) {
                    if (piece_pos.x == 0 ||
                    board_state[piece_pos.y - 1][piece_pos.x - 1] ||
                    board_state[piece_pos.y][piece_pos.x - 1] ||
                    board_state[piece_pos.y + 1][piece_pos.x - 1]
                    ) { return true; }
                    else { return false; }
                    break;
                }
                else if (piece_rotation == south) {
                    if (piece_pos.x == 1 ||
                    board_state[piece_pos.y][piece_pos.x - 2] ||
                    board_state[piece_pos.y + 1][piece_pos.x]
                    ) { return true; }
                    else { return false; }
                    break;
                }
                else if (piece_rotation == west) {
                    if (piece_pos.x == 1 ||
                    board_state[piece_pos.y - 1][piece_pos.x - 2] ||
                    board_state[piece_pos.y][piece_pos.x - 1] ||
                    board_state[piece_pos.y + 1][piece_pos.x - 1]
                    ) { return true; }
                    else { return false; }
                    break;
                }
            }
            case (j): {
                if (piece_rotation == north) {
                    if (piece_pos.x == 1 ||
                    board_state[piece_pos.y - 1][piece_pos.x - 2] ||
                    board_state[piece_pos.y][piece_pos.x - 2]
                    ) { return true; }
                    else { return false; }
                    break;
                }
                else if (piece_rotation == east) {
                    if (piece_pos.x == 0 ||
                    board_state[piece_pos.y - 1][piece_pos.x - 1] ||
                    board_state[piece_pos.y][piece_pos.x - 1] ||
                    board_state[piece_pos.y + 1][piece_pos.x - 1]
                    ) { return true; }
                    else { return false; }
                    break;
                }
                else if (piece_rotation == south) {
                    if (piece_pos.x == 1 ||
                    board_state[piece_pos.y][piece_pos.x - 2] ||
                    board_state[piece_pos.y + 1][piece_pos.x]
                    ) { return true; }
                    else { return false; }
                    break;
                }
                else if (piece_rotation == west) {
                    if (piece_pos.x == 1 ||
                    board_state[piece_pos.y - 1][piece_pos.x - 1] ||
                    board_state[piece_pos.y][piece_pos.x - 1] ||
                    board_state[piece_pos.y + 1][piece_pos.x - 2]
                    ) { return true; }
                    else { return false; }
                    break;
                }
            }
            case (i): {
                if (piece_rotation == north) {
                    if (piece_pos.x == 2 ||
                    board_state[piece_pos.y][piece_pos.x - 2]) { return true; }
                    else { return false; }
                    break;
                }
                else if (piece_rotation == east) {
                    if (piece_pos.x == 0 ||
                    board_state[piece_pos.y - 2][piece_pos.x - 1] ||
                    board_state[piece_pos.y - 1][piece_pos.x - 1] ||
                    board_state[piece_pos.y][piece_pos.x - 1] ||
                    board_state[piece_pos.y + 1][piece_pos.x - 1]) { return true; }
                    else { return false; }
                    break;
                }
                else if (piece_rotation == south) {
                    if (piece_pos.x == 2 ||
                    board_state[piece_pos.y + 1][piece_pos.x - 2]) { return true; }
                    else { return false; }
                    break;
                }
                else if (piece_rotation == west) {
                    if (piece_pos.x == 0 ||
                    board_state[piece_pos.y - 2][piece_pos.x - 1] ||
                    board_state[piece_pos.y - 1][piece_pos.x - 1] ||
                    board_state[piece_pos.y][piece_pos.x - 1] ||
                    board_state[piece_pos.y + 1][piece_pos.x - 1]) { return true; }
                    else { return false; }
                    break;
                }
            }
            case (o): {
                if (piece_pos.x == 1) { return true; }
                else { return false; }
                break;
            }
            case (t): {
                if (piece_rotation == north) {
                    if (piece_pos.x == 1 ||
                    board_state[piece_pos.y - 1][piece_pos.x - 1] ||
                    board_state[piece_pos.y][piece_pos.x - 2]
                    ) { return true; }
                    else { return false; }
                    break;
                }
                else if (piece_rotation == east) {
                    if (piece_pos.x == 0 ||
                    board_state[piece_pos.y - 1][piece_pos.x - 1] ||
                    board_state[piece_pos.y][piece_pos.x - 1] ||
                    board_state[piece_pos.y][piece_pos.x - 1]
                    ) { return true; }
                    else { return false; }
                    break;
                }
                else if (piece_rotation == south) {
                    if (piece_pos.x == 1 ||
                    board_state[piece_pos.y][piece_pos.x - 2] ||
                    board_state[piece_pos.y + 1][piece_pos.x - 1]
                    ) { return true; }
                    else { return false; }
                    break;
                }
                else if (piece_rotation == west) {
                    if (piece_pos.x == 1 ||
                    board_state[piece_pos.y - 1][piece_pos.x - 1] ||
                    board_state[piece_pos.y][piece_pos.x - 2] ||
                    board_state[piece_pos.y][piece_pos.x - 1]
                    ) { return true; }
                    else { return false; }
                    break;
                }
            }
        }
    }   
    else if (mode == 3) { // player movement, right
        switch (piece_type) {
            case (s): {
                if (piece_rotation == north) {
                    if (piece_pos.x == 8 || // right wall
                    board_state[piece_pos.y - 1][piece_pos.x + 2] ||
                    board_state[piece_pos.y][piece_pos.x + 1]
                    ) { return true; }
                    else { return false; }
                    break;
                }
                else if (piece_rotation == east) {
                    if (piece_pos.x == 8 || // left wall
                    board_state[piece_pos.y - 1][piece_pos.x + 1] ||
                    board_state[piece_pos.y][piece_pos.x + 2] ||
                    board_state[piece_pos.y + 1][piece_pos.x + 2]
                    ) { return true; }
                    else { return false; }
                    break;
                }
                else if (piece_rotation == south) {
                    if (piece_pos.x == 8 || // left wall
                    board_state[piece_pos.y][piece_pos.x + 2] ||
                    board_state[piece_pos.y + 1][piece_pos.x + 1]
                    ) { return true; }
                    else { return false; }
                    break;
                }
                else if (piece_rotation == west) {
                    if (piece_pos.x == 9 || // left wall
                    board_state[piece_pos.y - 1][piece_pos.x] ||
                    board_state[piece_pos.y][piece_pos.x + 1] ||
                    board_state[piece_pos.y + 1][piece_pos.x + 1]
                    ) { return true; }
                    else { return false; }
                    break;
                }
            }
            case (z): {
                if (piece_rotation == north) {
                    if (piece_pos.x == 8 || // left wall
                    board_state[piece_pos.y - 1][piece_pos.x + 1] ||
                    board_state[piece_pos.y][piece_pos.x + 2]
                    ) { return true; }
                    else { return false; }
                    break;
                }
                else if (piece_rotation == east) {
                    if (piece_pos.x == 8 || // left wall
                    board_state[piece_pos.y - 1][piece_pos.x + 2] ||
                    board_state[piece_pos.y][piece_pos.x + 2] ||
                    board_state[piece_pos.y + 1][piece_pos.x + 1]
                    ) { return true; }
                    else { return false; }
                    break;
                }
                else if (piece_rotation == south) {
                    if (piece_pos.x == 8 || // left wall
                    board_state[piece_pos.y][piece_pos.x + 1] ||
                    board_state[piece_pos.y + 1][piece_pos.x + 2]
                    ) { return true; }
                    else { return false; }
                    break;
                }
                else if (piece_rotation == west) {
                    if (piece_pos.x == 9 || // left wall
                    board_state[piece_pos.y - 1][piece_pos.x + 1] ||
                    board_state[piece_pos.y][piece_pos.x + 1] ||
                    board_state[piece_pos.y + 1][piece_pos.x]
                    ) { return true; }
                    else { return false; }
                    break;
                }
            }
            case (l): {
                if (piece_rotation == north) {
                    if (piece_pos.x == 8 ||
                    board_state[piece_pos.y - 1][piece_pos.x + 2] ||
                    board_state[piece_pos.y][piece_pos.x + 2]
                    ) { return true; }
                    else { return false; }
                    break;
                }
                else if (piece_rotation == east) {
                    if (piece_pos.x == 8 ||
                    board_state[piece_pos.y - 1][piece_pos.x + 1] ||
                    board_state[piece_pos.y][piece_pos.x + 1] ||
                    board_state[piece_pos.y + 1][piece_pos.x + 2]
                    ) { return true; }
                    else { return false; }
                    break;
                }
                else if (piece_rotation == south) {
                    if (piece_pos.x == 8 ||
                    board_state[piece_pos.y][piece_pos.x + 2] ||
                    board_state[piece_pos.y + 1][piece_pos.x]
                    ) { return true; }
                    else { return false; }
                    break;
                }
                else if (piece_rotation == west) {
                    if (piece_pos.x == 9 ||
                    board_state[piece_pos.y - 1][piece_pos.x + 1] ||
                    board_state[piece_pos.y][piece_pos.x + 1] ||
                    board_state[piece_pos.y + 1][piece_pos.x + 1]
                    ) { return true; }
                    else { return false; }
                    break;
                }
            }
            case (j): {
                if (piece_rotation == north) {
                    if (piece_pos.x == 8 ||
                    board_state[piece_pos.y - 1][piece_pos.x] ||
                    board_state[piece_pos.y][piece_pos.x + 2]
                    ) { return true; }
                    else { return false; }
                    break;
                }
                else if (piece_rotation == east) {
                    if (piece_pos.x == 8 ||
                    board_state[piece_pos.y - 1][piece_pos.x + 2] ||
                    board_state[piece_pos.y][piece_pos.x + 1] ||
                    board_state[piece_pos.y + 1][piece_pos.x + 1]
                    ) { return true; }
                    else { return false; }
                    break;
                }
                else if (piece_rotation == south) {
                    if (piece_pos.x == 8 ||
                    board_state[piece_pos.y][piece_pos.x + 2] ||
                    board_state[piece_pos.y + 1][piece_pos.x + 2]
                    ) { return true; }
                    else { return false; }
                    break;
                }
                else if (piece_rotation == west) {
                    if (piece_pos.x == 9 ||
                    board_state[piece_pos.y - 1][piece_pos.x + 1] ||
                    board_state[piece_pos.y][piece_pos.x + 1] ||
                    board_state[piece_pos.y + 1][piece_pos.x + 1]
                    ) { return true; }
                    else { return false; }
                    break;
                }
            }
            case (i): {
                if (piece_rotation == north) {
                    if (piece_pos.x == 8 ||
                    board_state[piece_pos.y][piece_pos.x + 2]) { return true; }
                    else { return false; }
                    break;
                }
                else if (piece_rotation == east) {
                    if (piece_pos.x == 9 ||
                    board_state[piece_pos.y - 2][piece_pos.x + 1] ||
                    board_state[piece_pos.y - 1][piece_pos.x + 1] ||
                    board_state[piece_pos.y][piece_pos.x + 1] ||
                    board_state[piece_pos.y + 1][piece_pos.x + 1]) { return true; }
                    else { return false; }
                    break;
                }
                else if (piece_rotation == south) {
                    if (piece_pos.x == 9 ||
                    board_state[piece_pos.y + 1][piece_pos.x + 2]) { return true; }
                    else { return false; }
                    break;
                }
                else if (piece_rotation == west) {
                    if (piece_pos.x == 9 ||
                    board_state[piece_pos.y - 2][piece_pos.x + 1] ||
                    board_state[piece_pos.y - 1][piece_pos.x + 1] ||
                    board_state[piece_pos.y][piece_pos.x + 1] ||
                    board_state[piece_pos.y + 1][piece_pos.x + 1]) { return true; }
                    else { return false; }
                    break;
                }
            }
            case (o): {
                if (piece_pos.x == 9) { return true; }
                else { return false; }
                break;
            }
            case (t): {
                if (piece_rotation == north) {
                    if (piece_pos.x == 8 ||
                    board_state[piece_pos.y - 1][piece_pos.x + 1] ||
                    board_state[piece_pos.y][piece_pos.x + 2]
                    ) { return true; }
                    else { return false; }
                    break;
                }
                else if (piece_rotation == east) {
                    if (piece_pos.x == 8 ||
                    board_state[piece_pos.y - 1][piece_pos.x + 1] ||
                    board_state[piece_pos.y][piece_pos.x + 2] ||
                    board_state[piece_pos.y][piece_pos.x + 1]
                    ) { return true; }
                    else { return false; }
                    break;
                }
                else if (piece_rotation == south) {
                    if (piece_pos.x == 8 ||
                    board_state[piece_pos.y][piece_pos.x + 2] ||
                    board_state[piece_pos.y + 1][piece_pos.x + 1]
                    ) { return true; }
                    else { return false; }
                    break;
                }
                else if (piece_rotation == west) {
                    if (piece_pos.x == 9 ||
                    board_state[piece_pos.y - 1][piece_pos.x + 1] ||
                    board_state[piece_pos.y][piece_pos.x + 1] ||
                    board_state[piece_pos.y][piece_pos.x + 1]
                    ) { return true; }
                    else { return false; }
                    break;
                }
            }
        }
    }
    return false;
}

int keypresses(int * piece_pos, int * piece_rotation) {
    // key flags, 1 when pressed, 0 when released
    static int left_flag = 0;
    static int right_flag = 0;
    static int up_flag = 0;
    static int down_flag = 0;
    static int ccw_flag = 0;
    static int cw_flag = 0;
    int keypressed = 0;
    
    // check cardinal directions for inputs
    if (!IsKeyDown(KEY_LEFT)) {
        left_flag = 0;
    }
    else if (IsKeyDown(KEY_LEFT)) {
        if (!left_flag) { // prevent movement each frame
            // do something
            //*piece_pos -= unit_size;
            left_flag = 1;
            keypressed = 2;
        }
    }
    
    if (!IsKeyDown(KEY_RIGHT)) {
        right_flag = 0;
    }
    else if (IsKeyDown(KEY_RIGHT)) {
        if (!right_flag) { // prevent movement each frame
            // do something
            //*piece_pos += unit_size;
            right_flag = 1;
            keypressed = 3;
        }
    }

    if (!IsKeyDown(KEY_UP)) {
        up_flag = 0;
    }
    else if (IsKeyDown(KEY_UP)) {
        if (!up_flag) { // prevent movement each frame
            // do something
            up_flag = 1;
        }
    }
    
    if (!IsKeyDown(KEY_DOWN)) {
        down_flag = 0;
    }
    else if (IsKeyDown(KEY_DOWN)) {
        if (!down_flag) { // prevent movement each frame
            // do something
            down_flag = 1;
        }
    }
    
    // check for rotation inputs
    if (!IsKeyDown(KEY_Z)) {
        ccw_flag = 0;
    }
    else if (IsKeyDown(KEY_Z)) {
        if (!ccw_flag) {
            // ccw rotation
            switch (*piece_rotation) {
                case 0: {
                    *piece_rotation = 3;
                    break;
                }
                case 1: {
                    *piece_rotation = 0;
                    break;
                }
                case 2: {
                    *piece_rotation = 1;
                    break;
                }
                case 3: {
                    *piece_rotation = 2;
                    break;
                }
                default: {
                    break;
                }
            }
            ccw_flag = 1;
            keypressed = 6;
        }
    }
    
    if (!IsKeyDown(KEY_X)) {
        cw_flag = 0;
    }
    else if (IsKeyDown(KEY_X)) {
        if (!cw_flag) {
            // cw rotation
            switch (*piece_rotation) {
                case 0: {
                    *piece_rotation = 1;
                    break;
                }
                case 1: {
                    *piece_rotation = 2;
                    break;
                }
                case 2: {
                    *piece_rotation = 3;
                    break;
                }
                case 3: {
                    *piece_rotation = 0;
                    break;
                }
                default: {
                    break;
                }
            }
            cw_flag = 1;
            keypressed = 7;
        }
    }
    
    return keypressed;
}

void move_piece(int keyop, int * piece_pos, int * piece_rotation) {
    if (keyop == 2) {
        * piece_pos -= unit_size;
    }
    else if (keyop == 3) {
        * piece_pos += unit_size;
    }
}

int clear (int ** board_state) {
    for (int i = 0; i < 20; i++) {
        for (int j = 0; j < 10; j++) {
            board_state[i][j] = 0;
        }
    }
    return 0;
}

int get_score (int ** board_state, int target_line) {
    int score = (20 - target_line);
    for (int i = 19; i >= target_line; i--) {
        for (int j = 0; j < 10; j++) {
            if (board_state[i][j] == 0) {
                score--;
            }
        }
    }
    
    if (score <= 0) {
        return 0;
    }
    else { 
        return score; 
    }
    
}

int main (void) {
    // draw parent window
    InitWindow(window_width, window_height, "raytris");
    Image image = LoadImage("images/Bird.jpg");
    Texture2D texture = LoadTextureFromImage(image);
    UnloadImage(image);
    
    // title screen variable
    bool title_screen = true;
    
    // board sizing
    int ** board; // board[rows][cols], 20x10
    board = (int**)malloc(sizeof(int*) * 20);
    for (int i = 0; i < 20; i++) {
        board[i] = (int*)malloc(sizeof(int) * 10);
    }
    
    for (int i = 0; i < 20; i++) {
        for (int j = 0; i < 10; i++) {
            board[i][j] = 0;
        }
    }
    
    int target_line = 16;
    
    int score = 0;
    
    // piece attributes
    int * piece_x = (int*)malloc(sizeof(int));
    * piece_x = ((window_width - (unit_size * 10)) / 2) + (4 * unit_size) + (unit_size / 2);
    int * piece_y = (int*)malloc(sizeof(int));
    * piece_y = ((window_height - (unit_size * 20)) / 2) + (unit_size / 2) + (2 * unit_size);
    int * piece_rotation = (int*)malloc(sizeof(int));
    * piece_rotation = 0;
    struct coord * piece_coord = (struct coord *)malloc(sizeof(struct coord) * 2);
    int piece_flag = 0;
    int piece = GetRandomValue(0, 6);
    int next_piece = GetRandomValue(0, 6);
    int bag[7] = {0, 0, 0, 0, 0, 0, 0};
    int bag_picked = 0;
    bag[piece]++;
    bag[next_piece]++;
    bag_picked += 2;
    bool get_new_piece = false;
    
    // extras
    int keyop;
    struct piece_info prev_pieces[100];
    int piece_count = 0;
    
    // frame setup
    int frame_count = 0;
    SetTargetFPS(60);
    
    /* todo
    boundary detections (rotations)
    lose condition
    */
    
    while(!WindowShouldClose()) {
        BeginDrawing();
        while (title_screen) {
            ClearBackground(RAYWHITE);
            DrawRectangle(window_width - 80, window_height - 80, 64, 64, BLACK);
            DrawRectangle(window_width - 76, window_height - 76, 56, 56, RAYWHITE);
            DrawText("raylib", window_width - 54, window_height - 34, 12, BLACK);
            DrawText("powered by:", window_width - 80, window_height - 92, 10, LIGHTGRAY);
            DrawText("Press enter to start.", (window_width / 2) - (12 * 5), window_height - 28, 12, DARKGRAY);
            DrawText("r", (window_width / 2) - 105, (window_height / 2), 40, RED);
            DrawText("a", (window_width / 2) - 70, (window_height / 2), 40, ORANGE);
            DrawText("y", (window_width / 2) - 35, (window_height / 2), 40, YELLOW);
            DrawText("t", (window_width / 2), (window_height / 2), 40, GREEN);
            DrawText("r", (window_width / 2) + 35, (window_height / 2), 40, DARKBLUE);
            DrawText("i", (window_width / 2) + 70, (window_height / 2), 40, SKYBLUE);
            DrawText("s", (window_width / 2) + 105, (window_height / 2), 40, PURPLE);
            DrawTexture(texture, 10, (window_height - 16) - 34, WHITE);
            if (IsKeyDown(KEY_ENTER)) {
                title_screen = false;
            }
            EndDrawing();
            continue;
        }
        if (get_new_piece) {
            prev_pieces[piece_count].piece = piece;
            prev_pieces[piece_count].x_pos = *piece_x;
            prev_pieces[piece_count].y_pos = *piece_y;
            prev_pieces[piece_count].rotation = *piece_rotation;
            piece_count++;
            piece = next_piece;
            next_piece = GetRandomValue(0, 6);
            if (bag_picked == 7) {
                for (int i = 0; i < 7; i++) {
                    bag[i] = 0;
                    bag_picked = 0;
                }
            }
            while (bag[next_piece] == 1) {
                next_piece = GetRandomValue(0, 6);
            }
            bag_picked++;
            bag[next_piece] = 1;
            for (int i = 0; i < 10; i++) {
                if (board[target_line - 1][i] == 1) {
                    score += get_score(board, target_line); // add call to score function
                    //printf("score: %d\n", score);
                    piece_count = clear(board);
                    target_line = GetRandomValue(4, 16);
                    while (target_line % 2) {
                        target_line = GetRandomValue(4, 16);
                    }
                }
            }
            * piece_rotation = 0;
            * piece_x = ((window_width - (unit_size * 10)) / 2) + (4 * unit_size) + (unit_size / 2);
            * piece_y = ((window_height - (unit_size * 20)) / 2) + (unit_size / 2) + (2 * unit_size);
            * piece_coord = get_pos(unit_size * 10, unit_size * 20, *piece_x, *piece_y);
            piece_flag = 0;
            get_new_piece = false;
        }
        if (frame_count) {
            //printf("a\n");
            board_update(piece, *piece_rotation, *piece_coord, board, 0);
        }
        draw_board(unit_size * 10, unit_size * 20, score, next_piece);
        DrawLine((window_width - (unit_size * 10)) / 2, ((window_height - (unit_size * 20)) / 2) + (target_line * unit_size), (window_width + (unit_size * 10)) / 2, ((window_height - (unit_size * 20)) / 2) + (target_line * unit_size), MAROON);
        if ((piece == 4 || piece == 5) && !piece_flag) {
            *piece_x += (unit_size / 2);
            *piece_y += (unit_size / 2);
            piece_flag = 1;
        }
        else if (!(piece == 4 || piece == 5)) {
            piece_flag = 0;
        }
        keyop = keypresses(piece_x, piece_rotation); // player movement
        if (!collision(piece, * piece_rotation, * piece_coord, board, keyop)) {
            move_piece(keyop, piece_x, piece_rotation);
        }
        if (piece_count == 0) {
            draw_piece(piece, *piece_x, *piece_y, *piece_rotation);
        } 
        else { 
            for (int i = 0; i < piece_count; i++) {
                draw_piece(prev_pieces[i].piece, prev_pieces[i].x_pos, prev_pieces[i].y_pos, prev_pieces[i].rotation);
                draw_piece(piece, *piece_x, *piece_y, *piece_rotation);
            }
        }
        *piece_coord = get_pos(unit_size * 10, unit_size * 20, *piece_x, *piece_y);
        frame_count++;
        if (!(frame_count % 10)) { // gravity
        get_new_piece = collision(piece, * piece_rotation, * piece_coord, board, 1);
        if (!get_new_piece) {
            *piece_y += unit_size;
        }
        //printf("piece is at (%d, %d)\n", piece_coord->x, piece_coord->y);
        board_update(piece, *piece_rotation, *piece_coord, board, 1);
        }
        EndDrawing();
    }
    
    CloseWindow();
    
    // free allocated memory
    free(piece_x);
    free(piece_y);
    free(piece_rotation);
    for (int i = 0; i < 20; i++) {
        free(board[i]);
    }
    free(board);
    free(piece_coord);
    UnloadTexture(texture);
    return 0;
}