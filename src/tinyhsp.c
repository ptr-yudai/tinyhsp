#define __APPLE__

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdint.h>
#include <GLFW/glfw3.h>
#ifdef __APPLE__
#include <OpenGL/gl.h>
#else
#include <GL/gl.h>
#endif
#include "token.h"
#include "lexer.h"
#include "parser.h"

int32_t width = 640;
int32_t height = 480;
uint8_t pixel_data[640 * 480 * 3];

int main(void)
{
	char line[LINE_BUF_SIZE];
	double value;
	
	while (fgets(line, LINE_BUF_SIZE, stdin) != NULL) {
		set_line(line);
		set_st_token_exists(0);
		value = parser_expression();
		printf(">>%f\n",value);
	}
    
    //
    
    GLFWwindow* window;

    // GLFWライブラリを初期化する
    if (!glfwInit())
        return -1;

    // ウインドウを生成する
    window = glfwCreateWindow(width, height, "Hello World", NULL, NULL);
    if (!window)
    {
        glfwTerminate();
        return -1;
    }

    // ウインドウのコンテキストを生成する
    glfwMakeContextCurrent(window);
    
    // 
    int index = 0;
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            pixel_data[index] = 255;
            pixel_data[index + 1] = 0;
            pixel_data[index + 2] = 0;
            index += 3;
         }
    }

    // ユーザーがウィンドウを閉じるまでループ
    while (!glfwWindowShouldClose(window))
    {
        // 描画処理をここに描く
        glClear(GL_COLOR_BUFFER_BIT);
        glRasterPos2i(-1, -1);
        glDrawPixels(width, height, GL_RGB, GL_UNSIGNED_BYTE, pixel_data);

        // フロントバッファとバックバッファを交換する
        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}
