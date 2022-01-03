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
 };




int main(){


       string a[]={"Denim","Shirt","Tie"};  // name of item aded in item class list
        double costing[]={400,200,300};                         // cost  of ach item added in Item Class list
         int quanAvail[]={50,50,50};                    //Quantity Avialble in shop



    Item item_list;
    shop Item_shop;


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



}