#include<iostream>
#include<list>
#include<map>
#include<iterator>
using namespace std;

class Item{
    private:
    string name;
    double amount;

    public:
    // paramatrized constructor
    Item(string name,double amount){
        this->name=name;
        this->amount=amount;
    }

    // getter and for data members

     string getItemName(){
        return this->name;
    }
    double getItemAmount(){
        return this->amount;
    }
};

class Itemdecor{
    public:
    Item *it;
    int q;

    public:
    Itemdecor(Item *it,int q){
        this->it=it;
        this->q=q;
    }

};


class Shop{
    private:
    map<Item*,int> store;

    public:
    // display the shop items
    void dispaly(){
        cout<<"........shop Items List............."<<endl;
        int sr_no=1;
        for(auto iter:store){
            cout<<sr_no<<" --> Item Name -> "<<(iter).first->getItemName()<<"    Item amount ->"<<iter.first->getItemAmount()<<"    Item quantity -> "<<iter.second<<endl;
            sr_no++;
        }

    }

    // check for item availability
    Item * isAvailableItem(string itemname,int quantity){
        for(auto iter1:store){
            //cout<<iter.first->getItemName()<<endl;
            if((itemname==iter1.first->getItemName()) && (iter1.second>=quantity))
            {
                return (iter1.first);
            }
        }
        return NULL;        
    }
    
    // add items to shop
    void add_shopItem(Item *item,int quantity){
        map<Item *,int>:: iterator it;
        it = store.find(item);
        if(it==store.end()){// if item not present in store
            store[item]=quantity;
        }
        else{
            (it)->second+=quantity;
        }
    }

    // get item from shop to add in basket
    Itemdecor * get_shopItem(Item *item,int quantity){
        map<Item *,int>:: iterator it;
        it =store.find(item);
        if(it== store.end()){
            return NULL;
        }
        else{
            //update quantity
            store[(it)->first]=(it)->second-quantity;
            return (new Itemdecor(((it)->first),quantity));
        }
        
    }

};




class Bucket {
    private:
    list <Itemdecor*> bucket;
    Shop *shop_obj;
    public:

    Bucket(Shop *shop_obj){
        this->shop_obj=shop_obj;
    }
    void add_bucketItem(string itemname,int req_quantity){
        Item * item=shop_obj->isAvailableItem(itemname,req_quantity);
        if(item){
            bucket.push_front(shop_obj->get_shopItem(item,req_quantity));
        }
    }

    bool removeItem(string itemname){

        for(auto iter:bucket){
            if(iter->it->getItemName()==itemname){
                shop_obj->add_shopItem(iter->it,iter->q);
                bucket.remove(iter);
                return true;
            }
            
        }
        return false;
        
    } 

    void dispaly(){
        cout<<"........Bucket Items List............."<<endl;
        int sr_no=1;
        for(auto iter:bucket){
            cout<<sr_no<<" --> Item Name ->"<<(iter)->it->getItemName()<<"       Item amount -> "<<iter->it->getItemAmount()<<"     Item quantity -> "<<iter->q<<endl;
            sr_no++;
        }

    }
    // bill generation
    double generateBill(){
        double bill=0;
        int sr_no=1;
        cout<<"..............BILL Generation............."<<endl;
        cout<<"........Bucket Items List............."<<endl;
        
        for(auto iter:bucket){
            cout<<sr_no<<" --> Item Name -> "<<(iter)->it->getItemName()<<"      Item amount ->  "<<iter->it->getItemAmount()<<"    Item quantity -> "<<iter->q<<"   total amount->  "<<((iter->it->getItemAmount())*(iter->q))<<endl;
            sr_no++;
            bill+=((iter->it->getItemAmount())*(iter->q));
        }
        cout<<"total amount to be paid ---->   "<<bill<<endl;
        return bill;
    }
};



int main(){
    
    // create three item
     Item milk("milk",23.00);
     Item bread("bread",20.50);
     Item butter("butter",45.60);

     // add to shop 
     Shop shop_obj;
     shop_obj.add_shopItem(&milk,100);
     shop_obj.add_shopItem(&bread,100);
     shop_obj.add_shopItem(&butter,100);
     shop_obj.dispaly();

    Bucket bucket(&shop_obj);
    // add to bucket
     bucket.add_bucketItem("milk",50);
     bucket.add_bucketItem("bread",45);
     bucket.add_bucketItem("butter",80);

     bucket.dispaly();
     bucket.generateBill();
     shop_obj.dispaly();

    // after removing 
     bucket.removeItem("bread");
     bucket.dispaly();
     bucket.generateBill();
     shop_obj.dispaly();
}
