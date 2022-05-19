#include <iostream>
#include "boost/di.h"

using namespace std;
namespace di = boost::di;

class IAnimal {
public:
    virtual void Greet()=0;

};

class Cat : public IAnimal{
public:
    void Greet() override{
        cout<<"Hi, I'm a cat!"<<endl;
    }
private:
    string name_ = "Unknown";
};
class Dog : public IAnimal{
public:
    void Greet() override{
        cout<<"Hi, I'm a dog!"<<endl;
    }

};

class PetOwner{
public:
    IAnimal* pet ;
    //string name_;
    PetOwner(IAnimal* pet):  pet(pet){};

    void GetInfo(){
        pet->Greet();
    }
};
int main() {
    auto injectorC = di::make_injector(di::bind<IAnimal>.to<Cat>());
    auto injectorD = di::make_injector(di::bind<IAnimal>.to<Dog>());
    auto myOwner = injectorC.create<PetOwner>();
    auto Owner2 = injectorD.create<PetOwner>();
    myOwner.GetInfo();
    Owner2.GetInfo();
    return 0;
}
