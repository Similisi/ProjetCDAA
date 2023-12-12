#include "contactinteraction.h"
ContactInteraction::ContactInteraction()
{

}

void ContactInteraction::AddContact(Contact* c){
    this->contact = c;
}
void ContactInteraction::AddInteraction(Interaction* i){
    this->interaction = i;
}

Contact* ContactInteraction::getContact(){
    return this->contact;
}
Interaction* ContactInteraction::getInteraction(){
    return this->interaction;
}
