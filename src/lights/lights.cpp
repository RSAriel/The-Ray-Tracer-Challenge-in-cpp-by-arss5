#include "lights.hpp"

PointLight::PointLight(Tuple position, Color intensity){
    this->position = position;
    this->intensity = intensity;
}

PointLight::PointLight(){
}

bool operator==(const PointLight& a, const PointLight& b){
    return a.position == b.position && a.intensity == b.intensity;
}