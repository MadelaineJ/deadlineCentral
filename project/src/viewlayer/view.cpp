#include "view.hpp"
#include "statemachine.hpp"

void view_layer() {

    while(true){

        BaseState:: currState->enter();
        BaseState:: currState->update();

    }

}
