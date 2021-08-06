#include <iostream>
#include <vector>
class Trees{
    int bigdr = 0;
    int littlebr=0;
    std::vector<std::vector<std::string>> name;
    std::vector<Trees*> country;
public:
    std::vector<std::string> branch(){
        std::string elf;
        std::vector<std::string> bran;
        littlebr = 2 + std::rand() % 2;
        for (int k = 0; k < 1 + littlebr; k++) {
            std::cout<<"Input elf"<<std::endl;
            std::cin >> elf;
            if (elf != "None") {
                bran.push_back(elf);
            }
        }
        return bran;
    }

    Trees* getName() {
        bigdr = 3 + std::rand() % 3;
        for (int j = 0; j < bigdr; j++) {
            this->name.push_back(this->branch());
        }
        return this;
    }


    std::vector<Trees*> countr(){
        for (int i=0; i < 5; i++){
            country.push_back(this->getName());
        }
        return country;
    }
    void searchNeighborsinTree(std::string elf) {
        for (int k=0; k<5; k++){
            int t=0, n=country[k]->bigdr;
            if ( k > 0){
                t=country[k-1]->bigdr;
                n=country[k-1]->bigdr+country[k]->bigdr;
            }
            for (int j=t; j < n; j++) {
                for (int i=0; i < 1+country[k]->littlebr; i++){
                    if (elf==country[k]->name[j][i]){
                        std::cout<<country[k]->littlebr<<"neighbors"<<std::endl;
                        break;
                    }
                }

            }
        }

    }
};

int main() {
    Trees* trees=new Trees;
    trees->countr();
    std::string elf;
    std::cout<<"Input elf who need"<<std::endl;
    std::cin >> elf;
    trees->searchNeighborsinTree(elf);
}
