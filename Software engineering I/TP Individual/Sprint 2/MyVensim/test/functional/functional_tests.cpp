#include "functional_tests.h"

void exponentialFuncionalTest () {
    Model* Modelexponential = new Model();
    System* pop1 = new System();
    pop1->setValue(100.0);
    System* pop2 = new System();
    pop2->setValue(0.0);
    Exponential* f = new Exponential(pop1,pop2);
    Modelexponential->add(f);
    Modelexponential->add(pop1);
    Modelexponential->add(pop2);
    Modelexponential->run(0,100);
    assert(abs(pop1->getValue() - 36.6032) < 0.0001);
    assert(abs(pop2->getValue() - 63.3968) < 0.0001);
}

void logisticalFuncionalTest () {
    Model* ModelLogistic = new Model();
    System* p1= new System();
    p1->setValue(100.0);
    System* p2 = new System();
    p2->setValue(10.0);
    Logistic* l = new Logistic(p1,p2);
    ModelLogistic->add(l);
    ModelLogistic->add(p1);
    ModelLogistic->add(p2);
    ModelLogistic->run(0,100);
    
    assert(abs(p1->getValue() - 88.2167) < 0.0001);
    assert(abs(p2->getValue() - 21.7834) < 0.0001);
}

void complexFuncionalTest () {
    System* q1 = new System();
    q1->setValue(100.0);
    System* q2 = new System();
    q2->setValue(0.0);
    System* q3 = new System();
    q3->setValue(100.0);
    System* q4 = new System();
    q4->setValue(0.0);
    System* q5 = new System();
    q5->setValue(0.0);

    Flow* f = new Exponential(q1,q2);
    Flow* g = new Exponential(q1,q3);
    Flow* r = new Exponential(q2,q5);
    Flow* t = new Exponential(q2,q3);
    Flow* u = new Exponential(q3,q4);
    Flow* v = new Exponential(q4,q1);

    Model* model = new Model();
    model->add(q1);
    model->add(q2);
    model->add(q3);
    model->add(q4);
    model->add(q5);
    model->add(f);
    model->add(g);
    model->add(r);
    model->add(t);
    model->add(u);
    model->add(v);
    model->run(0,100);
    assert(abs((q1->getValue() - 31.8513)) < 0.0001);
    assert(abs((q2->getValue() - 18.4003)) < 0.0001);
    assert(abs((q3->getValue() - 77.1143)) < 0.0001);
    assert(abs((q4->getValue() - 56.1728)) < 0.0001);
    assert(abs((q5->getValue() - 16.4612)) < 0.0001);
}