#ifndef MODEL_H
#define MODEL_H

#include "flow.h"

#include <cstring>
#include <vector>

/**
* @brief File responsible for project templates.
*
* @author Ananda Mendes 2021.
*/

class Model{
    protected:
        vector<Flow*> flows; /*! < Flow pointer vector */
        vector<System*> systems; /*! < Systems pointer vector */

    public:
        /**
         * @brief Builder to create a new model.
         * 
         */
        Model();

        /**
         * @brief Destructor to destroy the model.
         * 
         */
        virtual ~Model();

        /**
         * @brief Function to run the model.
         * 
         * @param start Initial value.
         * @param finish Final value.
         * @return Returns final value.
         */
        double run(int,int);

        /**
         * @brief Function to add a new system.
         * 
         */
        void add(System*);

        /**
         * @brief Function to add new flow.
         * 
         */
        void add(Flow*);
        
    private:
        /**
         * @brief Function to overload operator =.
         * 
         * @param model Model pointer.
         * @return Returns model.
         */
        Model* operator=(Model*);
};

#endif