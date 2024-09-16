#include "computations.hpp"

Computations::Computations(float t, Sphere object, Tuple point, Tuple eyev, Tuple normalv){
    this->t = t;
    this->object = object;
    this->point = point;
    this->eyev = eyev;
    this->normalv = normalv;
}

Computations prepare_computations(Intersection i, Ray r){
    Computations comps(i.t, i.object, r.position(i.t), -r.direction, normal_at(i.object, r.position(i.t)));
    if (dot(comps.normalv, comps.eyev) < 0){
        comps.inside = true;
        comps.normalv = -comps.normalv;
    } else {
        comps.inside = false;
    }
    return comps;
}