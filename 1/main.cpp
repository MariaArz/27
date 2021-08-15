#include <iostream>
#include <vector>

class Branch{
    int little=0;
    std::vector<std::string> br;
public:
    int getLittle(){
        return little;
    }
    Branch* setBranch(){
        std::string elf;
        if (!br.empty()){
            br.clear();
        }
        Branch* branch=new Branch;
        branch->little=2 + std::rand() % 2+1;
        for (int i=0; i < branch->little; i++){
            std::cout<<"Input elf"<<std::endl;
            std::cin >> elf;
            if (elf != "None") {
                branch->br.push_back(elf);
            }
        }
        return branch;
    }
    std::vector<std::string> getBranch(){
        return br;
    }
};
class Trees{
    Branch* branch=new Branch;
    int big=0;
    std::vector<Branch*> tr;
public:
    int getBig(){
        return big;
    }
    Trees* setTrees(){
        if (!tr.empty()){
            tr.clear();
        }
        Trees* trees=new Trees;
        trees->big=3 + std::rand() % 2;
        for (int i=0; i < trees->big; i++){
            trees->tr.push_back(branch->setBranch());
        }
        return trees;
    }
    std::vector<Branch*> getTrees(){
        return tr;
    }
};
class Country{
    Trees* trees=new Trees;
    std::vector<Trees*> cou;
public:
    void setCountry(){
        for (int i=0; i < 5; i++){
            cou.push_back(trees->setTrees());
        }
    }
    void search(std::string name){
        for (int i=0; i < 5; i++){
            for (int j=0; j < cou[i]->getBig(); j++){
                for (int k=0; k < cou[i]->getTrees()[j]->getLittle(); k++){
                    if (name==cou[i]->getTrees()[j]->getBranch()[k]){
                        std::cout<<cou[i]->getTrees()[j]->getLittle()-1<<" neighbors"<<std::endl;
                        break;
                    }
                }
            }
        }
    }
};
int main() {
    Country* country=new Country;
    country->setCountry();
    std::string elfSearch;
    std::cout<<"Input elf who need"<<std::endl;
    std::cin>>elfSearch;
    country->search(elfSearch);
    return 0;
}
