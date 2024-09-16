#include "lights.hpp"

PointLight::PointLight(Tuple position, Color intensity){
    this->position = position;
    this->intensity = intensity;
}