#include "flow.h"

Flow::Flow () {}

Flow::Flow (System* source, System* destination) {
    this-> source = source;
    this->destination = destination;
}

Flow::~Flow () {}

void Flow::setSources (System* source) {
    this->source = source;
}

void Flow::setDestination (System* destination) {
    this->destination = destination;
}

System* Flow::getSource () {
    return this->source;
}

System* Flow::getDestination () {
    return this->destination;
}

Flow* Flow::operator= (Flow* flow) {
    if (this == flow)
        return this;
        
    this->source = flow->getSource();
    this->destination = flow->getSource();
    return this;
}
