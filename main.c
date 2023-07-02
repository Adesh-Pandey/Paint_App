//
//  main.c
//  paint
//
//  Created by Adesh Pandey on 01/07/2023.
//

#include <stdio.h>
#include <SDL2/SDL.h>

int main(int argc, const char * argv[]) {
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        printf("SDL initialization failed: %s\n", SDL_GetError());
        return 1;
    }

    // Create a window and renderer
    SDL_Window* window = SDL_CreateWindow("Rectangle Example", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 1000, 800, 0);
    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    

    // Set the drawing color (red in this example)
//    SDL_SetRenderDrawColor(renderer, 135, 26, 218, 255);

    // Clear the renderer with the specified color
    SDL_RenderClear(renderer);
    SDL_SetRenderDrawColor(renderer, 135, 26, 218, 255);
    
    // Define the rectangle's dimensions and position
    int rectX = 300;
    int rectY = 200;
    int rectWidth = 200;
    int rectHeight = 150;

    // Create a rectangle using SDL_Rect structure
    SDL_Rect rectangle;
    rectangle.x = rectX;
    rectangle.y = rectY;
    rectangle.w = rectWidth;
    rectangle.h = rectHeight;

    // Draw the rectangle on the renderer
    SDL_RenderFillRect(renderer, &rectangle);

    // Present the renderer
    SDL_RenderPresent(renderer);
    SDL_RenderClear(renderer);

    // Event loop to handle window events
    SDL_Event event;
    int quit = 0;
//    int isDrawing = 0;
//    int prevMouseX = 0, prevMouseY = 0;
    while (!quit) {
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                // Quit the application when the window is closed
                quit = 1;
                break;
            }
//            if(event.type==SDL_MOUSEBUTTONDOWN){
//                mouseDown=1;
//            }
//            if(event.type==SDL_MOUSEBUTTONUP){
//                mouseDown=0;
//            }
            
            if(event.type==SDL_MOUSEMOTION){
                int mouseX;
                int mouseY;
                SDL_GetMouseState(&mouseX,&mouseY);

                printf("x=%d and y=%d \n",mouseX,mouseY);

                SDL_SetRenderDrawColor(renderer,177,177,255,1);
//                SDL_RenderDrawPoint(renderer,mouseX,mouseY);
//                SDL_RenderPresent(renderer);
                SDL_Rect rect;
                rect.x = mouseX;
                rect.y = mouseY;
                rect.w = 20;
                rect.h = 20;

                // Draw the rectangle on the renderer
                SDL_RenderFillRect(renderer, &rect);
//                SDL_RenderDrawPoint(renderer, mouseX,mouseY);
                SDL_RenderPresent(renderer);
            }else{
                SDL_RenderPresent(renderer);
            }
            SDL_SetRenderDrawColor(renderer,0,0,0,1);
            
            SDL_RenderClear(renderer);
//            if (event.type == SDL_MOUSEBUTTONDOWN) {
//                if (event.button.button == SDL_BUTTON_LEFT) {
//                    isDrawing = 1;
//                    prevMouseX = event.button.x;
//                    prevMouseY = event.button.y;
//                }
//            }
//
//            if (event.type == SDL_MOUSEBUTTONUP) {
//                if (event.button.button == SDL_BUTTON_LEFT) {
//                    isDrawing = 0;
//                }
//            }
//
//            if (event.type == SDL_MOUSEMOTION && isDrawing) {
//                SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
//                SDL_RenderDrawLine(renderer, prevMouseX, prevMouseY, event.motion.x, event.motion.y);
//                prevMouseX = event.motion.x;
//                prevMouseY = event.motion.y;
//            }
        }

//        // Clear the renderer with a white background
//        SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
////        SDL_RenderClear(renderer);
//
//        // Present the renderer to update the screen
//        SDL_RenderPresent(renderer);
    }
    

    // Destroy the renderer and window
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);

    // Quit SDL
    SDL_Quit();
        // Quit SDL
   printf("Hello, World!\n");
    return 0;
}
