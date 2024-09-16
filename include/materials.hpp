#ifndef MATERIALSH
#define MATERIALSH
#include "color.hpp"
#include "lights.hpp"

class Material {
    public:
        Color color;
        float ambient;
        float diffuse;
        float specular;
        float shininess;

        Material();
};

//Maybe should be in lights.cpp
Color lighting(Material material, PointLight light, Tuple point, Tuple eyev, Tuple normalv);

bool operator==(const Material &lhs, const Material &rhs);



#endif
