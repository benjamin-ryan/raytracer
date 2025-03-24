#include <iostream>

#define WIDTH 256
#define HEIGHT 256

int main()
{
    std::cout << "P3\n" << WIDTH << ' ' << HEIGHT << "\n255\n";

    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            float r = double(j) / (WIDTH - 1);
            float g = double(i) / (HEIGHT - 1);
            float b = 0.0;

            int i_r = int(255.9999 * r);
            int i_g = int(255.9999 * g);
            int i_b = int(255.9999 * b);

            std::cout << i_r << ' ' << i_g << ' ' << i_b << "\n";
        }
    }
}