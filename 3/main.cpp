#include <iostream>
#include <vector>
#include <cstdlib>
#include <cmath>
enum {
    A=1,
    B=2,
    C=3
};
class Employ {
    std::vector<int> employOne;
public:
    void type(int typeTask){
        if (typeTask==A) {
            employOne.push_back(A);
            std::cout<<"A"<<std::endl;
        }
        if (typeTask==B) {
            employOne.push_back(B);
            std::cout<<"B"<<std::endl;
        }
        if (typeTask==C){
            employOne.push_back(C);
            std::cout<<"C"<<std::endl;
        }
    }
};


class Medium: public Employ {
    std::vector<int> countEmployee;
public:

    void getCountEmployee(int employee){
         countEmployee.push_back(employee);
    }
    int getEmployee(int i){
        return countEmployee[i];
    }
    void distribution(int i,int countTask){

        std::cout<<"count of task "<< countTask <<std::endl;
        std::cout<<i<<" command"<<std::endl;

        for (int j=0; j < countTask; j++){
            if (i==countEmployee.size()-1 && countEmployee[i] < countTask){
                std::cout<<"Don't employees"<<std::endl;
                break;
            }
            type(std::rand()%3+1);
        }
        countEmployee[i]=countEmployee[i]-countTask;
    }
};
class Head : public Medium{
    int task=0;
    int allEmployee=0;
public:

    void getAllEmployee(int x){
        allEmployee+=x;
    }
    void getAllEmployeeDecrease(int x){
         allEmployee-=x;
    }
    int getAEmp(){
        return allEmployee;
    }
    int getTask(int t){
        return task;
    }
    int getSum(int n){
        return task+n;
    }
};

int main() {
    Head* command= new Head;
    int countCommand;
    std::cout<<"Input count of command"<<std::endl;
    std::cin>>countCommand;
    int countEmployees;
    for (int i=0; i < countCommand; i++){
        std::cout<<"count employees"<<std::endl;
        std::cin >> countEmployees;
        command->getCountEmployee(countEmployees);
        command->getAllEmployee(countEmployees);
    }
    int countTask=0;
    while (command->getAEmp() > 0){
        std::cout<<"Input task"<<std::endl;
        int task;
        std::cin>>task;
        command->getTask(task);

        for (int i=0; i < countCommand; i++){
            if(command->getEmployee(i) == 0){
                //i++;
                continue;
            }
            std::srand(command->getSum(i));
            countTask=std::rand()% command->getEmployee(i) + 1;
            command->distribution(i,countTask);
            command->getAllEmployeeDecrease(countTask);
        }
    }
    if (command->getAEmp()==0){
        std::cout<<"All employees are busy"<<std::endl;
    }
}
