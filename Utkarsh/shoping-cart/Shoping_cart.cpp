#include<iostream>
#include<list>
using namespace std;

class Item{
    private:
    string name;
    double amount;

    public:
    // default constructor
    Item(){
        this->name=name;
        this->amount=amount;
    }
    // paramatrized constructor
    Item(string name,double amount){
        this->name=name;
        this->amount=amount;
    }
    
    // getter and setter for data members

    string getItemName(){
        return this->name;
    }
    double getItemAmount(){
        return this->amount;
    }

    void setItemName(string str){
        this->name=str;
    }
    void setItemAmount(double price){
        this->amount=price;
    }

    
};

class Bucket {
    private:
    list <Item> bucket;

    public:
    Bucket(){
        this->bucket=bucket;
    }
    void addItem(const Item &item){
        bucket.push_front(item);

    }
    bool removeItem(Item &item){
        bucket.remove(item);
        
        return true;
    } 

    void dispaly(){
        cout<<"........Bucket Items List............."<<endl;
        int sr=1;
        list <Item>::iterator iter;
        for(iter=this->bucket.begin();iter!=this->bucket.end();iter++){
            cout<<sr<<" --> Item Name ->"<<iter->getItemName()<<" Item amount ->"<<iter->getItemAmount()<<endl;
            sr++;
        }

    }

    double generateBill(){
        double bill=0;
        int sr=1;
        cout<<"..............BILL Generation............."<<endl;
        cout<<"........Bucket Items List............."<<endl;
        list <Item>::iterator iter;
        for(iter=this->bucket.begin();iter!=this->bucket.end();iter++){
            cout<<sr<<" --> Item Name ->"<<iter->getItemName()<<" Item amount ->"<<iter->getItemAmount()<<endl;
            sr++;
            bill+=iter->getItemAmount();
        }
        cout<<"total amount to be paid ----> "<<bill<<endl;
        return bill;
    }
};



int main(){
    
    // create three item
     Item milk("milk",23.00);
     Item bread("bread",20.50);
     Item butter("butter",45.60);
    Bucket bucket;

    // add to bucket
     bucket.addItem(milk);
     bucket.addItem(bread);
     bucket.addItem(butter);

     bucket.dispaly();
     bucket.generateBill();

     bucket.removeItem(bread);

     bucket.dispaly();
     bucket.generateBill();
}
