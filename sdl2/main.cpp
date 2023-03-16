#include "globals.h"
#include "statemachine.h"

int main(int argc, char ** args){

    while(true){

        BaseState:: currState->enter();
        BaseState:: currState->update();

    }
    return 0;

}
