#include "canvas.hpp"

Canvas::Canvas(int width, int height) {
    pixels.resize(width, std::vector<Color>(height, Color(0, 0, 0)));
    this->width = width;
    this->height = height;
}

void Canvas::write_pixel(int x, int y, Color color) {
    if (x < 0 || x >= width || y < 0 || y >= height) {
        return;
    }
    pixels[x][y] = color;
}

Color Canvas::pixel_at(int x, int y) {
    return pixels[x][y];
}

std::string Canvas::canvas_to_ppm(){
    std::string ppm = "";
    std::string ppm_final = "";
    int count = 0;
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            Color c = pixels[j][i];
            int red = std::min(255, std::max(0, static_cast<int>(std::round(c.red * 255))));
            int green = std::min(255, std::max(0, static_cast<int>(std::round(c.green * 255))));
            int blue = std::min(255, std::max(0, static_cast<int>(std::round(c.blue * 255))));

            ppm += std::to_string(red) + " " + std::to_string(green) + " " + std::to_string(blue);

            if (j < width - 1) {
                ppm += " ";
            }
        }
        ppm += "\n";
    }

    for (char cr : ppm){
        ppm_final += cr;
        count += 1;
        if (cr == '\n'){
            count = 0;
        }
        if (count >= 68 && cr == ' '){
            ppm_final += "\n";
            count = 0;
        }
    }
    ppm_final = "P3\n" + std::to_string(width) + " " + std::to_string(height) + "\n255\n" + ppm_final;
    return ppm_final;
}

void Canvas::set_color(Color color){
    for (int i = 0; i < width; i++){
        for (int j = 0; j < height; j++){
            pixels[i][j] = color;
        }
    }
}

void print_ppm(std::string ppm){
    
    std::string random = std::to_string(rand());
    std::string filename = "../ppm/out__" + random + ".ppm";
    std::ofstream file(filename);
    if (file.is_open()){
        file << ppm;
    }
    file.close();
}

