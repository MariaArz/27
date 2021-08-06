#include <iostream>
#include <vector>
#include <cstdlib>
#include <cmath>
enum {
    A=1,
    B=2,
    C=3
};
void type(int typeTask){
    if (typeTask==A) std::cout<<"A"<<std::endl;
    if (typeTask==B) std::cout<<"B"<<std::endl;
    if (typeTask==C) std::cout<<"C"<<std::endl;
}
class Head{
public:
    int task=0;
};
class Medium: public Head{
    std::vector<int> countEmployee;
public:
    int getSum(int n){
        return task+n;
    }
    void getCountEmployee(int employee){
         countEmployee.push_back(employee);
    }
    int getEmployee(int i){
        return countEmployee[i];
    }
    int count=0;int n;
    void distridution(int i,int countTask){

        if (i == 0){
            n=countTask;
        }
        else {
            n=count;
        }
        if (countEmployee[i]<n) {
            count=countEmployee[i];
            n=abs(countEmployee[i]-n);
            countEmployee[i]=0;
        }
        else {
            count=n;
            countEmployee[i]=countEmployee[i]-count;

        }
        std::cout<<"count of task "<< count <<std::endl;
        std::cout<<i<<" command"<<std::endl;

        for (int j=0; j < count; j++){
            if (i==countEmployee.size()-1 && count==countEmployee[i]){
                std::cout<<"Don't employees"<<std::endl;
                break;
            }
            type(std::rand()%3+1);
        }
        if (countEmployee[i]==0){
            count=n;
        }
        else{
            count=0;
        }
    }


};
int main() {
    Medium* command= new Medium;
    int countCommand;
    std::cout<<"Input count of command"<<std::endl;
    std::cin>>countCommand;
    int employee, allEmployee=0;
    for (int i=0; i < countCommand; i++){
        std::cout<<"count employees"<<std::endl;
        std::cin>>employee;
        command->getCountEmployee(employee);
        allEmployee+=employee;
    }
    while (allEmployee>0){
        std::cout<<"Input task"<<std::endl;
        std::cin>>command->task;
        int countTask;
        for (int i=0; i < countCommand; i++){
            if(command->getEmployee(i)==0){
                i++;
            }
            std::srand(command->getSum(i));
            countTask=std::rand()%command->getEmployee(i)+1;
            command->distridution(i,countTask);
        }
        allEmployee=allEmployee-countTask;
    }
}
