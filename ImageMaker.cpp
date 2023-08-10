#include "ImageMaker.h"

ImageMaker::ImageMaker() {
    width = height = pen_blue = pen_green = pen_red = 0;
    for (int row{0}; row < MAX_WIDTH; row++){
        for (int col{0}; col < MAX_HEIGHT; col++) {
            image[row][col][RED] = MAX_COLOR;
            image[row][col][GREEN] = MAX_COLOR;
            image[row][col][BLUE] = MAX_COLOR;
        }
    }
}

ImageMaker::ImageMaker(string filename) {
    width = height = pen_red = pen_green = pen_blue = 0;
    LoadImage(filename);
}

void ImageMaker::LoadImage(string filename) {
    ifstream file(filename);
    string line{""};
    int red, green, blue , max = 0;

    //file.open(filename);
    if(!file.is_open()) {
        throw "File failed to open";
    }
    else
        file >> line >> width >> height >> max;
    SetWidth(width);
    SetHeight(height);
    if (line != "P3"){
        throw "Bad magic number";
    }
    else if (width > MAX_WIDTH || width < 0){
        throw "Width out of bounds";
    }
    else if (height > MAX_HEIGHT || height < 0){
        throw "Height out of bounds";
    }
    else if (max != MAX_COLOR){
        throw "Max color range not 255";
    }
    for(int col{0}; col < height; col++){
        for(int row{0}; row < width; row++) {
            file >> red >> green >> blue;
            if(red < 0 || green < 0 || blue < 0 || red > 255 || green > 255 || blue > 255){
                throw "Color value invalid";
            }
            else {
                image[row][col][RED] = red;
                image[row][col][GREEN] = green;
                image[row][col][BLUE] = blue;
            }
        }
    }
    file.close();
}

void ImageMaker::SaveImage(string filename) {
    ofstream file(filename);
    file << "P3\n" << width << " " << height << endl << "255" << endl ;
    if (GetWidth() <= 0 || GetHeight() <= 0){
        throw "Image must have non-zero dimensions";
    }
        for(int col{0}; col < height; col++){
            for(int row{0}; row < width; row++) {

                file << image[row][col][RED] << " ";
                file << image[row][col][GREEN] << " ";
                file << image[row][col][BLUE] << " ";
            }
            file << endl;
        }
    file.close();
}

int ImageMaker::GetWidth() {
    return width;
}

int ImageMaker::GetHeight() {
    return height;
}

void ImageMaker::SetWidth(int width) {
    if (width < 0 || width > MAX_WIDTH)
        throw "Width out of bounds";
    else
        this->width = width;
}

void ImageMaker::SetHeight(int height) {
    if (height < 0 || height > MAX_HEIGHT)
        throw "Height out of bounds";
    else
        this->height = height;
}

int ImageMaker::GetPenRed() {
    return pen_red;
}

int ImageMaker::GetPenGreen() {
    return pen_green;
}

int ImageMaker::GetPenBlue() {
    return pen_blue;
}

void ImageMaker::SetPenRed(int newR) {
    if (newR < 0 || newR > 255)
        throw "Color value invalid";
    else
        pen_red = newR;
}

void ImageMaker::SetPenGreen(int newG) {
    if (newG < 0)
        throw "Color value invalid";
    else if (newG > MAX_COLOR)
        throw "Max color range not 255";
    else
        pen_green = newG;
}

void ImageMaker::SetPenBlue(int newB) {
    if (newB < 0 || newB > 255)
        throw "Color value invalid";
    else
        pen_blue = newB;
}

void ImageMaker::DrawPixel(int x, int y) {
    if (x < 0 || x > width || y < 0 || y > height)
        throw "Point out of bounds";
    else if (x == 0 && y == 0 && width == 0 && height == 0)
        throw "Point out of bounds";
    else {
        image[x][y][RED] = GetPenRed();
        image[x][y][GREEN] = GetPenGreen();
        image[x][y][BLUE] = GetPenBlue();
    }
}

void ImageMaker::DrawRectangle(int x1, int y1, int x2, int y2) {
    if (x1 < 0 || x2 < 0 || y1 < 0 || y2 < 0)
        throw "Point out of bounds";
    else if (x1 == x2 && y1 == y2) {
        image[x1][y1][RED] = GetPenRed();
        image[x1][y1][GREEN] = GetPenGreen();
        image[x1][y1][BLUE] = GetPenBlue();
    }
}

void ImageMaker::DrawLine(int x1, int y1, int x2, int y2) {
    if (x1 < 0 || x2 < 0 || y1 < 0 || y2 < 0)
        throw "Point out of bounds";
    else if (x1 == x2 && y1 == y2) {
        image[x1][y1][RED] = GetPenRed();
        image[x1][y1][GREEN] = GetPenGreen();
        image[x1][y1][BLUE] = GetPenBlue();
    }
    else if (x1 == x2 && y1 != y2) {
        for (y1; y1 < y2 + 1; y1++) {
            image[x1][y1][RED] = GetPenRed();
            image[x1][y1][GREEN] = GetPenGreen();
            image[x1][y1][BLUE] = GetPenBlue();
        }
    }
    else if (x1 != x2 && y1 == y2) {
        for (x1; x1 < x2 + 1; x1++) {
            image[x1][y1][RED] = GetPenRed();
            image[x1][y1][GREEN] = GetPenGreen();
            image[x1][y1][BLUE] = GetPenBlue();
        }
    }
    else {
        for (int x = x1; x < x2 + 1; x++) {
            //int slope = (y2 - y1) / (x2 - x1);
            //int b = y2 - ((y2 - y1) / (x2 - x1) * x2);
            int y = ((y2 - y1) / (x2 - x1) * x) + y2 - ((y2 - y1) / (x2 - x1) * x2);
            image[x][y][RED] = GetPenRed();
            image[x][y][GREEN] = GetPenGreen();
            image[x][y][BLUE] = GetPenBlue();
        }
    }
}

bool ImageMaker::PointInBounds(int x, int y) {
    return ((x > 0 && x <= width) && (y > 0 && y <= height));
}