#ifndef CONTACTINTERACTION_H
#define CONTACTINTERACTION_H


#include "interaction.h"
#include "contact.h"

class ContactInteraction
{
public:
    ContactInteraction();
    void AddContact(Contact* c);
    void AddInteraction(Interaction* i);
    Contact* getContact();
    Interaction* getInteraction();
private:
    Interaction * interaction;
    Contact *contact;
};

#endif // CONTACTINTERACTION_H
