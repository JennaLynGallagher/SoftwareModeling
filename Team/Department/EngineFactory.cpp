#include "Team/Department/EngineFactory.h"

EngineFactory::EngineFactory(DepartmentMediator* mediator) : DepartmentFactory(mediator){

}

EngineFactory::~EngineFactory(){

}
    
void EngineFactory::createPart(DepartmentOutput* oldPart){
    //create new part
    Engine* part = new Engine();

    //determine if the part could be better
    //give 20% chance for part to be better,  part is not better iff (speed <= 0)
    if(part->getSpeed() > getPartSpeed(oldPart, "Engine")){
        //tell other departments that the new part is better, the team will add the part when it is passed to it by: team->partChanged(part);
        mediator->communicate(part);
    }

    //de-allocate part
    delete part;
}

void EngineFactory::simulation(){
    cout << "The driver is using the simulator to adjust to the weight distribution of the Engine." << endl;

    //get the speed of the part
    int speed = part->getSpeed() % 5;

    cout << "The Engine shows a speed of " << speed << "/5" << endl;
}

void EngineFactory::otherPartChanged(DepartmentOutput* part){
    cout << "The Engine department confirms that they have received the message about the new " << part->getType() << endl;
}

string EngineFactory::getType(){
    return "Engine";
}