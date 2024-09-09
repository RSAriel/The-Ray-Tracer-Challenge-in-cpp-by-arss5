#ifndef TUPLEH
#define TUPLEH


class Tuple {
    float x, y, z, w;

    public:
    Tuple(float x, float y, float z, float w) {
        this->x = x;
        this->y = y;
        this->z = z;
        this->w = w;
    }

    bool isVector(float w) {
        return w == 0.0;
    }

    bool isPoint(float w) {
        return w == 1.0;
    }

    void print() {
        std::cout << "x: " << x << " y: " << y << " z: " << z << " w: " << w << std::endl;
    }
};


Tuple Point(float x, float y, float z) {
    return Tuple(x, y, z, 1.0);
}

Tuple Vector(float x, float y, float z) {
    return Tuple(x, y, z, 0.0);
}
#endif