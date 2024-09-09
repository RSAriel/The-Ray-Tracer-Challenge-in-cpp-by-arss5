#ifndef COLORH
#define COLORH

class Color : public Tuple {
    public:
    float red, green, blue;

    Color() : Tuple(0.0, 0.0, 0.0, 0.0) {
        this->red = 0.0;
        this->green = 0.0;
        this->blue = 0.0;
    }

    Color(float red, float green, float blue) : Tuple(red, green, blue, 0.0) {
        this->red = red;
        this->green = green;
        this->blue = blue;
    }
};

Color operator*(Color a, Color b) {
    return Color(a.red * b.red, a.green * b.green, a.blue * b.blue);
}

#endif