#include <iostream>
#include <map>
#include <cstring>
#include <list>
using namespace std;

//Using item class to make a list of items 
class Item{

    public:
    std::map<std::string, double> item_inf;
    
    public:
   
    void add_item(std::string name, double amount){
    
    item_inf[name]=amount;

    }

    string getname(string name){
        auto it = item_inf.find(name);
        auto beg=item_inf.begin();
        auto end=item_inf.end();
        if(it==end)
            return NULL;
        else 
            return it->first;

    }

    double getamount(string name){
        auto it = item_inf.find(name);
        auto beg=item_inf.begin();
        auto end=item_inf.end();
        if(it==end)
            return 0;
        else 
            return it->second;
    }

    void show_items_list()
    {

    int i=1;
    auto beg = item_inf.begin();
    auto end = item_inf.end();
    
     
     std::cout << '\n' <<"------ List of items ------" << '\n';
     std::cout << '\n' << "S.no" << '\t' << "Name" << '\t' << "Amount" << '\n' <<  std::endl;

         while(beg!=end)
        {
        std::cout << i << "." << '\t' << beg->first  << '\t' << beg->second << std::endl;
        beg++;
        i++;
            }

    }
};

// class Itemdecor {
//     public:
//     string i;
//     int quantity;

//     public:
//     Itemdecor(string ptr, int Quant){
//             this->i=ptr;
//             this->quantity=Quant;
//     }
// };

class Shop {
    Item *ptr;
    public:
    map<string,int> item_list;
    
    public:
    
    void Add_Item(string it, int quant){
       auto em=item_list.find(it); 
        if(em==item_list.end()){
            item_list[it]=quant;
        }
        else
            em->second+=quant;
    }

    string Availablity(string Item1, int quantity){
        
        auto beg=item_list.begin();
        auto end=item_list.end();

        while(beg!=end){
            if(beg->first==Item1 && beg->second>=quantity){
                beg->second-=quantity;
                return beg->first;
            }
            else if(beg->first==Item1 && beg->second<=quantity){
                return "Not";
            }
            beg++;
        }
        return " ";
    }

    

    // Itemdecor * get_shopItem(string item,int quantity){
    //     auto it =item_list.find(item);
    //     if(it== item_list.end()){
    //         return NULL;
    //     }
    //     else{
    //         //update quantity
    //         item_list[it->first]=it->second-quantity;
    //         return (new Itemdecor(((it)->first),quantity));
    //     }
        
    // }


    void show_item()
    {

    int i=1;
    auto beg = item_list.begin();
    auto end = item_list.end();

    std::cout << '\n' <<  "------ List of items in shop ------" << '\n' ; 
    std::cout << '\n' << "S.no" << '\t' << "Name" << '\t' << "Quantity" << '\n' << std::endl;

         while(beg!=end)
        {
        std::cout << i << "." << '\t' << beg->first << '\t' << beg->second << std::endl;
        beg++;
        i++;
            }

    }
};

class Bucket{
    Item *ptr;
    public:
    std::map<std::string,int> Bucket_item;
    

    public:

    void add_bucketItem(Shop *shop_obj,string itemname,int req_quantity){
        string item=shop_obj->Availablity(itemname,req_quantity);
        if(item==itemname){
            Bucket_item[itemname]=req_quantity;
        }
        else if(item=="Not"){
             cout << '\n' <<itemname << '\t'  << "-->>" <<"NOT enough quantity" ;
        }
        else 
            cout << '\n' <<itemname << '\t' << "-->>" << "Not available in the shop" << endl;
    }
    void bill(Item *ptr1){
        double sum=0;
        int i=1;
        auto beg = ptr1->item_inf.begin();
        auto end = ptr1->item_inf.end();
        auto beg_bucket= Bucket_item.begin();
        auto end_bucket= Bucket_item.end();
        
        cout << '\n' <<"------ Final Bill ------" << '\n';
        cout << '\n' << "S.no" << '\t' << "Name" << '\t' << "Amount" << '\n' <<  std::endl;
        
        while (beg_bucket!=end_bucket)
        {
            auto it=ptr1->item_inf.find(beg_bucket->first); 
            if(it!=end){
                sum=sum+(it->second*beg_bucket->second);
                cout << i << '.' << '\t' << beg_bucket->first << '\t' << (it->second*beg_bucket->second) << '\n';
                i++;
            }

            else    
                cout << "->>>>> " << beg_bucket->first << " is not in the Item list!" << '\n';
                
            beg_bucket++;
        }

        cout <<'\n' <<  "Total Amount = " << sum << std::endl; 
    }

    void show_item_in_bucket()
    {

    int i=1;
    auto beg = Bucket_item.begin();
    auto end = Bucket_item.end();
    
    std::cout << '\n' <<"------ List of items in bucket ------" << '\n';
    std::cout << '\n' << "S.no" << '\t' << "Name" << '\t' << "Quantity" << '\n' <<  std::endl;

         while(beg!=end)
        {
        std::cout << i << "." << '\t' << beg->first << '\t' << beg->second << std::endl;
        beg++;
        i++;
            }

    }

    bool removeItem(Shop *shop_l,string itemname){
        auto beg = Bucket_item.begin();
        auto end = Bucket_item.end();

        while(beg!=end){
            if(beg->first==itemname){
                Bucket_item.erase(beg->first);
                shop_l->Add_Item(itemname,beg->second);
                return true;
            }
        }
        return false;
        
    } 

};

int main() {

    std::string a[]={"Apple","Orange","Banana"}; //string for adding item in item list
    std::string e[]={"Apple","Orange", "Banana" };  //string for adding item in bucket list
    int d[]={100,100,100};                  //Quantity array
    double b[]={100,20,30};                //Amount array
    int f[]={10,10,10};                  //Quantity array
    
    Item Item_list;
  
    Bucket cart;

    Shop Shop_list;

    //For transerving in the array
    int m=sizeof(a)/sizeof(a[0]);
    int n=sizeof(e)/sizeof(e[0]);
    
    for(int i=0; i<m; i++)         //Adding items in the item list
    {
        Item_list.add_item(a[i],b[i]);      
    }
    
    for(int i=0; i<n; i++)         //Adding items in the item list
    {
        Shop_list.Add_Item(e[i],d[i]);      
    }
    
    
    //To show the items in item list
    Item_list.show_items_list(); 


    cout <<'\n' << "-> Adding New items" << '\n' ; //Adding a net item
    Item_list.add_item("Grapes", 80);
    Shop_list.Add_Item("Grapes", 100);
    Item_list.show_items_list();

    cart.add_bucketItem(&Shop_list,"Orange",101); //More quantity than in shop
    cart.add_bucketItem(&Shop_list,"Oran",10); // Not in the list
    cart.add_bucketItem(&Shop_list,"Grapes",10);
    cart.add_bucketItem(&Shop_list,"Apple",10);

    cart.show_item_in_bucket();              //Showing the items with quantity in bucket 

    Shop_list.show_item();                  //shop with remaining quantity

    cart.removeItem(&Shop_list,"Apple");    //removing item from bucket

    cart.show_item_in_bucket();              //Showing the items with quantity in bucket 
    
    Shop_list.show_item();
    cart.bill(&Item_list);  //Generating the final bill of the product

}