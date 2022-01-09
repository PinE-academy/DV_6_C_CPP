#include <bits/stdc++.h>
// #include <iostream>
// #include <map>
// #include <cstring>
// #include <list>

using namespace std;

class Item{

    public:
        map<string, double> Item_ava;

    public:

        void add_item(string name, double cost){

            Item_ava[name]= cost;

        }

        string get_name(string name){

            auto it= Item_ava.find(name);
            auto beg= Item_ava.begin();
            auto end= Item_ava.end();

            if(it==end )
                    return NULL;
                else        
                    return it -> first;

        }

        double get_cost (string name){

            auto it= Item_ava.find(name);
            auto beg = Item_ava.begin();
            auto end= Item_ava.end();

            if (it == end)
                    return 0;
                else 
                    return it -> second;

                
         }

         void show_Item(){

             int n = 1;
                auto beg = Item_ava.begin();
                auto end = Item_ava.end();
            
             cout<< '\n' <<"------ List of items ------" << '\n';
            cout << '\n' << "S.no" << '\t' << "Name" << '\t' <<'\t' << "Amount" << '\n' <<  endl;

            while (beg != end)
            {
                cout << n << "." << '\t' << beg->first  << '\t' << '\t'<< beg->second << endl;

                n++;    
                beg++;

            }
            

         }

 };


 class shop{

    

     public:
        map<string, int> item_qua;

        void additem(string name, int quantity){

            auto it = item_qua.find(name);
            auto beg= item_qua.begin();
            auto end = item_qua.end();

            if (it == end){
            
                item_qua[name]= quantity;
            }
            else{

                it->second += quantity;
            }

           
        }   
        
            
        
    void show_item() {

    int i=1;
    auto beg = item_qua.begin();
    auto end = item_qua.end();

    cout << '\n' <<  "------ List of items in shop ------" << '\n' ; 
    cout << '\n' << "S.no" << '\t' << "Name" << '\t'<<'\t' << "Quantity" << '\n' << endl;

         while(beg!=end)
        {
        std::cout << i << "." << '\t' << beg->first << '\t'<<'\t' << beg->second << endl;
        beg++;
        i++;
            }

    }

        string availaibility(string itemName, int quant){

            
            auto beg= item_qua.begin();
            auto end = item_qua.end();

            while (beg !=end)
            {
                if(beg->first == itemName && beg->second >= quant){

                        beg->second -= quant;
                        return beg->first;

                }
                else if(beg->first == itemName && beg->second <= quant){
                    return "Not enough Quantity";
                }
                beg++;

            }

            return " ";
            

        }

 };


    class bucket{

        public:
            map<string, int> item_buck;
        public:


    void additem(shop *shopj, string itemName, int quant){
                string item= shopj->availaibility(itemName, quant);

                if(item== itemName){

                        item_buck[itemName]= quant;
                }

                  else if(item=="Not enough Quantity"){
             cout << '\n' <<itemName<< '\t'  << "-->>" <<"NOT enough quantity" ;
        }
        else 
            cout << '\n' <<itemName<< '\t' << "-->>" << "Not available in the shop" << endl;
    }

            
            
    void show_bucket_item(){

            int i=1;

    auto beg = item_buck.begin();
    auto end = item_buck.end();
    
    std::cout << '\n' <<"------ List of items in bucket ------" << '\n';
    std::cout << '\n' << "S.no" << '\t' << "Name" << '\t' << "Quantity" << '\n' <<  std::endl;

         while(beg!=end)
        {
        std::cout << i << "." << '\t' << beg->first << '\t' << beg->second << std::endl;
        beg++;
        i++;
            }

    }

    
    void bill(Item *ptr1){
        double sum=0;
        int i=1;
        auto beg= ptr1->Item_ava.begin();
        auto end = ptr1->Item_ava.end();
        auto beg_bucket= item_buck.begin();
        auto end_bucket= item_buck.end();

             cout << '\n' <<"------ Final Bill ------" << '\n';
             
            cout << '\n' << "S.no" << '\t' << "Name" << '\t' << "Amount" << '\n' << endl;

            while (beg_bucket!=end_bucket)
            {
                auto it = ptr1->Item_ava.find(beg_bucket->first); 

                 if(it!=end){
                sum=sum+(it->second*beg_bucket->second);
                cout << i << '.' << '\t' << beg_bucket->first << '\t' << (it->second*beg_bucket->second) << '\n';
                i++;
            }

            else    
                cout << "->>>> " << beg_bucket->first << " is not in the Item list!" << '\n';
                
            beg_bucket++;
            }
            


    }

    void remove_item(shop *shopObj, string itemName){

            auto beg= item_buck.begin();
            auto end = item_buck.end();

            while (beg !=end)
            {
                if (beg ->first == itemName)
                {
                    item_buck.erase(itemName);
                    shopObj->additem(itemName, beg->second);

                }
                beg++;
            }
            
        }


    };

int main(){


       string a[]={"Denim","Shirt","Tie"};           // name of item aded in item class list
        double costing[]={400,200,300};                         // cost  of ach item added in Item Class list
         int quanAvail[]={50,50,50};                    //Quantity Avialble in shop



    Item item_list;
    shop Item_shop;
    bucket Item_buck;

    int s = sizeof(a)/sizeof(a[0]);

    for (int i = 0; i < s; i++)
    {
        item_list.add_item(a[i], costing[i]);
    }

    for (int  i = 0; i < s; i++)
    {
        Item_shop.additem(a[i], quanAvail[i]);
    }
    
    
    item_list.show_Item();

    Item_shop.show_item();


    // add item in buckets now
                                                    
    Item_buck.additem(&Item_shop, "Denim", 2);
    Item_buck.additem(&Item_shop, "Tie", 5);
    Item_buck.additem(&Item_shop, "Shirt", 3);

    Item_buck.show_bucket_item();

    Item_buck.bill(&item_list);

    Item_buck.remove_item(&Item_shop, "Tie");

    Item_buck.show_bucket_item();

    Item_buck.bill(&item_list);
}