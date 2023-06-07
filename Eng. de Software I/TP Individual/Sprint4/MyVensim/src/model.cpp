#include "model.h"

Model::Model () {}

Model::~Model () {
    for (auto it = flows.begin(); it != flows.end(); it++) 
        delete *it;
    for (auto it = systems.begin(); it != systems.end(); it++)
        delete *it;
    this->flows.clear();
    this->systems.clear();
}

double Model::run (int start, int finish) {
    vector<double> values;
    System* source;
    System* destination;
    for (int i = start; i < finish; i++){

        int size = flows.size();
        
        for(int j = 0; j < size; j++) {
            values.push_back(flows[j]->run());
        } 

        for(int k = 0; k < size; k++){
            source = flows[k]->getSource();
            source->setValue(source->getValue() - values[k]);
            destination = flows[k]->getDestination();
            destination->setValue(destination->getValue() + values[k]);
        }
        values.clear();
    }
    return values[finish];
}

void Model::add (System* system) {
    this->systems.push_back(system);
}

void Model::add (Flow* flow) {
    this->flows.push_back(flow);
}

Model* Model::operator= (Model* model) {
    if(this == model)
        return this;

    for(vector<System*>::iterator it = systems.begin(); it != systems.end(); it++){
        delete *it;
    }

    this->systems.clear();

    for(vector<Flow*>::iterator it = flows.begin(); it != flows.end(); it++){
        delete *it;
    }

    this->flows.clear();
    
    int size = model->flows.size();
    for (int i = 0; i < size; i++){
        Flow* aux = model->flows[i];
        this->flows.push_back(aux);
    }

    size = model->systems.size();
    for (int i = 0; i < size; i++){
        System* aux = model->systems[i];
        this->systems.push_back(aux);
    }
    return this;
}
