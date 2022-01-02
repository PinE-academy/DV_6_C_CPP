#include <bits/stdc++.h>
// #include <iostream>
// #include <map>
// #include <cstring>
// #include <list>

using namespace std;

class Item{

    public:
        map<std :: string, double> Item_ava;

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
            
            std :: cout<< '\n' <<"------ List of items ------" << '\n';
            std::cout << '\n' << "S.no" << '\t' << "Name" << '\t' << "Amount" << '\n' <<  std::endl;

            while (beg != end)
            {
                std::cout << n << "." << '\t' << beg->first  << '\t' << beg->second << std::endl;

                n++;    
                beg++;

            }
            

         }






};


int main(){


       std::string a[]={"Denim","Shirt","cardigan"};  // name of item aded in item class list
        double costing[]={100,200,300};                         // cost  of ach item added in Item Class list

    Item item_list;

    int s = sizeof(a)/sizeof(a[0]);

    for (int i = 0; i < s; i++)
    {
        item_list.add_item(a[i], costing[i]);
    }
    
    item_list.show_Item();



}